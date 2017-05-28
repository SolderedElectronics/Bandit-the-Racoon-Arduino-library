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
// Utilities slide switch for LEDs control.
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

  //write current slide switch status to Serial monitor
  Serial.println(bandit.slide()); //writes 0 or 1
  
  //0 meaning up position, 1 meaning down position

  //depending on slide switch position, different LED colors are shown
  if (bandit.slide()) bandit.LED_on("red");
  else bandit.LED_on("green");          
}