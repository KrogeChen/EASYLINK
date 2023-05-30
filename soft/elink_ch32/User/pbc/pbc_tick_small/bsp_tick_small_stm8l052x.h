//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\snail_data_types.h"
#include "iostm8l052c6.h"
#include "intrinsics.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//STM8L052C6T6时钟配置模块
//------------------------------------------------------------------------------
//Timer2 ms tick 
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称:STM8L052C6T6时钟配置
//功能:配置晶振、系统时钟
//HSI 16M
//入口:无
//出口:无
//------------------------------------------------------------------------------
static void bsp_clock_cfg(void)
{
    if(0 == CLK_ICKCR_bit.HSION)
    {
        CLK_ICKCR_bit.HSION = 1;
    }
    while(0 == CLK_ICKCR_bit.HSIRDY);
    if(0x01 != CLK_SCSR)
    {
        CLK_SWCR_bit.SWEN = 1;
        CLK_SWR = 0x01;                 //HSI
        while(0x01 != CLK_SCSR);
    }
    CLK_SWCR_bit.SWEN = 0;
    CLK_CKDIVR_bit.CKM = 0;         //Presacler =1
    
    #ifdef NDEBUG
        IWDG_KR = 0xAA;              //Reload Watchdog Count
    #endif
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static sdt_int16u tick_millsecond;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
sdt_int16u bsp_pullSystemTickCount(void)
{
    return(tick_millsecond);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define  LEDONEPDIR      PE_DDR
#define  LEDONEGPIO      PE_ODR
#define  LEDONEBIT       0x80
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称:系统滴答时钟配置
//功能:中断方式
//TIMER2
//500us的定时
//------------------------------------------------------------------------------
#define Poied    (8000-1)
//------------------------------------------------------------------------------
void bsp_system_tick_cfg(void)
{
    bsp_clock_cfg();
    
    CLK_PCKENR1_bit.PCKEN10 = 1;   //Enable Tim2 Peripheral clock
    TIM2_CR1 = 0x80;
    TIM2_PSCR_bit.PSC = 0;
    TIM2_ARRH = (sdt_int8u)(Poied>>8);
    TIM2_ARRL = (sdt_int8u)(Poied&0x00FF);
    TIM2_IER_bit.UIE = 1;
    TIM2_CR1_bit.CEN = 1;
    
    LEDONEPDIR |= LEDONEBIT;       //1为输出管脚
    PE_CR1 |= 0x80;
    PE_CR2 &= (~0x80);
    __enable_interrupt();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifdef EPF_LOG_EN
static sdt_int8u epf_buff[64];
static sdt_int8u epf_pmd_in;
static sdt_int8u epf_pmd_ot;
static sdt_int32u epf_shift_reg;
static sdt_int32u epf_shift_mask;
static sdt_int32u epf_status_reg;
#define ESRG_PERAMBLE     0x01
#define ESRG_SYNC         0x02
#define ESRG_PAYLOAD      0x04
#define ESRG_EOF          0x08
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//TIM2 update interrupt
//------------------------------------------------------------------------------
#pragma vector = TIM2_OVR_UIF_vector
 __interrupt void TIM2_ISR(void)
 {
     static sdt_int8u base_tick;
     if(TIM2_SR1_bit.UIF)
     {
         TIM2_SR1_bit.UIF = 0;
         
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
                        epf_shift_reg |= (0x000010000);
                    }
                    else 
                    {
                        epf_shift_reg |= (0x000070000);
                    }
                    if(temp_8u & 0x20)
                    {
                        epf_shift_reg |= (0x000010000 << 4);
                    }
                    else 
                    {
                        epf_shift_reg |= (0x000070000 << 4);
                    }
                    if(temp_8u & 0x40)
                    {
                        epf_shift_reg |= (0x000010000 << 8);
                    }
                    else 
                    {
                        epf_shift_reg |= (0x000070000 << 8);
                    }
                    if(temp_8u & 0x80)
                    {
                        epf_shift_reg |= (0x000010000 << 12);
                    }
                    else 
                    {
                        epf_shift_reg |= (0x000070000 << 12);
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
                LEDONEGPIO |= LEDONEBIT;
            }
            else
            {
                LEDONEGPIO &= ~LEDONEBIT;
            }
            epf_shift_mask = epf_shift_mask >> 1;
        }        
        #endif
     }
 }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
sdt_int32u bsp_pull_us_count_32bits(void)
{
    static sdt_int32u rd_us_cnt;


    rd_us_cnt++;
    
    return(rd_us_cnt);
}
//------------------------------------------------------------------------------
sdt_int16u bsp_pull_us_count_16bits(void)
{
    static sdt_int16u rd_us_cnt;
    
    rd_us_cnt++;
    return(rd_us_cnt);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//EPF打印接口
//in:字符串文本
//out:失败指示,sdt_true--转移失败(缓冲区无法容纳转移的字符串长度)
//------------------------------------------------------------------------------
#ifdef EPF_LOG_EN
sdt_bool bsp_easy_printf(sdt_int8s* in_pStr)
{
    
    sdt_bool full;
    sdt_int8u rd_pmd_in;
    sdt_int8u rd_pmd_ot;
    sdt_int8u trs_bytes;
    sdt_int8u i;

    full = sdt_true;
    rd_pmd_in = epf_pmd_in;
//    __disable_interrupt();
    rd_pmd_ot = epf_pmd_ot;
//    __enable_interrupt();
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
                __disable_interrupt();
                epf_pmd_in++;
                if(epf_pmd_in > (sizeof(epf_buff) - 1))
                {
                    epf_pmd_in = 0;
                }
                __enable_interrupt();
                i++;
            }
            __disable_interrupt();
            if(0 == epf_status_reg)
            {
                epf_status_reg = (ESRG_PERAMBLE + ESRG_SYNC + ESRG_PAYLOAD + ESRG_EOF);
            }
            else
            {
                epf_status_reg |= ESRG_PAYLOAD;
            }
            __enable_interrupt();          
        }
    }                         
    return(full);
}
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++