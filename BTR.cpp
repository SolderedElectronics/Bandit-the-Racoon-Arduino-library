//==============================================================================
//    E - R A D I O N I C A . C O M,  H.Kolomana 6/A, Djakovo 31400, Croatia
//==============================================================================
// Project   :  Bandit the Racoon Arduino Library
// File      :  BTR.cpp
// Author    :  e-r.io 2017
// Licence   :  Open-source ! 
//==============================================================================
//==============================================================================
// To be used with Bandit the Racoon board:
// https://e-radionica.com/en/bandit-the-raccoon-btr.html
// If any questions, 
// just contact hello@e-r.io
//==============================================================================


#include <Arduino.h>
#include <BTR.h>
#include <Adafruit_NeoPixel.h>


//==============================================================================
// PUBLIC
//==============================================================================
//==============================================================================

Adafruit_NeoPixel clock = Adafruit_NeoPixel(WS2801_LENGHT, WS2812B_PIN, NEO_GRB + NEO_KHZ800);

// global variable to set level of LED brightnes
uint8_t LED_level = 100;

// global variable for AREF value in [mV]
uint16_t xAREF = 5000;

//==============================================================================
// general
//==============================================================================

void BTR::begin() {
	// set WS2812
  clock.begin();
  clock.show();

  // set GPIOs
}

//==============================================================================
// WS2801
//==============================================================================

void BTR::upaliLED(uint8_t _p, uint8_t _r, uint8_t _g, uint8_t _b) {
  clock.setPixelColor( _p-1, clock.Color(returnBrightness(_r), returnBrightness(_g), returnBrightness(_b)));
  clock.show();
}
//translated
void BTR::LED_on(uint8_t _p, uint8_t _r, uint8_t _g, uint8_t _b) {
  upaliLED(_p, _r, _g, _b);
}

void BTR::upaliLED(uint8_t _r, uint8_t _g, uint8_t _b) {
  for(int i=0; i<WS2801_LENGHT; i++) {
    clock.setPixelColor(i, clock.Color(returnBrightness(_r), returnBrightness(_g), returnBrightness(_b)));
  }

  clock.show();
}
//translated
void BTR::LED_on(_r, _g, _b) {
  upaliLED(_r, _g, _b);
}

void BTR::upaliLED(uint8_t _p, String _c) {
  if (_c == "crvena") upaliLED(_p, 240,20,20);
  else if (_c == "zelena") upaliLED(_p, 20,240,20);
  else if (_c == "plava") upaliLED(_p, 20,20,240);
}
//translated
void BTR::LED_on(uint8_t _p, String _c) {
  if (_c == "red") upaliLED(_p, 240,20,20);
  else if (_c == "green") upaliLED(_p, 20,240,20);
  else if (_c == "blue") upaliLED(_p, 20,20,240);
}

void BTR::upaliLED(String _c) {
  if (_c == "crvena") upaliLED(240,20,20);
  else if (_c == "zelena") upaliLED(20,240,20);
  else if (_c == "plava") upaliLED(20,20,240);
}
//translated
void BTR::upaliLED(String _c) {
  if (_c == "red") upaliLED(240,20,20);
  else if (_c == "green") upaliLED(20,240,20);
  else if (_c == "blue") upaliLED(20,20,240);
}

void BTR::postaviJacinu(uint8_t _l) {
  if (_l > 100) _l = 100;
  LED_level = _l;
}
//translated
void BTR::set_brightness(uint8_t _l) {
  postaviJacinu(_l);
}

void BTR::postaviJacinu(uint16_t _pot, bool _bA) {
  if (_bA) LED_level = map(_pot,0,1023,100,0);
  else postaviJacinu(_pot);
}
//translated
void BTR::set_brightness(uint16_t _pot, bool _bA) {
  postaviJacinu(_pot, _bA);
}


void BTR::duga() {
  uint8_t wait = 20;
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<clock.numPixels(); i++) {
      clock.setPixelColor(i, Wheel((i+j) & 255));
    }
    clock.show();
    delay(wait);
  }
  //turn of all LEDs in case of non-loop function
  upaliLED(0,0,0);
}
//translated
void BTR::rainbox() { duga(); }

void BTR::duga(String _s, bool _b) {
  uint16_t i, j;
  uint8_t wait = 30;

  for(j=0; j<256; j++) {
    for(i=0; i<clock.numPixels(); i++) {
      clock.setPixelColor(i, Wheel((i+j) & 255));
    }
    clock.show();

    // bool _b -> 0: change speed; 1: change brightness
    if (_b) {
     if (_s == "poti" || _s == "potenciometar") postaviJacinu(analogRead(POTI),1);
     else if (_s == "foto" || _s == "fotootpornik" || _s == "ldr") postaviJacinu(analogRead(LDR),1);
     else if (_s == "temp" || _s == "temperatura") postaviJacinu(analogRead(TEMP),1);
    }

    else {
      if (_s == "poti" || _s == "potenciometar") map(analogRead(POTI),1023,0,600,0);
      else if (_s == "foto" || _s == "fotootpornik" || _s == "ldr") wait = map(analogRead(LDR),0,1023,600,0);
    // else if (_s == "temp" || _s == "temperatura") wait == analogRead(TEMP);
    }

    delay(wait);
  }
  //turn of all LEDs in case of non-loop function
  upaliLED(0,0,0);
}

void BTR::cirkus() {
  uint8_t wait = 30;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< clock.numPixels(); i++) {
      clock.setPixelColor(i, Wheel(((i * 256 / clock.numPixels()) + j) & 255));
    }
    clock.show();
    delay(wait);
  }

  //turn of all LEDs in case of non-loop function
  upaliLED(0,0,0);
}
//translated
void BTR::circus() { cirkus(); }

void BTR::cirkus(String _s, bool _b) {
  uint16_t i, j;
  uint8_t wait = 30;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< clock.numPixels(); i++) {
      clock.setPixelColor(i, Wheel(((i * 256 / clock.numPixels()) + j) & 255));
    }
    clock.show();

    // bool _b -> 0: change speed; 1: change brightness
    if (_b) {
      if (_s == "poti" || _s == "potenciometar") postaviJacinu(analogRead(POTI),1);
     else if (_s == "foto" || _s == "fotootpornik" || _s == "ldr") postaviJacinu(analogRead(LDR),1);
     else if (_s == "temp" || _s == "temperatura") postaviJacinu(analogRead(TEMP),1);
    }

    else {
      if (_s == "poti" || _s == "potenciometar") wait = map(analogRead(POTI),1023,0,600,0);
      else if (_s == "foto" || _s == "fotootpornik" || _s == "ldr") wait = map(analogRead(LDR),0,1023,600,0);
   //   else if (_s == "temp" || _s == "temperatura") wait == analogRead(TEMP);
    }

    delay(wait);
  }
}

void BTR::ugasiLED() {
    upaliLED(0,0,0);
}
//translated
void BTR::LED_off() { ugasiLED(); }

//==============================================================================
// potentiometer
//==============================================================================

uint16_t BTR::poti() {
  uint16_t _r = map(analogRead(POTI),0,1023,1023,0);
  return _r;
}

uint16_t BTR::potiV() {
  float _r = map(analogRead(POTI),0,1023,1023,0);
  _r = (_r * xAREF) / 1024;
  return uint16_t(_r);
}

//==============================================================================
// fotoresistor
//==============================================================================

uint16_t BTR::ldr() {
  uint16_t _r = analogRead(LDR);
  return _r;
}

//==============================================================================
// switch slide
//==============================================================================

bool BTR::slide() {
  bool _r = digitalRead(SLIDE_SWITCH);
  return _r;
}

//==============================================================================
// temperature
//==============================================================================

uint8_t BTR::temp() {
  return calcTemp(10);
}


//==============================================================================
// PRIVATE
//==============================================================================
//==============================================================================

uint32_t BTR::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return clock.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return clock.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return clock.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
//==============================================================================
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.

//==============================================================================
uint8_t BTR::calcTemp(uint8_t _samples) {
  uint8_t _temp = 0; // variable for return
  uint16_t _v;
  uint16_t _aref = 5000;

  for(int i=0; i<_samples; i++) {
    _v = ((( analogRead(TEMP) * _aref ) / 1024) - 500) / 10;
    delay(2); // no need
    _temp += _v;
  }
  return _temp / _samples;
}
//==============================================================================
// input:   number of samples for temperature measuring
// output:  returns median temperature in Celsius

//==============================================================================
uint8_t BTR::returnBrightness(uint8_t _pwm_val) {
  uint8_t _r = pow(_pwm_val, (float(LED_level)/100));
  return _r;
}
//==============================================================================
// input:   brightness before reduction
// output:  returns reduced brightness
