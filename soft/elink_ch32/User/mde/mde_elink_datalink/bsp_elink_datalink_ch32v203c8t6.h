//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\snail_data_types.h"
#include "ch32v20x.h"
// #include "intrinsics.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 获取接收数据
//功能:
//入口: 接收字节的指针
//
//出口: sdt_true 收到有效数据
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_receive_byte(sdt_int8u* pOut_rcb)
{
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: PHY忙碌状态指示
//功能:
//入口:
//
//出口: sdt_true PHY忙碌
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_busy(void)
{
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 发送冲突指示
//功能:
//入口:
//
//出口: sdt_true 发生冲突
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_tx_conflict(void)
{

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 发送完成指示
//功能:
//入口:
//
//出口: sdt_true 数据发送完成
//------------------------------------------------------------------------------
sdt_bool bsp_pull_phy_tx_cpt(void)
{

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 转移数据到phy的发送缓冲区
//功能:
//入口: in_pByte   转移数据的字节指针
//      in_expect_bytes  期望发送的数据字节数
//
//出口: 剩余未转移字节数
//------------------------------------------------------------------------------
sdt_int16u bsp_transfet_bytes_to_phy_tx(sdt_int8u* in_pByte,sdt_int16u in_expect_bytes)
{

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
