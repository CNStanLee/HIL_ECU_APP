# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/pl4/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/pl4/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {pl4}\
-hw {/home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/bd1_wrapper.xsa}\
-proc {microblaze_0} -os {standalone} -out {/home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4}

platform write
platform generate -domains 
platform active {pl4}
platform clean
platform generate
platform clean
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
