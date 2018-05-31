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
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 825  1100 0    60   Input ~ 0
SDA
Text HLabel 825  1200 0    60   Input ~ 0
SCL
Text HLabel 825  1300 0    60   Input ~ 0
5V
Text HLabel 825  1400 0    60   Input ~ 0
GND
$Comp
L MCP23017 U?
U 1 1 5B107333
P 3225 2425
F 0 "U?" H 2675 3525 50  0000 C CNN
F 1 "MCP23017" H 3675 1325 50  0000 C CNN
F 2 "MODULE" H 2725 1325 50  0001 C CNN
F 3 "DOCUMENTATION" H 3225 2375 50  0001 C CNN
	1    3225 2425
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5B1075AB
P 5750 2325
F 0 "SW?" H 5900 2435 50  0000 C CNN
F 1 "SW_PUSH" H 5750 2245 50  0000 C CNN
F 2 "" H 5750 2325 50  0000 C CNN
F 3 "" H 5750 2325 50  0000 C CNN
	1    5750 2325
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B10760C
P 1600 3175
F 0 "R?" V 1680 3175 50  0000 C CNN
F 1 "R" V 1600 3175 50  0000 C CNN
F 2 "" V 1530 3175 50  0001 C CNN
F 3 "" H 1600 3175 50  0001 C CNN
	1    1600 3175
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B107671
P 1700 2750
F 0 "R?" V 1780 2750 50  0000 C CNN
F 1 "R" V 1700 2750 50  0000 C CNN
F 2 "" V 1630 2750 50  0001 C CNN
F 3 "" H 1700 2750 50  0001 C CNN
	1    1700 2750
	1    0    0    -1  
$EndComp
$Comp
L D D?
U 1 1 5B10770C
P 5800 3100
F 0 "D?" H 5800 3200 50  0000 C CNN
F 1 "D" H 5800 3000 50  0000 C CNN
F 2 "" H 5800 3100 50  0001 C CNN
F 3 "" H 5800 3100 50  0001 C CNN
	1    5800 3100
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5B1074A2
P 3725 4225
F 0 "C?" H 3750 4325 50  0000 L CNN
F 1 "C" H 3750 4125 50  0000 L CNN
F 2 "" H 3763 4075 50  0001 C CNN
F 3 "" H 3725 4225 50  0001 C CNN
	1    3725 4225
	1    0    0    -1  
$EndComp
$EndSCHEMATC
