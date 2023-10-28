//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "app_cfg.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "ch32v20x.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void app_general_task(void)
{
   //mde_watchdog_reload();
    pbc_pilot_light_task();
    app_debug_task();

    macro_cTimerTig(timer_runs,timerType_millisecond);

    if(pbc_pull_timerIsCompleted(&timer_runs))
    {
        pbc_reload_timerClock(&timer_runs,1000);


    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
void main(void)
{   
    //mde_watchdog_cfg();
    pbc_system_clock_cfg();

    USART_Printf_Init(1000000);
    printf("This is printf example\r\n");
    pbc_easy_printf("boot starting\r\n");
    pbc_task_create(app_general_task,0);
	pbc_task_create(app_log_task,2000);
    pbc_task_process();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
