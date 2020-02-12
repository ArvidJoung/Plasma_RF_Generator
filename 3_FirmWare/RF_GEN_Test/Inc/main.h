/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VDC_IN_AD_Pin GPIO_PIN_0
#define VDC_IN_AD_GPIO_Port GPIOC
#define VDC_OUT_AD_Pin GPIO_PIN_1
#define VDC_OUT_AD_GPIO_Port GPIOC
#define PW_IS_AD_Pin GPIO_PIN_2
#define PW_IS_AD_GPIO_Port GPIOC
#define FAN_PW_AD_Pin GPIO_PIN_3
#define FAN_PW_AD_GPIO_Port GPIOC
#define RV_CT_AD_Pin GPIO_PIN_0
#define RV_CT_AD_GPIO_Port GPIOA
#define FW_CT_AD_Pin GPIO_PIN_1
#define FW_CT_AD_GPIO_Port GPIOA
#define FET_T_AD_Pin GPIO_PIN_2
#define FET_T_AD_GPIO_Port GPIOA
#define PA6_FAN_PWM_Pin GPIO_PIN_6
#define PA6_FAN_PWM_GPIO_Port GPIOA
#define DDS_SLEEP_Pin GPIO_PIN_0
#define DDS_SLEEP_GPIO_Port GPIOB
#define DDS_RESET_Pin GPIO_PIN_1
#define DDS_RESET_GPIO_Port GPIOB
#define DDS_FSYNC_Pin GPIO_PIN_2
#define DDS_FSYNC_GPIO_Port GPIOB
#define DDS_CLK_Pin GPIO_PIN_10
#define DDS_CLK_GPIO_Port GPIOB
#define DDS_DATA_Pin GPIO_PIN_11
#define DDS_DATA_GPIO_Port GPIOB
#define PB12_LIMIT_SW_A_Pin GPIO_PIN_12
#define PB12_LIMIT_SW_A_GPIO_Port GPIOB
#define PB13_LIMIT_SW_B_Pin GPIO_PIN_13
#define PB13_LIMIT_SW_B_GPIO_Port GPIOB
#define JP_BIAS_Pin GPIO_PIN_14
#define JP_BIAS_GPIO_Port GPIOB
#define PC6_PW_PWM_Pin GPIO_PIN_6
#define PC6_PW_PWM_GPIO_Port GPIOC
#define PC7_PWR_ENA_Pin GPIO_PIN_7
#define PC7_PWR_ENA_GPIO_Port GPIOC
#define PC8_PRE_AMP_ENA_Pin GPIO_PIN_8
#define PC8_PRE_AMP_ENA_GPIO_Port GPIOC
#define PD2_GPIO_ON_Pin GPIO_PIN_2
#define PD2_GPIO_ON_GPIO_Port GPIOD
#define COM_LED_Pin GPIO_PIN_3
#define COM_LED_GPIO_Port GPIOB
#define WDT_LED_Pin GPIO_PIN_4
#define WDT_LED_GPIO_Port GPIOB
#define EPROM_WP_Pin GPIO_PIN_5
#define EPROM_WP_GPIO_Port GPIOB
#define PB6_BIAS_ON_Pin GPIO_PIN_6
#define PB6_BIAS_ON_GPIO_Port GPIOB
#define PLA_ON_LED_Pin GPIO_PIN_9
#define PLA_ON_LED_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
