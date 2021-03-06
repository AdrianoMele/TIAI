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
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,TEMP_SENS)
  __DECLARE_VAR(INT,TEMP_RIF)
  __DECLARE_VAR(BOOL,ATTERRAGGIO)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,TEMP_OK)
  __DECLARE_VAR(INT,GIORNI)
  __DECLARE_VAR(BOOL,NA)
  __DECLARE_VAR(BOOL,AR)
  __DECLARE_VAR(BOOL,O)
  __DECLARE_VAR(BOOL,NA_OK)
  __DECLARE_VAR(BOOL,AR_OK)
  __DECLARE_VAR(BOOL,O_OK)
  __DECLARE_VAR(BOOL,UMIDITA_OK)
  __DECLARE_VAR(BOOL,IRRIGAZIONE_OK_A)
  __DECLARE_VAR(BOOL,IRRIGAZIONE_OK_E)
  __DECLARE_VAR(BOOL,SEMINA_DES)
  __DECLARE_VAR(BOOL,SEMINA_SIN)
  __DECLARE_VAR(BOOL,SENS_LUCE_BUIO)
  __DECLARE_VAR(BOOL,IRRIGATORE_ACQUA_A)
  __DECLARE_VAR(BOOL,IRRIGATORE_ACQUA_E)
  __DECLARE_VAR(BOOL,START2)
  __DECLARE_VAR(INT,T_18)
  __DECLARE_VAR(INT,T_24)
  __DECLARE_VAR(BOOL,NOT_LUCE)
  __DECLARE_VAR(BOOL,LUCI_EM)
  __DECLARE_VAR(BOOL,EM_ROVER)
  __DECLARE_VAR(BOOL,FINE_EM_LUCE)
  __DECLARE_VAR(BOOL,ESTRAZIONE_OK)
  __DECLARE_VAR(BOOL,A_MOTORE_AVANTI)
  __DECLARE_VAR(BOOL,A_MOTORE_INDIETRO)
  __DECLARE_VAR(BOOL,A_APRI_SPAZZOLA)
  __DECLARE_VAR(BOOL,A_CHIUDI_SPAZZOLA)
  __DECLARE_VAR(BOOL,A_DOCK_RICARICA)
  __DECLARE_VAR(BOOL,SECCO1)
  __DECLARE_VAR(BOOL,SECCO2)
  __DECLARE_VAR(BOOL,A_AZIONA_SPAZZOLA)
  __DECLARE_VAR(BOOL,SENSORE_P)
  __DECLARE_VAR(BOOL,ESPULSIONE_OK)
  __DECLARE_VAR(BOOL,SPORCO)
  __DECLARE_VAR(BOOL,ESTRAZIONE_OSSIGENO)
  __DECLARE_VAR(BOOL,ESPULSIONE_OSSIGENO)
  __DECLARE_VAR(BOOL,VENTILATORE_A)
  __DECLARE_VAR(BOOL,VENTILATORE_B)
  __DECLARE_VAR(BOOL,GIORNO)
  __DECLARE_VAR(BOOL,NOTTE)
  __DECLARE_VAR(BOOL,DURATA_NOTTE)
  __DECLARE_VAR(BOOL,DURATA_GIORNO)
  __DECLARE_VAR(BOOL,TEMP1)
  __DECLARE_VAR(BOOL,UMIDIFICATORE_ACQUA)
  __DECLARE_VAR(BOOL,APERTURA)
  __DECLARE_VAR(BOOL,APERTO)
  R_TRIG R_TRIG1;
  STEP __step_list[39];
  UINT __nb_steps;
  ACTION __action_list[46];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[39];
  __IEC_BOOL_t __debug_transition_list[39];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
