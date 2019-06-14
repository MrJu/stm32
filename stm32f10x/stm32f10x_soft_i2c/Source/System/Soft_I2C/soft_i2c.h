/**
  ******************************************************************************
  * @file    soft_i2c.h
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   soft i2c driver header
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

#ifndef __SOFT_I2C_H
#define __SOFT_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#define SOFT_I2C_GPIO GPIOB
#define SOFT_I2C_SCL_PIN GPIO_Pin_6
#define SOFT_I2C_SDA_PIN GPIO_Pin_7
#define SOFT_I2C_GPIO_MODE GPIO_Mode_Out_PP
#define SOFT_I2C_RCC RCC_APB2Periph_GPIOB

#define Set_SDA_In()  {GPIOB->CRL &= 0x0FFFFFFF; GPIOB->CRL |= 4<<28;}
#define Set_SDA_Out() {GPIOB->CRL &= 0x0FFFFFFF; GPIOB->CRL |= 3<<28;}

#define Set_SCL() GPIO_WriteBit(SOFT_I2C_GPIO, SOFT_I2C_SCL_PIN, Bit_SET)
#define Clear_SCL() GPIO_WriteBit(SOFT_I2C_GPIO, SOFT_I2C_SCL_PIN, Bit_RESET)
#define Set_SDA() GPIO_WriteBit(SOFT_I2C_GPIO, SOFT_I2C_SDA_PIN, Bit_SET)
#define Clear_SDA() GPIO_WriteBit(SOFT_I2C_GPIO, SOFT_I2C_SDA_PIN, Bit_RESET)

#define Read_SDA() GPIO_ReadInputDataBit(SOFT_I2C_GPIO, SOFT_I2C_SDA_PIN)

void Soft_I2C_Init(void);
void Soft_I2C_Start(void);
void Soft_I2C_Stop(void);
void Soft_I2C_Ack(void);
void Soft_I2C_NAck(void);
uint8_t Soft_I2C_Wait_Ack(void);

void Soft_I2C_Send_Byte(uint8_t data);
uint8_t Soft_I2C_Read_Byte(uint8_t ack);

#ifdef __cplusplus
}
#endif

#endif /* __SOFT_I2C_H */

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
