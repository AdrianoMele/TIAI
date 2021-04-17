void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void SIM_TRAPANO_init__(SIM_TRAPANO *data__, BOOL retain) {
  __INIT_VAR(data__->ROT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OIL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->A,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P_ALTO,0,retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
  UINT i;
  data__->__nb_steps = 12;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[8].X,,1);
  __SET_VAR(data__->,__step_list[10].X,,1);
  data__->__nb_actions = 5;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 17;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define ALTO __step_list[0]
#define __SFC_ALTO 0
#define TRA_A_E_M __step_list[1]
#define __SFC_TRA_A_E_M 1
#define PEZZO_ALTO __step_list[2]
#define __SFC_PEZZO_ALTO 2
#define MEDIO __step_list[3]
#define __SFC_MEDIO 3
#define BASSO __step_list[4]
#define __SFC_BASSO 4
#define PEZZO_BASSO __step_list[5]
#define __SFC_PEZZO_BASSO 5
#define MEDIO_SENZA_PEZZO __step_list[6]
#define __SFC_MEDIO_SENZA_PEZZO 6
#define BASSO_SENZA_PEZZO __step_list[7]
#define __SFC_BASSO_SENZA_PEZZO 7
#define FERMO0 __step_list[8]
#define __SFC_FERMO0 8
#define RUOTA0 __step_list[9]
#define __SFC_RUOTA0 9
#define POMPA_FERMA0 __step_list[10]
#define __SFC_POMPA_FERMA0 10
#define POMPA_ACCESA0 __step_list[11]
#define __SFC_POMPA_ACCESA0 11

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_A 1
#define __SFC_X 2
#define __SFC_M 3
#define __SFC_B 4

// Code part
void SIM_TRAPANO_body__(SIM_TRAPANO *data__) {
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->ALTO.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->TRA_A_E_M.X)) {
    __SET_VAR(data__->,__transition_list[1],,((__GET_VAR(data__->DWN,) && __GET_VAR(data__->Y,)) && __GET_VAR(data__->P_ALTO,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,((__GET_VAR(data__->DWN,) && __GET_VAR(data__->Y,)) && __GET_VAR(data__->P_ALTO,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->PEZZO_ALTO.X)) {
    __SET_VAR(data__->,__transition_list[2],,(__GET_VAR(data__->DWN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PEZZO_ALTO.T,), __time_to_timespec(1, 0, 1, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,(__GET_VAR(data__->DWN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PEZZO_ALTO.T,), __time_to_timespec(1, 0, 1, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->MEDIO.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->TON0.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->TON0.Q,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->BASSO.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->TON3.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->TON3.Q,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->MEDIO.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->TON2.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->TON2.Q,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->TRA_A_E_M.X)) {
    __SET_VAR(data__->,__transition_list[6],,((__GET_VAR(data__->DWN,) && __GET_VAR(data__->Y,)) && !(__GET_VAR(data__->P_ALTO,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,((__GET_VAR(data__->DWN,) && __GET_VAR(data__->Y,)) && !(__GET_VAR(data__->P_ALTO,))));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->PEZZO_BASSO.X)) {
    __SET_VAR(data__->,__transition_list[7],,(__GET_VAR(data__->DWN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PEZZO_BASSO.T,), __time_to_timespec(1, 0, 1, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,(__GET_VAR(data__->DWN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PEZZO_BASSO.T,), __time_to_timespec(1, 0, 1, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->TRA_A_E_M.X)) {
    __SET_VAR(data__->,__transition_list[8],,(__GET_VAR(data__->DWN,) && !(__GET_VAR(data__->Y,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,(__GET_VAR(data__->DWN,) && !(__GET_VAR(data__->Y,))));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MEDIO_SENZA_PEZZO.X)) {
    __SET_VAR(data__->,__transition_list[9],,(__GET_VAR(data__->DWN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->MEDIO_SENZA_PEZZO.T,), __time_to_timespec(1, 0, 1, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,(__GET_VAR(data__->DWN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->MEDIO_SENZA_PEZZO.T,), __time_to_timespec(1, 0, 1, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->BASSO_SENZA_PEZZO.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->TON4.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->TON4.Q,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MEDIO_SENZA_PEZZO.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TON5.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TON5.Q,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->TRA_A_E_M.X)) {
    __SET_VAR(data__->,__transition_list[12],,(__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DWN,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,(__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DWN,))));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->FERMO0.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->ROT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->ROT,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->RUOTA0.X)) {
    __SET_VAR(data__->,__transition_list[14],,!(__GET_VAR(data__->ROT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,!(__GET_VAR(data__->ROT,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->POMPA_FERMA0.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->OIL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->OIL,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->POMPA_ACCESA0.X)) {
    __SET_VAR(data__->,__transition_list[16],,!(__GET_VAR(data__->OIL,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,!(__GET_VAR(data__->OIL,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,ALTO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,TRA_A_E_M.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PEZZO_ALTO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MEDIO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,BASSO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MEDIO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,TRA_A_E_M.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PEZZO_BASSO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,TRA_A_E_M.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MEDIO_SENZA_PEZZO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,BASSO_SENZA_PEZZO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MEDIO_SENZA_PEZZO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,TRA_A_E_M.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,FERMO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,RUOTA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,POMPA_FERMA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,POMPA_ACCESA0.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,TRA_A_E_M.X,,1);
    data__->TRA_A_E_M.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PEZZO_ALTO.X,,1);
    data__->PEZZO_ALTO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MEDIO.X,,1);
    data__->MEDIO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,BASSO.X,,1);
    data__->BASSO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,MEDIO.X,,1);
    data__->MEDIO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,ALTO.X,,1);
    data__->ALTO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PEZZO_BASSO.X,,1);
    data__->PEZZO_BASSO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MEDIO.X,,1);
    data__->MEDIO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MEDIO_SENZA_PEZZO.X,,1);
    data__->MEDIO_SENZA_PEZZO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,BASSO_SENZA_PEZZO.X,,1);
    data__->BASSO_SENZA_PEZZO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,MEDIO_SENZA_PEZZO.X,,1);
    data__->MEDIO_SENZA_PEZZO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,ALTO.X,,1);
    data__->ALTO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,ALTO.X,,1);
    data__->ALTO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,RUOTA0.X,,1);
    data__->RUOTA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,FERMO0.X,,1);
    data__->FERMO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,POMPA_ACCESA0.X,,1);
    data__->POMPA_ACCESA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,POMPA_FERMA0.X,,1);
    data__->POMPA_FERMA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // ALTO action associations
  {
    char active = __GET_VAR(data__->ALTO.X);
    char activated = active && !data__->ALTO.prev_state;
    char desactivated = !active && data__->ALTO.prev_state;

    if (active)       {__SET_VAR(data__->,A,,1);};
    if (desactivated) {__SET_VAR(data__->,A,,0);};

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // PEZZO_ALTO action associations
  {
    char active = __GET_VAR(data__->PEZZO_ALTO.X);
    char activated = active && !data__->PEZZO_ALTO.prev_state;
    char desactivated = !active && data__->PEZZO_ALTO.prev_state;

    if (active)       {__SET_VAR(data__->,X,,1);};
    if (desactivated) {__SET_VAR(data__->,X,,0);};

  }

  // MEDIO action associations
  {
    char active = __GET_VAR(data__->MEDIO.X);
    char activated = active && !data__->MEDIO.prev_state;
    char desactivated = !active && data__->MEDIO.prev_state;

    if (active)       {__SET_VAR(data__->,X,,1);};
    if (desactivated) {__SET_VAR(data__->,X,,0);};

    if (active)       {__SET_VAR(data__->,M,,1);};
    if (desactivated) {__SET_VAR(data__->,M,,0);};

  }

  // BASSO action associations
  {
    char active = __GET_VAR(data__->BASSO.X);
    char activated = active && !data__->BASSO.prev_state;
    char desactivated = !active && data__->BASSO.prev_state;

    if (active)       {__SET_VAR(data__->,X,,1);};
    if (desactivated) {__SET_VAR(data__->,X,,0);};

    if (active)       {__SET_VAR(data__->,B,,1);};
    if (desactivated) {__SET_VAR(data__->,B,,0);};

  }

  // PEZZO_BASSO action associations
  {
    char active = __GET_VAR(data__->PEZZO_BASSO.X);
    char activated = active && !data__->PEZZO_BASSO.prev_state;
    char desactivated = !active && data__->PEZZO_BASSO.prev_state;

    if (active)       {__SET_VAR(data__->,M,,1);};
    if (desactivated) {__SET_VAR(data__->,M,,0);};

  }

  // MEDIO_SENZA_PEZZO action associations
  {
    char active = __GET_VAR(data__->MEDIO_SENZA_PEZZO.X);
    char activated = active && !data__->MEDIO_SENZA_PEZZO.prev_state;
    char desactivated = !active && data__->MEDIO_SENZA_PEZZO.prev_state;

    if (active)       {__SET_VAR(data__->,M,,1);};
    if (desactivated) {__SET_VAR(data__->,M,,0);};

  }

  // BASSO_SENZA_PEZZO action associations
  {
    char active = __GET_VAR(data__->BASSO_SENZA_PEZZO.X);
    char activated = active && !data__->BASSO_SENZA_PEZZO.prev_state;
    char desactivated = !active && data__->BASSO_SENZA_PEZZO.prev_state;

    if (active)       {__SET_VAR(data__->,B,,1);};
    if (desactivated) {__SET_VAR(data__->,B,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_A].reset) {
    __SET_VAR(data__->,A,,0);
  }
  else if (data__->__action_list[__SFC_A].set) {
    __SET_VAR(data__->,A,,1);
  }
  if (data__->__action_list[__SFC_X].reset) {
    __SET_VAR(data__->,X,,0);
  }
  else if (data__->__action_list[__SFC_X].set) {
    __SET_VAR(data__->,X,,1);
  }
  if (data__->__action_list[__SFC_M].reset) {
    __SET_VAR(data__->,M,,0);
  }
  else if (data__->__action_list[__SFC_M].set) {
    __SET_VAR(data__->,M,,1);
  }
  if (data__->__action_list[__SFC_B].reset) {
    __SET_VAR(data__->,B,,0);
  }
  else if (data__->__action_list[__SFC_B].set) {
    __SET_VAR(data__->,B,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->DWN,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON1);
    __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->DWN,));
    __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON0);
    __SET_VAR(data__->TON3.,IN,,(__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DWN,))));
    __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON3);
    __SET_VAR(data__->TON2.,IN,,(__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DWN,))));
    __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON2);
    __SET_VAR(data__->TON4.,IN,,(__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DWN,))));
    __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON4);
    __SET_VAR(data__->TON5.,IN,,(__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DWN,))));
    __SET_VAR(data__->TON5.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON5);
  }



  goto __end;

__end:
  return;
} // SIM_TRAPANO_body__() 

// Steps undefinitions
#undef ALTO
#undef __SFC_ALTO
#undef TRA_A_E_M
#undef __SFC_TRA_A_E_M
#undef PEZZO_ALTO
#undef __SFC_PEZZO_ALTO
#undef MEDIO
#undef __SFC_MEDIO
#undef BASSO
#undef __SFC_BASSO
#undef PEZZO_BASSO
#undef __SFC_PEZZO_BASSO
#undef MEDIO_SENZA_PEZZO
#undef __SFC_MEDIO_SENZA_PEZZO
#undef BASSO_SENZA_PEZZO
#undef __SFC_BASSO_SENZA_PEZZO
#undef FERMO0
#undef __SFC_FERMO0
#undef RUOTA0
#undef __SFC_RUOTA0
#undef POMPA_FERMA0
#undef __SFC_POMPA_FERMA0
#undef POMPA_ACCESA0
#undef __SFC_POMPA_ACCESA0

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_A
#undef __SFC_X
#undef __SFC_M
#undef __SFC_B





void MAIN_TRAPANO_init__(MAIN_TRAPANO *data__, BOOL retain) {
  __INIT_VAR(data__->P,0,retain)
  __INIT_VAR(data__->A,0,retain)
  __INIT_VAR(data__->M,0,retain)
  __INIT_VAR(data__->B,0,retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->UP,0,retain)
  __INIT_VAR(data__->DWN,0,retain)
  __INIT_VAR(data__->ROT,0,retain)
  __INIT_VAR(data__->OIL,0,retain)
  UINT i;
  data__->__nb_steps = 8;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 4;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 9;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define F1 __step_list[0]
#define __SFC_F1 0
#define F2 __step_list[1]
#define __SFC_F2 1
#define F6 __step_list[2]
#define __SFC_F6 2
#define F7 __step_list[3]
#define __SFC_F7 3
#define F8 __step_list[4]
#define __SFC_F8 4
#define F3 __step_list[5]
#define __SFC_F3 5
#define F4 __step_list[6]
#define __SFC_F4 6
#define F5 __step_list[7]
#define __SFC_F5 7

// Actions definitions
#define __SFC_ROT 0
#define __SFC_DWN 1
#define __SFC_UP 2
#define __SFC_OIL 3

// Code part
void MAIN_TRAPANO_body__(MAIN_TRAPANO *data__) {
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->F1.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->Y,) && __GET_VAR(data__->P,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->Y,) && __GET_VAR(data__->P,)));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->F2.X)) {
    __SET_VAR(data__->,__transition_list[1],,((__GET_VAR(data__->M,) && !(__GET_VAR(data__->X,))) && __BOOL_LITERAL(TRUE)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,((__GET_VAR(data__->M,) && !(__GET_VAR(data__->X,))) && __BOOL_LITERAL(TRUE)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->F6.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->B,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->B,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->F7.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->A,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->A,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->F8.X)) {
    __SET_VAR(data__->,__transition_list[4],,!(__GET_VAR(data__->Y,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,!(__GET_VAR(data__->Y,)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->F2.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->X,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->F3.X)) {
    __SET_VAR(data__->,__transition_list[6],,(__GET_VAR(data__->M,) && __BOOL_LITERAL(TRUE)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,(__GET_VAR(data__->M,) && __BOOL_LITERAL(TRUE)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->F4.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->A,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->A,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->F5.X)) {
    __SET_VAR(data__->,__transition_list[8],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F5.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F5.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,F2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,F3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,F4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,F5.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F2.X,,1);
    data__->F2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F6.X,,1);
    data__->F6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F7.X,,1);
    data__->F7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F8.X,,1);
    data__->F8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F1.X,,1);
    data__->F1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,F3.X,,1);
    data__->F3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,F4.X,,1);
    data__->F4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,F5.X,,1);
    data__->F5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,F6.X,,1);
    data__->F6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // F2 action associations
  {
    char active = __GET_VAR(data__->F2.X);
    char activated = active && !data__->F2.prev_state;
    char desactivated = !active && data__->F2.prev_state;

    if (active)       {data__->__action_list[__SFC_ROT].set = 1;}

    if (active)       {__SET_VAR(data__->,DWN,,1);};
    if (desactivated) {__SET_VAR(data__->,DWN,,0);};

  }

  // F6 action associations
  {
    char active = __GET_VAR(data__->F6.X);
    char activated = active && !data__->F6.prev_state;
    char desactivated = !active && data__->F6.prev_state;

    if (active)       {__SET_VAR(data__->,DWN,,1);};
    if (desactivated) {__SET_VAR(data__->,DWN,,0);};

  }

  // F7 action associations
  {
    char active = __GET_VAR(data__->F7.X);
    char activated = active && !data__->F7.prev_state;
    char desactivated = !active && data__->F7.prev_state;

    if (active)       {__SET_VAR(data__->,UP,,1);};
    if (desactivated) {__SET_VAR(data__->,UP,,0);};

  }

  // F8 action associations
  {
    char active = __GET_VAR(data__->F8.X);
    char activated = active && !data__->F8.prev_state;
    char desactivated = !active && data__->F8.prev_state;

    if (active)       {data__->__action_list[__SFC_ROT].reset = 1;}

  }

  // F3 action associations
  {
    char active = __GET_VAR(data__->F3.X);
    char activated = active && !data__->F3.prev_state;
    char desactivated = !active && data__->F3.prev_state;

    if (active)       {__SET_VAR(data__->,DWN,,1);};
    if (desactivated) {__SET_VAR(data__->,DWN,,0);};

  }

  // F4 action associations
  {
    char active = __GET_VAR(data__->F4.X);
    char activated = active && !data__->F4.prev_state;
    char desactivated = !active && data__->F4.prev_state;

    if (active)       {__SET_VAR(data__->,UP,,1);};
    if (desactivated) {__SET_VAR(data__->,UP,,0);};

  }

  // F5 action associations
  {
    char active = __GET_VAR(data__->F5.X);
    char activated = active && !data__->F5.prev_state;
    char desactivated = !active && data__->F5.prev_state;

    if (active)       {__SET_VAR(data__->,OIL,,1);};
    if (desactivated) {__SET_VAR(data__->,OIL,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_ROT].reset) {
    __SET_VAR(data__->,ROT,,0);
  }
  else if (data__->__action_list[__SFC_ROT].set) {
    __SET_VAR(data__->,ROT,,1);
  }
  if (data__->__action_list[__SFC_DWN].reset) {
    __SET_VAR(data__->,DWN,,0);
  }
  else if (data__->__action_list[__SFC_DWN].set) {
    __SET_VAR(data__->,DWN,,1);
  }
  if (data__->__action_list[__SFC_UP].reset) {
    __SET_VAR(data__->,UP,,0);
  }
  else if (data__->__action_list[__SFC_UP].set) {
    __SET_VAR(data__->,UP,,1);
  }
  if (data__->__action_list[__SFC_OIL].reset) {
    __SET_VAR(data__->,OIL,,0);
  }
  else if (data__->__action_list[__SFC_OIL].set) {
    __SET_VAR(data__->,OIL,,1);
  }


  goto __end;

__end:
  return;
} // MAIN_TRAPANO_body__() 

// Steps undefinitions
#undef F1
#undef __SFC_F1
#undef F2
#undef __SFC_F2
#undef F6
#undef __SFC_F6
#undef F7
#undef __SFC_F7
#undef F8
#undef __SFC_F8
#undef F3
#undef __SFC_F3
#undef F4
#undef __SFC_F4
#undef F5
#undef __SFC_F5

// Actions undefinitions
#undef __SFC_ROT
#undef __SFC_DWN
#undef __SFC_UP
#undef __SFC_OIL





