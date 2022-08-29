#include <stm32f10x.h>
#include "bsp_RccClkConfig.h"

#define GPIOA_ODR_Addr  (GPIOA_BASE+0X0C) //0X0C-ODR¼Ä´æÆ÷µØÖ·Æ«ÒÆ    
#define PAout(n) *(unsigned int*)((GPIOA_ODR_Addr & 0xF0000000)+0X02000000+((GPIOA_ODR_Addr & 0X00FFFFFF)<<5)+(n<<2))


#define GPIOC_IDR_Addr (GPIOC_BASE+0X08)
#define PCin(n)  *(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000)+0X02000000+((GPIOC_IDR_Addr & 0X00FFFFFF)<<5)+(n<<2))


void Delay(uint32_t count)
{
	for(;count!=0;count--);
	
}



void MCO_Gpio_Config(void)
{
		GPIO_InitTypeDef GPIO_InitStruture;
		GPIO_InitStruture.GPIO_Pin = GPIO_Pin_8;
		GPIO_InitStruture.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStruture);
}



void LED_Config(void)
{
		GPIO_InitTypeDef GPIO_InitStruture;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		
	
		GPIO_InitStruture.GPIO_Pin = GPIO_Pin_8;
		GPIO_InitStruture.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStruture);
}



int main()
{	

		RCC_DeInit();
		SetSysClock(RCC_PLLMul_9);
	
		MCO_Gpio_Config();
		RCC_MCOConfig(RCC_MCO_SYSCLK);
	
		LED_Config();
	while(1)
	{		

		PAout(8)=0;
		Delay(0xfffff);
		PAout(8)=1;
		Delay(0xfffff);
	}

}




