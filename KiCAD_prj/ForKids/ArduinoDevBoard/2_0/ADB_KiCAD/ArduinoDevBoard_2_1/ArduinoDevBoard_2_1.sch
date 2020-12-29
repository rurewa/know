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
L Transistor_BJT:PN2222A Q1
U 1 1 5DFCD34A
P 2250 6600
F 0 "Q1" H 2440 6646 50  0000 L CNN
F 1 "PN2222A" H 2440 6555 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 2450 6525 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/PN/PN2222A.pdf" H 2250 6600 50  0001 L CNN
	1    2250 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5DFCDAF5
P 1700 6600
F 0 "R1" V 1493 6600 50  0000 C CNN
F 1 "100" V 1584 6600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1630 6600 50  0001 C CNN
F 3 "~" H 1700 6600 50  0001 C CNN
	1    1700 6600
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5DFCDE6D
P 1950 6950
F 0 "R2" H 1880 6904 50  0000 R CNN
F 1 "1K" H 1880 6995 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1880 6950 50  0001 C CNN
F 3 "~" H 1950 6950 50  0001 C CNN
	1    1950 6950
	-1   0    0    1   
$EndComp
Wire Wire Line
	1850 6600 1950 6600
Wire Wire Line
	1950 6800 1950 6600
Connection ~ 1950 6600
Wire Wire Line
	1950 6600 2050 6600
Wire Wire Line
	1950 7100 1950 7200
Wire Wire Line
	1950 7200 2350 7200
Wire Wire Line
	2350 7200 2350 6800
$Comp
L power:Earth #PWR08
U 1 1 5DFD0E34
P 2350 7300
F 0 "#PWR08" H 2350 7050 50  0001 C CNN
F 1 "Earth" H 2350 7150 50  0001 C CNN
F 2 "" H 2350 7300 50  0001 C CNN
F 3 "~" H 2350 7300 50  0001 C CNN
	1    2350 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 7300 2350 7200
Connection ~ 2350 7200
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5DFD5251
P 2650 6200
F 0 "J4" H 2730 6192 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2730 6101 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 2650 6200 50  0001 C CNN
F 3 "~" H 2650 6200 50  0001 C CNN
	1    2650 6200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5DFD83FF
P 2600 4050
F 0 "J2" H 2628 4026 50  0000 L CNN
F 1 "Conn_01x04_Female" H 2628 3935 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2600 4050 50  0001 C CNN
F 3 "~" H 2600 4050 50  0001 C CNN
	1    2600 4050
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR07
U 1 1 5DFDB32E
P 2350 6100
F 0 "#PWR07" H 2350 5950 50  0001 C CNN
F 1 "+5V" H 2365 6273 50  0000 C CNN
F 2 "" H 2350 6100 50  0001 C CNN
F 3 "" H 2350 6100 50  0001 C CNN
	1    2350 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 6100 2350 6200
Wire Wire Line
	2350 6400 2350 6300
Text GLabel 1250 6600 0    50   BiDi ~ 0
D3
$Comp
L power:Earth #PWR014
U 1 1 5DFD7EB0
P 9050 3850
F 0 "#PWR014" H 9050 3600 50  0001 C CNN
F 1 "Earth" H 9050 3700 50  0001 C CNN
F 2 "" H 9050 3850 50  0001 C CNN
F 3 "~" H 9050 3850 50  0001 C CNN
	1    9050 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR015
U 1 1 5DFD9772
P 9150 1650
F 0 "#PWR015" H 9150 1500 50  0001 C CNN
F 1 "+5V" H 9250 1600 50  0000 C CNN
F 2 "" H 9150 1650 50  0001 C CNN
F 3 "" H 9150 1650 50  0001 C CNN
	1    9150 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1650 9150 1750
Text GLabel 8350 2350 0    50   BiDi ~ 0
D2
Wire Wire Line
	8450 2350 8350 2350
$Comp
L Connector:Conn_01x03_Female J9
U 1 1 5DFDCB65
P 1950 3350
F 0 "J9" H 1978 3376 50  0000 L CNN
F 1 "Conn_01x03_Female" H 1978 3285 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 1950 3350 50  0001 C CNN
F 3 "~" H 1950 3350 50  0001 C CNN
	1    1950 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5DFDE4CA
P 1600 3700
F 0 "R8" H 1670 3746 50  0000 L CNN
F 1 "4.7K" H 1670 3655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1530 3700 50  0001 C CNN
F 3 "~" H 1600 3700 50  0001 C CNN
	1    1600 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 3450 1600 3450
Wire Wire Line
	1600 3450 1600 3550
$Comp
L power:+5V #PWR019
U 1 1 5DFDF39A
P 1450 3450
F 0 "#PWR019" H 1450 3300 50  0001 C CNN
F 1 "+5V" V 1465 3578 50  0000 L CNN
F 2 "" H 1450 3450 50  0001 C CNN
F 3 "" H 1450 3450 50  0001 C CNN
	1    1450 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1450 3450 1600 3450
Connection ~ 1600 3450
Text GLabel 1500 3350 0    50   BiDi ~ 0
D2
Wire Wire Line
	1750 3350 1500 3350
$Comp
L power:Earth #PWR020
U 1 1 5DFE0064
P 1100 3350
F 0 "#PWR020" H 1100 3100 50  0001 C CNN
F 1 "Earth" H 1100 3200 50  0001 C CNN
F 2 "" H 1100 3350 50  0001 C CNN
F 3 "~" H 1100 3350 50  0001 C CNN
	1    1100 3350
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM78M05_TO220 U1
U 1 1 5DFE3BB2
P 2250 1600
F 0 "U1" H 2250 1600 50  0000 C CNN
F 1 "LM78M05_TO220" H 2250 1750 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Wide" H 2250 1825 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM78M05.pdf" H 2250 1550 50  0001 C CNN
	1    2250 1600
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR010
U 1 1 5DFE5516
P 2250 2150
F 0 "#PWR010" H 2250 1900 50  0001 C CNN
F 1 "Earth" H 2250 2000 50  0001 C CNN
F 2 "" H 2250 2150 50  0001 C CNN
F 3 "~" H 2250 2150 50  0001 C CNN
	1    2250 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J6
U 1 1 5DFE6F52
P 2700 1400
F 0 "J6" V 2592 1212 50  0000 R CNN
F 1 "Conn_01x02_Female" V 2547 1212 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2700 1400 50  0001 C CNN
F 3 "~" H 2700 1400 50  0001 C CNN
	1    2700 1400
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J5
U 1 1 5DFE96A4
P 1700 1400
F 0 "J5" V 1600 1550 50  0000 R CNN
F 1 "Conn_01x02_Female" V 1547 1212 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1700 1400 50  0001 C CNN
F 3 "~" H 1700 1400 50  0001 C CNN
	1    1700 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2550 1600 2600 1600
$Comp
L power:+5V #PWR012
U 1 1 5DFEF4EB
P 3000 1600
F 0 "#PWR012" H 3000 1450 50  0001 C CNN
F 1 "+5V" V 3015 1728 50  0000 L CNN
F 2 "" H 3000 1600 50  0001 C CNN
F 3 "" H 3000 1600 50  0001 C CNN
	1    3000 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 1600 2800 1600
Wire Wire Line
	1700 1600 1500 1600
Wire Wire Line
	2450 6200 2350 6200
Wire Wire Line
	2450 6300 2350 6300
Text GLabel 8350 3450 0    50   BiDi ~ 0
D13
$Comp
L power:+5V #PWR026
U 1 1 5E00A71C
P 6200 2750
F 0 "#PWR026" H 6200 2600 50  0001 C CNN
F 1 "+5V" H 6215 2923 50  0000 C CNN
F 2 "" H 6200 2750 50  0001 C CNN
F 3 "" H 6200 2750 50  0001 C CNN
	1    6200 2750
	1    0    0    -1  
$EndComp
Text GLabel 4850 2950 0    50   BiDi ~ 0
D13
Text GLabel 4850 3300 0    50   BiDi ~ 0
A2
Text GLabel 4850 3650 0    50   BiDi ~ 0
A3
$Comp
L Device:R R11
U 1 1 5E00F777
P 5600 4050
F 0 "R11" H 5670 4096 50  0000 L CNN
F 1 "10K" H 5670 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 5530 4050 50  0001 C CNN
F 3 "~" H 5600 4050 50  0001 C CNN
	1    5600 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5E00FB9A
P 5300 4050
F 0 "R10" H 5370 4096 50  0000 L CNN
F 1 "10K" H 5370 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 5230 4050 50  0001 C CNN
F 3 "~" H 5300 4050 50  0001 C CNN
	1    5300 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 5E00FEED
P 5000 4050
F 0 "R9" H 5070 4096 50  0000 L CNN
F 1 "10K" H 5070 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4930 4050 50  0001 C CNN
F 3 "~" H 5000 4050 50  0001 C CNN
	1    5000 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3300 5300 3300
Wire Wire Line
	5300 3900 5300 3300
Connection ~ 5300 3300
Wire Wire Line
	5300 4200 5300 4350
Connection ~ 5300 4350
$Comp
L power:Earth #PWR023
U 1 1 5E019400
P 5300 4500
F 0 "#PWR023" H 5300 4250 50  0001 C CNN
F 1 "Earth" H 5300 4350 50  0001 C CNN
F 2 "" H 5300 4500 50  0001 C CNN
F 3 "~" H 5300 4500 50  0001 C CNN
	1    5300 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4500 5300 4350
Text GLabel 9550 2950 2    50   BiDi ~ 0
A2
Text GLabel 9550 3050 2    50   BiDi ~ 0
A3
Wire Wire Line
	9550 3050 9450 3050
Wire Wire Line
	9550 2950 9450 2950
$Comp
L power:Earth #PWR021
U 1 1 5E01E177
P 1600 3950
F 0 "#PWR021" H 1600 3700 50  0001 C CNN
F 1 "Earth" H 1600 3800 50  0001 C CNN
F 2 "" H 1600 3950 50  0001 C CNN
F 3 "~" H 1600 3950 50  0001 C CNN
	1    1600 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3950 1600 3850
$Comp
L Device:LED D1
U 1 1 5E023966
P 5500 5350
F 0 "D1" H 5500 5150 50  0000 C CNN
F 1 "LED" H 5500 5250 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5500 5350 50  0001 C CNN
F 3 "~" H 5500 5350 50  0001 C CNN
	1    5500 5350
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5E024026
P 5500 5700
F 0 "D2" H 5500 5500 50  0000 C CNN
F 1 "LED" H 5500 5600 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5500 5700 50  0001 C CNN
F 3 "~" H 5500 5700 50  0001 C CNN
	1    5500 5700
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 5E0244C6
P 5500 6050
F 0 "D3" H 5500 5850 50  0000 C CNN
F 1 "LED" H 5500 5950 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5500 6050 50  0001 C CNN
F 3 "~" H 5500 6050 50  0001 C CNN
	1    5500 6050
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D4
U 1 1 5E024A28
P 5500 6400
F 0 "D4" H 5500 6200 50  0000 C CNN
F 1 "LED" H 5500 6300 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5500 6400 50  0001 C CNN
F 3 "~" H 5500 6400 50  0001 C CNN
	1    5500 6400
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D5
U 1 1 5E024F12
P 5500 6750
F 0 "D5" H 5500 6550 50  0000 C CNN
F 1 "LED" H 5500 6650 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5500 6750 50  0001 C CNN
F 3 "~" H 5500 6750 50  0001 C CNN
	1    5500 6750
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 5350 6450 5350
Wire Wire Line
	6450 5350 6450 5700
Wire Wire Line
	6450 6750 5650 6750
Connection ~ 6450 5700
Wire Wire Line
	6450 5700 6450 6050
Connection ~ 6450 6050
Wire Wire Line
	6450 6050 6450 6400
Connection ~ 6450 6400
Wire Wire Line
	6450 6400 6450 6750
$Comp
L power:Earth #PWR018
U 1 1 5E02A299
P 6450 6900
F 0 "#PWR018" H 6450 6650 50  0001 C CNN
F 1 "Earth" H 6450 6750 50  0001 C CNN
F 2 "" H 6450 6900 50  0001 C CNN
F 3 "~" H 6450 6900 50  0001 C CNN
	1    6450 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 6900 6450 6750
Connection ~ 6450 6750
$Comp
L Device:R R3
U 1 1 5E02FA65
P 4950 5350
F 0 "R3" V 4743 5350 50  0000 C CNN
F 1 "100" V 4834 5350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4880 5350 50  0001 C CNN
F 3 "~" H 4950 5350 50  0001 C CNN
	1    4950 5350
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E0309A4
P 4950 5700
F 0 "R4" V 4743 5700 50  0000 C CNN
F 1 "100" V 4834 5700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4880 5700 50  0001 C CNN
F 3 "~" H 4950 5700 50  0001 C CNN
	1    4950 5700
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5E030E0A
P 4950 6050
F 0 "R5" V 4743 6050 50  0000 C CNN
F 1 "100" V 4834 6050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4880 6050 50  0001 C CNN
F 3 "~" H 4950 6050 50  0001 C CNN
	1    4950 6050
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5E031279
P 4950 6400
F 0 "R6" V 4743 6400 50  0000 C CNN
F 1 "100" V 4834 6400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4880 6400 50  0001 C CNN
F 3 "~" H 4950 6400 50  0001 C CNN
	1    4950 6400
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5E0319D2
P 4950 6750
F 0 "R7" V 4743 6750 50  0000 C CNN
F 1 "100" V 4834 6750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4880 6750 50  0001 C CNN
F 3 "~" H 4950 6750 50  0001 C CNN
	1    4950 6750
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Female J7
U 1 1 5E036B9A
P 5600 7100
F 0 "J7" H 5628 7076 50  0000 L CNN
F 1 "Conn_01x04_Female" H 5628 6985 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5600 7100 50  0001 C CNN
F 3 "~" H 5600 7100 50  0001 C CNN
	1    5600 7100
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR011
U 1 1 5E03FD36
P 5100 7450
F 0 "#PWR011" H 5100 7200 50  0001 C CNN
F 1 "Earth" H 5100 7300 50  0001 C CNN
F 2 "" H 5100 7450 50  0001 C CNN
F 3 "~" H 5100 7450 50  0001 C CNN
	1    5100 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 7200 5100 7200
Wire Wire Line
	5100 7200 5100 7450
Wire Wire Line
	5400 7300 5300 7300
Wire Wire Line
	5400 7100 5250 7100
Wire Wire Line
	5400 7000 5200 7000
Wire Wire Line
	5350 5350 5100 5350
Text GLabel 4650 5350 0    50   BiDi ~ 0
D8
Wire Wire Line
	4800 5350 4650 5350
Wire Wire Line
	8450 3450 8350 3450
Text GLabel 8350 2950 0    50   BiDi ~ 0
D8
Wire Wire Line
	8450 2950 8350 2950
Text GLabel 4650 5700 0    50   BiDi ~ 0
D9
Text GLabel 8350 3050 0    50   BiDi ~ 0
D9
Wire Wire Line
	8350 3050 8450 3050
Wire Wire Line
	4800 5700 4650 5700
Text GLabel 4650 6050 0    50   BiDi ~ 0
D10
Wire Wire Line
	4800 6050 4650 6050
Text GLabel 8350 3150 0    50   BiDi ~ 0
D10
Wire Wire Line
	8450 3150 8350 3150
Text GLabel 4650 6400 0    50   BiDi ~ 0
D11
Wire Wire Line
	4800 6400 4650 6400
Text GLabel 8350 3250 0    50   BiDi ~ 0
D11
Wire Wire Line
	8450 3250 8350 3250
Text GLabel 4650 6750 0    50   BiDi ~ 0
D12
Wire Wire Line
	4800 6750 4650 6750
Text GLabel 8350 3350 0    50   BiDi ~ 0
D12
Wire Wire Line
	8450 3350 8350 3350
Text Notes 1900 6300 0    50   ~ 0
Мотор
Text Notes 1950 1150 0    50   ~ 0
Стабилизатор напряжения
Text Notes 1550 3100 0    50   ~ 0
Датчик t\nDS18B20
$Comp
L Connector:Screw_Terminal_01x02 J8
U 1 1 5DFE5568
P 4800 1450
F 0 "J8" H 4880 1442 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 4880 1351 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 4800 1450 50  0001 C CNN
F 3 "~" H 4800 1450 50  0001 C CNN
	1    4800 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:D D6
U 1 1 5DFE6204
P 4350 1450
F 0 "D6" H 4350 1666 50  0000 C CNN
F 1 "1N4007" H 4350 1575 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 4350 1450 50  0001 C CNN
F 3 "~" H 4350 1450 50  0001 C CNN
	1    4350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1450 4500 1450
Wire Wire Line
	4600 1550 4500 1550
Wire Wire Line
	4500 1550 4500 1700
$Comp
L power:Earth #PWR017
U 1 1 5DFEC03F
P 4500 1750
F 0 "#PWR017" H 4500 1500 50  0001 C CNN
F 1 "Earth" H 4500 1600 50  0001 C CNN
F 2 "" H 4500 1750 50  0001 C CNN
F 3 "~" H 4500 1750 50  0001 C CNN
	1    4500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1450 4150 1450
Text Notes 3750 1650 0    50   ~ 0
Внешнее питание
Text Notes 4950 2700 0    118  ~ 0
Блок кнопок
Text Notes 4700 5000 0    118  ~ 0
Блок светодиодов
$Comp
L Connector:Conn_01x04_Female J10
U 1 1 5DFF84FC
P 8800 4950
F 0 "J10" H 8828 4926 50  0000 L CNN
F 1 "Conn_01x04_Female" H 8828 4835 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 8800 4950 50  0001 C CNN
F 3 "~" H 8800 4950 50  0001 C CNN
	1    8800 4950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J11
U 1 1 5DFF91E9
P 9350 4950
F 0 "J11" H 9378 4926 50  0000 L CNN
F 1 "Conn_01x04_Female" H 9378 4835 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9350 4950 50  0001 C CNN
F 3 "~" H 9350 4950 50  0001 C CNN
	1    9350 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 4850 8500 4850
Wire Wire Line
	8500 4850 8500 4950
Wire Wire Line
	8500 5150 8600 5150
Wire Wire Line
	8600 4950 8500 4950
Connection ~ 8500 4950
Wire Wire Line
	8500 4950 8500 5050
Wire Wire Line
	8600 5050 8500 5050
Connection ~ 8500 5050
Wire Wire Line
	8500 5050 8500 5150
$Comp
L power:+5V #PWR022
U 1 1 5E003AC7
P 8500 4750
F 0 "#PWR022" H 8500 4600 50  0001 C CNN
F 1 "+5V" H 8550 4800 50  0000 L CNN
F 2 "" H 8500 4750 50  0001 C CNN
F 3 "" H 8500 4750 50  0001 C CNN
	1    8500 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4750 8500 4850
Connection ~ 8500 4850
Wire Wire Line
	9150 4850 9050 4850
Wire Wire Line
	9050 4850 9050 4950
Wire Wire Line
	9050 5150 9150 5150
$Comp
L power:Earth #PWR024
U 1 1 5E00C477
P 9050 5250
F 0 "#PWR024" H 9050 5000 50  0001 C CNN
F 1 "Earth" H 9050 5100 50  0001 C CNN
F 2 "" H 9050 5250 50  0001 C CNN
F 3 "~" H 9050 5250 50  0001 C CNN
	1    9050 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 5250 9050 5150
Connection ~ 9050 5150
Wire Wire Line
	9150 5050 9050 5050
Connection ~ 9050 5050
Wire Wire Line
	9050 5050 9050 5150
Wire Wire Line
	9150 4950 9050 4950
Connection ~ 9050 4950
Wire Wire Line
	9050 4950 9050 5050
Text Notes 8650 4600 0    50   ~ 0
Шины питания
Wire Wire Line
	8450 2550 8350 2550
$Comp
L Connector:Conn_01x02_Female J12
U 1 1 5E0214E6
P 1800 4400
F 0 "J12" H 1828 4330 50  0000 L CNN
F 1 "Conn_01x02_Female" H 1828 4285 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1800 4400 50  0001 C CNN
F 3 "~" H 1800 4400 50  0001 C CNN
	1    1800 4400
	1    0    0    -1  
$EndComp
Text GLabel 1450 4400 0    50   Input ~ 0
D4
Wire Wire Line
	1600 4400 1450 4400
$Comp
L power:Earth #PWR025
U 1 1 5E0276EA
P 1600 4650
F 0 "#PWR025" H 1600 4400 50  0001 C CNN
F 1 "Earth" H 1600 4500 50  0001 C CNN
F 2 "" H 1600 4650 50  0001 C CNN
F 3 "~" H 1600 4650 50  0001 C CNN
	1    1600 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4650 1600 4500
Text Notes 1550 4300 0    50   ~ 0
Buzzer
Wire Wire Line
	9550 3450 9450 3450
$Comp
L Device:R_POT RV1
U 1 1 5E03950B
P 1600 5500
F 0 "RV1" H 1530 5546 50  0000 R CNN
F 1 "1K" H 1530 5455 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Runtron_RM-065_Vertical" H 1600 5500 50  0001 C CNN
F 3 "~" H 1600 5500 50  0001 C CNN
	1    1600 5500
	-1   0    0    -1  
$EndComp
Text GLabel 1300 5500 0    50   Input ~ 0
A7
Wire Wire Line
	1450 5500 1300 5500
$Comp
L power:Earth #PWR028
U 1 1 5E041882
P 1600 5800
F 0 "#PWR028" H 1600 5550 50  0001 C CNN
F 1 "Earth" H 1600 5650 50  0001 C CNN
F 2 "" H 1600 5800 50  0001 C CNN
F 3 "~" H 1600 5800 50  0001 C CNN
	1    1600 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 5800 1600 5650
$Comp
L power:+5V #PWR027
U 1 1 5E045F94
P 1600 5200
F 0 "#PWR027" H 1600 5050 50  0001 C CNN
F 1 "+5V" H 1615 5373 50  0000 C CNN
F 2 "" H 1600 5200 50  0001 C CNN
F 3 "" H 1600 5200 50  0001 C CNN
	1    1600 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 5200 1600 5350
Text Notes 2550 4550 0    50   ~ 0
MAX7219
Text Notes 2600 3850 0    50   ~ 0
SONAR HC-SR04
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5E05B2D9
P 2600 3350
F 0 "J1" H 2628 3326 50  0000 L CNN
F 1 "Conn_01x04_Female" H 2628 3235 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2600 3350 50  0001 C CNN
F 3 "~" H 2600 3350 50  0001 C CNN
	1    2600 3350
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 5E05BD68
P 2600 4900
F 0 "J3" H 2700 4900 50  0000 C CNN
F 1 "Conn_01x05_Female" H 2628 4835 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2600 4900 50  0001 C CNN
F 3 "~" H 2600 4900 50  0001 C CNN
	1    2600 4900
	-1   0    0    -1  
$EndComp
Text Notes 2550 3150 0    50   ~ 0
LCD1602
$Comp
L power:+5V #PWR05
U 1 1 5E06EB6A
P 2900 4700
F 0 "#PWR05" H 2900 4550 50  0001 C CNN
F 1 "+5V" V 2850 4650 50  0000 C CNN
F 2 "" H 2900 4700 50  0001 C CNN
F 3 "" H 2900 4700 50  0001 C CNN
	1    2900 4700
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR06
U 1 1 5E06F08F
P 3200 4850
F 0 "#PWR06" H 3200 4600 50  0001 C CNN
F 1 "Earth" H 3200 4700 50  0001 C CNN
F 2 "" H 3200 4850 50  0001 C CNN
F 3 "~" H 3200 4850 50  0001 C CNN
	1    3200 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 4700 2800 4700
$Comp
L power:+5V #PWR03
U 1 1 5E078870
P 2900 3950
F 0 "#PWR03" H 2900 3800 50  0001 C CNN
F 1 "+5V" V 2850 3900 50  0000 C CNN
F 2 "" H 2900 3950 50  0001 C CNN
F 3 "" H 2900 3950 50  0001 C CNN
	1    2900 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 3950 2800 3950
$Comp
L power:Earth #PWR04
U 1 1 5E07D13C
P 2900 4350
F 0 "#PWR04" H 2900 4100 50  0001 C CNN
F 1 "Earth" H 2900 4200 50  0001 C CNN
F 2 "" H 2900 4350 50  0001 C CNN
F 3 "~" H 2900 4350 50  0001 C CNN
	1    2900 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 4250 2800 4250
$Comp
L power:+5V #PWR01
U 1 1 5E081EB6
P 2900 3250
F 0 "#PWR01" H 2900 3100 50  0001 C CNN
F 1 "+5V" V 2850 3200 50  0000 C CNN
F 2 "" H 2900 3250 50  0001 C CNN
F 3 "" H 2900 3250 50  0001 C CNN
	1    2900 3250
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR02
U 1 1 5E0822C0
P 3250 3400
F 0 "#PWR02" H 3250 3150 50  0001 C CNN
F 1 "Earth" H 3250 3250 50  0001 C CNN
F 2 "" H 3250 3400 50  0001 C CNN
F 3 "~" H 3250 3400 50  0001 C CNN
	1    3250 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3250 2800 3250
Text GLabel 9550 3150 2    50   BiDi ~ 0
A4
Wire Wire Line
	9550 3150 9450 3150
Text GLabel 2950 3450 2    50   BiDi ~ 0
A4
Wire Wire Line
	2950 3450 2800 3450
Text GLabel 9550 3250 2    50   BiDi ~ 0
A5
Wire Wire Line
	9550 3250 9450 3250
Text GLabel 2950 3550 2    50   BiDi ~ 0
A5
Wire Wire Line
	2950 3550 2800 3550
Text GLabel 9550 2750 2    50   BiDi ~ 0
A0
Text GLabel 9550 2850 2    50   BiDi ~ 0
A1
Wire Wire Line
	9550 2750 9450 2750
Wire Wire Line
	9550 2850 9450 2850
Text GLabel 2950 4050 2    50   BiDi ~ 0
A0
Text GLabel 2950 4150 2    50   BiDi ~ 0
A1
Wire Wire Line
	2950 4050 2800 4050
Wire Wire Line
	2950 4150 2800 4150
Text GLabel 8350 2650 0    50   BiDi ~ 0
D5
Wire Wire Line
	8450 2650 8350 2650
Text GLabel 8350 2750 0    50   BiDi ~ 0
D6
Text GLabel 8350 2850 0    50   BiDi ~ 0
D7
Wire Wire Line
	8450 2750 8350 2750
Wire Wire Line
	8450 2850 8350 2850
Text GLabel 8350 2550 0    50   BiDi ~ 0
D4
Text GLabel 2900 4900 2    50   BiDi ~ 0
D5
Text GLabel 2900 5000 2    50   BiDi ~ 0
D6
Text GLabel 2900 5100 2    50   BiDi ~ 0
D7
Wire Wire Line
	2900 4900 2800 4900
Wire Wire Line
	2900 5000 2800 5000
Wire Wire Line
	2900 5100 2800 5100
Text GLabel 8350 2450 0    50   BiDi ~ 0
D3
Wire Wire Line
	8450 2450 8350 2450
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E1396D8
P 4150 1350
F 0 "#FLG0101" H 4150 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 4150 1523 50  0001 C CNN
F 2 "" H 4150 1350 50  0001 C CNN
F 3 "~" H 4150 1350 50  0001 C CNN
	1    4150 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1350 4150 1450
Connection ~ 4150 1450
Wire Wire Line
	4150 1450 4050 1450
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E14128F
P 1900 1250
F 0 "#FLG0102" H 1900 1325 50  0001 C CNN
F 1 "PWR_FLAG" H 1900 1423 50  0001 C CNN
F 2 "" H 1900 1250 50  0001 C CNN
F 3 "~" H 1900 1250 50  0001 C CNN
	1    1900 1250
	1    0    0    -1  
$EndComp
Text Notes 7250 1050 0    197  ~ 39
Arduino Dev Board 2.1
Wire Wire Line
	5100 5700 5200 5700
Text Notes 5300 7450 0    50   ~ 0
RGB светодиод
Wire Wire Line
	5100 6050 5250 6050
Wire Wire Line
	5100 6400 5300 6400
Wire Wire Line
	5100 6750 5350 6750
Wire Wire Line
	5200 7000 5200 5700
Connection ~ 5200 5700
Wire Wire Line
	5200 5700 5350 5700
Wire Wire Line
	5250 7100 5250 6050
Connection ~ 5250 6050
Wire Wire Line
	5250 6050 5350 6050
Wire Wire Line
	5300 7300 5300 6400
Connection ~ 5300 6400
Wire Wire Line
	5300 6400 5350 6400
Wire Wire Line
	1800 1600 1900 1600
Connection ~ 1900 1600
Wire Wire Line
	1900 1600 1950 1600
$Comp
L Device:CP C1
U 1 1 5E088B21
P 1900 1850
F 0 "C1" H 1650 1850 50  0000 L CNN
F 1 "47uF" H 1650 1750 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 1938 1700 50  0001 C CNN
F 3 "~" H 1900 1850 50  0001 C CNN
	1    1900 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5E088F3B
P 2600 1850
F 0 "C2" H 2718 1896 50  0000 L CNN
F 1 "10uF" H 2718 1805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 2638 1700 50  0001 C CNN
F 3 "~" H 2600 1850 50  0001 C CNN
	1    2600 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1900 2250 2050
Wire Wire Line
	2600 2000 2600 2050
Wire Wire Line
	2600 2050 2250 2050
Connection ~ 2250 2050
Wire Wire Line
	2250 2050 2250 2150
Wire Wire Line
	1900 2000 1900 2050
Wire Wire Line
	1900 2050 2250 2050
Wire Wire Line
	2600 1700 2600 1600
Connection ~ 2600 1600
Wire Wire Line
	2600 1600 2700 1600
Wire Wire Line
	1900 1700 1900 1600
$Comp
L Device:D D7
U 1 1 5E0EA09B
P 2250 1350
F 0 "D7" H 2100 1400 50  0000 C CNN
F 1 "1N4007" H 2450 1400 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 2250 1350 50  0001 C CNN
F 3 "~" H 2250 1350 50  0001 C CNN
	1    2250 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1350 1900 1350
Wire Wire Line
	1900 1350 1900 1600
Wire Wire Line
	2400 1350 2600 1350
Wire Wire Line
	2600 1350 2600 1600
Wire Wire Line
	1900 1250 1900 1350
Connection ~ 1900 1350
Wire Wire Line
	2900 4350 2900 4250
Wire Wire Line
	3200 4800 3200 4850
Wire Wire Line
	2800 4800 3200 4800
Wire Wire Line
	3250 3400 3250 3350
Wire Wire Line
	2800 3350 3250 3350
Wire Wire Line
	8950 3750 8950 3800
Wire Wire Line
	9050 3800 9050 3750
Wire Wire Line
	8950 3800 9050 3800
Wire Wire Line
	9050 3850 9050 3800
Connection ~ 9050 3800
Text GLabel 9550 3350 2    50   BiDi ~ 0
A6
Wire Wire Line
	9550 3350 9450 3350
Text GLabel 8350 2150 0    50   BiDi ~ 0
RX
Wire Wire Line
	8350 2150 8450 2150
Text GLabel 8350 2250 0    50   BiDi ~ 0
TX
Wire Wire Line
	8350 2250 8450 2250
Text GLabel 9550 3450 2    50   BiDi ~ 0
A7
Wire Wire Line
	9050 1650 9050 1750
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5DFCBFEA
P 8950 2750
F 0 "A1" H 8850 1750 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 8950 2750 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 8950 2750 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 8950 2750 50  0001 C CNN
	1    8950 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J15
U 1 1 5FEDFE09
P 2600 5550
F 0 "J15" H 2628 5576 50  0000 L CNN
F 1 "Conn_01x03_Female" H 2628 5485 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2600 5550 50  0001 C CNN
F 3 "~" H 2600 5550 50  0001 C CNN
	1    2600 5550
	-1   0    0    -1  
$EndComp
Text GLabel 3200 5650 2    50   Input ~ 0
D3
$Comp
L power:Earth #PWR032
U 1 1 5FEF0D5C
P 3450 5550
F 0 "#PWR032" H 3450 5300 50  0001 C CNN
F 1 "Earth" H 3450 5400 50  0001 C CNN
F 2 "" H 3450 5550 50  0001 C CNN
F 3 "~" H 3450 5550 50  0001 C CNN
	1    3450 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR031
U 1 1 5FF0DD42
P 2900 5550
F 0 "#PWR031" H 2900 5400 50  0001 C CNN
F 1 "+5V" V 2850 5500 50  0000 C CNN
F 2 "" H 2900 5550 50  0001 C CNN
F 3 "" H 2900 5550 50  0001 C CNN
	1    2900 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 5550 2900 5550
Text Notes 2550 5350 0    50   ~ 0
Servo SG90
$Comp
L Connector:Conn_01x02_Female J16
U 1 1 5FF1D977
P 6000 5500
F 0 "J16" V 5892 5312 50  0000 R CNN
F 1 "Conn_01x02_Female" V 5847 5312 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6000 5500 50  0001 C CNN
F 3 "~" H 6000 5500 50  0001 C CNN
	1    6000 5500
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J17
U 1 1 5FF1ED65
P 6000 5850
F 0 "J17" V 5892 5662 50  0000 R CNN
F 1 "Conn_01x02_Female" V 5847 5662 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6000 5850 50  0001 C CNN
F 3 "~" H 6000 5850 50  0001 C CNN
	1    6000 5850
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J18
U 1 1 5FF1EF7F
P 6000 6200
F 0 "J18" V 5892 6012 50  0000 R CNN
F 1 "Conn_01x02_Female" V 5847 6012 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6000 6200 50  0001 C CNN
F 3 "~" H 6000 6200 50  0001 C CNN
	1    6000 6200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5650 6400 6000 6400
Wire Wire Line
	6100 6400 6450 6400
Wire Wire Line
	5650 6050 6000 6050
Wire Wire Line
	6100 6050 6450 6050
Wire Wire Line
	5650 5700 6000 5700
Wire Wire Line
	6100 5700 6450 5700
Text Notes 1300 2750 0    118  ~ 0
Дискретные устройства
Text Notes 8450 4450 0    118  ~ 0
Коннекторы
Wire Notes Line
	9550 5400 8400 5400
Wire Notes Line
	1000 7600 3750 7600
Wire Notes Line
	6650 7600 4350 7600
Wire Notes Line
	4350 4750 6650 4750
Wire Notes Line
	6650 4750 6650 7600
Wire Notes Line
	4350 4750 4350 7600
Wire Notes Line
	4350 4700 6650 4700
Wire Notes Line
	6650 4700 6650 2500
Wire Notes Line
	6650 2500 4350 2500
Wire Notes Line
	4350 2500 4350 4700
Wire Notes Line
	3750 2500 1000 2500
Wire Notes Line
	3750 2500 3750 7600
Wire Notes Line
	1000 2500 1000 7600
Wire Notes Line
	1000 2300 6650 2300
Wire Notes Line
	6650 2300 6650 700 
Wire Notes Line
	6650 700  1000 700 
Wire Notes Line
	1000 700  1000 2300
Text Notes 5050 1000 0    118  ~ 0
Питание
Wire Wire Line
	1100 3350 1100 3250
Wire Wire Line
	1100 3250 1750 3250
Wire Wire Line
	5000 4350 5000 4200
Wire Wire Line
	5000 4350 5300 4350
Wire Wire Line
	5000 3900 5000 2950
Wire Wire Line
	4850 2950 5000 2950
Connection ~ 5000 2950
Wire Wire Line
	6200 2750 6200 2950
Wire Wire Line
	5000 2950 5650 2950
Wire Wire Line
	5300 3300 5650 3300
Wire Wire Line
	6050 3650 6200 3650
Wire Wire Line
	6050 3300 6200 3300
Connection ~ 6200 3300
Wire Wire Line
	6200 3300 6200 3650
Wire Wire Line
	6050 2950 6200 2950
Connection ~ 6200 2950
Wire Wire Line
	6200 2950 6200 3300
Wire Wire Line
	4850 3650 5600 3650
Wire Wire Line
	5600 4350 5600 4200
Wire Wire Line
	5300 4350 5600 4350
Wire Wire Line
	5600 3900 5600 3650
Connection ~ 5600 3650
Wire Wire Line
	5600 3650 5650 3650
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5FF7AB06
P 4400 1700
F 0 "#FLG0103" H 4400 1775 50  0001 C CNN
F 1 "PWR_FLAG" H 4400 1873 50  0001 C CNN
F 2 "" H 4400 1700 50  0001 C CNN
F 3 "~" H 4400 1700 50  0001 C CNN
	1    4400 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 1700 4500 1700
Connection ~ 4500 1700
Wire Wire Line
	4500 1700 4500 1750
Wire Wire Line
	3450 5450 3450 5550
Wire Wire Line
	2800 5450 3450 5450
$Comp
L Connector:Conn_01x02_Female J20
U 1 1 5FF97A28
P 3100 5850
F 0 "J20" V 2992 5662 50  0000 R CNN
F 1 "Conn_01x02_Female" V 2947 5662 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3100 5850 50  0001 C CNN
F 3 "~" H 3100 5850 50  0001 C CNN
	1    3100 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 5650 3000 5650
Wire Wire Line
	3100 5650 3200 5650
$Comp
L Connector:Conn_01x02_Female J19
U 1 1 5FFB5843
P 1350 6400
F 0 "J19" V 1400 6400 50  0000 R CNN
F 1 "Conn_01x02_Female" V 1197 6212 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1350 6400 50  0001 C CNN
F 3 "~" H 1350 6400 50  0001 C CNN
	1    1350 6400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1250 6600 1350 6600
Wire Wire Line
	1450 6600 1550 6600
Wire Notes Line
	8400 4250 9550 4250
Wire Notes Line
	8400 4250 8400 5400
Text GLabel 1500 1600 0    50   Input ~ 0
VIN
$Comp
L Connector:Conn_01x04_Female J13
U 1 1 60046ECC
P 3500 7000
F 0 "J13" H 3528 6976 50  0000 L CNN
F 1 "Conn_01x04_Female" H 3528 6885 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3500 7000 50  0001 C CNN
F 3 "~" H 3500 7000 50  0001 C CNN
	1    3500 7000
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0101
U 1 1 60048ECB
P 2950 7300
F 0 "#PWR0101" H 2950 7050 50  0001 C CNN
F 1 "Earth" H 2950 7150 50  0001 C CNN
F 2 "" H 2950 7300 50  0001 C CNN
F 3 "~" H 2950 7300 50  0001 C CNN
	1    2950 7300
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 60049990
P 3200 7200
F 0 "#PWR0102" H 3200 7050 50  0001 C CNN
F 1 "+5V" V 3250 7250 50  0000 L CNN
F 2 "" H 3200 7200 50  0001 C CNN
F 3 "" H 3200 7200 50  0001 C CNN
	1    3200 7200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3200 7200 3300 7200
Wire Wire Line
	3300 7100 2950 7100
Wire Wire Line
	2950 7100 2950 7300
Text GLabel 3050 6900 0    50   Input ~ 0
RX
Wire Wire Line
	3050 6900 3300 6900
Text GLabel 3050 7000 0    50   Output ~ 0
TX
Wire Wire Line
	3050 7000 3300 7000
Text Notes 3100 6800 0    50   ~ 0
Bluetooth
Wire Notes Line
	9550 4250 9550 5400
Text GLabel 4050 1450 0    50   Output ~ 0
VIN
NoConn ~ 9450 2150
NoConn ~ 9450 2250
NoConn ~ 9450 2550
$Comp
L power:+5V #PWR09
U 1 1 60107CC8
P 8850 1650
F 0 "#PWR09" H 8850 1500 50  0001 C CNN
F 1 "+5V" H 8750 1600 50  0000 C CNN
F 2 "" H 8850 1650 50  0001 C CNN
F 3 "" H 8850 1650 50  0001 C CNN
	1    8850 1650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW1
U 1 1 5FEA2232
P 5850 3050
F 0 "SW1" H 5850 3343 50  0000 C CNN
F 1 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 5850 3344 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5850 3350 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 5850 3350 50  0001 C CNN
	1    5850 3050
	1    0    0    -1  
$EndComp
NoConn ~ 6050 3050
NoConn ~ 5650 3050
$Comp
L Switch:SW_MEC_5E SW2
U 1 1 5FEB6DE7
P 5850 3400
F 0 "SW2" H 5850 3693 50  0000 C CNN
F 1 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 5850 3694 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5850 3700 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 5850 3700 50  0001 C CNN
	1    5850 3400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5E SW3
U 1 1 5FEB77CA
P 5850 3750
F 0 "SW3" H 5850 4043 50  0000 C CNN
F 1 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 5850 4044 50  0001 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5850 4050 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 5850 4050 50  0001 C CNN
	1    5850 3750
	1    0    0    -1  
$EndComp
NoConn ~ 5650 3400
NoConn ~ 6050 3400
NoConn ~ 6050 3750
NoConn ~ 5650 3750
Wire Wire Line
	8850 1650 8850 1750
$Comp
L power:+3.3V #PWR0103
U 1 1 5FEE0C91
P 9050 1650
F 0 "#PWR0103" H 9050 1500 50  0001 C CNN
F 1 "+3.3V" V 8950 1600 50  0000 C CNN
F 2 "" H 9050 1650 50  0001 C CNN
F 3 "" H 9050 1650 50  0001 C CNN
	1    9050 1650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
