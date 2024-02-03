# TOPOLOGY

HBS ---------------------------------------------------------------------------------------------------------------(Max..32)
        |               |                   |                               |                             |
		|          		|             		|                          		|                         	  |
		|          		|             		|                          		|                         	  |
	|-------|      	|-------|         	|--------|                     	|--------|                    |--------|
	| NODE  |      	| NODE  |         	|NODE(EX)|                     	|NODE(EX)|                    |NODE(WL)|
	|-------|      	|-------|         	|--------|                    	|--------|                    |--------|
	                                     WIRELESS                        WIRELESS                        MQTT
		           		              		.                           	.                              @
											.                    			.                              @
									.................            	.................                 %%%%%%%%%%
									.     	        .            	.     	        .                 % REMOTE %
									.               .            	.               .                 % SERVER %
								|--------|     |---------|      |--------|     |---------|            %%%%%%%%%%
							    | SENSER |	   | SENSER  |      | LINKAGE|     | LINKAGE |              	
		                        |--------|     |---------|      |--------|     |---------|              

注:每个节点分配96bit(12byte)的虚拟ID

# EASYLINK
easy link protocol by homebus

承担任务:
1、帧同步、寻址控制
2、数据的发送流、接收流
3、数据的差错控制
4、数据的流量管控
5、帧冲突管理


前导|界定|长度|控制|源地址|目标地址|报文类型|报文负载|校验
PRE  SFD  LEN  LCB   SRC     DST      TPE      PAY    FCS
 2    1    2    1     1       1        1        n      2
 
PRE  0xFF
SFD  0xC5
KEN  帧长度  从LEN到FCS的所有byte总和。
FCS  CRC16   多项式0x8005,初始值0xFFFF,计算数据从LEN开始，PAY结束。
LCB  BIT0:   1 公告报文

//--------------------------------------------------------------------------------------------------
//特殊地址分配
//0x00 空地址
//0xFF 空地址
//0x01 租约中心地址
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# NETWORK

## ELAP 地址租约

承担任务:
1、数据链路层的节点地址分配
2、虚拟ID和节点地址关联的租约表
3、子集管理

TPE: 0x01 地址租约服务
租约中心(地址:0x01)
首租流程
续租流程
租约中心申请流程

上电-->首租-->首租请求报文，SRC 0x00 DST 0x01-->租约中心应答-->获取租期和地址-->确认租约-->完毕
                                             -->租约中心无应答-->重试3次-->申请为租约中心

    -->续租-->续租请求报文，SRC 0x00 DST 0x01


    -->发布租约中心公告3次-->无冲突反馈-->正式成为租约中心,赋地址0x01
                          -->有冲突反馈-->退出租约中心申请-->进入地址租赁申请流程
//--------------------------------------------------------------------------------------------------
消息ID  命令   虚拟ID    节点地址
 MSGID  CMD     VUID      NADDR  
   2     1       12         1     
//--------------------------------------------------------------------------------------------------
CMD1:0x01 首租请求
		  35 AE | 01 | 89 76 73 87 AE 83 78 4A AE 83 78 4A | FF
		  
	 0x81 请求应答	  
          35 AE | 81 | 89 76 73 87 AE 83 78 38 AE 83 78 4A | 03	
		  
	 0xA1 租约失败,(一般是系统地址容量已满)
          35 AE | A1 | 89 76 73 87 AE 83 78 38 AE 83 78 4A | FF
		  
	 0xC1 租约确认
          35 AE | C1 | 89 76 73 87 AE 83 78 4A AE 83 78 4A | 03


CMD2:0x02 续租请求  
          35 AE | 02 | 89 76 73 87 AE 83 78 4A AE 83 78 4A | 03
		  
	 0x82 请求应答	  
          35 AE | 82 | 89 76 73 87 AE 83 78 38 AE 83 78 4A | 03	
		  
	 0xC2 租约确认
          35 AE | C2 | 89 76 73 87 AE 83 78 4A AE 83 78 4A | 03


CMD3:0x03 租约中心公告,
          空地址时,5秒内公告5次,无应答,本机成为租约中心,获得0x01地址。
          已经成为租约中心,每2小时,公告一次,1秒内连续发送3个报文。
          03 48 | 01 | 89 76 73 87 AE 83 78 31 AE 83 78 31 | FF
		  03 48 | 01 | 89 76 73 87 AE 83 78 31 AE 83 78 31 | 01
		                       本机ID
							   
     0x83 公告应答,收到应答,租约中心冲突,放弃成为租约中心。
	      03 48 | 81 | 89 76 73 87 AE 83 78 38 AE 83 78 39 | FF


格式: 消息ID  命令
       MSGID  CMD
         2     1 
CMD4:0x04 租约表请求
       03 48 | 04 | 


格式: 消息ID  命令  节点数量       节点表      
       MSGID  CMD     NODE      [NADDR+VUID] ... 
         2     1       1           1    12  
CMD5:0x05 租约表公布
       03 48 | 05 | 03 | 01 | 89 76 73 87 AE 83 78 31 AE 83 78 31 | 02 | 89 76 73 87 AE 83 78 31 AE 83 78 32 | 03 | 89 76 73 87 AE 83 78 31 AE 83 78 35 

CMD6:0x06 扩展备案

CMD7:0x07 扩展表公布
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
##EOTA 固件升级
TPE: 0x02 固件升级

开始 --> 接受到触发升级的信号及"固件资源位置"

     --> 向"固件资源位置"请求文件

     --> BOOT状态 -->发送升级数据包-->END
//--------------------------------------------------------------------------------------------------
KV值 KEY-VALUE 文件的关键标识 64BIT



格式: 消息ID  命令  状态   资源位置   
       MSGID  CMD   STU   VUID + FLKV
         2     1     1     12     8  
CMD1: 0x01 触发升级
           03 48 | 01 | FF |89 76 73 87 AE 83 78 31 AE 83 78 39 | 34 D3 81 47 E3 4D 71 30
		
      0x81  应答
	       03 48 | 81 | FF |89 76 73 87 AE 83 78 31 AE 83 78 39 | 34 D3 81 47 E3 4D 71 30

格式: 消息ID   命令  状态       资源KV   块序列   块内容(请求时内容为空)
       MSGID   CMD   STU         FLKV    BKSEQ    DETAILS
         2      1     1           8        2        128	
CMD2:0x02  传输请求
          03 48 | 02 | FF |34 D3 81 47 E3 4D 71 30 | 00 00 
		  
	 0x82  传输应答
	      03 48 | 82 | FF |34 D3 81 47 E3 4D 71 30 | 00 00 |93 94 ..(128B).. 23 54
		  
     0xA2  错误报告
          03 48 | A2 | FE |34 D3 81 47 E3 4D 71 30 | 00 00 

状态码:
     0x00 填充
	 0xFD 块请求超出文件范围
	 0xFE 未知错误
	 0xFF 填充

//----------------------------------------------------------------------------------------------------


 
     
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TPE: 0x03 公告发布

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
资源定位方式
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
消息服务质量
QoS 0: 消息至多传送 1 次。
QoS 1: 消息至少传送 1 次。
QoS 2: 消息仅仅传送 1 次。

