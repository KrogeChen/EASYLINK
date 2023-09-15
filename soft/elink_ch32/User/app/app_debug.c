//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\app_cfg.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "ch32v20x.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ACCEPT_LAMP      0
#define TRANSFET_RIGHT   1
#define TRANSFET_ERR     2
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//接收回调
//------------------------------------------------------------------------------
sdt_int8u callback_elink_link_data_accept(ELIK_EXCHANGE_DEF* in_pAccept_data)
{
    PILOT_PARA_DEF  pilot_para;

    pilot_para.led_num = ACCEPT_LAMP;
    pilot_para.loop_cnt = 1;
    pilot_para.lighten_ms = 100;
    pilot_para.dark_ms = 100;

    pbc_push_pilot_light_ldms(&pilot_para);
    //pbc_easy_printf("THIS IS LINK DATA");
    return(0);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void callback_elink_link_data_transfet(sdt_int32u in_faultBits)
{
    PILOT_PARA_DEF  pilot_para;
    if(in_faultBits)
    {
        pilot_para.led_num = TRANSFET_ERR;
        pilot_para.loop_cnt = 1;
        pilot_para.lighten_ms = 300;
        pilot_para.dark_ms = 100;

        pbc_push_pilot_light_ldms(&pilot_para);
    }
    else
    {
        pilot_para.led_num = TRANSFET_RIGHT;
        pilot_para.loop_cnt = 1;
        pilot_para.lighten_ms = 100;
        pilot_para.dark_ms = 100;

        pbc_push_pilot_light_ldms(&pilot_para);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static sdt_int8u detxd_buff[128];
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//调试任务
//------------------------------------------------------------------------------
void app_debug_task(void)
{
    static sdt_bool cfged = sdt_false;

    if(cfged)
    {
        mde_elink_dlk_task_process();

        macro_cTimerTig(timer_txdd,timerType_millisecond);

        if(pbc_pull_timerIsCompleted(&timer_txdd))
        {

            pbc_easy_printf("RUN");

            ELIK_EXCHANGE_DEF elk_exchange_data;

            elk_exchange_data.elk_src_addr = 0x01;
            elk_exchange_data.elk_dst_addr = 0x02;
            elk_exchange_data.elk_type = 0x01;
            elk_exchange_data.elk_payload_len =10;
            elk_exchange_data.pPayload = &detxd_buff[0];

            if(mde_transfet_elink_dlk(0,&elk_exchange_data,callback_elink_link_data_transfet))
            {
                pbc_reload_timerClock(&timer_txdd,2000);

            }

            //PILOT_PARA_DEF  pilot_para;
            //
            //pilot_para.led_num = TRANSFET_RIGHT;
            //pilot_para.loop_cnt = 1;
            //pilot_para.lighten_ms = 100;
            //pilot_para.dark_ms = 100;
            //
            //pbc_push_pilot_light_ldms(&pilot_para);
        }   //
    }
    else
    {
        ELINK_PRAR_DEF elink_prar;

        cfged = sdt_true;
        elink_prar.elk_local_addr = 0x01;
        elink_prar.cbk_elink_dlk_accept = callback_elink_link_data_accept;
        mde_elink_datalink_cfg(0,&elink_prar);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
