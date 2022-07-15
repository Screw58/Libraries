/*
 * keyboard.c
 *
 *  Created on: May 10, 2022
 *      Author: Jacek
 */
#include "keyboard.h"






typedef struct
{
	GPIO_TypeDef * GPIOx ;
	uint16_t  PIN;
}gpio_t;

//GPIO_TypeDef * gPIO;


gpio_t columns[] = {
		{ C1_PORT , C1_PIN} ,
		{ C2_PORT , C2_PIN} ,
		{ C3_PORT , C3_PIN} ,
		{ C4_PORT , C4_PIN}
};

gpio_t rows[] = {
		{ R1_PORT , R1_PIN} ,
		{ R2_PORT , R2_PIN} ,
		{ R3_PORT , R3_PIN} ,
		{ R4_PORT , R4_PIN}
};


void interrupt_function(void)
{
	volatile  uint8_t l =0;

	for(uint8_t i=0; i<4; i++)
		HAL_GPIO_WritePin(columns[i].GPIOx, columns[i].PIN, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(columns[l].GPIOx, columns[l].PIN, GPIO_PIN_SET);
	l++;
	if(l > 3) l=0;

}


int8_t read_button_number(void)
{
	uint8_t x ,y, value, flag;
	uint16_t outputregister, inputregister;
	x=y=0;
uint16_t wynik1, wynik2, wynik3;


	outputregister = columns[x].GPIOx->ODR ;
	inputregister = rows[y].GPIOx->IDR;

//	wynik1 = (outputregister & columns[x].PIN);
//	wynik2= (inputregister & rows[y].PIN);
//	wynik3= (wynik1 && wynik2 );

	while(y<4)
	{
		while(x<4)
		{
			if((outputregister & tab[x].PIN) && (inputregister & tabul[y].PIN))
			{
				flag = 1;
				value = x+ y * 4 ;
			}
			x++ ;
		}
		y++ ;
	}
	if(flag == 1)
	{
		return value;
		flag = 0;
	}
	else
		return -1;
}





