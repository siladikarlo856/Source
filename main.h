/**
  ******************************************************************************
  * @file    main.h 
  * @author  Karlo Siladi
  * @version V1.0.0
  * @date    
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stm32f4xx.h>
#include <stdio.h>
#include "mems.h"
#include "spi.h"
#include "gpio.h"
#include "lcd.h"
#include "ball.h"
#include "systick.h"
#include "touch.h"
#include "timers.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#define NO_ACTIVITY_TIME 5000000

#define STOP		1
#define START		S
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/*******************************END OF FILE************************************/
