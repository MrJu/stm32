/**
  ******************************************************************************
  * @file    main.c
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (C) 2019 Andrew <mrju.email@gmail.com>
  *
  * This program is free software; you can redistribute it and/or modify it
  * under the terms of the GNU General Public License as published by the Free
  * Software Foundation; either version 2 of the License, or (at your option)
  * any later version.
  *
  * This program is distributed in the hope that it will be useful, but WITHOUT
  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"

#define DELAY_COUNT 0x0FFFFF

/**
  * @brief  This function is used to delay.
  * @param  count: loop count.
  * @retval None
  */
void Delay(__IO uint32_t count)
{
	for(; count != 0; count--);
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	LED1_Config();

	while (1)
	{
		LED1(ON);
		Delay(DELAY_COUNT);
		LED1(OFF);
		Delay(DELAY_COUNT);
	}
}

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
