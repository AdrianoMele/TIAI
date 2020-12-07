#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
__DECLARE_STRUCT_TYPE(GESTIONEPIANI,
  SINT DIR;
    SINT PIANO_CORRENTE;
  )
__DECLARE_ARRAY_TYPE(__ARRAY_OF_SINT_20,SINT,[20])
__DECLARE_STRUCT_TYPE(RICHIESTE,
  USINT TOP;
    UINT DIM;
    USINT BOT;
    __ARRAY_OF_SINT_20 QUEUE;
  )
__DECLARE_STRUCT_TYPE(TASTIERINO,
  BOOL PULS_0;
    BOOL PULS_1;
    BOOL PULS_2;
    BOOL PULS_3;
    BOOL PULS_ALLARM;
  )
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK PYTHON_EVAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_EVAL;

void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain);
// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__);
// FUNCTION_BLOCK PYTHON_POLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_POLL;

void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain);
// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__);
// FUNCTION_BLOCK PYTHON_GEAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  PYTHON_EVAL PY_EVAL;
  __DECLARE_VAR(UINT,COUNTER)
  __DECLARE_VAR(UINT,ADD10_OUT)
  __DECLARE_VAR(BOOL,EQ13_OUT)
  __DECLARE_VAR(UINT,SEL15_OUT)
  __DECLARE_VAR(BOOL,AND7_OUT)

} PYTHON_GEAR;

void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain);
// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__);
// PROGRAM SENSORI_PIANI
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(GESTIONEPIANI,INFO)
  __DECLARE_EXTERNAL(TASTIERINO,DISPLAY)
  __DECLARE_VAR(BOOL,SENSOR0)
  __DECLARE_VAR(BOOL,SENSOR1)
  __DECLARE_VAR(BOOL,SENSOR2)
  __DECLARE_VAR(BOOL,SENSOR3)
  STEP __step_list[5];
  UINT __nb_steps;
  ACTION __action_list[4];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[8];
  __IEC_BOOL_t __debug_transition_list[8];
  UINT __nb_transitions;
  TIME __lasttick_time;

} SENSORI_PIANI;

void SENSORI_PIANI_init__(SENSORI_PIANI *data__, BOOL retain);
// Code part
void SENSORI_PIANI_body__(SENSORI_PIANI *data__);
// FUNCTION
RICHIESTE BOUBLESORT_CRESCENTE(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA);
// FUNCTION
RICHIESTE INSERISCI_PIANO_SALITA(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA, 
  SINT PIANO);
// FUNCTION
RICHIESTE BOUBLESORT_DECRESCENTE(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA);
// FUNCTION
RICHIESTE INSERISCI_PIANO_DISCESA(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA, 
  SINT PIANO);
// PROGRAM PRENOTAZIONI_INTERNE
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(BOOL,FLAG)
  __DECLARE_EXTERNAL(RICHIESTE,RICHIESTE_SALITA)
  __DECLARE_EXTERNAL(RICHIESTE,RICHIESTE_DISCESA)
  __DECLARE_EXTERNAL(TASTIERINO,DISPLAY)
  __DECLARE_EXTERNAL(GESTIONEPIANI,INFO)
  STEP __step_list[6];
  UINT __nb_steps;
  ACTION __action_list[4];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[9];
  __IEC_BOOL_t __debug_transition_list[9];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PRENOTAZIONI_INTERNE;

void PRENOTAZIONI_INTERNE_init__(PRENOTAZIONI_INTERNE *data__, BOOL retain);
// Code part
void PRENOTAZIONI_INTERNE_body__(PRENOTAZIONI_INTERNE *data__);
// FUNCTION
RICHIESTE PRELEVA_PIANO(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA);
// PROGRAM PRENOTAZIONI_ESTERNE
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,PULS_0_E)
  __DECLARE_EXTERNAL(GESTIONEPIANI,INFO)
  __DECLARE_EXTERNAL(RICHIESTE,RICHIESTE_SALITA)
  __DECLARE_EXTERNAL(RICHIESTE,RICHIESTE_DISCESA)
  __DECLARE_VAR(BOOL,PULS_1_E)
  __DECLARE_VAR(BOOL,PULS_2_E)
  __DECLARE_VAR(BOOL,PULS_3_E)
  STEP __step_list[5];
  UINT __nb_steps;
  ACTION __action_list[4];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[8];
  __IEC_BOOL_t __debug_transition_list[8];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PRENOTAZIONI_ESTERNE;

void PRENOTAZIONI_ESTERNE_init__(PRENOTAZIONI_ESTERNE *data__, BOOL retain);
// Code part
void PRENOTAZIONI_ESTERNE_body__(PRENOTAZIONI_ESTERNE *data__);
// PROGRAM GESTIONE_MOTORE
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(SINT,ACTUATOR)
  __DECLARE_VAR(BOOL,PORTE)
  __DECLARE_VAR(BOOL,SENSOR_PORTE)
  __DECLARE_EXTERNAL(BOOL,FLAG)
  __DECLARE_EXTERNAL(GESTIONEPIANI,INFO)
  __DECLARE_EXTERNAL(RICHIESTE,RICHIESTE_SALITA)
  __DECLARE_EXTERNAL(RICHIESTE,RICHIESTE_DISCESA)
  STEP __step_list[6];
  UINT __nb_steps;
  ACTION __action_list[7];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[7];
  __IEC_BOOL_t __debug_transition_list[7];
  UINT __nb_transitions;
  TIME __lasttick_time;

} GESTIONE_MOTORE;

void GESTIONE_MOTORE_init__(GESTIONE_MOTORE *data__, BOOL retain);
// Code part
void GESTIONE_MOTORE_body__(GESTIONE_MOTORE *data__);
#endif //__POUS_H
