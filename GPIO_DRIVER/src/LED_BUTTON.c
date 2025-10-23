/*
 * LED_BUTTON.c
 *
 *  Created on: Oct 23, 2025
 *      Author: krish
 */

#include "LED_BUTTON.h"
void LED_INIT(void)
{
	// Enable clocks for GPIOB
	GPIO_pClkControl(GPIOB, ENABLE);
	GPIO_pClkControl(GPIOC, ENABLE);

	// === Configure LEDs ===
	GPIO_handle led;
	led.pGPIOx = GPIOB;
	led.GPIO_pinconfig.GPIO_pinMode = GPIO_OUT_MODE;
	led.GPIO_pinconfig.GPIO_pinSpeed = GPIO_SPEED_M;
	led.GPIO_pinconfig.GPIO_pinPuPdControl = GPIO_NOPUPD;
	led.GPIO_pinconfig.GPIO_pinOtype = GPIO_OTy_PP;

	led.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_12;
	GPIO_INIT(&led);
	led.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_13;
	GPIO_INIT(&led);
	led.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_14;
	GPIO_INIT(&led);
}
void BUTTON_INIT(void)
{
	// Enable clocks for GPIOB
	GPIO_pClkControl(GPIOC, ENABLE);
	// === Configure Buttons ===
	GPIO_handle btn;
	btn.pGPIOx = GPIOC;
	btn.GPIO_pinconfig.GPIO_pinMode = GPIO_IN_MODE;
	btn.GPIO_pinconfig.GPIO_pinSpeed = GPIO_SPEED_M;
	btn.GPIO_pinconfig.GPIO_pinPuPdControl = GPIO_PIN_PD;

	btn.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_4;
	GPIO_INIT(&btn);
	btn.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_5;
	GPIO_INIT(&btn);
	btn.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_6;
	GPIO_INIT(&btn);
}
