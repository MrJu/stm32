/**
  ******************************************************************************
  * @file    led.h
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   led driver header
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

#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

enum {
  ON,
  OFF,
};

#define LED1_GPIO_PORT GPIOA
#define LED1_GPIO_CLK RCC_APB2Periph_GPIOA
#define LED1_GPIO_PIN GPIO_Pin_8
#define LED1_GPIO_MODE GPIO_Mode_Out_PP

#define LED2_GPIO_PORT GPIOD
#define LED2_GPIO_CLK RCC_APB2Periph_GPIOD
#define LED2_GPIO_PIN GPIO_Pin_2
#define LED2_GPIO_MODE GPIO_Mode_Out_PP

#define LED1(status)\
        if (status)\
          GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);\
        else\
          GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LED2(status)\
        if (status)\
          GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);\
        else\
          GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN)

void LED1_Config(void);
void LED2_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* __LED_H */

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
