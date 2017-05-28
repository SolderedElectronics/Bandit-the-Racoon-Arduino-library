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

// nužno kreirati novu klasu
BTR bandit;

void setup() {
  // postavlja WS2801
  bandit.begin();

  // mozes postaviti globalnu svjetlinu LED dioda u [%]
  bandit.postaviJacinu(50);

  // funkciju upaliLED() mozes koristiti na nekoliko nacina:
  // -->

  // upali specificnu LEDicu u RGB formatu (0-255)
  // brojevi LEDica nalaze se na pcb-u, a idu u smjeru
  // kazaljke na satu od 1 do 12
  bandit.upaliLED(1, 0, 255, 255); // rd.br. LEDice, crvena, zelena, plava
  delay(2000);

  // upali sve LEDice u RGB formatu
  bandit.upaliLED(240, 20, 240);  // crvena, zelena, plava
  // delay dunkcija
  for(int i=0; i < 2000; i++) {
    // tokom loop-a mozes mijenjati svjetlinu LEDica pomocu
    bandit.postaviJacinu(bandit.poti(), 1);  // poti() vraca ocitanja s potenciometra,
                                              // 1 za koristenje analognih, umjesto vrijednost u [%]
    delay(1);
  }

  // upali specifičnu LEDicu bojom u String formatu
  bandit.upaliLED(1, "crvena");   // rd.br. LEDice, boja u string formatu
  delay(2000);

  // gasi sve LEDice
  bandit.ugasiLED();
  delay(1000);

  // neki predefinirani efekti za LEDice
  bandit.duga();
  
}

void loop() {
  
  // funkciju je moguce pozvati i na ovaj nacin 
  // ->
  bandit.cirkus("poti",0);  // gdje potenciometar upravlja brzinom izvodjenja
                            // 0 - oznacava mijenjaj brzinu
                            // 1 - oznacava mijenjaj svjetlinu
                            
}