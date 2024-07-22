#include "uart_handler.h"
#include "car_control.h"
#include <stdbool.h>

uint8_t cmd = '\n';   // define the variable receive the data from hc05 
UART_HandleTypeDef huart1;  // Open the UART

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
      {
        if(huart->Instance == huart1.Instance)
          {
	          if (cmd != '\n')
	          flag = 1;		
          }
      }
    void handle()
      {
				
        if (flag==1)	
          {
              switch(cmd)
                {
                    case 'F':
											if(carEnable)
                      tien();
                      flag = 0;
                      break;
                    case 'B':
                      if(carEnable)
											lui();
                      flag = 0;   
                      break;
                    case 'L':
											if(carEnable)
                      quay_trai();
                      flag = 0;
                      break;
                    case 'R':
											if(carEnable)
                      quay_phai();
                      flag = 0;
                      break;
                    case 'S':
											if(carEnable)
											dung_lai();
											flag = 0;
											break;
										case 'X':
										 case 'x':
											carEnable = !carEnable;
											flag = 0;
                break;
										default:	// Use to change the speed of car 
											if(cmd >= '1' && cmd <= '9')
												{
													PWM_Car = (1023 * 50) / 100;
												}
											else if (cmd == '0')
												{
													PWM_Car = 0;
												}
											else if (cmd == 'q')
												{
													PWM_Car = 1023; 
												}
                }
                  HAL_UART_Receive_IT(&huart1, &cmd, 1);						

	        }
      }