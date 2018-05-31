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
P 3225 2350
F 0 "U?" H 2675 3450 50  0000 C CNN
F 1 "MCP23017" H 3675 1250 50  0000 C CNN
F 2 "MODULE" H 2725 1250 50  0001 C CNN
F 3 "DOCUMENTATION" H 3225 2300 50  0001 C CNN
	1    3225 2350
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
P 1600 2350
F 0 "R?" V 1680 2350 50  0000 C CNN
F 1 "4.7k" V 1600 2350 50  0000 C CNN
F 2 "" V 1530 2350 50  0001 C CNN
F 3 "" H 1600 2350 50  0001 C CNN
	1    1600 2350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B107671
P 1775 2350
F 0 "R?" V 1855 2350 50  0000 C CNN
F 1 "4.7k" V 1775 2350 50  0000 C CNN
F 2 "" V 1705 2350 50  0001 C CNN
F 3 "" H 1775 2350 50  0001 C CNN
	1    1775 2350
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
P 2025 1550
F 0 "C?" H 2050 1650 50  0000 L CNN
F 1 "0.1uF" H 2050 1450 50  0000 L CNN
F 2 "" H 2063 1400 50  0001 C CNN
F 3 "" H 2025 1550 50  0001 C CNN
	1    2025 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 3700 3225 3700
Wire Wire Line
	2275 1000 2275 1300
Wire Wire Line
	2275 1300 2275 1450
Wire Wire Line
	825  1300 1600 1300
Wire Wire Line
	1600 1300 1775 1300
Wire Wire Line
	1775 1300 2025 1300
Wire Wire Line
	2025 1300 2275 1300
Wire Wire Line
	2275 1000 3225 1000
Connection ~ 2275 1300
Wire Wire Line
	925  1900 2025 1900
Wire Wire Line
	2025 1900 2025 1900
Wire Wire Line
	2025 1900 2275 1900
Connection ~ 2025 1900
Wire Wire Line
	2025 2000 2275 2000
Connection ~ 2025 2000
Wire Wire Line
	2025 2100 2275 2100
Connection ~ 2025 2100
Wire Wire Line
	1200 2850 1775 2850
Wire Wire Line
	1775 2850 2275 2850
Wire Wire Line
	1200 2850 1200 1100
Wire Wire Line
	1200 1100 825  1100
Wire Wire Line
	825  1200 1150 1200
Wire Wire Line
	1150 1200 1150 2950
Wire Wire Line
	1150 2950 1600 2950
Wire Wire Line
	1600 2950 2275 2950
Wire Wire Line
	1600 2200 1600 1300
Connection ~ 1600 1300
Wire Wire Line
	1775 2200 1775 1300
Connection ~ 1775 1300
Wire Wire Line
	1775 2850 1775 2500
Connection ~ 1775 2850
Wire Wire Line
	1600 2500 1600 2950
Connection ~ 1600 2950
Wire Wire Line
	2025 1300 2025 1400
Connection ~ 2025 1300
Wire Wire Line
	2025 1900 2025 1700
Wire Wire Line
	925  1900 925  1400
Wire Wire Line
	925  1400 825  1400
Wire Wire Line
	2025 1900 2025 1900
Wire Wire Line
	2025 1900 2025 2000
Wire Wire Line
	2025 2000 2025 2100
Wire Wire Line
	2025 2100 2025 3700
Connection ~ 2025 1900
$EndSCHEMATC
