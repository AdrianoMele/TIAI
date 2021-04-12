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
// PROGRAM CARRELLO
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,START_BUTTON)

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(BOOL,GO_RIGHT)
  __DECLARE_EXTERNAL(BOOL,GO_LEFT)
  __DECLARE_EXTERNAL(BOOL,LOAD)
  __DECLARE_EXTERNAL(BOOL,FD)
  __DECLARE_EXTERNAL(BOOL,FS)
  __DECLARE_EXTERNAL(BOOL,FR)
  R_TRIG R_TRIG1;
  STEP __step_list[4];
  UINT __nb_steps;
  ACTION __action_list[4];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[4];
  __IEC_BOOL_t __debug_transition_list[4];
  UINT __nb_transitions;
  TIME __lasttick_time;

} CARRELLO;

void CARRELLO_init__(CARRELLO *data__, BOOL retain);
// Code part
void CARRELLO_body__(CARRELLO *data__);
// PROGRAM SIMULAZIONE_CARRELLO
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,DUMMY1)
  __DECLARE_VAR(BOOL,DUMMY2)
  __DECLARE_VAR(BOOL,DUMMY3)
  __DECLARE_EXTERNAL(BOOL,GO_RIGHT)
  __DECLARE_EXTERNAL(BOOL,GO_LEFT)
  __DECLARE_EXTERNAL(BOOL,LOAD)
  __DECLARE_EXTERNAL(BOOL,FD)
  __DECLARE_EXTERNAL(BOOL,FS)
  __DECLARE_EXTERNAL(BOOL,FR)
  STEP __step_list[7];
  UINT __nb_steps;
  ACTION __action_list[6];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[7];
  __IEC_BOOL_t __debug_transition_list[7];
  UINT __nb_transitions;
  TIME __lasttick_time;

} SIMULAZIONE_CARRELLO;

void SIMULAZIONE_CARRELLO_init__(SIMULAZIONE_CARRELLO *data__, BOOL retain);
// Code part
void SIMULAZIONE_CARRELLO_body__(SIMULAZIONE_CARRELLO *data__);
#endif //__POUS_H
