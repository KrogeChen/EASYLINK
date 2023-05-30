//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "chip_select.h"
#include "bsp_tick_small.h"
#include ".\snail_data_types.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if defined(stm32f103rct6)

#elif defined(STM8L052C6T6)
#include ".\bsp_tick_small_stm8l052c6t6.h"
#elif defined(HC32L136K8TA) || defined(HC32L136J8TA)
#include ".\bsp_tick_small_hc32l136x.h"

#else
  #error "mcu select is none"
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++