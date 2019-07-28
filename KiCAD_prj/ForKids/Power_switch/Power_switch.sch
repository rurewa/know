EESchema Schematic File Version 4
LIBS:Power_switch-cache
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
L Regulator_Linear:AMS1117-5.0 U2
U 1 1 5D39A83C
P 6040 3040
F 0 "U2" H 6040 3282 50  0000 C CNN
F 1 "AMS1117-5.0" H 6040 3191 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 6040 3240 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 6140 2790 50  0001 C CNN
	1    6040 3040
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5D39AD88
P 4235 3675
F 0 "D2" V 4335 3740 50  0000 C CNN
F 1 "LED" V 4228 3800 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 4235 3675 50  0001 C CNN
F 3 "~" H 4235 3675 50  0001 C CNN
	1    4235 3675
	0    1    -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5D39AF5B
P 4235 4035
F 0 "R1" H 4300 4105 50  0000 L CNN
F 1 "1K" H 4300 4000 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4165 4035 50  0001 C CNN
F 3 "~" H 4235 4035 50  0001 C CNN
	1    4235 4035
	1    0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Female J5
U 1 1 5D39DD03
P 7385 3590
F 0 "J5" H 7413 3566 50  0000 L CNN
F 1 "Conn_01x04_Female" H 7435 3490 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7385 3590 50  0001 C CNN
F 3 "~" H 7385 3590 50  0001 C CNN
	1    7385 3590
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D1
U 1 1 5D3B3C3A
P 3230 3490
F 0 "D1" H 3055 3445 50  0000 L CNN
F 1 "1N4148" H 3095 3575 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 3230 3315 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 3230 3490 50  0001 C CNN
	1    3230 3490
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5D3A8E86
P 2835 3490
F 0 "J1" H 2915 3482 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2915 3391 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 2835 3490 50  0001 C CNN
F 3 "~" H 2835 3490 50  0001 C CNN
	1    2835 3490
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3380 3590 3380 4240
$Comp
L Connector:Conn_01x04_Female J4
U 1 1 5D43D61A
P 7385 3140
F 0 "J4" H 7413 3116 50  0000 L CNN
F 1 "Conn_01x04_Female" H 7413 3025 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7385 3140 50  0001 C CNN
F 3 "~" H 7385 3140 50  0001 C CNN
	1    7385 3140
	1    0    0    -1  
$EndComp
Wire Wire Line
	7185 3340 7185 3240
Connection ~ 7185 3140
Wire Wire Line
	7185 3140 7185 3040
Connection ~ 7185 3240
Wire Wire Line
	7185 3240 7185 3140
Connection ~ 7185 3040
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 5D4411AA
P 7385 2535
F 0 "J3" H 7413 2511 50  0000 L CNN
F 1 "Conn_01x04_Female" H 7413 2420 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7385 2535 50  0001 C CNN
F 3 "~" H 7385 2535 50  0001 C CNN
	1    7385 2535
	1    0    0    -1  
$EndComp
Wire Wire Line
	7185 3490 7185 3590
Connection ~ 7185 3490
Connection ~ 7185 3590
Wire Wire Line
	7185 3590 7185 3690
Connection ~ 7185 3690
Wire Wire Line
	7185 3690 7185 3790
$Comp
L Regulator_Linear:AMS1117-3.3 U1
U 1 1 5D39A2DE
P 5285 3490
F 0 "U1" H 5285 3732 50  0000 C CNN
F 1 "AMS1117-3.3" H 5285 3641 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5285 3690 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 5385 3240 50  0001 C CNN
	1    5285 3490
	1    0    0    -1  
$EndComp
Wire Wire Line
	7185 2435 7185 2535
Connection ~ 7185 2735
Connection ~ 7185 2535
Wire Wire Line
	7185 2535 7185 2635
Connection ~ 7185 2635
Wire Wire Line
	7185 2635 7185 2735
$Comp
L Device:CP C5
U 1 1 5D4743B1
P 6535 3990
F 0 "C5" H 6565 4085 50  0000 L CNN
F 1 "22uF" H 6565 3890 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 6573 3840 50  0001 C CNN
F 3 "~" H 6535 3990 50  0001 C CNN
	1    6535 3990
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C4
U 1 1 5D473E0B
P 6235 3990
F 0 "C4" H 6255 4080 50  0000 L CNN
F 1 "22uF" H 6255 3885 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 6273 3840 50  0001 C CNN
F 3 "~" H 6235 3990 50  0001 C CNN
	1    6235 3990
	1    0    0    -1  
$EndComp
Wire Wire Line
	6235 3490 6235 3840
Wire Wire Line
	6535 3840 6535 3040
Wire Wire Line
	6040 4240 6235 4240
Wire Wire Line
	6535 4240 6535 4140
Connection ~ 6040 4240
Wire Wire Line
	6235 4140 6235 4240
Connection ~ 6235 4240
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5D4B160D
P 7785 2695
F 0 "J2" H 7813 2671 50  0000 L CNN
F 1 "Conn_01x04_Female" V 7485 2540 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7785 2695 50  0001 C CNN
F 3 "~" H 7785 2695 50  0001 C CNN
	1    7785 2695
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J6
U 1 1 5D4B914A
P 7785 3150
F 0 "J6" H 7813 3126 50  0000 L CNN
F 1 "Conn_01x04_Female" V 7950 2745 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7785 3150 50  0001 C CNN
F 3 "~" H 7785 3150 50  0001 C CNN
	1    7785 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J7
U 1 1 5D4BA084
P 7785 3595
F 0 "J7" H 7813 3571 50  0000 L CNN
F 1 "Conn_01x04_Female" V 7875 3640 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7785 3595 50  0001 C CNN
F 3 "~" H 7785 3595 50  0001 C CNN
	1    7785 3595
	1    0    0    -1  
$EndComp
Wire Wire Line
	7585 3795 7585 3695
Connection ~ 7585 2695
Wire Wire Line
	7585 2695 7585 2595
Connection ~ 7585 2795
Wire Wire Line
	7585 2795 7585 2695
Connection ~ 7585 2895
Wire Wire Line
	7585 2895 7585 2795
Connection ~ 7585 3050
Wire Wire Line
	7585 3050 7585 2895
Connection ~ 7585 3150
Wire Wire Line
	7585 3150 7585 3050
Connection ~ 7585 3250
Wire Wire Line
	7585 3250 7585 3150
Connection ~ 7585 3350
Wire Wire Line
	7585 3350 7585 3250
Connection ~ 7585 3495
Wire Wire Line
	7585 3495 7585 3350
Connection ~ 7585 3595
Wire Wire Line
	7585 3595 7585 3495
Connection ~ 7585 3695
Wire Wire Line
	7585 3695 7585 3595
$Comp
L power:Earth #PWR02
U 1 1 5D3CEC6B
P 7585 3875
F 0 "#PWR02" H 7585 3625 50  0001 C CNN
F 1 "Earth" H 7585 3725 50  0001 C CNN
F 2 "" H 7585 3875 50  0001 C CNN
F 3 "~" H 7585 3875 50  0001 C CNN
	1    7585 3875
	1    0    0    -1  
$EndComp
Wire Wire Line
	7585 3875 7585 3795
Connection ~ 7585 3795
Wire Wire Line
	6235 3490 7185 3490
$Comp
L Device:CP C6
U 1 1 5D40AE52
P 6925 3990
F 0 "C6" H 6960 4090 50  0000 L CNN
F 1 "22uF" H 6955 3890 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 6963 3840 50  0001 C CNN
F 3 "~" H 6925 3990 50  0001 C CNN
	1    6925 3990
	1    0    0    -1  
$EndComp
Wire Wire Line
	6535 3040 7185 3040
Wire Wire Line
	6925 3840 6925 2735
Wire Wire Line
	6925 4140 6925 4240
Wire Wire Line
	6235 4240 6535 4240
Connection ~ 6535 4240
Wire Wire Line
	6535 4240 6925 4240
Wire Wire Line
	4635 2735 4635 3040
Text Notes 2755 3735 0    50   ~ 0
12 V
Text Notes 6905 2630 0    50   ~ 0
12 V
Connection ~ 4635 3040
Wire Wire Line
	4235 3825 4235 3885
Wire Wire Line
	4635 3040 4635 3490
$Comp
L Device:CP C1
U 1 1 5D436796
P 4635 3985
F 0 "C1" H 4525 4135 50  0000 L CNN
F 1 "100uF" V 4695 4045 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P5.00mm" H 4673 3835 50  0001 C CNN
F 3 "~" H 4635 3985 50  0001 C CNN
	1    4635 3985
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 5D3A5D4B
P 3935 3490
F 0 "SW1" H 3945 3625 50  0000 C CNN
F 1 "SW_SPST" H 3935 3634 50  0001 C CNN
F 2 "Button_Switch_THT:Nidec_Copal_SH-7010C" H 3935 3490 50  0001 C CNN
F 3 "~" H 3935 3490 50  0001 C CNN
	1    3935 3490
	1    0    0    -1  
$EndComp
Wire Wire Line
	4235 4240 4235 4185
Wire Wire Line
	4235 3525 4235 3490
$Comp
L power:Earth #PWR04
U 1 1 5D4E7DC5
P 4235 4330
F 0 "#PWR04" H 4235 4080 50  0001 C CNN
F 1 "Earth" H 4235 4180 50  0001 C CNN
F 2 "" H 4235 4330 50  0001 C CNN
F 3 "~" H 4235 4330 50  0001 C CNN
	1    4235 4330
	1    0    0    -1  
$EndComp
Wire Wire Line
	6925 2735 7185 2735
Connection ~ 6925 2735
Wire Wire Line
	4635 3835 4635 3490
Connection ~ 4635 3490
Wire Wire Line
	4635 4240 4635 4135
Connection ~ 4635 4240
Wire Wire Line
	4635 2735 6925 2735
Wire Wire Line
	4135 3490 4235 3490
Text Notes 3765 2980 0    50   ~ 0
Коммутатор питания\nна 12/5/3.3 V
Wire Wire Line
	5285 4240 4885 4240
Connection ~ 5285 4240
Wire Wire Line
	5285 3790 5285 4240
Wire Wire Line
	6040 3340 6040 3590
$Comp
L Device:CP C2
U 1 1 5D5C66CC
P 4885 3990
F 0 "C2" H 4910 4090 50  0000 L CNN
F 1 "10uF" H 4895 3890 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 4923 3840 50  0001 C CNN
F 3 "~" H 4885 3990 50  0001 C CNN
	1    4885 3990
	1    0    0    -1  
$EndComp
Wire Wire Line
	4635 3490 4885 3490
Wire Wire Line
	4885 3840 4885 3490
Connection ~ 4885 3490
Wire Wire Line
	4885 3490 4985 3490
Wire Wire Line
	4885 4140 4885 4240
Connection ~ 4885 4240
Wire Wire Line
	4885 4240 4635 4240
$Comp
L Device:CP C3
U 1 1 5D5F1921
P 5635 3990
F 0 "C3" H 5660 4080 50  0000 L CNN
F 1 "10uF" H 5645 3890 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 5673 3840 50  0001 C CNN
F 3 "~" H 5635 3990 50  0001 C CNN
	1    5635 3990
	1    0    0    -1  
$EndComp
Wire Wire Line
	5285 4240 5635 4240
Wire Wire Line
	4635 3040 5635 3040
Wire Wire Line
	5635 4140 5635 4240
Connection ~ 5635 4240
Wire Wire Line
	5635 4240 6040 4240
Wire Wire Line
	5635 3840 5635 3040
Connection ~ 5635 3040
Wire Wire Line
	5635 3040 5740 3040
Wire Wire Line
	5585 3490 6235 3490
Connection ~ 6235 3490
Wire Wire Line
	6340 3040 6535 3040
Connection ~ 6535 3040
Connection ~ 4235 3490
Wire Wire Line
	4235 4240 4235 4330
Connection ~ 4235 4240
Wire Wire Line
	4235 4240 4635 4240
Wire Wire Line
	4235 3490 4635 3490
$Comp
L power:VCC #PWR03
U 1 1 5D4EC0D8
P 4235 3375
F 0 "#PWR03" H 4235 3225 50  0001 C CNN
F 1 "VCC" H 4252 3548 50  0000 C CNN
F 2 "" H 4235 3375 50  0001 C CNN
F 3 "" H 4235 3375 50  0001 C CNN
	1    4235 3375
	1    0    0    -1  
$EndComp
Wire Wire Line
	4235 3375 4235 3415
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D6437CF
P 4285 3415
F 0 "#FLG0101" H 4285 3490 50  0001 C CNN
F 1 "PWR_FLAG" V 4285 3543 50  0001 L CNN
F 2 "" H 4285 3415 50  0001 C CNN
F 3 "~" H 4285 3415 50  0001 C CNN
	1    4285 3415
	0    1    1    0   
$EndComp
Wire Wire Line
	4285 3415 4235 3415
Connection ~ 4235 3415
Wire Wire Line
	4235 3415 4235 3490
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5D647352
P 5935 3590
F 0 "#FLG0102" H 5935 3665 50  0001 C CNN
F 1 "PWR_FLAG" V 5935 3718 50  0001 L CNN
F 2 "" H 5935 3590 50  0001 C CNN
F 3 "~" H 5935 3590 50  0001 C CNN
	1    5935 3590
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5935 3590 6040 3590
Connection ~ 6040 3590
Wire Wire Line
	6040 3590 6040 4240
Wire Wire Line
	3035 3490 3080 3490
Wire Wire Line
	3380 3590 3035 3590
Wire Wire Line
	3380 3490 3735 3490
Wire Wire Line
	3380 4240 4235 4240
$EndSCHEMATC
