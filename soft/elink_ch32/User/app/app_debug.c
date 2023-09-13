//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\app_cfg.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "ch32v20x.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//接收回调
//------------------------------------------------------------------------------
sdt_int8u callback_elink_link_data_accept(ELIK_EXCHANGE_DEF* in_pAccept_data)
{
    //GPIOC->BSHR = 0x2000;
    pbc_easy_printf("THIS IS LINK DATA");
    return(0);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void callback_elink_link_data_transfet(sdt_int32u in_faultBits)
{

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
            pbc_reload_timerClock(&timer_txdd,2000);

            ELIK_EXCHANGE_DEF elk_exchange_data;

            elk_exchange_data.elk_src_addr = 0x01;
            elk_exchange_data.elk_dst_addr = 0x02;
            elk_exchange_data.elk_type = 0x01;
            elk_exchange_data.elk_payload_len =10;
            elk_exchange_data.pPayload = &detxd_buff[0];



            if(mde_pull_elink_dlk_busy(0))
            {
            }
            else
            {
                //mde_transfet_elink_dlk(0,&elk_exchange_data,callback_elink_link_data_transfet);
                //pbc_easy_printf("RUN");
            }
        }
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
