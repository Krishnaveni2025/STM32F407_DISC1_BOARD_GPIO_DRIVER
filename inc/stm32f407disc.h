/*
 * stm32f407disc.h
 *
 *  Created on: Oct 23, 2025
 *      Author: krish
 */

#ifndef INC_STM32F407DISC_H_
#define INC_STM32F407DISC_H_

#include<stdint.h>

#define _vo volatile


//for GPIO PORTA .... GPIO PORTI , should access AHB1 Bus
#define AHB1_BASE_ADDR  0x40020000U // U represents unsigned integer , because default it considers as signed (we can do type cast with uint32_t)

//offset addresses of GPIOA to GPIOI Registers
#define GPIOA_OFFSET 0x0000
#define GPIOB_OFFSET 0x0400
#define GPIOC_OFFSET 0x0800
#define GPIOD_OFFSET 0x0C00
#define GPIOE_OFFSET 0x1000
#define GPIOF_OFFSET 0x1400
#define GPIOG_OFFSET 0x1800
#define GPIOH_OFFSET 0x1C00
#define GPIOI_OFFSET 0x2000

//offset address of RCC Register
#define RCC_OFFSET   0x3800
/*Base Addresses of Peripherals that are hanging under AHB1 Bus */
//Base addresses of GPIOA to GPIOI Peripherals
#define GPIOA_BASE_ADDR (AHB1_BASE_ADDR + GPIOA_OFFSET)
#define GPIOB_BASE_ADDR (AHB1_BASE_ADDR + GPIOB_OFFSET)
#define GPIOC_BASE_ADDR (AHB1_BASE_ADDR + GPIOC_OFFSET)
#define GPIOD_BASE_ADDR (AHB1_BASE_ADDR + GPIOD_OFFSET)
#define GPIOE_BASE_ADDR (AHB1_BASE_ADDR + GPIOE_OFFSET)
#define GPIOF_BASE_ADDR (AHB1_BASE_ADDR + GPIOF_OFFSET)
#define GPIOG_BASE_ADDR (AHB1_BASE_ADDR + GPIOG_OFFSET)
#define GPIOH_BASE_ADDR (AHB1_BASE_ADDR + GPIOH_OFFSET)
#define GPIOI_BASE_ADDR (AHB1_BASE_ADDR + GPIOI_OFFSET)

//Base address of RCC Peripheral
#define RCC_BASE_ADDR (AHB1_BASE_ADDR + RCC_OFFSET)

/* ----------- Peripheral Register Definition Structure -------------------------*/
typedef struct{
	_vo uint32_t MODER; //GPIO port mode register  																					 Address offset: 0x00
	_vo uint32_t OTYPER;//GPIO port output type register 																			 Address offset: 0x04
	_vo uint32_t OSPEEDR;//GPIO port output speed register                                                                           Address offset: 0x08
	_vo uint32_t PUPDR;// GPIO port pull-up/pull-down register                                                                       Address offset: 0x0C
	_vo uint32_t IDR;//GPIO port input data register                                                                                 Address offset: 0x10
	_vo uint32_t ODR;//GPIO port output data register                                                                                Address offset: 0x14
	_vo uint32_t BSRR;//GPIO port bit set/reset register                                                                             Address offset: 0x18
	_vo uint32_t LCKR;//GPIO port configuration lock register                                                                        Address offset: 0x1C
	_vo uint32_t AFR[2];//AFR[0]: GPIO Port Alternate function LOW Register & AFR[1]: GPIO Port Alternate function HIGH Register       Address offset: 0x20 - 0x24
}GPIOPORT;

/* --------------- Peripheral Register Definition for RCC ----------------------*/
typedef struct{
	_vo uint32_t CR;//RCC clock control register                                           Address offset: 0x00
	_vo uint32_t PLLCFGR;//RCC PLL configuration register                                  Address offset: 0x04
	_vo uint32_t CFGR;//RCC clock configuration register                                   Address offset: 0x08
	_vo uint32_t CIR;//RCC clock interrupt register                                        Address offset: 0x0C
	_vo uint32_t AHB1RSTR;//RCC AHB1 peripheral reset register                             Address offset: 0x10
	_vo uint32_t AHB2RSTR;//RCC AHB2 peripheral reset register                             Address offset: 0x14
	_vo uint32_t AHB3RSTR;//RCC AHB3 peripheral reset register                             Address offset: 0x18
	_vo uint32_t RESERVED0;//                                                              Address offset: 0x1C
	_vo uint32_t APB1RSTR;//RCC APB1 peripheral reset register                             Address offset: 0x20
	_vo uint32_t APB2RSTR;//RCC APB2 peripheral reset register                             Address offset: 0x24
	uint32_t RESERVED1[2];//                                                               Address offset: [0]:0x28; [1]:0x2C
	_vo uint32_t AHB1ENR;//RCC AHB1 peripheral clock enable register                       Address offset: 0x30
	_vo uint32_t AHB2ENR;//RCC AHB2 peripheral clock enable register                       Address offset: 0x34
	_vo uint32_t AHB3ENR;//RCC AHB3 peripheral clock enable register                       Address offset: 0x38
	uint32_t RESERVED2;//                                                                  Address offset: 0x3C
	_vo uint32_t APB1ENR;//RCC APB1 peripheral clock enable register                       Address offset: 0x40
	_vo uint32_t APB2ENR;//RCC APB2 peripheral clock enable register  					   Address offset: 0x44
	uint32_t RESERVED3[2];//                                                               Address offset: [0]:0x48; [1]:0x4C
	_vo uint32_t AHB1LPENR;//RCC AHB1 peripheral clock enable in low power mode register   Address offset:0x50
	_vo uint32_t AHB2LPENR;//RCC AHB2 peripheral clock enable in low power mode register   Address offset:0x54
	_vo uint32_t AHB3LPENR;//RCC AHB3 peripheral clock enable in low power mode register   Address offset: 0x58
	uint32_t RESERVED4;//                                                                  Address offset: 0x5C
	_vo uint32_t APB1LPENR;//RCC APB1 peripheral clock enable in low power mode register   Address offset: 0x60
	_vo uint32_t APB2LPENR;//RCC APB2 peripheral clock enabled in low power mode  register Address offset: 0x64
	uint32_t RESERVED5[2];//                                                               Address offset: [0]:0x68; [1]:0x6C
	_vo uint32_t BDCR;//RCC Backup domain control register                                 Address offset: 0x70
	_vo uint32_t CSR;//RCC clock control & status register                                 Address offset: 0x7C
	uint32_t RESERVED6[2];//                                                               Address offset: [0]:0x78; [1]:0x7C
	_vo uint32_t SSCGR;//RCC spread spectrum clock generation register                     Address offset: 0x80
	_vo uint32_t PLLI2SCFGR;//RCC PLLI2S configuration register                            Address offset: 0x84

}RCC_REGISTER;

/* peripheral definitions ( Peripheral base addresses typecasted to GPIOPORT) */
#define GPIOA ((GPIOPORT*)GPIOA_BASE_ADDR)
#define GPIOB ((GPIOPORT*)GPIOB_BASE_ADDR)
#define GPIOC ((GPIOPORT*)GPIOC_BASE_ADDR)
#define GPIOD ((GPIOPORT*)GPIOD_BASE_ADDR)
#define GPIOE ((GPIOPORT*)GPIOE_BASE_ADDR)
#define GPIOF ((GPIOPORT*)GPIOF_BASE_ADDR)
#define GPIOG ((GPIOPORT*)GPIOG_BASE_ADDR)
#define GPIOH ((GPIOPORT*)GPIOH_BASE_ADDR)
#define GPIOI ((GPIOPORT*)GPIOI_BASE_ADDR)
//macro to access Rcc Peripheral register
#define RCC  ((RCC_REGISTER*)RCC_BASE_ADDR)

/*
 * Clock Enable Macros for GPIOx peripherals (x: A to I)
 */

#define GPIOA_PCLK_EN()    	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB1ENR |= (1 << 8))

/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI();
#define GPIOB_PCLK_DI();
#define GPIOC_PCLK_DI();
#define GPIOD_PCLK_DI();
#define GPIOE_PCLK_DI();
#define GPIOF_PCLK_DI();
#define GPIOG_PCLK_DI();
#define GPIOH_PCLK_DI();
#define GPIOI_PCLK_DI();

//to create Delay
#define smalldelay() for(uint32_t i = 0; i <= 50000;i++)

//some generic Macros
#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET

//Macros to reset GPIOx peripherals
#define GPIOA_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 0); (RCC->AHB1RSTR) &= ~(1 << 0); }while(0)
#define GPIOB_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 1); (RCC->AHB1RSTR) &= ~(1 << 1); }while(0)
#define GPIOC_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 2); (RCC->AHB1RSTR) &= ~(1 << 2); }while(0)
#define GPIOD_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 3); (RCC->AHB1RSTR) &= ~(1 << 3); }while(0)
#define GPIOE_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 4); (RCC->AHB1RSTR) &= ~(1 << 4); }while(0)
#define GPIOF_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 5); (RCC->AHB1RSTR) &= ~(1 << 5); }while(0)
#define GPIOG_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 6); (RCC->AHB1RSTR) &= ~(1 << 6); }while(0)
#define GPIOH_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 7); (RCC->AHB1RSTR) &= ~(1 << 7); }while(0)
#define GPIOI_REG_RESET()  do{ (RCC->AHB1RSTR) |= (1 << 8); (RCC->AHB1RSTR) &= ~(1 << 8); }while(0)
#include"gpio_driver_stm32f407disc.h"
#endif /* INC_STM32F407DISC_H_ */
