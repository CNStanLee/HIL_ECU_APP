# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/hwil_app_system/_ide/scripts/debugger_hwil_app-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/hwil_app_system/_ide/scripts/debugger_hwil_app-default.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Nexys Video 210276B81712B" && level==0 && jtag_device_ctx=="jsn-Nexys Video-210276B81712B-13636093-0"}
fpga -file /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/hwil_app/_ide/bitstream/bd1_wrapper.bit
targets -set -nocase -filter {name =~ "*microblaze*#5" && bscan=="USER2" }
loadhw -hw /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/pl4/export/pl4/hw/bd1_wrapper.xsa -regs
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "*microblaze*#5" && bscan=="USER2" }
rst -system
after 3000
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
dow /home/labuser/temp_changhong_2024_09_30/HIL_ECU_APP/ws4/hwil_app/Debug/hwil_app.elf
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
con
