/*
 * Application_Code.c
 *
 *  Created on: Jan 15, 2025
 *      Author: ivancalderon
 */

#include "Application_Code.h"

static GPIO_InitTypeDef* led_green;
static GPIO_InitTypeDef* led_red;
static GPIO_InitTypeDef* user_button;


void application_init(){

	user_button->Mode = GPIO_MODE_INPUT;
	user_button->Pin = PIN_USER_BUTTON;
	user_button->Pull = GPIO_NOPULL;
	user_button->Speed = GPIO_SPEED_FREQ_LOW;


	led_green->Pin = PIN_LED_GREEN;
	led_red->Pin = PIN_LED_RED;

	led_green->Mode = GPIO_MODE_OUTPUT_PP;
	led_red->Mode = GPIO_MODE_OUTPUT_PP;

	led_red->Pull = GPIO_PULLDOWN;
	led_green->Pull = GPIO_PULLDOWN;

	led_red->Speed = GPIO_SPEED_FREQ_LOW;
	led_green->Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(PORT_USER_BUTTON, user_button);
	HAL_GPIO_Init(PORT_LED_RED, led_red);
	HAL_GPIO_Init(PORT_LED_GREEN, led_green);


}

void led_blink(){
	HAL_GPIO_TogglePin(PORT_LED_GREEN, PIN_LED_GREEN);
	HAL_Delay(1000);
}

void button_state(){
	if(HAL_GPIO_ReadPin(PORT_USER_BUTTON, GPIO_PIN_0) == 1){
			HAL_GPIO_WritePin(PORT_LED_RED, GPIO_PIN_14, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(PORT_LED_RED, GPIO_PIN_14, GPIO_PIN_RESET);
	}
}
