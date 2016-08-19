/*
 * functions.h
 *
 *  Created on: Aug 7, 2016
 *      Author: Mike.Smith
 */

#ifndef IO_FUNCTIONS_RCCAR_H_
#define IO_FUNCTIONS_RCCAR_H_

#include "IO_functions.h"
#include "IO_Functions_FIXEDPATH.h"
#include "IO_Functions_BUTTONPATH.h"

// RC CAR
void InitRCOutput(void);
unsigned int ProcessInputRC(unsigned int command);
void DriveCarRC(unsigned int command);
void WriteCommandRC(unsigned int command);

#if EiE_Board
/* ATSAM3U header file: functions.h */

#define RC_PORT        A
#define OUTPUT1_PIN    9
#define OUTPUT2_PIN    10
#define OUTPUT3_PIN    16
#define OUTPUT4_PIN    15

#define RC_FORW        (1<<OUTPUT1_PIN)
#define RC_BACK        (1<<OUTPUT2_PIN)
#define RC_LEFT        (1<<OUTPUT3_PIN)
#define RC_RIGHT       (1<<OUTPUT4_PIN)

#define RC_COAST       0

#define ENABLE_OPENDRAIN(PORT,PIN)\
        ENABLE_OPENDRAIN_FME(PORT,PIN)
#define ENABLE_OPENDRAIN_FME(PORT,PIN)\
 AT91C_BASE_PIO##PORT->PIO_MDER |= (1<<PIN)
 
#elif Discovery_Board
/* STM32F4 header file: functions.h */


#define RC_PORT        E
#define OUTPUT1_PIN    8
#define OUTPUT2_PIN    10
#define OUTPUT3_PIN    12
#define OUTPUT4_PIN    14
#define RC_LEFT        (1<<OUTPUT3_PIN)
#define RC_FORW        (1<<OUTPUT2_PIN)
#define RC_RIGHT       (1<<OUTPUT4_PIN)
#define RC_BACK        (1<<OUTPUT1_PIN)
#define RC_COAST       0

#define ENABLE_OPENDRAIN(PORT,PIN)\
        ENABLE_OPENDRAIN_FME(PORT,PIN)
#define ENABLE_OPENDRAIN_FME(PORT,PIN)\
        GPIO##PORT->OTYPER |= (1<<PIN)

	
#else
#error "ARM Board not defined"
#endif

#endif /* IO_FUNCTIONS_RCCAR_H_ */
