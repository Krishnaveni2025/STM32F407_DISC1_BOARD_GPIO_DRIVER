/*
 * LED_BUTTON.h
 *
 *  Created on: Oct 23, 2025
 *      Author: krish
 */

#ifndef INC_LED_BUTTON_H_
#define INC_LED_BUTTON_H_
#include "gpio_driver_stm32f407disc.h"
// === Macros for Button Reads ===
#define BUTTON1   GPIO_RfromipPIN(GPIOC, GPIO_PIN_NO_4)
#define BUTTON2   GPIO_RfromipPIN(GPIOC, GPIO_PIN_NO_5)
#define BUTTON3   GPIO_RfromipPIN(GPIOC, GPIO_PIN_NO_6)

// === Macros for LED Control ===
#define LED1_ON   GPIO_WtoOPIN(GPIOB, GPIO_PIN_NO_12, GPIO_PIN_SET)
#define LED1_OFF  GPIO_WtoOPIN(GPIOB, GPIO_PIN_NO_12, GPIO_PIN_RESET)

#define LED2_ON   GPIO_WtoOPIN(GPIOB, GPIO_PIN_NO_13, GPIO_PIN_SET)
#define LED2_OFF  GPIO_WtoOPIN(GPIOB, GPIO_PIN_NO_13, GPIO_PIN_RESET)

#define LED3_ON   GPIO_WtoOPIN(GPIOB, GPIO_PIN_NO_14, GPIO_PIN_SET)
#define LED3_OFF  GPIO_WtoOPIN(GPIOB, GPIO_PIN_NO_14, GPIO_PIN_RESET)


void LED_INIT(void);
void BUTTON_INIT(void);

#endif /* INC_LED_BUTTON_H_ */
