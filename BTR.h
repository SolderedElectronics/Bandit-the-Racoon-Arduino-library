//==============================================================================
//    E - R A D I O N I C A . C O M,  H.Kolomana 6/A, Djakovo 31400, Croatia
//==============================================================================
// Project   :  Bandit the Racoon Arduino Library
// File      :  BTR.h
// Author    :  e-r.io 2017
// Licence   :  Open-source ! 
//==============================================================================
//==============================================================================
// To be used with Bandit the Racoon board:
// https://e-radionica.com/en/bandit-the-raccoon-btr.html
// If any questions, 
// just contact hello@e-r.io
//==============================================================================


#ifndef BTR_H
#define BTR_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

//---------- Includes ----------------------------------------------------------

//==============================================================================
#include "Adafruit_NeoPixel.h"
//==============================================================================
// Part of this library is Adafruit NeoPixel library for WS2812 LED devices.
//
//  NeoPixel is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as
//  published by the Free Software Foundation, either version 3 of
//  the License, or (at your option) any later version.

//---------- Defines -----------------------------------------------------------
//==============================================================================
#define POTI 			A0
#define LDR  			A1
#define TEMP 			A2
#define GENERAL_INPUT	A3
#define PUSHBUTTON		2
#define BUZZER			3
#define WS2812B_PIN		4
#define SLIDE_SWITCH	5
#define MOSFET_OUT		9
//==============================================================================
// ATMega328 GPIO Ports

//==============================================================================
#define WS2801_LENGHT	12

#define potenciometar A0

class BTR
{
	public:
		//==============================================================================
		void begin(void);
		//==============================================================================
		// must be called upon using library
		// sets WS2812, GPIO

		//==============================================================================
		void upaliLED(uint8_t _p, uint8_t _r, uint8_t _g, uint8_t _b);
		void LED_on(uint8_t _p, uint8_t _r, uint8_t _g, uint8_t _b);
		//==============================================================================
		// turn on specific LED with RG format
		// input: 	LED number, colors in RGB format

		void upaliLED(uint8_t _r, uint8_t _g, uint8_t _b);
		void LED_on(uint8_t _r, uint8_t _g, uint8_t _b);
		//==============================================================================
		// turn on all LEDs with RGB format
		// input:  	colors in RGB format

		//==============================================================================
		void upaliLED(uint8_t _p, String _c);
		void LED_on(uint8_t _p, String _c);
		//==============================================================================
		// input:	LED number, color in string format

		//==============================================================================
		void upaliLED(String _c);
		void LED_on(String _c);
		//==============================================================================
		// turn all LEDs in specific color
		// input:	color in string format

		//==============================================================================
		void ugasiLED();
		void LED_off();
		//==============================================================================
		// turn off all LEDs

		//==============================================================================
		void postaviJacinu(uint8_t _l);
		void set_brightness(uint8_t _l);
		//==============================================================================
		// set global LED brightness
		// input:	global LED brightness level in [%]

		//==============================================================================
		void postaviJacinu(uint16_t _pot, bool _bA);
		void set_brightness(uint16_t _pot, bool _bA);
		//==============================================================================
		// set global LED brightness
		// input:	value and bool as 1:10-bit value 0:value in [%]

		//==============================================================================
		uint16_t poti();
		//==============================================================================
		// output:	returns 10-bit value generated from potentiometer

		//==============================================================================
		uint16_t potiV();
		//==============================================================================
		// output:	returns [mV] in range 0-Vcc generated from potentiometer

		//==============================================================================
		uint16_t ldr();
		//==============================================================================
		// output:10bit value (0-1023) of LDR

		//==============================================================================
		bool slide();
		//==============================================================================
		// output: 1: slider down; 0: slider up

		void duga();
		void rainbox();
		void cirkus();
		void circus();
		void duga(String _s, bool _b);
		void cirkus(String _s, bool _b);
		uint8_t temp();

	private:
		//==============================================================================
		uint32_t Wheel(byte WheelPos);
		uint8_t calcTemp(uint8_t _samples);
		uint8_t returnBrightness(uint8_t _pwm_val);

};
#endif
