#include "car_control.h"

float flag = 0;  // Flag to check the signal from HC05
bool carEnable = true;
float PWM_Car;  // Speed of car 
TIM_HandleTypeDef htim2;

// Function of control car 
		void tien()
      {
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, PWM_Car);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, PWM_Car);
      }
    void lui()
      {
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, PWM_Car);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, PWM_Car);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
      }
    void quay_trai()
      {
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, PWM_Car);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, PWM_Car);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);				
      }
    void quay_phai()
      {
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, PWM_Car);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, PWM_Car);				
      }
    void dung_lai()
      {
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
      }