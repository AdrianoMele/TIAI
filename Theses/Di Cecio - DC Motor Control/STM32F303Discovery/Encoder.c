#include <Encoder.h>

/**INIZIALIZZAZIONE DELL'ENCODER*/
void init_encoder(){
  /* TIM2_Ch2 -> PA1 (AF1)*/
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;    //Abilito il clock
 
  GPIOA->MODER |= 1<<3;                 //PA1 in modalità Alternate Function
  GPIOA->MODER &= ~(1<<2); 
  GPIOA->AFR[0] |= 1<<4;                //Configuro AF1
  
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;   //Abilito TIM2
  
  TIM2->SMCR |= 7;                      //Modalità con clock 
  TIM2->CCMR1 &= ~(1<<9);               //Ch2 usato come input
  TIM2->CCMR1 |= (1<<8);
  TIM2->SMCR |= 1<<6;                   //Input sul ch2
  TIM2->SMCR |= 1<<5;
  TIM2->SMCR &= ~(1<<4);
}
/**AVVIO DELL'ENCODER*/
void start_encoder(){
  TIM2->CR1 |= TIM_CR1_CEN;             //Abilito il conteggio
}
/**INIZIALIZZAZIONE DEL TIMER PER LA ISR DI CONTROLLO*/
int init_timer(int frequenza_attivazione){
  /*Frequenza di campionamento 1kHz */
  int i = 1;
  uint32_t frequenza_timer;
  uint32_t arr;
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;   //Abilito TIM3
  do{
    frequenza_timer = FRQ/i;
    arr = (uint32_t) frequenza_timer/frequenza_attivazione;
    i++;
  }while(arr > 65535);
  TIM3->ARR = (uint16_t) arr;         //Auto-reload register
  TIM3->PSC = (uint16_t) i-1;             //Scalatura del clock
  TIM3->DIER |= 1;                      //Abilito le interruzioni
  NVIC->ISER[0] |= 1<<29;               //ISR per il TIM3
  return arr;
}
/**AVVIO DEL TIMER*/
void start_timer(){
  TIM3->CR1 |= TIM_CR1_CEN;             //Parte il timer
}
/**SELEZIONE DELLA DIREZIONE DEL MOTORE ATTRAVERSO IL DRIVER*/
void setDirection(int dir){
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;   //Abilito il clock per GPIOB
   
  GPIOB->MODER |= 1;                    //PB0 come output
  GPIOB->MODER &= ~(1<<1);
  GPIOB->MODER |= 1<<2;                 //PB1 come output
  GPIOB->MODER &= ~(1<<3);
  GPIOB->ODR |= 1<<1;                   //Sempre a 1
  GPIOB->MODER |= 1<<4;                 //PB2 come output
  GPIOB->MODER &= ~(1<<5);     
  
  switch(dir){
    case 1:
      GPIOB->ODR |= 1;
      GPIOB->ODR &= ~(1<<2);
      break;
  case 0:
      GPIOB->ODR &= ~1;
      GPIOB->ODR |= (1<<2);
      break;
  }
}
/**INIZIALIZZAZIONE DEL DRIVER E DELLA PERIFERICA PWM*/
void init_pwm(){
  /*TIM4_Ch1-> PD12 (AF2) */
  RCC->AHBENR |= RCC_AHBENR_GPIODEN;    //Abilito il clock per la periferica GPIOD
  GPIOD->MODER |= 1<<25;                //D12 in modalità Alternate Function
  GPIOD->MODER &= ~(1<<24);
  GPIOD->AFR[1] = 0;                    //Azzero il registro
  GPIOD->AFR[1] |= 1<<17;               //Configuro AF2
  
  setDirection(1);
 
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;   //Abilito TIM4     
  
  TIM4->CCMR1 |= 1<<3;                  //Abilito l'accesso al CCR1
  TIM4->CCMR1 |= 1<<6;                  //PWM Mode 1 per il canale 1
  TIM4->CCMR1 |= 1<<5;
  TIM4->CCMR1 &= ~(1<<4);
  
  TIM4->ARR = 1440;                     //Frq 50kHz
  
  TIM4->CCER |= 1;                      //Segnale in uscita dal pin
  
  TIM4->CR1 |= 1;                       //Abilito il conteggio  
}
/**AVVIO DEL DRIVER*/
void set_pwm(double duty){
  TIM4->CCR1 = (int) (1440*duty)/100;   //Configuro il duty-cycle
}

/**DISABILITAZIONE DEL TIMER DI CONTROLLO*/
void disable_timer(){
  RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN);
}
/**DISABILITAZIONE DEL TIMER DELL'ENCODER*/
void disable_encoder(){
   RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2EN);
}
/**DISABILITAZIONE DEL TIMER DEL DRIVER*/
void disable_pwm(){
  RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN);
}

