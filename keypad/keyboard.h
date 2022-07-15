/*
 * keyboard.h
 *
 *  Created on: May 10, 2022
 *      Author: Jacek
 */
#include <stdint.h>
#include "stm32f4xx_hal.h"

#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_

#define C1_PIN GPIO_PIN_12
#define C2_PIN GPIO_PIN_13
#define C3_PIN GPIO_PIN_14
#define C4_PIN GPIO_PIN_15
#define C1_PORT GPIOB
#define C2_PORT GPIOB
#define C3_PORT GPIOB
#define C4_PORT GPIOB

#define R1_PIN GPIO_PIN_6
#define R2_PIN GPIO_PIN_7
#define R3_PIN GPIO_PIN_8
#define R4_PIN GPIO_PIN_9
#define R1_PORT GPIOC
#define R2_PORT GPIOC
#define R3_PORT GPIOC
#define R4_PORT GPIOC

int8_t read_button_number(void);
void interrupt_function(void);


#endif /* INC_KEYBOARD_H_ */
