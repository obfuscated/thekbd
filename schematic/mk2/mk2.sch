EESchema Schematic File Version 4
LIBS:mk2-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3025 2000 2050 2050
U 5A14AEE6
F0 "left_side" 60
F1 "left_side.sch" 60
F2 "SDA" B R 5075 2625 60 
F3 "SCL" B R 5075 2850 60 
F4 "5V" B R 5075 3100 60 
F5 "GND" B R 5075 3350 60 
$EndSheet
$Sheet
S 7275 2350 1750 1275
U 5A14AF05
F0 "right_side" 60
F1 "right_side.sch" 60
F2 "SDA" I L 7275 2700 60 
F3 "SCL" I L 7275 2850 60 
F4 "5V" I L 7275 3025 60 
F5 "GND" I L 7275 3200 60 
$EndSheet
Wire Wire Line
	5075 2625 6250 2625
Wire Wire Line
	6250 2625 6250 2700
Wire Wire Line
	6250 2700 7275 2700
Wire Wire Line
	5075 2850 7275 2850
Wire Wire Line
	5075 3100 6250 3100
Wire Wire Line
	6250 3100 6250 3025
Wire Wire Line
	6250 3025 7275 3025
Wire Wire Line
	5075 3350 6250 3350
Wire Wire Line
	6250 3350 6250 3200
Wire Wire Line
	6250 3200 7275 3200
$EndSCHEMATC
