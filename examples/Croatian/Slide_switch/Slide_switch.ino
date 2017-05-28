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

// nužno kreirati novu klasu
BTR bandit;

void setup() {
  // postavlja WS2801
  bandit.begin();

  // zapocinje serijsku komunikaciju
  Serial.begin(9600);
}

void loop() {

  // ispisi ocitanja s slide-a u SerialMonitoru 
  // ->
  Serial.println(bandit.slide()); // ispisuje 0 ili 1
  
  // slide vraća bool na način
  // 0: pozdicija gore; 1: pozicija gore

  // ovisno o pozicija slidera izvodi LED funkcije
  // ->
  if (bandit.slide()) bandit.upaliLED("crvena");
  else bandit.upaliLED("zelena");
                           
}
