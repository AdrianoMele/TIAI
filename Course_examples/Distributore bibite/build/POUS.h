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
// FUNCTION_BLOCK DISTRIBUTORE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ATTIVA_SA)
  __DECLARE_VAR(BOOL,EROGA_PRODOTTO)
  __DECLARE_VAR(BOOL,RICARICA_PRODOTTO)
  __DECLARE_VAR(BOOL,PRELEVA)
  __DECLARE_VAR(BOOL,SVUOTA)
  __DECLARE_VAR(INT,PRODOTTI_DA_PRELEVARE)
  __DECLARE_VAR(BOOL,PRODOTTI_DISP)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,N_PRODOTTI)
  __DECLARE_VAR(BOOL,PRODOTTI_BUFFER)
  __DECLARE_VAR(BOOL,EROGA_TRIG)
  __DECLARE_VAR(BOOL,BUFFER_TRIG)
  R_TRIG RTRIG_EROGA;
  R_TRIG RTRIG_BUFFER;

} DISTRIBUTORE;

void DISTRIBUTORE_init__(DISTRIBUTORE *data__, BOOL retain);
// Code part
void DISTRIBUTORE_body__(DISTRIBUTORE *data__);
// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(BOOL,MONETA)
  __DECLARE_EXTERNAL(BOOL,SA)
  __DECLARE_EXTERNAL(BOOL,SB)
  __DECLARE_EXTERNAL(BOOL,APERTO)
  __DECLARE_EXTERNAL(BOOL,BLOCCA)
  __DECLARE_EXTERNAL(BOOL,SBLOCCA)
  R_TRIG R_TRIG1;
  STEP __step_list[6];
  UINT __nb_steps;
  ACTION __action_list[5];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[5];
  __IEC_BOOL_t __debug_transition_list[5];
  UINT __nb_transitions;
  TIME __lasttick_time;

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
// FUNCTION_BLOCK PISTONE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,APRI)
  __DECLARE_VAR(BOOL,APERTO)

  // FB private variables - TEMP, private and located variables
  TON TON0;
  TON TON1;

} PISTONE;

void PISTONE_init__(PISTONE *data__, BOOL retain);
// Code part
void PISTONE_body__(PISTONE *data__);
// PROGRAM SIMULATOR
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(BOOL,MONETA)
  __DECLARE_EXTERNAL(BOOL,SB)
  __DECLARE_EXTERNAL(BOOL,SA)
  __DECLARE_EXTERNAL(BOOL,SBLOCCA)
  __DECLARE_EXTERNAL(BOOL,BLOCCA)
  __DECLARE_EXTERNAL(BOOL,APERTO)
  __DECLARE_VAR(BOOL,A_APERTO)
  __DECLARE_VAR(BOOL,B_APERTO)
  __DECLARE_VAR(BOOL,PRELEVA_PRODOTTO)
  __DECLARE_VAR(BOOL,RICARICA_PRODOTTO)
  __DECLARE_VAR(BOOL,CREDITO_DISPONIBILE)
  __DECLARE_VAR(INT,PRODOTTI_NEL_VANO)
  __DECLARE_VAR(BOOL,PRODOTTI_DISPONIBILI)
  DISTRIBUTORE DISTRIBUTORE0;
  PISTONE PISTONE0;
  PISTONE PISTONE1;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  R_TRIG R_TRIG3;

} SIMULATOR;

void SIMULATOR_init__(SIMULATOR *data__, BOOL retain);
// Code part
void SIMULATOR_body__(SIMULATOR *data__);
#endif //__POUS_H
