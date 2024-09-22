#ifndef XPARAMETERS_H   /* prevent circular inclusions */
#define XPARAMETERS_H   /* by using protection macros */

/* Definitions for bus frequencies */
#define XPAR_CPU_M_AXI_DP_FREQ_HZ 100000000
/******************************************************************/

/* Canonical definitions for bus frequencies */
/******************************************************************/

#define XPAR_CPU_CORE_CLOCK_FREQ_HZ 100000000
#define XPAR_MICROBLAZE_CORE_CLOCK_FREQ_HZ 100000000

/******************************************************************/


/* Definitions for peripheral BD1_0_MICROBLAZE_3 */
#define XPAR_BD1_0_MICROBLAZE_3_ADDR_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_ADDR_TAG_BITS 17
#define XPAR_BD1_0_MICROBLAZE_3_ALLOW_DCACHE_WR 1
#define XPAR_BD1_0_MICROBLAZE_3_ALLOW_ICACHE_WR 1
#define XPAR_BD1_0_MICROBLAZE_3_AREA_OPTIMIZED 0
#define XPAR_BD1_0_MICROBLAZE_3_ASYNC_INTERRUPT 1
#define XPAR_BD1_0_MICROBLAZE_3_ASYNC_WAKEUP 3
#define XPAR_BD1_0_MICROBLAZE_3_AVOID_PRIMITIVES 0
#define XPAR_BD1_0_MICROBLAZE_3_BASE_VECTORS 0x0000000000000000
#define XPAR_BD1_0_MICROBLAZE_3_BRANCH_TARGET_CACHE_SIZE 0
#define XPAR_BD1_0_MICROBLAZE_3_CACHE_BYTE_SIZE 8192
#define XPAR_BD1_0_MICROBLAZE_3_DADDR_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_DATA_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_ADDR_TAG 17
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_ALWAYS_USED 1
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_BASEADDR 0x00000000
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_BYTE_SIZE 8192
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_DATA_WIDTH 0
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_FORCE_TAG_LUTRAM 0
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_HIGHADDR 0x3FFFFFFF
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_LINE_LEN 4
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_USE_WRITEBACK 0
#define XPAR_BD1_0_MICROBLAZE_3_DCACHE_VICTIMS 0
#define XPAR_BD1_0_MICROBLAZE_3_DC_AXI_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_COUNTER_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_ENABLED 1
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_EVENT_COUNTERS 5
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_EXTERNAL_TRACE 0
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_INTERFACE 0
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_LATENCY_COUNTERS 1
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_PROFILE_SIZE 0
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_TRACE_ASYNC_RESET 0
#define XPAR_BD1_0_MICROBLAZE_3_DEBUG_TRACE_SIZE 8192
#define XPAR_BD1_0_MICROBLAZE_3_DIV_ZERO_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_DP_AXI_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_DYNAMIC_BUS_SIZING 0
#define XPAR_BD1_0_MICROBLAZE_3_D_AXI 1
#define XPAR_BD1_0_MICROBLAZE_3_D_LMB 1
#define XPAR_BD1_0_MICROBLAZE_3_D_LMB_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_D_LMB_PROTOCOL 0
#define XPAR_BD1_0_MICROBLAZE_3_ECC_USE_CE_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_EDGE_IS_POSITIVE 1
#define XPAR_BD1_0_MICROBLAZE_3_ENABLE_DISCRETE_PORTS 0
#define XPAR_BD1_0_MICROBLAZE_3_ENDIANNESS 1
#define XPAR_BD1_0_MICROBLAZE_3_FAULT_TOLERANT 0
#define XPAR_BD1_0_MICROBLAZE_3_FPU_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_FREQ 100000000
#define XPAR_BD1_0_MICROBLAZE_3_FSL_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_FSL_LINKS 0
#define XPAR_BD1_0_MICROBLAZE_3_IADDR_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_ALWAYS_USED 1
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_BASEADDR 0x00000000
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_DATA_WIDTH 0
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_FORCE_TAG_LUTRAM 0
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_HIGHADDR 0x3FFFFFFF
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_LINE_LEN 4
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_STREAMS 0
#define XPAR_BD1_0_MICROBLAZE_3_ICACHE_VICTIMS 0
#define XPAR_BD1_0_MICROBLAZE_3_IC_AXI_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_ILL_OPCODE_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_IMPRECISE_EXCEPTIONS 0
#define XPAR_BD1_0_MICROBLAZE_3_INSTR_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_INTERCONNECT 2
#define XPAR_BD1_0_MICROBLAZE_3_INTERRUPT_IS_EDGE 0
#define XPAR_BD1_0_MICROBLAZE_3_INTERRUPT_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_IP_AXI_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_I_AXI 0
#define XPAR_BD1_0_MICROBLAZE_3_I_LMB 1
#define XPAR_BD1_0_MICROBLAZE_3_I_LMB_MON 0
#define XPAR_BD1_0_MICROBLAZE_3_I_LMB_PROTOCOL 0
#define XPAR_BD1_0_MICROBLAZE_3_LMB_DATA_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_LOCKSTEP_MASTER 0
#define XPAR_BD1_0_MICROBLAZE_3_LOCKSTEP_SELECT 0
#define XPAR_BD1_0_MICROBLAZE_3_LOCKSTEP_SLAVE 0
#define XPAR_BD1_0_MICROBLAZE_3_M0_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M0_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M1_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M1_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M2_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M2_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M3_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M3_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M4_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M4_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M5_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M5_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M6_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M6_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M7_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M7_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M8_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M8_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M9_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M9_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M10_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M10_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M11_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M11_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M12_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M12_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M13_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M13_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M14_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M14_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_M15_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M15_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_MMU_DTLB_SIZE 4
#define XPAR_BD1_0_MICROBLAZE_3_MMU_ITLB_SIZE 2
#define XPAR_BD1_0_MICROBLAZE_3_MMU_PRIVILEGED_INSTR 0
#define XPAR_BD1_0_MICROBLAZE_3_MMU_TLB_ACCESS 3
#define XPAR_BD1_0_MICROBLAZE_3_MMU_ZONES 16
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_ADDR_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_ARUSER_WIDTH 5
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_AWUSER_WIDTH 5
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_BUSER_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_EXCLUSIVE_ACCESS 0
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_RUSER_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_THREAD_ID_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_USER_SIGNALS 0
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_USER_VALUE 31
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DC_WUSER_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DP_ADDR_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DP_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DP_EXCLUSIVE_ACCESS 0
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_DP_THREAD_ID_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_D_BUS_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_ADDR_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_ARUSER_WIDTH 5
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_AWUSER_WIDTH 5
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_BUSER_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_RUSER_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_THREAD_ID_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_USER_SIGNALS 0
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_USER_VALUE 31
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IC_WUSER_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IP_ADDR_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IP_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_IP_THREAD_ID_WIDTH 1
#define XPAR_BD1_0_MICROBLAZE_3_M_AXI_I_BUS_EXCEPTION 0
#define XPAR_BD1_0_MICROBLAZE_3_NUMBER_OF_PC_BRK 1
#define XPAR_BD1_0_MICROBLAZE_3_NUMBER_OF_RD_ADDR_BRK 0
#define XPAR_BD1_0_MICROBLAZE_3_NUMBER_OF_WR_ADDR_BRK 0
#define XPAR_BD1_0_MICROBLAZE_3_NUM_SYNC_FF_CLK 2
#define XPAR_BD1_0_MICROBLAZE_3_NUM_SYNC_FF_CLK_DEBUG 2
#define XPAR_BD1_0_MICROBLAZE_3_NUM_SYNC_FF_CLK_IRQ 1
#define XPAR_BD1_0_MICROBLAZE_3_NUM_SYNC_FF_DBG_CLK 1
#define XPAR_BD1_0_MICROBLAZE_3_NUM_SYNC_FF_DBG_TRACE_CLK 2
#define XPAR_BD1_0_MICROBLAZE_3_OPCODE_0X0_ILLEGAL 0
#define XPAR_BD1_0_MICROBLAZE_3_OPTIMIZATION 0
#define XPAR_BD1_0_MICROBLAZE_3_PART xc7a200tsbg484-1
#define XPAR_BD1_0_MICROBLAZE_3_PC_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_PIADDR_SIZE 32
#define XPAR_BD1_0_MICROBLAZE_3_PVR 0
#define XPAR_BD1_0_MICROBLAZE_3_PVR_USER1 0x00
#define XPAR_BD1_0_MICROBLAZE_3_PVR_USER2 0x00000000
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR 0x00000000
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR_BIP 0
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR_DCE 0
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR_EE 0
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR_EIP 0
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR_ICE 0
#define XPAR_BD1_0_MICROBLAZE_3_RESET_MSR_IE 0
#define XPAR_BD1_0_MICROBLAZE_3_S0_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S0_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S1_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S1_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S2_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S2_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S3_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S3_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S4_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S4_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S5_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S5_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S6_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S6_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S7_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S7_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S8_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S8_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S9_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S9_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S10_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S10_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S11_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S11_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S12_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S12_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S13_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S13_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S14_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S14_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_S15_AXIS_DATA_WIDTH 32
#define XPAR_BD1_0_MICROBLAZE_3_S15_AXIS_PROTOCOL GENERIC
#define XPAR_BD1_0_MICROBLAZE_3_SCO 0
#define XPAR_BD1_0_MICROBLAZE_3_TEMPORAL_DEPTH 0
#define XPAR_BD1_0_MICROBLAZE_3_TRACE 0
#define XPAR_BD1_0_MICROBLAZE_3_UNALIGNED_EXCEPTIONS 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_BARREL 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_BRANCH_TARGET_CACHE 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_CONFIG_RESET 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_DCACHE 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_DIV 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_EXTENDED_FSL_INSTR 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_EXT_BRK 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_EXT_NM_BRK 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_FPU 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_HW_MUL 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_ICACHE 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_INTERRUPT 2
#define XPAR_BD1_0_MICROBLAZE_3_USE_MMU 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_MSR_INSTR 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_NON_SECURE 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_PCMP_INSTR 0
#define XPAR_BD1_0_MICROBLAZE_3_USE_REORDER_INSTR 1
#define XPAR_BD1_0_MICROBLAZE_3_USE_STACK_PROTECTION 0
#define XPAR_BD1_0_MICROBLAZE_3_COMPONENT_NAME bd1_inst_0_microblaze_3_0
#define XPAR_BD1_0_MICROBLAZE_3_EDK_IPTYPE PROCESSOR
#define XPAR_BD1_0_MICROBLAZE_3_EDK_SPECIAL microblaze
#define XPAR_BD1_0_MICROBLAZE_3_G_TEMPLATE_LIST 0
#define XPAR_BD1_0_MICROBLAZE_3_G_USE_EXCEPTIONS 0

/******************************************************************/

#define XPAR_CPU_ID 5
#define XPAR_MICROBLAZE_ID 5
#define XPAR_MICROBLAZE_ADDR_SIZE 32
#define XPAR_MICROBLAZE_ADDR_TAG_BITS 17
#define XPAR_MICROBLAZE_ALLOW_DCACHE_WR 1
#define XPAR_MICROBLAZE_ALLOW_ICACHE_WR 1
#define XPAR_MICROBLAZE_AREA_OPTIMIZED 0
#define XPAR_MICROBLAZE_ASYNC_INTERRUPT 1
#define XPAR_MICROBLAZE_ASYNC_WAKEUP 3
#define XPAR_MICROBLAZE_AVOID_PRIMITIVES 0
#define XPAR_MICROBLAZE_BASE_VECTORS 0x0000000000000000
#define XPAR_MICROBLAZE_BRANCH_TARGET_CACHE_SIZE 0
#define XPAR_MICROBLAZE_CACHE_BYTE_SIZE 8192
#define XPAR_MICROBLAZE_DADDR_SIZE 32
#define XPAR_MICROBLAZE_DATA_SIZE 32
#define XPAR_MICROBLAZE_DCACHE_ADDR_TAG 17
#define XPAR_MICROBLAZE_DCACHE_ALWAYS_USED 1
#define XPAR_MICROBLAZE_DCACHE_BASEADDR 0x00000000
#define XPAR_MICROBLAZE_DCACHE_BYTE_SIZE 8192
#define XPAR_MICROBLAZE_DCACHE_DATA_WIDTH 0
#define XPAR_MICROBLAZE_DCACHE_FORCE_TAG_LUTRAM 0
#define XPAR_MICROBLAZE_DCACHE_HIGHADDR 0x3FFFFFFF
#define XPAR_MICROBLAZE_DCACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_DCACHE_USE_WRITEBACK 0
#define XPAR_MICROBLAZE_DCACHE_VICTIMS 0
#define XPAR_MICROBLAZE_DC_AXI_MON 0
#define XPAR_MICROBLAZE_DEBUG_COUNTER_WIDTH 32
#define XPAR_MICROBLAZE_DEBUG_ENABLED 1
#define XPAR_MICROBLAZE_DEBUG_EVENT_COUNTERS 5
#define XPAR_MICROBLAZE_DEBUG_EXTERNAL_TRACE 0
#define XPAR_MICROBLAZE_DEBUG_INTERFACE 0
#define XPAR_MICROBLAZE_DEBUG_LATENCY_COUNTERS 1
#define XPAR_MICROBLAZE_DEBUG_PROFILE_SIZE 0
#define XPAR_MICROBLAZE_DEBUG_TRACE_ASYNC_RESET 0
#define XPAR_MICROBLAZE_DEBUG_TRACE_SIZE 8192
#define XPAR_MICROBLAZE_DIV_ZERO_EXCEPTION 0
#define XPAR_MICROBLAZE_DP_AXI_MON 0
#define XPAR_MICROBLAZE_DYNAMIC_BUS_SIZING 0
#define XPAR_MICROBLAZE_D_AXI 1
#define XPAR_MICROBLAZE_D_LMB 1
#define XPAR_MICROBLAZE_D_LMB_MON 0
#define XPAR_MICROBLAZE_D_LMB_PROTOCOL 0
#define XPAR_MICROBLAZE_ECC_USE_CE_EXCEPTION 0
#define XPAR_MICROBLAZE_EDGE_IS_POSITIVE 1
#define XPAR_MICROBLAZE_ENABLE_DISCRETE_PORTS 0
#define XPAR_MICROBLAZE_ENDIANNESS 1
#define XPAR_MICROBLAZE_FAULT_TOLERANT 0
#define XPAR_MICROBLAZE_FPU_EXCEPTION 0
#define XPAR_MICROBLAZE_FREQ 100000000
#define XPAR_MICROBLAZE_FSL_EXCEPTION 0
#define XPAR_MICROBLAZE_FSL_LINKS 0
#define XPAR_MICROBLAZE_IADDR_SIZE 32
#define XPAR_MICROBLAZE_ICACHE_ALWAYS_USED 1
#define XPAR_MICROBLAZE_ICACHE_BASEADDR 0x00000000
#define XPAR_MICROBLAZE_ICACHE_DATA_WIDTH 0
#define XPAR_MICROBLAZE_ICACHE_FORCE_TAG_LUTRAM 0
#define XPAR_MICROBLAZE_ICACHE_HIGHADDR 0x3FFFFFFF
#define XPAR_MICROBLAZE_ICACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_ICACHE_STREAMS 0
#define XPAR_MICROBLAZE_ICACHE_VICTIMS 0
#define XPAR_MICROBLAZE_IC_AXI_MON 0
#define XPAR_MICROBLAZE_ILL_OPCODE_EXCEPTION 0
#define XPAR_MICROBLAZE_IMPRECISE_EXCEPTIONS 0
#define XPAR_MICROBLAZE_INSTR_SIZE 32
#define XPAR_MICROBLAZE_INTERCONNECT 2
#define XPAR_MICROBLAZE_INTERRUPT_IS_EDGE 0
#define XPAR_MICROBLAZE_INTERRUPT_MON 0
#define XPAR_MICROBLAZE_IP_AXI_MON 0
#define XPAR_MICROBLAZE_I_AXI 0
#define XPAR_MICROBLAZE_I_LMB 1
#define XPAR_MICROBLAZE_I_LMB_MON 0
#define XPAR_MICROBLAZE_I_LMB_PROTOCOL 0
#define XPAR_MICROBLAZE_LMB_DATA_SIZE 32
#define XPAR_MICROBLAZE_LOCKSTEP_MASTER 0
#define XPAR_MICROBLAZE_LOCKSTEP_SELECT 0
#define XPAR_MICROBLAZE_LOCKSTEP_SLAVE 0
#define XPAR_MICROBLAZE_M0_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M0_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M1_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M1_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M2_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M2_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M3_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M3_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M4_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M4_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M5_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M5_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M6_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M6_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M7_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M7_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M8_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M8_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M9_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M9_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M10_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M10_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M11_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M11_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M12_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M12_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M13_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M13_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M14_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M14_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M15_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M15_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_MMU_DTLB_SIZE 4
#define XPAR_MICROBLAZE_MMU_ITLB_SIZE 2
#define XPAR_MICROBLAZE_MMU_PRIVILEGED_INSTR 0
#define XPAR_MICROBLAZE_MMU_TLB_ACCESS 3
#define XPAR_MICROBLAZE_MMU_ZONES 16
#define XPAR_MICROBLAZE_M_AXI_DC_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DC_ARUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_DC_AWUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_DC_BUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DC_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DC_EXCLUSIVE_ACCESS 0
#define XPAR_MICROBLAZE_M_AXI_DC_RUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DC_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DC_USER_SIGNALS 0
#define XPAR_MICROBLAZE_M_AXI_DC_USER_VALUE 31
#define XPAR_MICROBLAZE_M_AXI_DC_WUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DP_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DP_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DP_EXCLUSIVE_ACCESS 0
#define XPAR_MICROBLAZE_M_AXI_DP_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_D_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_M_AXI_IC_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IC_ARUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_IC_AWUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_IC_BUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IC_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IC_RUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IC_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IC_USER_SIGNALS 0
#define XPAR_MICROBLAZE_M_AXI_IC_USER_VALUE 31
#define XPAR_MICROBLAZE_M_AXI_IC_WUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IP_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IP_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IP_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_I_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_NUMBER_OF_PC_BRK 1
#define XPAR_MICROBLAZE_NUMBER_OF_RD_ADDR_BRK 0
#define XPAR_MICROBLAZE_NUMBER_OF_WR_ADDR_BRK 0
#define XPAR_MICROBLAZE_NUM_SYNC_FF_CLK 2
#define XPAR_MICROBLAZE_NUM_SYNC_FF_CLK_DEBUG 2
#define XPAR_MICROBLAZE_NUM_SYNC_FF_CLK_IRQ 1
#define XPAR_MICROBLAZE_NUM_SYNC_FF_DBG_CLK 1
#define XPAR_MICROBLAZE_NUM_SYNC_FF_DBG_TRACE_CLK 2
#define XPAR_MICROBLAZE_OPCODE_0X0_ILLEGAL 0
#define XPAR_MICROBLAZE_OPTIMIZATION 0
#define XPAR_MICROBLAZE_PART xc7a200tsbg484-1
#define XPAR_MICROBLAZE_PC_WIDTH 32
#define XPAR_MICROBLAZE_PIADDR_SIZE 32
#define XPAR_MICROBLAZE_PVR 0
#define XPAR_MICROBLAZE_PVR_USER1 0x00
#define XPAR_MICROBLAZE_PVR_USER2 0x00000000
#define XPAR_MICROBLAZE_RESET_MSR 0x00000000
#define XPAR_MICROBLAZE_RESET_MSR_BIP 0
#define XPAR_MICROBLAZE_RESET_MSR_DCE 0
#define XPAR_MICROBLAZE_RESET_MSR_EE 0
#define XPAR_MICROBLAZE_RESET_MSR_EIP 0
#define XPAR_MICROBLAZE_RESET_MSR_ICE 0
#define XPAR_MICROBLAZE_RESET_MSR_IE 0
#define XPAR_MICROBLAZE_S0_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S0_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S1_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S1_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S2_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S2_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S3_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S3_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S4_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S4_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S5_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S5_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S6_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S6_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S7_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S7_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S8_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S8_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S9_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S9_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S10_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S10_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S11_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S11_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S12_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S12_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S13_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S13_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S14_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S14_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S15_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S15_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_SCO 0
#define XPAR_MICROBLAZE_TEMPORAL_DEPTH 0
#define XPAR_MICROBLAZE_TRACE 0
#define XPAR_MICROBLAZE_UNALIGNED_EXCEPTIONS 0
#define XPAR_MICROBLAZE_USE_BARREL 0
#define XPAR_MICROBLAZE_USE_BRANCH_TARGET_CACHE 0
#define XPAR_MICROBLAZE_USE_CONFIG_RESET 0
#define XPAR_MICROBLAZE_USE_DCACHE 0
#define XPAR_MICROBLAZE_USE_DIV 0
#define XPAR_MICROBLAZE_USE_EXTENDED_FSL_INSTR 0
#define XPAR_MICROBLAZE_USE_EXT_BRK 0
#define XPAR_MICROBLAZE_USE_EXT_NM_BRK 0
#define XPAR_MICROBLAZE_USE_FPU 0
#define XPAR_MICROBLAZE_USE_HW_MUL 0
#define XPAR_MICROBLAZE_USE_ICACHE 0
#define XPAR_MICROBLAZE_USE_INTERRUPT 2
#define XPAR_MICROBLAZE_USE_MMU 0
#define XPAR_MICROBLAZE_USE_MSR_INSTR 0
#define XPAR_MICROBLAZE_USE_NON_SECURE 0
#define XPAR_MICROBLAZE_USE_PCMP_INSTR 0
#define XPAR_MICROBLAZE_USE_REORDER_INSTR 1
#define XPAR_MICROBLAZE_USE_STACK_PROTECTION 0
#define XPAR_MICROBLAZE_COMPONENT_NAME bd1_inst_0_microblaze_3_0
#define XPAR_MICROBLAZE_EDK_IPTYPE PROCESSOR
#define XPAR_MICROBLAZE_EDK_SPECIAL microblaze
#define XPAR_MICROBLAZE_G_TEMPLATE_LIST 0
#define XPAR_MICROBLAZE_G_USE_EXCEPTIONS 0

/******************************************************************/


/******************************************************************/

/* Platform specific definitions */
#define PLATFORM_MB
 
/* Definitions for sleep timer configuration */
#define XSLEEP_TIMER_IS_DEFAULT_TIMER
 
 
/******************************************************************/
/* Definitions for driver BRAM */
#define XPAR_XBRAM_NUM_INSTANCES 2U

/* Definitions for peripheral BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR */
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_DEVICE_ID 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_DATA_WIDTH 32U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_ECC 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_FAULT_INJECT 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_CE_FAILING_REGISTERS 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_UE_FAILING_REGISTERS 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_ECC_STATUS_REGISTERS 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_CE_COUNTER_WIDTH 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_ECC_ONOFF_REGISTER 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_ECC_ONOFF_RESET_VALUE 1U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_WRITE_ACCESS 2U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_BASEADDR 0x00000000U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_HIGHADDR 0x0001FFFFU
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_S_AXI_CTRL_BASEADDR 0xFFFFFFFFU  
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_S_AXI_CTRL_HIGHADDR 0xFFFFFFFFU  


/* Definitions for peripheral BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR */
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_DEVICE_ID 1U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_DATA_WIDTH 32U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_ECC 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_FAULT_INJECT 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_CE_FAILING_REGISTERS 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_UE_FAILING_REGISTERS 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_ECC_STATUS_REGISTERS 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_CE_COUNTER_WIDTH 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_ECC_ONOFF_REGISTER 0U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_ECC_ONOFF_RESET_VALUE 1U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_WRITE_ACCESS 2U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_BASEADDR 0x00000000U
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_HIGHADDR 0x0001FFFFU
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_S_AXI_CTRL_BASEADDR 0xFFFFFFFFU  
#define XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_S_AXI_CTRL_HIGHADDR 0xFFFFFFFFU  


/******************************************************************/

/* Canonical definitions for peripheral BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR */
#define XPAR_BRAM_0_DEVICE_ID XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_DLMB_BRAM_IF_CNTLR_DEVICE_ID
#define XPAR_BRAM_0_DATA_WIDTH 32U
#define XPAR_BRAM_0_ECC 0U
#define XPAR_BRAM_0_FAULT_INJECT 0U
#define XPAR_BRAM_0_CE_FAILING_REGISTERS 0U
#define XPAR_BRAM_0_UE_FAILING_REGISTERS 0U
#define XPAR_BRAM_0_ECC_STATUS_REGISTERS 0U
#define XPAR_BRAM_0_CE_COUNTER_WIDTH 0U
#define XPAR_BRAM_0_ECC_ONOFF_REGISTER 0U
#define XPAR_BRAM_0_ECC_ONOFF_RESET_VALUE 1U
#define XPAR_BRAM_0_WRITE_ACCESS 2U
#define XPAR_BRAM_0_BASEADDR 0x00000000U
#define XPAR_BRAM_0_HIGHADDR 0x0001FFFFU
#define XPAR_BRAM_0_CTRL_BASEADDR 0xFFFFFFFFU  
#define XPAR_BRAM_0_CTRL_HIGHADDR 0xFFFFFFFEU  
#define XPAR_DLMB_0_CNTLR_BASEADDR 0x00000000
#define XPAR_DLMB_0_CNTLR_HIGHADDR 0x0001FFFF
#define XPAR_DLMB_CNTLR_BASEADDR XPAR_DLMB_0_CNTLR_BASEADDR
#define XPAR_DLMB_CNTLR_HIGHADDR XPAR_DLMB_0_CNTLR_HIGHADDR

/* Canonical definitions for peripheral BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR */
#define XPAR_BRAM_1_DEVICE_ID XPAR_BD1_0_MICROBLAZE_3_LOCAL_MEMORY_ILMB_BRAM_IF_CNTLR_DEVICE_ID
#define XPAR_BRAM_1_DATA_WIDTH 32U
#define XPAR_BRAM_1_ECC 0U
#define XPAR_BRAM_1_FAULT_INJECT 0U
#define XPAR_BRAM_1_CE_FAILING_REGISTERS 0U
#define XPAR_BRAM_1_UE_FAILING_REGISTERS 0U
#define XPAR_BRAM_1_ECC_STATUS_REGISTERS 0U
#define XPAR_BRAM_1_CE_COUNTER_WIDTH 0U
#define XPAR_BRAM_1_ECC_ONOFF_REGISTER 0U
#define XPAR_BRAM_1_ECC_ONOFF_RESET_VALUE 1U
#define XPAR_BRAM_1_WRITE_ACCESS 2U
#define XPAR_BRAM_1_BASEADDR 0x00000000U
#define XPAR_BRAM_1_HIGHADDR 0x0001FFFFU
#define XPAR_BRAM_1_CTRL_BASEADDR 0xFFFFFFFFU  
#define XPAR_BRAM_1_CTRL_HIGHADDR 0xFFFFFFFEU  
#define XPAR_ILMB_0_CNTLR_BASEADDR 0x00000000
#define XPAR_ILMB_0_CNTLR_HIGHADDR 0x0001FFFF
#define XPAR_ILMB_CNTLR_BASEADDR XPAR_ILMB_0_CNTLR_BASEADDR
#define XPAR_ILMB_CNTLR_HIGHADDR XPAR_ILMB_0_CNTLR_HIGHADDR


/******************************************************************/

/* Definitions for driver CAN_CONTROLLER */
#define XPAR_CAN_CONTROLLER_NUM_INSTANCES 1

/* Definitions for peripheral BD1_0_MB3_CAN_CONTROLLER */
#define XPAR_BD1_0_MB3_CAN_CONTROLLER_DEVICE_ID 0
#define XPAR_BD1_0_MB3_CAN_CONTROLLER_S00_AXI_BASEADDR 0x45A00000
#define XPAR_BD1_0_MB3_CAN_CONTROLLER_S00_AXI_HIGHADDR 0x45A0FFFF


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 2

/* Definitions for peripheral BD1_0_MB3_GPIO_LED */
#define XPAR_BD1_0_MB3_GPIO_LED_BASEADDR 0x44010000
#define XPAR_BD1_0_MB3_GPIO_LED_HIGHADDR 0x4401FFFF
#define XPAR_BD1_0_MB3_GPIO_LED_DEVICE_ID 0
#define XPAR_BD1_0_MB3_GPIO_LED_INTERRUPT_PRESENT 0
#define XPAR_BD1_0_MB3_GPIO_LED_IS_DUAL 0


/* Definitions for peripheral BD1_0_MB3_GPIO_SW2 */
#define XPAR_BD1_0_MB3_GPIO_SW2_BASEADDR 0x44020000
#define XPAR_BD1_0_MB3_GPIO_SW2_HIGHADDR 0x4402FFFF
#define XPAR_BD1_0_MB3_GPIO_SW2_DEVICE_ID 1
#define XPAR_BD1_0_MB3_GPIO_SW2_INTERRUPT_PRESENT 0
#define XPAR_BD1_0_MB3_GPIO_SW2_IS_DUAL 0


/******************************************************************/

/* Canonical definitions for peripheral BD1_0_MB3_GPIO_LED */
#define XPAR_GPIO_0_BASEADDR 0x44010000
#define XPAR_GPIO_0_HIGHADDR 0x4401FFFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_BD1_0_MB3_GPIO_LED_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 0
#define XPAR_GPIO_0_IS_DUAL 0

/* Canonical definitions for peripheral BD1_0_MB3_GPIO_SW2 */
#define XPAR_GPIO_1_BASEADDR 0x44020000
#define XPAR_GPIO_1_HIGHADDR 0x4402FFFF
#define XPAR_GPIO_1_DEVICE_ID XPAR_BD1_0_MB3_GPIO_SW2_DEVICE_ID
#define XPAR_GPIO_1_INTERRUPT_PRESENT 0
#define XPAR_GPIO_1_IS_DUAL 0


/******************************************************************/

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 2
#define XPAR_XINTC_HAS_IPR 1
#define XPAR_XINTC_HAS_SIE 1
#define XPAR_XINTC_HAS_CIE 1
#define XPAR_XINTC_HAS_IVR 1
/* Definitions for driver INTC */
#define XPAR_XINTC_NUM_INSTANCES 1

/* Definitions for peripheral BD1_0_MICROBLAZE_3_AXI_INTC */
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_DEVICE_ID 0
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_BASEADDR 0x44200000
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_HIGHADDR 0x4420FFFF
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_KIND_OF_INTR 0xFFFFFFFC
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_HAS_FAST 1
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_IVAR_RESET_VALUE 0x0000000000000010
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_NUM_INTR_INPUTS 2
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_NUM_SW_INTR 0
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_ADDR_WIDTH 32


/******************************************************************/

#define XPAR_INTC_SINGLE_BASEADDR 0x44200000
#define XPAR_INTC_SINGLE_HIGHADDR 0x4420FFFF
#define XPAR_INTC_SINGLE_DEVICE_ID XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_DEVICE_ID
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_TYPE 0U
#define XPAR_BD1_0_MB3_T1_INTERRUPT_MASK 0X000001U
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_BD1_0_MB3_T1_INTERRUPT_INTR 0U
#define XPAR_BD1_0_MB3_CAN_CONTROLLER_IRQN_MASK 0X000002U
#define XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_BD1_0_MB3_CAN_CONTROLLER_IRQN_INTR 1U

/******************************************************************/

/* Canonical definitions for peripheral BD1_0_MICROBLAZE_3_AXI_INTC */
#define XPAR_INTC_0_DEVICE_ID XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_DEVICE_ID
#define XPAR_INTC_0_BASEADDR 0x44200000U
#define XPAR_INTC_0_HIGHADDR 0x4420FFFFU
#define XPAR_INTC_0_KIND_OF_INTR 0xFFFFFFFCU
#define XPAR_INTC_0_HAS_FAST 1U
#define XPAR_INTC_0_IVAR_RESET_VALUE 0x0000000000000010U
#define XPAR_INTC_0_NUM_INTR_INPUTS 2U
#define XPAR_INTC_0_NUM_SW_INTR 0U
#define XPAR_INTC_0_ADDR_WIDTH 32U
#define XPAR_INTC_0_INTC_TYPE 0U

#define XPAR_INTC_0_TMRCTR_1_VEC_ID XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_BD1_0_MB3_T1_INTERRUPT_INTR
#define XPAR_INTC_0_CAN_CONTROLLER_0_VEC_ID XPAR_BD1_0_MICROBLAZE_3_AXI_INTC_BD1_0_MB3_CAN_CONTROLLER_IRQN_INTR

/******************************************************************/

/* Definitions for driver TMRCTR */
#define XPAR_XTMRCTR_NUM_INSTANCES 2U

/* Definitions for peripheral BD1_0_MB3_T0 */
#define XPAR_BD1_0_MB3_T0_DEVICE_ID 0U
#define XPAR_BD1_0_MB3_T0_BASEADDR 0x44C10000U
#define XPAR_BD1_0_MB3_T0_HIGHADDR 0x44C1FFFFU
#define XPAR_BD1_0_MB3_T0_CLOCK_FREQ_HZ 100000000U


/* Definitions for peripheral BD1_0_MB3_T1 */
#define XPAR_BD1_0_MB3_T1_DEVICE_ID 1U
#define XPAR_BD1_0_MB3_T1_BASEADDR 0x44C00000U
#define XPAR_BD1_0_MB3_T1_HIGHADDR 0x44C0FFFFU
#define XPAR_BD1_0_MB3_T1_CLOCK_FREQ_HZ 100000000U


/******************************************************************/

/* Canonical definitions for peripheral BD1_0_MB3_T0 */
#define XPAR_TMRCTR_0_DEVICE_ID 0U
#define XPAR_TMRCTR_0_BASEADDR 0x44C10000U
#define XPAR_TMRCTR_0_HIGHADDR 0x44C1FFFFU
#define XPAR_TMRCTR_0_CLOCK_FREQ_HZ XPAR_BD1_0_MB3_T0_CLOCK_FREQ_HZ
/* Canonical definitions for peripheral BD1_0_MB3_T1 */
#define XPAR_TMRCTR_1_DEVICE_ID 1U
#define XPAR_TMRCTR_1_BASEADDR 0x44C00000U
#define XPAR_TMRCTR_1_HIGHADDR 0x44C0FFFFU
#define XPAR_TMRCTR_1_CLOCK_FREQ_HZ XPAR_BD1_0_MB3_T1_CLOCK_FREQ_HZ

/******************************************************************/

#endif  /* end of protection macro */
