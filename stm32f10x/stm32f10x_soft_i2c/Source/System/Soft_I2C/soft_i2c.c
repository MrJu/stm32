/**
  ******************************************************************************
  * @file    soft_i2c.c
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   soft i2c driver body
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
#include "soft_i2c.h"
#include "delay.h"

/**
  * @brief  This function is used to configue the GPIO for soft i2c.
  * @param  None
  * @retval None
  */
void Soft_I2C_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(SOFT_I2C_RCC, ENABLE );

	GPIO_InitStructure.GPIO_Pin = SOFT_I2C_SCL_PIN | SOFT_I2C_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode = SOFT_I2C_GPIO_MODE;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SOFT_I2C_GPIO, &GPIO_InitStructure);

	GPIO_SetBits(SOFT_I2C_GPIO, SOFT_I2C_SCL_PIN | SOFT_I2C_SCL_PIN);
}

/**
  * @brief  This function generates start signal.
  * @param  None
  * @retval None
  */
void Soft_I2C_Start(void)
{
	Set_SDA_Out()

	Set_SDA();
	Set_SCL();
	Delay_Us(4);

	Clear_SDA();
	Delay_Us(4);
	Clear_SCL();
}

/**
  * @brief  This function generates stop signal.
  * @param  None
  * @retval None
  */
void Soft_I2C_Stop(void)
{
	Set_SDA_Out()

	Clear_SCL();
	Clear_SDA();
	Delay_Us(4);

	Set_SCL();
	Set_SDA();
	Delay_Us(4);
}

/**
  * @brief  This function wait for ack signal.
  * @param  None
  * @retval An ErrorStatus enumuration value:
  * - SUCCESS: received ack.
  * - ERROR: timeout.
  */
uint8_t Soft_I2C_Wait_Ack(void)
{
	uint8_t timeout = 0;

	Set_SDA_In()

	Set_SDA();
	Delay_Us(1);

	Set_SCL();
	Delay_Us(1);

	while (Read_SDA())
	{
		timeout++;
		if(timeout > 250)
		{
			Soft_I2C_Stop();
			return ERROR;
		}
	}

	Clear_SCL();
	return SUCCESS;
}

/**
  * @brief  This function generates ack signal.
  * @param  None
  * @retval None
  */
void Soft_I2C_Ack(void)
{
	Set_SDA_Out()

	Clear_SCL();
	Clear_SDA();
	Delay_Us(2);

	Set_SCL();
	Delay_Us(2);

	Clear_SCL();
}

/**
  * @brief  This function doesn't generate ack signal.
  * @param  None
  * @retval None
  */
void Soft_I2C_NAck(void)
{
	Set_SDA_Out()

	Clear_SCL();
	Set_SDA();
	Delay_Us(2);

	Set_SCL();
	Delay_Us(2);

	Clear_SCL();
}

/**
  * @brief  This function sends one byte.
  * @param  data: to send to salve.
  * @retval None
  */
void Soft_I2C_Send_Byte(uint8_t data)
{
	uint8_t i;

	Set_SDA_Out()

	Clear_SCL();

	for(i = 0; i < 8; i++)
	{
		if (data & 0x80)
			Set_SDA();
		else
			Clear_SDA();
		Delay_Us(2);

		data <<= 1;

		Set_SCL();
		Delay_Us(2);

		Clear_SCL();
		Delay_Us(2);
	}
}

/**
  * @brief  This function reads one byte.
  * @param  ack: determine whether the host generates ack signal.
  * @retval The data from slave.
  */
uint8_t Soft_I2C_Read_Byte(uint8_t ack)
{
	uint8_t i, rev = 0;

	Set_SDA_In()

	for (i = 0; i < 8; i++)
	{
		Clear_SCL();
		Delay_Us(2);

		Set_SCL();
		rev <<= 1;
		rev += Read_SDA();
		Delay_Us(1);
	}

	if (!ack)
		Soft_I2C_NAck();
	else
		Soft_I2C_Ack();

	return rev;
}

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
