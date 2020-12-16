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
L Driver_Motor:L293D U2
U 1 1 5F78128C
P 7825 3850
F 0 "U2" H 7825 5031 50  0000 C CNN
F 1 "L293D" H 7925 4050 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 8075 3100 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/l293.pdf" H 7525 4550 50  0001 C CNN
	1    7825 3850
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5F78383F
P 3480 3870
F 0 "A1" H 3480 3270 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 3480 3770 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3480 3870 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3480 3870 50  0001 C CNN
	1    3480 3870
	1    0    0    -1  
$EndComp
Text GLabel 7175 3250 0    50   Output ~ 0
IN3
Text GLabel 7175 3450 0    50   Output ~ 0
IN4
$Comp
L power:+9V #PWR08
U 1 1 5F793BCF
P 7625 2100
F 0 "#PWR08" H 7625 1950 50  0001 C CNN
F 1 "+9V" H 7640 2273 50  0000 C CNN
F 2 "" H 7625 2100 50  0001 C CNN
F 3 "" H 7625 2100 50  0001 C CNN
	1    7625 2100
	1    0    0    -1  
$EndComp
Text GLabel 2880 4370 0    50   Output ~ 0
D11
Wire Wire Line
	2980 4370 2880 4370
$Comp
L Device:CP C2
U 1 1 5F7A5D36
P 5940 1540
F 0 "C2" H 6058 1586 50  0000 L CNN
F 1 "330uF" H 6058 1495 50  0000 L CNN
F 2 "" H 5978 1390 50  0001 C CNN
F 3 "~" H 5940 1540 50  0001 C CNN
	1    5940 1540
	1    0    0    -1  
$EndComp
Wire Wire Line
	7625 4650 7625 4750
Wire Wire Line
	7725 4750 7725 4650
Wire Wire Line
	7625 4750 7725 4750
Wire Wire Line
	7725 4750 7825 4750
Wire Wire Line
	8025 4750 8025 4650
Connection ~ 7725 4750
Wire Wire Line
	7925 4650 7925 4750
Connection ~ 7925 4750
Wire Wire Line
	7925 4750 8025 4750
Connection ~ 7825 4750
Wire Wire Line
	7825 4750 7925 4750
$Comp
L Switch:SW_SPDT SW1
U 1 1 5F7AEAC2
P 7625 2450
F 0 "SW1" V 7625 2300 50  0000 L CNN
F 1 "SW_SPDT" V 7925 2200 50  0001 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 7625 2450 50  0001 C CNN
F 3 "~" H 7625 2450 50  0001 C CNN
	1    7625 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	7725 2650 7725 2850
Wire Wire Line
	7625 2100 7625 2150
$Comp
L Diode:1N4001 D2
U 1 1 5F7B6481
P 7925 2150
F 0 "D2" H 7925 2367 50  0000 C CNN
F 1 "1N4001" H 7925 2276 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 7925 1975 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 7925 2150 50  0001 C CNN
	1    7925 2150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7775 2150 7625 2150
Connection ~ 7625 2150
Wire Wire Line
	7625 2150 7625 2250
$Comp
L power:Earth #PWR010
U 1 1 5F7B89BD
P 8225 2225
F 0 "#PWR010" H 8225 1975 50  0001 C CNN
F 1 "Earth" H 8225 2075 50  0001 C CNN
F 2 "" H 8225 2225 50  0001 C CNN
F 3 "~" H 8225 2225 50  0001 C CNN
	1    8225 2225
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U1
U 1 1 5F7C803E
P 4710 1555
F 0 "U1" H 4710 1797 50  0000 C CNN
F 1 "L7805" H 4710 1706 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin2" H 4735 1405 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 4710 1505 50  0001 C CNN
	1    4710 1555
	1    0    0    -1  
$EndComp
NoConn ~ 7525 2650
$Comp
L Device:R R1
U 1 1 5F7CA298
P 6675 3650
F 0 "R1" V 6468 3650 50  0000 C CNN
F 1 "100K" V 6559 3650 50  0000 C CNN
F 2 "" V 6605 3650 50  0001 C CNN
F 3 "~" H 6675 3650 50  0001 C CNN
	1    6675 3650
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5F7CB336
P 6675 4250
F 0 "R2" V 6468 4250 50  0000 C CNN
F 1 "100K" V 6559 4250 50  0000 C CNN
F 2 "" V 6605 4250 50  0001 C CNN
F 3 "~" H 6675 4250 50  0001 C CNN
	1    6675 4250
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR05
U 1 1 5F7CCC0C
P 6375 4550
F 0 "#PWR05" H 6375 4300 50  0001 C CNN
F 1 "Earth" H 6375 4400 50  0001 C CNN
F 2 "" H 6375 4550 50  0001 C CNN
F 3 "~" H 6375 4550 50  0001 C CNN
	1    6375 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6375 4550 6375 4250
Wire Wire Line
	6375 3650 6525 3650
Wire Wire Line
	6525 4250 6375 4250
Connection ~ 6375 4250
Wire Wire Line
	6375 4250 6375 3650
$Comp
L Connector:Screw_Terminal_01x02 J8
U 1 1 5F806128
P 8675 3900
F 0 "J8" H 8755 3892 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8755 3801 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 8675 3900 50  0001 C CNN
F 3 "~" H 8675 3900 50  0001 C CNN
	1    8675 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8325 3850 8475 3850
Wire Wire Line
	8475 3850 8475 3900
Wire Wire Line
	8325 4050 8475 4050
Wire Wire Line
	8475 4050 8475 4000
Wire Wire Line
	7175 3250 7325 3250
Wire Wire Line
	6825 3650 7325 3650
Wire Wire Line
	6825 4250 7325 4250
Wire Wire Line
	7175 3450 7325 3450
Wire Wire Line
	8325 3250 8475 3250
Wire Wire Line
	8475 3250 8475 3300
Wire Wire Line
	8325 3450 8475 3450
Wire Wire Line
	8475 3450 8475 3400
$Comp
L Connector:Conn_01x02_Female J5
U 1 1 5F84921C
P 5210 1355
F 0 "J5" V 5310 1355 50  0000 R CNN
F 1 "Conn_01x02_Female" V 5310 1505 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5210 1355 50  0001 C CNN
F 3 "~" H 5210 1355 50  0001 C CNN
	1    5210 1355
	0    -1   -1   0   
$EndComp
Text GLabel 7925 2750 1    50   Input ~ 0
5V
Wire Wire Line
	7925 2750 7925 2850
$Comp
L power:Earth #PWR04
U 1 1 5F84F4BF
P 4710 2055
F 0 "#PWR04" H 4710 1805 50  0001 C CNN
F 1 "Earth" H 4710 1905 50  0001 C CNN
F 2 "" H 4710 2055 50  0001 C CNN
F 3 "~" H 4710 2055 50  0001 C CNN
	1    4710 2055
	1    0    0    -1  
$EndComp
Wire Wire Line
	4710 2055 4710 2005
$Comp
L power:+9V #PWR03
U 1 1 5F851F48
P 4210 1205
F 0 "#PWR03" H 4210 1055 50  0001 C CNN
F 1 "+9V" H 4225 1378 50  0000 C CNN
F 2 "" H 4210 1205 50  0001 C CNN
F 3 "" H 4210 1205 50  0001 C CNN
	1    4210 1205
	1    0    0    -1  
$EndComp
Text GLabel 7175 4050 0    50   Output ~ 0
IN2
Wire Wire Line
	7175 4050 7325 4050
Text GLabel 7175 3850 0    50   Output ~ 0
IN1
Wire Wire Line
	7175 3850 7325 3850
$Comp
L Connector:Screw_Terminal_01x02 J7
U 1 1 5F8298E7
P 8675 3300
F 0 "J7" H 8755 3292 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8755 3201 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 8675 3300 50  0001 C CNN
F 3 "~" H 8675 3300 50  0001 C CNN
	1    8675 3300
	1    0    0    -1  
$EndComp
Text GLabel 10070 2405 2    50   Input ~ 0
11
Wire Wire Line
	9170 2155 9170 2205
Connection ~ 9170 2155
Wire Wire Line
	8970 2155 9170 2155
Wire Wire Line
	9170 1705 9170 1805
Connection ~ 9970 2405
Wire Wire Line
	10070 2405 9970 2405
Wire Wire Line
	9970 2305 9970 2405
Wire Wire Line
	9570 2405 9470 2405
Text GLabel 8970 2155 0    50   Input ~ 0
IN4
Text GLabel 9970 2305 1    50   Input ~ 0
IN3
Wire Wire Line
	9170 2105 9170 2155
Wire Wire Line
	9170 2605 9170 2805
Wire Wire Line
	9970 2405 9870 2405
$Comp
L power:Earth #PWR012
U 1 1 5F7801C1
P 9170 2805
F 0 "#PWR012" H 9170 2555 50  0001 C CNN
F 1 "Earth" H 9170 2655 50  0001 C CNN
F 2 "" H 9170 2805 50  0001 C CNN
F 3 "~" H 9170 2805 50  0001 C CNN
	1    9170 2805
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F77EB8E
P 9720 2405
F 0 "R5" V 9513 2405 50  0000 C CNN
F 1 "330" V 9604 2405 50  0000 C CNN
F 2 "" V 9650 2405 50  0001 C CNN
F 3 "~" H 9720 2405 50  0001 C CNN
	1    9720 2405
	0    -1   1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5F77DB81
P 9170 1955
F 0 "R3" H 9240 2001 50  0000 L CNN
F 1 "10K" H 9240 1910 50  0000 L CNN
F 2 "" V 9100 1955 50  0001 C CNN
F 3 "~" H 9170 1955 50  0001 C CNN
	1    9170 1955
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q1
U 1 1 5F7559A6
P 9270 2405
F 0 "Q1" H 9460 2451 50  0000 L CNN
F 1 "PN2222A" H 9460 2360 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9470 2330 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/PN2222-D.PDF" H 9270 2405 50  0001 L CNN
	1    9270 2405
	-1   0    0    -1  
$EndComp
$Comp
L power:+9V #PWR011
U 1 1 5F87AD8B
P 9170 1705
F 0 "#PWR011" H 9170 1555 50  0001 C CNN
F 1 "+9V" H 9185 1878 50  0000 C CNN
F 2 "" H 9170 1705 50  0001 C CNN
F 3 "" H 9170 1705 50  0001 C CNN
	1    9170 1705
	1    0    0    -1  
$EndComp
Wire Wire Line
	9175 4750 9175 4800
Connection ~ 9175 4750
Wire Wire Line
	8975 4750 9175 4750
Wire Wire Line
	9175 4300 9175 4400
Connection ~ 9975 5000
Wire Wire Line
	10075 5000 9975 5000
Wire Wire Line
	9975 4900 9975 5000
Wire Wire Line
	9575 5000 9475 5000
Wire Wire Line
	9175 4700 9175 4750
Wire Wire Line
	9175 5200 9175 5400
Wire Wire Line
	9975 5000 9875 5000
$Comp
L power:Earth #PWR014
U 1 1 5F880F51
P 9175 5400
F 0 "#PWR014" H 9175 5150 50  0001 C CNN
F 1 "Earth" H 9175 5250 50  0001 C CNN
F 2 "" H 9175 5400 50  0001 C CNN
F 3 "~" H 9175 5400 50  0001 C CNN
	1    9175 5400
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5F880F57
P 9725 5000
F 0 "R6" V 9518 5000 50  0000 C CNN
F 1 "330" V 9609 5000 50  0000 C CNN
F 2 "" V 9655 5000 50  0001 C CNN
F 3 "~" H 9725 5000 50  0001 C CNN
	1    9725 5000
	0    -1   1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5F880F5D
P 9175 4550
F 0 "R4" H 9245 4596 50  0000 L CNN
F 1 "10K" H 9245 4505 50  0000 L CNN
F 2 "" V 9105 4550 50  0001 C CNN
F 3 "~" H 9175 4550 50  0001 C CNN
	1    9175 4550
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q2
U 1 1 5F880F63
P 9275 5000
F 0 "Q2" H 9465 5046 50  0000 L CNN
F 1 "PN2222A" H 9465 4955 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9475 4925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/PN2222-D.PDF" H 9275 5000 50  0001 L CNN
	1    9275 5000
	-1   0    0    -1  
$EndComp
$Comp
L power:+9V #PWR013
U 1 1 5F880F69
P 9175 4300
F 0 "#PWR013" H 9175 4150 50  0001 C CNN
F 1 "+9V" H 9190 4473 50  0000 C CNN
F 2 "" H 9175 4300 50  0001 C CNN
F 3 "" H 9175 4300 50  0001 C CNN
	1    9175 4300
	1    0    0    -1  
$EndComp
Text GLabel 8975 4750 0    50   Input ~ 0
IN1
Text GLabel 9975 4900 1    50   Input ~ 0
IN2
Text GLabel 2880 4470 0    50   Output ~ 0
D12
Wire Wire Line
	2880 4470 2980 4470
Text GLabel 10075 5000 2    50   Input ~ 0
12
Wire Wire Line
	4210 1205 4210 1555
Wire Wire Line
	4210 1555 4360 1555
$Comp
L Device:CP C1
U 1 1 5F794C46
P 4360 1805
F 0 "C1" H 4160 1805 50  0000 L CNN
F 1 "47uF" H 4160 1705 50  0000 L CNN
F 2 "" H 4398 1655 50  0001 C CNN
F 3 "~" H 4360 1805 50  0001 C CNN
	1    4360 1805
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5F795937
P 5060 1805
F 0 "C3" H 5178 1851 50  0000 L CNN
F 1 "10uF" H 5178 1760 50  0000 L CNN
F 2 "" H 5098 1655 50  0001 C CNN
F 3 "~" H 5060 1805 50  0001 C CNN
	1    5060 1805
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D1
U 1 1 5F797DAE
P 4710 1205
F 0 "D1" H 4710 1422 50  0000 C CNN
F 1 "1N4007" H 4710 1331 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 4710 1030 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 4710 1205 50  0001 C CNN
	1    4710 1205
	1    0    0    -1  
$EndComp
Wire Wire Line
	4560 1205 4360 1205
Wire Wire Line
	4860 1205 5060 1205
Wire Wire Line
	4360 1955 4360 2005
Wire Wire Line
	4360 2005 4710 2005
Connection ~ 4710 2005
Wire Wire Line
	4710 2005 4710 1855
Wire Wire Line
	4710 2005 5060 2005
Wire Wire Line
	5060 2005 5060 1955
Wire Wire Line
	4360 1655 4360 1555
Connection ~ 4360 1555
Wire Wire Line
	4360 1555 4410 1555
Wire Wire Line
	5060 1655 5060 1555
Connection ~ 5060 1555
Wire Wire Line
	5060 1555 5010 1555
Wire Wire Line
	5060 1205 5060 1555
Wire Wire Line
	4360 1205 4360 1555
Wire Wire Line
	5060 1555 5210 1555
Wire Wire Line
	5310 1555 5410 1555
$Comp
L power:Earth #PWR02
U 1 1 5F7B7EC9
P 3530 5020
F 0 "#PWR02" H 3530 4770 50  0001 C CNN
F 1 "Earth" H 3530 4870 50  0001 C CNN
F 2 "" H 3530 5020 50  0001 C CNN
F 3 "~" H 3530 5020 50  0001 C CNN
	1    3530 5020
	1    0    0    -1  
$EndComp
Wire Wire Line
	3480 4870 3480 4920
Wire Wire Line
	3480 4920 3530 4920
Wire Wire Line
	3580 4920 3580 4870
Wire Wire Line
	3530 5020 3530 4920
Connection ~ 3530 4920
Wire Wire Line
	3530 4920 3580 4920
$Comp
L Connector:Conn_01x15_Female J1
U 1 1 5F7EF007
P 2725 6150
F 0 "J1" H 2617 6943 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2617 6944 50  0001 C CNN
F 2 "" H 2725 6150 50  0001 C CNN
F 3 "~" H 2725 6150 50  0001 C CNN
	1    2725 6150
	-1   0    0    -1  
$EndComp
Text GLabel 2880 3270 0    50   Output ~ 0
RX
Wire Wire Line
	2880 3270 2980 3270
Text GLabel 2880 3370 0    50   Output ~ 0
TX
Wire Wire Line
	2880 3370 2980 3370
Text GLabel 2880 3470 0    50   Output ~ 0
D2
Wire Wire Line
	2880 3470 2980 3470
Text GLabel 2880 3570 0    50   Output ~ 0
D3
Wire Wire Line
	2880 3570 2980 3570
Text GLabel 2880 3670 0    50   Output ~ 0
D4
Wire Wire Line
	2880 3670 2980 3670
Text GLabel 2880 3770 0    50   Output ~ 0
D5
Wire Wire Line
	2880 3770 2980 3770
Text GLabel 2880 3870 0    50   Output ~ 0
D6
Wire Wire Line
	2880 3870 2980 3870
Text GLabel 2880 3970 0    50   Output ~ 0
D7
Wire Wire Line
	2880 3970 2980 3970
Text GLabel 2880 4070 0    50   Output ~ 0
D8
Wire Wire Line
	2880 4070 2980 4070
Text GLabel 2880 4170 0    50   Output ~ 0
D9
Wire Wire Line
	2880 4170 2980 4170
Text GLabel 2880 4270 0    50   Output ~ 0
D10
Wire Wire Line
	2880 4270 2980 4270
Text GLabel 2330 3270 2    50   Input ~ 0
RX
Wire Wire Line
	2330 3170 2230 3170
Text GLabel 2330 3170 2    50   Input ~ 0
TX
Wire Wire Line
	2330 3270 2230 3270
Text GLabel 2330 3570 2    50   Input ~ 0
D2
Wire Wire Line
	2330 3370 2230 3370
Text GLabel 2330 3670 2    50   Input ~ 0
D3
Text GLabel 2330 3770 2    50   Input ~ 0
D4
Wire Wire Line
	2330 3570 2230 3570
Text GLabel 2330 3870 2    50   Input ~ 0
D5
Wire Wire Line
	2330 3670 2230 3670
Text GLabel 2330 3970 2    50   Input ~ 0
D6
Wire Wire Line
	2330 3770 2230 3770
Text GLabel 2330 4070 2    50   Input ~ 0
D7
Wire Wire Line
	2330 3870 2230 3870
Text GLabel 2330 4170 2    50   Input ~ 0
D8
Wire Wire Line
	2330 3970 2230 3970
Text GLabel 2330 4270 2    50   Input ~ 0
D9
Wire Wire Line
	2330 4070 2230 4070
Text GLabel 2330 4370 2    50   Input ~ 0
D10
Wire Wire Line
	2330 4170 2230 4170
Text GLabel 2330 4470 2    50   Input ~ 0
D11
Wire Wire Line
	2330 4270 2230 4270
Text GLabel 2330 4570 2    50   Input ~ 0
D12
Wire Wire Line
	2330 4370 2230 4370
Text GLabel 2880 4570 0    50   Output ~ 0
D13
Wire Wire Line
	2880 4570 2980 4570
Text GLabel 4780 4570 0    50   Input ~ 0
D13
Wire Wire Line
	2330 4470 2230 4470
Text GLabel 4080 3370 2    50   Output ~ 0
RST
Wire Wire Line
	4080 3370 3980 3370
Wire Wire Line
	2230 4570 2330 4570
$Comp
L Connector:Conn_01x15_Female J2
U 1 1 5F8C06B6
P 1380 3870
F 0 "J2" H 1272 4663 50  0000 C CNN
F 1 "Conn_01x15_Female" H 1272 4664 50  0001 C CNN
F 2 "" H 1380 3870 50  0001 C CNN
F 3 "~" H 1380 3870 50  0001 C CNN
	1    1380 3870
	-1   0    0    -1  
$EndComp
Text GLabel 1680 3270 2    50   Input ~ 0
RX
Wire Wire Line
	1680 3170 1580 3170
Text GLabel 1680 3170 2    50   Input ~ 0
TX
Wire Wire Line
	1680 3270 1580 3270
Text GLabel 1680 3570 2    50   Input ~ 0
D2
Wire Wire Line
	1680 3370 1580 3370
Text GLabel 1680 3670 2    50   Input ~ 0
D3
Text GLabel 1680 3770 2    50   Input ~ 0
D4
Wire Wire Line
	1680 3570 1580 3570
Text GLabel 1680 3870 2    50   Input ~ 0
D5
Wire Wire Line
	1680 3670 1580 3670
Text GLabel 1680 3970 2    50   Input ~ 0
D6
Wire Wire Line
	1680 3770 1580 3770
Text GLabel 1680 4070 2    50   Input ~ 0
D7
Wire Wire Line
	1680 3870 1580 3870
Text GLabel 1680 4170 2    50   Input ~ 0
D8
Wire Wire Line
	1680 3970 1580 3970
Text GLabel 1680 4270 2    50   Input ~ 0
D9
Wire Wire Line
	1680 4070 1580 4070
Wire Wire Line
	1680 4170 1580 4170
Wire Wire Line
	1680 4270 1580 4270
Wire Wire Line
	1680 4370 1580 4370
Wire Wire Line
	1680 4470 1580 4470
Text GLabel 1680 3370 2    50   Input ~ 0
RST
Wire Wire Line
	1580 4570 1680 4570
Text GLabel 1680 4570 2    50   Input ~ 0
D12
Text GLabel 1680 4470 2    50   Input ~ 0
D11
Text GLabel 1680 4370 2    50   Input ~ 0
D10
$Comp
L Connector:Conn_01x15_Female J4
U 1 1 5F7DAE2F
P 2030 3870
F 0 "J4" H 1922 4663 50  0000 C CNN
F 1 "Conn_01x15_Female" H 1922 4664 50  0001 C CNN
F 2 "" H 2030 3870 50  0001 C CNN
F 3 "~" H 2030 3870 50  0001 C CNN
	1    2030 3870
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2925 5450 2925 5550
Connection ~ 2925 5550
Wire Wire Line
	2925 5550 2925 5650
Connection ~ 2925 5650
Wire Wire Line
	2925 5650 2925 5750
Connection ~ 2925 5750
Wire Wire Line
	2925 5750 2925 5850
Connection ~ 2925 5850
Wire Wire Line
	2925 5850 2925 5950
Connection ~ 2925 5950
Wire Wire Line
	2925 5950 2925 6050
Connection ~ 2925 6050
Wire Wire Line
	2925 6050 2925 6150
Connection ~ 2925 6150
Wire Wire Line
	2925 6150 2925 6250
Connection ~ 2925 6250
Wire Wire Line
	2925 6250 2925 6350
Connection ~ 2925 6350
Wire Wire Line
	2925 6350 2925 6450
Connection ~ 2925 6450
Wire Wire Line
	2925 6450 2925 6550
Connection ~ 2925 6550
Wire Wire Line
	2925 6550 2925 6650
Connection ~ 2925 6650
Wire Wire Line
	2925 6650 2925 6750
Connection ~ 2925 6750
Wire Wire Line
	2925 6750 2925 6850
$Comp
L power:Earth #PWR01
U 1 1 5F90867D
P 2925 7000
F 0 "#PWR01" H 2925 6750 50  0001 C CNN
F 1 "Earth" H 2925 6850 50  0001 C CNN
F 2 "" H 2925 7000 50  0001 C CNN
F 3 "~" H 2925 7000 50  0001 C CNN
	1    2925 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2925 7000 2925 6850
Connection ~ 2925 6850
$Comp
L Connector:Screw_Terminal_01x02 J6
U 1 1 5F92A9B2
P 6590 1490
F 0 "J6" H 6670 1482 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6670 1391 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 6590 1490 50  0001 C CNN
F 3 "~" H 6590 1490 50  0001 C CNN
	1    6590 1490
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR07
U 1 1 5F92D669
P 6340 1790
F 0 "#PWR07" H 6340 1540 50  0001 C CNN
F 1 "Earth" H 6340 1640 50  0001 C CNN
F 2 "" H 6340 1790 50  0001 C CNN
F 3 "~" H 6340 1790 50  0001 C CNN
	1    6340 1790
	1    0    0    -1  
$EndComp
Wire Wire Line
	6340 1590 6390 1590
$Comp
L power:+9V #PWR06
U 1 1 5F934D34
P 6340 1290
F 0 "#PWR06" H 6340 1140 50  0001 C CNN
F 1 "+9V" H 6355 1463 50  0000 C CNN
F 2 "" H 6340 1290 50  0001 C CNN
F 3 "" H 6340 1290 50  0001 C CNN
	1    6340 1290
	1    0    0    -1  
$EndComp
Wire Wire Line
	6340 1490 6390 1490
Wire Wire Line
	7825 4900 7825 4750
$Comp
L power:Earth #PWR09
U 1 1 5F7A7077
P 7825 4900
F 0 "#PWR09" H 7825 4650 50  0001 C CNN
F 1 "Earth" H 7825 4750 50  0001 C CNN
F 2 "" H 7825 4900 50  0001 C CNN
F 3 "~" H 7825 4900 50  0001 C CNN
	1    7825 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6340 1590 6340 1690
Wire Wire Line
	5940 1390 6340 1390
Wire Wire Line
	6340 1390 6340 1490
Wire Wire Line
	5940 1690 6340 1690
Connection ~ 6340 1690
Wire Wire Line
	6340 1690 6340 1790
Wire Wire Line
	6340 1290 6340 1390
Connection ~ 6340 1390
$Comp
L Connector:Conn_01x15_Female J3
U 1 1 5F9A5137
P 3140 6145
F 0 "J3" H 3140 6995 50  0000 C CNN
F 1 "Conn_01x15_Female" H 3032 6939 50  0001 C CNN
F 2 "" H 3140 6145 50  0001 C CNN
F 3 "~" H 3140 6145 50  0001 C CNN
	1    3140 6145
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3340 5445 3340 5545
Connection ~ 3340 5545
Wire Wire Line
	3340 5545 3340 5645
Connection ~ 3340 5645
Wire Wire Line
	3340 5645 3340 5745
Connection ~ 3340 5745
Wire Wire Line
	3340 5745 3340 5845
Connection ~ 3340 5845
Wire Wire Line
	3340 5845 3340 5945
Connection ~ 3340 5945
Wire Wire Line
	3340 5945 3340 6045
Connection ~ 3340 6045
Wire Wire Line
	3340 6045 3340 6145
Connection ~ 3340 6145
Wire Wire Line
	3340 6145 3340 6245
Connection ~ 3340 6245
Wire Wire Line
	3340 6245 3340 6345
Connection ~ 3340 6345
Wire Wire Line
	3340 6345 3340 6445
Connection ~ 3340 6445
Wire Wire Line
	3340 6445 3340 6545
Connection ~ 3340 6545
Wire Wire Line
	3340 6545 3340 6645
Connection ~ 3340 6645
Wire Wire Line
	3340 6645 3340 6745
Connection ~ 3340 6745
Wire Wire Line
	3340 6745 3340 6845
Text GLabel 3340 5345 1    50   Input ~ 0
5V
Wire Wire Line
	3340 5345 3340 5445
Connection ~ 3340 5445
$Comp
L Connector:Conn_01x15_Female J9
U 1 1 5FE4B216
P 5105 3870
F 0 "J9" H 5133 3850 50  0000 L CNN
F 1 "Conn_01x15_Female" H 5133 3805 50  0001 L CNN
F 2 "" H 5105 3870 50  0001 C CNN
F 3 "~" H 5105 3870 50  0001 C CNN
	1    5105 3870
	1    0    0    -1  
$EndComp
Text GLabel 2330 3370 2    50   Input ~ 0
RST
$Comp
L power:Earth #PWR016
U 1 1 5FF49C9A
P 2580 3545
F 0 "#PWR016" H 2580 3295 50  0001 C CNN
F 1 "Earth" H 2580 3395 50  0001 C CNN
F 2 "" H 2580 3545 50  0001 C CNN
F 3 "~" H 2580 3545 50  0001 C CNN
	1    2580 3545
	1    0    0    -1  
$EndComp
Wire Wire Line
	2580 3545 2580 3470
Wire Wire Line
	2230 3470 2580 3470
Wire Wire Line
	4905 4570 4780 4570
$Comp
L power:Earth #PWR015
U 1 1 5FF7A5A6
P 1930 3545
F 0 "#PWR015" H 1930 3295 50  0001 C CNN
F 1 "Earth" H 1930 3395 50  0001 C CNN
F 2 "" H 1930 3545 50  0001 C CNN
F 3 "~" H 1930 3545 50  0001 C CNN
	1    1930 3545
	1    0    0    -1  
$EndComp
Wire Wire Line
	1930 3545 1930 3470
Wire Wire Line
	1580 3470 1930 3470
Wire Wire Line
	4080 4570 3980 4570
Wire Wire Line
	3980 4470 4080 4470
Wire Wire Line
	3980 4370 4080 4370
Wire Wire Line
	3980 4270 4080 4270
Wire Wire Line
	3980 4170 4080 4170
Wire Wire Line
	3980 4070 4080 4070
Wire Wire Line
	3980 3970 4080 3970
Wire Wire Line
	3980 3870 4080 3870
Wire Wire Line
	4080 3670 3980 3670
Text GLabel 4080 3270 2    50   Output ~ 0
RST
Wire Wire Line
	4080 3270 3980 3270
Text GLabel 4080 3670 2    50   Output ~ 0
AREF
Text GLabel 4080 3870 2    50   Output ~ 0
A0
Text GLabel 4080 3970 2    50   Output ~ 0
A1
Text GLabel 4080 4070 2    50   Output ~ 0
A2
Text GLabel 4080 4170 2    50   Output ~ 0
A3
Text GLabel 4080 4270 2    50   Output ~ 0
A4
Text GLabel 4080 4370 2    50   Output ~ 0
A5
Text GLabel 4080 4470 2    50   Output ~ 0
A6
Text GLabel 4080 4570 2    50   Output ~ 0
A7
Text GLabel 3580 2760 1    50   Output ~ 0
3V3
Wire Wire Line
	3580 2760 3580 2870
Text GLabel 3680 2760 1    50   Output ~ 0
5V
Wire Wire Line
	3680 2760 3680 2870
Text GLabel 4773 4470 0    50   Input ~ 0
3V3
Wire Wire Line
	4905 4470 4773 4470
Text GLabel 4815 4370 0    50   Input ~ 0
AREF
Wire Wire Line
	4815 4370 4905 4370
Text GLabel 4725 4270 0    50   Input ~ 0
A0
Wire Wire Line
	4725 4270 4905 4270
Text GLabel 4725 4170 0    50   Input ~ 0
A1
Wire Wire Line
	4725 4170 4905 4170
Text GLabel 4725 4070 0    50   Input ~ 0
A2
Wire Wire Line
	4725 4070 4905 4070
Text GLabel 4725 3970 0    50   Input ~ 0
A3
Wire Wire Line
	4725 3970 4905 3970
Text GLabel 4725 3870 0    50   Input ~ 0
A4
Wire Wire Line
	4725 3870 4905 3870
Text GLabel 4725 3770 0    50   Input ~ 0
A5
Wire Wire Line
	4725 3770 4905 3770
Text GLabel 4725 3670 0    50   Input ~ 0
A6
Wire Wire Line
	4725 3670 4905 3670
Text GLabel 4725 3570 0    50   Input ~ 0
A7
Wire Wire Line
	4725 3570 4905 3570
Text GLabel 4725 3470 0    50   Input ~ 0
5V
Wire Wire Line
	4725 3470 4905 3470
Text GLabel 4770 3370 0    50   Input ~ 0
RST
Wire Wire Line
	4770 3370 4905 3370
$Comp
L power:Earth #PWR017
U 1 1 600F6A9B
P 4455 3370
F 0 "#PWR017" H 4455 3120 50  0001 C CNN
F 1 "Earth" H 4455 3220 50  0001 C CNN
F 2 "" H 4455 3370 50  0001 C CNN
F 3 "~" H 4455 3370 50  0001 C CNN
	1    4455 3370
	1    0    0    -1  
$EndComp
Wire Wire Line
	4905 3270 4455 3270
Wire Wire Line
	4455 3270 4455 3370
Text GLabel 5410 1555 2    50   Output ~ 0
VIN
Text GLabel 3380 2760 1    50   Input ~ 0
VIN
Wire Wire Line
	3380 2870 3380 2760
Text GLabel 4750 3170 0    50   Input ~ 0
VIN
Wire Wire Line
	4750 3170 4905 3170
Text GLabel 5625 4570 0    50   Input ~ 0
D13
$Comp
L Connector:Conn_01x15_Female J10
U 1 1 601BB451
P 5950 3870
F 0 "J10" H 5978 3850 50  0000 L CNN
F 1 "Conn_01x15_Female" H 5978 3805 50  0001 L CNN
F 2 "" H 5950 3870 50  0001 C CNN
F 3 "~" H 5950 3870 50  0001 C CNN
	1    5950 3870
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4570 5625 4570
Text GLabel 5618 4470 0    50   Input ~ 0
3V3
Wire Wire Line
	5750 4470 5618 4470
Text GLabel 5660 4370 0    50   Input ~ 0
AREF
Wire Wire Line
	5660 4370 5750 4370
Text GLabel 5570 4270 0    50   Input ~ 0
A0
Wire Wire Line
	5570 4270 5750 4270
Text GLabel 5570 4170 0    50   Input ~ 0
A1
Wire Wire Line
	5570 4170 5750 4170
Text GLabel 5570 4070 0    50   Input ~ 0
A2
Wire Wire Line
	5570 4070 5750 4070
Text GLabel 5570 3970 0    50   Input ~ 0
A3
Wire Wire Line
	5570 3970 5750 3970
Text GLabel 5570 3870 0    50   Input ~ 0
A4
Wire Wire Line
	5570 3870 5750 3870
Text GLabel 5570 3770 0    50   Input ~ 0
A5
Wire Wire Line
	5570 3770 5750 3770
Text GLabel 5570 3670 0    50   Input ~ 0
A6
Wire Wire Line
	5570 3670 5750 3670
Text GLabel 5570 3570 0    50   Input ~ 0
A7
Wire Wire Line
	5570 3570 5750 3570
Text GLabel 5570 3470 0    50   Input ~ 0
5V
Wire Wire Line
	5570 3470 5750 3470
Text GLabel 5615 3370 0    50   Input ~ 0
RST
Wire Wire Line
	5615 3370 5750 3370
$Comp
L power:Earth #PWR018
U 1 1 601BB471
P 5300 3370
F 0 "#PWR018" H 5300 3120 50  0001 C CNN
F 1 "Earth" H 5300 3220 50  0001 C CNN
F 2 "" H 5300 3370 50  0001 C CNN
F 3 "~" H 5300 3370 50  0001 C CNN
	1    5300 3370
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3270 5300 3270
Wire Wire Line
	5300 3270 5300 3370
Text GLabel 5595 3170 0    50   Input ~ 0
VIN
Wire Wire Line
	5595 3170 5750 3170
Wire Wire Line
	8075 2150 8225 2150
Wire Wire Line
	8225 2150 8225 2225
$EndSCHEMATC
