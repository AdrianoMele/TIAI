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





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->F12X,0,retain)
  __INIT_VAR(data__->F1X,0,retain)
  __INIT_VAR(data__->F4X,0,retain)
  __INIT_VAR(data__->C1,0,retain)
  __INIT_VAR(data__->PED,0,retain)
  __INIT_VAR(data__->C2,0,retain)
  __INIT_VAR(data__->V1,0,retain)
  __INIT_VAR(data__->V2,0,retain)
  __INIT_VAR(data__->G1,0,retain)
  __INIT_VAR(data__->G2,0,retain)
  __INIT_VAR(data__->R1,0,retain)
  __INIT_VAR(data__->R2,0,retain)
  UINT i;
  data__->__nb_steps = 9;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[6].X,,1);
  data__->__nb_actions = 9;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 11;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define F1 __step_list[0]
#define __SFC_F1 0
#define F2 __step_list[1]
#define __SFC_F2 1
#define F4 __step_list[2]
#define __SFC_F4 2
#define F5 __step_list[3]
#define __SFC_F5 3
#define F6 __step_list[4]
#define __SFC_F6 4
#define F3 __step_list[5]
#define __SFC_F3 5
#define F10 __step_list[6]
#define __SFC_F10 6
#define F11 __step_list[7]
#define __SFC_F11 7
#define F12 __step_list[8]
#define __SFC_F12 8

// Actions definitions
#define __SFC_V1 0
#define __SFC_R2 1
#define __SFC_F1X 2
#define __SFC_G1 3
#define __SFC_F4X 4
#define __SFC_R1 5
#define __SFC_V2 6
#define __SFC_G2 7
#define __SFC_F12X 8

// Code part
void MAIN_body__(MAIN *data__) {
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
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->C1,) && !(__GET_VAR(data__->PED,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->C1,) && !(__GET_VAR(data__->PED,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->F2.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_VAR(data__->F12X,) && (__GET_VAR(data__->C2,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 400, 2, 0, 0, 0)))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_VAR(data__->F12X,) && (__GET_VAR(data__->C2,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 400, 2, 0, 0, 0)))));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->F4.X)) {
    __SET_VAR(data__->,__transition_list[2],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F4.T,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F4.T,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->F5.X)) {
    __SET_VAR(data__->,__transition_list[3],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F5.T,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F5.T,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->F6.X)) {
    __SET_VAR(data__->,__transition_list[4],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F6.T,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F6.T,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->F2.X)) {
    __SET_VAR(data__->,__transition_list[5],,((__GET_VAR(data__->PED,) && !(__GET_VAR(data__->C2,))) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 100, 2, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,((__GET_VAR(data__->PED,) && !(__GET_VAR(data__->C2,))) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 100, 2, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->F3.X)) {
    __SET_VAR(data__->,__transition_list[6],,(__GET_VAR(data__->F12X,) && (__GET_VAR(data__->C2,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F3.T,), __time_to_timespec(1, 300, 0, 0, 0, 0)))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,(__GET_VAR(data__->F12X,) && (__GET_VAR(data__->C2,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F3.T,), __time_to_timespec(1, 300, 0, 0, 0, 0)))));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->F1.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->PED,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->PED,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->F10.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->F1X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->F1X,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->F11.X)) {
    __SET_VAR(data__->,__transition_list[9],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F11.T,), __time_to_timespec(1, 0, 3, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F11.T,), __time_to_timespec(1, 0, 3, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->F12.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->F4X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->F4X,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,F2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,F3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,F1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,F10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,F11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,F12.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F2.X,,1);
    data__->F2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F4.X,,1);
    data__->F4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F5.X,,1);
    data__->F5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F6.X,,1);
    data__->F6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,F3.X,,1);
    data__->F3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,F11.X,,1);
    data__->F11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,F12.X,,1);
    data__->F12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,F10.X,,1);
    data__->F10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // F1 action associations
  {
    char active = __GET_VAR(data__->F1.X);
    char activated = active && !data__->F1.prev_state;
    char desactivated = !active && data__->F1.prev_state;

    if (active)       {__SET_VAR(data__->,V1,,1);};
    if (desactivated) {__SET_VAR(data__->,V1,,0);};

    if (active)       {__SET_VAR(data__->,R2,,1);};
    if (desactivated) {__SET_VAR(data__->,R2,,0);};

    if (active)       {__SET_VAR(data__->,F1X,,1);};
    if (desactivated) {__SET_VAR(data__->,F1X,,0);};

  }

  // F2 action associations
  {
    char active = __GET_VAR(data__->F2.X);
    char activated = active && !data__->F2.prev_state;
    char desactivated = !active && data__->F2.prev_state;

    if (active)       {__SET_VAR(data__->,V1,,1);};
    if (desactivated) {__SET_VAR(data__->,V1,,0);};

    if (active)       {__SET_VAR(data__->,R2,,1);};
    if (desactivated) {__SET_VAR(data__->,R2,,0);};

  }

  // F4 action associations
  {
    char active = __GET_VAR(data__->F4.X);
    char activated = active && !data__->F4.prev_state;
    char desactivated = !active && data__->F4.prev_state;

    if (active)       {__SET_VAR(data__->,G1,,1);};
    if (desactivated) {__SET_VAR(data__->,G1,,0);};

    if (active)       {__SET_VAR(data__->,R2,,1);};
    if (desactivated) {__SET_VAR(data__->,R2,,0);};

    if (active)       {__SET_VAR(data__->,F4X,,1);};
    if (desactivated) {__SET_VAR(data__->,F4X,,0);};

  }

  // F5 action associations
  {
    char active = __GET_VAR(data__->F5.X);
    char activated = active && !data__->F5.prev_state;
    char desactivated = !active && data__->F5.prev_state;

    if (active)       {__SET_VAR(data__->,R1,,1);};
    if (desactivated) {__SET_VAR(data__->,R1,,0);};

    if (active)       {__SET_VAR(data__->,V2,,1);};
    if (desactivated) {__SET_VAR(data__->,V2,,0);};

  }

  // F6 action associations
  {
    char active = __GET_VAR(data__->F6.X);
    char activated = active && !data__->F6.prev_state;
    char desactivated = !active && data__->F6.prev_state;

    if (active)       {__SET_VAR(data__->,R1,,1);};
    if (desactivated) {__SET_VAR(data__->,R1,,0);};

    if (active)       {__SET_VAR(data__->,G2,,1);};
    if (desactivated) {__SET_VAR(data__->,G2,,0);};

  }

  // F3 action associations
  {
    char active = __GET_VAR(data__->F3.X);
    char activated = active && !data__->F3.prev_state;
    char desactivated = !active && data__->F3.prev_state;

    if (active)       {__SET_VAR(data__->,V1,,1);};
    if (desactivated) {__SET_VAR(data__->,V1,,0);};

    if (active)       {__SET_VAR(data__->,R2,,1);};
    if (desactivated) {__SET_VAR(data__->,R2,,0);};

  }

  // F12 action associations
  {
    char active = __GET_VAR(data__->F12.X);
    char activated = active && !data__->F12.prev_state;
    char desactivated = !active && data__->F12.prev_state;

    if (active)       {__SET_VAR(data__->,F12X,,1);};
    if (desactivated) {__SET_VAR(data__->,F12X,,0);};

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
  if (data__->__action_list[__SFC_V1].reset) {
    __SET_VAR(data__->,V1,,0);
  }
  else if (data__->__action_list[__SFC_V1].set) {
    __SET_VAR(data__->,V1,,1);
  }
  if (data__->__action_list[__SFC_R2].reset) {
    __SET_VAR(data__->,R2,,0);
  }
  else if (data__->__action_list[__SFC_R2].set) {
    __SET_VAR(data__->,R2,,1);
  }
  if (data__->__action_list[__SFC_F1X].reset) {
    __SET_VAR(data__->,F1X,,0);
  }
  else if (data__->__action_list[__SFC_F1X].set) {
    __SET_VAR(data__->,F1X,,1);
  }
  if (data__->__action_list[__SFC_G1].reset) {
    __SET_VAR(data__->,G1,,0);
  }
  else if (data__->__action_list[__SFC_G1].set) {
    __SET_VAR(data__->,G1,,1);
  }
  if (data__->__action_list[__SFC_F4X].reset) {
    __SET_VAR(data__->,F4X,,0);
  }
  else if (data__->__action_list[__SFC_F4X].set) {
    __SET_VAR(data__->,F4X,,1);
  }
  if (data__->__action_list[__SFC_R1].reset) {
    __SET_VAR(data__->,R1,,0);
  }
  else if (data__->__action_list[__SFC_R1].set) {
    __SET_VAR(data__->,R1,,1);
  }
  if (data__->__action_list[__SFC_V2].reset) {
    __SET_VAR(data__->,V2,,0);
  }
  else if (data__->__action_list[__SFC_V2].set) {
    __SET_VAR(data__->,V2,,1);
  }
  if (data__->__action_list[__SFC_G2].reset) {
    __SET_VAR(data__->,G2,,0);
  }
  else if (data__->__action_list[__SFC_G2].set) {
    __SET_VAR(data__->,G2,,1);
  }
  if (data__->__action_list[__SFC_F12X].reset) {
    __SET_VAR(data__->,F12X,,0);
  }
  else if (data__->__action_list[__SFC_F12X].set) {
    __SET_VAR(data__->,F12X,,1);
  }


  goto __end;

__end:
  return;
} // MAIN_body__() 

// Steps undefinitions
#undef F1
#undef __SFC_F1
#undef F2
#undef __SFC_F2
#undef F4
#undef __SFC_F4
#undef F5
#undef __SFC_F5
#undef F6
#undef __SFC_F6
#undef F3
#undef __SFC_F3
#undef F10
#undef __SFC_F10
#undef F11
#undef __SFC_F11
#undef F12
#undef __SFC_F12

// Actions undefinitions
#undef __SFC_V1
#undef __SFC_R2
#undef __SFC_F1X
#undef __SFC_G1
#undef __SFC_F4X
#undef __SFC_R1
#undef __SFC_V2
#undef __SFC_G2
#undef __SFC_F12X





