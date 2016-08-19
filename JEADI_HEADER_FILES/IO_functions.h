/*
 * functions.h
 *
 *  Created on: Aug 7, 2016
 *      Author: Mike.Smith
 */

#ifndef IO_FUNCTIONS_H_
#define IO_FUNCTIONS_H_

// Article 1 Blink LED - Push Button Common functions
void InitLED12(void);	//Initialize IO Interfaces
void InitActivateButton(void);

void ToggleLED1(void);
void ToggleLED2(void);
unsigned int ReadActivateButton(void);
void WaitSometime(unsigned int delay);

#if EiE_Board
/* ATSAM3U header file: functions.h */
#define MPGL1 1
#include "configuration.h"

// Pin definition and register values
#define DELAY    0x49000
#define LED_PORT B
#define LED1_PIN 15    //Pin 15 on port B
#define LED2_PIN 20    //Pin 20 on port B
#define BUTTON_PORT A
#define BUTTON1_PIN 17  //Pin 17 port A
#define LED1_ON (1<<LED1_PIN)
#define LED2_ON (1<<LED2_PIN)
#define START_BUTTON (1<<BUTTON1_PIN)
//Port A Clock enable
#define PORTCLOCK_A 0x00000400

//MACRO to enable the port pin
#define ENABLEPORT(PORT,PIN)\
  ENABLEPORT_FME(PORT,PIN)
#define ENABLEPORT_FME(PORT,PIN)\
  AT91C_BASE_PIO##PORT->PIO_PER |= (1<<PIN)

//MACRO to set mode to output
#define SETPINOUTPUT(PORT,PIN)\
  SETPINOUTPUT_FME(PORT,PIN)

#if 0
#define SETPINOUTPUT_FME(PORT,PIN)\
  AT91C_BASE_PIO##PORT->PIO_OER |= (1<<PIN);\
  //Enable writing PIO_ODSR
  AT91C_BASE_PIO##PORT->PIO_OWER |= (1<<PIN)
#endif

#define SETPINOUTPUT_FME(PORT,PIN)\
  AT91C_BASE_PIO##PORT->PIO_OER |= (1<<PIN);\
  AT91C_BASE_PIO##PORT->PIO_OWER |= (1<<PIN)

//MACRO to enable input
#define SETPININPUT(PORT,PIN)\
  SETPININPUT_FME(PORT,PIN)
#define SETPININPUT_FME(PORT,PIN)\
  AT91C_BASE_PMC->PMC_PCER |=\
  PORTCLOCK_##PORT;\
  AT91C_BASE_PIO##PORT->PIO_ODR |= (1<<PIN)

// MACRO to write output register
#define OUTPUTREGISTER(PORT)\
  OUTPUTREGISTER_FME(PORT)
#define OUTPUTREGISTER_FME(PORT)\
  AT91C_BASE_PIO##PORT->PIO_ODSR

// MACRO to read ACTIVE LOW Activate Button Bit
#define ACTIVATE_BUTTON_BIT( )\
	(~AT91C_BASE_PIOA->PIO_PDSR) & START_BUTTON

#define SETUP_PROCESSOR() \
	AT91C_BASE_WDTC->WDTC_WDMR = WDT_MR_INIT

#elif Discovery_Board
  /* STM32F4 header file: functions.h */
  #include "stm32f4xx.h"

  //Pin definition and register values
  #define DELAY 0xfffff
  #define LED_PORT D
  #define LED1_PIN 12     //Pin 12 on port D
  #define LED2_PIN 13     //Pin 13 on port D
  #define BUTTON_PORT A
  #define BUTTON1_PIN 0   //Pin 0 on port A
  #define LED1_ON (1<<LED1_PIN)
  #define LED2_ON (1<<LED2_PIN)
  #define START_BUTTON (1<<BUTTON1_PIN)
  //Port A clock enable
  #define PORTCLOCK_A 0
  //Port D clock enable
  #define PORTCLOCK_D 3

  //MACRO to enable the port pin
  #define ENABLEPORT(PORT,PIN)\
    ENABLEPORT_FME(PORT,PIN)
  #define ENABLEPORT_FME(PORT,PIN)\
    RCC->AHB1ENR |= (1<<PORTCLOCK_##PORT)

  //MACRO to set mode to output
  #define SETPINOUTPUT(PORT,PIN)\
    SETPINOUTPUT_FME(PORT,PIN)
  #define SETPINOUTPUT_FME(PORT,PIN)\
    GPIO##PORT->MODER |= (1<<(PIN*2))

  //MACRO to enable input
  #define SETPININPUT(PORT,PIN)\
    SETPININPUT_FME(PORT,PIN)
  #define SETPININPUT_FME(PORT,PIN)\
	/* DO NOTHING */
	//Pin mode is already set to
	//  input as a default value)

  // MACRO to write output register
  #define OUTPUTREGISTER(PORT)\
    OUTPUTREGISTER_FME(PORT)
  #define OUTPUTREGISTER_FME(PORT)\
    GPIO##PORT->ODR

  // MACRO to read ACTIVE HIGH Activate Button Bit
  #define ACTIVATE_BUTTON_BIT( )\
         (GPIOA->IDR) & START_BUTTON

#define SETUP_PROCESSOR() \
	/* NONE NEEDED */

#else
#error "ARM Board not defined"
#endif


#endif /* IO_FUNCTIONS_H_ */
