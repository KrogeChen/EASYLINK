//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "chip_select.h"
#include ".\bsp_elink_datalink.h"
#include ".\snail_data_types.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if defined(CH32V203C8T6)
  #include "bsp_elink_datalink_ch32v203c8t6.h"
#elif defined(STM8L052C6T6)

#elif defined(HC32L136K8TA) || defined(HC32L136J8TA)

#else
  #error "mcu select is none"
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
