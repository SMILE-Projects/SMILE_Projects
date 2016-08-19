/*
 * functions.h
 *
 *  Created on: Aug 7, 2016
 *      Author: Mike.Smith
 */

#ifndef IO_FUNCTIONS_FIXEDPATH_H_
#define IO_FUNCTIONS_FIXEDPATH_H_

#include "IO_functions.h"

// FIXED PATH
void InitButtons(void);
void InitLED(void);
void DriveCar_FixedPath(void);
void DriveCar_ButtonPath(void);
void DriveCar(unsigned int command);
unsigned int ReadFixedPath(void);
void WriteCommand(unsigned int command);

#if EiE_Board
/* ATSAM3U header file: functions.h */
#define LED3_PIN  17  //Pin 17 on port B
#define LED4_PIN  19  //Pin 19 on port B
#define RIGHT     (1<<LED1_PIN)    /********************************************************/
#define BACK      (1<<LED2_PIN)
#define FORW      (1<<LED3_PIN)
#define LEFT      (1<<LED4_PIN)
#define END_COMMAND 0xFFFF //End of Pattern
#define COAST 0x0          //Do nothing

#elif Discovery_Board
/* STM32F4 header file: functions.h */
		// Part 2
#define LED3_PIN 14  //Pin 14 on port D
#define LED4_PIN 15  //Pin 15 on port D
#define LEFT	(1<<LED1_PIN)
#define FORW	(1<<LED2_PIN)
#define RIGHT	(1<<LED3_PIN)
#define BACK	(1<<LED4_PIN)
#define END_COMMAND 0xFFFF  //End of Pattern
#define COAST 0x0           //Do nothing

#else
#error "ARM Board not defined"
#endif


#endif /* IO_FUNCTIONS_FIXEDPATH_H_ */
