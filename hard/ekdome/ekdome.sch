EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	9500 4625 9365 4625
Wire Wire Line
	9500 4580 9500 4625
Wire Wire Line
	9365 4580 9365 4625
Wire Wire Line
	9500 4280 9500 4250
Wire Wire Line
	9365 4250 9365 4280
Wire Wire Line
	9500 3800 9810 3800
Connection ~ 9500 3800
Wire Wire Line
	9500 3950 9500 3800
Wire Wire Line
	9365 3900 9640 3900
Connection ~ 9365 3900
Wire Wire Line
	9365 3950 9365 3900
$Comp
L kicad_symbol_general:1.5KExxA D23
U 1 1 638A5508
P 9500 4430
F 0 "D23" V 9455 4505 50  0000 L CNN
F 1 "3.9V" V 9530 4505 50  0000 L CNN
F 2 "kicad_footprint_general:D_SOD-123F" H 9500 4230 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 9450 4430 50  0001 C CNN
	1    9500 4430
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:1.5KExxA D21
U 1 1 638A4F75
P 9500 4100
F 0 "D21" V 9525 4025 50  0000 R CNN
F 1 "3.9V" V 9450 4025 50  0000 R CNN
F 2 "kicad_footprint_general:D_SOD-123F" H 9500 3900 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 9450 4100 50  0001 C CNN
	1    9500 4100
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:1.5KExxA D20
U 1 1 638A4935
P 9365 4100
F 0 "D20" V 9395 4330 50  0000 R CNN
F 1 "3.9V" V 9320 4330 50  0000 R CNN
F 2 "kicad_footprint_general:D_SOD-123F" H 9365 3900 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 9315 4100 50  0001 C CNN
	1    9365 4100
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:1.5KExxA D22
U 1 1 638A3FEF
P 9365 4430
F 0 "D22" V 9320 4210 50  0000 L CNN
F 1 "3.9V" V 9395 4210 50  0000 L CNN
F 2 "kicad_footprint_general:D_SOD-123F" H 9365 4230 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 9315 4430 50  0001 C CNN
	1    9365 4430
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 638A185E
P 9000 4670
F 0 "#PWR0101" H 9000 4420 50  0001 C CNN
F 1 "GND" H 9080 4540 50  0000 R CNN
F 2 "" H 9000 4670 50  0001 C CNN
F 3 "" H 9000 4670 50  0001 C CNN
	1    9000 4670
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 3900 7600 3900
Wire Wire Line
	7350 4650 7350 3900
Wire Wire Line
	8650 4650 7350 4650
Wire Wire Line
	8650 4200 8650 4650
Wire Wire Line
	8700 4200 8650 4200
Wire Wire Line
	9000 3800 9500 3800
Connection ~ 9000 3800
Wire Wire Line
	8400 3800 9000 3800
Wire Wire Line
	9000 4000 9000 3800
Wire Wire Line
	8450 4400 8450 4450
$Comp
L power:GND #PWR0102
U 1 1 6389D1F4
P 8450 4450
F 0 "#PWR0102" H 8450 4200 50  0001 C CNN
F 1 "GND" H 8530 4315 50  0000 R CNN
F 2 "" H 8450 4450 50  0001 C CNN
F 3 "" H 8450 4450 50  0001 C CNN
	1    8450 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3800 7600 3800
Wire Wire Line
	7250 4200 7250 3800
Wire Wire Line
	8150 4200 7250 4200
Wire Wire Line
	8450 3900 9365 3900
Connection ~ 8450 3900
Wire Wire Line
	8400 3900 8450 3900
Wire Wire Line
	8450 4000 8450 3900
Wire Wire Line
	8450 3600 8400 3600
Wire Wire Line
	8450 3500 8450 3600
Wire Wire Line
	8450 3500 8700 3500
Connection ~ 8450 3500
Wire Wire Line
	8450 3500 8450 3400
$Comp
L kicad_symbol_general:Q_NPN_BEC Q21
U 1 1 63898382
P 8900 4200
F 0 "Q21" H 8820 4360 50  0000 L CNN
F 1 "S8050" H 8740 4030 50  0000 L CNN
F 2 "kicad_footprint_general:SOT-23" H 9100 4300 50  0001 C CNN
F 3 "" H 8900 4200 50  0001 C CNN
	1    8900 4200
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:Q_NPN_BEC Q20
U 1 1 63897DBA
P 8350 4200
F 0 "Q20" H 8520 4280 50  0000 L CNN
F 1 "S8050" H 8190 4040 50  0000 L CNN
F 2 "kicad_footprint_general:SOT-23" H 8550 4300 50  0001 C CNN
F 3 "" H 8350 4200 50  0001 C CNN
	1    8350 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3700 7400 3700
Wire Wire Line
	7400 3600 7600 3600
NoConn ~ 7600 3300
Wire Wire Line
	7100 3400 7200 3400
Wire Wire Line
	7100 3500 7100 3400
Wire Wire Line
	7600 3500 7100 3500
Wire Wire Line
	7600 3400 7400 3400
$Comp
L kicad_symbol_general:C_Small C20
U 1 1 6387BE0E
P 7300 3400
F 0 "C20" V 7195 3410 50  0000 C CNN
F 1 "100nF" V 7260 3550 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 7300 3400 50  0001 C CNN
F 3 "" H 7300 3400 50  0001 C CNN
	1    7300 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 3700 8600 3700
Wire Wire Line
	8400 3500 8450 3500
Wire Wire Line
	8500 3150 8950 3150
Wire Wire Line
	8500 3200 8500 3150
Wire Wire Line
	8400 3200 8500 3200
Connection ~ 10250 3800
Wire Wire Line
	10250 3150 10250 3800
Wire Wire Line
	9500 3150 10250 3150
Wire Wire Line
	10065 3950 10350 3950
Connection ~ 10065 3950
Wire Wire Line
	10065 3300 10065 3950
Wire Wire Line
	9500 3300 9850 3300
Wire Wire Line
	10250 3850 10350 3850
Wire Wire Line
	10010 3800 10250 3800
Wire Wire Line
	10010 3950 10065 3950
Wire Wire Line
	9300 3150 9150 3150
Wire Wire Line
	9150 3300 9300 3300
$Comp
L kicad_symbol_general:C_Small C22
U 1 1 63877B7A
P 9400 3300
F 0 "C22" V 9520 3300 50  0000 C CNN
F 1 "20nF" V 9450 3470 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 9400 3300 50  0001 C CNN
F 3 "" H 9400 3300 50  0001 C CNN
	1    9400 3300
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:C_Small C21
U 1 1 638774DD
P 9400 3150
F 0 "C21" V 9280 3165 50  0000 C CNN
F 1 "20nF" V 9355 3320 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 9400 3150 50  0001 C CNN
F 3 "" H 9400 3150 50  0001 C CNN
	1    9400 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 3300 8950 3300
$Comp
L kicad_symbol_general:R_Small_US R24
U 1 1 638759B4
P 9050 3150
F 0 "R24" V 8970 3000 50  0000 C CNN
F 1 "33k" V 8965 3200 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 9050 3150 50  0001 C CNN
F 3 "" H 9050 3150 50  0001 C CNN
	1    9050 3150
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R25
U 1 1 6387585E
P 9050 3300
F 0 "R25" V 9135 3160 50  0000 C CNN
F 1 "33k" V 9135 3355 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 9050 3300 50  0001 C CNN
F 3 "" H 9050 3300 50  0001 C CNN
	1    9050 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 3400 8450 3400
Wire Wire Line
	9640 3950 9810 3950
Wire Wire Line
	9640 3900 9640 3950
$Comp
L kicad_symbol_general:C_Small C24
U 1 1 638735A4
P 9910 3950
F 0 "C24" V 10030 3950 50  0000 C CNN
F 1 "10uF" V 9870 3815 50  0000 C CNN
F 2 "kicad_footprint_general:C_0805_2012Metric" H 9910 3950 50  0001 C CNN
F 3 "" H 9910 3950 50  0001 C CNN
	1    9910 3950
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:C_Small C23
U 1 1 63871F39
P 9910 3800
F 0 "C23" V 9785 3800 50  0000 C CNN
F 1 "10uF" V 9870 3665 50  0000 C CNN
F 2 "kicad_footprint_general:C_0805_2012Metric" H 9910 3800 50  0001 C CNN
F 3 "" H 9910 3800 50  0001 C CNN
	1    9910 3800
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:Conn_01x02 J20
U 1 1 63871B02
P 10550 3850
F 0 "J20" H 10630 3842 50  0000 L CNN
F 1 "HBS" H 10630 3751 50  0000 L CNN
F 2 "kicad_footprint_general:PhoenixContact_MCV_1,5_2-G-3.81_1x02_P3.81mm_Vertical" H 10550 3850 50  0001 C CNN
F 3 "" H 10550 3850 50  0001 C CNN
	1    10550 3850
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:MS1192 U20
U 1 1 63870DF1
P 8000 3600
F 0 "U20" H 7770 4145 50  0000 C CNN
F 1 "MS1192" H 8145 4145 50  0000 C CNN
F 2 "kicad_footprint_general:SOIC-16_3.9x9.9mm_P1.27mm" H 8000 3600 50  0001 C CNN
F 3 "" H 8000 3600 50  0001 C CNN
	1    8000 3600
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:CH32V203C8T6 U10
U 1 1 638FA0BD
P 3850 4400
F 0 "U10" H 4485 5450 50  0000 L CNN
F 1 "CH32V203C8T6" H 4485 5365 50  0000 L CNN
F 2 "kicad_footprint_general:LQFP-48_7x7mm_P0.5mm" H 3950 5595 50  0001 C CNN
F 3 "" H 4425 3350 50  0001 C CNN
	1    3850 4400
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:Conn_01x02 J30
U 1 1 638FB0D0
P 10950 960
F 0 "J30" H 10880 1060 50  0000 L CNN
F 1 "POWER" H 10810 750 50  0000 L CNN
F 2 "kicad_footprint_general:PhoenixContact_MCV_1,5_2-G-3.81_1x02_P3.81mm_Vertical" H 10950 960 50  0001 C CNN
F 3 "" H 10950 960 50  0001 C CNN
	1    10950 960 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10750 960  10675 960 
Wire Wire Line
	10750 1060 10350 1060
$Comp
L kicad_symbol_general:L_Core_Iron_Coupled L31
U 1 1 63908577
P 9950 1470
F 0 "L31" V 9915 1585 50  0000 L CNN
F 1 "100mH" V 9995 1580 50  0000 L CNN
F 2 "" H 9950 1470 50  0001 C CNN
F 3 "~" H 9950 1470 50  0001 C CNN
	1    9950 1470
	0    1    1    0   
$EndComp
Wire Wire Line
	9850 1270 9850 1060
Wire Wire Line
	10050 1270 10050 960 
Connection ~ 10050 960 
Connection ~ 10250 3150
Wire Wire Line
	9850 1670 9850 1910
Connection ~ 9850 3300
Wire Wire Line
	9850 3300 10065 3300
Text Label 10090 960  0    50   ~ 0
+18V
$Comp
L kicad_symbol_general:R_Small_US R30
U 1 1 6391F047
P 8800 960
F 0 "R30" V 8710 960 50  0000 C CNN
F 1 "15R" V 8895 960 50  0000 C CNN
F 2 "kicad_footprint_general:R_Axial_DIN0411_L9.9mm_D3.6mm_P18mm_Horizontal" H 8800 960 50  0001 C CNN
F 3 "" H 8800 960 50  0001 C CNN
	1    8800 960 
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:1.5KExxA D32
U 1 1 639250CA
P 8450 1225
F 0 "D32" V 8395 1435 50  0000 R CNN
F 1 "SAMBJ28A" V 8480 1660 50  0000 R CNN
F 2 "kicad_footprint_general:D_SMB" H 8450 1025 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 8400 1225 50  0001 C CNN
	1    8450 1225
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 639297C6
P 8500 1520
F 0 "#PWR0104" H 8500 1270 50  0001 C CNN
F 1 "GND" H 8580 1390 50  0000 R CNN
F 2 "" H 8500 1520 50  0001 C CNN
F 3 "" H 8500 1520 50  0001 C CNN
	1    8500 1520
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:1.5KExxCA D37
U 1 1 6392A2A4
P 9600 1710
F 0 "D37" V 9635 1960 50  0000 C CNN
F 1 "SMBJ24CA" V 9555 1965 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMB" H 9600 1510 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 9600 1710 50  0001 C CNN
	1    9600 1710
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:1.5KExxCA D38
U 1 1 6392AA43
P 10350 1710
F 0 "D38" V 10400 1550 50  0000 C CNN
F 1 "SMBJ24CA" V 10325 1435 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMB" H 10350 1510 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 10350 1710 50  0001 C CNN
	1    10350 1710
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:1.5KExxCA D39
U 1 1 63935587
P 10050 2210
F 0 "D39" H 10045 2100 50  0000 C CNN
F 1 "SMBJ24CA" H 10050 2025 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMB" H 10050 2010 50  0001 C CNN
F 3 "https://www.vishay.com/docs/88301/15ke.pdf" H 10050 2210 50  0001 C CNN
	1    10050 2210
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R32
U 1 1 6393A373
P 9850 2800
F 0 "R32" H 9790 2755 50  0000 R CNN
F 1 "0R" H 9770 2835 50  0000 R CNN
F 2 "kicad_footprint_general:R_0805_2012Metric" H 9850 2800 50  0001 C CNN
F 3 "" H 9850 2800 50  0001 C CNN
	1    9850 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	9850 2900 9850 3300
$Comp
L kicad_symbol_general:R_Small_US R31
U 1 1 6393B646
P 10250 2800
F 0 "R31" H 10185 2755 50  0000 R CNN
F 1 "0R" H 10175 2835 50  0000 R CNN
F 2 "kicad_footprint_general:R_0805_2012Metric" H 10250 2800 50  0001 C CNN
F 3 "" H 10250 2800 50  0001 C CNN
	1    10250 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	10250 2900 10250 3150
$Comp
L kicad_symbol_general:CP_Small C30
U 1 1 6393E638
P 7960 1240
F 0 "C30" H 8048 1286 50  0000 L CNN
F 1 "47uF" H 8048 1195 50  0000 L CNN
F 2 "" H 7960 1240 50  0001 C CNN
F 3 "" H 7960 1240 50  0001 C CNN
	1    7960 1240
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:C_Small C32
U 1 1 6393ED5E
P 7700 1240
F 0 "C32" H 7510 1310 50  0000 L CNN
F 1 "1uF" H 7525 1160 50  0000 L CNN
F 2 "kicad_footprint_general:C_0805_2012Metric" H 7700 1240 50  0001 C CNN
F 3 "" H 7700 1240 50  0001 C CNN
	1    7700 1240
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:XL1509 U30
U 1 1 6393F43A
P 6840 1300
F 0 "U30" H 6605 1545 50  0000 C CNN
F 1 "XL1509" H 6995 1545 50  0000 C CNN
F 2 "kicad_footprint_general:SOIC-8_3.9x4.9mm_P1.27mm" H 6840 1300 50  0001 C CNN
F 3 "" H 6440 1700 50  0001 C CNN
	1    6840 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1140 7700 960 
Wire Wire Line
	7960 1140 7960 960 
Connection ~ 7960 960 
Wire Wire Line
	7960 960  7700 960 
Wire Wire Line
	7700 1460 7960 1460
Wire Wire Line
	7700 1340 7700 1460
Connection ~ 8500 1460
Wire Wire Line
	8500 1460 8500 1520
Wire Wire Line
	7960 1340 7960 1460
Connection ~ 7960 1460
Wire Wire Line
	7960 1460 8450 1460
Wire Wire Line
	6440 1150 6400 1150
Wire Wire Line
	6400 1150 6400 960 
Wire Wire Line
	6400 960  7550 960 
Wire Wire Line
	7240 1150 7300 1150
Wire Wire Line
	7300 1150 7300 1250
Wire Wire Line
	7300 1460 7700 1460
Wire Wire Line
	7240 1450 7300 1450
Connection ~ 7300 1450
Wire Wire Line
	7300 1450 7300 1460
Wire Wire Line
	7240 1350 7300 1350
Connection ~ 7300 1350
Wire Wire Line
	7300 1350 7300 1450
Wire Wire Line
	7240 1250 7300 1250
Connection ~ 7300 1250
Wire Wire Line
	7300 1250 7300 1350
$Comp
L kicad_symbol_general:L_Small L30
U 1 1 639655D3
P 6000 1250
F 0 "L30" V 6135 1250 50  0000 C CNN
F 1 "68uH" V 6060 1250 50  0000 C CNN
F 2 "kicad_footprint_general:L_Bourns_SRN6045TA" H 6000 1250 50  0001 C CNN
F 3 "" H 6000 1250 50  0001 C CNN
	1    6000 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6440 1250 6200 1250
$Comp
L kicad_symbol_general:1N5818 D33
U 1 1 6396A342
P 6200 1460
F 0 "D33" V 6170 1205 50  0000 L CNN
F 1 "SS14" V 6240 1205 50  0000 L CNN
F 2 "kicad_footprint_general:D_SMA" H 6200 1285 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 6200 1460 50  0001 C CNN
	1    6200 1460
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 1310 6200 1250
Connection ~ 6200 1250
Wire Wire Line
	6200 1250 6100 1250
Wire Wire Line
	6200 1610 6200 1660
$Comp
L power:GND #PWR0105
U 1 1 6397AB23
P 6200 1690
F 0 "#PWR0105" H 6200 1440 50  0001 C CNN
F 1 "GND" H 6280 1560 50  0000 R CNN
F 2 "" H 6200 1690 50  0001 C CNN
F 3 "" H 6200 1690 50  0001 C CNN
	1    6200 1690
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1690 6200 1660
Connection ~ 6200 1660
Wire Wire Line
	6440 1350 6370 1350
Wire Wire Line
	6370 1350 6370 1960
Wire Wire Line
	6370 1960 5350 1960
Wire Wire Line
	5350 1960 5350 1250
NoConn ~ 6440 1450
$Comp
L kicad_symbol_general:CP_Small C33
U 1 1 63988BDE
P 5800 1450
F 0 "C33" H 5750 1175 50  0000 L CNN
F 1 "220uF" H 5755 1105 50  0000 L CNN
F 2 "kicad_footprint_general:CP_Elec_6.3x5.4" H 5800 1450 50  0001 C CNN
F 3 "" H 5800 1450 50  0001 C CNN
	1    5800 1450
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:C_Small C34
U 1 1 6398D981
P 5630 1450
F 0 "C34" H 5570 1790 50  0000 L CNN
F 1 "100nF" H 5525 1715 50  0000 L CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 5630 1450 50  0001 C CNN
F 3 "" H 5630 1450 50  0001 C CNN
	1    5630 1450
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:C_Small C35
U 1 1 6398DDFA
P 5460 1450
F 0 "C35" H 5385 1185 50  0000 L CNN
F 1 "1uF" H 5390 1115 50  0000 L CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 5460 1450 50  0001 C CNN
F 3 "" H 5460 1450 50  0001 C CNN
	1    5460 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5460 1660 5460 1550
Wire Wire Line
	5460 1660 5630 1660
Wire Wire Line
	5630 1550 5630 1660
Connection ~ 5630 1660
Wire Wire Line
	5630 1660 5800 1660
Wire Wire Line
	5800 1550 5800 1660
Connection ~ 5800 1660
Wire Wire Line
	5800 1660 6200 1660
Wire Wire Line
	5460 1350 5460 1250
Wire Wire Line
	5350 1250 5460 1250
Connection ~ 5460 1250
Wire Wire Line
	5460 1250 5630 1250
Wire Wire Line
	5630 1350 5630 1250
Connection ~ 5630 1250
Wire Wire Line
	5800 1350 5800 1250
Wire Wire Line
	5630 1250 5800 1250
Connection ~ 5800 1250
Wire Wire Line
	5800 1250 5900 1250
Connection ~ 5350 1250
$Comp
L kicad_symbol_general:LM1117-3.3 U31
U 1 1 639B16DF
P 4200 1250
F 0 "U31" H 4200 1492 50  0000 C CNN
F 1 "AMS1117-3.3" H 4200 1401 50  0000 C CNN
F 2 "kicad_footprint_general:SOT-223" H 4200 1450 50  0001 C CNN
F 3 "" H 4300 1000 50  0001 C CNN
	1    4200 1250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3900 1350 3820 1350
Wire Wire Line
	3820 1350 3820 1250
Wire Wire Line
	3820 1250 3900 1250
$Comp
L kicad_symbol_general:CP_Small C36
U 1 1 639E1CCC
P 3610 1420
F 0 "C36" H 3690 1415 50  0000 L CNN
F 1 "220uF" H 3685 1345 50  0000 L CNN
F 2 "kicad_footprint_general:CP_Elec_6.3x5.4" H 3610 1420 50  0001 C CNN
F 3 "" H 3610 1420 50  0001 C CNN
	1    3610 1420
	1    0    0    -1  
$EndComp
Connection ~ 3820 1250
$Comp
L kicad_symbol_general:C_Small C37
U 1 1 639E8700
P 3440 1420
F 0 "C37" H 3375 1715 50  0000 L CNN
F 1 "1uF" H 3380 1645 50  0000 L CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 3440 1420 50  0001 C CNN
F 3 "" H 3440 1420 50  0001 C CNN
	1    3440 1420
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:C_Small C38
U 1 1 639E8E35
P 3260 1420
F 0 "C38" H 3010 1425 50  0000 L CNN
F 1 "100nF" H 3010 1350 50  0000 L CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 3260 1420 50  0001 C CNN
F 3 "" H 3260 1420 50  0001 C CNN
	1    3260 1420
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1250 2850 1250
Wire Wire Line
	3260 1320 3260 1250
Connection ~ 3260 1250
Wire Wire Line
	3260 1250 3440 1250
Wire Wire Line
	3440 1320 3440 1250
Connection ~ 3440 1250
Wire Wire Line
	3440 1250 3610 1250
Wire Wire Line
	3610 1320 3610 1250
Connection ~ 3610 1250
Wire Wire Line
	3610 1250 3820 1250
Wire Wire Line
	3260 1520 3260 1610
Wire Wire Line
	3260 1610 3440 1610
Wire Wire Line
	4200 1610 4200 1550
Wire Wire Line
	3610 1520 3610 1610
Connection ~ 3610 1610
Wire Wire Line
	3610 1610 3900 1610
Wire Wire Line
	3440 1520 3440 1610
Connection ~ 3440 1610
Wire Wire Line
	3440 1610 3610 1610
$Comp
L power:GND #PWR0106
U 1 1 63A16A6B
P 4200 1660
F 0 "#PWR0106" H 4200 1410 50  0001 C CNN
F 1 "GND" H 4280 1530 50  0000 R CNN
F 2 "" H 4200 1660 50  0001 C CNN
F 3 "" H 4200 1660 50  0001 C CNN
	1    4200 1660
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1660 4200 1610
Connection ~ 4200 1610
Text Label 5220 1250 0    50   ~ 0
+5V
Text Label 8600 3700 2    50   ~ 0
+5V
$Comp
L kicad_symbol_general:R_Small_US R20
U 1 1 63A1F574
P 7300 3200
F 0 "R20" V 7135 3200 50  0000 C CNN
F 1 "1.6k" V 7215 3205 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 7300 3200 50  0001 C CNN
F 3 "" H 7300 3200 50  0001 C CNN
	1    7300 3200
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R21
U 1 1 63A1FDF4
P 6900 3360
F 0 "R21" H 7100 3330 50  0000 R CNN
F 1 "3.3k" H 7110 3400 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 6900 3360 50  0001 C CNN
F 3 "" H 6900 3360 50  0001 C CNN
	1    6900 3360
	-1   0    0    1   
$EndComp
Wire Wire Line
	7400 3200 7600 3200
Wire Wire Line
	7200 3200 6900 3200
Wire Wire Line
	6900 3200 6900 3260
$Comp
L power:GND #PWR0107
U 1 1 63A38021
P 6900 3500
F 0 "#PWR0107" H 6900 3250 50  0001 C CNN
F 1 "GND" H 6980 3365 50  0000 R CNN
F 2 "" H 6900 3500 50  0001 C CNN
F 3 "" H 6900 3500 50  0001 C CNN
	1    6900 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3460 6900 3500
Wire Wire Line
	6900 3200 6700 3200
Connection ~ 6900 3200
$Comp
L kicad_symbol_general:R_Small_US R22
U 1 1 63A4801A
P 7300 3600
F 0 "R22" V 7265 3735 50  0000 C CNN
F 1 "0R" V 7265 3490 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 7300 3600 50  0001 C CNN
F 3 "" H 7300 3600 50  0001 C CNN
	1    7300 3600
	0    1    1    0   
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R23
U 1 1 63A483A9
P 7300 3700
F 0 "R23" V 7265 3835 50  0000 C CNN
F 1 "0R" V 7265 3590 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 7300 3700 50  0001 C CNN
F 3 "" H 7300 3700 50  0001 C CNN
	1    7300 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 3600 7000 3600
Wire Wire Line
	7200 3700 7000 3700
Text Label 7000 3700 0    50   ~ 0
TX2
Text Label 7000 3600 0    50   ~ 0
EN
Text Label 6700 3200 0    50   ~ 0
RX2
$Comp
L kicad_symbol_general:C_Small C11
U 1 1 638B5BBE
P 1550 4350
F 0 "C11" V 1590 4380 50  0000 L CNN
F 1 "18pF" V 1665 4285 50  0000 L CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 1550 4350 50  0001 C CNN
F 3 "" H 1550 4350 50  0001 C CNN
	1    1550 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	2130 4250 2750 4250
Wire Wire Line
	2130 4250 2130 4150
Wire Wire Line
	1695 4280 1650 4280
Wire Wire Line
	1650 4280 1650 4250
Wire Wire Line
	1650 4220 1695 4220
$Comp
L kicad_symbol_general:C_Small C10
U 1 1 63911BEA
P 1550 4150
F 0 "C10" V 1500 4195 50  0000 L CNN
F 1 "18pF" V 1500 3925 50  0000 L CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 1550 4150 50  0001 C CNN
F 3 "" H 1550 4150 50  0001 C CNN
	1    1550 4150
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 4250 1400 4250
Connection ~ 1650 4250
Wire Wire Line
	1650 4250 1650 4220
Wire Wire Line
	1450 4150 1400 4150
Wire Wire Line
	1400 4150 1400 4250
Wire Wire Line
	1400 4350 1450 4350
Connection ~ 1400 4250
Wire Wire Line
	1400 4250 1400 4350
Wire Wire Line
	4950 4150 5200 4150
Text Label 5200 4150 2    50   ~ 0
UDP
Wire Wire Line
	4950 4250 5200 4250
Text Label 5200 4250 2    50   ~ 0
UDM
$Comp
L kicad_symbol_general:C_Small C15
U 1 1 6395900F
P 4500 5625
F 0 "C15" H 4580 5560 50  0000 C CNN
F 1 "100nF" H 4310 5625 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 4500 5625 50  0001 C CNN
F 3 "" H 4500 5625 50  0001 C CNN
	1    4500 5625
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 5500 4500 5500
Wire Wire Line
	4500 5525 4500 5500
Connection ~ 4500 5500
Wire Wire Line
	4500 5500 4750 5500
Wire Wire Line
	4300 5500 4300 5750
$Comp
L kicad_symbol_general:C_Small C16
U 1 1 639A5190
P 2140 4650
F 0 "C16" H 2000 4665 50  0000 C CNN
F 1 "100nF" H 2325 4690 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 2140 4650 50  0001 C CNN
F 3 "" H 2140 4650 50  0001 C CNN
	1    2140 4650
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:C_Small C12
U 1 1 639A5BA4
P 2250 3725
F 0 "C12" H 2160 3655 50  0000 C CNN
F 1 "100nF" H 2125 3800 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 2250 3725 50  0001 C CNN
F 3 "" H 2250 3725 50  0001 C CNN
	1    2250 3725
	-1   0    0    1   
$EndComp
$Comp
L kicad_symbol_general:C_Small C13
U 1 1 639A636B
P 3195 3150
F 0 "C13" H 3115 3095 50  0000 C CNN
F 1 "100nF" H 3380 3140 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 3195 3150 50  0001 C CNN
F 3 "" H 3195 3150 50  0001 C CNN
	1    3195 3150
	-1   0    0    1   
$EndComp
$Comp
L kicad_symbol_general:C_Small C14
U 1 1 639A66E3
P 5200 3850
F 0 "C14" H 5050 3860 50  0000 C CNN
F 1 "100nF" H 5070 3790 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 5200 3850 50  0001 C CNN
F 3 "" H 5200 3850 50  0001 C CNN
	1    5200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4550 2140 4550
Wire Wire Line
	2140 4550 1900 4550
Connection ~ 2140 4550
Wire Wire Line
	2250 4650 2250 4750
Wire Wire Line
	2250 4750 2140 4750
Wire Wire Line
	2250 4650 2750 4650
Wire Wire Line
	2140 4750 1900 4750
Connection ~ 2140 4750
Wire Wire Line
	2250 3850 2750 3850
Wire Wire Line
	2250 3850 2250 3825
$Comp
L power:GND #PWR0108
U 1 1 63A28C94
P 2250 3600
F 0 "#PWR0108" H 2250 3350 50  0001 C CNN
F 1 "GND" H 2330 3465 50  0000 R CNN
F 2 "" H 2250 3600 50  0001 C CNN
F 3 "" H 2250 3600 50  0001 C CNN
	1    2250 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 3600 2250 3625
Wire Wire Line
	4950 3950 5200 3950
Wire Wire Line
	3400 3050 3195 3050
Wire Wire Line
	3195 3050 2950 3050
Connection ~ 3195 3050
Connection ~ 5200 3950
Wire Wire Line
	5200 3950 5400 3950
Wire Wire Line
	5200 3750 4950 3750
Wire Wire Line
	4950 3750 4950 3850
Wire Wire Line
	5200 3750 5400 3750
Connection ~ 5200 3750
Text Label 5400 3750 2    50   ~ 0
VCC
Text Label 5400 3950 2    50   ~ 0
GND
$Comp
L kicad_symbol_general:D_Bridge_AA+- D31
U 1 1 638FD990
P 9300 1090
F 0 "D31" H 9350 1355 50  0000 C CNN
F 1 "MB10S" H 9350 1285 50  0000 C CNN
F 2 "kicad_footprint_general:Diode_Bridge_MB10S" H 9340 1060 50  0001 C CNN
F 3 "~" H 9340 1060 50  0001 C CNN
	1    9300 1090
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8950 1220 8950 1460
Wire Wire Line
	8950 1460 8500 1460
Connection ~ 7700 960 
Connection ~ 7700 1460
$Comp
L kicad_symbol_general:1N5819 D30
U 1 1 63979CE1
P 10525 960
F 0 "D30" H 10530 1120 50  0000 C CNN
F 1 "SS14" H 10525 1050 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMA" H 10525 785 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 10525 960 50  0001 C CNN
	1    10525 960 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10375 960  10050 960 
Wire Wire Line
	9500 960  10050 960 
Connection ~ 9850 1060
Wire Wire Line
	9600 1910 9600 1860
Wire Wire Line
	9600 1910 9850 1910
Wire Wire Line
	9600 1060 9600 1220
Wire Wire Line
	9600 1060 9850 1060
Wire Wire Line
	10350 1565 10350 1560
Connection ~ 10350 1060
Wire Wire Line
	10350 1060 9850 1060
Connection ~ 10350 1560
Wire Wire Line
	10350 1560 10350 1060
Wire Wire Line
	9500 1220 9600 1220
Connection ~ 9600 1220
Wire Wire Line
	9600 1220 9600 1560
Wire Wire Line
	8900 960  9000 960 
Wire Wire Line
	8950 1220 9000 1220
Wire Wire Line
	9900 2210 9850 2210
Wire Wire Line
	10200 2210 10250 2210
Wire Wire Line
	10050 1670 10050 1910
Wire Wire Line
	10350 1910 10350 1860
Wire Wire Line
	10250 3850 10250 3800
$Comp
L power:GND #PWR0110
U 1 1 63C9F114
P 1400 4400
F 0 "#PWR0110" H 1400 4150 50  0001 C CNN
F 1 "GND" H 1480 4270 50  0000 R CNN
F 2 "" H 1400 4400 50  0001 C CNN
F 3 "" H 1400 4400 50  0001 C CNN
	1    1400 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 4400 1400 4350
Connection ~ 1400 4350
Text Label 1900 4550 0    50   ~ 0
GND
Text Label 1900 4750 0    50   ~ 0
VCC
Wire Wire Line
	10250 2210 10250 2700
Wire Wire Line
	9850 2210 9850 2700
Wire Wire Line
	10050 1910 10250 1910
Wire Wire Line
	10250 2210 10250 1910
Connection ~ 10250 2210
Connection ~ 10250 1910
Wire Wire Line
	10250 1910 10350 1910
Wire Wire Line
	9850 2210 9850 1910
Connection ~ 9850 2210
Connection ~ 9850 1910
Text Label 4750 5500 2    50   ~ 0
VCC
Text Label 4750 5750 2    50   ~ 0
GND
Text Label 2950 3050 0    50   ~ 0
VCC
Text Label 2950 3250 0    50   ~ 0
GND
Wire Wire Line
	4950 4050 5200 4050
Wire Wire Line
	4950 4350 5200 4350
Wire Wire Line
	4950 4450 5200 4450
Wire Wire Line
	4950 4550 5200 4550
Wire Wire Line
	4950 4650 5200 4650
Wire Wire Line
	4950 4750 5200 4750
Wire Wire Line
	4950 4850 5200 4850
Wire Wire Line
	4950 4950 5200 4950
Wire Wire Line
	4200 5750 4200 5500
Wire Wire Line
	4100 5750 4100 5500
Wire Wire Line
	3900 5750 3900 5500
Wire Wire Line
	3800 5750 3800 5500
Wire Wire Line
	3700 5750 3700 5500
Wire Wire Line
	3600 5750 3600 5500
Wire Wire Line
	3500 5750 3500 5500
Wire Wire Line
	3400 5750 3400 5500
Wire Wire Line
	3300 5750 3300 5500
Wire Wire Line
	2750 4950 2500 4950
Wire Wire Line
	2750 4850 2500 4850
Wire Wire Line
	2750 4750 2500 4750
Wire Wire Line
	2750 4450 2500 4450
Wire Wire Line
	2750 4150 2500 4150
Wire Wire Line
	2750 4050 2500 4050
Wire Wire Line
	2750 3950 2500 3950
Wire Wire Line
	3600 3050 3600 3300
Wire Wire Line
	3700 3050 3700 3300
Wire Wire Line
	3800 3050 3800 3300
Wire Wire Line
	3900 3050 3900 3300
Wire Wire Line
	4000 3050 4000 3300
Wire Wire Line
	4100 3050 4100 3300
Wire Wire Line
	4200 3050 4200 3300
Wire Wire Line
	4300 3050 4300 3300
Wire Wire Line
	4400 3050 4400 3300
Wire Wire Line
	3300 3300 3300 3250
Wire Wire Line
	3300 3250 3195 3250
Connection ~ 3195 3250
Wire Wire Line
	3195 3250 2950 3250
Wire Wire Line
	3400 3050 3400 3300
$Comp
L kicad_symbol_general:C_Small C17
U 1 1 63FC5238
P 1550 3700
F 0 "C17" H 1465 3635 50  0000 C CNN
F 1 "100nF" H 1680 3635 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 1550 3700 50  0001 C CNN
F 3 "" H 1550 3700 50  0001 C CNN
	1    1550 3700
	1    0    0    -1  
$EndComp
Text Label 2500 4450 0    50   ~ 0
NRST
$Comp
L kicad_symbol_general:R_Small_US R12
U 1 1 63FC7EAB
P 1750 3550
F 0 "R12" V 1830 3560 50  0000 C CNN
F 1 "330R" V 1665 3555 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 1750 3550 50  0001 C CNN
F 3 "" H 1750 3550 50  0001 C CNN
	1    1750 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1550 3500 1550 3550
Connection ~ 1550 3550
Wire Wire Line
	1550 3550 1550 3600
Wire Wire Line
	1550 3550 1650 3550
$Comp
L power:GND #PWR0111
U 1 1 64001BBD
P 1550 3900
F 0 "#PWR0111" H 1550 3650 50  0001 C CNN
F 1 "GND" H 1630 3770 50  0000 R CNN
F 2 "" H 1550 3900 50  0001 C CNN
F 3 "" H 1550 3900 50  0001 C CNN
	1    1550 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 3800 1550 3850
$Comp
L power:VCC #PWR0112
U 1 1 640157F8
P 1550 3195
F 0 "#PWR0112" H 1550 3045 50  0001 C CNN
F 1 "VCC" H 1567 3368 50  0000 C CNN
F 2 "" H 1550 3195 50  0001 C CNN
F 3 "" H 1550 3195 50  0001 C CNN
	1    1550 3195
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 3550 2050 3550
Text Label 2050 3550 2    50   ~ 0
NRST
Text Label 5200 4350 2    50   ~ 0
TX1
Text Label 5200 4450 2    50   ~ 0
RX1
Text Label 2500 4950 0    50   ~ 0
TX2
Text Label 3300 5750 1    50   ~ 0
RX2
Text Label 4100 5750 1    50   ~ 0
TX3
Text Label 4200 5750 1    50   ~ 0
RX3
Text Label 3800 5750 1    50   ~ 0
TX4
Text Label 3900 5750 1    50   ~ 0
RX4
Text Label 3400 5750 1    50   ~ 0
EN
$Comp
L kicad_symbol_general:R_Small_US R10
U 1 1 640696FB
P 3200 2900
F 0 "R10" V 3235 2835 50  0000 R CNN
F 1 "10k" V 3150 2830 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 3200 2900 50  0001 C CNN
F 3 "" H 3200 2900 50  0001 C CNN
	1    3200 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3300 2900 3500 2900
Wire Wire Line
	3500 2900 3500 3300
Text Label 3500 3050 3    50   ~ 0
BOOT0
Text Label 2950 2900 0    50   ~ 0
GND
Text Label 4000 5750 1    50   ~ 0
BOOT1
$Comp
L kicad_symbol_general:USB_C_Receptacle_14 J10
U 1 1 6392847F
P 1100 1425
F 0 "J10" H 760 2195 50  0000 C CNN
F 1 "USB_P" H 1340 2195 50  0000 C CNN
F 2 "kicad_footprint_general:USB_C_Receptacle_14Pin" H 1250 1425 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1250 1425 50  0001 C CNN
	1    1100 1425
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:USB_C_Receptacle_14 J11
U 1 1 6392AC66
P 1050 6500
F 0 "J11" H 715 7265 50  0000 C CNN
F 1 "DBG" H 1350 7265 50  0000 C CNN
F 2 "kicad_footprint_general:USB_C_Receptacle_14Pin" H 1200 6500 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1200 6500 50  0001 C CNN
	1    1050 6500
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:CH340E U11
U 1 1 6392E39B
P 3470 6850
F 0 "U11" H 3250 7295 50  0000 C CNN
F 1 "CH340E" H 3625 7295 50  0000 C CNN
F 2 "kicad_footprint_general:MSOP-10_3x3mm_P0.5mm" V 3130 6430 50  0001 L CNN
F 3 "http://www.datasheet5.com/pdf-local-2195953" H 3120 7650 50  0001 C CNN
	1    3470 6850
	1    0    0    -1  
$EndComp
Connection ~ 1795 4150
Wire Wire Line
	1650 4350 1795 4350
Wire Wire Line
	1795 4350 2750 4350
Connection ~ 1795 4350
Wire Wire Line
	1795 4150 1650 4150
Wire Wire Line
	2130 4150 1795 4150
$Comp
L kicad_symbol_general:Crystal_GND24_Small Y10
U 1 1 638A42DA
P 1795 4250
F 0 "Y10" V 1841 4147 50  0000 R CNN
F 1 "12M" V 1750 4147 50  0000 R CNN
F 2 "kicad_footprint_general:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 1795 4250 50  0001 C CNN
F 3 "~" H 1795 4250 50  0001 C CNN
	1    1795 4250
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R11
U 1 1 63FC4B64
P 1550 3400
F 0 "R11" H 1670 3370 50  0000 C CNN
F 1 "10k" H 1670 3455 50  0000 C CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 1550 3400 50  0001 C CNN
F 3 "" H 1550 3400 50  0001 C CNN
	1    1550 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 1250 4650 1250
$Comp
L kicad_symbol_general:1N5819 D34
U 1 1 63A5D317
P 5000 1250
F 0 "D34" H 4960 1350 50  0000 C CNN
F 1 "SS14" H 5150 1355 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMA" H 5000 1075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 5000 1250 50  0001 C CNN
	1    5000 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 1250 5350 1250
Wire Wire Line
	4850 1500 4750 1500
Wire Wire Line
	4750 1500 4750 1250
Connection ~ 4750 1250
Wire Wire Line
	4750 1250 4850 1250
Wire Wire Line
	4850 1750 4750 1750
Wire Wire Line
	4750 1750 4750 1500
Connection ~ 4750 1500
Wire Wire Line
	5150 1500 5295 1500
Wire Wire Line
	5150 1750 5300 1750
Text Label 5295 1500 2    50   ~ 0
VBA
Text Label 5300 1750 2    50   ~ 0
VBB
Wire Wire Line
	1700 1425 1750 1425
Wire Wire Line
	1750 1425 1750 1525
Wire Wire Line
	1750 1725 1700 1725
Wire Wire Line
	1700 1625 1750 1625
Connection ~ 1750 1625
Wire Wire Line
	1750 1625 1750 1725
Wire Wire Line
	1700 1525 1750 1525
Connection ~ 1750 1525
Wire Wire Line
	1750 1525 1750 1625
Wire Wire Line
	1750 1425 1950 1425
Connection ~ 1750 1425
Text Label 1950 1425 2    50   ~ 0
VBA
Wire Wire Line
	1700 1825 1750 1825
Wire Wire Line
	1750 1825 1750 1925
Wire Wire Line
	1750 2125 1700 2125
Wire Wire Line
	1700 2025 1750 2025
Connection ~ 1750 2025
Wire Wire Line
	1750 2025 1750 2125
Wire Wire Line
	1700 1925 1750 1925
Connection ~ 1750 1925
Wire Wire Line
	1750 1925 1750 2025
$Comp
L power:GND #PWR0113
U 1 1 63B6F0B8
P 1750 2150
F 0 "#PWR0113" H 1750 1900 50  0001 C CNN
F 1 "GND" H 1830 2020 50  0000 R CNN
F 2 "" H 1750 2150 50  0001 C CNN
F 3 "" H 1750 2150 50  0001 C CNN
	1    1750 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2125 1750 2150
Connection ~ 1750 2125
Wire Wire Line
	800  2450 800  2500
Wire Wire Line
	800  2500 925  2500
Wire Wire Line
	1175 2500 1175 2450
Wire Wire Line
	925  2450 925  2500
Connection ~ 925  2500
Wire Wire Line
	925  2500 1050 2500
Wire Wire Line
	1050 2450 1050 2500
Connection ~ 1050 2500
Wire Wire Line
	1050 2500 1175 2500
$Comp
L power:GND #PWR0114
U 1 1 63BD409A
P 1200 2500
F 0 "#PWR0114" H 1200 2250 50  0001 C CNN
F 1 "GND" H 1280 2370 50  0000 R CNN
F 2 "" H 1200 2500 50  0001 C CNN
F 3 "" H 1200 2500 50  0001 C CNN
	1    1200 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1175 2500 1200 2500
Connection ~ 1175 2500
Wire Wire Line
	1700 1025 1750 1025
Wire Wire Line
	1750 1025 1750 1125
Wire Wire Line
	1700 1125 1750 1125
Connection ~ 1750 1125
Wire Wire Line
	1750 1125 1950 1125
Wire Wire Line
	1700 825  1750 825 
Wire Wire Line
	1750 825  1750 925 
Wire Wire Line
	1750 925  1700 925 
Wire Wire Line
	1750 925  1950 925 
Connection ~ 1750 925 
NoConn ~ 1700 1225
NoConn ~ 1700 1325
Text Label 1950 925  2    50   ~ 0
UDM
Text Label 1950 1125 2    50   ~ 0
UDP
Wire Wire Line
	750  7525 750  7600
Wire Wire Line
	750  7600 875  7600
Wire Wire Line
	1125 7600 1125 7525
Wire Wire Line
	1000 7525 1000 7600
Connection ~ 1000 7600
Wire Wire Line
	1000 7600 1125 7600
Wire Wire Line
	875  7525 875  7600
Connection ~ 875  7600
Wire Wire Line
	875  7600 1000 7600
Wire Wire Line
	1650 7000 1700 7000
Wire Wire Line
	1700 7000 1700 7100
Wire Wire Line
	1700 7200 1650 7200
Wire Wire Line
	1650 7100 1700 7100
Connection ~ 1700 7100
Wire Wire Line
	1700 7100 1700 7200
Wire Wire Line
	1650 6900 1700 6900
Wire Wire Line
	1700 6900 1700 7000
Connection ~ 1700 7000
$Comp
L power:GND #PWR0115
U 1 1 63D9A2CC
P 1150 7600
F 0 "#PWR0115" H 1150 7350 50  0001 C CNN
F 1 "GND" H 1230 7470 50  0000 R CNN
F 2 "" H 1150 7600 50  0001 C CNN
F 3 "" H 1150 7600 50  0001 C CNN
	1    1150 7600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1125 7600 1150 7600
Connection ~ 1125 7600
$Comp
L power:GND #PWR0116
U 1 1 63DB9A37
P 1700 7250
F 0 "#PWR0116" H 1700 7000 50  0001 C CNN
F 1 "GND" H 1780 7120 50  0000 R CNN
F 2 "" H 1700 7250 50  0001 C CNN
F 3 "" H 1700 7250 50  0001 C CNN
	1    1700 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 7200 1700 7250
Connection ~ 1700 7200
Wire Wire Line
	1650 6800 1700 6800
Wire Wire Line
	1700 6800 1700 6700
Wire Wire Line
	1700 6500 1650 6500
Wire Wire Line
	1650 6600 1700 6600
Connection ~ 1700 6600
Wire Wire Line
	1700 6600 1700 6500
Wire Wire Line
	1650 6700 1700 6700
Connection ~ 1700 6700
Wire Wire Line
	1700 6700 1700 6600
Wire Wire Line
	1700 6800 1900 6800
Connection ~ 1700 6800
Text Label 1900 6800 2    50   ~ 0
VBB
NoConn ~ 1650 6400
NoConn ~ 1650 6300
Wire Wire Line
	1650 6100 1700 6100
Wire Wire Line
	1700 6100 1700 6200
Wire Wire Line
	1700 6200 1650 6200
Wire Wire Line
	1700 6200 1900 6200
Connection ~ 1700 6200
Wire Wire Line
	1650 6000 1700 6000
Wire Wire Line
	1700 6000 1700 5900
Wire Wire Line
	1700 5900 1650 5900
Wire Wire Line
	1700 6000 1900 6000
Connection ~ 1700 6000
Text Label 1900 6200 2    50   ~ 0
U2P
Text Label 1900 6000 2    50   ~ 0
U2M
Wire Wire Line
	3070 7000 2870 7000
Text Label 2870 7000 0    50   ~ 0
U2P
Wire Wire Line
	3070 7150 2870 7150
Text Label 2870 7150 0    50   ~ 0
U2M
Wire Wire Line
	3070 6800 2870 6800
Text Label 2370 6800 0    50   ~ 0
GND
Wire Wire Line
	3070 6650 3020 6650
Wire Wire Line
	3020 6650 3020 6550
Wire Wire Line
	3020 6550 3070 6550
Wire Wire Line
	3020 6550 2870 6550
Connection ~ 3020 6550
$Comp
L power:VCC #PWR0117
U 1 1 6406874E
P 2470 6550
F 0 "#PWR0117" H 2470 6400 50  0001 C CNN
F 1 "VCC" V 2530 6615 50  0000 C CNN
F 2 "" H 2470 6550 50  0001 C CNN
F 3 "" H 2470 6550 50  0001 C CNN
	1    2470 6550
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:C_Small C19
U 1 1 64068EE4
P 2870 6675
F 0 "C19" H 2940 6735 50  0000 C CNN
F 1 "1uF" H 2950 6615 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 2870 6675 50  0001 C CNN
F 3 "" H 2870 6675 50  0001 C CNN
	1    2870 6675
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:C_Small C18
U 1 1 64069595
P 2595 6675
F 0 "C18" H 2670 6735 50  0000 C CNN
F 1 "100nF" H 2715 6605 50  0000 C CNN
F 2 "kicad_footprint_general:C_0603_1608Metric" H 2595 6675 50  0001 C CNN
F 3 "" H 2595 6675 50  0001 C CNN
	1    2595 6675
	1    0    0    -1  
$EndComp
Wire Wire Line
	2870 6575 2870 6550
Connection ~ 2870 6550
Wire Wire Line
	2870 6550 2595 6550
Wire Wire Line
	2870 6775 2870 6800
Connection ~ 2870 6800
Wire Wire Line
	2870 6800 2595 6800
Wire Wire Line
	2595 6575 2595 6550
Connection ~ 2595 6550
Wire Wire Line
	2595 6550 2470 6550
Wire Wire Line
	2595 6775 2595 6800
Connection ~ 2595 6800
Wire Wire Line
	2595 6800 2370 6800
NoConn ~ 3870 7050
NoConn ~ 3870 7150
NoConn ~ 3870 6600
Wire Wire Line
	3870 6700 4070 6700
Wire Wire Line
	3870 6800 4070 6800
Text Label 4070 6700 2    50   ~ 0
TX1
Text Label 4070 6800 2    50   ~ 0
RX1
Wire Wire Line
	8450 1375 8450 1460
Connection ~ 8450 1460
Wire Wire Line
	8450 1460 8500 1460
Wire Wire Line
	8450 1075 8450 960 
Wire Wire Line
	7960 960  8450 960 
Connection ~ 8450 960 
Wire Wire Line
	8450 960  8700 960 
$Comp
L kicad_symbol_general:1N5819 D35
U 1 1 6449258F
P 5000 1500
F 0 "D35" H 4960 1610 50  0000 C CNN
F 1 "SS14" H 5155 1610 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMA" H 5000 1325 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 5000 1500 50  0001 C CNN
	1    5000 1500
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:1N5819 D36
U 1 1 64492DF8
P 5000 1750
F 0 "D36" H 4960 1860 50  0000 C CNN
F 1 "SS14" H 5150 1860 50  0000 C CNN
F 2 "kicad_footprint_general:D_SMA" H 5000 1575 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 5000 1750 50  0001 C CNN
	1    5000 1750
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 6449BEFA
P 7550 900
F 0 "#FLG0101" H 7550 975 50  0001 C CNN
F 1 "PWR_FLAG" H 7550 1073 50  0000 C CNN
F 2 "" H 7550 900 50  0001 C CNN
F 3 "~" H 7550 900 50  0001 C CNN
	1    7550 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 900  7550 960 
Connection ~ 7550 960 
Wire Wire Line
	7550 960  7700 960 
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 644C2BCD
P 1850 1625
F 0 "#FLG0102" H 1850 1700 50  0001 C CNN
F 1 "PWR_FLAG" V 1850 1730 50  0000 L CNN
F 2 "" H 1850 1625 50  0001 C CNN
F 3 "~" H 1850 1625 50  0001 C CNN
	1    1850 1625
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 1625 1750 1625
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 644EAB17
P 4750 1150
F 0 "#FLG0103" H 4750 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 4750 1323 50  0000 C CNN
F 2 "" H 4750 1150 50  0001 C CNN
F 3 "~" H 4750 1150 50  0001 C CNN
	1    4750 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1150 4750 1250
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 64513F8E
P 5460 1150
F 0 "#FLG0104" H 5460 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 5460 1323 50  0000 C CNN
F 2 "" H 5460 1150 50  0001 C CNN
F 3 "~" H 5460 1150 50  0001 C CNN
	1    5460 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5460 1150 5460 1250
$Comp
L power:PWR_FLAG #FLG0105
U 1 1 6453C1AF
P 1750 6500
F 0 "#FLG0105" H 1750 6575 50  0001 C CNN
F 1 "PWR_FLAG" V 1750 6605 50  0000 L CNN
F 2 "" H 1750 6500 50  0001 C CNN
F 3 "~" H 1750 6500 50  0001 C CNN
	1    1750 6500
	0    1    1    0   
$EndComp
Wire Wire Line
	1750 6500 1700 6500
Connection ~ 1700 6500
NoConn ~ 3600 3050
NoConn ~ 3700 3050
NoConn ~ 3800 3050
NoConn ~ 3900 3050
NoConn ~ 5200 4050
NoConn ~ 5200 4550
NoConn ~ 5200 4650
NoConn ~ 5200 4750
NoConn ~ 5200 4850
NoConn ~ 5200 4950
NoConn ~ 4200 5750
NoConn ~ 4100 5750
NoConn ~ 3900 5750
NoConn ~ 3800 5750
NoConn ~ 3700 5750
NoConn ~ 3600 5750
NoConn ~ 3500 5750
NoConn ~ 2500 4850
NoConn ~ 2500 4750
NoConn ~ 2500 4150
NoConn ~ 2500 4050
NoConn ~ 2500 3950
Text Label 2650 1250 0    50   ~ 0
VCC
Wire Wire Line
	9000 4400 9000 4625
Text Label 8700 3500 2    50   ~ 0
GND
$Comp
L power:PWR_FLAG #FLG0106
U 1 1 64AC2B9D
P 3900 1650
F 0 "#FLG0106" H 3900 1725 50  0001 C CNN
F 1 "PWR_FLAG" H 3900 1823 50  0000 C CNN
F 2 "" H 3900 1650 50  0001 C CNN
F 3 "~" H 3900 1650 50  0001 C CNN
	1    3900 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 1650 3900 1610
Connection ~ 3900 1610
Wire Wire Line
	3900 1610 4200 1610
Wire Wire Line
	9365 4625 9000 4625
Connection ~ 9365 4625
Connection ~ 9000 4625
Wire Wire Line
	9000 4625 9000 4670
$Comp
L kicad_symbol_general:R_Small_US R40
U 1 1 64BDCDC1
P 6500 5350
F 0 "R40" V 6645 5425 50  0000 R CNN
F 1 "10k" V 6575 5420 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 6500 5350 50  0001 C CNN
F 3 "" H 6500 5350 50  0001 C CNN
	1    6500 5350
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R41
U 1 1 64BDD009
P 6500 5600
F 0 "R41" V 6635 5665 50  0000 R CNN
F 1 "10k" V 6570 5660 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 6500 5600 50  0001 C CNN
F 3 "" H 6500 5600 50  0001 C CNN
	1    6500 5600
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:LED_Small D40
U 1 1 64BDEFBC
P 6800 5350
F 0 "D40" H 6800 5200 50  0000 C CNN
F 1 "RED" H 6800 5275 50  0000 C CNN
F 2 "kicad_footprint_general:LED_0603_1608Metric" V 6800 5350 50  0001 C CNN
F 3 "" V 6800 5350 50  0001 C CNN
	1    6800 5350
	-1   0    0    1   
$EndComp
Wire Wire Line
	6600 5350 6700 5350
Wire Wire Line
	6900 5350 7100 5350
Text Label 7100 5350 2    50   ~ 0
GND
Wire Wire Line
	6400 5350 6350 5350
Text Label 6150 5350 0    50   ~ 0
VCC
Wire Wire Line
	6350 5350 6350 5600
Connection ~ 6350 5350
Wire Wire Line
	6350 5350 6150 5350
Wire Wire Line
	6400 5600 6350 5600
Connection ~ 6350 5600
Wire Wire Line
	6350 5600 6350 5850
Wire Wire Line
	6600 5600 6700 5600
Wire Wire Line
	6900 5600 7100 5600
Text Label 7100 5600 2    50   ~ 0
LPU
$Comp
L kicad_symbol_general:R_Small_US R42
U 1 1 64DA0B14
P 6500 5850
F 0 "R42" V 6635 5915 50  0000 R CNN
F 1 "10k" V 6570 5910 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 6500 5850 50  0001 C CNN
F 3 "" H 6500 5850 50  0001 C CNN
	1    6500 5850
	0    -1   -1   0   
$EndComp
$Comp
L kicad_symbol_general:LED_Small D42
U 1 1 64DA0E16
P 6800 5850
F 0 "D42" H 6800 5700 50  0000 C CNN
F 1 "RED" H 6800 5775 50  0000 C CNN
F 2 "kicad_footprint_general:LED_0603_1608Metric" V 6800 5850 50  0001 C CNN
F 3 "" V 6800 5850 50  0001 C CNN
	1    6800 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6600 5850 6700 5850
Wire Wire Line
	6900 5850 7100 5850
Wire Wire Line
	6400 5850 6350 5850
Connection ~ 6350 5850
$Comp
L kicad_symbol_general:R_Small_US R43
U 1 1 64E4BE9D
P 6500 6100
F 0 "R43" V 6635 6165 50  0000 R CNN
F 1 "10k" V 6570 6160 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 6500 6100 50  0001 C CNN
F 3 "" H 6500 6100 50  0001 C CNN
	1    6500 6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6350 6100 6400 6100
Wire Wire Line
	6350 5850 6350 6100
Wire Wire Line
	6600 6100 6700 6100
$Comp
L kicad_symbol_general:LED_Small D43
U 1 1 64ECB503
P 6800 6100
F 0 "D43" H 6800 5950 50  0000 C CNN
F 1 "RED" H 6800 6025 50  0000 C CNN
F 2 "kicad_footprint_general:LED_0603_1608Metric" V 6800 6100 50  0001 C CNN
F 3 "" V 6800 6100 50  0001 C CNN
	1    6800 6100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6900 6100 7100 6100
Text Label 7100 5850 2    50   ~ 0
LPR
Text Label 7100 6100 2    50   ~ 0
LPH
$Comp
L kicad_symbol_general:R_Small_US R44
U 1 1 64EF73FE
P 6500 6350
F 0 "R44" V 6635 6415 50  0000 R CNN
F 1 "10k" V 6570 6410 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 6500 6350 50  0001 C CNN
F 3 "" H 6500 6350 50  0001 C CNN
	1    6500 6350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6400 6350 6350 6350
Wire Wire Line
	6350 6350 6350 6100
Connection ~ 6350 6100
$Comp
L kicad_symbol_general:LED_Small D44
U 1 1 64F2302F
P 6800 6350
F 0 "D44" H 6800 6200 50  0000 C CNN
F 1 "RED" H 6800 6275 50  0000 C CNN
F 2 "kicad_footprint_general:LED_0603_1608Metric" V 6800 6350 50  0001 C CNN
F 3 "" V 6800 6350 50  0001 C CNN
	1    6800 6350
	-1   0    0    1   
$EndComp
Wire Wire Line
	6600 6350 6700 6350
Wire Wire Line
	6900 6350 7100 6350
Text Label 7100 6350 2    50   ~ 0
LRN
$Comp
L kicad_symbol_general:LED_Small D41
U 1 1 64D23F46
P 6800 5600
F 0 "D41" H 6800 5450 50  0000 C CNN
F 1 "RED" H 6800 5525 50  0000 C CNN
F 2 "kicad_footprint_general:LED_0603_1608Metric" V 6800 5600 50  0001 C CNN
F 3 "" V 6800 5600 50  0001 C CNN
	1    6800 5600
	-1   0    0    1   
$EndComp
Text Label 4400 3050 3    50   ~ 0
LRN
Text Label 4300 3050 3    50   ~ 0
LPH
Text Label 4200 3050 3    50   ~ 0
LPR
Text Label 4100 3050 3    50   ~ 0
LPU
NoConn ~ 4000 3050
$Comp
L kicad_symbol_general:R_Small_US R13
U 1 1 651DD823
P 4150 5950
F 0 "R13" V 4220 6025 50  0000 R CNN
F 1 "10k" V 4075 6020 50  0000 R CNN
F 2 "kicad_footprint_general:R_0603_1608Metric" H 4150 5950 50  0001 C CNN
F 3 "" H 4150 5950 50  0001 C CNN
	1    4150 5950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 5950 4050 5950
Wire Wire Line
	4000 5500 4000 5950
Wire Wire Line
	4250 5950 4500 5950
Wire Wire Line
	4300 5750 4500 5750
Wire Wire Line
	4500 5725 4500 5750
Connection ~ 4500 5750
Wire Wire Line
	4500 5750 4750 5750
Wire Wire Line
	4500 5750 4500 5950
$Comp
L kicad_symbol_general:R_Small_US R33
U 1 1 65314F24
P 3005 1250
F 0 "R33" V 3145 1320 50  0000 R CNN
F 1 "0R" V 3080 1305 50  0000 R CNN
F 2 "kicad_footprint_general:R_0805_2012Metric" H 3005 1250 50  0001 C CNN
F 3 "" H 3005 1250 50  0001 C CNN
	1    3005 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3105 1250 3260 1250
$Comp
L power:PWR_FLAG #FLG0107
U 1 1 65316206
P 2850 1150
F 0 "#FLG0107" H 2850 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 2850 1323 50  0000 C CNN
F 2 "" H 2850 1150 50  0001 C CNN
F 3 "~" H 2850 1150 50  0001 C CNN
	1    2850 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 1150 2850 1250
Connection ~ 2850 1250
Wire Wire Line
	2850 1250 2905 1250
$Comp
L kicad_symbol_general:C_Small C39
U 1 1 6544D335
P 4650 1440
F 0 "C39" H 4655 1380 50  0000 L CNN
F 1 "22uF" H 4655 1515 50  0000 L CNN
F 2 "kicad_footprint_general:C_1206_3216Metric" H 4650 1440 50  0001 C CNN
F 3 "" H 4650 1440 50  0001 C CNN
	1    4650 1440
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 1340 4650 1250
Connection ~ 4650 1250
Wire Wire Line
	4650 1250 4750 1250
Wire Wire Line
	4650 1610 4200 1610
Wire Wire Line
	4650 1540 4650 1610
$Comp
L Connector:TestPoint TP10
U 1 1 65611167
P 1350 3550
F 0 "TP10" V 1280 3675 50  0000 C CNN
F 1 "NRST" V 1410 3675 50  0000 C CNN
F 2 "kicad_footprint_general:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 1550 3550 50  0001 C CNN
F 3 "~" H 1550 3550 50  0001 C CNN
	1    1350 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1350 3550 1550 3550
$Comp
L Connector:TestPoint TP12
U 1 1 656A01F7
P 3500 2850
F 0 "TP12" H 3510 3055 50  0000 C CNN
F 1 "BOOT" H 3510 3125 50  0000 C CNN
F 2 "kicad_footprint_general:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 3700 2850 50  0001 C CNN
F 3 "~" H 3700 2850 50  0001 C CNN
	1    3500 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2900 3500 2850
Connection ~ 3500 2900
Wire Wire Line
	2950 2900 3100 2900
Wire Wire Line
	3100 2730 2950 2730
Text Label 2950 2730 0    50   ~ 0
VCC
$Comp
L Connector:TestPoint TP11
U 1 1 65671A5D
P 1350 3850
F 0 "TP11" V 1280 3970 50  0000 C CNN
F 1 "GND" V 1410 3975 50  0000 C CNN
F 2 "kicad_footprint_general:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 1550 3850 50  0001 C CNN
F 3 "~" H 1550 3850 50  0001 C CNN
	1    1350 3850
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP13
U 1 1 6572BAC5
P 3100 2730
F 0 "TP13" V 3015 2855 50  0000 C CNN
F 1 "VCC" V 2930 2845 50  0000 C CNN
F 2 "kicad_footprint_general:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 3300 2730 50  0001 C CNN
F 3 "~" H 3300 2730 50  0001 C CNN
	1    3100 2730
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 3850 1550 3850
Connection ~ 1550 3850
Wire Wire Line
	1550 3850 1550 3900
Wire Wire Line
	1550 3195 1550 3300
$EndSCHEMATC
