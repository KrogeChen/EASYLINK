//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "bsp_elink_datalink.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Elink  data link layer solid
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef SOLID_ELINK_DLK_H
#define SOLID_ELINK_DLK_H
//------------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++solid+++++++++++++++++++++++++++++++++++++++++
#define MAX_SOLID    1
//-----------------------------------------------------------------------------
static ELINK_DLK_OPER_DEF elink_dlk_solid[MAX_SOLID];
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static void elink_dlk_solid_cfg(void)
{
    bsp_elink_phy_cfg();
//-----------------------------------------------------------------------------
    elink_dlk_solid[0].pull_phy_receive_byte = bsp_pull_phy_receive_byte;
    elink_dlk_solid[0].pull_phy_busy = bsp_pull_phy_busy;
    elink_dlk_solid[0].pull_phy_tx_conflict = bsp_pull_phy_tx_conflict;
    elink_dlk_solid[0].pull_phy_tx_cpt = bsp_pull_phy_tx_cpt;
    elink_dlk_solid[0].push_phy_start_tx = bsp_push_phy_start_tx;
    elink_dlk_solid[0].push_phy_start_rx = bsp_push_phy_start_rx;
    elink_dlk_solid[0].transfet_bytes_to_phy_tx = bsp_transfet_bytes_to_phy_tx;
    elink_dlk_solid[0].pull_random_backtime = bsp_pull_random_backtime;
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
}
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


