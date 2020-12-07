#include <stm32f30x.h>
#include <DAC.h>
#include <Encoder.h>

#define CONV 500        //Dimensione massima del vettore di convoluzione in quanto dopo CONV i valori del vettore di convoluzione sono trascurabili
#define MAX 2000        //Dimensione dell'array da passare a matlab

int fc = 1000;          //Frequenza di campionamento

double matlab[MAX];     //Array da passare a matlab
int index_matlab;
double dx;

double theta[CONV];
double vettore_convoluzione[CONV];
int index_theta;
double velocita;

double alfa=20.2, beta=-0.4, gamma=0.9802;  //Parametri del derivatore reale (ricavati attraverso la digitalizzazione)

double Kp = 0.5853;     //Azione proporzionale PID
double Ki = 0.0094;     //Azione integrale PID
double new_step;        //Posizione corrente
double errore;          //Errore per il controllo
double pwm;             //Uscita del controllore
double somma_integrale; //Variabile di appoggio per l'azione integrale

double REF = 200;       //Velocita di riferimento

/**FUNZIONE PER IL CALCOLO DELLA POTENZA*/
double exp(double base, int esp){
  double prodotto=1;
  if(esp == 0)
    return 1;
  else{
    for(int i=0;i<esp;i++)
        prodotto = (double) prodotto* base;
    return prodotto;
  }
}
/**FUNZIONE DI INIZIALIZZAZIONE DEL DERIVATORE*/
void init_filtro(){
  for(int i=0; i<CONV; i++){
    vettore_convoluzione[i] = exp(gamma, i);            //Inizializzazione del vettore di convoluzione
    theta[i] = 0;
  }
}
/**FUNZIONE DI INSERIMENTO DI UN ELEMENTO NEL VETTORE
    UTILE PER IL CALCOLO DELLA CONVOLUZIONE*/
void inserisci(double* vettore,double pos ,int dim){   
  for(int i=0; i<dim-1; i++){
    vettore[i] = vettore[i+1];
  }
  vettore[dim-1] = pos;
}
/**DERIVAORE REALE*/
double derivatore(double theta_new){ 
  double somma_differenziale=0;
  double prod_conv = 1;
  double vel = 0;
  inserisci(theta,theta_new,CONV);
  //Convoluzione discreta
  for(int i=0, k=CONV-1; i<CONV && k>=0; i++, k--){
    prod_conv = theta[k]*vettore_convoluzione[i];
    somma_differenziale = somma_differenziale+prod_conv;
  }
  vel = (alfa*theta_new)+(beta*somma_differenziale);
  return vel;
}
int main()
{
  init_dac();           // Riferimento per il comparatore
  setVoltage(2.0f);
  init_encoder();       // Sensore              - Inizializza tutte le perferiche per il controllo
  init_timer(fc);       // Campionamento        - Inizializza il timer per generare un'interruzione ogni 1/fc ms
  init_pwm();           // Segnale di controllo - Inizializza la periferica PWM
  
  start_encoder();      // Abilitazione di tutte le periferiche
  somma_integrale = 0;
  errore = 0;
  dx = 36*3.14/180;     //Risoluzione dell'encoder
  
  start_timer();        // Avvio del controllore
 
  while(1);
}

void TIM3_IRQHandler(){
  TIM3->SR &= ~1; 
 /**                               -----------------                ---------                     --------------
                                  |                 |              |         |                   |              |
 REF ---> ( - )----- error -----> |  Controller PI  | --- pmw ---> |  MOTOR  | --- new_step ---> |  Derivatore  | --- velocita ---|--->   
            |                     |                 |              |         |                   |              |                 |
            |                      -----------------                ---------                     --------------                  |
            |                                                                                                                     |
            -----------------------------------------------------------------------------------------------------------------------
 */
  
  new_step = TIM2->CNT;
  
  new_step = (double)new_step*dx;       //Poszione corrente
 
  velocita = derivatore(new_step);      //Velocità corrente
  
  /*RETROAZIONE DEL SISTEMA*/
  errore = REF-velocita;                //Calcolo dell'errore

  /*CONTROLLO PID*/
  somma_integrale = somma_integrale + errore;            //Calcolo dell'azione integrale
  pwm = (double) (Kp*errore + Ki*somma_integrale);       //Calcolo dell'uscita
  if(pwm>70)
    pwm=70;
  if(pwm<0)
    pwm=0;
  set_pwm(pwm);                                          //Applicazione dell'uscita
  
  /*PSALVATAGGIO DEI VALORI DA PASSARE A MATLAB*/
  if(index_matlab<MAX){
    matlab[index_matlab] = velocita;
    index_matlab++;
  }
 
}
    
