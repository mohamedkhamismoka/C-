/*
    Base addresses of Flash and SRAM memories
*/
#define FLASH_BASEADDR	0x08000000UL //typecast also would work (uint32_t) isntead of UL
#define SRAM1_BASEADDR	0x20000000UL
#define SRAM SRAM1_BASEADDR 
// #define SRAM2_BASEADDR	// uC doen't have SRAM2
#define ROM_BASEADDR	0x1FFF0000UL // ROM = System memory
*
    Base addresses of AHBx and APBx Bus Peripheral
*/
#define PERIPH_BASE	0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE 0x40010000UL
#define AHB1PERIPH_BASE 0x40020000UL
#define AHB2PERIPH_BASE 0x50000000UL
    Base addresses of peripherals which are hanging on AHB1 bus
*/
#define GPIOA_BASEADDR (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR (AHB1PERIPH_BASE + 0x1000)
#define GPIOH_BASEADDR (AHB1PERIPH_BASE + 0x1C00)
#define CRC_BASEADDR (AHB1PERIPH_BASE + 0x3000)
#define RCC_BASEADDR (AHB1PERIPH_BASE + 0x3800)
#define FIR_BASEADDR (AHB1PERIPH_BASE + 0x3C00)
#define DMA1_BASEADDR (AHB1PERIPH_BASE + 0x6000)
#define DMA2_BASEADDR (AHB1PERIPH_BASE + 0x6400)
#define USB_OTG_FS_BASEADDR (AHB1PERIPH_BASE + 0xFFE0000)
/*
    Base addresses of peripherals which are hanging on APB1 bus
*/
#define TIM2_BASEADDR (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASEADDR (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASEADDR (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASEADDR (APB1PERIPH_BASE + 0x0C00)
#define USART2_BASEADDR (APB1PERIPH_BASE + 0x4400) دا الmodel بتاعنا 
/*
    Peripheral register definition structure for GPIO
*/
typedef struct {
	volatile uint32_t MODER; // GPIO port mode register - Address offset: 0x00
	volatile uint32_t OTYPER; // GPIO port output type register - Address offset: 0x04
	volatile uint32_t OSPEEDER; // GPIO port output speed register - Address offset: 0x08
	volatile uint32_t PUPDR; // GPIO port pull-up/pull-down register - Address offset: 0x0C
	volatile uint32_t IDR; // GPIO port input data register - Address offset: 0x10
	volatile uint32_t ODR; // GPIO port output data register - Address offset: 0x14
	volatile uint32_t BSRR; // GPIO port bit set/reset register - Address offset: 0x18
	volatile uint32_t LCKR; // GPIO port configuration lock register - Address offset: 0x1C
	volatile uint32_t AFR[2]; // GPIO alternate function low register AFR[0] = AFRL and AFR[1] = AFRH - Address offset: 0x20-0X24
} GPIO_RegDef_t;
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR) 
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR) 
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR) 
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR) 
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR) 
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR) 
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR) 
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR) 
*/
typedef struct {
	volatile uint32_t CR; // RCC clock control register - Address offset: 0x00
	volatile uint32_t PLLCFGR; // RCC PLL configuration register - Address offset: 0x04
	volatile uint32_t CFGR; // RCC clock configuration register - Address offset: 0x08
	volatile uint32_t CIR; // RCC clock interrupt register - Address offset: 0x0C
	volatile uint32_t AHB1RSTR; // RCC AHB1 peripheral reset register - Address offset: 0x10
	volatile uint32_t AHB2RSTR; // RCC AHB2 peripheral reset register - Address offset: 0x14
	volatile uint32_t Reserved0; // Reserved - Address offset: 0x18
	volatile uint32_t Reserved1; // Reserved - Address offset: 0x1C
	volatile uint32_t APB1RSTR; // RCC APB1 peripheral reset register - Address offset: 0x20
	volatile uint32_t APB2RSTR; // RCC APB2 peripheral reset register - Address offset: 0x24
	volatile uint32_t Reserved2; // Reserved - Address offset: 0x28
	volatile uint32_t Reserved3; // Reserved - Address offset: 0x2C
	volatile uint32_t AHB1ENR; // RCC AHB1 peripheral clock enable register - Address offset: 0x30
	volatile uint32_t AHB2ENR; // RCC AHB2 peripheral clock enable register - Address offset: 0x34
	volatile uint32_t Reserved4; // Reserved - Address offset: 0x38
	volatile uint32_t Reserved5; // Reserved - Address offset: 0x3C
	volatile uint32_t APB1ENR; // RCC APB1 peripheral clock enable register - Address offset: 0x40
	volatile uint32_t APB2ENR; // RCC APB2 peripheral clock enable register - Address offset: 0x44
	volatile uint32_t Reserved6; // Reserved - Address offset: 0x48
	volatile uint32_t Reserved7; // Reserved - Address offset: 0x4C
	volatile uint32_t AHB1LPENR; // RCC AHB1 peripheral clock enable in low power mode register - Address offset: 0x50
	volatile uint32_t AHB2LPENR; // RCC AHB2 peripheral clock enable in low power mode register - Address offset: 0x54
	volatile uint32_t Reserved8; // RCC - Address offset: 0x58
	volatile uint32_t Reserved9; // RCC - Address offset: 0x5C
	volatile uint32_t APB1LPENR; // RCC APB1 peripheral clock enable in low power mode register - Address offset: 0x60
	volatile uint32_t APB2LPENR; // RCC APB2 peripheral clock enable in low power mode register - Address offset: 0x64
	volatile uint32_t Reserved10; // Reserved - Address offset: 0x68
	volatile uint32_t Reserved11; // Reserved - Address offset: 0x6C
	volatile uint32_t BDCR; // RCC Backup domain control register - Address offset: 0x70
	volatile uint32_t CSR; // RCC clock control & status register - Address offset: 0x74
	volatile uint32_t Reserved12; // Reserved - Address offset: 0x78
	volatile uint32_t Reserved13; // Reserved - Address offset: 0x7C
	volatile uint32_t SSCGR; // RCC spread spectrum clock generation register - Address offset: 0x80
	volatile uint32_t PLLI2SCFGR; // RCC PLLI2S configuration register - Address offset: 0x84
	volatile uint32_t Reserved14; // Reserved - Address offset: 0x88
	volatile uint32_t DCKCFGR; // RCC  Dedicated Clocks Configuration Register - Address offset: 0x8C
} RCC_RegDef_t;
*/ 
    Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
*/
#define RCC	((RCC_RegDef_t*)RCC_BASEADDR)
// Clock Enable Macros for GPIOx peripherals
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1<<4))
// Clock Disable Macros for USARTx peripherals
#define USART1_PCLK_DI() (RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI() (RCC->APB1ENR &= ~(1<<17))
#define USART6_PCLK_DI() (RCC->APB2ENR &= ~(1<<5))

