//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\app_cfg.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//macro_cTimerTig(timer_reboot,timerType_millisecond);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static enum
{
   LOG_PRODUCT     = 0x00,
   LOG_VERSION     = 0x01,
   LOG_RUN         = 0x02,
   LOG_IDLE        = 0xfe,
   LOG_MASK        = 0xff,
}log_status;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void app_log_task(void)
{
    switch(log_status)
    {
        case LOG_PRODUCT:
        {
            pbc_easy_printf("product name:");
            pbc_easy_printf(PRODUCT_NAME);
            pbc_easy_printf("\r\n");
            log_status = LOG_VERSION;
            break;
        }        
        case LOG_VERSION:
        {
          
            sdt_string log_string[30];
            sdt_string number_str[10];
            
            pbc_clear_string(&log_string[0],sizeof(log_string));
            
            pbc_string_append("version:",&log_string[0]);
            
            pbc_clear_string(&number_str[0],sizeof(number_str));
            pbc_int16u_to_string_convert(MAIN_VERSION,&number_str[0]);
            pbc_string_append(&number_str[0],&log_string[0]);
            
            pbc_string_append(".",&log_string[0]);
            
            pbc_clear_string(&number_str[0],sizeof(number_str));
            pbc_int16u_to_string_convert(SON_VERSION,&number_str[0]);
            pbc_string_append(&number_str[0],&log_string[0]);
            
            pbc_string_append("\r\n",&log_string[0]);
            
            pbc_easy_printf((sdt_int8s*)&log_string[0]);
            
            log_status = LOG_RUN;
            break;
        }
        case LOG_RUN:
        {
            //pbc_easy_printf("APP RUNING\r\n");
            break;
        }
        case LOG_IDLE:
        {
            log_status = LOG_RUN;
            break;
        }
        case LOG_MASK:
        {
            log_status = LOG_IDLE;
            break;
        }
        default:
        {
            log_status = LOG_IDLE;
            break;
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
