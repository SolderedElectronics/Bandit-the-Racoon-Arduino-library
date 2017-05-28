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
// Different examples for LED control.
// If any questions, 
// just contact hello@e-r.io
//==============================================================================

#include "BTR.h"

//create BTR class object
BTR bandit;

void setup() {
  //must be called on each startup
  bandit.begin();

  //global brightness of LEDs in [%] can be set with this function
  bandit.set_brightness(50);

  //function LED_on can be used in a few ways:

  //turn on specific LED in RGB format (0-255)
  //number of each LED is written on the PCB, they are going clockwise
  //from 1st to 12th
  bandit.LED_on(1, 0, 255, 255); //number of led, red, green, blue
  delay(2000);

  //this turns all LEDs in RGB format
  bandit.LED_on(240, 20, 240);  //red, green, blue

  //during this loop you can chnage brightness of LEDs using potentiometer
  for(int i=0; i < 2000; i++) {
    bandit.set_brightness(bandit.poti(), 1);  //poti() returns reading from potientiometer
                                              //1 for using analog, instead of percentage[%] values
    delay(1);
  }

  //turn on specific LED to specific color(String)
  bandit.LED_on(1, "red");   //number of LED, color
  //colors available: red, green, blue - At the moment

  delay(2000);

  //turn off all LEDs
  bandit.LED_off();
  delay(1000);

  //predefined LED effects
  bandit.rainbox();
  delay(1000);
}

void loop() {
  
  // function can be called at this was:
  bandit.circus("poti",0);  //potentiometer changes the:
                            //if 0 as second attribute - change speed
                            //if 1 as second attribute - change brightness
                            
}