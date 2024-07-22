#ifndef CAR_CONTROL_H
#define CAR_CONTROL_H
#include <stdbool.h>
#include "main.h"

extern float flag;
extern bool carEnable;
extern float PWM_Car;
extern TIM_HandleTypeDef htim2;

void tien();
void lui();
void quay_trai();
void quay_phai();
void dung_lai();

#endif