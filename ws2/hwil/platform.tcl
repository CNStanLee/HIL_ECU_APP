# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/temporary/Desktop/ChanghongTemp/ws2/hwil/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/temporary/Desktop/ChanghongTemp/ws2/hwil/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {hwil}\
-hw {/home/temporary/Desktop/ChanghongTemp/np2023/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}\
-proc {mb_dos} -os {standalone} -out {/home/temporary/Desktop/ChanghongTemp/ws2}

platform write
platform generate -domains 
platform active {hwil}
platform generate
domain create -name {mb_finn} -os {standalone} -proc {mb_finn} -arch {32-bit} -display-name {mb_finn} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain create -name {mb0_ctl} -os {standalone} -proc {microblaze_0} -arch {32-bit} -display-name {mb0_ctl} -desc {} -runtime {cpp}
platform generate -domains 
domain -report -json
platform write
domain create -name {mb1_ecu1} -os {standalone} -proc {microblaze_1} -arch {32-bit} -display-name {mb1_ecu1} -desc {} -runtime {cpp}
platform generate -domains 
domain -report -json
platform write
domain create -name {mb2_ecu2} -os {standalone} -proc {microblaze_2} -arch {32-bit} -display-name {mb2_ecu2} -desc {} -runtime {cpp}
platform generate -domains 
domain -report -json
platform write
domain create -name {mb3_ecu3} -os {standalone} -proc {microblaze_3} -arch {32-bit} -display-name {mb3_ecu3} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
platform generate -domains mb_finn,mb0_ctl,mb1_ecu1,mb2_ecu2,mb3_ecu3 
platform active {hwil}
domain create -name {standalone_microblaze_0} -display-name {standalone_microblaze_0} -os {standalone} -proc {microblaze_0} -runtime {cpp} -arch {32-bit} -support-app {hello_world}
platform generate -domains 
platform write
domain active {standalone_domain}
domain active {mb_finn}
domain active {mb0_ctl}
domain active {mb1_ecu1}
domain active {mb2_ecu2}
domain active {mb3_ecu3}
domain active {standalone_microblaze_0}
platform generate -quick
platform clean
platform generate
platform clean
platform generate
platform active {hwil}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform clean
platform generate
platform clean
platform generate
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform clean
platform generate
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains 
platform active {hwil}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains 
platform active {hwil}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains standalone_domain,mb_finn,mb0_ctl,standalone_microblaze_0,mb1_ecu1,mb2_ecu2,mb3_ecu3 
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform active {hwil}
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform active {hwil}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/whole_design_wrapper.xsa}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/whole_design_wrapper.xsa}
platform active {hwil}
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {/home/temporary/Desktop/ChanghongTemp/np2023v2/014microblaze20183to2023/microblaze20183/bd1_wrapper.xsa}
platform generate -domains 
