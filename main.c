/**
  ******************************************************************************
  * @file    main.c 
  * @author  Karlo Siladi
  * @version V1.0.0
  * @date    
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
void drawStartScreen(void);

static TP_STATE* TP_State;


/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	/* L3GD20 Struct */
	L3GD20_t L3GD20_Data;
	/* Ball Struct	*/
	Ball ball;

	/* SysTick initalization*/
	systickInit(MS_FREQUENCY);
	
	/* LCD initialization */
  LCD_Init();
  /* Example how to use functions to write on LCD */
  drawStartScreen();
  /* L3GD20 Init*/
	L3GD20_Init(L3GD20_Scale_2000);
	
	ball.X = 120;
	ball.Y = 160;
	ball.Vx = 0;
	ball.Vy = 0;
	BALL_Display(ball);
	
	/* Infinite loop */
  while (1)
  {
		/* Read data */
		L3GD20_Read(&L3GD20_Data);
		BALL_Update(L3GD20_Data, &ball);
		
		/* Delay */
		delay_ms(50);
  }
}


/**
  * @brief  Example how to draw and print something on LCD
  * @param  None
  * @retval None
  */
void drawStartScreen(void)
{
		/* Set LCD foreground layer */
		LCD_SetLayer(LCD_FOREGROUND_LAYER);
	
	if (IOE_Config() == IOE_OK)
	{   
		/* Clear LCD and set background color */
		LCD_Clear(LCD_COLOR_BLUE2);
		/* Set LCD font */
		LCD_SetFont(&Font16x24);
		/* Set LCD text color */
		LCD_SetTextColor(LCD_COLOR_BLACK); 
		/*Print sting on LCD line 5*/
		LCD_DisplayStringLine(LINE(4), (uint8_t*)"Touch to start game");
		while(1){
			TP_State = IOE_TP_GetState();
			if(TP_State->TouchDetected) break;
		}
		
		
		/* Clear LCD and set background color */
		LCD_Clear(LCD_COLOR_WHITE);
		/* Set LCD text color */
		LCD_SetTextColor(LCD_COLOR_BLACK); 
		/* Set LCD font */
		LCD_DrawRect(LEFT_BOUNDARY, TOP_BOUNDARY,  RIGHT_BOUNDARY-LEFT_BOUNDARY, BOTTOM_BOUNDARY-TOP_BOUNDARY);
		/* Set LCD font */
		LCD_SetFont(&Font12x12);
		/* Set LCD text color */
		LCD_SetTextColor(BALL_COLOR); 
  }  
  else
  {
    LCD_Clear(LCD_COLOR_RED);
    LCD_SetTextColor(LCD_COLOR_BLACK); 
    LCD_DisplayStringLine(LCD_LINE_6,(uint8_t*)"   IOE NOT OK      ");
    LCD_DisplayStringLine(LCD_LINE_7,(uint8_t*)"Reset the board   ");
    LCD_DisplayStringLine(LCD_LINE_8,(uint8_t*)"and try again     ");
  }
	
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
		
  }
}
#endif

/**
  * @}
  */


/******************************END OF FILE*****************************************/
