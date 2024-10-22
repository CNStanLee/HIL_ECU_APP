
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = standalone
 PARAMETER OS_VER = 9.0
 PARAMETER PROC_INSTANCE = bd1_0_microblaze_2
END


BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu
 PARAMETER DRIVER_VER = 2.18
 PARAMETER HW_INSTANCE = bd1_0_microblaze_2
END


BEGIN DRIVER
 PARAMETER DRIVER_NAME = can_controller
 PARAMETER DRIVER_VER = 1.0
 PARAMETER HW_INSTANCE = bd1_0_mb2_can_controller
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 4.10
 PARAMETER HW_INSTANCE = bd1_0_mb2_gpio_led
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = tmrctr
 PARAMETER DRIVER_VER = 4.11
 PARAMETER HW_INSTANCE = bd1_0_mb2_t0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = tmrctr
 PARAMETER DRIVER_VER = 4.11
 PARAMETER HW_INSTANCE = bd1_0_mb2_t1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = intc
 PARAMETER DRIVER_VER = 3.17
 PARAMETER HW_INSTANCE = bd1_0_microblaze_2_axi_intc
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 4.9
 PARAMETER HW_INSTANCE = bd1_0_microblaze_2_local_memory_dlmb_bram_if_cntlr
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 4.9
 PARAMETER HW_INSTANCE = bd1_0_microblaze_2_local_memory_ilmb_bram_if_cntlr
END


