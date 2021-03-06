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
L Regulator_Linear:LM7805_TO220 U1
U 1 1 5F9EE97F
P 3450 2350
F 0 "U1" H 3450 2350 50  0000 C CNN
F 1 "LM7805_TO220" H 3450 2501 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3450 2575 50  0001 C CIN
F 3 "https://www.onsemi.cn/PowerSolutions/document/MC7800-D.PDF" H 3450 2300 50  0001 C CNN
	1    3450 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5F9EFC80
P 3000 2700
F 0 "C1" H 3118 2746 50  0000 L CNN
F 1 "33uF" H 3118 2655 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 3038 2550 50  0001 C CNN
F 3 "~" H 3000 2700 50  0001 C CNN
	1    3000 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5F9F0161
P 3900 2700
F 0 "C2" H 4018 2746 50  0000 L CNN
F 1 "10uF" H 4018 2655 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 3938 2550 50  0001 C CNN
F 3 "~" H 3900 2700 50  0001 C CNN
	1    3900 2700
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4001 D1
U 1 1 5F9F34B7
P 3450 2050
F 0 "D1" H 3450 2267 50  0000 C CNN
F 1 "1N4001" H 3450 2176 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 3450 1875 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 3450 2050 50  0001 C CNN
	1    3450 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5FA083F2
P 4250 2600
F 0 "D2" V 4289 2482 50  0000 R CNN
F 1 "LED" V 4198 2482 50  0000 R CNN
F 2 "" H 4250 2600 50  0001 C CNN
F 3 "~" H 4250 2600 50  0001 C CNN
	1    4250 2600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5FA0B024
P 4250 3000
F 0 "R1" H 4320 3046 50  0000 L CNN
F 1 "1K" H 4320 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4180 3000 50  0001 C CNN
F 3 "~" H 4250 3000 50  0001 C CNN
	1    4250 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5FA11076
P 5550 1750
F 0 "J1" H 5630 1696 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 5630 1651 50  0001 L CNN
F 2 "" H 5550 1750 50  0001 C CNN
F 3 "~" H 5550 1750 50  0001 C CNN
	1    5550 1750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPST_x2 SW1
U 1 1 5FA12DAF
P 5000 1750
F 0 "SW1" H 5000 1893 50  0000 C CNN
F 1 "SW_DPST_x2" H 5000 1894 50  0001 C CNN
F 2 "Button_Switch_THT:Nidec_Copal_SH-7010C" H 5000 1750 50  0001 C CNN
F 3 "~" H 5000 1750 50  0001 C CNN
	1    5000 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1850 5250 1850
Wire Wire Line
	5250 1850 5250 2250
$Comp
L power:Earth #PWR02
U 1 1 5FA1D592
P 5250 2350
F 0 "#PWR02" H 5250 2100 50  0001 C CNN
F 1 "Earth" H 5250 2200 50  0001 C CNN
F 2 "" H 5250 2350 50  0001 C CNN
F 3 "~" H 5250 2350 50  0001 C CNN
	1    5250 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1750 5200 1750
Wire Wire Line
	3000 2550 3000 2350
Wire Wire Line
	3000 2050 3300 2050
Wire Wire Line
	3000 2850 3000 2900
Wire Wire Line
	3900 2900 3900 2850
Wire Wire Line
	3000 2900 3450 2900
Connection ~ 3450 2900
Wire Wire Line
	3450 2900 3900 2900
Wire Wire Line
	3600 2050 3900 2050
Wire Wire Line
	3900 2050 3900 2350
Wire Wire Line
	3450 2650 3450 2900
Wire Wire Line
	3150 2350 3000 2350
Connection ~ 3000 2350
Wire Wire Line
	3000 2350 3000 2050
Wire Wire Line
	3750 2350 3900 2350
Connection ~ 3900 2350
Wire Wire Line
	3900 2350 3900 2550
Wire Wire Line
	3900 2350 4250 2350
Wire Wire Line
	4250 2350 4250 2450
Wire Wire Line
	4250 2750 4250 2850
Wire Wire Line
	3450 2900 3450 3250
Wire Wire Line
	3450 3250 3850 3250
Wire Wire Line
	4250 3250 4250 3150
$Comp
L power:Earth #PWR01
U 1 1 5FA24526
P 3850 3350
F 0 "#PWR01" H 3850 3100 50  0001 C CNN
F 1 "Earth" H 3850 3200 50  0001 C CNN
F 2 "" H 3850 3350 50  0001 C CNN
F 3 "~" H 3850 3350 50  0001 C CNN
	1    3850 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3350 3850 3250
Connection ~ 3850 3250
Wire Wire Line
	3850 3250 4250 3250
Text GLabel 2850 2350 0    50   Input ~ 0
INPUT
Wire Wire Line
	2850 2350 2900 2350
Text GLabel 4400 2350 2    50   Output ~ 0
OUTPUT+5V
Connection ~ 4250 2350
Text GLabel 4700 1750 0    50   Input ~ 0
INPUT
Wire Wire Line
	4700 1750 4800 1750
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5F9F8E5F
P 5350 2250
F 0 "#FLG0101" H 5350 2325 50  0001 C CNN
F 1 "PWR_FLAG" V 5350 2378 50  0000 L CNN
F 2 "" H 5350 2250 50  0001 C CNN
F 3 "~" H 5350 2250 50  0001 C CNN
	1    5350 2250
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5F9F9CB4
P 2900 2250
F 0 "#FLG0102" H 2900 2325 50  0001 C CNN
F 1 "PWR_FLAG" H 2750 2400 50  0000 C CNN
F 2 "" H 2900 2250 50  0001 C CNN
F 3 "~" H 2900 2250 50  0001 C CNN
	1    2900 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2250 2900 2350
Connection ~ 2900 2350
Wire Wire Line
	2900 2350 3000 2350
Wire Wire Line
	5350 2250 5250 2250
Connection ~ 5250 2250
Wire Wire Line
	5250 2250 5250 2350
Wire Wire Line
	4250 2350 4400 2350
Wire Wire Line
	4400 3250 4250 3250
Connection ~ 4250 3250
$Comp
L Connector:Conn_01x05_Female J2
U 1 1 5FA04E51
P 5250 2950
F 0 "J2" H 5142 3243 50  0000 C CNN
F 1 "Conn_01x05_Female" H 5278 2885 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 5250 2950 50  0001 C CNN
F 3 "~" H 5250 2950 50  0001 C CNN
	1    5250 2950
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 5FA074C5
P 6200 2950
F 0 "J3" H 6092 3243 50  0000 C CNN
F 1 "Conn_01x05_Female" H 6228 2885 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6200 2950 50  0001 C CNN
F 3 "~" H 6200 2950 50  0001 C CNN
	1    6200 2950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5450 2750 5450 2850
Connection ~ 5450 2850
Wire Wire Line
	5450 2850 5450 2950
Connection ~ 5450 2950
Wire Wire Line
	5450 2950 5450 3050
Connection ~ 5450 3050
Wire Wire Line
	5450 3050 5450 3150
Wire Wire Line
	5450 2950 5600 2950
Wire Wire Line
	6400 2750 6400 2850
Connection ~ 6400 2850
Wire Wire Line
	6400 2850 6400 2950
Connection ~ 6400 2950
Wire Wire Line
	6400 2950 6400 3050
Connection ~ 6400 3050
Wire Wire Line
	6400 3050 6400 3150
Text GLabel 4400 3250 2    50   Output ~ 0
OUTPUT_GND
Text GLabel 5600 2950 2    50   Output ~ 0
OUTPUT+5V
Text GLabel 6550 2950 2    50   Output ~ 0
OUTPUT_GND
Wire Wire Line
	6550 2950 6400 2950
$EndSCHEMATC
