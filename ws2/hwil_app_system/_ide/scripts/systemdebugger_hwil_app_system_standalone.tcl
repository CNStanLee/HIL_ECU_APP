# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/temporary/Desktop/ChanghongTemp/ws2/hwil_app_system/_ide/scripts/systemdebugger_hwil_app_system_standalone.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source /home/temporary/Desktop/ChanghongTemp/ws2/hwil_app_system/_ide/scripts/systemdebugger_hwil_app_system_standalone.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Nexys Video 210276B81712B" && level==0 && jtag_device_ctx=="jsn-Nexys Video-210276B81712B-13636093-0"}
fpga -file /home/temporary/Desktop/ChanghongTemp/ws2/hwil_app/_ide/bitstream/bd1_wrapper.bit
targets -set -nocase -filter {name =~ "*microblaze*#5" && bscan=="USER2" }
loadhw -hw /home/temporary/Desktop/ChanghongTemp/ws2/hwil/export/hwil/hw/bd1_wrapper.xsa -regs
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "*microblaze*#5" && bscan=="USER2" }
rst -system
after 3000
targets -set -nocase -filter {name =~ "*microblaze*#5" && bscan=="USER2" }
dow /home/temporary/Desktop/ChanghongTemp/ws2/dos/Debug/dos.elf
targets -set -nocase -filter {name =~ "*microblaze*#4" && bscan=="USER2" }
dow /home/temporary/Desktop/ChanghongTemp/ws2/finn/Debug/finn.elf
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
dow /home/temporary/Desktop/ChanghongTemp/ws2/hwil_app/Debug/hwil_app.elf
targets -set -nocase -filter {name =~ "*microblaze*#1" && bscan=="USER2" }
dow /home/temporary/Desktop/ChanghongTemp/ws2/ecu1/Debug/ecu1.elf
targets -set -nocase -filter {name =~ "*microblaze*#2" && bscan=="USER2" }
dow /home/temporary/Desktop/ChanghongTemp/ws2/ecu2/Debug/ecu2.elf
targets -set -nocase -filter {name =~ "*microblaze*#3" && bscan=="USER2" }
dow /home/temporary/Desktop/ChanghongTemp/ws2/ecu3/Debug/ecu3.elf
targets -set -nocase -filter {name =~ "*microblaze*#5" && bscan=="USER2" }
con
targets -set -nocase -filter {name =~ "*microblaze*#4" && bscan=="USER2" }
con
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
con
targets -set -nocase -filter {name =~ "*microblaze*#1" && bscan=="USER2" }
con
targets -set -nocase -filter {name =~ "*microblaze*#2" && bscan=="USER2" }
con
targets -set -nocase -filter {name =~ "*microblaze*#3" && bscan=="USER2" }
con
