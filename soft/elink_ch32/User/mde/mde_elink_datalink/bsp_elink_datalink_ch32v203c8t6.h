//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\snail_data_types.h"
#include "ch32v20x.h"
// #include "intrinsics.h"
#include "..\..\pbc\pbc_pilot_light\pbc_pilot_light.h"
//--------------------------------------------------------------------
#include "stdlib.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define DSIABLE_INTERRUPT  __disable_irq()
#define ENABLE_INTERRUPT   __enable_irq()
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef enum
{
    TXCPC_IDLE  = 0x00,
    TXCPC_TOEND = 0x01,
    TXCPC_WTEND = 0x02,
    TXCPC_ISEND = 0x03,
}TXDCMPC_DEF;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static volatile sdt_int16u rand_seed;
static volatile sdt_bool bus_busy;
static volatile sdt_bool bus_conflict;
static volatile TXDCMPC_DEF txdcmpc;
static volatile sdt_int8u ctrl_conflict;
static volatile sdt_int8u rx_ami_idx = 0;
static sdt_int8u rx_ami[2];
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//TIM3 总线忙碌检测,下降延发生后,后续2000us视为总线忙碌,TIM3用于2000us的释放时间,约4个字符的时间,同时清洗AMI接收编码的index
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void bsp_tim3_cfg(void)
{

    NVIC_InitTypeDef  NVIC_InitStructure = {0};

   // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//----------------------------------------------------------------------------------
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    TIM3->CTLR1 = 0x0088;        //0000 - 00 00 - 1 00 0 - 1000
    TIM3->CTLR2 = 0x0000;
    TIM3->PSC = 71;              //1us
    TIM3->ATRLR = 2000;
    TIM3->DMAINTENR = 0x0001;    //UIE

    TIM3->CTLR1 |= 0x0001;       //CEN

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

//------------------------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
void TIM3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//------------------------------------------------------------------------------
void TIM3_IRQHandler(void)
{
    if(TIM3->INTFR & 0x0001)
    {
        TIM3->INTFR &= ~0x0001;

        //rx_ami_idx = 0;
        bus_busy = sdt_false;
        if(TXCPC_WTEND == txdcmpc)
        {
            txdcmpc = TXCPC_ISEND;
        }
        //GPIOA->BSHR = 0x8000;
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
////-------------------------------------------------------------------------
//void EXTI0_IRQHandler(void)
//{
//   if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
//   {
//      //GPIOA->BCR = 0x8000;
//
//      bus_busy = sdt_true;
//      TIM3->CTLR1 &= ~0x0001;
//      TIM3->CNT = 0;
//      TIM3->CTLR1 = 0x0001;  //CEN
//      EXTI_ClearITPendingBit(EXTI_Line0);     /* Clear Flag */
//   }
//}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void EXTI15_10_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//-------------------------------------------------------------------------
void EXTI15_10_IRQHandler(void)
{
   if(EXTI_GetITStatus(EXTI_Line11)!=RESET)
   {
       //PILOT_PARA_DEF  pilot_para;
       //
       //pilot_para.led_num = 0;
       //pilot_para.loop_cnt = 1;
       //pilot_para.lighten_ms = 100;
       //pilot_para.dark_ms = 100;
       //
       //pbc_push_pilot_light_ldms(&pilot_para);

      bus_busy = sdt_true;
      TIM3->CTLR1 &= ~0x0001;
      TIM3->CNT = 0;
      TIM3->CTLR1 = 0x0001;  //CEN
      EXTI_ClearITPendingBit(EXTI_Line11);     /* Clear Flag */
   }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART2 & USART3 peripheral.
 *
 * @return  none
 */
void USARTx_CFG(void)
{

    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    bsp_tim3_cfg();

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 | RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);


    /* USART3 TX-->B.10  RX-->B.11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    EXTI_InitTypeDef EXTI_InitStructure = {0};

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
    EXTI_InitStructure.EXTI_Line = EXTI_Line11;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    EXTI->INTENR &= (~EXTI_Line11);

    //EXTI_InitTypeDef EXTI_InitStructure = {0};
    ////NVIC_InitTypeDef NVIC_InitStructure = {0};
    ///* GPIOA ----> EXTI_Line0 */
    //GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
    //EXTI_InitStructure.EXTI_Line = EXTI_Line0;
    //EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    //EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    //EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    //EXTI_Init(&EXTI_InitStructure);
    //
    //NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    //NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    //NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    //NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    //NVIC_Init(&NVIC_InitStructure);


    USART_InitStructure.USART_BaudRate = 19200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;


    USART_Init(USART3, &USART_InitStructure);
    USART_ITConfig(USART3, (USART_IT_TXE), ENABLE);
    USART_ITConfig(USART3, (USART_IT_RXNE), ENABLE);



//    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

//    USART_Cmd(USART2, ENABLE);
    USART_Cmd(USART3, ENABLE);

    //GPIO_InitTypeDef GPIO_InitStructure = {0};
    //A.05  EN
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIOA->BSHR = 0x0020;                          //control io


}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define RXB_SIZE  128
#define TXB_SIZE  128
static sdt_int8u tx_buff[TXB_SIZE];
static sdt_int8u tx_in = 0;
static sdt_int8u tx_out = 0;
static sdt_int8u rx_buff[RXB_SIZE];
static sdt_int8u rx_in = 0;
static sdt_int8u rx_out = 0;
#define CFT_SIZE  6
static sdt_int8u cft_buff[CFT_SIZE];
static sdt_int8u cft_in = 0;
static sdt_int8u cft_out = 0;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void USART3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define CTRLCFT_CHKING  0x01
#define CTRLCFT_TOEND   0x02
/*********************************************************************
 * @fn      USART3_IRQHandler
 *
 * @brief   This function handles USART3 global interrupt request.
 *
 * @return  none
 */
//--------------------------------------------------------------------
void USART3_IRQHandler(void)
{
    sdt_int8u rx_data;
    sdt_int8u loop_data;
    sdt_int8u index_shadow;


    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {

        if(RESET != USART_GetFlagStatus(USART3,USART_FLAG_RXNE))
        {

            rx_data = USART_ReceiveData(USART3);

            if(ctrl_conflict)
            {
                rand_seed += rx_data;
                if(cft_in == cft_out)  //empty rxd is error data
                {

                }
                else
                {
                    loop_data = cft_buff[cft_out];
                    cft_out ++;
                    if(cft_out > (CFT_SIZE - 1))
                    {
                        cft_out = 0;
                    }
                    if(cft_in == cft_out)    //next is empty
                    {
                        if(ctrl_conflict & CTRLCFT_TOEND)
                        {
                            ctrl_conflict = 0;
                        }
                    }
                    if(loop_data == rx_data)
                    {
                        //GPIOC->BCR = 0x2000;   //debug
                    }
                    else
                    {//conflict is occurrence
                        //tx_in = 0;
                        //tx_out = 0;
                        tx_in = tx_out;
                        USART_ITConfig(USART3, (USART_IT_TXE), DISABLE);
                        bus_conflict = sdt_true;
                        //GPIOC->BSHR = 0x2000;   //debug
                    }
                }
            }
            else
            {

                rx_ami[rx_ami_idx] = rx_data;
                rx_ami_idx ++;
                if(rx_ami_idx > 1)
                {
                    rx_ami_idx = 0;
                    rx_data = (rx_ami[0] & 0x01) + ((rx_ami[0] & 0x04) >> 1) + ((rx_ami[0] & 0x10) >> 2) + ((rx_ami[0] & 0x40) >> 3);
                    rx_data = rx_data + ((rx_ami[1] & 0x01) << 4) + ((rx_ami[1] & 0x04) << 3) + ((rx_ami[1] & 0x10) << 2) + ((rx_ami[1] & 0x40) << 1);

                    index_shadow = rx_in;
                    index_shadow ++;                  //calculate next index
                    if(index_shadow > (RXB_SIZE - 1))
                    {
                        index_shadow = 0;
                    }
                    if(index_shadow == rx_out) //overflow
                    {

                    }
                    else
                    {
                        rx_buff[rx_in] = rx_data;
                        rx_in = index_shadow;
                    }
                }
            }
        }
    }

    sdt_int8u tx_data;
    sdt_bool tx_end = sdt_false;
    static sdt_int8u amicode[2];
    static sdt_bool next_ami = sdt_false;

    if(0x00 != (USART3->CTLR1 & USART_CTLR1_TXEIE))
    {
        if(0x00 != (USART3->STATR & USART_FLAG_TXE))
        {
            if(next_ami)
            {
                next_ami = sdt_false;
                tx_data = amicode[1];
            }
            else
            {
                if(tx_in == tx_out) //send data is empty
                {
                    tx_end = sdt_true;
                }
                else
                {
                    sdt_int8u transfet;
                    transfet = tx_buff[tx_out];
                    tx_out ++;
                    if(tx_out > (TXB_SIZE - 1))
                    {
                        tx_out = 0;
                    }
                    if(tx_in == tx_out)    //next buff is empty
                    {

                    }
                    amicode[0] = (((transfet&0x08) << 3) + ((transfet&0x04) << 2) + ((transfet&0x02) << 1) + (transfet&0x01)) + 0xaa;
                    amicode[1] = (((transfet&0x80) >> 1) + ((transfet&0x40) >> 2) + ((transfet&0x20) >> 3) + ((transfet&0x10) >> 4)) + 0xaa;
                    next_ami = sdt_true;

                    tx_data = amicode[0];
                }
            }
            if(tx_end)
            {
                ctrl_conflict |= CTRLCFT_TOEND;
                USART_ITConfig(USART3, (USART_IT_TXE), DISABLE);

                txdcmpc = TXCPC_TOEND;
            }
            else
            {
                sdt_int8u cft_shadow;
                cft_shadow = cft_in;
                cft_shadow ++;
                if(cft_shadow > (CFT_SIZE - 1))
                {
                    cft_shadow = 0;
                }
                if(cft_shadow == cft_out)  //overflow
                {//conflict is occurrence , bus is error or line off
                    //tx_in = 0;
                    tx_in = tx_out;
                    USART_ITConfig(USART3, (USART_IT_TXE), DISABLE);
                    bus_conflict = sdt_true;
                    //GPIOC->BSHR = 0x2000;   //debug
                }
                else
                {
                    cft_buff[cft_in] = tx_data;
                    cft_in = cft_shadow;
                }
                ctrl_conflict = CTRLCFT_CHKING;
                USART_SendData(USART3,tx_data);
                USART_ClearFlag(USART3,USART_FLAG_TC);
                txdcmpc = TXCPC_IDLE;
            }
        }
    }
}
//*********************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------
void bsp_elink_phy_cfg(void)
{
    USARTx_CFG();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 获取接收数据
//功能:
//入口: 接收字节的指针
//
//出口: sdt_true 收到有效数据
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_receive_byte(sdt_int8u* pOut_rcb)
{
    sdt_int8u rx_in_shadow,rx_out_shadow;
    sdt_int8u data_shadow;

    DSIABLE_INTERRUPT;
    rx_in_shadow = rx_in;
    rx_out_shadow = rx_out;
    ENABLE_INTERRUPT;


    if(rx_in_shadow == rx_out_shadow) //send data is empty
    {
        return(sdt_false);
    }
    else
    {
        data_shadow = rx_buff[rx_out_shadow];
        rx_out_shadow++;
        if(rx_out_shadow > (RXB_SIZE - 1))
        {
            rx_out_shadow = 0;
        }

        DSIABLE_INTERRUPT;
        rx_out = rx_out_shadow;
        ENABLE_INTERRUPT;

        *pOut_rcb = data_shadow;
        return(sdt_true);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: PHY忙碌状态指示
//功能:
//入口:
//
//出口: sdt_true PHY忙碌
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_busy(void)
{

    return(bus_busy);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 发送冲突指示
//功能:
//入口:
//
//出口: sdt_true 发生冲突
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_tx_conflict(void)
{
    sdt_bool sd_cft;

    sd_cft = bus_conflict;
    DSIABLE_INTERRUPT;
    bus_conflict = sdt_false;
    ENABLE_INTERRUPT;

    return(sd_cft);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 发送完成指示
//功能:
//入口:
//
//出口: sdt_true 数据发送完成
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_tx_cpt(void)
{
    TXDCMPC_DEF sdw_txdcmpc;

    sdw_txdcmpc = txdcmpc;
    if(TXCPC_TOEND == sdw_txdcmpc)
    {
        txdcmpc = TXCPC_WTEND;
        TIM3->CTLR1 &= ~0x0001;
        TIM3->CNT = 0;
        TIM3->CTLR1 = 0x0001;  //CEN
    }
    else if(TXCPC_ISEND == sdw_txdcmpc)
    {
        txdcmpc = TXCPC_IDLE;
        GPIOA->BSHR = 0x0020;


        return(sdt_true);
    }

    return(sdt_false);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: PHY开始进入发送状态
//功能:
//入口:
//
//出口:
//------------------------------------------------------------------------------
void bsp_push_phy_start_tx(void)
{
    EXTI->INTENR &= (~EXTI_Line11);

    cft_in = 0;
    cft_out = 0;
    bus_conflict = sdt_false;
    GPIOA->BCR = 0x0020;

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: PHY开始进入接收状态
//功能:
//入口:
//
//出口:
//------------------------------------------------------------------------------
void bsp_push_phy_start_rx(void)
{
    rx_ami_idx = 0;
    ctrl_conflict = 0;
    GPIOA->BSHR = 0x0020;

    EXTI->INTFR = (EXTI_Line11);
    EXTI->INTENR |= (EXTI_Line11);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 转移数据到phy的发送缓冲区
//功能:
//入口: in_pByte   转移数据的字节指针
//      in_expect_bytes  期望发送的数据字节数
//
//出口: 剩余未转移字节数
//------------------------------------------------------------------------------
sdt_int16u bsp_transfet_bytes_to_phy_tx(sdt_int8u* in_pByte,sdt_int16u in_expect_bytes)
{
    sdt_int8u index_shadow;
    sdt_int8u i = 0;
    sdt_int16u remain_bytes;

    remain_bytes = in_expect_bytes;
    while(1)
    {
        if(bus_conflict)
        {
            DSIABLE_INTERRUPT;
            tx_in = tx_out;
            ENABLE_INTERRUPT;
            return(0);
        }
        index_shadow = tx_in;
        index_shadow++;
        if(index_shadow > (TXB_SIZE - 1))
        {
            index_shadow = 0;
        }
        if(index_shadow == tx_out) //overflow
        {
            break;
        }
        else
        {
            DSIABLE_INTERRUPT;
            tx_buff[tx_in] = in_pByte[i];
            tx_in = index_shadow;
            ENABLE_INTERRUPT;
            i++ ;
            remain_bytes --;
            if(0 == remain_bytes)
            {
                break;
            }
        }
    }
    USART_ITConfig(USART3, (USART_IT_TXE), ENABLE);


    return(remain_bytes);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 获取避退随机数时间,由BSP产生避退随机数
//功能:
//入口:
//
//
//出口: 避退随机数时间,ms
//------------------------------------------------------------------------------
sdt_int16u bsp_pull_random_backtime(void)
{
    srand(rand_seed);

    return(rand()%2048);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
