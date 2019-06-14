/**
  ******************************************************************************
  * @file    printk.c
  * @author  andrew <mrju.email@gmail.com>
  * @version V0.0.0
  * @date    xx-xx-2019
  * @brief   printk driver body
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
#include <stdio.h>
#include "usart.h"

/**
  * @brief  This function redirect uart1 tx.
	* @param  ch: the char to send.
  * @param  f: the standard I/O required.
  * @retval None
  */
int fputc(int ch, FILE *f)
{
  USART_SendData(USART1, (uint8_t)ch);
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
  return ch;
}

/**
  * @brief  This function redirect uart1 rx.
  * @param  f: the standard I/O required.
  * @retval None
  */
int fgetc(FILE *f)
{
  while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
  return (int)USART_ReceiveData(USART1);
}

/******************* (C) COPYRIGHT 2019 andrew <mrju.email@gmail.com> *****END OF FILE****/
