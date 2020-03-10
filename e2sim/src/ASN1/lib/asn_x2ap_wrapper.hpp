/*****************************************************************************
#                                                                            *
# Copyright 2019 AT&T Intellectual Property                                  *
# Copyright 2019 Nokia                                                       *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/
#ifndef ASN_X2AP_PDU_WRAPPER_HPP
#define ASN_X2AP_PDU_WRAPPER_HPP

#include <asn/per/codec.hpp>
#include <asn/printer.hpp>
#include <asn/utility.hpp>

#include <X2AP-CommonDataTypes.hpp>
#include <X2AP-Constants.hpp>
#include <X2AP-Containers.hpp>
#include <X2AP-IEs.hpp>
#include <X2AP-PDU-Contents.hpp>
#include <X2AP-PDU-Descriptions.hpp>

#define X2AP_PDU_DEFAULT_BUFFER_SIZE 4096

//Credit: copied from E2-Manager
struct X2APpduWrapper
{
    unsigned char* m_allocation_buffer;
    size_t m_allocation_buffer_size;

    X2APpduWrapper(size_t allocation_buffer_size = X2AP_PDU_DEFAULT_BUFFER_SIZE)
    {
        m_allocation_buffer_size = allocation_buffer_size;
        m_allocation_buffer = 0;
        if (allocation_buffer_size) {
            m_allocation_buffer =
              new (std::nothrow) unsigned char[allocation_buffer_size];
            m_allocator.reset(
              m_allocation_buffer,
              m_allocation_buffer_size); // initialized correctly on
                                         // allocation failure.
        }
    }

    ~X2APpduWrapper()
    {
        if (m_allocation_buffer)
            delete[] m_allocation_buffer;
    }

    asn::allocator& ref_allocator() { return m_allocator; }

    X2AP_PDU& ref_pdu() { return m_pdu; }

    // reset pdu and allocation buffer. Allows reusing.
    void clear()
    {
        m_pdu.clear();
        m_allocator.reset(m_allocation_buffer, m_allocation_buffer_size);
    }

  private:
    X2AP_PDU m_pdu;
    asn::allocator m_allocator;
};


#endif
