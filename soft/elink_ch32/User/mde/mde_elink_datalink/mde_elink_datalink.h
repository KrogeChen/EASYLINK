#ifndef MDE_ELINK_DATALINK_H
#define MDE_ELINK_DATALINK_H
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef snail_data_types
    #include ".\snail_data_types.h"
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
    sdt_int8u  elk_src_addr;    //源地址
    sdt_int8u  elk_dst_addr;    //目标地址
    sdt_int8u  elk_ctrl_bits;   //控制字
    sdt_int8u  elk_type;        //类型
    sdt_int16u elk_payload_len; //负载数据长度
    sdt_int8u* pPayload;        //负载数据
}ELIK_EXCHANGE_DEF;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef sdt_int8u (CBK_ELINK_DLK_ACCEPT)(ELIK_EXCHANGE_DEF* in_pAccept_data);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
    sdt_int8u               elk_local_addr;    //本机地址
    CBK_ELINK_DLK_ACCEPT    *cbk_elink_dlk_accept; //data link 接收数据回调
}ELINK_PRAR_DEF;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
//应用示例
{
    ELIK_EXCHANGE_DEF elk_exchange_data;
    mde_elink_dlk_task_process();
    if(mde_pull_elink_dlk_busy(0))
    {
    }
    else
    {
        mde_transfet_elink_dlk(0,&elk_exchange_data);
    }
}
//-----------------------------------------------------------------------------
sdt_int8u callback_accept_data_s0(ELIK_EXCHANGE_DEF* in_pAccept_data)
{
    return(0);
}
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//名称: E-link数据链路初始化配置
//功能:
//入口: in_sbr 实列号  in_link_para实列参数
//
//出口: 无
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mde_elink_datalink_cfg(sdt_int8u in_sbr,ELINK_PRAR_DEF* pIn_link_para);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: E-link数据链路任务处理
//功能: 处理数据链路的报文
//入口: 无
//
//出口: 无
//------------------------------------------------------------------------------
void mde_elink_dlk_task_process(void);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 获取data link忙碌状态
//功能:
//入口: in_sbr          ---实列号
//
//
//
//出口: sdt_true -- 忙碌,不能进行数据的发送操作
//------------------------------------------------------------------------------
sdt_bool mde_pull_elink_dlk_busy(sdt_int8u in_sbr);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 发送一串数据到数据链路
//功能:
//入口: in_sbr  ---实列号
//
//
//
//出口:sdt_true 发送数据交换完毕
//------------------------------------------------------------------------------
sdt_bool mde_transfet_elink_dlk(sdt_int8u in_sbr,ELIK_EXCHANGE_DEF* in_pTransfet_data);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
