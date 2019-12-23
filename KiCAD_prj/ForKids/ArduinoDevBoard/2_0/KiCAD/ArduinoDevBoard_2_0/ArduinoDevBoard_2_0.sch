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
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5DFCBFEA
P 6000 3450
F 0 "A1" H 5900 2450 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 6000 3450 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 6000 3450 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 6000 3450 50  0001 C CNN
	1    6000 3450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q1
U 1 1 5DFCD34A
P 1850 1300
F 0 "Q1" H 2040 1346 50  0000 L CNN
F 1 "PN2222A" H 2040 1255 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 2050 1225 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/PN/PN2222A.pdf" H 1850 1300 50  0001 L CNN
	1    1850 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5DFCDAF5
P 1300 1300
F 0 "R1" V 1093 1300 50  0000 C CNN
F 1 "100" V 1184 1300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1230 1300 50  0001 C CNN
F 3 "~" H 1300 1300 50  0001 C CNN
	1    1300 1300
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5DFCDE6D
P 1550 1650
F 0 "R2" H 1480 1604 50  0000 R CNN
F 1 "1K" H 1480 1695 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1480 1650 50  0001 C CNN
F 3 "~" H 1550 1650 50  0001 C CNN
	1    1550 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 1300 1550 1300
Wire Wire Line
	1550 1500 1550 1300
Connection ~ 1550 1300
Wire Wire Line
	1550 1300 1650 1300
Wire Wire Line
	1550 1800 1550 1900
Wire Wire Line
	1550 1900 1950 1900
Wire Wire Line
	1950 1900 1950 1500
$Comp
L power:Earth #PWR08
U 1 1 5DFD0E34
P 1950 2000
F 0 "#PWR08" H 1950 1750 50  0001 C CNN
F 1 "Earth" H 1950 1850 50  0001 C CNN
F 2 "" H 1950 2000 50  0001 C CNN
F 3 "~" H 1950 2000 50  0001 C CNN
	1    1950 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2000 1950 1900
Connection ~ 1950 1900
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5DFD5251
P 2250 900
F 0 "J4" H 2330 892 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2330 801 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 2250 900 50  0001 C CNN
F 3 "~" H 2250 900 50  0001 C CNN
	1    2250 900 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5DFD83FF
P 2400 3800
F 0 "J2" H 2428 3776 50  0000 L CNN
F 1 "Conn_01x04_Female" H 2428 3685 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2400 3800 50  0001 C CNN
F 3 "~" H 2400 3800 50  0001 C CNN
	1    2400 3800
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR07
U 1 1 5DFDB32E
P 1950 800
F 0 "#PWR07" H 1950 650 50  0001 C CNN
F 1 "+5V" H 1965 973 50  0000 C CNN
F 2 "" H 1950 800 50  0001 C CNN
F 3 "" H 1950 800 50  0001 C CNN
	1    1950 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 800  1950 900 
Wire Wire Line
	1950 1100 1950 1000
Text GLabel 1050 1300 0    50   BiDi ~ 0
D3
Wire Wire Line
	1150 1300 1050 1300
$Comp
L power:Earth #PWR014
U 1 1 5DFD7EB0
P 6100 4550
F 0 "#PWR014" H 6100 4300 50  0001 C CNN
F 1 "Earth" H 6100 4400 50  0001 C CNN
F 2 "" H 6100 4550 50  0001 C CNN
F 3 "~" H 6100 4550 50  0001 C CNN
	1    6100 4550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR015
U 1 1 5DFD9772
P 6200 2350
F 0 "#PWR015" H 6200 2200 50  0001 C CNN
F 1 "+5V" H 6215 2523 50  0000 C CNN
F 2 "" H 6200 2350 50  0001 C CNN
F 3 "" H 6200 2350 50  0001 C CNN
	1    6200 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2350 6200 2450
Text GLabel 5400 3050 0    50   BiDi ~ 0
D2
Wire Wire Line
	5500 3050 5400 3050
$Comp
L Connector:Conn_01x03_Female J9
U 1 1 5DFDCB65
P 8200 1400
F 0 "J9" H 8228 1426 50  0000 L CNN
F 1 "Conn_01x03_Female" H 8228 1335 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8200 1400 50  0001 C CNN
F 3 "~" H 8200 1400 50  0001 C CNN
	1    8200 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5DFDE4CA
P 7850 1750
F 0 "R8" H 7920 1796 50  0000 L CNN
F 1 "4.7K" H 7920 1705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 7780 1750 50  0001 C CNN
F 3 "~" H 7850 1750 50  0001 C CNN
	1    7850 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1500 7850 1500
Wire Wire Line
	7850 1500 7850 1600
$Comp
L power:+5V #PWR019
U 1 1 5DFDF39A
P 7700 1500
F 0 "#PWR019" H 7700 1350 50  0001 C CNN
F 1 "+5V" V 7715 1628 50  0000 L CNN
F 2 "" H 7700 1500 50  0001 C CNN
F 3 "" H 7700 1500 50  0001 C CNN
	1    7700 1500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 1500 7850 1500
Connection ~ 7850 1500
Text GLabel 7750 1400 0    50   BiDi ~ 0
D2
Wire Wire Line
	8000 1400 7750 1400
$Comp
L power:Earth #PWR020
U 1 1 5DFE0064
P 7850 1300
F 0 "#PWR020" H 7850 1050 50  0001 C CNN
F 1 "Earth" H 7850 1150 50  0001 C CNN
F 2 "" H 7850 1300 50  0001 C CNN
F 3 "~" H 7850 1300 50  0001 C CNN
	1    7850 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 1300 7850 1300
$Comp
L Regulator_Linear:LM78M05_TO220 U1
U 1 1 5DFE3BB2
P 4200 1200
F 0 "U1" H 4200 1200 50  0000 C CNN
F 1 "LM78M05_TO220" H 4200 850 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 4200 1425 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM78M05.pdf" H 4200 1150 50  0001 C CNN
	1    4200 1200
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR010
U 1 1 5DFE5516
P 4200 1750
F 0 "#PWR010" H 4200 1500 50  0001 C CNN
F 1 "Earth" H 4200 1600 50  0001 C CNN
F 2 "" H 4200 1750 50  0001 C CNN
F 3 "~" H 4200 1750 50  0001 C CNN
	1    4200 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J6
U 1 1 5DFE6F52
P 4650 1000
F 0 "J6" V 4542 812 50  0000 R CNN
F 1 "Conn_01x02_Female" V 4497 812 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 1000 50  0001 C CNN
F 3 "~" H 4650 1000 50  0001 C CNN
	1    4650 1000
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J5
U 1 1 5DFE96A4
P 3650 1000
F 0 "J5" V 3550 1150 50  0000 R CNN
F 1 "Conn_01x02_Female" V 3497 812 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3650 1000 50  0001 C CNN
F 3 "~" H 3650 1000 50  0001 C CNN
	1    3650 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 1200 4550 1200
$Comp
L power:+5V #PWR012
U 1 1 5DFEF4EB
P 4950 1200
F 0 "#PWR012" H 4950 1050 50  0001 C CNN
F 1 "+5V" V 4965 1328 50  0000 L CNN
F 2 "" H 4950 1200 50  0001 C CNN
F 3 "" H 4950 1200 50  0001 C CNN
	1    4950 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 1200 4750 1200
Wire Wire Line
	3650 1200 3450 1200
Wire Wire Line
	2050 900  1950 900 
Wire Wire Line
	2050 1000 1950 1000
Text GLabel 5400 4150 0    50   BiDi ~ 0
D13
$Comp
L Switch:SW_SPST SW4
U 1 1 5E0087E0
P 10000 4350
F 0 "SW4" H 10000 4493 50  0000 C CNN
F 1 "SW_SPST" H 10000 4494 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 10000 4350 50  0001 C CNN
F 3 "~" H 10000 4350 50  0001 C CNN
	1    10000 4350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW5
U 1 1 5E008C1E
P 10000 4700
F 0 "SW5" H 10000 4843 50  0000 C CNN
F 1 "SW_SPST" H 10000 4844 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 10000 4700 50  0001 C CNN
F 3 "~" H 10000 4700 50  0001 C CNN
	1    10000 4700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW6
U 1 1 5E00916E
P 10000 5050
F 0 "SW6" H 10000 5193 50  0000 C CNN
F 1 "SW_SPST" H 10000 5194 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 10000 5050 50  0001 C CNN
F 3 "~" H 10000 5050 50  0001 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 4350 10400 4350
Wire Wire Line
	10400 4350 10400 4700
Wire Wire Line
	10400 5050 10200 5050
Wire Wire Line
	10200 4700 10400 4700
Connection ~ 10400 4700
Wire Wire Line
	10400 4700 10400 5050
$Comp
L power:+5V #PWR026
U 1 1 5E00A71C
P 10400 4150
F 0 "#PWR026" H 10400 4000 50  0001 C CNN
F 1 "+5V" H 10415 4323 50  0000 C CNN
F 2 "" H 10400 4150 50  0001 C CNN
F 3 "" H 10400 4150 50  0001 C CNN
	1    10400 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 4150 10400 4350
Connection ~ 10400 4350
Text GLabel 9050 4350 0    50   BiDi ~ 0
D13
Text GLabel 9050 4700 0    50   BiDi ~ 0
A2
Text GLabel 9050 5050 0    50   BiDi ~ 0
A3
$Comp
L Device:R R11
U 1 1 5E00F777
P 9750 5450
F 0 "R11" H 9820 5496 50  0000 L CNN
F 1 "10K" H 9820 5405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 9680 5450 50  0001 C CNN
F 3 "~" H 9750 5450 50  0001 C CNN
	1    9750 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5E00FB9A
P 9500 5450
F 0 "R10" H 9570 5496 50  0000 L CNN
F 1 "10K" H 9570 5405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 9430 5450 50  0001 C CNN
F 3 "~" H 9500 5450 50  0001 C CNN
	1    9500 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 5E00FEED
P 9250 5450
F 0 "R9" H 9320 5496 50  0000 L CNN
F 1 "10K" H 9320 5405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 9180 5450 50  0001 C CNN
F 3 "~" H 9250 5450 50  0001 C CNN
	1    9250 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 5050 9750 5050
Wire Wire Line
	9050 4700 9500 4700
Wire Wire Line
	9050 4350 9250 4350
Wire Wire Line
	9250 5300 9250 4350
Connection ~ 9250 4350
Wire Wire Line
	9250 4350 9800 4350
Wire Wire Line
	9500 5300 9500 4700
Connection ~ 9500 4700
Wire Wire Line
	9500 4700 9800 4700
Wire Wire Line
	9750 5300 9750 5050
Connection ~ 9750 5050
Wire Wire Line
	9750 5050 9800 5050
Wire Wire Line
	9250 5600 9250 5750
Wire Wire Line
	9250 5750 9500 5750
Wire Wire Line
	9750 5750 9750 5600
Wire Wire Line
	9500 5600 9500 5750
Connection ~ 9500 5750
Wire Wire Line
	9500 5750 9750 5750
$Comp
L power:Earth #PWR023
U 1 1 5E019400
P 9500 5900
F 0 "#PWR023" H 9500 5650 50  0001 C CNN
F 1 "Earth" H 9500 5750 50  0001 C CNN
F 2 "" H 9500 5900 50  0001 C CNN
F 3 "~" H 9500 5900 50  0001 C CNN
	1    9500 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 5900 9500 5750
Text GLabel 6600 3650 2    50   BiDi ~ 0
A2
Text GLabel 6600 3750 2    50   BiDi ~ 0
A3
Wire Wire Line
	6600 3750 6500 3750
Wire Wire Line
	6600 3650 6500 3650
$Comp
L power:Earth #PWR021
U 1 1 5E01E177
P 7850 2000
F 0 "#PWR021" H 7850 1750 50  0001 C CNN
F 1 "Earth" H 7850 1850 50  0001 C CNN
F 2 "" H 7850 2000 50  0001 C CNN
F 3 "~" H 7850 2000 50  0001 C CNN
	1    7850 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 2000 7850 1900
$Comp
L Device:LED D1
U 1 1 5E023966
P 5550 5200
F 0 "D1" H 5543 4945 50  0000 C CNN
F 1 "LED" H 5543 5036 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5550 5200 50  0001 C CNN
F 3 "~" H 5550 5200 50  0001 C CNN
	1    5550 5200
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5E024026
P 5550 5550
F 0 "D2" H 5543 5295 50  0000 C CNN
F 1 "LED" H 5543 5386 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5550 5550 50  0001 C CNN
F 3 "~" H 5550 5550 50  0001 C CNN
	1    5550 5550
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 5E0244C6
P 5550 5900
F 0 "D3" H 5543 5645 50  0000 C CNN
F 1 "LED" H 5543 5736 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5550 5900 50  0001 C CNN
F 3 "~" H 5550 5900 50  0001 C CNN
	1    5550 5900
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D4
U 1 1 5E024A28
P 5550 6250
F 0 "D4" H 5543 5995 50  0000 C CNN
F 1 "LED" H 5543 6086 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5550 6250 50  0001 C CNN
F 3 "~" H 5550 6250 50  0001 C CNN
	1    5550 6250
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D5
U 1 1 5E024F12
P 5550 6600
F 0 "D5" H 5543 6345 50  0000 C CNN
F 1 "LED" H 5543 6436 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5550 6600 50  0001 C CNN
F 3 "~" H 5550 6600 50  0001 C CNN
	1    5550 6600
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 5E02546C
P 6100 5550
F 0 "SW1" H 6100 5693 50  0000 C CNN
F 1 "SW_SPST" H 6100 5694 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6100 5550 50  0001 C CNN
F 3 "~" H 6100 5550 50  0001 C CNN
	1    6100 5550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW2
U 1 1 5E025A87
P 6100 5900
F 0 "SW2" H 6100 6043 50  0000 C CNN
F 1 "SW_SPST" H 6100 6044 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6100 5900 50  0001 C CNN
F 3 "~" H 6100 5900 50  0001 C CNN
	1    6100 5900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 5E025E64
P 6100 6250
F 0 "SW3" H 6100 6393 50  0000 C CNN
F 1 "SW_SPST" H 6100 6394 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6100 6250 50  0001 C CNN
F 3 "~" H 6100 6250 50  0001 C CNN
	1    6100 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5200 6500 5200
Wire Wire Line
	6500 5200 6500 5550
Wire Wire Line
	6500 6600 5700 6600
Wire Wire Line
	6300 5550 6500 5550
Connection ~ 6500 5550
Wire Wire Line
	6500 5550 6500 5900
Wire Wire Line
	6300 5900 6500 5900
Connection ~ 6500 5900
Wire Wire Line
	6500 5900 6500 6250
Wire Wire Line
	6300 6250 6500 6250
Connection ~ 6500 6250
Wire Wire Line
	6500 6250 6500 6600
$Comp
L power:Earth #PWR018
U 1 1 5E02A299
P 6500 6750
F 0 "#PWR018" H 6500 6500 50  0001 C CNN
F 1 "Earth" H 6500 6600 50  0001 C CNN
F 2 "" H 6500 6750 50  0001 C CNN
F 3 "~" H 6500 6750 50  0001 C CNN
	1    6500 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 6750 6500 6600
Connection ~ 6500 6600
Wire Wire Line
	5900 5550 5700 5550
Wire Wire Line
	5900 5900 5700 5900
Wire Wire Line
	5900 6250 5700 6250
$Comp
L Device:R R3
U 1 1 5E02FA65
P 5000 5200
F 0 "R3" V 4793 5200 50  0000 C CNN
F 1 "100" V 4884 5200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4930 5200 50  0001 C CNN
F 3 "~" H 5000 5200 50  0001 C CNN
	1    5000 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E0309A4
P 5000 5550
F 0 "R4" V 4793 5550 50  0000 C CNN
F 1 "100" V 4884 5550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4930 5550 50  0001 C CNN
F 3 "~" H 5000 5550 50  0001 C CNN
	1    5000 5550
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5E030E0A
P 5000 5900
F 0 "R5" V 4793 5900 50  0000 C CNN
F 1 "100" V 4884 5900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4930 5900 50  0001 C CNN
F 3 "~" H 5000 5900 50  0001 C CNN
	1    5000 5900
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5E031279
P 5000 6250
F 0 "R6" V 4793 6250 50  0000 C CNN
F 1 "100" V 4884 6250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4930 6250 50  0001 C CNN
F 3 "~" H 5000 6250 50  0001 C CNN
	1    5000 6250
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5E0319D2
P 5000 6600
F 0 "R7" V 4793 6600 50  0000 C CNN
F 1 "100" V 4884 6600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4930 6600 50  0001 C CNN
F 3 "~" H 5000 6600 50  0001 C CNN
	1    5000 6600
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Female J7
U 1 1 5E036B9A
P 5650 6950
F 0 "J7" H 5678 6926 50  0000 L CNN
F 1 "Conn_01x04_Female" H 5678 6835 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5650 6950 50  0001 C CNN
F 3 "~" H 5650 6950 50  0001 C CNN
	1    5650 6950
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR011
U 1 1 5E03FD36
P 5150 7300
F 0 "#PWR011" H 5150 7050 50  0001 C CNN
F 1 "Earth" H 5150 7150 50  0001 C CNN
F 2 "" H 5150 7300 50  0001 C CNN
F 3 "~" H 5150 7300 50  0001 C CNN
	1    5150 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 7050 5150 7050
Wire Wire Line
	5150 7050 5150 7300
Wire Wire Line
	5450 7150 5350 7150
Wire Wire Line
	5450 6950 5300 6950
Wire Wire Line
	5450 6850 5250 6850
Wire Wire Line
	5400 5200 5150 5200
Text GLabel 4700 5200 0    50   BiDi ~ 0
D8
Wire Wire Line
	4850 5200 4700 5200
Wire Wire Line
	5500 4150 5400 4150
Text GLabel 5400 3650 0    50   BiDi ~ 0
D8
Wire Wire Line
	5500 3650 5400 3650
Text GLabel 4700 5550 0    50   BiDi ~ 0
D9
Text GLabel 5400 3750 0    50   BiDi ~ 0
D9
Wire Wire Line
	5400 3750 5500 3750
Wire Wire Line
	4850 5550 4700 5550
Text GLabel 4700 5900 0    50   BiDi ~ 0
D10
Wire Wire Line
	4850 5900 4700 5900
Text GLabel 5400 3850 0    50   BiDi ~ 0
D10
Wire Wire Line
	5500 3850 5400 3850
Text GLabel 4700 6250 0    50   BiDi ~ 0
D11
Wire Wire Line
	4850 6250 4700 6250
Text GLabel 5400 3950 0    50   BiDi ~ 0
D11
Wire Wire Line
	5500 3950 5400 3950
Text GLabel 4700 6600 0    50   BiDi ~ 0
D12
Wire Wire Line
	4850 6600 4700 6600
Text GLabel 5400 4050 0    50   BiDi ~ 0
D12
Wire Wire Line
	5500 4050 5400 4050
Text Notes 1500 1000 0    50   ~ 0
Мотор
Text Notes 3900 750  0    50   ~ 0
Стабилизатор питания
Text Notes 7800 1150 0    50   ~ 0
Датчик t\nDS18B20
$Comp
L Connector:Screw_Terminal_01x02 J8
U 1 1 5DFE5568
P 6750 1050
F 0 "J8" H 6830 1042 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6830 951 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 6750 1050 50  0001 C CNN
F 3 "~" H 6750 1050 50  0001 C CNN
	1    6750 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:D D6
U 1 1 5DFE6204
P 6300 1050
F 0 "D6" H 6300 1266 50  0000 C CNN
F 1 "1N4007" H 6300 1175 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 6300 1050 50  0001 C CNN
F 3 "~" H 6300 1050 50  0001 C CNN
	1    6300 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1050 6450 1050
Wire Wire Line
	6550 1150 6450 1150
Wire Wire Line
	6450 1150 6450 1350
$Comp
L power:Earth #PWR017
U 1 1 5DFEC03F
P 6450 1350
F 0 "#PWR017" H 6450 1100 50  0001 C CNN
F 1 "Earth" H 6450 1200 50  0001 C CNN
F 2 "" H 6450 1350 50  0001 C CNN
F 3 "~" H 6450 1350 50  0001 C CNN
	1    6450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1050 6100 1050
Text Notes 5700 1250 0    50   ~ 0
Внешнее питание
$Comp
L power:+12V #PWR016
U 1 1 5DFF1EDA
P 6000 1050
F 0 "#PWR016" H 6000 900 50  0001 C CNN
F 1 "+12V" V 6015 1178 50  0000 L CNN
F 2 "" H 6000 1050 50  0001 C CNN
F 3 "" H 6000 1050 50  0001 C CNN
	1    6000 1050
	0    -1   -1   0   
$EndComp
Text Notes 9350 4200 0    50   ~ 0
Блок кнопок
Text Notes 5800 5100 0    50   ~ 0
Блок светодиодов
$Comp
L Connector:Conn_01x04_Female J10
U 1 1 5DFF84FC
P 9000 1000
F 0 "J10" H 9028 976 50  0000 L CNN
F 1 "Conn_01x04_Female" H 9028 885 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9000 1000 50  0001 C CNN
F 3 "~" H 9000 1000 50  0001 C CNN
	1    9000 1000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J11
U 1 1 5DFF91E9
P 9850 1000
F 0 "J11" H 9878 976 50  0000 L CNN
F 1 "Conn_01x04_Female" H 9878 885 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9850 1000 50  0001 C CNN
F 3 "~" H 9850 1000 50  0001 C CNN
	1    9850 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 900  8700 900 
Wire Wire Line
	8700 900  8700 1000
Wire Wire Line
	8700 1200 8800 1200
Wire Wire Line
	8800 1000 8700 1000
Connection ~ 8700 1000
Wire Wire Line
	8700 1000 8700 1100
Wire Wire Line
	8800 1100 8700 1100
Connection ~ 8700 1100
Wire Wire Line
	8700 1100 8700 1200
$Comp
L power:+5V #PWR022
U 1 1 5E003AC7
P 8700 800
F 0 "#PWR022" H 8700 650 50  0001 C CNN
F 1 "+5V" H 8750 850 50  0000 L CNN
F 2 "" H 8700 800 50  0001 C CNN
F 3 "" H 8700 800 50  0001 C CNN
	1    8700 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 800  8700 900 
Connection ~ 8700 900 
Wire Wire Line
	9650 900  9550 900 
Wire Wire Line
	9550 900  9550 1000
Wire Wire Line
	9550 1200 9650 1200
$Comp
L power:Earth #PWR024
U 1 1 5E00C477
P 9550 1300
F 0 "#PWR024" H 9550 1050 50  0001 C CNN
F 1 "Earth" H 9550 1150 50  0001 C CNN
F 2 "" H 9550 1300 50  0001 C CNN
F 3 "~" H 9550 1300 50  0001 C CNN
	1    9550 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 1300 9550 1200
Connection ~ 9550 1200
Wire Wire Line
	9650 1100 9550 1100
Connection ~ 9550 1100
Wire Wire Line
	9550 1100 9550 1200
Wire Wire Line
	9650 1000 9550 1000
Connection ~ 9550 1000
Wire Wire Line
	9550 1000 9550 1100
Text Notes 9100 750  0    50   ~ 0
Шины питания
Wire Wire Line
	5500 3250 5400 3250
$Comp
L Connector:Conn_01x02_Female J12
U 1 1 5E0214E6
P 9550 2000
F 0 "J12" H 9578 1930 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9578 1885 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9550 2000 50  0001 C CNN
F 3 "~" H 9550 2000 50  0001 C CNN
	1    9550 2000
	1    0    0    -1  
$EndComp
Text GLabel 9200 2000 0    50   Input ~ 0
D4
Wire Wire Line
	9350 2000 9200 2000
$Comp
L power:Earth #PWR025
U 1 1 5E0276EA
P 9350 2250
F 0 "#PWR025" H 9350 2000 50  0001 C CNN
F 1 "Earth" H 9350 2100 50  0001 C CNN
F 2 "" H 9350 2250 50  0001 C CNN
F 3 "~" H 9350 2250 50  0001 C CNN
	1    9350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 2250 9350 2100
Text Notes 9300 1900 0    50   ~ 0
Buzzer
Wire Wire Line
	6600 4150 6500 4150
$Comp
L Device:R_POT RV1
U 1 1 5E03950B
P 9900 2600
F 0 "RV1" H 9830 2646 50  0000 R CNN
F 1 "1K" H 9830 2555 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Runtron_RM-065_Vertical" H 9900 2600 50  0001 C CNN
F 3 "~" H 9900 2600 50  0001 C CNN
	1    9900 2600
	-1   0    0    -1  
$EndComp
Text GLabel 9600 2600 0    50   Input ~ 0
A7
Wire Wire Line
	9750 2600 9600 2600
$Comp
L power:Earth #PWR028
U 1 1 5E041882
P 9900 2900
F 0 "#PWR028" H 9900 2650 50  0001 C CNN
F 1 "Earth" H 9900 2750 50  0001 C CNN
F 2 "" H 9900 2900 50  0001 C CNN
F 3 "~" H 9900 2900 50  0001 C CNN
	1    9900 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 2900 9900 2750
$Comp
L power:+5V #PWR027
U 1 1 5E045F94
P 9900 2300
F 0 "#PWR027" H 9900 2150 50  0001 C CNN
F 1 "+5V" H 9915 2473 50  0000 C CNN
F 2 "" H 9900 2300 50  0001 C CNN
F 3 "" H 9900 2300 50  0001 C CNN
	1    9900 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 2300 9900 2450
Text Notes 2350 4300 0    50   ~ 0
MAX7219
Text Notes 2400 3600 0    50   ~ 0
SONAR HC-SR04
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5E05B2D9
P 2400 3100
F 0 "J1" H 2428 3076 50  0000 L CNN
F 1 "Conn_01x04_Female" H 2428 2985 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2400 3100 50  0001 C CNN
F 3 "~" H 2400 3100 50  0001 C CNN
	1    2400 3100
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 5E05BD68
P 2400 4650
F 0 "J3" H 2500 4650 50  0000 C CNN
F 1 "Conn_01x05_Female" H 2428 4585 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2400 4650 50  0001 C CNN
F 3 "~" H 2400 4650 50  0001 C CNN
	1    2400 4650
	-1   0    0    -1  
$EndComp
Text Notes 2350 2900 0    50   ~ 0
LCD1602
$Comp
L power:+5V #PWR05
U 1 1 5E06EB6A
P 2700 4450
F 0 "#PWR05" H 2700 4300 50  0001 C CNN
F 1 "+5V" V 2650 4400 50  0000 C CNN
F 2 "" H 2700 4450 50  0001 C CNN
F 3 "" H 2700 4450 50  0001 C CNN
	1    2700 4450
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR06
U 1 1 5E06F08F
P 3000 4600
F 0 "#PWR06" H 3000 4350 50  0001 C CNN
F 1 "Earth" H 3000 4450 50  0001 C CNN
F 2 "" H 3000 4600 50  0001 C CNN
F 3 "~" H 3000 4600 50  0001 C CNN
	1    3000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 4450 2600 4450
$Comp
L power:+5V #PWR03
U 1 1 5E078870
P 2700 3700
F 0 "#PWR03" H 2700 3550 50  0001 C CNN
F 1 "+5V" V 2650 3650 50  0000 C CNN
F 2 "" H 2700 3700 50  0001 C CNN
F 3 "" H 2700 3700 50  0001 C CNN
	1    2700 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 3700 2600 3700
$Comp
L power:Earth #PWR04
U 1 1 5E07D13C
P 2700 4100
F 0 "#PWR04" H 2700 3850 50  0001 C CNN
F 1 "Earth" H 2700 3950 50  0001 C CNN
F 2 "" H 2700 4100 50  0001 C CNN
F 3 "~" H 2700 4100 50  0001 C CNN
	1    2700 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 4000 2600 4000
$Comp
L power:+5V #PWR01
U 1 1 5E081EB6
P 2700 3000
F 0 "#PWR01" H 2700 2850 50  0001 C CNN
F 1 "+5V" V 2650 2950 50  0000 C CNN
F 2 "" H 2700 3000 50  0001 C CNN
F 3 "" H 2700 3000 50  0001 C CNN
	1    2700 3000
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR02
U 1 1 5E0822C0
P 3050 3150
F 0 "#PWR02" H 3050 2900 50  0001 C CNN
F 1 "Earth" H 3050 3000 50  0001 C CNN
F 2 "" H 3050 3150 50  0001 C CNN
F 3 "~" H 3050 3150 50  0001 C CNN
	1    3050 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3000 2600 3000
Text GLabel 6600 3850 2    50   BiDi ~ 0
A4
Wire Wire Line
	6600 3850 6500 3850
Text GLabel 2750 3200 2    50   BiDi ~ 0
A4
Wire Wire Line
	2750 3200 2600 3200
Text GLabel 6600 3950 2    50   BiDi ~ 0
A5
Wire Wire Line
	6600 3950 6500 3950
Text GLabel 2750 3300 2    50   BiDi ~ 0
A5
Wire Wire Line
	2750 3300 2600 3300
Text GLabel 6600 3450 2    50   BiDi ~ 0
A0
Text GLabel 6600 3550 2    50   BiDi ~ 0
A1
Wire Wire Line
	6600 3450 6500 3450
Wire Wire Line
	6600 3550 6500 3550
Text GLabel 2750 3800 2    50   BiDi ~ 0
A0
Text GLabel 2750 3900 2    50   BiDi ~ 0
A1
Wire Wire Line
	2750 3800 2600 3800
Wire Wire Line
	2750 3900 2600 3900
Text GLabel 5400 3350 0    50   BiDi ~ 0
D5
Wire Wire Line
	5500 3350 5400 3350
Text GLabel 5400 3450 0    50   BiDi ~ 0
D6
Text GLabel 5400 3550 0    50   BiDi ~ 0
D7
Wire Wire Line
	5500 3450 5400 3450
Wire Wire Line
	5500 3550 5400 3550
Text GLabel 5400 3250 0    50   BiDi ~ 0
D4
Text GLabel 2700 4650 2    50   BiDi ~ 0
D5
Text GLabel 2700 4750 2    50   BiDi ~ 0
D6
Text GLabel 2700 4850 2    50   BiDi ~ 0
D7
Wire Wire Line
	2700 4650 2600 4650
Wire Wire Line
	2700 4750 2600 4750
Wire Wire Line
	2700 4850 2600 4850
Text GLabel 5400 3150 0    50   BiDi ~ 0
D3
Wire Wire Line
	5500 3150 5400 3150
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E1396D8
P 6100 950
F 0 "#FLG0101" H 6100 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 6100 1123 50  0001 C CNN
F 2 "" H 6100 950 50  0001 C CNN
F 3 "~" H 6100 950 50  0001 C CNN
	1    6100 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 950  6100 1050
Connection ~ 6100 1050
Wire Wire Line
	6100 1050 6000 1050
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E14128F
P 3850 850
F 0 "#FLG0102" H 3850 925 50  0001 C CNN
F 1 "PWR_FLAG" H 3850 1023 50  0001 C CNN
F 2 "" H 3850 850 50  0001 C CNN
F 3 "~" H 3850 850 50  0001 C CNN
	1    3850 850 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5E1480FF
P 2050 1900
F 0 "#FLG0103" H 2050 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 2050 2073 50  0001 C CNN
F 2 "" H 2050 1900 50  0001 C CNN
F 3 "~" H 2050 1900 50  0001 C CNN
	1    2050 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 1900 1950 1900
Text Notes 900  2500 0    118  ~ 0
Arduino Dev Board 2.1
Wire Wire Line
	5150 5550 5250 5550
Text Notes 5350 7300 0    50   ~ 0
RGB светодиод
Wire Wire Line
	5150 5900 5300 5900
Wire Wire Line
	5150 6250 5350 6250
Wire Wire Line
	5150 6600 5400 6600
Wire Wire Line
	5250 6850 5250 5550
Connection ~ 5250 5550
Wire Wire Line
	5250 5550 5400 5550
Wire Wire Line
	5300 6950 5300 5900
Connection ~ 5300 5900
Wire Wire Line
	5300 5900 5400 5900
Wire Wire Line
	5350 7150 5350 6250
Connection ~ 5350 6250
Wire Wire Line
	5350 6250 5400 6250
Wire Wire Line
	3750 1200 3850 1200
Connection ~ 3850 1200
Wire Wire Line
	3850 1200 3900 1200
$Comp
L Device:CP C1
U 1 1 5E088B21
P 3850 1450
F 0 "C1" H 3600 1450 50  0000 L CNN
F 1 "47uF" H 3600 1350 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 3888 1300 50  0001 C CNN
F 3 "~" H 3850 1450 50  0001 C CNN
	1    3850 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5E088F3B
P 4550 1450
F 0 "C2" H 4668 1496 50  0000 L CNN
F 1 "10uF" H 4668 1405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 4588 1300 50  0001 C CNN
F 3 "~" H 4550 1450 50  0001 C CNN
	1    4550 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1500 4200 1650
Wire Wire Line
	4550 1600 4550 1650
Wire Wire Line
	4550 1650 4200 1650
Connection ~ 4200 1650
Wire Wire Line
	4200 1650 4200 1750
Wire Wire Line
	3850 1600 3850 1650
Wire Wire Line
	3850 1650 4200 1650
Wire Wire Line
	4550 1300 4550 1200
Connection ~ 4550 1200
Wire Wire Line
	4550 1200 4650 1200
Wire Wire Line
	3850 1300 3850 1200
$Comp
L power:+12V #PWR09
U 1 1 5E0DAC93
P 3450 1200
F 0 "#PWR09" H 3450 1050 50  0001 C CNN
F 1 "+12V" V 3465 1328 50  0000 L CNN
F 2 "" H 3450 1200 50  0001 C CNN
F 3 "" H 3450 1200 50  0001 C CNN
	1    3450 1200
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D7
U 1 1 5E0EA09B
P 4200 950
F 0 "D7" H 4200 850 50  0000 C CNN
F 1 "1N4007" H 4200 1075 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 4200 950 50  0001 C CNN
F 3 "~" H 4200 950 50  0001 C CNN
	1    4200 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 950  3850 950 
Wire Wire Line
	3850 950  3850 1200
Wire Wire Line
	4350 950  4550 950 
Wire Wire Line
	4550 950  4550 1200
Wire Wire Line
	3850 850  3850 950 
Connection ~ 3850 950 
Wire Wire Line
	2700 4100 2700 4000
Wire Wire Line
	3000 4550 3000 4600
Wire Wire Line
	2600 4550 3000 4550
Wire Wire Line
	3050 3150 3050 3100
Wire Wire Line
	2600 3100 3050 3100
Wire Wire Line
	6000 4450 6000 4500
Wire Wire Line
	6100 4500 6100 4450
Wire Wire Line
	6000 4500 6100 4500
Wire Wire Line
	6100 4550 6100 4500
Connection ~ 6100 4500
Text GLabel 6600 4050 2    50   BiDi ~ 0
A6
Wire Wire Line
	6600 4050 6500 4050
$Comp
L Connector:Conn_01x15_Female J13
U 1 1 5E0CC87F
P 3950 3450
F 0 "J13" H 3842 4243 50  0000 C CNN
F 1 "Conn_01x15_Female" H 3842 4244 50  0001 C CNN
F 2 "" H 3950 3450 50  0001 C CNN
F 3 "~" H 3950 3450 50  0001 C CNN
	1    3950 3450
	-1   0    0    -1  
$EndComp
Text GLabel 5400 2850 0    50   BiDi ~ 0
RX
Wire Wire Line
	5400 2850 5500 2850
Text GLabel 5400 2950 0    50   BiDi ~ 0
TX
Wire Wire Line
	5400 2950 5500 2950
Text GLabel 4250 2750 2    50   BiDi ~ 0
RX
Wire Wire Line
	4250 2750 4150 2750
Text GLabel 4250 2850 2    50   BiDi ~ 0
TX
Wire Wire Line
	4250 2850 4150 2850
Text GLabel 4250 3150 2    50   BiDi ~ 0
D2
Wire Wire Line
	4250 2950 4150 2950
Text GLabel 4250 3250 2    50   BiDi ~ 0
D3
Text GLabel 4250 3350 2    50   BiDi ~ 0
D4
Wire Wire Line
	4250 3150 4150 3150
Text GLabel 4250 3450 2    50   BiDi ~ 0
D5
Wire Wire Line
	4250 3250 4150 3250
Text GLabel 4250 3550 2    50   BiDi ~ 0
D6
Wire Wire Line
	4250 3350 4150 3350
Text GLabel 4250 3650 2    50   BiDi ~ 0
D7
Wire Wire Line
	4250 3450 4150 3450
Text GLabel 4250 3750 2    50   BiDi ~ 0
D8
Wire Wire Line
	4250 3550 4150 3550
Text GLabel 4250 3850 2    50   BiDi ~ 0
D9
Wire Wire Line
	4250 3650 4150 3650
Text GLabel 4250 3950 2    50   BiDi ~ 0
D10
Wire Wire Line
	4250 3750 4150 3750
Text GLabel 4250 4050 2    50   BiDi ~ 0
D11
Wire Wire Line
	4250 3850 4150 3850
Text GLabel 4250 4150 2    50   BiDi ~ 0
D12
Wire Wire Line
	4250 3950 4150 3950
Wire Wire Line
	4250 4050 4150 4050
Wire Wire Line
	4250 4150 4150 4150
$Comp
L power:Earth #PWR013
U 1 1 5E261BA5
P 4550 3150
F 0 "#PWR013" H 4550 2900 50  0001 C CNN
F 1 "Earth" H 4550 3000 50  0001 C CNN
F 2 "" H 4550 3150 50  0001 C CNN
F 3 "~" H 4550 3150 50  0001 C CNN
	1    4550 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3150 4550 3050
Wire Wire Line
	4150 3050 4550 3050
Text GLabel 6600 2950 2    50   BiDi ~ 0
RST
Wire Wire Line
	6600 2950 6500 2950
Text GLabel 6600 2850 2    50   BiDi ~ 0
RST
Wire Wire Line
	6600 2850 6500 2850
Text GLabel 4250 2950 2    50   BiDi ~ 0
RST
$Comp
L Connector:Conn_01x15_Female J14
U 1 1 5E289CEE
P 7450 3500
F 0 "J14" H 7342 4293 50  0000 C CNN
F 1 "Conn_01x15_Female" H 7342 4294 50  0001 C CNN
F 2 "" H 7450 3500 50  0001 C CNN
F 3 "~" H 7450 3500 50  0001 C CNN
	1    7450 3500
	-1   0    0    -1  
$EndComp
Text GLabel 5900 2350 1    50   BiDi ~ 0
VIN
Wire Wire Line
	5900 2350 5900 2400
Text GLabel 7800 2800 2    50   BiDi ~ 0
VIN
Wire Wire Line
	7800 2800 7650 2800
$Comp
L power:Earth #PWR030
U 1 1 5E2AF375
P 8250 3000
F 0 "#PWR030" H 8250 2750 50  0001 C CNN
F 1 "Earth" H 8250 2850 50  0001 C CNN
F 2 "" H 8250 3000 50  0001 C CNN
F 3 "~" H 8250 3000 50  0001 C CNN
	1    8250 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3000 8250 2900
Wire Wire Line
	8250 2900 7650 2900
Text GLabel 7800 3000 2    50   BiDi ~ 0
RST
Wire Wire Line
	7800 3000 7650 3000
$Comp
L power:+5V #PWR029
U 1 1 5E2C78C9
P 7800 3100
F 0 "#PWR029" H 7800 2950 50  0001 C CNN
F 1 "+5V" V 7800 3350 50  0000 C CNN
F 2 "" H 7800 3100 50  0001 C CNN
F 3 "" H 7800 3100 50  0001 C CNN
	1    7800 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 3100 7650 3100
Wire Wire Line
	7800 3200 7650 3200
Text GLabel 6600 4150 2    50   BiDi ~ 0
A7
Text GLabel 7800 3200 2    50   BiDi ~ 0
A7
Text GLabel 7800 3300 2    50   BiDi ~ 0
A6
Wire Wire Line
	7800 3300 7650 3300
Text GLabel 7800 3400 2    50   BiDi ~ 0
A5
Wire Wire Line
	7800 3400 7650 3400
Text GLabel 7800 3500 2    50   BiDi ~ 0
A4
Wire Wire Line
	7800 3500 7650 3500
Text GLabel 7800 3600 2    50   BiDi ~ 0
A3
Wire Wire Line
	7800 3600 7650 3600
Text GLabel 7800 3700 2    50   BiDi ~ 0
A2
Wire Wire Line
	7800 3700 7650 3700
Text GLabel 7800 3800 2    50   BiDi ~ 0
A1
Wire Wire Line
	7800 3800 7650 3800
Text GLabel 7800 3900 2    50   BiDi ~ 0
A0
Wire Wire Line
	7800 3900 7650 3900
Text GLabel 7800 4200 2    50   BiDi ~ 0
D13
Wire Wire Line
	7800 4200 7650 4200
Text GLabel 6100 2350 1    50   BiDi ~ 0
3V3
Wire Wire Line
	6100 2350 6100 2450
Text GLabel 7800 4100 2    50   BiDi ~ 0
3V3
Wire Wire Line
	7800 4100 7650 4100
Text GLabel 7800 4000 2    50   BiDi ~ 0
AREF
Wire Wire Line
	7800 4000 7650 4000
Text GLabel 6600 3250 2    50   BiDi ~ 0
AREF
Wire Wire Line
	6600 3250 6500 3250
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5E39482E
P 5750 2400
F 0 "#FLG0104" H 5750 2475 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 2573 50  0001 C CNN
F 2 "" H 5750 2400 50  0001 C CNN
F 3 "~" H 5750 2400 50  0001 C CNN
	1    5750 2400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 2400 5900 2400
Connection ~ 5900 2400
Wire Wire Line
	5900 2400 5900 2450
$EndSCHEMATC
