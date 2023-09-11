//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\snail_data_types.h"
#include "ch32v20x.h"
// #include "intrinsics.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define DSIABLE_INTERRUPT  __disable_irq()
#define ENABLE_INTERRUPT   __enable_irq()
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

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 | RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    /* USART3 TX-->A.2   RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* USART3 TX-->B.10  RX-->B.11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 19200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

//    USART_Init(USART2, &USART_InitStructure);
//    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

    USART_Init(USART3, &USART_InitStructure);
    USART_ITConfig(USART3, (USART_IT_TXE + USART_IT_RXNE), ENABLE);

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
    GPIOA->BSHR = 0x0020;                          //debug io

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  //PC13
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIOC->BSHR = 0x2000;                          //debug io

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void USART3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*********************************************************************
 * @fn      USART3_IRQHandler
 *
 * @brief   This function handles USART3 global interrupt request.
 *
 * @return  none
 */
void USART3_IRQHandler(void)
{
    sdt_int8u rx_data;
    sdt_int8u index_shadow;
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        if(RESET != USART_GetFlagStatus(USART3,USART_FLAG_RXNE))
        {
            rx_data = USART_ReceiveData(USART3);

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

    sdt_int8u tx_data;
    sdt_bool tx_end = sdt_false;
    if(RESET != USART_GetITStatus(USART3, USART_IT_TXE))
    {
        if(RESET != USART_GetFlagStatus(USART3,USART_FLAG_TXE))
        {
            if(tx_in == tx_out) //send data is empty
            {
                tx_end = sdt_true;
            }
            else
            {
                tx_data = tx_buff[tx_out];
                tx_out ++;
                if(tx_out > (TXB_SIZE - 1))
                {
                    tx_out = 0;
                }
                if(tx_in == tx_out)    //next is empty
                {

                }
                USART_SendData(USART3,tx_data);
                USART_ClearFlag(USART3,USART_FLAG_TC);
            }
            if(tx_end)
            {
                USART_ITConfig(USART3, (USART_IT_TXE), DISABLE);
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
    return(0);
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

    return(0);
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
    return(0);
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
    if(tx_in == tx_out)
    {
        if(RESET == USART_GetITStatus(USART3, USART_IT_TXE))
        {
            if(RESET != USART_GetFlagStatus(USART3,USART_FLAG_TC))
            {
                GPIOA->BSHR = 0x0020;                         //debug io
                GPIOC->BSHR = 0x2000;
                return(sdt_true);
            }
        }
    }
    return(sdt_false);
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
    GPIOA->BCR = 0x0020;                           //debug io
    GPIOC->BCR = 0x2000;
    return(remain_bytes);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
