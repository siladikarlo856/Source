/**
  ******************************************************************************
  * @file    ball.h 
  * @author  Karlo Siladi
  * @version V1.0.0
  * @date    
  * @brief   Header for ball.c module
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BALL_H
#define __BALL_H

/* Includes ------------------------------------------------------------------*/
#include <stm32f4xx.h>
#include <stdlib.h>
#include "lcd.h"
#include "mems.h"

/* Defines ------------------------------------------------------------------*/
#define LEFT_BOUNDARY 		10
#define RIGHT_BOUNDARY		310
#define TOP_BOUNDARY			10
#define BOTTOM_BOUNDARY		230

#define BALL_RADIUS				20
#define BALL_COLOR		LCD_COLOR_GREEN
#define WALL_BOUNCE			 -0.5
#define SENSOR_DENSITY		0.05
/* Exported types ------------------------------------------------------------*/
typedef struct 
{
  int16_t X;
  int16_t Y;
	int16_t Vx;
	int16_t Vy;
} Ball, * pBall; 
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void BALL_Display(Ball ball);
void BALL_Update(L3GD20_t L3GD20_Data, Ball* ball);

#endif /* __BALL_H */

/*******************************END OF FILE************************************/
