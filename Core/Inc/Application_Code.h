/*
 * Application_Code.h
 *
 *  Created on: Jan 15, 2025
 *      Author: ivancalderon
 */

#ifndef INC_APPLICATION_CODE_H_
#define INC_APPLICATION_CODE_H_

#include "stm32f4xx_hal.h"

#define PORT_USER_BUTTON GPIOA
#define PIN_USER_BUTTON GPIO_PIN_0

#define PORT_LED_GREEN GPIOG
#define PORT_LED_RED   GPIOG

#define PIN_LED_GREEN GPIO_PIN_13
#define PIN_LED_RED   GPIO_PIN_14

void application_init();
void led_blink();
void button_state();



#endif /* INC_APPLICATION_CODE_H_ */
