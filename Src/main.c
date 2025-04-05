/*
 * PORT:D
 * PİN:15
 *
 *
 *
 *
 *
 */
#define PERIPH_BASE 				(0x40000000UL)


#define AHB1PERIPH_OFFSET 			(0x00020000UL)//uzaklık ahb1perıph1
#define AHB1PERIPH_BASE 			(PERIPH_BASE + AHB1PERIPH_OFFSET )//0x40000000 +  0x00020000


#define GPIOA_OFFSET 				(0x0000UL)
#define GPIO_BASE					(AHB1PERIPH_BASE + GPIOA_OFFSET )


#define RCC_OFFSET 					(0x3800UL)
#define RCC_BASE					(AHB1PERIPH_BASE  +  RCC_OFFSET )//0x40000000 +  0x00020000 + 0x3800


#define AHB1EN_R_OFFSET 			(0x30UL)
#define RCC_AHB1EN_R				(*(volatile unsigned  int *)(RCC_BASE + AHB1EN_R_OFFSET) )


#define GPIODEN   				     (1U<<0UL)//0b 0000 	0000	0000	0000	0000	0000	0000	0001

#define MODE_R_OFFSET				(0x00UL)
#define GPIOD_MODE_R				(*(volatile unsigned  int *)(GPIO_BASE	+ MODE_R_OFFSET)  )


#define	OD_R_OFFSET 				(0x14UL)
#define GPIOD_OD_R					(*(volatile unsigned  int *)(GPIO_BASE  + 0x14UL) )


#define PIN_15						(1U<<15)
#define LED_PIN						PIN_15

/*
 *
 *
 * RCC_AHB1EN_R					0b 0000 	0000	0000	0000	1000	1111	0000	0000
 *
 *
 */
int main (void ){

	RCC_AHB1EN_R |= GPIODEN;

	//set pin 15 to bit 1
	GPIOD_MODE_R |=  (1U<<10); //SET BİT 10 TO 1
	GPIOD_MODE_R &=~ (1U<<11); // SET BİT 11 TO 0

	while(1){

		/* SET PIN 15 HIGH*/
		GPIOD_OD_R |=LED_PIN;
		/*AÇ KAPA*/
		GPIOD_OD_R ^=LED_PIN;
		for (int i=0 ;i<100000000;i++){}




}
}
