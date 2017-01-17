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

/**
  * @brief  Macro that calculate absolute value of x
  * @param  Integer x
  * @retval Absolute value of x
  */
#define abs(x)  ( ( (x) < 0) ? -(x) : (x) )

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
void BALL_MoveBall(Ball *ball);

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

	/*Move ball*/
	ball->X += (ball->Vx);
	ball->Y += (ball->Vy);

	/* check boundaries */
	if(ball->Y >= RIGHT_BOUNDARY-BALL_RADIUS-1){
		ball->Y = RIGHT_BOUNDARY-BALL_RADIUS-2;
		ball->Vy *= WALL_BOUNCE;
	}
	if(ball->Y <= LEFT_BOUNDARY+BALL_RADIUS+1){
		ball->Y = LEFT_BOUNDARY+BALL_RADIUS+2;
		ball->Vy *= WALL_BOUNCE;
	}
	if(ball->X <= TOP_BOUNDARY+BALL_RADIUS+1){
		ball->X = TOP_BOUNDARY+BALL_RADIUS+2;
		ball->Vx *= WALL_BOUNCE;
	}
	if(ball->X >= BOTTOM_BOUNDARY-BALL_RADIUS-1){
		ball->X = BOTTOM_BOUNDARY-BALL_RADIUS-2;
		ball->Vx *= WALL_BOUNCE;
	}
	
	/* Check if ball moves */
	if(oldBall.X != ball->X || oldBall.Y != ball->Y) {
		/* Ball is moving. Reset NO_ACTIVITY_TIMER */
		TIM_ResetCountdown(TIM1);
		
		/* Refresh ball only if it moves */
		LCD_SetTextColor(LCD_COLOR_WHITE);
		BALL_Display(oldBall);
		LCD_SetTextColor(BALL_COLOR);
		BALL_Display(*ball);
	}
	
}

/**
  * @brief  Refresh x and y coordinate 
	* @param  Ball*: pointer to ball
  * @retval None
  */
void BALL_MoveBall(Ball *ball)
{

}

/******************************END OF FILE*****************************************/
