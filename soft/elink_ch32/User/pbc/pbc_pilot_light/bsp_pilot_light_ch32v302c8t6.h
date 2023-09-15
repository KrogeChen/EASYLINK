//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef snail_data_types
    #include ".\snail_data_types.h"
#endif
//-------------------------------------------------------------------------------------------------
#include "ch32v20x.h"

//-------------------------------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//PC13
//PB12
//PA15
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define LIGHT_L0            GPIOC->BCR  = 0x2000
#define DARK_L0             GPIOC->BSHR = 0x2000
#define LIGHT_L1            GPIOB->BCR   = 0x1000
#define DARK_L1             GPIOB->BSHR = 0x1000
#define LIGHT_L2            GPIOA->BCR   = 0x8000
#define DARK_L2             GPIOA->BSHR = 0x8000
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 指示灯端口配置
//功能:
//入口:
//
//出口:
//-------------------------------------------------------------------------------------------------
void bsp_pilot_light_cfg(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  //PC13
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIOC->BSHR = 0x2000;                                 //

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //PB12
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIOB->BSHR = 0x1000;                              //
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //PA15
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIOA->BSHR = 0x8000;                             //
    
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 点亮指示灯
//功能:
//入口: 灯编号
//
//出口: 无
//-------------------------------------------------------------------------------------------------
void bsp_pilot_light_lighten(sdt_int8u in_lamp_id)
{
    switch(in_lamp_id)
    {
        case 0:
        {
            LIGHT_L0;
            break;
        }
        case 1:
        {
            LIGHT_L1;
            break;
        }
        case 2:
        {
            LIGHT_L2;
            break;
        }
        case 3:
        {

            break;
        }
        default:
        {
            break;
        }
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 熄灭指示灯
//功能:
//入口: 灯编号
//
//出口: 无
//-------------------------------------------------------------------------------------------------
void bsp_pilot_light_dark(sdt_int8u in_lamp_id)
{
    switch(in_lamp_id)
    {
        case 0:
        {
            DARK_L0;
            break;
        }
        case 1:
        {
            DARK_L1;
            break;
        }
        case 2:
        {
            DARK_L2;
            break;
        }
        case 3:
        {

            break;
        }
        default:
        {
            break;
        }
    }
}
//-------------------------------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
