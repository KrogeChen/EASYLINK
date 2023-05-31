//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
compiler - preprocessor
$PROJ_DIR$\
$PROJ_DIR$\..\chip\lib_hc32l13x
$PROJ_DIR$\..\chip\lib_hc32l13x\common
$PROJ_DIR$\..\chip\lib_hc32l13x\driver\inc

link - config
$PROJ_DIR$\hc32l13x.icf

debug - setup download
$PROJ_DIR$\..\chip\lib_hc32l13x\HC32L13X.svd
$PROJ_DIR$\..\chip\lib_hc32l13x\flashloader\HC32L13X.board
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef CHIP_SELECT_H
#define CHIP_SELECT_H
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define CH32V203C8T6
//-----------------------------------------------------------------------------
#define BOOT_SUPPORT
#define EA2X_WIRELESS
//#define EA2X_BUSVALVE
//-----------------------------------------------------------------------------
//HC32L136J8TA  EA22 2022版本,cmt2300无线阀
#define HARDWARE_FLAG  0x45413232
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
