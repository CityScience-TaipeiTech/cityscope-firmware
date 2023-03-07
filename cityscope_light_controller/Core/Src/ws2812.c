#include "tim.h"
#include "ws2812.h"

static uint8_t LED_Data[WS2821_MAX_LED][4];
static uint32_t pwmData[(24 * WS2821_MAX_LED) + 50];

uint8_t data_sent_flag = 0;
uint16_t indx = 0;

void WS2812_SetLed(uint8_t led_id, uint8_t red, uint8_t green, uint8_t blue)
{
  LED_Data[led_id][0] = led_id;
  LED_Data[led_id][1] = green;
  LED_Data[led_id][2] = red;
  LED_Data[led_id][3] = blue;
}

void WS2812_Send(void)
{
  indx = 0;
  uint32_t color;
  for (int i = 0; i < WS2821_MAX_LED; i++)
  {
    color = ((LED_Data[i][1] << 16) | (LED_Data[i][2] << 8) | (LED_Data[i][3]));
    for (int i = 23; i >= 0; i--)
    {
      if (color & (1 << i))
      {
        pwmData[indx] = 60; // 80 * 0.68
      } else
      {
        pwmData[indx] = 30; // 80 * 0.32
      }
      indx++;
    }
  }

  for (int i = 0; i < 50; i++)
  {
    pwmData[indx] = 0;
    indx++;
  }

  HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, pwmData, indx);
  while (!data_sent_flag)
  {
  };
  data_sent_flag = 0;
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim2) 
  {
    HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
    data_sent_flag = 1;
  }
}