

#ifndef __SRS_CONNECTOR_HPP__
#define __SRS_CONNECTOR_HPP__

// total number of slices to write in the config file
#define SLICE_NUM 10

#define CONFIG_PATH "/root/radio_code/scope_config/slicing/"
#define SCHEDULING_FILENAME "slice_scheduling_policy.txt"
#define SLICING_BASE_FILENAME "slice_allocation_mask_tenant_"

void write_control_policies_json(std::string control_msg);
void write_scheduling_policy_json(std::string new_policy);
void write_slicing_policy_json(std::string new_policy);

#endif