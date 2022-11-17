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
$Comp
L kicad_symbol_general:MS1192 U?
U 1 1 636A0D9E
P 2395 3450
F 0 "U?" H 2395 4117 50  0000 C CNN
F 1 "MS1192" H 2395 4026 50  0000 C CNN
F 2 "" H 2395 3450 50  0001 C CNN
F 3 "" H 2395 3450 50  0001 C CNN
	1    2395 3450
	-1   0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:MS1192 U?
U 1 1 636A12F0
P 9035 3450
F 0 "U?" H 9035 4117 50  0000 C CNN
F 1 "MS1192" H 9035 4026 50  0000 C CNN
F 2 "" H 9035 3450 50  0001 C CNN
F 3 "" H 9035 3450 50  0001 C CNN
	1    9035 3450
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:Q_NMOS_GSD Q?
U 1 1 636A3208
P 4900 3050
F 0 "Q?" H 4755 3140 50  0000 L CNN
F 1 "2N7002" H 4675 2885 50  0000 L CNN
F 2 "" H 5100 3150 50  0001 C CNN
F 3 "" H 4900 3050 50  0001 C CNN
	1    4900 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2795 3050 3135 3050
$Comp
L kicad_symbol_general:R_Small_US R?
U 1 1 636A89F8
P 5000 2655
F 0 "R?" H 5068 2701 50  0000 L CNN
F 1 "R_Small_US" H 5068 2610 50  0000 L CNN
F 2 "" H 5000 2655 50  0001 C CNN
F 3 "" H 5000 2655 50  0001 C CNN
	1    5000 2655
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 636A93DB
P 5000 2445
F 0 "#PWR?" H 5000 2295 50  0001 C CNN
F 1 "VCC" H 5017 2618 50  0000 C CNN
F 2 "" H 5000 2445 50  0001 C CNN
F 3 "" H 5000 2445 50  0001 C CNN
	1    5000 2445
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2555 5000 2445
$Comp
L power:GND #PWR?
U 1 1 636A9ADD
P 5000 3280
F 0 "#PWR?" H 5000 3030 50  0001 C CNN
F 1 "GND" H 5000 3145 50  0000 C CNN
F 2 "" H 5000 3280 50  0001 C CNN
F 3 "" H 5000 3280 50  0001 C CNN
	1    5000 3280
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3250 5000 3280
Wire Wire Line
	8635 3050 8305 3050
$Comp
L kicad_symbol_general:Q_NMOS_GSD Q?
U 1 1 636AD2DD
P 6600 3050
F 0 "Q?" H 6475 3210 50  0000 L CNN
F 1 "2N7002" H 6300 2895 50  0000 L CNN
F 2 "" H 6800 3150 50  0001 C CNN
F 3 "" H 6600 3050 50  0001 C CNN
	1    6600 3050
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 636AF415
P 6500 3315
F 0 "#PWR?" H 6500 3065 50  0001 C CNN
F 1 "GND" H 6500 3175 50  0000 C CNN
F 2 "" H 6500 3315 50  0001 C CNN
F 3 "" H 6500 3315 50  0001 C CNN
	1    6500 3315
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3250 6500 3315
$Comp
L kicad_symbol_general:R_Small_US R?
U 1 1 636AFF51
P 6500 2645
F 0 "R?" H 6568 2691 50  0000 L CNN
F 1 "R_Small_US" H 6568 2600 50  0000 L CNN
F 2 "" H 6500 2645 50  0001 C CNN
F 3 "" H 6500 2645 50  0001 C CNN
	1    6500 2645
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 636B0794
P 6500 2445
F 0 "#PWR?" H 6500 2295 50  0001 C CNN
F 1 "VCC" H 6517 2618 50  0000 C CNN
F 2 "" H 6500 2445 50  0001 C CNN
F 3 "" H 6500 2445 50  0001 C CNN
	1    6500 2445
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2545 6500 2445
$Comp
L kicad_symbol_general:Q_NMOS_GSD Q?
U 1 1 636B1F83
P 8105 3050
F 0 "Q?" H 8310 3060 50  0000 L CNN
F 1 "2N7002" H 8215 2915 50  0000 L CNN
F 2 "" H 8305 3150 50  0001 C CNN
F 3 "" H 8105 3050 50  0001 C CNN
	1    8105 3050
	-1   0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R?
U 1 1 636B4483
P 8005 2650
F 0 "R?" H 8073 2696 50  0000 L CNN
F 1 "R_Small_US" H 8073 2605 50  0000 L CNN
F 2 "" H 8005 2650 50  0001 C CNN
F 3 "" H 8005 2650 50  0001 C CNN
	1    8005 2650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 636B55BF
P 8005 2485
F 0 "#PWR?" H 8005 2335 50  0001 C CNN
F 1 "VCC" H 8022 2658 50  0000 C CNN
F 2 "" H 8005 2485 50  0001 C CNN
F 3 "" H 8005 2485 50  0001 C CNN
	1    8005 2485
	1    0    0    -1  
$EndComp
Wire Wire Line
	8005 2550 8005 2485
$Comp
L power:GND #PWR?
U 1 1 636B7677
P 8005 3315
F 0 "#PWR?" H 8005 3065 50  0001 C CNN
F 1 "GND" H 8005 3175 50  0000 C CNN
F 2 "" H 8005 3315 50  0001 C CNN
F 3 "" H 8005 3315 50  0001 C CNN
	1    8005 3315
	1    0    0    -1  
$EndComp
Wire Wire Line
	8005 3250 8005 3315
$Comp
L kicad_symbol_general:Q_NMOS_GSD Q?
U 1 1 636BA176
P 3335 3050
F 0 "Q?" H 3541 3096 50  0000 L CNN
F 1 "2N7002" H 3495 2945 50  0000 L CNN
F 2 "" H 3535 3150 50  0001 C CNN
F 3 "" H 3335 3050 50  0001 C CNN
	1    3335 3050
	1    0    0    -1  
$EndComp
$Comp
L kicad_symbol_general:R_Small_US R?
U 1 1 636BCDE8
P 3435 2540
F 0 "R?" H 3503 2586 50  0000 L CNN
F 1 "R_Small_US" H 3503 2495 50  0000 L CNN
F 2 "" H 3435 2540 50  0001 C CNN
F 3 "" H 3435 2540 50  0001 C CNN
	1    3435 2540
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 636BCDEE
P 3435 2345
F 0 "#PWR?" H 3435 2195 50  0001 C CNN
F 1 "VCC" H 3452 2518 50  0000 C CNN
F 2 "" H 3435 2345 50  0001 C CNN
F 3 "" H 3435 2345 50  0001 C CNN
	1    3435 2345
	1    0    0    -1  
$EndComp
Wire Wire Line
	3435 2440 3435 2345
$Comp
L power:GND #PWR?
U 1 1 636BFED4
P 3435 3305
F 0 "#PWR?" H 3435 3055 50  0001 C CNN
F 1 "GND" H 3435 3170 50  0000 C CNN
F 2 "" H 3435 3305 50  0001 C CNN
F 3 "" H 3435 3305 50  0001 C CNN
	1    3435 3305
	1    0    0    -1  
$EndComp
Wire Wire Line
	3435 3250 3435 3305
Wire Wire Line
	5950 3550 7560 3550
Wire Wire Line
	2795 3550 3950 3550
$Comp
L 74xGxx:74AUC2G08 U?
U 1 1 636FCA1B
P 4315 3050
F 0 "U?" H 4290 2783 50  0000 C CNN
F 1 "74AUC2G08" H 4290 2874 50  0000 C CNN
F 2 "" H 4315 3050 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 4315 3050 50  0001 C CNN
	1    4315 3050
	1    0    0    1   
$EndComp
Wire Wire Line
	4015 3100 3950 3100
Wire Wire Line
	3950 3100 3950 3550
Connection ~ 3950 3550
Wire Wire Line
	3950 3550 5550 3550
$Comp
L 74xGxx:74AUC2G08 U?
U 2 1 6370D646
P 7165 3050
F 0 "U?" H 7140 2783 50  0000 C CNN
F 1 "74AUC2G08" H 7140 2874 50  0000 C CNN
F 2 "" H 7165 3050 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 7165 3050 50  0001 C CNN
	2    7165 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	8005 2750 8005 2805
Connection ~ 8005 2805
Wire Wire Line
	8005 2805 8005 2850
Wire Wire Line
	5000 2755 5000 2800
Wire Wire Line
	6500 2745 6500 2800
Wire Wire Line
	3435 2850 3435 2800
Wire Wire Line
	4565 3050 4700 3050
Wire Wire Line
	4015 3000 3950 3000
Wire Wire Line
	3950 3000 3950 2800
Connection ~ 3435 2800
Wire Wire Line
	3435 2800 3435 2640
Wire Wire Line
	5550 3550 6500 2800
Connection ~ 6500 2800
Wire Wire Line
	6500 2800 6500 2850
Wire Wire Line
	5950 3550 5000 2800
Connection ~ 5000 2800
Wire Wire Line
	5000 2800 5000 2850
Wire Wire Line
	6800 3050 6915 3050
Wire Wire Line
	7465 3100 7560 3100
Wire Wire Line
	7560 3100 7560 3550
Wire Wire Line
	7465 3000 7560 3000
Wire Wire Line
	7560 3000 7560 2805
Wire Wire Line
	7560 2805 8005 2805
Connection ~ 7560 3550
Wire Wire Line
	7560 3550 8635 3550
Wire Wire Line
	3950 2800 3435 2800
$EndSCHEMATC
