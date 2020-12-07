#ifndef ENCODER_H
#define ENCODER_H
#include <stm32f30x.h>
#define FRQ 72000000

void init_encoder();
void init_pwm();
void set_pwm(double duty);
void setDirection(int dir);
int init_timer(int frequenza_attivazione);
void start_timer();
void start_encoder();

void disable_timer();
void disable_encoder();
void disable_pwm();

#endif