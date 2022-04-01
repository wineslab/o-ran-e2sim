#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "srs_connector.hpp"

using json = nlohmann::json;

std::string last_scheduling_policy_json;
std::string last_slicing_policy_json;


// receive agent control and write it on config files
// expected control looks like: '{"sched": "1,0,0", "slicing": "5,10,3"}'
void write_control_policies_json(std::string control_msg) {

    std::cout << "Writing JSON-formatted control policies: " << control_msg << std::endl;

    // parse json control message to retrieve policies
    json control_msg_json = json::parse(control_msg);
    std::string scheduling_policies = control_msg_json.value("sched", "");
    std::string slicing_policies = control_msg_json.value("slicing", "");

    if (scheduling_policies.length() > 0) {
        std::cout << "Received scheduling policies " << scheduling_policies << std::endl;

        if (!last_scheduling_policy_json.empty() && scheduling_policies.compare(last_scheduling_policy_json) == 0) {
            std::cout << "Scheduling policies are the same as last ones" << std::endl;
        }
        else {
            std::cout << "Writing new scheduling policies on config file " << std::endl;
            write_scheduling_policy_json(scheduling_policies);

            // update last received policy
            last_scheduling_policy_json = scheduling_policies;
        }
    }

    if (slicing_policies.length() > 0) {
        std::cout << "Received slicing policies " << slicing_policies << std::endl;

        if (!last_slicing_policy_json.empty() && slicing_policies.compare(last_slicing_policy_json) == 0) {
            std::cout << "Slicing policies are the same as last ones" << std::endl;
        }
        else {
            std::cout << "Received slicing policies " << slicing_policies << std::endl;
            write_slicing_policy_json(slicing_policies);

            // update last received policy
            last_slicing_policy_json = slicing_policies;
        }
    }

    if (scheduling_policies.length() + slicing_policies.length() <= 0) {
        std::cout << "No valid policies received" << std::endl;
    }

}


// write scheduling policies on config file
void write_scheduling_policy_json(std::string new_policy) {

    std::fstream fs;
    std::string filename;
    const std::string file_header = "# slice::scheduling policy\n"
                                    "# 0 = default srsLTE round-robin\n"
                                    "# 1 = waterfilling\n"
                                    "# 2 = proportional";
    const std::string policies_delimiter = ",";
    const std::string config_delimiter = "::";
    const std::string default_policy = "0";

    size_t pos = 0;
    int slice_num = 0;
    std::string token;

    // form path of configuration file
    std::string config_path(CONFIG_PATH);
    std::string scheduling_filename(SCHEDULING_FILENAME);
    filename = config_path + scheduling_filename;

    // the file is created if it does not exist
    fs.open(filename, std::fstream::out);

    // write header
    fs << file_header << std::endl;

    // get policies by splitting string on delimiters and write them
    // the last policy has pos == std::string::npos but the policy still needs to be written
    bool last_policy = true;
    while ((pos = new_policy.find(policies_delimiter)) != std::string::npos || last_policy) {
        if (pos == std::string::npos) {
            // write last policy
            token = new_policy;
            last_policy = false;
        }
        else {
            // write other policies
            token = new_policy.substr(0, pos);
        }

        fs << slice_num << config_delimiter << token << std::endl;

        if (last_policy) {
            new_policy.erase(0, pos + policies_delimiter.length());
        }

        slice_num++;
    }

    // write default policy for remaining slices
    for (int i = slice_num; i < SLICE_NUM; ++i) {
        fs << i << config_delimiter << default_policy << std::endl;
    }

    fs.close();
}


// write slicing policy on config file
void write_slicing_policy_json(std::string new_policy) {

    std::fstream fs;
    std::string base_filename;

    const int rbg_num = 25;
    const std::string policies_delimiter = ",";
    const std::string filename_extension = ".txt";

    size_t pos = 0;
    int slice_num = 0;
    int first_rbg_position = 0;
    std::string token;

    // form path of configuration file
    std::string config_path(CONFIG_PATH);
    std::string scheduling_filename(SLICING_BASE_FILENAME);
    base_filename = config_path + scheduling_filename;

    // get policies by splitting string on delimiters and write them
    // the last policy has pos == std::string::npos but the policy still needs to be written
    bool last_policy = true;
    while ((pos = new_policy.find(policies_delimiter)) != std::string::npos || last_policy) {
        if (pos == std::string::npos) {
            // write last policy
            token = new_policy;
            last_policy = false;
        }
        else {
            // write other policies
            token = new_policy.substr(0, pos);
        }

        // create rbg mask
        int written = 0;
        std::string rbg_mask;
        int rbg_policy = std::stoi(token);
        for (int i = 0; written < rbg_policy && i < rbg_num; ++i) {
            if (i < first_rbg_position) {
                rbg_mask += "0";
            }
            else {
                rbg_mask += "1";
                first_rbg_position++;
                written++;
            }
        }

        // write remaining rbgs
        for (int j = first_rbg_position; j < rbg_num; ++j) {
            rbg_mask += "0";
        }

        std::cout << "Writing slicing mask slice " << slice_num << ": " << rbg_mask << std::endl;

        // write policy, the file is created if it does not exist
        std::string filename = base_filename + std::to_string(slice_num) + filename_extension;
        fs.open(filename, std::fstream::out);
        fs << rbg_mask;

        if (last_policy) {
            new_policy.erase(0, pos + policies_delimiter.length());
        }

        slice_num++;
        fs.close();
    }
}
