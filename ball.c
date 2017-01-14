/**
  ******************************************************************************
  * @file    ball.c 
  * @author  Karlo Siladi
  * @version V1.0.0
  * @date    
  * @brief  Functions of ball
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ball.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
void BALL_Display(Ball ball)
{
		LCD_DrawFullCircle(ball.X, ball.Y, BALL_RADIUS);
}
/**
  * @}
  */
void BALL_Update(L3GD20_t L3GD20_Data, Ball* ball)
{
	// Variable for motion check 
	Ball oldBall = *ball;
	
	// Sensor and LCD are in inverse orientation
	ball->Vx += L3GD20_Data.Y * SENSOR_DENSITY;
	ball->Vy += L3GD20_Data.X * SENSOR_DENSITY;

	ball->X += (ball->Vx);
	ball->Y += (ball->Vy);

	if(ball->Y >= RIGHT_BOUNDARY-BALL_RADIUS-1){
		ball->Y = RIGHT_BOUNDARY-BALL_RADIUS-1;
		ball->Vy *= WALL_BOUNCE;
	}
	if(ball->Y <= LEFT_BOUNDARY+BALL_RADIUS+1){
		ball->Y = LEFT_BOUNDARY+BALL_RADIUS+1;
		ball->Vy *= WALL_BOUNCE;
	}
	if(ball->X <= TOP_BOUNDARY+BALL_RADIUS+1){
		ball->X = TOP_BOUNDARY+BALL_RADIUS+1;
		ball->Vx *= WALL_BOUNCE;
	}
	if(ball->X >= BOTTOM_BOUNDARY-BALL_RADIUS-1){
		ball->X = BOTTOM_BOUNDARY-BALL_RADIUS-1;
		ball->Vx *= WALL_BOUNCE;
	}
	
	if(oldBall.X != ball->X || oldBall.Y != ball->Y) {
		/* Update ball on LCD */
		LCD_SetTextColor(LCD_COLOR_WHITE);
		BALL_Display(oldBall);
		LCD_SetTextColor(BALL_COLOR);
		BALL_Display(*ball);
	}
	
}

/******************************END OF FILE*****************************************/
