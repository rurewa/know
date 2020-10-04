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
L Driver_Motor:L293D U?
U 1 1 5F78128C
P 7050 3600
F 0 "U?" H 7050 4781 50  0000 C CNN
F 1 "L293D" H 7150 3800 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 7300 2850 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/l293.pdf" H 6750 4300 50  0001 C CNN
	1    7050 3600
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano_v3.x A?
U 1 1 5F78383F
P 4350 3600
F 0 "A?" H 4350 3000 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 4350 3500 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 4350 3600 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4350 3600 50  0001 C CNN
	1    4350 3600
	1    0    0    -1  
$EndComp
Text GLabel 6400 3000 0    50   Output ~ 0
IN3
Text GLabel 6400 3200 0    50   Output ~ 0
IN4
$Comp
L power:+9V #PWR?
U 1 1 5F793BCF
P 6850 1850
F 0 "#PWR?" H 6850 1700 50  0001 C CNN
F 1 "+9V" H 6865 2023 50  0000 C CNN
F 2 "" H 6850 1850 50  0001 C CNN
F 3 "" H 6850 1850 50  0001 C CNN
	1    6850 1850
	1    0    0    -1  
$EndComp
Text GLabel 3750 4100 0    50   Output ~ 0
D11
Wire Wire Line
	3850 4100 3750 4100
$Comp
L Device:CP C?
U 1 1 5F7A5D36
P 5750 1350
F 0 "C?" H 5868 1396 50  0000 L CNN
F 1 "330uF" H 5868 1305 50  0000 L CNN
F 2 "" H 5788 1200 50  0001 C CNN
F 3 "~" H 5750 1350 50  0001 C CNN
	1    5750 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 4400 6850 4500
Wire Wire Line
	6950 4500 6950 4400
Wire Wire Line
	6850 4500 6950 4500
Wire Wire Line
	6950 4500 7050 4500
Wire Wire Line
	7250 4500 7250 4400
Connection ~ 6950 4500
Wire Wire Line
	7150 4400 7150 4500
Connection ~ 7150 4500
Wire Wire Line
	7150 4500 7250 4500
Connection ~ 7050 4500
Wire Wire Line
	7050 4500 7150 4500
$Comp
L Switch:SW_SPDT SW?
U 1 1 5F7AEAC2
P 6850 2200
F 0 "SW?" V 6850 2050 50  0000 L CNN
F 1 "SW_SPDT" V 7150 1950 50  0001 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 6850 2200 50  0001 C CNN
F 3 "~" H 6850 2200 50  0001 C CNN
	1    6850 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 2400 6950 2600
Wire Wire Line
	6850 1850 6850 1900
$Comp
L Diode:1N4001 D?
U 1 1 5F7B6481
P 7150 1900
F 0 "D?" H 7150 2117 50  0000 C CNN
F 1 "1N4001" H 7150 2026 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 7150 1725 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 7150 1900 50  0001 C CNN
	1    7150 1900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7000 1900 6850 1900
Connection ~ 6850 1900
Wire Wire Line
	6850 1900 6850 2000
$Comp
L power:Earth #PWR?
U 1 1 5F7B89BD
P 7450 1900
F 0 "#PWR?" H 7450 1650 50  0001 C CNN
F 1 "Earth" H 7450 1750 50  0001 C CNN
F 2 "" H 7450 1900 50  0001 C CNN
F 3 "~" H 7450 1900 50  0001 C CNN
	1    7450 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7450 1900 7300 1900
$Comp
L Regulator_Linear:L7805 U?
U 1 1 5F7C803E
P 5400 2300
F 0 "U?" H 5400 2542 50  0000 C CNN
F 1 "L7805" H 5400 2451 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin2" H 5425 2150 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 5400 2250 50  0001 C CNN
	1    5400 2300
	1    0    0    -1  
$EndComp
NoConn ~ 6750 2400
$Comp
L Device:R R?
U 1 1 5F7CA298
P 5900 3400
F 0 "R?" V 5693 3400 50  0000 C CNN
F 1 "100K" V 5784 3400 50  0000 C CNN
F 2 "" V 5830 3400 50  0001 C CNN
F 3 "~" H 5900 3400 50  0001 C CNN
	1    5900 3400
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F7CB336
P 5900 4000
F 0 "R?" V 5693 4000 50  0000 C CNN
F 1 "100K" V 5784 4000 50  0000 C CNN
F 2 "" V 5830 4000 50  0001 C CNN
F 3 "~" H 5900 4000 50  0001 C CNN
	1    5900 4000
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5F7CCC0C
P 5600 4300
F 0 "#PWR?" H 5600 4050 50  0001 C CNN
F 1 "Earth" H 5600 4150 50  0001 C CNN
F 2 "" H 5600 4300 50  0001 C CNN
F 3 "~" H 5600 4300 50  0001 C CNN
	1    5600 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 4300 5600 4000
Wire Wire Line
	5600 3400 5750 3400
Wire Wire Line
	5750 4000 5600 4000
Connection ~ 5600 4000
Wire Wire Line
	5600 4000 5600 3400
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 5F806128
P 7900 3650
F 0 "J?" H 7980 3642 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7980 3551 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 7900 3650 50  0001 C CNN
F 3 "~" H 7900 3650 50  0001 C CNN
	1    7900 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3600 7700 3600
Wire Wire Line
	7700 3600 7700 3650
Wire Wire Line
	7550 3800 7700 3800
Wire Wire Line
	7700 3800 7700 3750
Wire Wire Line
	6400 3000 6550 3000
Wire Wire Line
	6050 3400 6550 3400
Wire Wire Line
	6050 4000 6550 4000
Wire Wire Line
	6400 3200 6550 3200
Wire Wire Line
	7550 3000 7700 3000
Wire Wire Line
	7700 3000 7700 3050
Wire Wire Line
	7550 3200 7700 3200
Wire Wire Line
	7700 3200 7700 3150
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F84921C
P 5900 2100
F 0 "J?" V 6000 2100 50  0000 R CNN
F 1 "Conn_01x02_Female" V 6000 2250 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5900 2100 50  0001 C CNN
F 3 "~" H 5900 2100 50  0001 C CNN
	1    5900 2100
	0    -1   -1   0   
$EndComp
Text GLabel 7150 2500 1    50   Input ~ 0
5V
Wire Wire Line
	7150 2500 7150 2600
Text GLabel 6100 2300 2    50   Output ~ 0
5V
$Comp
L power:Earth #PWR?
U 1 1 5F84F4BF
P 5400 2800
F 0 "#PWR?" H 5400 2550 50  0001 C CNN
F 1 "Earth" H 5400 2650 50  0001 C CNN
F 2 "" H 5400 2800 50  0001 C CNN
F 3 "~" H 5400 2800 50  0001 C CNN
	1    5400 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2800 5400 2750
$Comp
L power:+9V #PWR?
U 1 1 5F851F48
P 4900 1950
F 0 "#PWR?" H 4900 1800 50  0001 C CNN
F 1 "+9V" H 4915 2123 50  0000 C CNN
F 2 "" H 4900 1950 50  0001 C CNN
F 3 "" H 4900 1950 50  0001 C CNN
	1    4900 1950
	1    0    0    -1  
$EndComp
Text GLabel 6400 3800 0    50   Output ~ 0
IN2
Wire Wire Line
	6400 3800 6550 3800
Text GLabel 6400 3600 0    50   Output ~ 0
IN1
Wire Wire Line
	6400 3600 6550 3600
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 5F8298E7
P 7900 3050
F 0 "J?" H 7980 3042 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7980 2951 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 7900 3050 50  0001 C CNN
F 3 "~" H 7900 3050 50  0001 C CNN
	1    7900 3050
	1    0    0    -1  
$EndComp
Text GLabel 9250 2150 2    50   Input ~ 0
11
Wire Wire Line
	8350 1900 8350 1950
Connection ~ 8350 1900
Wire Wire Line
	8150 1900 8350 1900
Wire Wire Line
	8350 1450 8350 1550
Connection ~ 9150 2150
Wire Wire Line
	9250 2150 9150 2150
Wire Wire Line
	9150 2050 9150 2150
Wire Wire Line
	8750 2150 8650 2150
Text GLabel 8150 1900 0    50   Input ~ 0
IN4
Text GLabel 9150 2050 1    50   Input ~ 0
IN3
Wire Wire Line
	8350 1850 8350 1900
Wire Wire Line
	8350 2350 8350 2550
Wire Wire Line
	9150 2150 9050 2150
$Comp
L power:Earth #PWR?
U 1 1 5F7801C1
P 8350 2550
F 0 "#PWR?" H 8350 2300 50  0001 C CNN
F 1 "Earth" H 8350 2400 50  0001 C CNN
F 2 "" H 8350 2550 50  0001 C CNN
F 3 "~" H 8350 2550 50  0001 C CNN
	1    8350 2550
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F77EB8E
P 8900 2150
F 0 "R?" V 8693 2150 50  0000 C CNN
F 1 "330" V 8784 2150 50  0000 C CNN
F 2 "" V 8830 2150 50  0001 C CNN
F 3 "~" H 8900 2150 50  0001 C CNN
	1    8900 2150
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F77DB81
P 8350 1700
F 0 "R?" H 8420 1746 50  0000 L CNN
F 1 "10K" H 8420 1655 50  0000 L CNN
F 2 "" V 8280 1700 50  0001 C CNN
F 3 "~" H 8350 1700 50  0001 C CNN
	1    8350 1700
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q?
U 1 1 5F7559A6
P 8450 2150
F 0 "Q?" H 8640 2196 50  0000 L CNN
F 1 "PN2222A" H 8640 2105 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8650 2075 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/PN2222-D.PDF" H 8450 2150 50  0001 L CNN
	1    8450 2150
	-1   0    0    -1  
$EndComp
$Comp
L power:+9V #PWR?
U 1 1 5F87AD8B
P 8350 1450
F 0 "#PWR?" H 8350 1300 50  0001 C CNN
F 1 "+9V" H 8365 1623 50  0000 C CNN
F 2 "" H 8350 1450 50  0001 C CNN
F 3 "" H 8350 1450 50  0001 C CNN
	1    8350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 4500 8400 4550
Connection ~ 8400 4500
Wire Wire Line
	8200 4500 8400 4500
Wire Wire Line
	8400 4050 8400 4150
Connection ~ 9200 4750
Wire Wire Line
	9300 4750 9200 4750
Wire Wire Line
	9200 4650 9200 4750
Wire Wire Line
	8800 4750 8700 4750
Wire Wire Line
	8400 4450 8400 4500
Wire Wire Line
	8400 4950 8400 5150
Wire Wire Line
	9200 4750 9100 4750
$Comp
L power:Earth #PWR?
U 1 1 5F880F51
P 8400 5150
F 0 "#PWR?" H 8400 4900 50  0001 C CNN
F 1 "Earth" H 8400 5000 50  0001 C CNN
F 2 "" H 8400 5150 50  0001 C CNN
F 3 "~" H 8400 5150 50  0001 C CNN
	1    8400 5150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F880F57
P 8950 4750
F 0 "R?" V 8743 4750 50  0000 C CNN
F 1 "330" V 8834 4750 50  0000 C CNN
F 2 "" V 8880 4750 50  0001 C CNN
F 3 "~" H 8950 4750 50  0001 C CNN
	1    8950 4750
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F880F5D
P 8400 4300
F 0 "R?" H 8470 4346 50  0000 L CNN
F 1 "10K" H 8470 4255 50  0000 L CNN
F 2 "" V 8330 4300 50  0001 C CNN
F 3 "~" H 8400 4300 50  0001 C CNN
	1    8400 4300
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q?
U 1 1 5F880F63
P 8500 4750
F 0 "Q?" H 8690 4796 50  0000 L CNN
F 1 "PN2222A" H 8690 4705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8700 4675 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/PN2222-D.PDF" H 8500 4750 50  0001 L CNN
	1    8500 4750
	-1   0    0    -1  
$EndComp
$Comp
L power:+9V #PWR?
U 1 1 5F880F69
P 8400 4050
F 0 "#PWR?" H 8400 3900 50  0001 C CNN
F 1 "+9V" H 8415 4223 50  0000 C CNN
F 2 "" H 8400 4050 50  0001 C CNN
F 3 "" H 8400 4050 50  0001 C CNN
	1    8400 4050
	1    0    0    -1  
$EndComp
Text GLabel 8200 4500 0    50   Input ~ 0
IN1
Text GLabel 9200 4650 1    50   Input ~ 0
IN2
Text GLabel 3750 4200 0    50   Output ~ 0
D12
Wire Wire Line
	3750 4200 3850 4200
Text GLabel 9300 4750 2    50   Input ~ 0
12
Wire Wire Line
	4900 1950 4900 2300
Wire Wire Line
	4900 2300 5050 2300
Text GLabel 4250 2450 1    50   Input ~ 0
5V
Wire Wire Line
	4250 2450 4250 2600
$Comp
L Device:CP C?
U 1 1 5F794C46
P 5050 2550
F 0 "C?" H 4850 2550 50  0000 L CNN
F 1 "47uF" H 4850 2450 50  0000 L CNN
F 2 "" H 5088 2400 50  0001 C CNN
F 3 "~" H 5050 2550 50  0001 C CNN
	1    5050 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5F795937
P 5750 2550
F 0 "C?" H 5868 2596 50  0000 L CNN
F 1 "10uF" H 5868 2505 50  0000 L CNN
F 2 "" H 5788 2400 50  0001 C CNN
F 3 "~" H 5750 2550 50  0001 C CNN
	1    5750 2550
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D?
U 1 1 5F797DAE
P 5400 1950
F 0 "D?" H 5400 2167 50  0000 C CNN
F 1 "1N4007" H 5400 2076 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 5400 1775 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 5400 1950 50  0001 C CNN
	1    5400 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1950 5050 1950
Wire Wire Line
	5550 1950 5750 1950
Wire Wire Line
	5050 2700 5050 2750
Wire Wire Line
	5050 2750 5400 2750
Connection ~ 5400 2750
Wire Wire Line
	5400 2750 5400 2600
Wire Wire Line
	5400 2750 5750 2750
Wire Wire Line
	5750 2750 5750 2700
Wire Wire Line
	5050 2400 5050 2300
Connection ~ 5050 2300
Wire Wire Line
	5050 2300 5100 2300
Wire Wire Line
	5750 2400 5750 2300
Connection ~ 5750 2300
Wire Wire Line
	5750 2300 5700 2300
Wire Wire Line
	5750 1950 5750 2300
Wire Wire Line
	5050 1950 5050 2300
Wire Wire Line
	5750 2300 5900 2300
Wire Wire Line
	6000 2300 6100 2300
$Comp
L power:Earth #PWR?
U 1 1 5F7B7EC9
P 4400 4750
F 0 "#PWR?" H 4400 4500 50  0001 C CNN
F 1 "Earth" H 4400 4600 50  0001 C CNN
F 2 "" H 4400 4750 50  0001 C CNN
F 3 "~" H 4400 4750 50  0001 C CNN
	1    4400 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 4600 4350 4650
Wire Wire Line
	4350 4650 4400 4650
Wire Wire Line
	4450 4650 4450 4600
Wire Wire Line
	4400 4750 4400 4650
Connection ~ 4400 4650
Wire Wire Line
	4400 4650 4450 4650
$Comp
L Connector:Conn_01x15_Female J?
U 1 1 5F7EF007
P 1950 3700
F 0 "J?" H 1842 4493 50  0000 C CNN
F 1 "Conn_01x15_Female" H 1842 4494 50  0001 C CNN
F 2 "" H 1950 3700 50  0001 C CNN
F 3 "~" H 1950 3700 50  0001 C CNN
	1    1950 3700
	-1   0    0    -1  
$EndComp
Text GLabel 3750 3000 0    50   Output ~ 0
RX
Wire Wire Line
	3750 3000 3850 3000
Text GLabel 3750 3100 0    50   Output ~ 0
TX
Wire Wire Line
	3750 3100 3850 3100
Text GLabel 3750 3200 0    50   Output ~ 0
D2
Wire Wire Line
	3750 3200 3850 3200
Text GLabel 3750 3300 0    50   Output ~ 0
D3
Wire Wire Line
	3750 3300 3850 3300
Text GLabel 3750 3400 0    50   Output ~ 0
D4
Wire Wire Line
	3750 3400 3850 3400
Text GLabel 3750 3500 0    50   Output ~ 0
D5
Wire Wire Line
	3750 3500 3850 3500
Text GLabel 3750 3600 0    50   Output ~ 0
D6
Wire Wire Line
	3750 3600 3850 3600
Text GLabel 3750 3700 0    50   Output ~ 0
D7
Wire Wire Line
	3750 3700 3850 3700
Text GLabel 3750 3800 0    50   Output ~ 0
D8
Wire Wire Line
	3750 3800 3850 3800
Text GLabel 3750 3900 0    50   Output ~ 0
D9
Wire Wire Line
	3750 3900 3850 3900
Text GLabel 3750 4000 0    50   Output ~ 0
D10
Wire Wire Line
	3750 4000 3850 4000
Text GLabel 3300 3000 2    50   Input ~ 0
RX
Wire Wire Line
	3300 3000 3200 3000
Text GLabel 3300 3100 2    50   Input ~ 0
TX
Wire Wire Line
	3300 3100 3200 3100
Text GLabel 3300 3300 2    50   Input ~ 0
D2
Wire Wire Line
	3300 3200 3200 3200
Text GLabel 3300 3400 2    50   Input ~ 0
D3
Wire Wire Line
	3300 3300 3200 3300
Text GLabel 3300 3500 2    50   Input ~ 0
D4
Wire Wire Line
	3300 3400 3200 3400
Text GLabel 3300 3600 2    50   Input ~ 0
D5
Wire Wire Line
	3300 3500 3200 3500
Text GLabel 3300 3700 2    50   Input ~ 0
D6
Wire Wire Line
	3300 3600 3200 3600
Text GLabel 3300 3800 2    50   Input ~ 0
D7
Wire Wire Line
	3300 3700 3200 3700
Text GLabel 3300 3900 2    50   Input ~ 0
D8
Wire Wire Line
	3300 3800 3200 3800
Text GLabel 3300 4000 2    50   Input ~ 0
D9
Wire Wire Line
	3300 3900 3200 3900
Text GLabel 3300 4100 2    50   Input ~ 0
D10
Wire Wire Line
	3300 4000 3200 4000
Text GLabel 3300 4200 2    50   Input ~ 0
D11
Wire Wire Line
	3300 4100 3200 4100
Text GLabel 3300 4300 2    50   Input ~ 0
D12
Wire Wire Line
	3300 4200 3200 4200
Text GLabel 3750 4300 0    50   Output ~ 0
D13
Wire Wire Line
	3750 4300 3850 4300
Text GLabel 3300 4400 2    50   Input ~ 0
D13
Wire Wire Line
	3300 4300 3200 4300
Text GLabel 4950 3100 2    50   Output ~ 0
RST
Wire Wire Line
	4950 3100 4850 3100
Text GLabel 3300 3200 2    50   Input ~ 0
RST
Wire Wire Line
	3200 4400 3300 4400
$Comp
L Connector:Conn_01x15_Female J?
U 1 1 5F8C06B6
P 2350 3700
F 0 "J?" H 2242 4493 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2242 4494 50  0001 C CNN
F 2 "" H 2350 3700 50  0001 C CNN
F 3 "~" H 2350 3700 50  0001 C CNN
	1    2350 3700
	-1   0    0    -1  
$EndComp
Text GLabel 2650 3000 2    50   Input ~ 0
RX
Wire Wire Line
	2650 3000 2550 3000
Text GLabel 2650 3100 2    50   Input ~ 0
TX
Wire Wire Line
	2650 3100 2550 3100
Text GLabel 2650 3300 2    50   Input ~ 0
D2
Wire Wire Line
	2650 3200 2550 3200
Text GLabel 2650 3400 2    50   Input ~ 0
D3
Wire Wire Line
	2650 3300 2550 3300
Text GLabel 2650 3500 2    50   Input ~ 0
D4
Wire Wire Line
	2650 3400 2550 3400
Text GLabel 2650 3600 2    50   Input ~ 0
D5
Wire Wire Line
	2650 3500 2550 3500
Text GLabel 2650 3700 2    50   Input ~ 0
D6
Wire Wire Line
	2650 3600 2550 3600
Text GLabel 2650 3800 2    50   Input ~ 0
D7
Wire Wire Line
	2650 3700 2550 3700
Text GLabel 2650 3900 2    50   Input ~ 0
D8
Wire Wire Line
	2650 3800 2550 3800
Text GLabel 2650 4000 2    50   Input ~ 0
D9
Wire Wire Line
	2650 3900 2550 3900
Wire Wire Line
	2650 4000 2550 4000
Wire Wire Line
	2650 4100 2550 4100
Wire Wire Line
	2650 4200 2550 4200
Text GLabel 2650 4400 2    50   Input ~ 0
D13
Wire Wire Line
	2650 4300 2550 4300
Text GLabel 2650 3200 2    50   Input ~ 0
RST
Wire Wire Line
	2550 4400 2650 4400
Text GLabel 2650 4300 2    50   Input ~ 0
D12
Text GLabel 2650 4200 2    50   Input ~ 0
D11
Text GLabel 2650 4100 2    50   Input ~ 0
D10
$Comp
L Connector:Conn_01x15_Female J?
U 1 1 5F7DAE2F
P 3000 3700
F 0 "J?" H 2892 4493 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2892 4494 50  0001 C CNN
F 2 "" H 3000 3700 50  0001 C CNN
F 3 "~" H 3000 3700 50  0001 C CNN
	1    3000 3700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2150 3000 2150 3100
Connection ~ 2150 3100
Wire Wire Line
	2150 3100 2150 3200
Connection ~ 2150 3200
Wire Wire Line
	2150 3200 2150 3300
Connection ~ 2150 3300
Wire Wire Line
	2150 3300 2150 3400
Connection ~ 2150 3400
Wire Wire Line
	2150 3400 2150 3500
Connection ~ 2150 3500
Wire Wire Line
	2150 3500 2150 3600
Connection ~ 2150 3600
Wire Wire Line
	2150 3600 2150 3700
Connection ~ 2150 3700
Wire Wire Line
	2150 3700 2150 3800
Connection ~ 2150 3800
Wire Wire Line
	2150 3800 2150 3900
Connection ~ 2150 3900
Wire Wire Line
	2150 3900 2150 4000
Connection ~ 2150 4000
Wire Wire Line
	2150 4000 2150 4100
Connection ~ 2150 4100
Wire Wire Line
	2150 4100 2150 4200
Connection ~ 2150 4200
Wire Wire Line
	2150 4200 2150 4300
Connection ~ 2150 4300
Wire Wire Line
	2150 4300 2150 4400
$Comp
L power:Earth #PWR?
U 1 1 5F90867D
P 2150 4550
F 0 "#PWR?" H 2150 4300 50  0001 C CNN
F 1 "Earth" H 2150 4400 50  0001 C CNN
F 2 "" H 2150 4550 50  0001 C CNN
F 3 "~" H 2150 4550 50  0001 C CNN
	1    2150 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 4550 2150 4400
Connection ~ 2150 4400
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 5F92A9B2
P 6400 1300
F 0 "J?" H 6480 1292 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6480 1201 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 6400 1300 50  0001 C CNN
F 3 "~" H 6400 1300 50  0001 C CNN
	1    6400 1300
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5F92D669
P 6150 1600
F 0 "#PWR?" H 6150 1350 50  0001 C CNN
F 1 "Earth" H 6150 1450 50  0001 C CNN
F 2 "" H 6150 1600 50  0001 C CNN
F 3 "~" H 6150 1600 50  0001 C CNN
	1    6150 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1400 6200 1400
$Comp
L power:+9V #PWR?
U 1 1 5F934D34
P 6150 1100
F 0 "#PWR?" H 6150 950 50  0001 C CNN
F 1 "+9V" H 6165 1273 50  0000 C CNN
F 2 "" H 6150 1100 50  0001 C CNN
F 3 "" H 6150 1100 50  0001 C CNN
	1    6150 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1300 6200 1300
Wire Wire Line
	7050 4650 7050 4500
$Comp
L power:Earth #PWR?
U 1 1 5F7A7077
P 7050 4650
F 0 "#PWR?" H 7050 4400 50  0001 C CNN
F 1 "Earth" H 7050 4500 50  0001 C CNN
F 2 "" H 7050 4650 50  0001 C CNN
F 3 "~" H 7050 4650 50  0001 C CNN
	1    7050 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1400 6150 1500
Wire Wire Line
	5750 1200 6150 1200
Wire Wire Line
	6150 1200 6150 1300
Wire Wire Line
	5750 1500 6150 1500
Connection ~ 6150 1500
Wire Wire Line
	6150 1500 6150 1600
Wire Wire Line
	6150 1100 6150 1200
Connection ~ 6150 1200
$Comp
L Connector:Conn_01x15_Female J?
U 1 1 5F9A5137
P 2900 1950
F 0 "J?" H 2900 2800 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2792 2744 50  0001 C CNN
F 2 "" H 2900 1950 50  0001 C CNN
F 3 "~" H 2900 1950 50  0001 C CNN
	1    2900 1950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3100 1250 3100 1350
Connection ~ 3100 1350
Wire Wire Line
	3100 1350 3100 1450
Connection ~ 3100 1450
Wire Wire Line
	3100 1450 3100 1550
Connection ~ 3100 1550
Wire Wire Line
	3100 1550 3100 1650
Connection ~ 3100 1650
Wire Wire Line
	3100 1650 3100 1750
Connection ~ 3100 1750
Wire Wire Line
	3100 1750 3100 1850
Connection ~ 3100 1850
Wire Wire Line
	3100 1850 3100 1950
Connection ~ 3100 1950
Wire Wire Line
	3100 1950 3100 2050
Connection ~ 3100 2050
Wire Wire Line
	3100 2050 3100 2150
Connection ~ 3100 2150
Wire Wire Line
	3100 2150 3100 2250
Connection ~ 3100 2250
Wire Wire Line
	3100 2250 3100 2350
Connection ~ 3100 2350
Wire Wire Line
	3100 2350 3100 2450
Connection ~ 3100 2450
Wire Wire Line
	3100 2450 3100 2550
Connection ~ 3100 2550
Wire Wire Line
	3100 2550 3100 2650
Text GLabel 3100 1150 1    50   Input ~ 0
5V
Wire Wire Line
	3100 1150 3100 1250
Connection ~ 3100 1250
$EndSCHEMATC