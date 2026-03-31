/*
 * gpio_driver_stm32f407disc.c
 *
 *  Created on: Oct 23, 2025
 *      Author: krish
 */
#include"gpio_driver_stm32f407disc.h"


/*********************************************************************
 * @fn      		  - GPIO_pClkControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_pClkControl(GPIOPORT *pGPIOx, uint8_t EorD)
{
	if(EorD == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}else if(pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}else if(pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}else if(pGPIOx == GPIOI){
			GPIOI_PCLK_EN();
		}
	}
	else{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}else if(pGPIOx == GPIOB){
			GPIOB_PCLK_DI();
		}else if(pGPIOx == GPIOC){
			GPIOC_PCLK_DI();
		}else if(pGPIOx == GPIOD){
			GPIOD_PCLK_DI();
		}else if(pGPIOx == GPIOE){
			GPIOE_PCLK_DI();
		}else if(pGPIOx == GPIOF){
			GPIOF_PCLK_DI();
		}else if(pGPIOx == GPIOG){
			GPIOG_PCLK_DI();
		}else if(pGPIOx == GPIOH){
			GPIOH_PCLK_DI();
		}else if(pGPIOx == GPIOI){
			GPIOI_PCLK_DI();
		}
	}
}

/*********************************************************************
 * @fn      		  - GPIO_INIT
 *
 * @brief             - This function initializes the given GPIO port
 *
 * @param[in]         -  gpio peripheral handle structure
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_INIT(GPIO_handle *GPIOHandle)
{
	uint32_t temp = 0;
	//1. configure the mode of the gpio pin
	GPIOHandle->pGPIOx->MODER &= ~(0x3 << GPIOHandle->GPIO_pinconfig.GPIO_pinNumber);//Clear the  pin
	temp = ((GPIOHandle->GPIO_pinconfig.GPIO_pinMode)<<(2*GPIOHandle->GPIO_pinconfig.GPIO_pinNumber));
	GPIOHandle->pGPIOx->MODER |= temp;//set the pin
	temp = 0;
	//2. configure output type
	GPIOHandle->pGPIOx->OTYPER &= ~(0x1 << GPIOHandle->GPIO_pinconfig.GPIO_pinNumber);//clear the pin
	temp = ((GPIOHandle->GPIO_pinconfig.GPIO_pinOtype)<<(GPIOHandle->GPIO_pinconfig.GPIO_pinNumber));
	GPIOHandle->pGPIOx->OTYPER |= temp;//set the pin
	temp = 0;
	//3. configure the pullup puldown settings
	GPIOHandle->pGPIOx->PUPDR &= ~(0x3 << GPIOHandle->GPIO_pinconfig.GPIO_pinNumber);
	temp = ((GPIOHandle->GPIO_pinconfig.GPIO_pinPuPdControl)<<(2*GPIOHandle->GPIO_pinconfig.GPIO_pinNumber));
	GPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;
	//4. configure the speed
	GPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << GPIOHandle->GPIO_pinconfig.GPIO_pinNumber);
	temp = ((GPIOHandle->GPIO_pinconfig.GPIO_pinSpeed)<<(2*GPIOHandle->GPIO_pinconfig.GPIO_pinNumber));
	GPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;

	//5. configure alternate functionality
	if(GPIOHandle->GPIO_pinconfig.GPIO_pinMode == GPIO_AF_MODE)
	{
		uint8_t temp1, temp2;
		temp1 = GPIOHandle->GPIO_pinconfig.GPIO_pinNumber / 8;
		temp2 = GPIOHandle->GPIO_pinconfig.GPIO_pinNumber % 8;
		GPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4*temp2));//clearing
		GPIOHandle->pGPIOx->AFR[temp1] = (GPIOHandle->GPIO_pinconfig.GPIO_pinAFMode << (4*temp2));
	}
}
/*********************************************************************
 * @fn      		  - GPIO_DEINIT
 *
 * @brief             - This function resets the given GPIO Peripheral
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - none

 */
void GPIO_DEINIT(GPIOPORT *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}else if(pGPIOx == GPIOB){
		GPIOB_REG_RESET();
	}else if(pGPIOx == GPIOC){
		GPIOC_REG_RESET();
	}else if(pGPIOx == GPIOD){
		GPIOD_REG_RESET();
	}else if(pGPIOx == GPIOE){
		GPIOE_REG_RESET();
	}else if(pGPIOx == GPIOF){
		GPIOF_REG_RESET();
	}else if(pGPIOx == GPIOG){
		GPIOG_REG_RESET();
	}else if(pGPIOx == GPIOH){
		GPIOH_REG_RESET();
	}else if(pGPIOx == GPIOI){
		GPIOI_REG_RESET();
	}

}
/*********************************************************************
 * @fn      		  - GPIO_RfromipPIN
 *
 * @brief             - this function read the Value at the given pin of the given GPIO port base address
 *
 * @param[in]         - base address of the GPIO Peripheral
 * @param[in]         - pin number of the GPIO PORT
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t GPIO_RfromipPIN(GPIOPORT *pGPIOx, uint8_t pinNumber)
{
	uint8_t value;
	value = (uint8_t)(pGPIOx->IDR >> pinNumber)&(0x00000001);
	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_RfromipPORT
 *
 * @brief             - read the input from the given GPIO PORT
 *
 * @param[in]         - base address of the GPIO peripheral
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - 2bytes value
 *
 * @Note              -

 */
uint16_t GPIO_RfromipPORT(GPIOPORT *pGPIOx)
{
	uint16_t value = (uint16_t)pGPIOx->IDR;
	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_WtoOPIN
 *
 * @brief             - Enables or Disables the given pin number data
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - pin number of the gpio port
 * @param[in]         - value to be written 0 or 1
 *
 * @return            - none
 *
 * @Note              - none

 */
void GPIO_WtoOPIN(GPIOPORT *pGPIOx, uint8_t pinNumber, uint8_t data)
{
	if(data == GPIO_PIN_SET)
	{
		//Write 1 to the GPIO pin
		pGPIOx->ODR |= (1 << pinNumber);//set pin
	}
	else
	{
		// write 0
		pGPIOx->ODR &= ~(1 << pinNumber); // clear pin
	}
}
/*********************************************************************
 * @fn      		  - GPIO_WtoOPORT
 *
 * @brief             - Enables or Disables the given GPIO peripheral
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - data to be written into the register
 * @param[in]         - none
 *
 * @return            - none
 *
 * @Note              - none

 */
void GPIO_WtoOPORT(GPIOPORT *pGPIOx, uint16_t data)
{
	pGPIOx->ODR = data;
}
/*********************************************************************
 * @fn      		  - GPIO_ToggleOPIN
 *
 * @brief             - toggles the given pin number of the given GPIO PORT
 *
 * @param[in]         - GPIO PORT base address
 * @param[in]         - GPIO PORT pin number
 * @param[in]         - none
 *
 * @return            - none
 *
 * @Note              - none

 */
void GPIO_ToggleOPIN(GPIOPORT *pGPIOx, uint8_t pinNumber)
{
	pGPIOx->ODR ^= (1 << pinNumber);
}

