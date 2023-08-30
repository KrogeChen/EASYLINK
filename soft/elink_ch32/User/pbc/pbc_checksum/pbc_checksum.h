#ifndef pbc_checksum_H
#define pbc_checksum_H
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef snail_data_types
    #include ".\snail_data_types.h"
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++task++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++interface++++++++++++++++++++++++++++++++++
//name: CRC16计算，Modbus标准
//fun:  16bits的字返回
//in: 
//      in_pBytes     计算CRC值的原始数据指针
//      in_length     数据长度
//out:  16Bit CRC值
//------------------------------------------------------------------------------
sdt_int16u pbc_crc16_modbus(sdt_int8u* in_pBytes,sdt_int16u in_length);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//name: CRC16计算，Modbus标准
//fun:  8bits的数组返回
//in: 
//      in_pBytes     计算CRC值的原始数据指针
//      in_length     数据长度
//      out_pCrcdata  crc值的指针,小端模式, out_pCrcdata[1]高位， out_pCrcdata[0]低位，
//out:  none
//------------------------------------------------------------------------------
void pbc_crc16_modbus_byte(sdt_int8u* in_pBytes,sdt_int16u in_length,sdt_int8u* out_pCrcdata);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//name: CRC16计算，Modbus标准
//fun:  8bits的数组返回
//in:
//      in_pBytes     计算CRC值的原始数据指针
//      in_length     数据长度
//      out_pCrcdata  crc值的指针,大端模式, out_pCrcdata[0]高位， out_pCrcdata[1]低位，
//out:  none
//------------------------------------------------------------------------------
void pbc_crc16_modbus_byte_big(sdt_int8u* in_pBytes,sdt_int16u in_length,sdt_int8u* out_pCrcdata);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//name: CRC16计算，Modbus标准
//fun:  8bits的字符串返回
//in: 
//      in_pBytes     计算CRC值的原始数据指针
//      in_length     数据长度
//      out_pCrcString  crc值的指针,大端模式, out_pCrcString[0]高位， out_pCrcString[3]低位，
//out:  none
//------------------------------------------------------------------------------
void pbc_crc16_modbus_string(sdt_int8u* in_pBytes,sdt_int16u in_length,sdt_int8u* out_pCrcString);
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
