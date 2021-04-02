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
L power:Earth #PWR0102
U 1 1 6066A049
P 6775 5275
F 0 "#PWR0102" H 6775 5025 50  0001 C CNN
F 1 "Earth" H 6775 5125 50  0001 C CNN
F 2 "" H 6775 5275 50  0001 C CNN
F 3 "~" H 6775 5275 50  0001 C CNN
	1    6775 5275
	1    0    0    -1  
$EndComp
Text Notes 7050 4975 0    79   ~ 0
ПРЕДОХРАНИТЕЛЬ
Text Notes 6825 2300 0    79   ~ 0
АКБ
Wire Wire Line
	6375 2950 6375 3125
Wire Wire Line
	6375 3725 6375 3900
Text Notes 6950 4475 0    79   ~ 0
ЗАПАЛ
Wire Wire Line
	5950 3650 5950 3900
Wire Wire Line
	5950 3900 6375 3900
Wire Wire Line
	5950 3900 5950 4675
Connection ~ 5950 3900
Wire Wire Line
	5950 3250 5950 2950
Wire Wire Line
	6775 3725 6775 4175
Wire Wire Line
	6775 5100 6775 5275
$Comp
L power:+12V #PWR01
U 1 1 606AF8B1
P 7575 2100
F 0 "#PWR01" H 7575 1950 50  0001 C CNN
F 1 "+12V" H 7590 2273 50  0000 C CNN
F 2 "" H 7575 2100 50  0001 C CNN
F 3 "" H 7575 2100 50  0001 C CNN
	1    7575 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7575 2100 7775 2100
$Comp
L power:Earth #PWR02
U 1 1 606B1BE8
P 7575 2300
F 0 "#PWR02" H 7575 2050 50  0001 C CNN
F 1 "Earth" H 7575 2150 50  0001 C CNN
F 2 "" H 7575 2300 50  0001 C CNN
F 3 "~" H 7575 2300 50  0001 C CNN
	1    7575 2300
	1    0    0    -1  
$EndComp
Text Notes 7575 2850 0    197  ~ 0
БАЗА
Wire Notes Line
	5775 5500 8725 5500
Wire Notes Line
	5775 1675 5775 5500
Wire Notes Line
	8725 1675 8725 5500
Wire Wire Line
	5950 2950 6375 2950
Wire Notes Line
	5775 1675 8725 1675
Connection ~ 5950 2950
Wire Wire Line
	5225 2950 5950 2950
$Comp
L power:+12V #PWR0101
U 1 1 60669BA2
P 6775 2225
F 0 "#PWR0101" H 6775 2075 50  0001 C CNN
F 1 "+12V" H 6790 2398 50  0000 C CNN
F 2 "" H 6775 2225 50  0001 C CNN
F 3 "" H 6775 2225 50  0001 C CNN
	1    6775 2225
	1    0    0    -1  
$EndComp
Text Notes 4375 2175 0    79   ~ 0
ПУЛЬТ
Wire Notes Line
	3825 1950 5350 1950
Wire Wire Line
	6775 3125 6775 2375
Wire Wire Line
	6775 2225 6775 2375
Connection ~ 6775 2375
Text Notes 4275 2550 0    79   ~ 0
КЛЮЧ
Wire Wire Line
	4700 2700 4700 2950
Wire Wire Line
	4700 2600 4700 2375
Wire Wire Line
	4700 2950 4825 2950
Wire Wire Line
	4700 2375 6775 2375
Wire Notes Line
	3825 4650 3825 1950
Wire Wire Line
	4150 3650 4150 3800
Wire Wire Line
	4150 2375 4150 2650
Connection ~ 4700 2375
Wire Wire Line
	4150 2375 4700 2375
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 606ADA85
P 7975 2100
F 0 "J2" H 8055 2046 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8055 2001 50  0001 L CNN
F 2 "" H 7975 2100 50  0001 C CNN
F 3 "~" H 7975 2100 50  0001 C CNN
	1    7975 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G SW1
U 1 1 606AB7D5
P 5025 2950
F 0 "SW1" H 5025 2875 50  0000 C CNN
F 1 "SW_MEC_5G" H 5025 3144 50  0001 C CNN
F 2 "" H 5025 3150 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 5025 3150 50  0001 C CNN
	1    5025 2950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G SW2
U 1 1 606A4562
P 4150 2850
F 0 "SW2" V 4150 2998 50  0000 L CNN
F 1 "SW_MEC_5G" H 4150 3044 50  0001 C CNN
F 2 "" H 4150 3050 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4150 3050 50  0001 C CNN
	1    4150 2850
	0    1    1    0   
$EndComp
$Comp
L Device:L L1
U 1 1 6067DD81
P 6775 4400
F 0 "L1" H 6828 4446 50  0000 L CNN
F 1 "L" H 6828 4355 50  0000 L CNN
F 2 "" H 6775 4400 50  0001 C CNN
F 3 "~" H 6775 4400 50  0001 C CNN
	1    6775 4400
	1    0    0    -1  
$EndComp
$Comp
L pspice:DIODE D2
U 1 1 6065CF7B
P 5950 3450
F 0 "D2" V 5975 3325 50  0000 C CNN
F 1 "DIODE" V 5725 3325 50  0000 C CNN
F 2 "Diode_THT:D_DO-15_P15.24mm_Horizontal" H 5950 3450 50  0001 C CNN
F 3 "~" H 5950 3450 50  0001 C CNN
	1    5950 3450
	0    -1   -1   0   
$EndComp
$Comp
L Device:Fuse F1
U 1 1 6069695D
P 6775 4950
F 0 "F1" H 6835 4996 50  0000 L CNN
F 1 "5A" H 6835 4905 50  0000 L CNN
F 2 "" V 6705 4950 50  0001 C CNN
F 3 "~" H 6775 4950 50  0001 C CNN
	1    6775 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 6068D2B4
P 4150 3950
F 0 "R1" H 4050 3950 50  0000 C CNN
F 1 "10K" H 4275 3950 50  0000 C CNN
F 2 "" V 4080 3950 50  0001 C CNN
F 3 "~" H 4150 3950 50  0001 C CNN
	1    4150 3950
	-1   0    0    1   
$EndComp
$Comp
L Device:Buzzer BZ1
U 1 1 6067B7DE
P 4575 3725
F 0 "BZ1" H 4650 3550 50  0000 R CNN
F 1 "Buzzer" H 4750 3950 50  0000 R CNN
F 2 "Buzzer_Beeper:MagneticBuzzer_ProSignal_ABI-010-RC" V 4550 3825 50  0001 C CNN
F 3 "~" V 4550 3825 50  0001 C CNN
	1    4575 3725
	1    0    0    -1  
$EndComp
$Comp
L Relay:DIPxx-1Axx-11x K1
U 1 1 606702BE
P 6575 3425
F 0 "K1" H 6975 3475 50  0000 C CNN
F 1 "DIPxx-1Axx-11x" H 7250 3575 50  0000 C CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 6925 3375 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 6575 3425 50  0001 C CNN
	1    6575 3425
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 6066C43D
P 4900 2600
F 0 "J1" H 5000 2550 50  0000 R CNN
F 1 "Conn_01x02_Female" V 4837 2648 50  0001 L CNN
F 2 "" H 4900 2600 50  0001 C CNN
F 3 "~" H 4900 2600 50  0001 C CNN
	1    4900 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 6066B9D4
P 4150 3500
F 0 "D1" V 4150 3625 50  0000 C CNN
F 1 "LED" V 4150 3350 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 4150 3500 50  0001 C CNN
F 3 "~" H 4150 3500 50  0001 C CNN
	1    4150 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7575 2300 7575 2200
Wire Wire Line
	7575 2200 7775 2200
Wire Wire Line
	6775 4550 6775 4675
Wire Wire Line
	5950 4675 6775 4675
Connection ~ 6775 4675
Wire Wire Line
	6775 4675 6775 4800
Wire Wire Line
	4150 4100 4150 4175
Wire Wire Line
	4150 4175 4450 4175
Connection ~ 6775 4175
Wire Wire Line
	6775 4175 6775 4250
Wire Wire Line
	4450 3825 4475 3825
Wire Wire Line
	4450 3825 4450 4175
Connection ~ 4450 4175
Wire Wire Line
	4450 4175 6775 4175
Wire Wire Line
	4150 3050 4150 3250
Wire Wire Line
	4475 3625 4450 3625
Wire Wire Line
	4450 3625 4450 3250
Wire Wire Line
	4450 3250 4150 3250
Connection ~ 4150 3250
Wire Wire Line
	4150 3250 4150 3350
Wire Notes Line
	5325 1950 5325 4675
Wire Notes Line
	5325 4675 3800 4675
$EndSCHEMATC
