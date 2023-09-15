//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "chip_select.h"
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if defined(stm32f103rct6)

#elif defined(stm8l052r8t6)

#elif defined(hc32l136k8ta)

#elif defined(hc32l176kata)

#elif defined(fm33lc025n)

#elif defined(stc8g1k08)

#elif defined(CH32V203C8T6)
  #include "bsp_pilot_light_ch32v302c8t6.h"
#else
  #error "mcu select is none"
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
