#ifndef __CAN_DRV_H_
#define __CAN_DRV_H_

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include "stdio.h"

#include "gpio_drv.h"


#include "xil_printf.h"

#define     FrameNum      13
#define SJA_BASE_ADR 		0x0			// 以下寄存器定义均修改为偏移地址

#define SJA_MOD   SJA_BASE_ADR + 0x00

#define RM_BIT     0x01  //复位模式请求位
#define LOM_BIT    0x02  //只听模式位
#define STM_BIT    0x04  //自检模式位
#define AFM_BIT    0x08  //验收滤波器模式位
#define SM_BIT     0x10  //睡眠模式位

/**********************
命令寄存器及其位定义
************************/
#define SJA_CMR    SJA_BASE_ADR + 0x01
#define TR_BIT         0x01       //发送请求位
#define AT_BIT         0x02        //中止发送位
#define RRB_BIT        0x04        //释放接收缓冲器位
#define CDO_BIT        0x08        //清除数据溢出位
#define SRR_BIT        0x10        //自身接收请求位

/**********************
状态寄存器及其位定义
************************/
#define SJA_SR     SJA_BASE_ADR + 0x02
#define RBS_BIT           0x01                    //接收缓冲器状态位
#define DOS_BIT           0x02                     //数据溢出状态位
#define TBS_BIT           0x04                      //发送缓冲器状态位
#define TCS_BIT           0x08                      //发送完成状态位
#define RS_BIT            0x10                    //接收状态位
#define TS_BIT            0x20                     //发送状态位
#define ES_BIT            0x40                   //错误状态位
#define BS_BIT            0x80                    //总线状态位

/**********************
中断寄存器及其位定义
************************/
#define SJA_IR     SJA_BASE_ADR + 0x03
#define RI_BIT            0x01                     //接收中断位
#define TI_BIT            0x02                      //发送中断位
#define EI_BIT            0x04                      //错误警告中断位
#define DOI_BIT           0x08                     //数据溢出中断位
#define WUI_BIT           0x10                      //唤醒中断位
#define EPI_BIT           0x20                      //错误消极中断位
#define ALI_BIT           0x40                     //仲裁丢失中断位
#define BEI_BIT           0x80                    //总线错误中断位

/**********************
中断使能寄存器及其位定义
************************/
#define SJA_IER    SJA_BASE_ADR + 0x04
#define RIE_BIT           0x01                     //接收中断使能位
#define TIE_BIT           0x02                      //发送中断使能位
#define EIE_BIT           0x04                      //错误警告中断使能位
#define DOIE_BIT          0x08                      //数据溢出中断使能位
#define WUIE_BIT          0x10                      //唤醒中断使能位
#define EPIE_BIT          0x20                      //错误消极中断使能位
#define ALIE_BIT          0x40                      //仲裁丢失中断使能位
#define BEIE_BIT          0x80                     //总线错误中断使能位


#define SJA_BTR0   SJA_BASE_ADR + 0x06	  //总线定时器0寄存器
#define SJA_BTR1   SJA_BASE_ADR + 0x07	  //总线定时器1寄存器
#define SAM_BIT           0x80               //采样模式位；0==总线被采样1次；1== 总线被采样3次

/**********************
输出控制寄存器及其位定义
************************/
#define SJA_OCR    SJA_BASE_ADR + 0x08
           /*OCMODE1 ，OCMODE0 */
#define BiPhaseMode       0x00                      //双相输出模式
#define NormalMode        0x02                  //正常输出模式
#define ClkOutMode        (0x01|0x02)       //时钟输出模式
           /*TX1 的输出管脚配置*/
#define OCPOL1_BIT        0x20                  //输出极性控制位
#define Tx1Float          0x00                      //配置为悬空
#define Tx1PullDn         0x40                  //配置为下拉
#define Tx1PullUp         0x80                 //配置为上拉
#define Tx1PshPull        (0x40|0x80)       //配置为推挽
            /*TX0 的输出管脚配置*/
#define OCPOL0_BIT        0x04                      //输出极性控制位
#define Tx0Float          0x00                      //配置为悬空
#define Tx0PullDn         0x08                      //配置为下拉
#define Tx0PullUp         0x10                      //配置为上拉
#define Tx0PshPull        (0x10|0x08)                    //配置为推挽

#define SJA_TEST   SJA_BASE_ADR + 0x09         //测试寄存器

/********************************
 * #define SJA_10   SJA_BASE_ADR + 0x0a   寄存器功能保留
 ********************************/

/**********************
其他寄存器及其位定义
************************/
#define SJA_ALC      SJA_BASE_ADR + 0x0b		//仲裁丢失捕捉寄存器
#define SJA_ECC      SJA_BASE_ADR + 0x0c		//错误捕捉寄存器
#define SJA_EWLR     SJA_BASE_ADR + 0x0d		//错误报警限制寄存器
#define SJA_RXERR    SJA_BASE_ADR + 0x0e		//RX 错误计数器寄存器
#define SJA_TXERR    SJA_BASE_ADR + 0x0f		//TX 错误计数器寄存器

/**********************
验收滤波器寄存器及其位定义
************************/
#define SJA_ACR0     SJA_BASE_ADR + 0x10		//验收代码0寄存器
#define SJA_ACR1     SJA_BASE_ADR + 0x11		//验收代码1寄存器
#define SJA_ACR2     SJA_BASE_ADR + 0x12		//验收代码2寄存器
#define SJA_ACR3     SJA_BASE_ADR + 0x13		//验收代码3寄存器

#define SJA_AMR0     SJA_BASE_ADR + 0x14		//验收屏蔽0寄存器
#define SJA_AMR1     SJA_BASE_ADR + 0x15		//验收屏蔽1寄存器
#define SJA_AMR2     SJA_BASE_ADR + 0x16		//验收屏蔽2寄存器
#define SJA_AMR3     SJA_BASE_ADR + 0x17		//验收屏蔽3寄存器

/**********************
TX缓冲器地址定义
************************/
#define SJA_TBSR0    SJA_BASE_ADR + 0x10
#define SJA_TBSR1    SJA_BASE_ADR + 0x11
#define SJA_TBSR2    SJA_BASE_ADR + 0x12
#define SJA_TBSR3    SJA_BASE_ADR + 0x13
#define SJA_TBSR4    SJA_BASE_ADR + 0x14
#define SJA_TBSR5    SJA_BASE_ADR + 0x15
#define SJA_TBSR6    SJA_BASE_ADR + 0x16
#define SJA_TBSR7    SJA_BASE_ADR + 0x17
#define SJA_TBSR8    SJA_BASE_ADR + 0x18
#define SJA_TBSR9    SJA_BASE_ADR + 0x19
#define SJA_TBSR10   SJA_BASE_ADR + 0x1a
#define SJA_TBSR11   SJA_BASE_ADR + 0x1b
#define SJA_TBSR12   SJA_BASE_ADR + 0x1c

/**********************
RX缓冲器地址定义
************************/
#define SJA_RBSR0    SJA_BASE_ADR + 0x10
#define SJA_RBSR1    SJA_BASE_ADR + 0x11
#define SJA_RBSR2    SJA_BASE_ADR + 0x12
#define SJA_RBSR3    SJA_BASE_ADR + 0x13
#define SJA_RBSR4    SJA_BASE_ADR + 0x14
#define SJA_RBSR5    SJA_BASE_ADR + 0x15
#define SJA_RBSR6    SJA_BASE_ADR + 0x16
#define SJA_RBSR7    SJA_BASE_ADR + 0x17
#define SJA_RBSR8    SJA_BASE_ADR + 0x18
#define SJA_RBSR9    SJA_BASE_ADR + 0x19
#define SJA_RBSR10   SJA_BASE_ADR + 0x1a
#define SJA_RBSR11   SJA_BASE_ADR + 0x1b
#define SJA_RBSR12   SJA_BASE_ADR + 0x1c

#define SJA_RMC      SJA_BASE_ADR + 0x1d           //RX 信息计数器 寄存器
#define SJA_RBSA     SJA_BASE_ADR + 0x1e            //RX 缓冲区起始地址 寄存器

/**********************
时钟分频寄存器地址定义
************************/
#define SJA_CDR       SJA_BASE_ADR + 0x1f		 //时钟分频 寄存器
#define CLKOff_BIT        0x08                     //时钟关闭位，时钟输出管脚控制位
#define RXINTEN_BIT       0x20                      //用于接收中断的管脚TX1
#define CBP_BIT           0x40                      //CAN 比较器旁路控制位
#define CANMode_BIT       0x80                     //CAN 模式控制位



//pin def

// Bit offset
#define RST 0x04
#define ALE 0x03
#define RD  0x02
#define WR  0x01
#define CS  0x00

// RXD byte offset
#define CAN_PRX_BYTE 0x00
#define CAN_RXD_BYTE 0x01


#define CAN_CMD_BYTE 0x00

struct can_regs {
    volatile uint32_t control;
    volatile uint32_t tx_fifo;
    volatile uint32_t rx_fifo;
    volatile uint32_t reg3;
};

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


#define PELI 0x88
#define CAN_CONFIG 0xf8

/*Device ID*/
#define MB0_CAN0_ID 0x02
#define MB0_CAN1_ID 0x03

#define MB1_CAN0_ID 0x04
#define MB2_CAN0_ID 0x05
#define MB3_CAN0_ID 0x06


struct can_data_frame
{
    /* data mdoe */
    uint8_t data_mode;
    /* data addr */
    uint8_t addr1;
    uint8_t addr2;
    uint8_t addr3;
    /* config code */
    uint8_t config_code;
    /* Data */
    uint8_t data0;
    uint8_t data1;
    uint8_t data2;
    uint8_t data3;
    uint8_t data4;
    uint8_t data5;
    uint8_t data6;
    uint8_t data7;
    /*CAN controller ADDR*/
    uint32_t can_addr;
};



void can_init(uint32_t can_addr);
void can_set_pin(uint32_t can_addr, uint8_t pin, uint8_t value);
void can_set_data(uint32_t can_addr, uint8_t value);
uint8_t can_read_data(uint32_t can_addr);
void write_register(uint32_t can_addr, uint8_t reg_addr, uint8_t reg_data);
uint8_t read_register(uint32_t can_addr, uint8_t reg_addr);
void can_txd(uint32_t can_addr);
void can_rxd(uint32_t can_addr);
void can_txd_frame(struct can_data_frame *frame);
struct can_data_frame initialize_can_data_frame(addr1,addr2,addr3,can_addr);
void can_rxd_frame(struct can_data_frame *frame);

#endif
