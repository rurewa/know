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
P 5280 6275
F 0 "U2" H 5360 6365 50  0000 C CNN
F 1 "L293D" H 5380 6475 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5530 5525 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/l293.pdf" H 4980 6975 50  0001 C CNN
	1    5280 6275
	1    0    0    -1  
$EndComp
Text GLabel 4630 5675 0    50   Output ~ 0
IN3
Text GLabel 4630 5875 0    50   Output ~ 0
IN4
Text GLabel 7860 3140 0    50   Output ~ 0
D11
Wire Wire Line
	7960 3140 7860 3140
$Comp
L Device:CP C3
U 1 1 5F7A5D36
P 4635 2470
F 0 "C3" H 4445 2560 50  0000 L CNN
F 1 "330uF" H 4305 2470 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 4673 2320 50  0001 C CNN
F 3 "~" H 4635 2470 50  0001 C CNN
	1    4635 2470
	1    0    0    -1  
$EndComp
Wire Wire Line
	5080 7075 5080 7175
Wire Wire Line
	5180 7175 5180 7075
Wire Wire Line
	5080 7175 5180 7175
Wire Wire Line
	5180 7175 5280 7175
Wire Wire Line
	5480 7175 5480 7075
Connection ~ 5180 7175
Wire Wire Line
	5380 7075 5380 7175
Connection ~ 5380 7175
Wire Wire Line
	5380 7175 5480 7175
Connection ~ 5280 7175
Wire Wire Line
	5280 7175 5380 7175
$Comp
L Diode:1N4001 D2
U 1 1 5F7B6481
P 4365 2240
F 0 "D2" H 4365 2457 50  0000 C CNN
F 1 "1N4001" H 4365 2366 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 4365 2065 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 4365 2240 50  0001 C CNN
	1    4365 2240
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U1
U 1 1 5F7C803E
P 2590 2395
F 0 "U1" H 2590 2637 50  0000 C CNN
F 1 "L7805" H 2590 2546 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin2" H 2615 2245 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2590 2345 50  0001 C CNN
	1    2590 2395
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F7CA298
P 4130 6075
F 0 "R1" V 3923 6075 50  0000 C CNN
F 1 "100K" V 4014 6075 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4060 6075 50  0001 C CNN
F 3 "~" H 4130 6075 50  0001 C CNN
	1    4130 6075
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5F7CB336
P 4130 6675
F 0 "R2" V 3923 6675 50  0000 C CNN
F 1 "100K" V 4014 6675 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4060 6675 50  0001 C CNN
F 3 "~" H 4130 6675 50  0001 C CNN
	1    4130 6675
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR010
U 1 1 5F7CCC0C
P 3830 6975
F 0 "#PWR010" H 3830 6725 50  0001 C CNN
F 1 "Earth" H 3830 6825 50  0001 C CNN
F 2 "" H 3830 6975 50  0001 C CNN
F 3 "~" H 3830 6975 50  0001 C CNN
	1    3830 6975
	1    0    0    -1  
$EndComp
Wire Wire Line
	3830 6975 3830 6675
Wire Wire Line
	3830 6075 3980 6075
Wire Wire Line
	3980 6675 3830 6675
Connection ~ 3830 6675
Wire Wire Line
	3830 6675 3830 6075
$Comp
L Connector:Screw_Terminal_01x02 J10
U 1 1 5F806128
P 6130 6325
F 0 "J10" H 6210 6317 50  0000 L CNN
F 1 "M1" H 6210 6226 50  0000 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 6130 6325 50  0001 C CNN
F 3 "~" H 6130 6325 50  0001 C CNN
	1    6130 6325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5780 6275 5930 6275
Wire Wire Line
	5930 6275 5930 6325
Wire Wire Line
	5780 6475 5930 6475
Wire Wire Line
	5930 6475 5930 6425
Wire Wire Line
	4630 5675 4780 5675
Wire Wire Line
	4280 6075 4780 6075
Wire Wire Line
	4280 6675 4780 6675
Wire Wire Line
	4630 5875 4780 5875
Wire Wire Line
	5780 5675 5930 5675
Wire Wire Line
	5930 5675 5930 5725
Wire Wire Line
	5780 5875 5930 5875
Wire Wire Line
	5930 5875 5930 5825
$Comp
L Connector:Conn_01x02_Female J7
U 1 1 5F84921C
P 3090 2195
F 0 "J7" V 3190 2195 50  0000 R CNN
F 1 "Conn_01x02_Female" V 3190 2345 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3090 2195 50  0001 C CNN
F 3 "~" H 3090 2195 50  0001 C CNN
	1    3090 2195
	0    -1   -1   0   
$EndComp
$Comp
L power:Earth #PWR07
U 1 1 5F84F4BF
P 2590 2980
F 0 "#PWR07" H 2590 2730 50  0001 C CNN
F 1 "Earth" H 2590 2830 50  0001 C CNN
F 2 "" H 2590 2980 50  0001 C CNN
F 3 "~" H 2590 2980 50  0001 C CNN
	1    2590 2980
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR05
U 1 1 5F851F48
P 2090 2045
F 0 "#PWR05" H 2090 1895 50  0001 C CNN
F 1 "+9V" H 2105 2218 50  0000 C CNN
F 2 "" H 2090 2045 50  0001 C CNN
F 3 "" H 2090 2045 50  0001 C CNN
	1    2090 2045
	1    0    0    -1  
$EndComp
Text GLabel 4630 6475 0    50   Output ~ 0
IN2
Wire Wire Line
	4630 6475 4780 6475
Text GLabel 4630 6275 0    50   Output ~ 0
IN1
Wire Wire Line
	4630 6275 4780 6275
$Comp
L Connector:Screw_Terminal_01x02 J9
U 1 1 5F8298E7
P 6130 5725
F 0 "J9" H 6210 5717 50  0000 L CNN
F 1 "M2" H 6210 5626 50  0000 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 6130 5725 50  0001 C CNN
F 3 "~" H 6130 5725 50  0001 C CNN
	1    6130 5725
	1    0    0    -1  
$EndComp
Text GLabel 10290 5585 2    50   Input ~ 0
D11
Wire Wire Line
	9390 5335 9390 5385
Connection ~ 9390 5335
Wire Wire Line
	9190 5335 9390 5335
Wire Wire Line
	9390 4885 9390 4985
Connection ~ 10190 5585
Wire Wire Line
	10290 5585 10190 5585
Wire Wire Line
	10190 5485 10190 5585
Wire Wire Line
	9790 5585 9690 5585
Text GLabel 9190 5335 0    50   Input ~ 0
IN4
Text GLabel 10190 5485 1    50   Input ~ 0
IN3
Wire Wire Line
	9390 5285 9390 5335
Wire Wire Line
	9390 5785 9390 5985
Wire Wire Line
	10190 5585 10090 5585
$Comp
L power:Earth #PWR015
U 1 1 5F7801C1
P 9390 5985
F 0 "#PWR015" H 9390 5735 50  0001 C CNN
F 1 "Earth" H 9390 5835 50  0001 C CNN
F 2 "" H 9390 5985 50  0001 C CNN
F 3 "~" H 9390 5985 50  0001 C CNN
	1    9390 5985
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F77EB8E
P 9940 5585
F 0 "R5" V 9733 5585 50  0000 C CNN
F 1 "330" V 9824 5585 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 9870 5585 50  0001 C CNN
F 3 "~" H 9940 5585 50  0001 C CNN
	1    9940 5585
	0    -1   1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5F77DB81
P 9390 5135
F 0 "R3" H 9460 5181 50  0000 L CNN
F 1 "10K" H 9460 5090 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 9320 5135 50  0001 C CNN
F 3 "~" H 9390 5135 50  0001 C CNN
	1    9390 5135
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q1
U 1 1 5F7559A6
P 9490 5585
F 0 "Q1" H 9680 5631 50  0000 L CNN
F 1 "PN2222A" H 9680 5540 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 9690 5510 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/PN2222-D.PDF" H 9490 5585 50  0001 L CNN
	1    9490 5585
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7355 5360 7355 5410
Connection ~ 7355 5360
Wire Wire Line
	7155 5360 7355 5360
Wire Wire Line
	7355 4910 7355 5010
Connection ~ 8155 5610
Wire Wire Line
	8255 5610 8155 5610
Wire Wire Line
	8155 5510 8155 5610
Wire Wire Line
	7755 5610 7655 5610
Wire Wire Line
	7355 5310 7355 5360
Wire Wire Line
	7355 5810 7355 6010
Wire Wire Line
	8155 5610 8055 5610
$Comp
L power:Earth #PWR017
U 1 1 5F880F51
P 7355 6010
F 0 "#PWR017" H 7355 5760 50  0001 C CNN
F 1 "Earth" H 7355 5860 50  0001 C CNN
F 2 "" H 7355 6010 50  0001 C CNN
F 3 "~" H 7355 6010 50  0001 C CNN
	1    7355 6010
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5F880F57
P 7905 5610
F 0 "R6" V 7698 5610 50  0000 C CNN
F 1 "330" V 7789 5610 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 7835 5610 50  0001 C CNN
F 3 "~" H 7905 5610 50  0001 C CNN
	1    7905 5610
	0    -1   1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5F880F5D
P 7355 5160
F 0 "R4" H 7425 5206 50  0000 L CNN
F 1 "10K" H 7425 5115 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 7285 5160 50  0001 C CNN
F 3 "~" H 7355 5160 50  0001 C CNN
	1    7355 5160
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PN2222A Q2
U 1 1 5F880F63
P 7455 5610
F 0 "Q2" H 7645 5656 50  0000 L CNN
F 1 "PN2222A" H 7645 5565 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 7655 5535 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/PN2222-D.PDF" H 7455 5610 50  0001 L CNN
	1    7455 5610
	-1   0    0    -1  
$EndComp
Text GLabel 7155 5360 0    50   Input ~ 0
IN1
Text GLabel 8155 5510 1    50   Input ~ 0
IN2
Text GLabel 7860 3240 0    50   Output ~ 0
D12
Wire Wire Line
	7860 3240 7960 3240
Wire Wire Line
	2090 2395 2240 2395
$Comp
L Device:CP C1
U 1 1 5F794C46
P 2240 2645
F 0 "C1" H 2040 2645 50  0000 L CNN
F 1 "47uF" H 2040 2545 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 2278 2495 50  0001 C CNN
F 3 "~" H 2240 2645 50  0001 C CNN
	1    2240 2645
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5F795937
P 2940 2645
F 0 "C2" H 3058 2691 50  0000 L CNN
F 1 "10uF" H 3058 2600 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 2978 2495 50  0001 C CNN
F 3 "~" H 2940 2645 50  0001 C CNN
	1    2940 2645
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D1
U 1 1 5F797DAE
P 2590 2045
F 0 "D1" H 2590 2262 50  0000 C CNN
F 1 "1N4007" H 2590 2171 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2590 1870 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2590 2045 50  0001 C CNN
	1    2590 2045
	1    0    0    -1  
$EndComp
Wire Wire Line
	2440 2045 2240 2045
Wire Wire Line
	2740 2045 2940 2045
Wire Wire Line
	2240 2795 2240 2845
Wire Wire Line
	2240 2845 2590 2845
Connection ~ 2590 2845
Wire Wire Line
	2590 2845 2590 2695
Wire Wire Line
	2590 2845 2940 2845
Wire Wire Line
	2940 2845 2940 2795
Wire Wire Line
	2240 2495 2240 2395
Connection ~ 2240 2395
Wire Wire Line
	2240 2395 2290 2395
Wire Wire Line
	2940 2495 2940 2395
Connection ~ 2940 2395
Wire Wire Line
	2940 2395 2890 2395
Wire Wire Line
	2940 2045 2940 2395
Wire Wire Line
	2240 2045 2240 2395
Wire Wire Line
	2940 2395 3090 2395
Wire Wire Line
	3190 2395 3290 2395
$Comp
L power:Earth #PWR03
U 1 1 5F7B7EC9
P 8510 3790
F 0 "#PWR03" H 8510 3540 50  0001 C CNN
F 1 "Earth" H 8510 3640 50  0001 C CNN
F 2 "" H 8510 3790 50  0001 C CNN
F 3 "~" H 8510 3790 50  0001 C CNN
	1    8510 3790
	1    0    0    -1  
$EndComp
Wire Wire Line
	8460 3690 8510 3690
Wire Wire Line
	8560 3690 8560 3640
Connection ~ 8510 3690
Wire Wire Line
	8510 3690 8560 3690
$Comp
L Connector:Conn_01x15_Female J2
U 1 1 5F7EF007
P 1320 6320
F 0 "J2" H 1212 7113 50  0000 C CNN
F 1 "Conn_01x15_Female" H 1212 7114 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 1320 6320 50  0001 C CNN
F 3 "~" H 1320 6320 50  0001 C CNN
	1    1320 6320
	-1   0    0    -1  
$EndComp
Text GLabel 7860 2040 0    50   Output ~ 0
RX
Wire Wire Line
	7860 2040 7960 2040
Text GLabel 7860 2140 0    50   Output ~ 0
TX
Wire Wire Line
	7860 2140 7960 2140
Text GLabel 7860 2240 0    50   Output ~ 0
D2
Wire Wire Line
	7860 2240 7960 2240
Text GLabel 7860 2340 0    50   Output ~ 0
D3
Wire Wire Line
	7860 2340 7960 2340
Text GLabel 7860 2440 0    50   Output ~ 0
D4
Wire Wire Line
	7860 2440 7960 2440
Text GLabel 7860 2540 0    50   Output ~ 0
D5
Wire Wire Line
	7860 2540 7960 2540
Text GLabel 7860 2640 0    50   Output ~ 0
D6
Wire Wire Line
	7860 2640 7960 2640
Text GLabel 7860 2740 0    50   Output ~ 0
D7
Wire Wire Line
	7860 2740 7960 2740
Text GLabel 7860 2840 0    50   Output ~ 0
D8
Wire Wire Line
	7860 2840 7960 2840
Text GLabel 7860 2940 0    50   Output ~ 0
D9
Wire Wire Line
	7860 2940 7960 2940
Text GLabel 7860 3040 0    50   Output ~ 0
D10
Wire Wire Line
	7860 3040 7960 3040
Text GLabel 7310 2040 2    50   Input ~ 0
RX
Wire Wire Line
	7310 1940 7210 1940
Text GLabel 7310 1940 2    50   Input ~ 0
TX
Wire Wire Line
	7310 2040 7210 2040
Text GLabel 7310 2340 2    50   Input ~ 0
D2
Wire Wire Line
	7310 2140 7210 2140
Text GLabel 7310 2440 2    50   Input ~ 0
D3
Text GLabel 7310 2540 2    50   Input ~ 0
D4
Wire Wire Line
	7310 2340 7210 2340
Text GLabel 7310 2640 2    50   Input ~ 0
D5
Wire Wire Line
	7310 2440 7210 2440
Text GLabel 7310 2740 2    50   Input ~ 0
D6
Wire Wire Line
	7310 2540 7210 2540
Text GLabel 7310 2840 2    50   Input ~ 0
D7
Wire Wire Line
	7310 2640 7210 2640
Text GLabel 7310 2940 2    50   Input ~ 0
D8
Wire Wire Line
	7310 2740 7210 2740
Text GLabel 7310 3040 2    50   Input ~ 0
D9
Wire Wire Line
	7310 2840 7210 2840
Text GLabel 7310 3140 2    50   Input ~ 0
D10
Wire Wire Line
	7310 2940 7210 2940
Wire Wire Line
	7310 3040 7210 3040
Wire Wire Line
	7310 3140 7210 3140
Text GLabel 7860 3340 0    50   Output ~ 0
D13
Wire Wire Line
	7860 3340 7960 3340
Text GLabel 9760 3340 0    50   Input ~ 0
D13
Wire Wire Line
	7310 3240 7210 3240
Text GLabel 9060 2140 2    50   Output ~ 0
RST
Wire Wire Line
	9060 2140 8960 2140
Wire Wire Line
	7210 3340 7310 3340
$Comp
L Connector:Conn_01x15_Female J1
U 1 1 5F7DAE2F
P 7010 2640
F 0 "J1" H 6902 3433 50  0000 C CNN
F 1 "Conn_01x15_Female" H 6902 3434 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 7010 2640 50  0001 C CNN
F 3 "~" H 7010 2640 50  0001 C CNN
	1    7010 2640
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1520 5620 1520 5720
Connection ~ 1520 5720
Wire Wire Line
	1520 5720 1520 5820
Connection ~ 1520 5820
Wire Wire Line
	1520 5820 1520 5920
Connection ~ 1520 5920
Wire Wire Line
	1520 5920 1520 6020
Connection ~ 1520 6020
Wire Wire Line
	1520 6020 1520 6120
Connection ~ 1520 6120
Wire Wire Line
	1520 6120 1520 6220
Connection ~ 1520 6220
Wire Wire Line
	1520 6220 1520 6320
Connection ~ 1520 6320
Wire Wire Line
	1520 6320 1520 6420
Connection ~ 1520 6420
Wire Wire Line
	1520 6420 1520 6520
Connection ~ 1520 6520
Wire Wire Line
	1520 6520 1520 6620
Connection ~ 1520 6620
Wire Wire Line
	1520 6620 1520 6720
Connection ~ 1520 6720
Wire Wire Line
	1520 6720 1520 6820
Connection ~ 1520 6820
Wire Wire Line
	1520 6820 1520 6920
Connection ~ 1520 6920
Wire Wire Line
	1520 6920 1520 7020
$Comp
L power:Earth #PWR02
U 1 1 5F90867D
P 1520 7170
F 0 "#PWR02" H 1520 6920 50  0001 C CNN
F 1 "Earth" H 1520 7020 50  0001 C CNN
F 2 "" H 1520 7170 50  0001 C CNN
F 3 "~" H 1520 7170 50  0001 C CNN
	1    1520 7170
	1    0    0    -1  
$EndComp
Connection ~ 1520 7020
$Comp
L Connector:Screw_Terminal_01x02 J8
U 1 1 5F92A9B2
P 5055 2410
F 0 "J8" H 5135 2402 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 5135 2311 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 5055 2410 50  0001 C CNN
F 3 "~" H 5055 2410 50  0001 C CNN
	1    5055 2410
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR09
U 1 1 5F92D669
P 4805 2710
F 0 "#PWR09" H 4805 2460 50  0001 C CNN
F 1 "Earth" H 4805 2560 50  0001 C CNN
F 2 "" H 4805 2710 50  0001 C CNN
F 3 "~" H 4805 2710 50  0001 C CNN
	1    4805 2710
	1    0    0    -1  
$EndComp
Wire Wire Line
	4805 2510 4855 2510
$Comp
L power:+9V #PWR08
U 1 1 5F934D34
P 4805 2210
F 0 "#PWR08" H 4805 2060 50  0001 C CNN
F 1 "+9V" H 4820 2383 50  0000 C CNN
F 2 "" H 4805 2210 50  0001 C CNN
F 3 "" H 4805 2210 50  0001 C CNN
	1    4805 2210
	1    0    0    -1  
$EndComp
Wire Wire Line
	4805 2410 4855 2410
Wire Wire Line
	5280 7325 5280 7265
$Comp
L power:Earth #PWR012
U 1 1 5F7A7077
P 5280 7325
F 0 "#PWR012" H 5280 7075 50  0001 C CNN
F 1 "Earth" H 5280 7175 50  0001 C CNN
F 2 "" H 5280 7325 50  0001 C CNN
F 3 "~" H 5280 7325 50  0001 C CNN
	1    5280 7325
	1    0    0    -1  
$EndComp
Wire Wire Line
	4805 2210 4805 2240
$Comp
L Connector:Conn_01x15_Female J3
U 1 1 5F9A5137
P 1735 6315
F 0 "J3" H 1735 7165 50  0000 C CNN
F 1 "Conn_01x15_Female" H 1627 7109 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 1735 6315 50  0001 C CNN
F 3 "~" H 1735 6315 50  0001 C CNN
	1    1735 6315
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1935 5615 1935 5715
Connection ~ 1935 5715
Wire Wire Line
	1935 5715 1935 5815
Connection ~ 1935 5815
Wire Wire Line
	1935 5815 1935 5915
Connection ~ 1935 5915
Wire Wire Line
	1935 5915 1935 6015
Connection ~ 1935 6015
Wire Wire Line
	1935 6015 1935 6115
Connection ~ 1935 6115
Wire Wire Line
	1935 6115 1935 6215
Connection ~ 1935 6215
Wire Wire Line
	1935 6215 1935 6315
Connection ~ 1935 6315
Wire Wire Line
	1935 6315 1935 6415
Connection ~ 1935 6415
Wire Wire Line
	1935 6415 1935 6515
Connection ~ 1935 6515
Wire Wire Line
	1935 6515 1935 6615
Connection ~ 1935 6615
Wire Wire Line
	1935 6615 1935 6715
Connection ~ 1935 6715
Wire Wire Line
	1935 6715 1935 6815
Connection ~ 1935 6815
Wire Wire Line
	1935 6815 1935 6915
Connection ~ 1935 6915
Wire Wire Line
	1935 6915 1935 7015
Text GLabel 1935 5515 1    50   Input ~ 0
5V
Wire Wire Line
	1935 5515 1935 5615
Connection ~ 1935 5615
$Comp
L Connector:Conn_01x15_Female J6
U 1 1 5FE4B216
P 10085 2640
F 0 "J6" H 10113 2620 50  0000 L CNN
F 1 "Conn_01x15_Female" H 10113 2575 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 10085 2640 50  0001 C CNN
F 3 "~" H 10085 2640 50  0001 C CNN
	1    10085 2640
	1    0    0    -1  
$EndComp
Text GLabel 7310 2140 2    50   Input ~ 0
RST
$Comp
L power:Earth #PWR01
U 1 1 5FF49C9A
P 7560 2315
F 0 "#PWR01" H 7560 2065 50  0001 C CNN
F 1 "Earth" H 7560 2165 50  0001 C CNN
F 2 "" H 7560 2315 50  0001 C CNN
F 3 "~" H 7560 2315 50  0001 C CNN
	1    7560 2315
	1    0    0    -1  
$EndComp
Wire Wire Line
	7560 2315 7560 2240
Wire Wire Line
	7210 2240 7560 2240
Wire Wire Line
	9885 3340 9760 3340
Wire Wire Line
	9060 3340 8960 3340
Wire Wire Line
	8960 3240 9060 3240
Wire Wire Line
	8960 3140 9060 3140
Wire Wire Line
	8960 3040 9060 3040
Wire Wire Line
	8960 2940 9060 2940
Wire Wire Line
	8960 2840 9060 2840
Wire Wire Line
	8960 2740 9060 2740
Wire Wire Line
	8960 2640 9060 2640
Wire Wire Line
	9060 2440 8960 2440
Text GLabel 9060 2040 2    50   Output ~ 0
RST
Wire Wire Line
	9060 2040 8960 2040
Text GLabel 9060 2440 2    50   Output ~ 0
AREF
Text GLabel 9060 2640 2    50   Output ~ 0
A0
Text GLabel 9060 2740 2    50   Output ~ 0
A1
Text GLabel 9060 2840 2    50   Output ~ 0
A2
Text GLabel 9060 2940 2    50   Output ~ 0
A3
Text GLabel 9060 3040 2    50   Output ~ 0
A4
Text GLabel 9060 3140 2    50   Output ~ 0
A5
Text GLabel 9060 3240 2    50   Output ~ 0
A6
Text GLabel 9060 3340 2    50   Output ~ 0
A7
Text GLabel 8560 1530 1    50   Output ~ 0
3V3
Wire Wire Line
	8560 1530 8560 1640
Text GLabel 8660 1530 1    50   Output ~ 0
5V
Wire Wire Line
	8660 1530 8660 1640
Text GLabel 9753 3240 0    50   Input ~ 0
3V3
Wire Wire Line
	9885 3240 9753 3240
Text GLabel 9795 3140 0    50   Input ~ 0
AREF
Wire Wire Line
	9795 3140 9885 3140
Text GLabel 9705 3040 0    50   Input ~ 0
A0
Wire Wire Line
	9705 3040 9885 3040
Text GLabel 9705 2940 0    50   Input ~ 0
A1
Wire Wire Line
	9705 2940 9885 2940
Text GLabel 9705 2840 0    50   Input ~ 0
A2
Wire Wire Line
	9705 2840 9885 2840
Text GLabel 9705 2740 0    50   Input ~ 0
A3
Wire Wire Line
	9705 2740 9885 2740
Text GLabel 9705 2640 0    50   Input ~ 0
A4
Wire Wire Line
	9705 2640 9885 2640
Text GLabel 9705 2540 0    50   Input ~ 0
A5
Wire Wire Line
	9705 2540 9885 2540
Text GLabel 9705 2440 0    50   Input ~ 0
A6
Wire Wire Line
	9705 2440 9885 2440
Text GLabel 9705 2340 0    50   Input ~ 0
A7
Wire Wire Line
	9705 2340 9885 2340
Text GLabel 9705 2240 0    50   Input ~ 0
5V
Wire Wire Line
	9705 2240 9885 2240
Text GLabel 9750 2140 0    50   Input ~ 0
RST
Wire Wire Line
	9750 2140 9885 2140
$Comp
L power:Earth #PWR06
U 1 1 600F6A9B
P 9435 2140
F 0 "#PWR06" H 9435 1890 50  0001 C CNN
F 1 "Earth" H 9435 1990 50  0001 C CNN
F 2 "" H 9435 2140 50  0001 C CNN
F 3 "~" H 9435 2140 50  0001 C CNN
	1    9435 2140
	1    0    0    -1  
$EndComp
Wire Wire Line
	9885 2040 9435 2040
Wire Wire Line
	9435 2040 9435 2140
Text GLabel 3290 2395 2    50   Output ~ 0
VIN
Text GLabel 9730 1940 0    50   Input ~ 0
VIN
Wire Wire Line
	9730 1940 9885 1940
Text GLabel 8360 1530 1    50   Input ~ 0
VIN
$Comp
L power:PWR_FLAG #FLG01
U 1 1 601D189F
P 8230 1590
F 0 "#FLG01" H 8230 1665 50  0001 C CNN
F 1 "PWR_FLAG" V 8230 1717 50  0000 L CNN
F 2 "" H 8230 1590 50  0001 C CNN
F 3 "~" H 8230 1590 50  0001 C CNN
	1    8230 1590
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8360 1640 8360 1590
Wire Wire Line
	8230 1590 8360 1590
Connection ~ 8360 1590
Wire Wire Line
	8360 1590 8360 1530
Text GLabel 8255 5610 2    50   Input ~ 0
D12
Wire Wire Line
	5205 7265 5280 7265
Connection ~ 5280 7265
Wire Wire Line
	5280 7265 5280 7175
$Comp
L power:PWR_FLAG #FLG04
U 1 1 6032A93D
P 5205 7265
F 0 "#FLG04" H 5205 7340 50  0001 C CNN
F 1 "PWR_FLAG" V 5205 7392 50  0000 L CNN
F 2 "" H 5205 7265 50  0001 C CNN
F 3 "~" H 5205 7265 50  0001 C CNN
	1    5205 7265
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2090 2045 2090 2395
$Comp
L Switch:SW_DPST_x2 SW1
U 1 1 60340348
P 3900 2240
F 0 "SW1" H 3990 2360 50  0000 R CNN
F 1 "SW_DPST_x2" V 3855 2152 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 2240 50  0001 C CNN
F 3 "~" H 3900 2240 50  0001 C CNN
	1    3900 2240
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5F78383F
P 8460 2640
F 0 "A1" H 8460 2040 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 8460 2540 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 8460 2640 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 8460 2640 50  0001 C CNN
	1    8460 2640
	1    0    0    -1  
$EndComp
Wire Wire Line
	8460 3640 8460 3690
Wire Wire Line
	8510 3690 8510 3790
$Comp
L power:PWR_FLAG #FLG02
U 1 1 6037893D
P 4900 2240
F 0 "#FLG02" H 4900 2315 50  0001 C CNN
F 1 "PWR_FLAG" V 4900 2368 50  0000 L CNN
F 2 "" H 4900 2240 50  0001 C CNN
F 3 "~" H 4900 2240 50  0001 C CNN
	1    4900 2240
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2240 4805 2240
Connection ~ 4805 2240
NoConn ~ 7310 3240
NoConn ~ 7310 3340
Wire Wire Line
	2590 2845 2590 2980
Wire Wire Line
	1520 7020 1520 7170
$Comp
L Connector:Conn_01x15_Female J4
U 1 1 60409FAA
P 2390 6320
F 0 "J4" H 2282 7113 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2282 7114 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 2390 6320 50  0001 C CNN
F 3 "~" H 2390 6320 50  0001 C CNN
	1    2390 6320
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2590 5620 2590 5720
Connection ~ 2590 5720
Wire Wire Line
	2590 5720 2590 5820
Connection ~ 2590 5820
Wire Wire Line
	2590 5820 2590 5920
Connection ~ 2590 5920
Wire Wire Line
	2590 5920 2590 6020
Connection ~ 2590 6020
Wire Wire Line
	2590 6020 2590 6120
Connection ~ 2590 6120
Wire Wire Line
	2590 6120 2590 6220
Connection ~ 2590 6220
Wire Wire Line
	2590 6220 2590 6320
Connection ~ 2590 6320
Wire Wire Line
	2590 6320 2590 6420
Connection ~ 2590 6420
Wire Wire Line
	2590 6420 2590 6520
Connection ~ 2590 6520
Wire Wire Line
	2590 6520 2590 6620
Connection ~ 2590 6620
Wire Wire Line
	2590 6620 2590 6720
Connection ~ 2590 6720
Wire Wire Line
	2590 6720 2590 6820
Connection ~ 2590 6820
Wire Wire Line
	2590 6820 2590 6920
Connection ~ 2590 6920
Wire Wire Line
	2590 6920 2590 7020
$Comp
L power:Earth #PWR04
U 1 1 60409FCB
P 2590 7170
F 0 "#PWR04" H 2590 6920 50  0001 C CNN
F 1 "Earth" H 2590 7020 50  0001 C CNN
F 2 "" H 2590 7170 50  0001 C CNN
F 3 "~" H 2590 7170 50  0001 C CNN
	1    2590 7170
	1    0    0    -1  
$EndComp
Connection ~ 2590 7020
$Comp
L Connector:Conn_01x15_Female J5
U 1 1 60409FD2
P 2805 6315
F 0 "J5" H 2805 7165 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2697 7109 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 2805 6315 50  0001 C CNN
F 3 "~" H 2805 6315 50  0001 C CNN
	1    2805 6315
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3005 5615 3005 5715
Connection ~ 3005 5715
Wire Wire Line
	3005 5715 3005 5815
Connection ~ 3005 5815
Wire Wire Line
	3005 5815 3005 5915
Connection ~ 3005 5915
Wire Wire Line
	3005 5915 3005 6015
Connection ~ 3005 6015
Wire Wire Line
	3005 6015 3005 6115
Connection ~ 3005 6115
Wire Wire Line
	3005 6115 3005 6215
Connection ~ 3005 6215
Wire Wire Line
	3005 6215 3005 6315
Connection ~ 3005 6315
Wire Wire Line
	3005 6315 3005 6415
Connection ~ 3005 6415
Wire Wire Line
	3005 6415 3005 6515
Connection ~ 3005 6515
Wire Wire Line
	3005 6515 3005 6615
Connection ~ 3005 6615
Wire Wire Line
	3005 6615 3005 6715
Connection ~ 3005 6715
Wire Wire Line
	3005 6715 3005 6815
Connection ~ 3005 6815
Wire Wire Line
	3005 6815 3005 6915
Connection ~ 3005 6915
Wire Wire Line
	3005 6915 3005 7015
Text GLabel 3005 5515 1    50   Input ~ 0
5V
Wire Wire Line
	3005 5515 3005 5615
Connection ~ 3005 5615
Wire Wire Line
	2590 7020 2590 7170
Wire Notes Line
	900  7450 900  4700
Wire Notes Line
	900  4700 3450 4700
Wire Notes Line
	3450 4700 3450 7450
Wire Notes Line
	3450 7450 900  7450
Wire Notes Line
	1750 3150 1750 1350
Wire Notes Line
	6800 6200 6800 4350
Wire Notes Line
	6800 4350 10700 4350
Wire Notes Line
	10700 4350 10700 6200
Wire Notes Line
	10700 6200 6800 6200
Wire Notes Line
	6800 3950 6800 900 
Wire Notes Line
	6800 900  10250 900 
Wire Notes Line
	10250 900  10250 3950
Wire Notes Line
	10250 3950 6800 3950
Text Notes 1400 5050 0    118  ~ 24
Шины питания
Text Notes 1950 1650 0    118  ~ 24
Внешнее электропитание платы
Text Notes 8050 4600 0    118  ~ 24
Реверс моторов
Text Notes 7500 5200 0    118  ~ 24
M1
Text Notes 9500 5150 0    118  ~ 24
M2
Wire Wire Line
	4805 2240 4805 2410
Wire Wire Line
	4805 2510 4805 2660
Wire Wire Line
	4515 2240 4635 2240
Wire Wire Line
	4635 2320 4635 2240
Connection ~ 4635 2240
Wire Wire Line
	4635 2240 4805 2240
Wire Wire Line
	4635 2620 4635 2660
Wire Wire Line
	4635 2660 4805 2660
Connection ~ 4805 2660
Wire Wire Line
	4805 2660 4805 2710
Text GLabel 5280 5070 1    50   Input ~ 0
5V
Wire Wire Line
	5180 5275 5180 5180
Wire Wire Line
	5180 5180 5280 5180
Wire Wire Line
	5380 5180 5380 5275
Wire Wire Line
	5280 5070 5280 5180
Connection ~ 5280 5180
Wire Wire Line
	5280 5180 5380 5180
Wire Wire Line
	4100 2240 4215 2240
$Comp
L power:+9V #PWR0101
U 1 1 602C5E63
P 3575 2240
F 0 "#PWR0101" H 3575 2090 50  0001 C CNN
F 1 "+9V" V 3645 2290 50  0000 C CNN
F 2 "" H 3575 2240 50  0001 C CNN
F 3 "" H 3575 2240 50  0001 C CNN
	1    3575 2240
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3575 2240 3700 2240
Text GLabel 7355 4910 1    50   Input ~ 0
5V
Text GLabel 9390 4885 1    50   Input ~ 0
5V
Wire Notes Line
	5525 1350 5525 3150
Wire Notes Line
	1750 1350 5525 1350
Wire Notes Line
	1750 3150 5525 3150
Text Notes 4465 4840 0    118  ~ 24
Драйвер мотора
$EndSCHEMATC
