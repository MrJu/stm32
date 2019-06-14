/**
  ******************************************************************************
  * @file    delay.c
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   systick delay body
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
#include "delay.h"

/**
  * @brief  Delays for a specified amount of time in us.
  * @param  us: specifies the delay time in us.
  * @retval None
  */
void Delay_Us(__IO uint32_t us)
{
	uint32_t i;

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);

	if (SysTick_Config(SystemCoreClock / 1000000))
	{
		while (1);
	}

	for(i = 0; i < us; i++)
	{
		while (!((SysTick->CTRL) & (1 << 16)));
	}

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/**
  * @brief  Delays for a specified amount of time in ms.
  * @param  ms: specifies the dalay time in ms.
  * @retval None
  */
void Delay_Ms(__IO uint32_t ms)
{
	uint32_t i;	

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);

	if (SysTick_Config(SystemCoreClock / 1000))
	{
		while (1);
	}

	for(i = 0; i < ms; i++)
	{
		while (!((SysTick->CTRL) & (1 << 16)));
	}

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
