#include <DAC.h>
/**
    PA4 come pin di comando  
*/

/**INZIALIZZAZIONE DEL DAC*/
void init_dac(){
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  GPIOA->MODER |= GPIO_MODER_MODER4;
  DAC->CR |= DAC_CR_EN1;
}
/**DIABILITAZIONE DEL DAC*/
void disable_dac(){
   RCC->APB1ENR &= ~RCC_APB1ENR_DACEN;
}
/**PILOTAGGIO DEL DAC*/
void setVoltage(float voltage){
  float temp = (float) 4095.0*voltage;
  int data = (int) temp/3;
  DAC->DHR12R1 = data;
  for(int i=0; i<1000; i++);
}