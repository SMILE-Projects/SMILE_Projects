/*
 * functions.h
 *
 *  Created on: Aug 7, 2016
 *      Author: Mike.Smith
 */

#ifndef IO_FUNCTIONS_BUTTONPATH_H_
#define IO_FUNCTIONS_BUTTONPATH_H_

#include "IO_functions.h"
#include "IO_Functions_FIXEDPATH.h"

// BUTTON PATH
void InitEndButton(void);
unsigned int ReadEndButton(void);
void InitOtherButtons(void);
unsigned int ReadDirectionButtons(void);
unsigned int ProcessButtonInput(unsigned int input);


#if EiE_Board
/* ATSAM3U header file: functions.h */
#define INPUT_PORT    B
#define INPUT1_PIN    0
#define INPUT2_PIN    1
#define INPUT3_PIN    2
#define INPUT4_PIN    3
#define INPUT5_PIN    4
#define LEFT_BUTTON   (1<<INPUT1_PIN)
#define RIGHT_BUTTON  (1<<INPUT2_PIN)
#define FORW_BUTTON   (1<<INPUT3_PIN)
#define BACK_BUTTON   (1<<INPUT4_PIN)
#define END_BUTTON    (1<<INPUT5_PIN)
//Port B Clock enable
#define PORTCLOCK_B   0x00000800

//MACRO for enabling input pullup resistors
#define ENABLE_PULLUP(PORT,PIN)
  //Enabled by default in ATSAM3U

// MACRO to read input register
#define INPUTREGISTER(PORT)\
  INPUTREGISTER_FME(PORT)
#define INPUTREGISTER_FME(PORT)\
  (AT91C_BASE_PIO##PORT->PIO_PDSR)
  
#elif Discovery_Board
/* STM32F4 header file: functions.h */

#define INPUT_PORT    E
#define INPUT1_PIN    7
#define INPUT2_PIN    9
#define INPUT3_PIN    11
#define INPUT4_PIN    13
#define INPUT5_PIN    15
#define LEFT_BUTTON   (1<<INPUT1_PIN)
#define FORW_BUTTON   (1<<INPUT2_PIN)
#define RIGHT_BUTTON  (1<<INPUT3_PIN)
#define BACK_BUTTON   (1<<INPUT4_PIN)
#define END_BUTTON    (1<<INPUT5_PIN)
//Port E Clock enable
#define PORTCLOCK_E   4

//MACRO for enabling input pullup resistors
#define ENABLE_PULLUP(PORT,PIN) ENABLE_PULLUP_FME(PORT,PIN)
#define ENABLE_PULLUP_FME(PORT,PIN)\
  GPIO##PORT->PUPDR |= (1<<(PIN*2))

// MACRO to read input register
  #define INPUTREGISTER(PORT)\
    INPUTREGISTER_FME(PORT)
  #define INPUTREGISTER_FME(PORT)\
    GPIO##PORT->IDR
	
#else
#error "ARM Board not defined"
#endif

#endif /* IO_FUNCTIONS_BUTTONPATH_H_ */
