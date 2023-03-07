/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ws2812.h
  * @brief   This file contains all the function prototypes for
  *          the ws2812.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 CSL Taipei Tech.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WS2812_H__
#define __WS2812_H__

#define WS2821_MAX_LED 10

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdint.h>
#include <stdbool.h>
void WS2812_SetLed(uint8_t led_id, uint8_t red, uint8_t green, uint8_t blue);
void WS2812_Send(void);
#ifdef __cplusplus
}
#endif

#endif /* __WS2812_H__ */

