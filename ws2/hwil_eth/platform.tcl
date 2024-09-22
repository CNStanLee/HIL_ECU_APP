# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/temporary/Desktop/ChanghongTemp/ws2/hwil_eth/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/temporary/Desktop/ChanghongTemp/ws2/hwil_eth/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {hwil_eth}\
-hw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/whole_design_wrapper.xsa}\
-proc {bd1_0_mb_dos} -os {standalone} -out {/home/temporary/Desktop/ChanghongTemp/ws2}

platform write
platform generate -domains 
platform active {hwil_eth}
domain create -name {mb_finn} -os {standalone} -proc {bd1_0_mb_finn} -arch {32-bit} -display-name {mb_finn} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain create -name {mb_ctrl} -os {standalone} -proc {bd1_0_microblaze_0} -arch {32-bit} -display-name {mb_ctrl} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain create -name {mb_ecu1} -os {standalone} -proc {bd1_0_microblaze_1} -arch {32-bit} -display-name {mb_ecu1} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain remove standalone_domain
platform generate -domains 
platform write
domain create -name {mb_dos} -os {standalone} -proc {bd1_0_mb_dos} -arch {32-bit} -display-name {mb_dos} -desc {} -runtime {cpp}
platform generate -domains 
domain -report -json
platform write
domain create -name {mb2_ecu2} -os {standalone} -proc {bd1_0_microblaze_2} -arch {32-bit} -display-name {mb2_ecu2} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain create -name {mb3_ecu3} -os {standalone} -proc {bd1_0_microblaze_3} -arch {32-bit} -display-name {mb3_ecu3} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
platform generate
