/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_RIGHT
//#define MASTER_LEFT
// #define EE_HANDS

// Underglow
/*
#undef RGBLED_NUM
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_SLEEP
*/
#ifdef PS2_MOUSE_ENABLE
	#define PS2_MOUSE_USE_REMOTE_MODE		// To fix mouse jerking and randomly right clicking with the default stream mode
	#define PS2_MOUSE_ROTATE 180 			// compensate for south-facing device orientation
  
	#define PS2_MOUSE_BTN_LEFT      0
	#define PS2_MOUSE_BTN_RIGHT     1
	#define PS2_MOUSE_BTN_MIDDLE    2
    #define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_RIGHT)
	#define PS2_MOUSE_SCROLL_BTN_SEND 300
	
	#define PS2_MOUSE_SCROLL_MASK 0xFF
  
	#define PS2_MOUSE_X_MULTIPLIER 8
	#define PS2_MOUSE_Y_MULTIPLIER PS2_MOUSE_X_MULTIPLIER
  
	#define PS2_MOUSE_USE_2_1_SCALING
#endif

#ifdef PS2_DRIVER_INTERRUPT
	// clock on pin 3 (D0, use INT0 interrupt)
	// Update INT0 and ISC00 and ISC01 to match the interrupt used for the CLOCK_PIN
	#define PS2_CLOCK_PIN D0
	  // data on pin 2 (D1)
	#define PS2_DATA_PIN D1

	#define PS2_INT_INIT()  do {    \
		EICRA |= ((1<<ISC01) |      \
				  (0<<ISC00));      \
	} while (0)
	#define PS2_INT_ON()  do {      \
		EIMSK |= (1<<INT0);         \
	} while (0)
	#define PS2_INT_OFF() do {      \
		EIMSK &= ~(1<<INT0);        \
	} while (0)
	#define PS2_INT_VECT   INT0_vect
#endif

#ifdef PS2_DRIVER_BUSYWAIT
	// clock on pin 3 (D0)
	#define PS2_CLOCK_PIN D0
	  // data on pin 2 (D1)
	#define PS2_DATA_PIN D1
#endif

	