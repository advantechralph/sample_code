
'*****************************************************/
'*
'NHD-14432WG.bas
'Program for writing to Newhaven Display 144x32 -WG series Graphic LCD
'
'c.2008 Curt Lagerstam - Newhaven Display International, LLC.
'
'  This program is free software; you can redistribute it and/or modify
' it under the terms of the GNU General Public License as published by
' the Free Software Foundation; either version 2 of the License, or
' (at your option) any later version.
'
' This program is distributed in the hope that it will be useful,
' but WITHOUT ANY WARRANTY; without even the implied warranty of
' MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
' GNU General Public License for more details.
'/
'*****************************************************/
'-------------------------------------------------------------------------------
'-------------------------------------------------------------------------------
'NHD-14432WG
'144x32 Graphic LCD
'pin1 = VSS
'pin2 = VDD
'pin3 = V0
'pin4 = RS = P3.0
'pin5 = RW = P3.7
'pin6 = E = P3.4
'pin7-14 = Data = P1
'pin15,16 = BKL
'-------------------------------------------------------------------------------
Declare Sub Wcom
Declare Sub Wdata
Declare Sub Init
Declare Sub Show
Dim A As Byte
Dim Count As Byte
Dim Counthi As Byte
Dim Col As Byte
$large
'-------------------------------------------------------------------------------

Waitms 100
Reset P3.0
Reset P1

Do
Call Init
Call Show
Wait 1
Loop
'-------------------------------------------------------------------------------
Sub Init
A = &H38
Call Wcom
A = &H0C
Call Wcom
A = &H06
Call Wcom
A = &H02
Call Wcom
A = &H01
Call Wcom
Waitms 2
Col = &H80
For Counthi = 1 To 32
 A = &H3E
 Call Wcom
 A = Col
 Call Wcom
 A = &H80
 Call Wcom
 For Count = 1 To 36
  A = &H00
  Call Wdata
 Next Count
 Incr Col
Next Counthi
End Sub
'-------------------------------------------------------------------------------
Sub Page1
Restore Dta1
Col = &H80
For Counthi = 1 To 32
 A = &H3E
 Call Wcom
 A = Col
 Call Wcom
 A = &H80
 Call Wcom
 For Count = 1 To 18
  Read A
  Call Wdata
 Next Count
 Incr Col
Next Counthi
End Sub
'-------------------------------------------------------------------------------
Sub Wcom
P1 = A
Reset P3.0
Reset P3.7
Set P3.4
Set P3.1
Reset P3.1
Reset P3.4
End Sub

Sub Wdata
P1 = A
Set P3.0
Reset P3.7
Set P3.4
Set P3.1
Reset P3.1
Reset P3.4
End Sub

Dta1:
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H33 , &H7F , &H11 , &HE6 , &H38 , &HC6 , &HFB , &H30 , &HF9 , &H9E , &H7C , &HC0 , &H71 , &H98 , &H00 , &H00,
Data &H00 , &H00 , &H33 , &H63 , &H39 , &HE6 , &H38 , &HC6 , &HC3 , &H30 , &HCD , &HB3 , &H66 , &HC0 , &H71 , &H98 , &H00 , &H00,
Data &H00 , &H00 , &H3B , &H61 , &HBB , &H66 , &H6C , &H6C , &HC3 , &HB0 , &HCD , &HB0 , &H66 , &HC0 , &HD8 , &H90 , &H00 , &H00,
Data &H00 , &H00 , &H3B , &H7D , &HAB , &H7E , &H6C , &H6C , &HFB , &HB0 , &HCD , &HBC , &H66 , &HC0 , &HD8 , &HF0 , &H00 , &H00,
Data &H00 , &H00 , &H37 , &H61 , &HAB , &H66 , &H6C , &H6C , &HC3 , &H70 , &HCD , &H8F , &H7C , &HC0 , &HD8 , &H60 , &H00 , &H00,
Data &H00 , &H00 , &H37 , &H61 , &HEF , &H66 , &HFE , &H6C , &HC3 , &H70 , &HCD , &H83 , &H60 , &HC1 , &HFC , &H60 , &H00 , &H00,
Data &H00 , &H00 , &H33 , &H60 , &HC6 , &H66 , &HC6 , &H38 , &HC3 , &H30 , &HCD , &HB3 , &H60 , &HC1 , &H8C , &H60 , &H00 , &H00,
Data &H00 , &H00 , &H33 , &H7C , &HC6 , &H66 , &HC6 , &H38 , &HFB , &H30 , &HF9 , &H9E , &H60 , &HFD , &H8C , &H60 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &HCC , &HCC , &HF8 , &H06 , &H0C , &H33 , &HCF , &H66 , &H67 , &H80 , &H18 , &HFC , &HFD , &H98 , &H31 , &H94 , &H00,
Data &H00 , &HEC , &HCC , &HC4 , &H06 , &H1C , &H76 , &H79 , &HE6 , &H6C , &H60 , &H1C , &H30 , &HC1 , &H98 , &H11 , &H14 , &H00,
Data &H00 , &HEC , &HCC , &HC6 , &H1E , &H2C , &HB6 , &H79 , &HA6 , &H58 , &H60 , &H3C , &H30 , &HC1 , &H98 , &H19 , &H14 , &H00,
Data &H00 , &HEC , &HFC , &HC6 , &H06 , &H2C , &HB0 , &H61 , &H35 , &H58 , &H00 , &H24 , &H30 , &HF9 , &HF8 , &H1B , &H7E , &H00,
Data &H00 , &HDC , &HCC , &HC7 , &HC6 , &H4D , &H31 , &HC3 , &H39 , &HD8 , &HEE , &H66 , &H30 , &HC1 , &H9B , &H8A , &H24 , &H00,
Data &H00 , &HDC , &HCC , &HC6 , &H06 , &H7F , &HF8 , &H66 , &H19 , &H98 , &H60 , &H7E , &H30 , &HC1 , &H98 , &H0A , &H7E , &H00,
Data &H00 , &HCC , &HCC , &HCC , &H06 , &H0C , &H36 , &H6C , &H19 , &H8C , &H60 , &H42 , &H30 , &HC1 , &H98 , &H0E , &H28 , &H00,
Data &H00 , &HCC , &HCC , &HF8 , &H06 , &H0C , &H33 , &HDF , &H99 , &H87 , &HA0 , &HC3 , &H30 , &HC1 , &H98 , &H04 , &H28 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00,
