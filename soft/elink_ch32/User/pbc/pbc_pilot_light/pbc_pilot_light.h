#ifndef PBC_PILOT_LIGHT_H
#define PBC_PILOT_LIGHT_H
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef snail_data_types
    #include ".\snail_data_types.h"
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define  LAMP_LOOP_ALWAYS   0xff
//------------------------------------------------------------------------------
typedef struct
{
    sdt_int8u  led_num;     //灯序列
    sdt_int8u  loop_cnt;    //循环次数，0xff 一直循环
    sdt_int16u lighten_ms;  //点亮时间
    sdt_int16u dark_ms;     //熄灭时间
}PILOT_PARA_DEF;
//++++++++++++++++++++++++++++++++++task++++++++++++++++++++++++++++++++++++++++
//名称: pilot light模块任务
//功能:
//入口: 无
//
//出口: 无
//------------------------------------------------------------------------------
void pbc_pilot_light_task(void);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++interface+++++++++++++++++++++++++++++++++++++
//name:设置指示灯亮、暗时间
//fun:
//in:   参数指针
//
//
//out:  none
//------------------------------------------------------------------------------
void pbc_push_pilot_light_ldms(PILOT_PARA_DEF* in_pPilot_para);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++