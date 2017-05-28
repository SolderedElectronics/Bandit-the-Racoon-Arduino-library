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
// Reads light level with photoresistor and make VU meter for light on LEDs.
// If any questions, 
// just contact hello@e-r.io
//==============================================================================

#include "BTR.h"

//BTR class
BTR bandit;

void setup() {
  //must be called on each startup
  bandit.begin();

  Serial.begin(9600);
}

void loop() {

  //write readings frol LDR on Serial monitor
  Serial.print(bandit.ldr()); // ispisuje 10-bitna ocitanja (0-1023)
  
  //following code makes VU meter from the onboard light sensor
  int vu_metar = map(bandit.ldr(), 0, 1023, 0, 12); //map reading resolution
                                                    //to the number of LEDs
  for( int i = 0; i <= vu_metar; i++) {
    bandit.LED_on(i, "green"); //turn affected LEDs green
  }

  for( int i = 12; i > vu_metar; i--) {
    bandit.LED_on(i, 0,0,0);    //others should go off
  }
                           
}
