//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//pilot light match
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef PBC_PILOT_LIGHT_MATCH_H
#define PBC_PILOT_LIGHT_MATCH_H
//------------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++solid+++++++++++++++++++++++++++++++++++++++++
#define max_solid    3
//-----------------------------------------------------------------------------
static pilot_oper_def pilot_oper_solid[max_solid];
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static void pilot_solid_cfg(void)
{
//-----------------------------------------------------------------------------
    bsp_pilot_light_cfg();
    pilot_oper_solid[0].lamp_id = 0;
    pilot_oper_solid[0].dark_ms = 1;
    pilot_oper_solid[0].lighten_ms = 0;
    pilot_oper_solid[0].set_loop = 0;
    pilot_oper_solid[0].run_loop = 0;
    
    pilot_oper_solid[1].lamp_id = 1;
    pilot_oper_solid[1].dark_ms = 1;
    pilot_oper_solid[1].lighten_ms = 0;
    pilot_oper_solid[1].set_loop = 0;
    pilot_oper_solid[1].run_loop = 0;
    
    pilot_oper_solid[2].lamp_id = 2;
    pilot_oper_solid[2].dark_ms = 1;
    pilot_oper_solid[2].lighten_ms = 0;
    pilot_oper_solid[2].set_loop = 0;
    pilot_oper_solid[2].run_loop = 0;
    
//-----------------------------------------------------------------------------
}
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
