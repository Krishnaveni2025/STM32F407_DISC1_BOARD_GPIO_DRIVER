/**
 ******************************************************************************
 * @file           : main.c
 * @author         : krishnaveni
 * @brief          : Main program body
 ******************************************************************************
 **/

#include "gpio_driver_stm32f407disc.h"
#include"LED_BUTTON.h"
int main(void)
{
	LED_INIT();
	BUTTON_INIT();

    // === Main Loop ===
    while (1)
    {
    	if(BUTTON1 == PRESSED)
    	{
    		LED1_ON;
    		smalldelay();
    		LED1_OFF;
    	}
    	else if(BUTTON2 == PRESSED)
    	{
    		LED2_ON;
    		smalldelay();
    		LED2_OFF;
    	 }
    	 else if(BUTTON3 == PRESSED)
    	 {
    		 LED3_ON;
    		 smalldelay();
    		 LED3_OFF;
    	 }
    	LED1_OFF;
        LED2_OFF;
        LED3_OFF;

    }
}
