//==============================================================================
//    E - R A D I O N I C A . C O M,  H.Kolomana 6/A, Djakovo 31400, Croatia
//==============================================================================
// Project   :  Bandit the Racoon Arduino Library
// File      :  BTR Arduino Example
// Author    :  e-r.io 2017
// Licence   :  Open-source ! 
//==============================================================================
//==============================================================================
// To be used with Bandit the Racoon board:
// https://e-radionica.com/en/bandit-the-raccoon-btr.html
// Reads potentiometer in Serial, changes LEDs effect depending on poti adjustment.
// If any questions, 
// just contact hello@e-r.io
//==============================================================================

#include "BTR.h"

//make new object for a class
BTR bandit;

void setup() {
  //must be called
  bandit.begin();

  Serial.begin(9600);
}

void loop() {

  //write potentiometer readings in Serial monitor
  Serial.print(bandit.poti()); //writes 10-bit reading(0-1023)
  Serial.println("\t" + String(bandit.potiV()) + " mV"); //show poti reading in [mV]

  //uses potentiometer readings to change speed/brightness of LEDs
  bandit.circus("poti",0);  //potentiometer changes the:
                            //if 0 as second attribute - change speed
                            //if 1 as second attribute - change brightness
                           
}
