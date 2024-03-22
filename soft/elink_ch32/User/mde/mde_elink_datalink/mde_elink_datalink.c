//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//version:10
//date: 25/08/2023
//note: elink链路代码初始编写
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\snail_data_types.h"
#include "..\..\pbc\pbc_tick_small\pbc_tick_small.h"
#include "..\..\pbc\pbc_checksum\pbc_checksum.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\mde_elink_datalink.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define TIMEOUTRX_V    100
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//数据缓冲区结构体
//------------------------------------------------------------------------------
#define MAX_PAY_LEN  246
#define RAW_PAYIDX   10
typedef union
{
    struct
    {
        sdt_int8u edlk_pre[2];
        sdt_int8u edlk_sfd;
        sdt_int8u edlk_src;
        sdt_int8u edlk_dst;
		sdt_int8u edlk_fcs[2];
		sdt_int8u edlk_cbits;
		sdt_int8u edlk_type;
        sdt_int8u edlk_len;

        sdt_int8u edlk_pay[MAX_PAY_LEN];
    };
    sdt_int8u edlk_raw[256];
}ELINK_DLK_BUFF_DEF;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef enum
{
    elink_rs_idle        = 0x00,
    elink_rs_rx_str      = 0x01,
    elink_rs_rx_pre      = 0x02,
    elink_rs_rx_sfd      = 0x03,
	elink_rs_rx_src      = 0x04,
	elink_rs_rx_dst      = 0x05,
    elink_rs_rx_fcsh     = 0x06,
	elink_rs_rx_fcsl     = 0x07,
	elink_rs_rx_cbits    = 0x08,
	elink_rs_rx_type     = 0x09,
    elink_rs_rx_len      = 0x0a,
    elink_rs_rx_pay      = 0x0b,

    elink_rs_tx_data     = 0x10,
    elink_rs_tx_complete = 0x11,
    elink_rs_tx_retry    = 0x12,

}ELINK_RUN_STATUS_DEF;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
    sdt_int8u  local_address;
    ELINK_RUN_STATUS_DEF elink_link_run_s;
    sdt_bool   plan_transfet;   //准备发送数据

    sdt_int8u  rx_index;
    ELINK_DLK_BUFF_DEF rx_buff;
    ELINK_DLK_BUFF_DEF tx_buff;
    sdt_int16u tx_len;
    sdt_int16u tx_index;

    sdt_int8u  shunback_try;                                 //发送冲突避退，尝试次数

    timerClock_def    timer_rx_timeout;
    timerClock_def    timer_shunback;

    CBK_ELINK_DLK_ACCEPT* cbk_link_appect;                    //接收数据回调
    CBK_TRANSFET_COMPLETE* cbk_link_transfet_cpt;             //发送完毕回调
    sdt_bool (*pull_phy_receive_byte)(sdt_int8u* pOut_rcb);   //从PHY获取一个接收字节
    sdt_bool (*pull_phy_tx_conflict)(void);                   //获取PHY的冲突情况
    sdt_bool (*pull_phy_busy)(void);                          //获取PHY忙碌状态
    sdt_bool (*pull_phy_tx_cpt)(void);                        //获取tx数据发送完毕
    void (*push_phy_start_tx)(void);                          //PHY开始发送数据
    void (*push_phy_start_rx)(void);                          //PHY开始接收数据
    sdt_int8u (*transfet_bytes_to_phy_tx)(sdt_int8u* in_pByte,sdt_int8u in_expect_bytes);  //转移数据
    sdt_int16u (*pull_random_backtime)(void);                 //获取随机避退时间
}ELINK_DLK_OPER_DEF;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//链路状态迁跃
//------------------------------------------------------------------------------
static void elink_link_data_status(ELINK_DLK_OPER_DEF* mix_elink_oper)
{
    ELINK_RUN_STATUS_DEF rd_run_s;
    sdt_int8u rec_byte;

    pbc_timerMillRun_task(&mix_elink_oper->timer_rx_timeout);
    pbc_timerMillRun_task(&mix_elink_oper->timer_shunback);

    if(pbc_pull_timerIsOnceTriggered(&mix_elink_oper->timer_rx_timeout))
    {
        mix_elink_oper->elink_link_run_s = elink_rs_idle;
    }

    if(0 == mix_elink_oper->pull_phy_receive_byte)
    {
        return;
    }
    if(0 == mix_elink_oper->cbk_link_appect)
    {
        return;
    }

    do
    {
        rd_run_s = mix_elink_oper->elink_link_run_s;
        switch(rd_run_s)
        {
            case elink_rs_idle:
            {
                mix_elink_oper->elink_link_run_s = elink_rs_rx_str;
                break;
            }
            case elink_rs_rx_str:
            {
                mix_elink_oper->push_phy_start_rx();
                mix_elink_oper->elink_link_run_s = elink_rs_rx_pre;
                break;
            }
            case elink_rs_rx_pre:
            {
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) //收到一个字节
                {
                    if(0xff == rec_byte)
                    {
                        pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_sfd;
                    }
                }
                else if(mix_elink_oper->plan_transfet)
                {
                    if(mix_elink_oper->pull_phy_busy())
                    {
                    }
                    else
                    {
                        mix_elink_oper->tx_index = 0;
                        mix_elink_oper->push_phy_start_tx();
                        mix_elink_oper->elink_link_run_s = elink_rs_tx_data;  //PHY 非忙碌,进入发送状态
                    }
                }
                break;
            }
            case elink_rs_rx_sfd:
            {
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) //收到一个字节
                {
                    if(0xc5 == rec_byte)
                    {
                        pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_src;
                    }
                    else if(0xff == rec_byte)
                    {

                    }
                    else
                    {
                        pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_pre;
                    }
                }
                break;
            }
			case elink_rs_rx_src:
			{
				if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
				{
	                pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_src = rec_byte;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_dst;					
				}
				break;
			}
			case elink_rs_rx_dst:
			{
				if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
			    {
	                pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_dst = rec_byte;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_fcsh;					
				}
				break;
			}
			case elink_rs_rx_fcsh:
			{
				if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
                {
	                pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_fcs[0] = rec_byte;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_fcsl;
				}
				break;
			}
			case elink_rs_rx_fcsl:
			{
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
                {
	                pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_fcs[1] = rec_byte;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_cbits;
				}
				break;
			}
			case elink_rs_rx_cbits:
			{
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
                {
	                pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_cbits = rec_byte;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_type;
				}

				break;
			}
			case elink_rs_rx_type:
			{
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
                {
	                pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_type = rec_byte;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_type;
				}

				break;
			}
			case elink_rs_rx_len:
			{
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte)) 
                {
		            pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    mix_elink_oper->rx_buff.edlk_len = rec_byte;
				    
				    if(mix_elink_oper->rx_buff.edlk_len > (MAX_PAY_LEN))
                    {
                        pbc_stop_timerIsOnceTriggered(&mix_elink_oper->timer_rx_timeout);
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_pre; //溢出
                    }
                    else
                    {
                        pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                        mix_elink_oper->rx_index = RAW_PAYIDX;
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_pay;
                    }					
				}
				break;
			}
			case elink_rs_rx_pay:
			{
                if(mix_elink_oper->pull_phy_receive_byte(&rec_byte))
                {
                    mix_elink_oper->rx_buff.edlk_raw[mix_elink_oper->rx_index] = rec_byte;
                    mix_elink_oper->rx_index ++;

                    if(0 == mix_elink_oper->rx_index)
                    {//溢出
                        pbc_stop_timerIsOnceTriggered(&mix_elink_oper->timer_rx_timeout);
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_pre; //溢出
					}
                    else if(mix_elink_oper->rx_index < (mix_elink_oper->rx_buff.edlk_len + RAW_PAYIDX))
                    {
                        pbc_reload_timerClock(&mix_elink_oper->timer_rx_timeout,TIMEOUTRX_V);
                    }
                    else
                    {//end receive data,verify data

                        sdt_int8u cala_crc[2];
						sdt_int8u recv_crc[2];

                        //if(18 == mix_elink_oper->rx_len)
                        //{
						//
                        //}
						recv_crc[0] = mix_elink_oper->rx_buff.edlk_fcs[0];
						recv_crc[1] = mix_elink_oper->rx_buff.edlk_fcs[1];
						mix_elink_oper->rx_buff.edlk_fcs[0] = 0xff;
						mix_elink_oper->rx_buff.edlk_fcs[1] = 0xff;
						
                        pbc_crc16_modbus_byte(&mix_elink_oper->rx_buff.edlk_src,(mix_elink_oper->rx_buff.edlk_len + 7),&cala_crc[0]);
                        if((cala_crc[0] == recv_crc[0]) && (cala_crc[1] == recv_crc[1]))
                        {
                            ELIK_EXCHANGE_DEF appcet_bytes;

                            appcet_bytes.elk_ctrl_bits = mix_elink_oper->rx_buff.edlk_cbits;
                            appcet_bytes.elk_src_addr = mix_elink_oper->rx_buff.edlk_src;
                            appcet_bytes.elk_dst_addr = mix_elink_oper->rx_buff.edlk_dst;
                            appcet_bytes.elk_type = mix_elink_oper->rx_buff.edlk_type;
                            appcet_bytes.elk_payload_len = mix_elink_oper->rx_buff.edlk_len;
                            appcet_bytes.pPayload = &mix_elink_oper->rx_buff.edlk_pay[0];
                            mix_elink_oper->cbk_link_appect(&appcet_bytes);         //回调,处理数据
                        }
                        pbc_stop_timerIsOnceTriggered(&mix_elink_oper->timer_rx_timeout);
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_pre;
                    }
                }
				break;
			}
            case elink_rs_tx_data:
            {
                if(mix_elink_oper->pull_phy_tx_conflict())
                {
                    pbc_reload_timerClock(&mix_elink_oper->timer_shunback,mix_elink_oper->pull_random_backtime());//载入随机避退时间
                    mix_elink_oper->elink_link_run_s = elink_rs_tx_retry; //retry
                }
                else
                {//转移数据到PHY

                    sdt_int8u remain_bytes;

                    remain_bytes = mix_elink_oper->transfet_bytes_to_phy_tx(&mix_elink_oper->tx_buff.edlk_raw[mix_elink_oper->tx_index],(mix_elink_oper->tx_len - mix_elink_oper->tx_index));
                    mix_elink_oper->tx_index = mix_elink_oper->tx_len - remain_bytes;

                    if(0 == remain_bytes) //数据转移完毕,检测PHY发送完成
                    {
                        mix_elink_oper->elink_link_run_s = elink_rs_tx_complete;
                    }
                }
                break;
            }
            case elink_rs_tx_complete:
            {
                if(mix_elink_oper->pull_phy_tx_conflict())
                {
                    pbc_reload_timerClock(&mix_elink_oper->timer_shunback,mix_elink_oper->pull_random_backtime());
                    mix_elink_oper->elink_link_run_s = elink_rs_tx_retry; //retry

                }
                else if(mix_elink_oper->pull_phy_tx_cpt())
                {
                    mix_elink_oper->plan_transfet = sdt_false;          //清除发送计划
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_str; //回到接收状态
                    mix_elink_oper->cbk_link_transfet_cpt(0);
                }
                break;
            }
            case elink_rs_tx_retry:
            {
                if(mix_elink_oper->shunback_try > 4)     //尝试次数超
                {
                    mix_elink_oper->plan_transfet = sdt_false;
                    mix_elink_oper->elink_link_run_s = elink_rs_rx_str; //回到接收状态
                    mix_elink_oper->cbk_link_transfet_cpt(TANS_FAULT_CFT);
                }
                else
                {
                    if(pbc_pull_timerIsCompleted(&mix_elink_oper->timer_shunback))
                    {
                        mix_elink_oper->shunback_try ++;
                        mix_elink_oper->elink_link_run_s = elink_rs_rx_str; //回到接收状态,重新寻找机会发送
                    }
                }
                break;
            }
            default:
            {
                mix_elink_oper->elink_link_run_s = elink_rs_idle;
                break;
            }
        }
    } while (rd_run_s != mix_elink_oper->elink_link_run_s);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include ".\mde_elink_datalink_match.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: E-link数据链路任务处理
//功能: 处理数据链路的报文
//入口: 无
//
//出口: 无
//------------------------------------------------------------------------------
void mde_elink_dlk_task_process(void)
{
    sdt_int8u i;
    for(i = 0;i < MAX_SOLID;i ++)
    {
        elink_link_data_status(&elink_dlk_solid[i]);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
void mde_elink_datalink_cfg(sdt_int8u in_sbr,ELINK_PRAR_DEF* pIn_link_para)
{
    elink_dlk_solid_cfg();
    if(in_sbr < MAX_SOLID)
    {
        elink_dlk_solid[in_sbr].local_address = pIn_link_para->elk_local_addr;
        elink_dlk_solid[in_sbr].cbk_link_appect = pIn_link_para->cbk_elink_dlk_accept;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 获取data link忙碌状态
//功能:
//入口: in_sbr          ---实列号
//
//
//
//出口: sdt_true -- 忙碌,不能进行数据的发送操作
//------------------------------------------------------------------------------
sdt_bool mde_pull_elink_dlk_busy(sdt_int8u in_sbr)
{
    return(elink_dlk_solid[in_sbr].plan_transfet);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名称: 发送一串数据到数据链路
//功能:
//入口: in_sbr  ---实列号
//
//
//
//出口:sdt_true 发送数据交换完毕
//------------------------------------------------------------------------------
sdt_bool mde_transfet_elink_dlk(sdt_int8u in_sbr,ELIK_EXCHANGE_DEF* in_pTransfet_data,CBK_TRANSFET_COMPLETE* in_pCbk_transfet_cpt)
{
    if(sdt_false == elink_dlk_solid[in_sbr].plan_transfet)
    {

        elink_dlk_solid[in_sbr].tx_buff.edlk_pre[0] = 0xff;
        elink_dlk_solid[in_sbr].tx_buff.edlk_pre[1] = 0xff;
        elink_dlk_solid[in_sbr].tx_buff.edlk_sfd = 0xc5;
        elink_dlk_solid[in_sbr].tx_buff.edlk_src = in_pTransfet_data->elk_src_addr;
        elink_dlk_solid[in_sbr].tx_buff.edlk_dst = in_pTransfet_data->elk_dst_addr;
        elink_dlk_solid[in_sbr].tx_buff.edlk_fcs[0] = 0xff;
        elink_dlk_solid[in_sbr].tx_buff.edlk_fcs[1] = 0xff;
        elink_dlk_solid[in_sbr].tx_buff.edlk_cbits = in_pTransfet_data->elk_ctrl_bits;
        elink_dlk_solid[in_sbr].tx_buff.edlk_type = in_pTransfet_data->elk_type;
        elink_dlk_solid[in_sbr].tx_buff.edlk_len = (in_pTransfet_data->elk_payload_len);


        sdt_int8u i;
        sdt_int8u calc_crc[2];

        for(i = 0;i < in_pTransfet_data->elk_payload_len;i++)
        {
            elink_dlk_solid[in_sbr].tx_buff.edlk_pay[i] = in_pTransfet_data->pPayload[i];
        }
        pbc_crc16_modbus_byte(&elink_dlk_solid[in_sbr].tx_buff.edlk_src,(elink_dlk_solid[in_sbr].tx_buff.edlk_len + 7),&calc_crc[0]);
        elink_dlk_solid[in_sbr].tx_buff.edlk_fcs[0] = calc_crc[0];
        elink_dlk_solid[in_sbr].tx_buff.edlk_fcs[1] = calc_crc[1];

        elink_dlk_solid[in_sbr].tx_len = in_pTransfet_data->elk_payload_len + 10;  //转移长度控制

        elink_dlk_solid[in_sbr].cbk_link_transfet_cpt = in_pCbk_transfet_cpt;

        elink_dlk_solid[in_sbr].plan_transfet = sdt_true;
        elink_dlk_solid[in_sbr].shunback_try = 0;
        return(sdt_true);
    }
    return(sdt_false);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





















