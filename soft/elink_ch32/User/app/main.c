//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "app_cfg.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "ch32v20x.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define TxSize1    (size(TxBuffer1))
#define TxSize2    (size(TxBuffer2))
#define size(a)    (sizeof(a) / sizeof(*(a)))

/* Global typedef */
typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} TestStatus;

/* Global Variable */
u8 TxBuffer1[] = "*Buffer1 Send from USART2 to USART3 using Interrupt!"; /* Send by UART2 */
u8 TxBuffer2[] = "#Buffer2 Send from USART3 to USART2 using Interrupt!"; /* Send by UART3 */
u8 RxBuffer1[TxSize1] = {0};                                             /* USART2 Using */
u8 RxBuffer2[TxSize2] = {0};                                             /* USART3 Using  */

volatile u8 TxCnt1 = 0, RxCnt1 = 0;
volatile u8 TxCnt2 = 0, RxCnt2 = 0;
volatile u8 Rxfinish1 = 0, Rxfinish2 = 0;
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

    /* USART2 TX-->A.2   RX-->A.3 */
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

    USART_Init(USART2, &USART_InitStructure);
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

    USART_Init(USART3, &USART_InitStructure);
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_Cmd(USART2, ENABLE);
    USART_Cmd(USART3, ENABLE);

    //GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIOA->BSHR = 0x0020;
}
void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void USART3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*********************************************************************
 * @fn      USART2_IRQHandler
 *
 * @brief   This function handles USART2 global interrupt request.
 *
 * @return  none
 */
volatile sdt_int8u enalbe_txd = 1;
void USART2_IRQHandler(void)
{
    sdt_int8u rx_rd;
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
        rx_rd = USART_ReceiveData(USART2);
        RxBuffer1[RxCnt1++] = rx_rd;
        if(0x39 == rx_rd)
        {
            enalbe_txd = 1;
        }

        if(RxCnt1 == TxSize2)
        {
            USART_ITConfig(USART2, USART_IT_RXNE, DISABLE);
            Rxfinish1 = 1;
        }
    }
}

/*********************************************************************
 * @fn      USART3_IRQHandler
 *
 * @brief   This function handles USART3 global interrupt request.
 *
 * @return  none
 */
void USART3_IRQHandler(void)
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        RxBuffer2[RxCnt2++] = USART_ReceiveData(USART3);

        if(RxCnt2 == TxSize1)
        {
            USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
            Rxfinish2 = 1;
        }
    }
}

//*********************************************************************
void app_general_task(void)
{
   //mde_watchdog_reload();

    macro_cTimerTig(timer_txtest,timerType_millisecond);

    if(pbc_pull_timerIsCompleted(&timer_txtest))
    {
        enalbe_txd = 1;
        pbc_reload_timerClock(&timer_txtest,500);
        if(enalbe_txd)
        {

            enalbe_txd = 0;
            TxCnt1 = 0;
            GPIOA->BCR = 0x0020;
            while(TxCnt1 < TxSize1) /* USART2--->USART3 */
            {

                sdt_int8u amicode[2];
                sdt_int8u temp_u8;

                temp_u8 = 0x55;
                amicode[0] = (((temp_u8&0x08) << 3) + ((temp_u8&0x04) << 2) + ((temp_u8&0x02) << 1) + (temp_u8&0x01)) + 0xaa;
                amicode[1] = (((temp_u8&0x80) >> 1) + ((temp_u8&0x40) >> 2) + ((temp_u8&0x20) >> 3) + ((temp_u8&0x10) >> 4)) + 0xaa;
                TxCnt1++;

                USART_SendData(USART2, amicode[0]);
                while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET) /* waiting for sending finish */
                {
                }
                USART_SendData(USART2, amicode[1]);
                while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET) /* waiting for sending finish */
                {
                }


            }
            GPIOA->BSHR = 0x0020;
        }
        pbc_easy_printf("TXD");
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
void main(void)
{   
    //mde_watchdog_cfg();
    pbc_system_clock_cfg();
    USARTx_CFG();
    pbc_easy_printf("boot starting\r\n");
    pbc_task_create(app_general_task,0);
	pbc_task_create(app_log_task,2000);
    pbc_task_process();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
