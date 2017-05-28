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

// nužno kreirati novu klasu
BTR bandit;

void setup() {
  // postavlja WS2801
  bandit.begin();

  // zapocinje serijsku komunikaciju
  Serial.begin(9600);
}

void loop() {

  // ispisi ocitanja s potenciometra u SerialMonitoru 
  // ->
  Serial.print(bandit.poti()); // ispisuje 10-bitna ocitanja (0-1023)
  Serial.println("\t" + String(bandit.potiV()) + " mV"); // pretvara ocitanja u [mV]

  // koristi ocitanja s potenciometrom za upravljanje brzine izvođenja
  // LED.cirkus funkcije ->
  bandit.cirkus("poti",0); // s obzirom na potenciometar,
                           // 0 - oznacava mijenjaj brzinu
                           // 1 - oznacava mijenjaj svjetlinu
                           
}
