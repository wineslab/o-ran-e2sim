// VIAVI RIC Tester streaming data input and closed loop
//
// Maintainer: agustin.pozuelo@viavisolutions.com
//
// Copyright 2020 VIAVI Solutions
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied
// See the License for the specific language governing permissions and
// limitations under the License

#include <atomic>
#include <chrono>
#include <functional>
#include <ext/stdio_filebuf.h>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <vector>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <nlohmann/json.hpp>


namespace viavi {

using namespace std::chrono_literals;
using Clock = std::chrono::steady_clock;
using json = nlohmann::json;

void panic(const char* why)
{
    throw std::runtime_error(std::string("RIC tester: ") + why
        + ". ERRNO " + std::to_string(errno) + ": " + ::strerror(errno));
}

static int sample_data_callback(json& message)
{
    std::stringstream ss; ss << "RIC tester thread " << std::this_thread::get_id();
    auto I = ss.str();
    int report_count = 0;
    if (message.contains("ueMeasReport")) {
        json reports = message["ueMeasReport"]["ueMeasReportList"];
        
        message["ueMeasReport"].erase("ueMeasReportList");
        std::clog << I << " got " << reports.size() << " UE reports: " << message["ueMeasReport"];
        
        for (auto& report: reports) {
            ++report_count;
            int serving_cell = report["nrCellIdentity"];
            int rsrp = report["servingCellRfReport"]["rsrp"];
        }
    }
    if (message.contains("cellMeasReport")) {
        json reports = message["cellMeasReport"]["cellMeasReportList"];
        
        message["cellMeasReport"].erase("cellMeasReportList");
        std::clog << I << " got " << reports.size() << " cell reports: " << message["cellMeasReport"];
        
        for (auto& report: reports) {
            ++report_count;
            int serving_cell = report["nrCellIdentity"];
            int throughput = report["throughput"];
        }
    }
    return report_count;
}

class RICTesterReceiver
{
    public:
    RICTesterReceiver(int portno = 3001, std::function<int(json& message)> data_callback = sample_data_callback)
    {
        listen_fd = socket(AF_INET, SOCK_STREAM, 0);
        int enabled = 1;
        if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &enabled, sizeof(enabled)) < 0)
            panic("ERROR opening socket");
        struct sockaddr_in serv_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(portno),
            .sin_addr = { .s_addr = INADDR_ANY}
        };
        if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
            panic("Bind error");

        printf("Listening on TCP 0.0.0.0:%d...\n", portno);
        listen(listen_fd, 3); // Max 3 pending connections

        set_callback(data_callback);
        threads_.emplace_back([this] {server();});
    }

    void set_callback(std::function<int(json& message)> data_callback)
    {
        data_callback_ = data_callback;
        if (!data_callback && data_pipe_[0] == STDIN_FILENO) {
            printf("No data callback provided, creating data pipe...\n");
            if (pipe(data_pipe_))
                panic("Cannot create data pipe");
            data_filebuf_ = __gnu_cxx::stdio_filebuf<char> {data_pipe_[0], std::ios::in};
        }
    }

    std::basic_filebuf<char>* get_data_filebuf()
    {
        return &data_filebuf_;
    }

    ~RICTesterReceiver()
    {
        alive = false;
        for (auto& t: threads_)
            t.join();
    }

    protected:
    int listen_fd;
    std::vector<std::thread> threads_;
    bool alive = true;
    std::function<int(json& message)> data_callback_;
    int data_pipe_[2] = {STDIN_FILENO, STDOUT_FILENO};  // Default to stdin, stdout
    __gnu_cxx::stdio_filebuf<char> data_filebuf_;

    void server()
    {
        while (alive)
        {
            int connection_fd = accept(listen_fd, NULL, NULL);
            if (connection_fd <= 0)
                panic("ERROR on accept");
            threads_.emplace_back([this, connection_fd] {service(connection_fd);});
        }
    }

    void service(int connection_fd)
    {
        std::stringstream ss; ss << "RIC tester thread " << std::this_thread::get_id();
        auto I = ss.str();
        std::clog << I << " starting connection on fd " << connection_fd << std::endl;
        int report_count = 0;
        auto log_time = Clock::now();
        try {
            __gnu_cxx::stdio_filebuf<char>
                inbuf {connection_fd, std::ios::in},
                outbuf{data_pipe_[1], std::ios::out};
            std::istream input {&inbuf};
            std::ostream output{&outbuf};

            while (alive && input.good())
            {
                if (!data_callback_)
                {
                    // Pipe raw data and let user decode JSON
                    char buf[4096];
                    input.get(buf[0]); // Block until 1 char is ready
                    output.write(buf, 1 + input.readsome(buf+1, sizeof(buf)-1));
                }
                else try
                {
                    // Decode JSON message and pass it to user's callback
                    json message;
                    input >> message;
                    std::clog << I << " Message type: " << message.begin().key() << std::endl;
                    report_count += data_callback_(message);
                } catch (const std::exception& ex) {
                    std::clog << I << " ERROR in CALLBACK: " << ex.what() << std::endl;
                }

                if (Clock::now() > log_time) {
                    std::clog << I << " got " << report_count << " reports" << std::endl;
                    log_time += 10s;
                }
            }
        } catch (const std::exception& ex) {
            std::clog << I << " ERROR: " << ex.what() << std::endl;
        }
        std::clog << I << " closed connection after " << report_count << " reports" << std::endl;
    }

};

}
