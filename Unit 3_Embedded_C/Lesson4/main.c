/*
 *main.c
 *
 *      Author:Hamza
 */

#include <Platform_Types.h>
typedef union {
	uint32_t all_pins;
	struct{
		uint32_t pin0:1;
		uint32_t pin1:1;
		uint32_t pin2:1;
		uint32_t pin3:1;
		uint32_t pin4:1;
		uint32_t pin5:1;
		uint32_t pin6:1;
		uint32_t pin7:1;
		uint32_t pin8:1;
		uint32_t pin9:1;
		uint32_t pin10:1;
		uint32_t pin11:1;
		uint32_t pin12:1;
		uint32_t pin13:1;
		uint32_t pin14:1;
		uint32_t pin15:1;
		uint32_t pin16:1;
		uint32_t pin17:1;
		uint32_t pin18:1;
		uint32_t pin19:1;
		uint32_t pin20:1;
		uint32_t pin21:1;
		uint32_t pin22:1;
		uint32_t pin23:1;
		uint32_t pin24:1;
	};
} reg;
#define SYSCTL_base 0x400FE000
#define GPIOF_base  0x40025000
 volatile  reg* SYSCTL_RCGC2_R = (volatile  reg*)(SYSCTL_base+0x108);
 volatile  reg* GPIO_PORTF_DIR_R = (volatile  reg*)(GPIOF_base+0X400);
 volatile  reg* GPIO_PORTF_DEN_R = (volatile  reg*)(GPIOF_base+0X51C);
 volatile  reg* PORTF = (volatile  reg*)(GPIOF_base+0X3FC);
int main(void)
{   volatile int i ;
	GPIO_PORTF_DIR_R->pin3=1;
	GPIO_PORTF_DEN_R->pin3=1;
	
	while(1)
	{
		PORTF->pin13=1;
		for(i=0;i<500000;i++);
		PORTF->pin13=0;
		for(i=0;i<500000;i++);
	}
	for(;;);
}
