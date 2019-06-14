/**
  ******************************************************************************
  * @file    delay.h
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   systick delay header
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

#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

void Delay_Us(__IO uint32_t us);
void Delay_Ms(__IO uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif /* __DELAY_H */

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
