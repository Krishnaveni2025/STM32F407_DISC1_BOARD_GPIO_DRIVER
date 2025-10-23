/*
 * gpio_driver_stm32f407disc.h
 *
 *  Created on: Oct 23, 2025
 *      Author: krishnaveni
 */

#ifndef INC_GPIO_DRIVER_STM32F407DISC_H_
#define INC_GPIO_DRIVER_STM32F407DISC_H_
#include"stm32f407disc.h"
typedef struct{
	uint8_t GPIO_pinNumber; //Possible values from @GPIO_PIN_NUMBERS
	uint8_t GPIO_pinMode;	//possible values from @GPIO_PIN_MODES
	uint8_t GPIO_pinSpeed;  //Possible values from @GPIO_PIN_SPEEDS
	uint8_t GPIO_pinPuPdControl;//possible values from @GPIO_PIN_PUPD
	uint8_t GPIO_pinOtype;  // possible values from @GPIO_PIN_OUTPUT_TYPE
	uint8_t GPIO_pinAFMode; //possible values from

}GPIO_PINCONFIG;

//Macros Related to Button Interface for PULLDOWN Configuration
#define HIGH 1
#define PRESSED HIGH


//GPIO pin Possible modes @GPIO_PIN_MODES
#define GPIO_IN_MODE     0
#define GPIO_OUT_MODE    1
#define GPIO_AF_MODE     2
#define GPIO_ANALOG_MODE 3

//GPIO pin possible output types @GPIO_PIN_OUTPUT_TYPE
#define GPIO_OTy_PP  0
#define GPIO_OTy_OD  1

//GPIO pin possible output speeds @GPIO_PIN_SPEEDS
#define GPIO_SPEED_L  0
#define GPIO_SPEED_M  1
#define GPIO_SPEED_H  2
#define GPIO_SPEED_VH 3

//GPIO PULLUP AND PULLDOWN configuration possibilities @GPIO_PIN_PUPD
#define GPIO_NOPUPD 0
#define GPIO_PIN_PU     1
#define GPIO_PIN_PD     2

//Gpio pin numbers from 0 to 15 @GPIO_PIN_NUMBERS
#define GPIO_PIN_NO_0   0
#define GPIO_PIN_NO_1   1
#define GPIO_PIN_NO_2   2
#define GPIO_PIN_NO_3   3
#define GPIO_PIN_NO_4   4
#define GPIO_PIN_NO_5   5
#define GPIO_PIN_NO_6   6
#define GPIO_PIN_NO_7   7
#define GPIO_PIN_NO_8   8
#define GPIO_PIN_NO_9   9
#define GPIO_PIN_NO_10  10
#define GPIO_PIN_NO_11  11
#define GPIO_PIN_NO_12  12
#define GPIO_PIN_NO_13  13
#define GPIO_PIN_NO_14  14
#define GPIO_PIN_NO_15  15

//handle structure of a GPIO Pin
typedef struct{
	GPIOPORT *pGPIOx;//holds the base address of the gpio port to which the port belongs to
	GPIO_PINCONFIG GPIO_pinconfig;//holds the pin configuration settings
}GPIO_handle;

//To handle the peripheral clock of GPIO PORT
void GPIO_pClkControl(GPIOPORT *pGPIOx,uint8_t EorD);

//To Initialize and Deinitialize GPIO
void GPIO_INIT(GPIO_handle *GPIOHandle);
void GPIO_DEINIT(GPIOPORT *pGPIOx);

//To read and write data
uint8_t GPIO_RfromipPIN(GPIOPORT *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_RfromipPORT(GPIOPORT *GPIOx);
void GPIO_WtoOPIN(GPIOPORT *pGPIOx, uint8_t pinNumber, uint8_t data);
void GPIO_WtoOPORT(GPIOPORT *GPIOx, uint16_t data);
void GPIO_ToggleOPIN(GPIOPORT *pGPIOx, uint8_t pinNumber);

#endif /* INC_GPIO_DRIVER_STM32F407DISC_H_ */

