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
// PROGRAM SIM_TRAPANO
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,ROT)
  __DECLARE_VAR(BOOL,OIL)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,DWN)
  __DECLARE_VAR(BOOL,A)
  __DECLARE_VAR(BOOL,M)
  __DECLARE_VAR(BOOL,B)
  __DECLARE_VAR(BOOL,X)
  __DECLARE_VAR(BOOL,Y)
  __DECLARE_VAR(BOOL,P_ALTO)
  TON TON0;
  TON TON1;
  TON TON2;
  TON TON3;
  TON TON4;
  TON TON5;
  STEP __step_list[12];
  UINT __nb_steps;
  ACTION __action_list[5];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[17];
  __IEC_BOOL_t __debug_transition_list[17];
  UINT __nb_transitions;
  TIME __lasttick_time;

} SIM_TRAPANO;

void SIM_TRAPANO_init__(SIM_TRAPANO *data__, BOOL retain);
// Code part
void SIM_TRAPANO_body__(SIM_TRAPANO *data__);
// PROGRAM MAIN_TRAPANO
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,P)
  __DECLARE_VAR(BOOL,A)
  __DECLARE_VAR(BOOL,M)
  __DECLARE_VAR(BOOL,B)
  __DECLARE_VAR(BOOL,X)
  __DECLARE_VAR(BOOL,Y)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,DWN)
  __DECLARE_VAR(BOOL,ROT)
  __DECLARE_VAR(BOOL,OIL)
  STEP __step_list[8];
  UINT __nb_steps;
  ACTION __action_list[4];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[9];
  __IEC_BOOL_t __debug_transition_list[9];
  UINT __nb_transitions;
  TIME __lasttick_time;

} MAIN_TRAPANO;

void MAIN_TRAPANO_init__(MAIN_TRAPANO *data__, BOOL retain);
// Code part
void MAIN_TRAPANO_body__(MAIN_TRAPANO *data__);
#endif //__POUS_H
