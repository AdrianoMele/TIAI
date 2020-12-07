#ifndef DAC_H
#define DAC_H
#include <stm32f30x.h>

void init_dac();
void disable_dac();

void setVoltage(float voltage);

#endif