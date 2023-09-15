//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\snail_data_types.h"
#include "ch32v20x.h"
// #include "intrinsics.h"
#include "bsp_tick_small.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define DSIABLE_INTERRUPT  __disable_irq()
#define ENABLE_INTERRUPT   __enable_irq()
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//-----------------------------------------------------------------------------
//Timer2  us tick
//Timer2  ms tick GPTM
//-----------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称:CH32V203时钟配置
//功能:配置晶振、FLASH等待时间、系统时钟
//HSE 12M
//PLL 72M
//入口:无,在系统复位后,第一个调用
//出口:无
//-----------------------------------------------------------------------------
static void bsp_clock_cfg(void)
{

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static sdt_int16u tick_millsecond;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
sdt_int16u bsp_pullSystemTickCount(void)
{
    return(tick_millsecond);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//EPF 端口:PA07
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称:系统滴答时钟配置
//功能:TIM2配置为系统时钟定时器
//500us的中断定时器
//------------------------------------------------------------------------------
#define BASE_CNT        500
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
//--------------------------------------------------------------------------------
void bsp_system_tick_cfg(void)
{
    bsp_clock_cfg();

    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//----------------------------------------------------------------------------------
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM2->CTLR1 = 0x0080; //0000 - 00 00 - 1 00 0 - 0000
    TIM2->CTLR2 = 0x0000;
    TIM2->PSC = 71;              //1us
    TIM2->ATRLR = BASE_CNT;
    TIM2->DMAINTENR = 0x0001;  //UIE

    TIM2->CTLR1 |= 0x0001;  //CEN

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

   //NVIC_EnableIRQ(TIM2_IRQn);
    __enable_irq();

//------------------------------------------------------------------------------
    #ifdef EPF_LOG_EN//EPF字符端口
    GPIO_Toggle_INIT();
    #endif


//------------------------------------------------------------------------------

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//UIF,32位微秒计数处理
//CCR0A CA0F 比较中断,500u中断,1ms系统时隙
//------------------------------------------------------------------------------
static sdt_int16u tick_mircs_h;
//------------------------------------------------------------------------------
#ifdef EPF_LOG_EN
static sdt_int8u epf_buff[64];
static volatile sdt_int8u epf_pmd_in;
static volatile sdt_int8u epf_pmd_ot;
static volatile sdt_int32u epf_shift_reg;
static volatile sdt_int32u epf_shift_mask;
static volatile sdt_int32u epf_status_reg;
#define ESRG_PERAMBLE     0x01
#define ESRG_SYNC         0x02
#define ESRG_PAYLOAD      0x04
#define ESRG_EOF          0x08
#endif
//------------------------------------------------------------------------------
void TIM2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//------------------------------------------------------------------------------
void TIM2_IRQHandler(void)
{
    static sdt_int8u base_tick;
    
    if(TIM2->INTFR & 0x0001)
    {

        TIM2->INTFR &= ~0x0001;
//         M0P_TIM2_MODE23->ICLR_f.CA0F = 0;
//         M0P_TIM2_MODE23->CCR0A_f.CCR0A += BASE_CNT;
         base_tick ++;
         if(base_tick & 0x01)
         {
             tick_millsecond ++;
         }
         #ifdef EPF_LOG_EN
         sdt_int8u temp_8u;
         if(0 == epf_shift_mask)
         {
             if(epf_status_reg & ESRG_PERAMBLE)
             {
                 epf_status_reg &= ~ESRG_PERAMBLE;
                 epf_shift_reg = 0x00005555;
                 epf_shift_mask = 0x0008000;
             }
             else if(epf_status_reg & ESRG_SYNC)
             {
                 epf_status_reg &= ~ESRG_SYNC;
                 epf_shift_reg = 0x0000007F;
                 epf_shift_mask = 0x0000080;
             }
             else if(epf_status_reg & ESRG_PAYLOAD)
             {
                 if(epf_pmd_in != epf_pmd_ot)
                 {
                     temp_8u = epf_buff[epf_pmd_ot];//取字节数据
                     epf_pmd_ot++;
                     if(epf_pmd_ot > (sizeof(epf_buff) - 1))
                     {
                         epf_pmd_ot = 0;
                     }
                     if(epf_pmd_ot == epf_pmd_in)
                     {
                         epf_status_reg &= ~ESRG_PAYLOAD;
                     }
                     epf_shift_reg = 0;//生成发送电平
                     if(temp_8u & 0x01)
                     {
                         epf_shift_reg |= 0x000000001;
                     }
                     else 
                     {
                         epf_shift_reg |= 0x000000007;
                     }
                     if(temp_8u & 0x02)
                     {
                         epf_shift_reg |= (0x000000001 << 4);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 4);
                     }
                     if(temp_8u & 0x04)
                     {
                         epf_shift_reg |= (0x000000001 << 8);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 8);
                     }
                     if(temp_8u & 0x08)
                     {
                         epf_shift_reg |= (0x000000001 << 12);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 12);
                     }
                     if(temp_8u & 0x10)
                     {
                         epf_shift_reg |= (0x000000001 << 16);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 16);
                     }
                     if(temp_8u & 0x20)
                     {
                         epf_shift_reg |= (0x000000001 << 20);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 20);
                     }
                     if(temp_8u & 0x40)
                     {
                         epf_shift_reg |= (0x000000001 << 24);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 24);
                     }
                     if(temp_8u & 0x80)
                     {
                         epf_shift_reg |= (0x000000001 << 28);
                     }
                     else 
                     {
                         epf_shift_reg |= (0x000000007 << 28);
                     }
                     epf_shift_mask = 0x80000000;
                 }
             }
             else if(epf_status_reg & ESRG_EOF)
             {
                 epf_status_reg &= ~ESRG_EOF;
                 epf_shift_reg = 0x00000001;
                 epf_shift_mask = 0x0000080;
             }
         }
         if(0 != epf_shift_mask)
         {
             if(epf_shift_reg & epf_shift_mask)
             {
                 GPIOA->BSHR = 0x0080;     //dark
             }
             else
             {
                 GPIOA->BCR = 0x0080;     //light
             }
             epf_shift_mask = epf_shift_mask >> 1;
         }        
         #endif

// //------------------------------------------------------------------------------
// //       static sdt_int16u distance_t;
// //       do
// //       {
// //           M0P_TIM2_MODE23->ICLR_f.CA0F = 0;
// //           M0P_TIM2_MODE23->CCR0A_f.CCR0A += BASE_CNT;
// //           distance_t = M0P_TIM2_MODE23->CCR0A_f.CCR0A;
// //           distance_t = distance_t - M0P_TIM2_MODE23->CNT_f.CNT;
// //           base_tick ++;
// //           if(base_tick & 0x01)
// //           {
// //               tick_millsecond ++;    
// //           }
// //       }while(distance_t > BASE_CNT);  //此现象由某个其他中断大于500us的情况造成
     }
    // if(0 != M0P_TIM2_MODE23->IFR_f.UIF)
    // {
        // M0P_TIM2_MODE23->ICLR_f.UIF = 0;
        // tick_mircs_h ++;               //us 高16bit
    // }
}
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
sdt_int32u bsp_pull_us_count_32bits(void)
{
    sdt_int32u rd_us_cnt;
    sdt_int16u rd_us_h;

    do
    {
        rd_us_h = tick_mircs_h;
        rd_us_cnt = rd_us_h;
        rd_us_cnt = rd_us_cnt << 16;
//        rd_us_cnt |= M0P_TIM2_MODE23->CNT_f.CNT;
    }while(rd_us_h != tick_mircs_h);
    
    return(rd_us_cnt);

}
//------------------------------------------------------------------------------
sdt_int16u bsp_pull_us_count_16bits(void)
{
    static sdt_int16u rd_us_cnt;
    
    rd_us_cnt++;
//    rd_us_cnt = M0P_TIM2_MODE23->CNT_f.CNT;
    return(rd_us_cnt);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//EPF打印接口
//in:字符串文本
//out:失败指示,sdt_true--转移失败(缓冲区无法容纳转移的字符串长度)
//------------------------------------------------------------------------------
#ifdef EPF_LOG_EN
sdt_bool bsp_easy_printf(sdt_int8s* in_pStr)
{
    
    sdt_int8u full;
    sdt_int8u rd_pmd_in;
    sdt_int8u rd_pmd_ot;
    sdt_int8u trs_bytes;
    sdt_int8u i;

    full = sdt_true;
    rd_pmd_in = epf_pmd_in;
    rd_pmd_ot = epf_pmd_ot;

    rd_pmd_in ++;
    if(rd_pmd_in > (sizeof(epf_buff) - 1))
    {
        rd_pmd_in = 0;
    }
    
    if(rd_pmd_in == rd_pmd_ot)//full
    {
    }
    else
    {
        rd_pmd_ot --;
        if(rd_pmd_ot > (sizeof(epf_buff) - 1))
        {
            rd_pmd_ot = (sizeof(epf_buff) - 1);
        }
        //计算字符串和缓冲区的大小,决定是否转移数据
        if(epf_pmd_in == rd_pmd_ot)//buff is full
        {
            return(sdt_true);
        }
        else if(epf_pmd_in > rd_pmd_ot)
        {
            trs_bytes = sizeof(epf_buff) - (epf_pmd_in - rd_pmd_ot);
        }
        else 
        {
            trs_bytes = (rd_pmd_ot - epf_pmd_in);
        }
        for(i = 0;i < trs_bytes;i++)
        {
            if(0 == in_pStr[i])
            {
                full = sdt_false;
                break;
            }            
        }
        if(sdt_false == full)
        {
            i = 0;
            while(0 != in_pStr[i])//转移数据
            {
                epf_buff[epf_pmd_in] = (sdt_int8u)in_pStr[i];
                DSIABLE_INTERRUPT;
                epf_pmd_in++;
                if(epf_pmd_in > (sizeof(epf_buff) - 1))
                {
                    epf_pmd_in = 0;
                }
                ENABLE_INTERRUPT;
                i++;
            }
            DSIABLE_INTERRUPT;
            if(0 == epf_status_reg)
            {
                epf_status_reg = (ESRG_PERAMBLE + ESRG_SYNC + ESRG_PAYLOAD + ESRG_EOF);
            }
            else
            {
                epf_status_reg |= ESRG_PAYLOAD;
            }
            ENABLE_INTERRUPT;
        }
    }                         
    return(full);
}
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
