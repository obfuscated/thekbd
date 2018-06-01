EESchema Schematic File Version 2
LIBS:mylib_experimental
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
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
L Arduino_Micro_Socket ARD?
U 1 1 5A153725
P 2800 1775
F 0 "ARD?" V 2900 1775 60  0000 C CNN
F 1 "Arduino_Micro_Socket" V 2700 1775 60  0000 C CNN
F 2 "" H 4600 5525 60  0001 C CNN
F 3 "" H 4600 5525 60  0001 C CNN
	1    2800 1775
	1    0    0    -1  
$EndComp
NoConn ~ 4100 1775
NoConn ~ 1500 2075
NoConn ~ 1500 875 
NoConn ~ 1500 975 
$Comp
L 74HC4050 U?
U 1 1 5A20B7AC
P 2775 5525
F 0 "U?" H 2775 5025 60  0000 C CNN
F 1 "74HC4050" H 2775 5975 60  0000 C CNN
F 2 "" H 2775 5225 60  0000 C CNN
F 3 "" H 2775 5225 60  0000 C CNN
	1    2775 5525
	1    0    0    -1  
$EndComp
$Comp
L TFT128x64 U?
U 1 1 5A20C231
P 3025 3950
AR Path="/5A20C231" Ref="U?"  Part="1" 
AR Path="/5A14AEE6/5A20C231" Ref="U?"  Part="1" 
F 0 "U?" V 3025 4100 60  0000 C CNN
F 1 "TFT128x64" V 3175 4100 60  0000 C CNN
F 2 "" V 3175 4100 60  0001 C CNN
F 3 "" V 3175 4100 60  0001 C CNN
	1    3025 3950
	1    0    0    -1  
$EndComp
NoConn ~ 3325 5275
NoConn ~ 3325 5375
$Comp
L C C?
U 1 1 5A21B12B
P 1400 5500
F 0 "C?" H 1425 5600 50  0000 L CNN
F 1 "0.1uF" H 1425 5400 50  0000 L CNN
F 2 "" H 1438 5350 50  0001 C CNN
F 3 "" H 1400 5500 50  0001 C CNN
	1    1400 5500
	1    0    0    -1  
$EndComp
NoConn ~ 4100 2475
NoConn ~ 4100 2575
NoConn ~ 4100 2675
$Comp
L CONN_01X07 J?
U 1 1 5A22DA35
P 2775 7000
F 0 "J?" H 2775 7400 50  0000 C CNN
F 1 "Display" V 2875 7000 50  0000 C CNN
F 2 "" H 2775 7000 50  0001 C CNN
F 3 "" H 2775 7000 50  0001 C CNN
	1    2775 7000
	0    1    1    0   
$EndComp
NoConn ~ 4100 1975
Text HLabel 1000 1175 0    60   BiDi ~ 0
SDA
Text HLabel 1000 1275 0    60   BiDi ~ 0
SCL
Text HLabel 1000 1375 0    60   BiDi ~ 0
5V
Text HLabel 1000 1475 0    60   BiDi ~ 0
GND
$Comp
L SW_PUSH SW?
U 1 1 5B14819F
P 6475 1325
F 0 "SW?" H 6625 1435 50  0000 C CNN
F 1 "SW_PUSH" H 6475 1245 50  0000 C CNN
F 2 "" H 6475 1325 50  0000 C CNN
F 3 "" H 6475 1325 50  0000 C CNN
	1    6475 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1481A6
P 6725 1025
F 0 "D?" H 6725 1125 50  0000 C CNN
F 1 "D" H 6725 925 50  0000 C CNN
F 2 "" H 6725 1025 50  0001 C CNN
F 3 "" H 6725 1025 50  0001 C CNN
	1    6725 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1481AD
P 6475 2075
F 0 "SW?" H 6625 2185 50  0000 C CNN
F 1 "SW_PUSH" H 6475 1995 50  0000 C CNN
F 2 "" H 6475 2075 50  0000 C CNN
F 3 "" H 6475 2075 50  0000 C CNN
	1    6475 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1481B4
P 6725 1775
F 0 "D?" H 6725 1875 50  0000 C CNN
F 1 "D" H 6725 1675 50  0000 C CNN
F 2 "" H 6725 1775 50  0001 C CNN
F 3 "" H 6725 1775 50  0001 C CNN
	1    6725 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1481BB
P 6475 2825
F 0 "SW?" H 6625 2935 50  0000 C CNN
F 1 "SW_PUSH" H 6475 2745 50  0000 C CNN
F 2 "" H 6475 2825 50  0000 C CNN
F 3 "" H 6475 2825 50  0000 C CNN
	1    6475 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1481C2
P 6725 2525
F 0 "D?" H 6725 2625 50  0000 C CNN
F 1 "D" H 6725 2425 50  0000 C CNN
F 2 "" H 6725 2525 50  0001 C CNN
F 3 "" H 6725 2525 50  0001 C CNN
	1    6725 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1481C9
P 6475 3625
F 0 "SW?" H 6625 3735 50  0000 C CNN
F 1 "SW_PUSH" H 6475 3545 50  0000 C CNN
F 2 "" H 6475 3625 50  0000 C CNN
F 3 "" H 6475 3625 50  0000 C CNN
	1    6475 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1481D0
P 6725 3325
F 0 "D?" H 6725 3425 50  0000 C CNN
F 1 "D" H 6725 3225 50  0000 C CNN
F 2 "" H 6725 3325 50  0001 C CNN
F 3 "" H 6725 3325 50  0001 C CNN
	1    6725 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1481D7
P 6475 4425
F 0 "SW?" H 6625 4535 50  0000 C CNN
F 1 "SW_PUSH" H 6475 4345 50  0000 C CNN
F 2 "" H 6475 4425 50  0000 C CNN
F 3 "" H 6475 4425 50  0000 C CNN
	1    6475 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1481DE
P 6725 4125
F 0 "D?" H 6725 4225 50  0000 C CNN
F 1 "D" H 6725 4025 50  0000 C CNN
F 2 "" H 6725 4125 50  0001 C CNN
F 3 "" H 6725 4125 50  0001 C CNN
	1    6725 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1481E5
P 6475 5200
F 0 "SW?" H 6625 5310 50  0000 C CNN
F 1 "SW_PUSH" H 6475 5120 50  0000 C CNN
F 2 "" H 6475 5200 50  0000 C CNN
F 3 "" H 6475 5200 50  0000 C CNN
	1    6475 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1481EC
P 6725 4900
F 0 "D?" H 6725 5000 50  0000 C CNN
F 1 "D" H 6725 4800 50  0000 C CNN
F 2 "" H 6725 4900 50  0001 C CNN
F 3 "" H 6725 4900 50  0001 C CNN
	1    6725 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148201
P 7125 1325
F 0 "SW?" H 7275 1435 50  0000 C CNN
F 1 "SW_PUSH" H 7125 1245 50  0000 C CNN
F 2 "" H 7125 1325 50  0000 C CNN
F 3 "" H 7125 1325 50  0000 C CNN
	1    7125 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148208
P 7375 1025
F 0 "D?" H 7375 1125 50  0000 C CNN
F 1 "D" H 7375 925 50  0000 C CNN
F 2 "" H 7375 1025 50  0001 C CNN
F 3 "" H 7375 1025 50  0001 C CNN
	1    7375 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14820F
P 7125 2075
F 0 "SW?" H 7275 2185 50  0000 C CNN
F 1 "SW_PUSH" H 7125 1995 50  0000 C CNN
F 2 "" H 7125 2075 50  0000 C CNN
F 3 "" H 7125 2075 50  0000 C CNN
	1    7125 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148216
P 7375 1775
F 0 "D?" H 7375 1875 50  0000 C CNN
F 1 "D" H 7375 1675 50  0000 C CNN
F 2 "" H 7375 1775 50  0001 C CNN
F 3 "" H 7375 1775 50  0001 C CNN
	1    7375 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14821D
P 7125 2825
F 0 "SW?" H 7275 2935 50  0000 C CNN
F 1 "SW_PUSH" H 7125 2745 50  0000 C CNN
F 2 "" H 7125 2825 50  0000 C CNN
F 3 "" H 7125 2825 50  0000 C CNN
	1    7125 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148224
P 7375 2525
F 0 "D?" H 7375 2625 50  0000 C CNN
F 1 "D" H 7375 2425 50  0000 C CNN
F 2 "" H 7375 2525 50  0001 C CNN
F 3 "" H 7375 2525 50  0001 C CNN
	1    7375 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14822B
P 7125 3625
F 0 "SW?" H 7275 3735 50  0000 C CNN
F 1 "SW_PUSH" H 7125 3545 50  0000 C CNN
F 2 "" H 7125 3625 50  0000 C CNN
F 3 "" H 7125 3625 50  0000 C CNN
	1    7125 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148232
P 7375 3325
F 0 "D?" H 7375 3425 50  0000 C CNN
F 1 "D" H 7375 3225 50  0000 C CNN
F 2 "" H 7375 3325 50  0001 C CNN
F 3 "" H 7375 3325 50  0001 C CNN
	1    7375 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148239
P 7125 4425
F 0 "SW?" H 7275 4535 50  0000 C CNN
F 1 "SW_PUSH" H 7125 4345 50  0000 C CNN
F 2 "" H 7125 4425 50  0000 C CNN
F 3 "" H 7125 4425 50  0000 C CNN
	1    7125 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148240
P 7375 4125
F 0 "D?" H 7375 4225 50  0000 C CNN
F 1 "D" H 7375 4025 50  0000 C CNN
F 2 "" H 7375 4125 50  0001 C CNN
F 3 "" H 7375 4125 50  0001 C CNN
	1    7375 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148247
P 7125 5200
F 0 "SW?" H 7275 5310 50  0000 C CNN
F 1 "SW_PUSH" H 7125 5120 50  0000 C CNN
F 2 "" H 7125 5200 50  0000 C CNN
F 3 "" H 7125 5200 50  0000 C CNN
	1    7125 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14824E
P 7375 4900
F 0 "D?" H 7375 5000 50  0000 C CNN
F 1 "D" H 7375 4800 50  0000 C CNN
F 2 "" H 7375 4900 50  0001 C CNN
F 3 "" H 7375 4900 50  0001 C CNN
	1    7375 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148263
P 7775 1325
F 0 "SW?" H 7925 1435 50  0000 C CNN
F 1 "SW_PUSH" H 7775 1245 50  0000 C CNN
F 2 "" H 7775 1325 50  0000 C CNN
F 3 "" H 7775 1325 50  0000 C CNN
	1    7775 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14826A
P 8025 1025
F 0 "D?" H 8025 1125 50  0000 C CNN
F 1 "D" H 8025 925 50  0000 C CNN
F 2 "" H 8025 1025 50  0001 C CNN
F 3 "" H 8025 1025 50  0001 C CNN
	1    8025 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148271
P 7775 2075
F 0 "SW?" H 7925 2185 50  0000 C CNN
F 1 "SW_PUSH" H 7775 1995 50  0000 C CNN
F 2 "" H 7775 2075 50  0000 C CNN
F 3 "" H 7775 2075 50  0000 C CNN
	1    7775 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148278
P 8025 1775
F 0 "D?" H 8025 1875 50  0000 C CNN
F 1 "D" H 8025 1675 50  0000 C CNN
F 2 "" H 8025 1775 50  0001 C CNN
F 3 "" H 8025 1775 50  0001 C CNN
	1    8025 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14827F
P 7775 2825
F 0 "SW?" H 7925 2935 50  0000 C CNN
F 1 "SW_PUSH" H 7775 2745 50  0000 C CNN
F 2 "" H 7775 2825 50  0000 C CNN
F 3 "" H 7775 2825 50  0000 C CNN
	1    7775 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148286
P 8025 2525
F 0 "D?" H 8025 2625 50  0000 C CNN
F 1 "D" H 8025 2425 50  0000 C CNN
F 2 "" H 8025 2525 50  0001 C CNN
F 3 "" H 8025 2525 50  0001 C CNN
	1    8025 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14828D
P 7775 3625
F 0 "SW?" H 7925 3735 50  0000 C CNN
F 1 "SW_PUSH" H 7775 3545 50  0000 C CNN
F 2 "" H 7775 3625 50  0000 C CNN
F 3 "" H 7775 3625 50  0000 C CNN
	1    7775 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148294
P 8025 3325
F 0 "D?" H 8025 3425 50  0000 C CNN
F 1 "D" H 8025 3225 50  0000 C CNN
F 2 "" H 8025 3325 50  0001 C CNN
F 3 "" H 8025 3325 50  0001 C CNN
	1    8025 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14829B
P 7775 4425
F 0 "SW?" H 7925 4535 50  0000 C CNN
F 1 "SW_PUSH" H 7775 4345 50  0000 C CNN
F 2 "" H 7775 4425 50  0000 C CNN
F 3 "" H 7775 4425 50  0000 C CNN
	1    7775 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1482A2
P 8025 4125
F 0 "D?" H 8025 4225 50  0000 C CNN
F 1 "D" H 8025 4025 50  0000 C CNN
F 2 "" H 8025 4125 50  0001 C CNN
F 3 "" H 8025 4125 50  0001 C CNN
	1    8025 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1482A9
P 7775 5200
F 0 "SW?" H 7925 5310 50  0000 C CNN
F 1 "SW_PUSH" H 7775 5120 50  0000 C CNN
F 2 "" H 7775 5200 50  0000 C CNN
F 3 "" H 7775 5200 50  0000 C CNN
	1    7775 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1482B0
P 8025 4900
F 0 "D?" H 8025 5000 50  0000 C CNN
F 1 "D" H 8025 4800 50  0000 C CNN
F 2 "" H 8025 4900 50  0001 C CNN
F 3 "" H 8025 4900 50  0001 C CNN
	1    8025 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1482C5
P 8425 1325
F 0 "SW?" H 8575 1435 50  0000 C CNN
F 1 "SW_PUSH" H 8425 1245 50  0000 C CNN
F 2 "" H 8425 1325 50  0000 C CNN
F 3 "" H 8425 1325 50  0000 C CNN
	1    8425 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1482CC
P 8675 1025
F 0 "D?" H 8675 1125 50  0000 C CNN
F 1 "D" H 8675 925 50  0000 C CNN
F 2 "" H 8675 1025 50  0001 C CNN
F 3 "" H 8675 1025 50  0001 C CNN
	1    8675 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1482D3
P 8425 2075
F 0 "SW?" H 8575 2185 50  0000 C CNN
F 1 "SW_PUSH" H 8425 1995 50  0000 C CNN
F 2 "" H 8425 2075 50  0000 C CNN
F 3 "" H 8425 2075 50  0000 C CNN
	1    8425 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1482DA
P 8675 1775
F 0 "D?" H 8675 1875 50  0000 C CNN
F 1 "D" H 8675 1675 50  0000 C CNN
F 2 "" H 8675 1775 50  0001 C CNN
F 3 "" H 8675 1775 50  0001 C CNN
	1    8675 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1482E1
P 8425 2825
F 0 "SW?" H 8575 2935 50  0000 C CNN
F 1 "SW_PUSH" H 8425 2745 50  0000 C CNN
F 2 "" H 8425 2825 50  0000 C CNN
F 3 "" H 8425 2825 50  0000 C CNN
	1    8425 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1482E8
P 8675 2525
F 0 "D?" H 8675 2625 50  0000 C CNN
F 1 "D" H 8675 2425 50  0000 C CNN
F 2 "" H 8675 2525 50  0001 C CNN
F 3 "" H 8675 2525 50  0001 C CNN
	1    8675 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1482EF
P 8425 3625
F 0 "SW?" H 8575 3735 50  0000 C CNN
F 1 "SW_PUSH" H 8425 3545 50  0000 C CNN
F 2 "" H 8425 3625 50  0000 C CNN
F 3 "" H 8425 3625 50  0000 C CNN
	1    8425 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1482F6
P 8675 3325
F 0 "D?" H 8675 3425 50  0000 C CNN
F 1 "D" H 8675 3225 50  0000 C CNN
F 2 "" H 8675 3325 50  0001 C CNN
F 3 "" H 8675 3325 50  0001 C CNN
	1    8675 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1482FD
P 8425 4425
F 0 "SW?" H 8575 4535 50  0000 C CNN
F 1 "SW_PUSH" H 8425 4345 50  0000 C CNN
F 2 "" H 8425 4425 50  0000 C CNN
F 3 "" H 8425 4425 50  0000 C CNN
	1    8425 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148304
P 8675 4125
F 0 "D?" H 8675 4225 50  0000 C CNN
F 1 "D" H 8675 4025 50  0000 C CNN
F 2 "" H 8675 4125 50  0001 C CNN
F 3 "" H 8675 4125 50  0001 C CNN
	1    8675 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14830B
P 8425 5200
F 0 "SW?" H 8575 5310 50  0000 C CNN
F 1 "SW_PUSH" H 8425 5120 50  0000 C CNN
F 2 "" H 8425 5200 50  0000 C CNN
F 3 "" H 8425 5200 50  0000 C CNN
	1    8425 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148312
P 8675 4900
F 0 "D?" H 8675 5000 50  0000 C CNN
F 1 "D" H 8675 4800 50  0000 C CNN
F 2 "" H 8675 4900 50  0001 C CNN
F 3 "" H 8675 4900 50  0001 C CNN
	1    8675 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148327
P 9075 1325
F 0 "SW?" H 9225 1435 50  0000 C CNN
F 1 "SW_PUSH" H 9075 1245 50  0000 C CNN
F 2 "" H 9075 1325 50  0000 C CNN
F 3 "" H 9075 1325 50  0000 C CNN
	1    9075 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14832E
P 9325 1025
F 0 "D?" H 9325 1125 50  0000 C CNN
F 1 "D" H 9325 925 50  0000 C CNN
F 2 "" H 9325 1025 50  0001 C CNN
F 3 "" H 9325 1025 50  0001 C CNN
	1    9325 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148335
P 9075 2075
F 0 "SW?" H 9225 2185 50  0000 C CNN
F 1 "SW_PUSH" H 9075 1995 50  0000 C CNN
F 2 "" H 9075 2075 50  0000 C CNN
F 3 "" H 9075 2075 50  0000 C CNN
	1    9075 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14833C
P 9325 1775
F 0 "D?" H 9325 1875 50  0000 C CNN
F 1 "D" H 9325 1675 50  0000 C CNN
F 2 "" H 9325 1775 50  0001 C CNN
F 3 "" H 9325 1775 50  0001 C CNN
	1    9325 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148343
P 9075 2825
F 0 "SW?" H 9225 2935 50  0000 C CNN
F 1 "SW_PUSH" H 9075 2745 50  0000 C CNN
F 2 "" H 9075 2825 50  0000 C CNN
F 3 "" H 9075 2825 50  0000 C CNN
	1    9075 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14834A
P 9325 2525
F 0 "D?" H 9325 2625 50  0000 C CNN
F 1 "D" H 9325 2425 50  0000 C CNN
F 2 "" H 9325 2525 50  0001 C CNN
F 3 "" H 9325 2525 50  0001 C CNN
	1    9325 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148351
P 9075 3625
F 0 "SW?" H 9225 3735 50  0000 C CNN
F 1 "SW_PUSH" H 9075 3545 50  0000 C CNN
F 2 "" H 9075 3625 50  0000 C CNN
F 3 "" H 9075 3625 50  0000 C CNN
	1    9075 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148358
P 9325 3325
F 0 "D?" H 9325 3425 50  0000 C CNN
F 1 "D" H 9325 3225 50  0000 C CNN
F 2 "" H 9325 3325 50  0001 C CNN
F 3 "" H 9325 3325 50  0001 C CNN
	1    9325 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14835F
P 9075 4425
F 0 "SW?" H 9225 4535 50  0000 C CNN
F 1 "SW_PUSH" H 9075 4345 50  0000 C CNN
F 2 "" H 9075 4425 50  0000 C CNN
F 3 "" H 9075 4425 50  0000 C CNN
	1    9075 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148366
P 9325 4125
F 0 "D?" H 9325 4225 50  0000 C CNN
F 1 "D" H 9325 4025 50  0000 C CNN
F 2 "" H 9325 4125 50  0001 C CNN
F 3 "" H 9325 4125 50  0001 C CNN
	1    9325 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B14836D
P 9075 5200
F 0 "SW?" H 9225 5310 50  0000 C CNN
F 1 "SW_PUSH" H 9075 5120 50  0000 C CNN
F 2 "" H 9075 5200 50  0000 C CNN
F 3 "" H 9075 5200 50  0000 C CNN
	1    9075 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148374
P 9325 4900
F 0 "D?" H 9325 5000 50  0000 C CNN
F 1 "D" H 9325 4800 50  0000 C CNN
F 2 "" H 9325 4900 50  0001 C CNN
F 3 "" H 9325 4900 50  0001 C CNN
	1    9325 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148389
P 9725 1325
F 0 "SW?" H 9875 1435 50  0000 C CNN
F 1 "SW_PUSH" H 9725 1245 50  0000 C CNN
F 2 "" H 9725 1325 50  0000 C CNN
F 3 "" H 9725 1325 50  0000 C CNN
	1    9725 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148390
P 9975 1025
F 0 "D?" H 9975 1125 50  0000 C CNN
F 1 "D" H 9975 925 50  0000 C CNN
F 2 "" H 9975 1025 50  0001 C CNN
F 3 "" H 9975 1025 50  0001 C CNN
	1    9975 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148397
P 9725 2075
F 0 "SW?" H 9875 2185 50  0000 C CNN
F 1 "SW_PUSH" H 9725 1995 50  0000 C CNN
F 2 "" H 9725 2075 50  0000 C CNN
F 3 "" H 9725 2075 50  0000 C CNN
	1    9725 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14839E
P 9975 1775
F 0 "D?" H 9975 1875 50  0000 C CNN
F 1 "D" H 9975 1675 50  0000 C CNN
F 2 "" H 9975 1775 50  0001 C CNN
F 3 "" H 9975 1775 50  0001 C CNN
	1    9975 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1483A5
P 9725 2825
F 0 "SW?" H 9875 2935 50  0000 C CNN
F 1 "SW_PUSH" H 9725 2745 50  0000 C CNN
F 2 "" H 9725 2825 50  0000 C CNN
F 3 "" H 9725 2825 50  0000 C CNN
	1    9725 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1483AC
P 9975 2525
F 0 "D?" H 9975 2625 50  0000 C CNN
F 1 "D" H 9975 2425 50  0000 C CNN
F 2 "" H 9975 2525 50  0001 C CNN
F 3 "" H 9975 2525 50  0001 C CNN
	1    9975 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1483B3
P 9725 3625
F 0 "SW?" H 9875 3735 50  0000 C CNN
F 1 "SW_PUSH" H 9725 3545 50  0000 C CNN
F 2 "" H 9725 3625 50  0000 C CNN
F 3 "" H 9725 3625 50  0000 C CNN
	1    9725 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1483BA
P 9975 3325
F 0 "D?" H 9975 3425 50  0000 C CNN
F 1 "D" H 9975 3225 50  0000 C CNN
F 2 "" H 9975 3325 50  0001 C CNN
F 3 "" H 9975 3325 50  0001 C CNN
	1    9975 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1483C1
P 9725 4425
F 0 "SW?" H 9875 4535 50  0000 C CNN
F 1 "SW_PUSH" H 9725 4345 50  0000 C CNN
F 2 "" H 9725 4425 50  0000 C CNN
F 3 "" H 9725 4425 50  0000 C CNN
	1    9725 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1483C8
P 9975 4125
F 0 "D?" H 9975 4225 50  0000 C CNN
F 1 "D" H 9975 4025 50  0000 C CNN
F 2 "" H 9975 4125 50  0001 C CNN
F 3 "" H 9975 4125 50  0001 C CNN
	1    9975 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1483CF
P 9725 5200
F 0 "SW?" H 9875 5310 50  0000 C CNN
F 1 "SW_PUSH" H 9725 5120 50  0000 C CNN
F 2 "" H 9725 5200 50  0000 C CNN
F 3 "" H 9725 5200 50  0000 C CNN
	1    9725 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1483D6
P 9975 4900
F 0 "D?" H 9975 5000 50  0000 C CNN
F 1 "D" H 9975 4800 50  0000 C CNN
F 2 "" H 9975 4900 50  0001 C CNN
F 3 "" H 9975 4900 50  0001 C CNN
	1    9975 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1483EB
P 10375 1325
F 0 "SW?" H 10525 1435 50  0000 C CNN
F 1 "SW_PUSH" H 10375 1245 50  0000 C CNN
F 2 "" H 10375 1325 50  0000 C CNN
F 3 "" H 10375 1325 50  0000 C CNN
	1    10375 1325
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B1483F2
P 10625 1025
F 0 "D?" H 10625 1125 50  0000 C CNN
F 1 "D" H 10625 925 50  0000 C CNN
F 2 "" H 10625 1025 50  0001 C CNN
F 3 "" H 10625 1025 50  0001 C CNN
	1    10625 1025
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1483F9
P 10375 2075
F 0 "SW?" H 10525 2185 50  0000 C CNN
F 1 "SW_PUSH" H 10375 1995 50  0000 C CNN
F 2 "" H 10375 2075 50  0000 C CNN
F 3 "" H 10375 2075 50  0000 C CNN
	1    10375 2075
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148400
P 10625 1775
F 0 "D?" H 10625 1875 50  0000 C CNN
F 1 "D" H 10625 1675 50  0000 C CNN
F 2 "" H 10625 1775 50  0001 C CNN
F 3 "" H 10625 1775 50  0001 C CNN
	1    10625 1775
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148407
P 10375 2825
F 0 "SW?" H 10525 2935 50  0000 C CNN
F 1 "SW_PUSH" H 10375 2745 50  0000 C CNN
F 2 "" H 10375 2825 50  0000 C CNN
F 3 "" H 10375 2825 50  0000 C CNN
	1    10375 2825
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14840E
P 10625 2525
F 0 "D?" H 10625 2625 50  0000 C CNN
F 1 "D" H 10625 2425 50  0000 C CNN
F 2 "" H 10625 2525 50  0001 C CNN
F 3 "" H 10625 2525 50  0001 C CNN
	1    10625 2525
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148415
P 10375 3625
F 0 "SW?" H 10525 3735 50  0000 C CNN
F 1 "SW_PUSH" H 10375 3545 50  0000 C CNN
F 2 "" H 10375 3625 50  0000 C CNN
F 3 "" H 10375 3625 50  0000 C CNN
	1    10375 3625
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14841C
P 10625 3325
F 0 "D?" H 10625 3425 50  0000 C CNN
F 1 "D" H 10625 3225 50  0000 C CNN
F 2 "" H 10625 3325 50  0001 C CNN
F 3 "" H 10625 3325 50  0001 C CNN
	1    10625 3325
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148423
P 10375 4425
F 0 "SW?" H 10525 4535 50  0000 C CNN
F 1 "SW_PUSH" H 10375 4345 50  0000 C CNN
F 2 "" H 10375 4425 50  0000 C CNN
F 3 "" H 10375 4425 50  0000 C CNN
	1    10375 4425
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B14842A
P 10625 4125
F 0 "D?" H 10625 4225 50  0000 C CNN
F 1 "D" H 10625 4025 50  0000 C CNN
F 2 "" H 10625 4125 50  0001 C CNN
F 3 "" H 10625 4125 50  0001 C CNN
	1    10625 4125
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B148431
P 10375 5200
F 0 "SW?" H 10525 5310 50  0000 C CNN
F 1 "SW_PUSH" H 10375 5120 50  0000 C CNN
F 2 "" H 10375 5200 50  0000 C CNN
F 3 "" H 10375 5200 50  0000 C CNN
	1    10375 5200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5B148438
P 10625 4900
F 0 "D?" H 10625 5000 50  0000 C CNN
F 1 "D" H 10625 4800 50  0000 C CNN
F 2 "" H 10625 4900 50  0001 C CNN
F 3 "" H 10625 4900 50  0001 C CNN
	1    10625 4900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X07 J?
U 1 1 5B1654E1
P 2000 3400
F 0 "J?" H 2000 3800 50  0000 C CNN
F 1 "Display" V 2100 3400 50  0000 C CNN
F 2 "" H 2000 3400 50  0001 C CNN
F 3 "" H 2000 3400 50  0001 C CNN
	1    2000 3400
	0    1    1    0   
$EndComp
$Comp
L CONN_01X07 J?
U 1 1 5B16A050
P 4550 1375
F 0 "J?" H 4550 1775 50  0000 C CNN
F 1 "Outputs" V 4650 1375 50  0000 C CNN
F 2 "" H 4550 1375 50  0001 C CNN
F 3 "" H 4550 1375 50  0001 C CNN
	1    4550 1375
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X07 J?
U 1 1 5B16A24A
P 5175 975
F 0 "J?" H 5175 1375 50  0000 C CNN
F 1 "Outputs" V 5275 975 50  0000 C CNN
F 2 "" H 5175 975 50  0001 C CNN
F 3 "" H 5175 975 50  0001 C CNN
	1    5175 975 
	-1   0    0    1   
$EndComp
Wire Wire Line
	1000 2275 1500 2275
Wire Wire Line
	1000 1375 1100 1375
Wire Wire Line
	1100 2575 1500 2575
Wire Wire Line
	1100 1375 1100 2575
Wire Wire Line
	1000 1275 1500 1275
Wire Wire Line
	1000 1175 1500 1175
Wire Wire Line
	1500 2475 1425 2475
Wire Wire Line
	1425 2475 1425 2725
Wire Wire Line
	1750 2925 1800 2925
Wire Wire Line
	1400 5175 2225 5175
Wire Wire Line
	1400 5875 2225 5875
Wire Wire Line
	3275 4900 2075 4900
Wire Wire Line
	2075 4900 2075 5175
Connection ~ 2075 5175
Wire Wire Line
	3375 4950 2125 4950
Wire Wire Line
	2125 4950 2125 5875
Connection ~ 2125 5875
Wire Wire Line
	3275 4900 3275 4600
Wire Wire Line
	3375 4950 3375 4600
Wire Wire Line
	3175 4600 3175 4850
Wire Wire Line
	3175 4850 1925 4850
Wire Wire Line
	1925 4850 1925 5275
Wire Wire Line
	1925 5275 2225 5275
Wire Wire Line
	3075 4600 3075 4800
Wire Wire Line
	3075 4800 1875 4800
Wire Wire Line
	1875 4800 1875 5475
Wire Wire Line
	1875 5475 2225 5475
Wire Wire Line
	2975 4600 2975 4750
Wire Wire Line
	2975 4750 1825 4750
Wire Wire Line
	1825 4750 1825 5675
Wire Wire Line
	1825 5675 2225 5675
Wire Wire Line
	2875 4600 2875 4650
Wire Wire Line
	2875 4650 3775 4650
Wire Wire Line
	3775 4650 3775 5775
Wire Wire Line
	3775 5775 3325 5775
Wire Wire Line
	2775 4600 2775 4700
Wire Wire Line
	2775 4700 3675 4700
Wire Wire Line
	3675 4700 3675 5575
Wire Wire Line
	3675 5575 3325 5575
Wire Wire Line
	4100 2075 4200 2075
Wire Wire Line
	4100 2175 4175 2175
Wire Wire Line
	4100 975  4250 975 
Wire Wire Line
	4250 975  4250 2925
Wire Wire Line
	1400 5350 1400 5175
Connection ~ 1400 5175
Wire Wire Line
	1400 5650 1400 6800
Connection ~ 1400 5875
Wire Wire Line
	4100 875  4275 875 
Wire Wire Line
	4275 875  4275 2950
Wire Wire Line
	1400 2750 1700 2750
Wire Wire Line
	1400 6800 2475 6800
Wire Wire Line
	1575 5175 1575 6750
Wire Wire Line
	1575 6750 2575 6750
Wire Wire Line
	2575 6750 2575 6800
Connection ~ 1575 5175
Wire Wire Line
	2225 5375 1975 5375
Wire Wire Line
	1975 5375 1975 6500
Wire Wire Line
	1975 6500 2875 6500
Wire Wire Line
	2875 6500 2875 6800
Wire Wire Line
	2225 5575 2075 5575
Wire Wire Line
	2075 5575 2075 6400
Wire Wire Line
	2075 6400 2975 6400
Wire Wire Line
	2975 6400 2975 6800
Wire Wire Line
	4100 2275 4225 2275
Wire Wire Line
	2225 5775 2175 5775
Wire Wire Line
	2175 5775 2175 6150
Wire Wire Line
	2175 6150 3075 6150
Wire Wire Line
	3075 6150 3075 6800
Wire Wire Line
	2775 6800 2775 6750
Wire Wire Line
	2775 6750 3675 6750
Wire Wire Line
	3675 6750 3675 5675
Wire Wire Line
	3675 5675 3325 5675
Wire Wire Line
	2675 6800 2675 6700
Wire Wire Line
	2675 6700 3625 6700
Wire Wire Line
	3625 6700 3625 5875
Wire Wire Line
	3625 5875 3325 5875
Wire Wire Line
	6475 1025 6575 1025
Wire Wire Line
	6475 1775 6575 1775
Wire Wire Line
	6475 2525 6575 2525
Wire Wire Line
	6475 3325 6575 3325
Wire Wire Line
	6475 4125 6575 4125
Wire Wire Line
	6475 4900 6575 4900
Wire Wire Line
	5375 700  10125 700 
Wire Wire Line
	5425 750  8825 750 
Wire Wire Line
	5450 775  8175 775 
Wire Wire Line
	5475 800  7525 800 
Wire Wire Line
	5500 825  6875 825 
Wire Wire Line
	6050 1625 6050 2425
Wire Wire Line
	6050 2425 5750 2425
Wire Wire Line
	5750 2525 6075 2525
Wire Wire Line
	6075 2525 6075 2375
Wire Wire Line
	5750 2625 6075 2625
Wire Wire Line
	6075 2625 6075 3125
Wire Wire Line
	5750 2725 6050 2725
Wire Wire Line
	6050 2725 6050 3925
Wire Wire Line
	5750 2825 6025 2825
Wire Wire Line
	6025 2825 6025 4725
Wire Wire Line
	5750 2925 6000 2925
Wire Wire Line
	6000 2925 6000 5500
Wire Wire Line
	7125 1025 7225 1025
Wire Wire Line
	7125 1775 7225 1775
Wire Wire Line
	7125 2525 7225 2525
Wire Wire Line
	7125 3325 7225 3325
Wire Wire Line
	7125 4125 7225 4125
Wire Wire Line
	7125 4900 7225 4900
Wire Wire Line
	7775 1025 7875 1025
Wire Wire Line
	7775 1775 7875 1775
Wire Wire Line
	7775 2525 7875 2525
Wire Wire Line
	7775 3325 7875 3325
Wire Wire Line
	7775 4125 7875 4125
Wire Wire Line
	7775 4900 7875 4900
Wire Wire Line
	8425 1025 8525 1025
Wire Wire Line
	8425 1775 8525 1775
Wire Wire Line
	8425 2525 8525 2525
Wire Wire Line
	8425 3325 8525 3325
Wire Wire Line
	8425 4125 8525 4125
Wire Wire Line
	8425 4900 8525 4900
Wire Wire Line
	9075 1025 9175 1025
Wire Wire Line
	9075 1775 9175 1775
Wire Wire Line
	9075 2525 9175 2525
Wire Wire Line
	9075 3325 9175 3325
Wire Wire Line
	9075 4125 9175 4125
Wire Wire Line
	9075 4900 9175 4900
Wire Wire Line
	9725 1025 9825 1025
Wire Wire Line
	9725 1775 9825 1775
Wire Wire Line
	9725 2525 9825 2525
Wire Wire Line
	9725 3325 9825 3325
Wire Wire Line
	9725 4125 9825 4125
Wire Wire Line
	9725 4900 9825 4900
Wire Wire Line
	10375 1025 10475 1025
Wire Wire Line
	10375 1775 10475 1775
Wire Wire Line
	10375 2525 10475 2525
Wire Wire Line
	10375 3325 10475 3325
Wire Wire Line
	10375 4125 10475 4125
Wire Wire Line
	10375 4900 10475 4900
Wire Wire Line
	6000 5500 10375 5500
Connection ~ 9725 5500
Connection ~ 9075 5500
Connection ~ 8425 5500
Connection ~ 7775 5500
Wire Wire Line
	6025 4725 10375 4725
Connection ~ 8425 4725
Connection ~ 7775 4725
Connection ~ 7125 5500
Connection ~ 6475 5500
Connection ~ 7125 4725
Connection ~ 6475 4725
Wire Wire Line
	6050 3925 10375 3925
Connection ~ 6475 3925
Connection ~ 7125 3925
Wire Wire Line
	6075 3125 10375 3125
Connection ~ 7125 3125
Wire Wire Line
	6075 2375 10375 2375
Connection ~ 7125 2375
Connection ~ 7775 2375
Connection ~ 8425 2375
Connection ~ 7775 3125
Connection ~ 8425 3125
Connection ~ 9075 3125
Connection ~ 9725 3125
Connection ~ 9075 2375
Wire Wire Line
	6050 1625 10375 1625
Connection ~ 9075 1625
Connection ~ 8425 1625
Connection ~ 7775 3925
Connection ~ 8425 3925
Connection ~ 9075 3925
Connection ~ 9725 3925
Connection ~ 9075 4725
Connection ~ 9725 4725
Connection ~ 9725 2375
Connection ~ 9725 1625
Connection ~ 6875 1025
Connection ~ 6875 1775
Connection ~ 6875 2525
Connection ~ 6875 3325
Connection ~ 6875 4125
Connection ~ 6875 4900
Wire Wire Line
	7525 800  7525 4900
Wire Wire Line
	8175 775  8175 4900
Wire Wire Line
	8825 750  8825 4900
Wire Wire Line
	9475 725  9475 4900
Wire Wire Line
	10125 700  10125 4900
Connection ~ 10125 4900
Connection ~ 9475 4900
Connection ~ 8825 4900
Connection ~ 8175 4900
Connection ~ 7525 4900
Connection ~ 7525 4125
Connection ~ 8175 4125
Connection ~ 8825 4125
Connection ~ 9475 4125
Connection ~ 10125 4125
Wire Wire Line
	10775 675  10775 4900
Connection ~ 10775 4125
Connection ~ 10125 3325
Connection ~ 10775 3325
Connection ~ 9475 3325
Connection ~ 8825 3325
Connection ~ 8175 3325
Connection ~ 7525 3325
Connection ~ 7525 2525
Connection ~ 8175 2525
Connection ~ 8825 2525
Connection ~ 9475 2525
Connection ~ 10125 2525
Connection ~ 10775 2525
Connection ~ 10775 1775
Connection ~ 10125 1775
Connection ~ 9475 1775
Connection ~ 8825 1775
Connection ~ 8175 1775
Connection ~ 7525 1775
Connection ~ 7525 1025
Connection ~ 8175 1025
Connection ~ 8825 1025
Connection ~ 9475 1025
Connection ~ 10125 1025
Connection ~ 10775 1025
Wire Wire Line
	5400 725  9475 725 
Wire Wire Line
	5375 675  10775 675 
Connection ~ 7125 1625
Connection ~ 7775 1625
Connection ~ 10775 4900
Connection ~ 6475 1625
Connection ~ 6475 2375
Connection ~ 6475 3125
Wire Wire Line
	1800 2925 1800 3200
Wire Wire Line
	4250 2925 1900 2925
Wire Wire Line
	1900 2925 1900 3200
Wire Wire Line
	4275 2950 2000 2950
Wire Wire Line
	2000 2950 2000 3200
Wire Wire Line
	4175 2175 4175 2975
Wire Wire Line
	4175 2975 2100 2975
Wire Wire Line
	2100 2975 2100 3200
Wire Wire Line
	4200 2075 4200 3000
Wire Wire Line
	4200 3000 2200 3000
Wire Wire Line
	2200 3000 2200 3200
Wire Wire Line
	1700 2750 1700 3200
Wire Wire Line
	4225 2275 4225 3025
Wire Wire Line
	4225 3025 2300 3025
Wire Wire Line
	2300 3025 2300 3200
Wire Wire Line
	4100 1075 4350 1075
Wire Wire Line
	4100 1175 4350 1175
Wire Wire Line
	4100 1275 4350 1275
Wire Wire Line
	4100 1375 4350 1375
Wire Wire Line
	4100 1475 4350 1475
Wire Wire Line
	4100 1575 4350 1575
Wire Wire Line
	4100 1675 4350 1675
Wire Wire Line
	5375 700  5375 775 
Wire Wire Line
	5400 725  5400 875 
Wire Wire Line
	5400 875  5375 875 
Wire Wire Line
	5375 975  5425 975 
Wire Wire Line
	5425 975  5425 750 
Wire Wire Line
	5375 1075 5450 1075
Wire Wire Line
	5450 1075 5450 775 
Wire Wire Line
	5375 1175 5475 1175
Wire Wire Line
	5475 1175 5475 800 
Wire Wire Line
	5375 1275 5500 1275
Wire Wire Line
	5500 1275 5500 825 
$Comp
L Conn_01x06 J?
U 1 1 5B11C0D9
P 5550 2725
F 0 "J?" H 5550 3025 50  0000 C CNN
F 1 "Inputs" V 5650 2675 50  0000 C CNN
F 2 "" H 5550 2725 50  0001 C CNN
F 3 "" H 5550 2725 50  0001 C CNN
	1    5550 2725
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x06 J?
U 1 1 5B11C290
P 1225 3400
F 0 "J?" H 1225 3700 50  0000 C CNN
F 1 "Inputs" V 1325 3350 50  0000 C CNN
F 2 "" H 1225 3400 50  0001 C CNN
F 3 "" H 1225 3400 50  0001 C CNN
	1    1225 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	1425 2725 1750 2725
Wire Wire Line
	1750 2725 1750 2925
Wire Wire Line
	1000 1475 1000 2275
Wire Wire Line
	1400 2275 1400 2750
Connection ~ 1400 2275
Wire Wire Line
	1425 3200 1425 2900
Wire Wire Line
	1425 2900 1300 2900
Wire Wire Line
	1300 2900 1300 1975
Wire Wire Line
	1300 1975 1500 1975
Wire Wire Line
	1325 3200 1325 2925
Wire Wire Line
	1325 2925 1275 2925
Wire Wire Line
	1275 2925 1275 1875
Wire Wire Line
	1275 1875 1500 1875
Wire Wire Line
	1225 3200 1250 3200
Wire Wire Line
	1250 3200 1250 1775
Wire Wire Line
	1250 1775 1500 1775
Wire Wire Line
	1500 1675 1225 1675
Wire Wire Line
	1225 1675 1225 2925
Wire Wire Line
	1225 2925 1125 2925
Wire Wire Line
	1125 2925 1125 3200
Wire Wire Line
	1500 1575 1200 1575
Wire Wire Line
	1200 1575 1200 2900
Wire Wire Line
	1200 2900 1025 2900
Wire Wire Line
	1025 2900 1025 3200
Wire Wire Line
	1500 1475 1175 1475
Wire Wire Line
	1175 1475 1175 2875
Wire Wire Line
	1175 2875 925  2875
Wire Wire Line
	925  2875 925  3200
Wire Wire Line
	6875 825  6875 4900
$EndSCHEMATC
