/**
  ******************************************************************************
  * @file    led.c
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   led driver body
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
#include "led.h"   

/**
  * @brief  This function configures led1 GPIO.
  * @param  None
  * @retval None
  */
void LED1_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd( LED1_GPIO_CLK, ENABLE);

  GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = LED1_GPIO_MODE;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);

  GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
}

/**
  * @brief  This function configures led2 GPIO.
  * @param  None
  * @retval None
  */
void LED2_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(LED2_GPIO_CLK, ENABLE);

  GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = LED2_GPIO_MODE;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);

  GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
