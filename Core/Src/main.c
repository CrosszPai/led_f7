/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_TIM2_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
volatile int count = 0;
volatile int count2 = 0;
volatile int count3 = 0;
volatile int count4 = 0;
volatile int count5 = 0;
volatile int count6 = 0;
volatile int count7 = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == RESET_B_Pin){
		count = 0;
		count2 = 0;
		count3 = 0;
		count4 = 0;
		count5 = 0;
		count6 = 0;
		count7 = 0;
		HAL_GPIO_WritePin(OUT1_1_GPIO_Port, OUT1_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT1_2_GPIO_Port, OUT1_2_Pin, RESET);
		HAL_GPIO_WritePin(OUT2_1_GPIO_Port, OUT2_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT2_2_GPIO_Port, OUT2_2_Pin, RESET);
		HAL_GPIO_WritePin(OUT3_1_GPIO_Port, OUT3_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT3_2_GPIO_Port, OUT3_2_Pin, RESET);
		HAL_GPIO_WritePin(OUT4_1_GPIO_Port, OUT4_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT4_2_GPIO_Port, OUT4_2_Pin, RESET);
		HAL_GPIO_WritePin(OUT5_1_GPIO_Port, OUT5_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT5_2_GPIO_Port, OUT5_2_Pin, RESET);
		HAL_GPIO_WritePin(OUT6_1_GPIO_Port, OUT6_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT6_2_GPIO_Port, OUT6_2_Pin, RESET);
		HAL_GPIO_WritePin(OUT7_1_GPIO_Port, OUT7_1_Pin, RESET);
		HAL_GPIO_WritePin(OUT7_2_GPIO_Port, OUT7_2_Pin, RESET);
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, RESET);
	}
	if(GPIO_Pin == IN1_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count++;
		if(count == 3){
			count = 0;
		}
		if(count == 0){
			HAL_GPIO_WritePin(OUT1_1_GPIO_Port, OUT1_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT1_2_GPIO_Port, OUT1_2_Pin, RESET);
		}
		if(count == 1){
			HAL_GPIO_WritePin(OUT1_1_GPIO_Port, OUT1_1_Pin, SET);
			HAL_GPIO_WritePin(OUT1_2_GPIO_Port, OUT1_2_Pin, RESET);
		}
		if(count == 2){
			HAL_GPIO_WritePin(OUT1_1_GPIO_Port, OUT1_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT1_2_GPIO_Port, OUT1_2_Pin, SET);
		}
	}
	if(GPIO_Pin == IN2_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count2++;
		if(count2 == 3){
			count2 = 0;
		}
		if(count2 == 0){
			HAL_GPIO_WritePin(OUT2_1_GPIO_Port, OUT2_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT2_2_GPIO_Port, OUT2_2_Pin, RESET);
		}
		if(count2 == 1){
			HAL_GPIO_WritePin(OUT2_1_GPIO_Port, OUT2_1_Pin, SET);
			HAL_GPIO_WritePin(OUT2_2_GPIO_Port, OUT2_2_Pin, RESET);
		}
		if(count2 == 2){
			HAL_GPIO_WritePin(OUT1_1_GPIO_Port, OUT2_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT2_2_GPIO_Port, OUT2_2_Pin, SET);
		}
	}
	if(GPIO_Pin == IN3_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count3++;
		if(count3 == 3){
			count3 = 0;
		}
		if(count3 == 0){
			HAL_GPIO_WritePin(OUT3_1_GPIO_Port, OUT3_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT3_2_GPIO_Port, OUT3_2_Pin, RESET);
		}
		if(count3 == 1){
			HAL_GPIO_WritePin(OUT3_1_GPIO_Port, OUT3_1_Pin, SET);
			HAL_GPIO_WritePin(OUT3_2_GPIO_Port, OUT3_2_Pin, RESET);
		}
		if(count3 == 2){
			HAL_GPIO_WritePin(OUT3_1_GPIO_Port, OUT3_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT3_2_GPIO_Port, OUT3_2_Pin, SET);
		}
	}
	if(GPIO_Pin == IN4_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count4++;
		if(count4 == 3){
			count4 = 0;
		}
		if(count4 == 0){
			HAL_GPIO_WritePin(OUT4_1_GPIO_Port, OUT4_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT4_2_GPIO_Port, OUT4_2_Pin, RESET);
		}
		if(count4 == 1){
			HAL_GPIO_WritePin(OUT4_1_GPIO_Port, OUT4_1_Pin, SET);
			HAL_GPIO_WritePin(OUT4_2_GPIO_Port, OUT4_2_Pin, RESET);
		}
		if(count4 == 2){
			HAL_GPIO_WritePin(OUT4_1_GPIO_Port, OUT4_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT4_2_GPIO_Port, OUT4_2_Pin, SET);
		}
	}
	if(GPIO_Pin == IN5_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count5++;
		if(count5 == 3){
			count5 = 0;
		}
		if(count5 == 0){
			HAL_GPIO_WritePin(OUT5_1_GPIO_Port, OUT5_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT5_2_GPIO_Port, OUT5_2_Pin, RESET);
		}
		if(count5 == 1){
			HAL_GPIO_WritePin(OUT5_1_GPIO_Port, OUT5_1_Pin, SET);
			HAL_GPIO_WritePin(OUT5_2_GPIO_Port, OUT5_2_Pin, RESET);
		}
		if(count5 == 2){
			HAL_GPIO_WritePin(OUT5_1_GPIO_Port, OUT5_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT5_2_GPIO_Port, OUT5_2_Pin, SET);
		}
	}
	if(GPIO_Pin == IN6_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count6++;
		if(count6 == 3){
			count6 = 0;
		}
		if(count6 == 0){
			HAL_GPIO_WritePin(OUT6_1_GPIO_Port, OUT6_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT6_2_GPIO_Port, OUT6_2_Pin, RESET);
		}
		if(count6 == 1){
			HAL_GPIO_WritePin(OUT6_1_GPIO_Port, OUT6_1_Pin, SET);
			HAL_GPIO_WritePin(OUT6_2_GPIO_Port, OUT6_2_Pin, RESET);
		}
		if(count6 == 2){
			HAL_GPIO_WritePin(OUT6_1_GPIO_Port, OUT6_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT6_2_GPIO_Port, OUT6_2_Pin, SET);
		}
	}
	if(GPIO_Pin == IN7_Pin){
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, SET);
		count7++;
		if(count7 == 3){
			count7 = 0;
		}
		if(count7 == 0){
			HAL_GPIO_WritePin(OUT7_1_GPIO_Port, OUT7_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT7_2_GPIO_Port, OUT7_2_Pin, RESET);
		}
		if(count7 == 1){
			HAL_GPIO_WritePin(OUT7_1_GPIO_Port, OUT7_1_Pin, SET);
			HAL_GPIO_WritePin(OUT7_2_GPIO_Port, OUT7_2_Pin, RESET);
		}
		if(count7 == 2){
			HAL_GPIO_WritePin(OUT7_1_GPIO_Port, OUT7_1_Pin, RESET);
			HAL_GPIO_WritePin(OUT7_2_GPIO_Port, OUT7_2_Pin, SET);
		}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
