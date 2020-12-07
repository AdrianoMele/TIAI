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





void TP_RESETOFF_TIMER_init__(TP_RESETOFF_TIMER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->PREV_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CURRENT_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TP_RESETOFF_TIMER_body__(TP_RESETOFF_TIMER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
__SET_VAR(data__->,CURRENT_TIME,,__CURRENT_TIME)
  #undef GetFbVar
  #undef SetFbVar
;
  if ((((__GET_VAR(data__->STATE,) == 0) && !(__GET_VAR(data__->PREV_IN,))) && __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->CURRENT_TIME,));
  } else if ((__GET_VAR(data__->STATE,) == 1)) {
    if (LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_add(__GET_VAR(data__->START_TIME,), __GET_VAR(data__->PT,)), __GET_VAR(data__->CURRENT_TIME,))) {
      __SET_VAR(data__->,STATE,,2);
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ET,,__GET_VAR(data__->PT,));
    } else {
      __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->CURRENT_TIME,), __GET_VAR(data__->START_TIME,)));
    };
  };
  if (((__GET_VAR(data__->STATE,) == 2) && !(__GET_VAR(data__->IN,)))) {
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STATE,,0);
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STATE,,0);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,PREV_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TP_RESETOFF_TIMER_body__() 





void CANCELLO_ESTERNO_init__(CANCELLO_ESTERNO *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,BUTTON,data__->BUTTON,retain)
  __INIT_VAR(data__->LIGHT,0,retain)
  __INIT_VAR(data__->MOT_A,0,retain)
  __INIT_EXTERNAL(BOOL,MOT_C,data__->MOT_C,retain)
  __INIT_EXTERNAL(BOOL,ALARM1,data__->ALARM1,retain)
  __INIT_EXTERNAL(BOOL,ALARM2,data__->ALARM2,retain)
  __INIT_EXTERNAL(BOOL,ALARM3,data__->ALARM3,retain)
  __INIT_EXTERNAL(BOOL,ALARM4,data__->ALARM4,retain)
  __INIT_EXTERNAL(BOOL,FOTOC1,data__->FOTOC1,retain)
  __INIT_EXTERNAL(BOOL,C_CHIUSO,data__->C_CHIUSO,retain)
  __INIT_EXTERNAL(BOOL,C_APERTO,data__->C_APERTO,retain)
  __INIT_VAR(data__->BUTTON1,0,retain)
  __INIT_VAR(data__->MOT_A1,0,retain)
  __INIT_EXTERNAL(BOOL,MOT_C1,data__->MOT_C1,retain)
  __INIT_EXTERNAL(BOOL,FOTOC2,data__->FOTOC2,retain)
  __INIT_EXTERNAL(BOOL,G_CHIUSO,data__->G_CHIUSO,retain)
  __INIT_VAR(data__->G_APERTO,0,retain)
  __INIT_EXTERNAL(BOOL,S_MOV1,data__->S_MOV1,retain)
  __INIT_VAR(data__->BUTTON2,0,retain)
  __INIT_EXTERNAL(BOOL,C_PEDONALE,data__->C_PEDONALE,retain)
  UINT i;
  data__->__nb_steps = 28;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[6].X,,1);
  __SET_VAR(data__->,__step_list[13].X,,1);
  __SET_VAR(data__->,__step_list[19].X,,1);
  __SET_VAR(data__->,__step_list[26].X,,1);
  data__->__nb_actions = 13;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 34;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define F0 __step_list[0]
#define __SFC_F0 0
#define F1 __step_list[1]
#define __SFC_F1 1
#define F2 __step_list[2]
#define __SFC_F2 2
#define F3 __step_list[3]
#define __SFC_F3 3
#define F4 __step_list[4]
#define __SFC_F4 4
#define F5 __step_list[5]
#define __SFC_F5 5
#define S0 __step_list[6]
#define __SFC_S0 6
#define S0B __step_list[7]
#define __SFC_S0B 7
#define S1 __step_list[8]
#define __SFC_S1 8
#define S2 __step_list[9]
#define __SFC_S2 9
#define S4 __step_list[10]
#define __SFC_S4 10
#define S5 __step_list[11]
#define __SFC_S5 11
#define S3 __step_list[12]
#define __SFC_S3 12
#define F6 __step_list[13]
#define __SFC_F6 13
#define F7 __step_list[14]
#define __SFC_F7 14
#define F8 __step_list[15]
#define __SFC_F8 15
#define F9 __step_list[16]
#define __SFC_F9 16
#define F10 __step_list[17]
#define __SFC_F10 17
#define F11 __step_list[18]
#define __SFC_F11 18
#define S11 __step_list[19]
#define __SFC_S11 19
#define S0B0 __step_list[20]
#define __SFC_S0B0 20
#define S6 __step_list[21]
#define __SFC_S6 21
#define S7 __step_list[22]
#define __SFC_S7 22
#define S9 __step_list[23]
#define __SFC_S9 23
#define S10 __step_list[24]
#define __SFC_S10 24
#define S8 __step_list[25]
#define __SFC_S8 25
#define F12 __step_list[26]
#define __SFC_F12 26
#define F13 __step_list[27]
#define __SFC_F13 27

// Actions definitions
#define __SFC_MOT_A 0
#define __SFC_BUTTON 1
#define __SFC_LIGHT 2
#define __SFC_MOT_C 3
#define __SFC_C_CHIUSO 4
#define __SFC_C_APERTO 5
#define __SFC_MOT_A1 6
#define __SFC_BUTTON1 7
#define __SFC_MOT_C1 8
#define __SFC_G_CHIUSO 9
#define __SFC_G_APERTO 10
#define __SFC_C_PEDONALE 11
#define __SFC_BUTTON2 12

// Code part
void CANCELLO_ESTERNO_body__(CANCELLO_ESTERNO *data__) {
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
  if (__GET_VAR(data__->F0.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_EXTERNAL(data__->BUTTON,) && !(__GET_EXTERNAL(data__->ALARM1,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_EXTERNAL(data__->BUTTON,) && !(__GET_EXTERNAL(data__->ALARM1,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->F1.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_EXTERNAL(data__->BUTTON,) || __GET_EXTERNAL(data__->C_APERTO,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_EXTERNAL(data__->BUTTON,) || __GET_EXTERNAL(data__->C_APERTO,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->F2.X)) {
    __SET_VAR(data__->,__transition_list[2],,(__GET_EXTERNAL(data__->BUTTON,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 0, 5, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,(__GET_EXTERNAL(data__->BUTTON,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 0, 5, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->F3.X)) {
    __SET_VAR(data__->,__transition_list[3],,(__GET_EXTERNAL(data__->BUTTON,) || __GET_EXTERNAL(data__->FOTOC1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,(__GET_EXTERNAL(data__->BUTTON,) || __GET_EXTERNAL(data__->FOTOC1,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->F4.X)) {
    __SET_VAR(data__->,__transition_list[4],,(__GET_EXTERNAL(data__->BUTTON,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 0, 5, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,(__GET_EXTERNAL(data__->BUTTON,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F2.T,), __time_to_timespec(1, 0, 5, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->F3.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_EXTERNAL(data__->C_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_EXTERNAL(data__->C_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->F5.X)) {
    __SET_VAR(data__->,__transition_list[6],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->S0.X)) {
    __SET_VAR(data__->,__transition_list[7],,(__GET_EXTERNAL(data__->BUTTON,) && !(__GET_EXTERNAL(data__->ALARM1,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,(__GET_EXTERNAL(data__->BUTTON,) && !(__GET_EXTERNAL(data__->ALARM1,))));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->S0B.X)) {
    __SET_VAR(data__->,__transition_list[8],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F1.T,), __time_to_timespec(1, 0, 20, 0, 0, 0)) && __GET_VAR(data__->F1.X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F1.T,), __time_to_timespec(1, 0, 20, 0, 0, 0)) && __GET_VAR(data__->F1.X,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->S1.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->F3.X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->F3.X,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->S2.X)) {
    __SET_VAR(data__->,__transition_list[10],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F3.T,), __time_to_timespec(1, 0, 20, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F3.T,), __time_to_timespec(1, 0, 20, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->S4.X)) {
    __SET_VAR(data__->,__transition_list[11],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->S2.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->F4.X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->F4.X,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->S5.X)) {
    __SET_VAR(data__->,__transition_list[13],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F1.T,), __GET_VAR(data__->F3.T,)) && __GET_VAR(data__->F1.X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F1.T,), __GET_VAR(data__->F3.T,)) && __GET_VAR(data__->F1.X,)));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->S0B.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->F2.X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->F2.X,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->S3.X)) {
    __SET_VAR(data__->,__transition_list[15],,(LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F1.T,), __GET_VAR(data__->F3.T,)) && __GET_VAR(data__->F3.X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,(LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F1.T,), __GET_VAR(data__->F3.T,)) && __GET_VAR(data__->F3.X,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->F6.X)) {
    __SET_VAR(data__->,__transition_list[16],,(__GET_VAR(data__->BUTTON1,) && !(__GET_EXTERNAL(data__->ALARM2,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,(__GET_VAR(data__->BUTTON1,) && !(__GET_EXTERNAL(data__->ALARM2,))));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->F7.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->G_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->G_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->F8.X)) {
    __SET_VAR(data__->,__transition_list[18],,((!(__GET_EXTERNAL(data__->S_MOV1,)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F8.T,), __time_to_timespec(1, 0, 15, 0, 0, 0))) || __GET_VAR(data__->BUTTON1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,((!(__GET_EXTERNAL(data__->S_MOV1,)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F8.T,), __time_to_timespec(1, 0, 15, 0, 0, 0))) || __GET_VAR(data__->BUTTON1,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->F9.X)) {
    __SET_VAR(data__->,__transition_list[19],,(__GET_VAR(data__->BUTTON1,) || __GET_EXTERNAL(data__->FOTOC2,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,(__GET_VAR(data__->BUTTON1,) || __GET_EXTERNAL(data__->FOTOC2,)));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->F10.X)) {
    __SET_VAR(data__->,__transition_list[20],,(__GET_VAR(data__->BUTTON1,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F8.T,), __time_to_timespec(1, 0, 5, 0, 0, 0))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,(__GET_VAR(data__->BUTTON1,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F8.T,), __time_to_timespec(1, 0, 5, 0, 0, 0))));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->F9.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_EXTERNAL(data__->G_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_EXTERNAL(data__->G_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->F11.X)) {
    __SET_VAR(data__->,__transition_list[22],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->S11.X)) {
    __SET_VAR(data__->,__transition_list[23],,((__GET_VAR(data__->BUTTON1,) || (!(__GET_VAR(data__->G_APERTO,)) && __GET_EXTERNAL(data__->C_APERTO,))) && !(__GET_EXTERNAL(data__->ALARM2,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,((__GET_VAR(data__->BUTTON1,) || (!(__GET_VAR(data__->G_APERTO,)) && __GET_EXTERNAL(data__->C_APERTO,))) && !(__GET_EXTERNAL(data__->ALARM2,))));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->S0B0.X)) {
    __SET_VAR(data__->,__transition_list[24],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F7.T,), __time_to_timespec(1, 0, 15, 0, 0, 0)) && __GET_VAR(data__->F7.X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F7.T,), __time_to_timespec(1, 0, 15, 0, 0, 0)) && __GET_VAR(data__->F7.X,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->S6.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->F9.X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->F9.X,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->S7.X)) {
    __SET_VAR(data__->,__transition_list[26],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F9.T,), __time_to_timespec(1, 0, 15, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F9.T,), __time_to_timespec(1, 0, 15, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->S9.X)) {
    __SET_VAR(data__->,__transition_list[27],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->S7.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->F10.X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->F10.X,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->S10.X)) {
    __SET_VAR(data__->,__transition_list[29],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F7.T,), __GET_VAR(data__->F9.T,)) && __GET_VAR(data__->F7.X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,(GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F7.T,), __GET_VAR(data__->F9.T,)) && __GET_VAR(data__->F7.X,)));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->S0B0.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_VAR(data__->F8.X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->F8.X,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->S8.X)) {
    __SET_VAR(data__->,__transition_list[31],,(LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F7.T,), __GET_VAR(data__->F9.T,)) && __GET_VAR(data__->F9.X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,(LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F7.T,), __GET_VAR(data__->F9.T,)) && __GET_VAR(data__->F9.X,)));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->F12.X)) {
    __SET_VAR(data__->,__transition_list[32],,(__GET_VAR(data__->BUTTON2,) && !(__GET_EXTERNAL(data__->ALARM1,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,(__GET_VAR(data__->BUTTON2,) && !(__GET_EXTERNAL(data__->ALARM1,))));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->F13.X)) {
    __SET_VAR(data__->,__transition_list[33],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,F3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,F5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,S0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,S0B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,S1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,S2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,S4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,S2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,S5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,S0B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,S3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,F6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,F7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,F8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,F9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,F10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,F9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,F11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,S11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,S0B0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,S6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,S7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,S9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,S7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,S10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,S0B0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,S8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,F12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,F13.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F1.X,,1);
    data__->F1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F2.X,,1);
    data__->F2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F3.X,,1);
    data__->F3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F4.X,,1);
    data__->F4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F1.X,,1);
    data__->F1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,F5.X,,1);
    data__->F5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,F0.X,,1);
    data__->F0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,S0B.X,,1);
    data__->S0B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,S1.X,,1);
    data__->S1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,S2.X,,1);
    data__->S2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,S4.X,,1);
    data__->S4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,S0.X,,1);
    data__->S0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,S5.X,,1);
    data__->S5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,S1.X,,1);
    data__->S1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,S3.X,,1);
    data__->S3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,S4.X,,1);
    data__->S4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,F7.X,,1);
    data__->F7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,F8.X,,1);
    data__->F8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,F9.X,,1);
    data__->F9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,F10.X,,1);
    data__->F10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,F7.X,,1);
    data__->F7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,F11.X,,1);
    data__->F11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,F6.X,,1);
    data__->F6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,S0B0.X,,1);
    data__->S0B0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,S6.X,,1);
    data__->S6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,S7.X,,1);
    data__->S7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,S9.X,,1);
    data__->S9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,S11.X,,1);
    data__->S11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,S10.X,,1);
    data__->S10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,S6.X,,1);
    data__->S6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,S8.X,,1);
    data__->S8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,S9.X,,1);
    data__->S9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,F13.X,,1);
    data__->F13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,F12.X,,1);
    data__->F12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // F1 action associations
  {
    char active = __GET_VAR(data__->F1.X);
    char activated = active && !data__->F1.prev_state;
    char desactivated = !active && data__->F1.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_A].set = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LIGHT].set = 1;}

  }

  // F2 action associations
  {
    char active = __GET_VAR(data__->F2.X);
    char activated = active && !data__->F2.prev_state;
    char desactivated = !active && data__->F2.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_A].reset = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LIGHT].reset = 1;}

  }

  // F3 action associations
  {
    char active = __GET_VAR(data__->F3.X);
    char activated = active && !data__->F3.prev_state;
    char desactivated = !active && data__->F3.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_C].set = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LIGHT].set = 1;}

  }

  // F4 action associations
  {
    char active = __GET_VAR(data__->F4.X);
    char activated = active && !data__->F4.prev_state;
    char desactivated = !active && data__->F4.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_C].reset = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LIGHT].reset = 1;}

  }

  // F5 action associations
  {
    char active = __GET_VAR(data__->F5.X);
    char activated = active && !data__->F5.prev_state;
    char desactivated = !active && data__->F5.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_C].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LIGHT].reset = 1;}

  }

  // S0B action associations
  {
    char active = __GET_VAR(data__->S0B.X);
    char activated = active && !data__->S0B.prev_state;
    char desactivated = !active && data__->S0B.prev_state;

    if (active)       {data__->__action_list[__SFC_C_CHIUSO].reset = 1;}

  }

  // S1 action associations
  {
    char active = __GET_VAR(data__->S1.X);
    char activated = active && !data__->S1.prev_state;
    char desactivated = !active && data__->S1.prev_state;

    if (active)       {data__->__action_list[__SFC_C_APERTO].set = 1;}

  }

  // S2 action associations
  {
    char active = __GET_VAR(data__->S2.X);
    char activated = active && !data__->S2.prev_state;
    char desactivated = !active && data__->S2.prev_state;

    if (active)       {data__->__action_list[__SFC_C_APERTO].reset = 1;}

  }

  // S4 action associations
  {
    char active = __GET_VAR(data__->S4.X);
    char activated = active && !data__->S4.prev_state;
    char desactivated = !active && data__->S4.prev_state;

    if (active)       {data__->__action_list[__SFC_C_CHIUSO].set = 1;}

  }

  // S3 action associations
  {
    char active = __GET_VAR(data__->S3.X);
    char activated = active && !data__->S3.prev_state;
    char desactivated = !active && data__->S3.prev_state;

    if (active)       {data__->__action_list[__SFC_C_APERTO].reset = 1;}

  }

  // F7 action associations
  {
    char active = __GET_VAR(data__->F7.X);
    char activated = active && !data__->F7.prev_state;
    char desactivated = !active && data__->F7.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_A1].set = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON1].reset = 1;}

  }

  // F8 action associations
  {
    char active = __GET_VAR(data__->F8.X);
    char activated = active && !data__->F8.prev_state;
    char desactivated = !active && data__->F8.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_A1].reset = 1;}

  }

  // F9 action associations
  {
    char active = __GET_VAR(data__->F9.X);
    char activated = active && !data__->F9.prev_state;
    char desactivated = !active && data__->F9.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_C1].set = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON1].reset = 1;}

  }

  // F10 action associations
  {
    char active = __GET_VAR(data__->F10.X);
    char activated = active && !data__->F10.prev_state;
    char desactivated = !active && data__->F10.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_C1].reset = 1;}

    if (active)       {data__->__action_list[__SFC_BUTTON1].reset = 1;}

  }

  // F11 action associations
  {
    char active = __GET_VAR(data__->F11.X);
    char activated = active && !data__->F11.prev_state;
    char desactivated = !active && data__->F11.prev_state;

    if (active)       {data__->__action_list[__SFC_MOT_C1].reset = 1;}

  }

  // S0B0 action associations
  {
    char active = __GET_VAR(data__->S0B0.X);
    char activated = active && !data__->S0B0.prev_state;
    char desactivated = !active && data__->S0B0.prev_state;

    if (active)       {data__->__action_list[__SFC_G_CHIUSO].reset = 1;}

  }

  // S6 action associations
  {
    char active = __GET_VAR(data__->S6.X);
    char activated = active && !data__->S6.prev_state;
    char desactivated = !active && data__->S6.prev_state;

    if (active)       {data__->__action_list[__SFC_G_APERTO].set = 1;}

  }

  // S7 action associations
  {
    char active = __GET_VAR(data__->S7.X);
    char activated = active && !data__->S7.prev_state;
    char desactivated = !active && data__->S7.prev_state;

    if (active)       {data__->__action_list[__SFC_G_APERTO].reset = 1;}

  }

  // S9 action associations
  {
    char active = __GET_VAR(data__->S9.X);
    char activated = active && !data__->S9.prev_state;
    char desactivated = !active && data__->S9.prev_state;

    if (active)       {data__->__action_list[__SFC_G_CHIUSO].set = 1;}

  }

  // S8 action associations
  {
    char active = __GET_VAR(data__->S8.X);
    char activated = active && !data__->S8.prev_state;
    char desactivated = !active && data__->S8.prev_state;

    if (active)       {data__->__action_list[__SFC_G_APERTO].reset = 1;}

  }

  // F13 action associations
  {
    char active = __GET_VAR(data__->F13.X);
    char activated = active && !data__->F13.prev_state;
    char desactivated = !active && data__->F13.prev_state;

    if (activated) {
      data__->__action_list[__SFC_C_PEDONALE].set = 1;
      data__->__action_list[__SFC_C_PEDONALE].reset_remaining_time = __time_to_timespec(1, 0, 10, 0, 0, 0);
    }

    if (active)       {data__->__action_list[__SFC_BUTTON2].reset = 1;}

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
  if (data__->__action_list[__SFC_MOT_A].reset) {
    __SET_VAR(data__->,MOT_A,,0);
  }
  else if (data__->__action_list[__SFC_MOT_A].set) {
    __SET_VAR(data__->,MOT_A,,1);
  }
  if (data__->__action_list[__SFC_BUTTON].reset) {
    __SET_EXTERNAL(data__->,BUTTON,,0);
  }
  else if (data__->__action_list[__SFC_BUTTON].set) {
    __SET_EXTERNAL(data__->,BUTTON,,1);
  }
  if (data__->__action_list[__SFC_LIGHT].reset) {
    __SET_VAR(data__->,LIGHT,,0);
  }
  else if (data__->__action_list[__SFC_LIGHT].set) {
    __SET_VAR(data__->,LIGHT,,1);
  }
  if (data__->__action_list[__SFC_MOT_C].reset) {
    __SET_EXTERNAL(data__->,MOT_C,,0);
  }
  else if (data__->__action_list[__SFC_MOT_C].set) {
    __SET_EXTERNAL(data__->,MOT_C,,1);
  }
  if (data__->__action_list[__SFC_C_CHIUSO].reset) {
    __SET_EXTERNAL(data__->,C_CHIUSO,,0);
  }
  else if (data__->__action_list[__SFC_C_CHIUSO].set) {
    __SET_EXTERNAL(data__->,C_CHIUSO,,1);
  }
  if (data__->__action_list[__SFC_C_APERTO].reset) {
    __SET_EXTERNAL(data__->,C_APERTO,,0);
  }
  else if (data__->__action_list[__SFC_C_APERTO].set) {
    __SET_EXTERNAL(data__->,C_APERTO,,1);
  }
  if (data__->__action_list[__SFC_MOT_A1].reset) {
    __SET_VAR(data__->,MOT_A1,,0);
  }
  else if (data__->__action_list[__SFC_MOT_A1].set) {
    __SET_VAR(data__->,MOT_A1,,1);
  }
  if (data__->__action_list[__SFC_BUTTON1].reset) {
    __SET_VAR(data__->,BUTTON1,,0);
  }
  else if (data__->__action_list[__SFC_BUTTON1].set) {
    __SET_VAR(data__->,BUTTON1,,1);
  }
  if (data__->__action_list[__SFC_MOT_C1].reset) {
    __SET_EXTERNAL(data__->,MOT_C1,,0);
  }
  else if (data__->__action_list[__SFC_MOT_C1].set) {
    __SET_EXTERNAL(data__->,MOT_C1,,1);
  }
  if (data__->__action_list[__SFC_G_CHIUSO].reset) {
    __SET_EXTERNAL(data__->,G_CHIUSO,,0);
  }
  else if (data__->__action_list[__SFC_G_CHIUSO].set) {
    __SET_EXTERNAL(data__->,G_CHIUSO,,1);
  }
  if (data__->__action_list[__SFC_G_APERTO].reset) {
    __SET_VAR(data__->,G_APERTO,,0);
  }
  else if (data__->__action_list[__SFC_G_APERTO].set) {
    __SET_VAR(data__->,G_APERTO,,1);
  }
  if (data__->__action_list[__SFC_C_PEDONALE].reset) {
    __SET_EXTERNAL(data__->,C_PEDONALE,,0);
  }
  else if (data__->__action_list[__SFC_C_PEDONALE].set) {
    __SET_EXTERNAL(data__->,C_PEDONALE,,1);
  }
  if (data__->__action_list[__SFC_BUTTON2].reset) {
    __SET_VAR(data__->,BUTTON2,,0);
  }
  else if (data__->__action_list[__SFC_BUTTON2].set) {
    __SET_VAR(data__->,BUTTON2,,1);
  }


  goto __end;

__end:
  return;
} // CANCELLO_ESTERNO_body__() 

// Steps undefinitions
#undef F0
#undef __SFC_F0
#undef F1
#undef __SFC_F1
#undef F2
#undef __SFC_F2
#undef F3
#undef __SFC_F3
#undef F4
#undef __SFC_F4
#undef F5
#undef __SFC_F5
#undef S0
#undef __SFC_S0
#undef S0B
#undef __SFC_S0B
#undef S1
#undef __SFC_S1
#undef S2
#undef __SFC_S2
#undef S4
#undef __SFC_S4
#undef S5
#undef __SFC_S5
#undef S3
#undef __SFC_S3
#undef F6
#undef __SFC_F6
#undef F7
#undef __SFC_F7
#undef F8
#undef __SFC_F8
#undef F9
#undef __SFC_F9
#undef F10
#undef __SFC_F10
#undef F11
#undef __SFC_F11
#undef S11
#undef __SFC_S11
#undef S0B0
#undef __SFC_S0B0
#undef S6
#undef __SFC_S6
#undef S7
#undef __SFC_S7
#undef S9
#undef __SFC_S9
#undef S10
#undef __SFC_S10
#undef S8
#undef __SFC_S8
#undef F12
#undef __SFC_F12
#undef F13
#undef __SFC_F13

// Actions undefinitions
#undef __SFC_MOT_A
#undef __SFC_BUTTON
#undef __SFC_LIGHT
#undef __SFC_MOT_C
#undef __SFC_C_CHIUSO
#undef __SFC_C_APERTO
#undef __SFC_MOT_A1
#undef __SFC_BUTTON1
#undef __SFC_MOT_C1
#undef __SFC_G_CHIUSO
#undef __SFC_G_APERTO
#undef __SFC_C_PEDONALE
#undef __SFC_BUTTON2





void TP_RESET_TIMER_init__(TP_RESET_TIMER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->PREV_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CURRENT_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TP_RESET_TIMER_body__(TP_RESET_TIMER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
__SET_VAR(data__->,CURRENT_TIME,,__CURRENT_TIME)
  #undef GetFbVar
  #undef SetFbVar
;
  if ((((__GET_VAR(data__->STATE,) == 0) && !(__GET_VAR(data__->PREV_IN,))) && __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->CURRENT_TIME,));
  } else if ((__GET_VAR(data__->STATE,) == 1)) {
    if (LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_add(__GET_VAR(data__->START_TIME,), __GET_VAR(data__->PT,)), __GET_VAR(data__->CURRENT_TIME,))) {
      __SET_VAR(data__->,STATE,,2);
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ET,,__GET_VAR(data__->PT,));
    } else {
      __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->CURRENT_TIME,), __GET_VAR(data__->START_TIME,)));
    };
  };
  if (((__GET_VAR(data__->STATE,) == 2) && !(__GET_VAR(data__->IN,)))) {
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STATE,,0);
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->CURRENT_TIME,));
  };
  __SET_VAR(data__->,PREV_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TP_RESET_TIMER_body__() 





void ILLUMINAZIONE_init__(ILLUMINAZIONE *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,C_CHIUSO,data__->C_CHIUSO,retain)
  __INIT_EXTERNAL(BOOL,BUTTON,data__->BUTTON,retain)
  __INIT_EXTERNAL(BOOL,C_PEDONALE,data__->C_PEDONALE,retain)
  __INIT_EXTERNAL(BOOL,G_CHIUSO,data__->G_CHIUSO,retain)
  __INIT_EXTERNAL(BOOL,LIGHT1,data__->LIGHT1,retain)
  __INIT_EXTERNAL(BOOL,LIGHT2,data__->LIGHT2,retain)
  __INIT_EXTERNAL(BOOL,LIGHT3,data__->LIGHT3,retain)
  __INIT_EXTERNAL(BOOL,LIGHT4,data__->LIGHT4,retain)
  __INIT_VAR(data__->S_CREPUSCOLARE,0,retain)
  __INIT_VAR(data__->B_LIGHT1,0,retain)
  __INIT_VAR(data__->B_LIGHT2,0,retain)
  __INIT_VAR(data__->B_LIGHT3,0,retain)
  __INIT_VAR(data__->B_LIGHT4,0,retain)
  __INIT_VAR(data__->B_TIMER,0,retain)
  TP_init__(&data__->TP0,retain);
  __INIT_VAR(data__->TEMPO_ACCENSIONE,__tod_to_timespec(0, 30, 12),retain)
  __INIT_VAR(data__->DATA_INIZIALE,__dt_to_timespec(45, 29, 12, 11, 7, 2020),retain)
  __INIT_VAR(data__->TEMPO_CORRENTE,__tod_to_timespec(0, 0, 0),retain)
  RTC_init__(&data__->RTC0,retain);
  __INIT_EXTERNAL(BOOL,S_MOV1,data__->S_MOV1,retain)
  TP_RESET_TIMER_init__(&data__->TP_WITH_RESET0,retain);
  TP_RESETOFF_TIMER_init__(&data__->TP_RESETOFF_TIMER0,retain);
  TP_RESETOFF_TIMER_init__(&data__->TP_RESETOFF_TIMER1,retain);
  TP_init__(&data__->TP1,retain);
  __INIT_VAR(data__->GIORNODOPO,0,retain)
  __INIT_VAR(data__->DATE_AND_TIME_TO_TIME_OF_DAY35_OUT,__tod_to_timespec(0, 0, 0),retain)
  __INIT_VAR(data__->GT37_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void ILLUMINAZIONE_body__(ILLUMINAZIONE *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TP0.,IN,,(__GET_VAR(data__->S_CREPUSCOLARE,) && !(__GET_EXTERNAL(data__->C_CHIUSO,))));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 25, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_EXTERNAL(data__->,LIGHT1,,(__GET_VAR(data__->B_LIGHT1,) || __GET_VAR(data__->TP0.Q,)));
  __SET_VAR(data__->TP_WITH_RESET0.,IN,,(__GET_VAR(data__->S_CREPUSCOLARE,) && !(__GET_EXTERNAL(data__->G_CHIUSO,))));
  __SET_VAR(data__->TP_WITH_RESET0.,PT,,__time_to_timespec(1, 0, 30, 0, 0, 0));
  __SET_VAR(data__->TP_WITH_RESET0.,RESET,,(__GET_EXTERNAL(data__->S_MOV1,) && __GET_VAR(data__->S_CREPUSCOLARE,)));
  TP_RESET_TIMER_body__(&data__->TP_WITH_RESET0);
  __SET_EXTERNAL(data__->,LIGHT2,,(__GET_VAR(data__->B_LIGHT2,) || __GET_VAR(data__->TP_WITH_RESET0.Q,)));
  __SET_VAR(data__->RTC0.,IN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->RTC0.,PDT,,__GET_VAR(data__->DATA_INIZIALE,));
  RTC_body__(&data__->RTC0);
  __SET_VAR(data__->,DATE_AND_TIME_TO_TIME_OF_DAY35_OUT,,DATE_AND_TIME_TO_TIME_OF_DAY(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->RTC0.CDT,)));
  __SET_VAR(data__->,TEMPO_CORRENTE,,__GET_VAR(data__->DATE_AND_TIME_TO_TIME_OF_DAY35_OUT,));
  __SET_VAR(data__->,GT37_OUT,,GT__BOOL__TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TOD)__GET_VAR(data__->TEMPO_CORRENTE,),
    (TOD)__GET_VAR(data__->TEMPO_ACCENSIONE,)));
  __SET_VAR(data__->TP_RESETOFF_TIMER0.,IN,,(!(__GET_VAR(data__->GIORNODOPO,)) && __GET_VAR(data__->GT37_OUT,)));
  __SET_VAR(data__->TP_RESETOFF_TIMER0.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
  __SET_VAR(data__->TP_RESETOFF_TIMER0.,RESET,,__GET_VAR(data__->B_TIMER,));
  TP_RESETOFF_TIMER_body__(&data__->TP_RESETOFF_TIMER0);
  __SET_VAR(data__->TP1.,IN,,__GET_EXTERNAL(data__->C_PEDONALE,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 0, 25, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_EXTERNAL(data__->,LIGHT3,,((__GET_VAR(data__->S_CREPUSCOLARE,) && (__GET_VAR(data__->TP1.Q,) || __GET_VAR(data__->TP_RESETOFF_TIMER0.Q,))) || __GET_VAR(data__->B_LIGHT3,)));
  __SET_VAR(data__->TP_RESETOFF_TIMER1.,IN,,(!(__GET_VAR(data__->GIORNODOPO,)) && __GET_VAR(data__->GT37_OUT,)));
  __SET_VAR(data__->TP_RESETOFF_TIMER1.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
  __SET_VAR(data__->TP_RESETOFF_TIMER1.,RESET,,__GET_VAR(data__->B_TIMER,));
  TP_RESETOFF_TIMER_body__(&data__->TP_RESETOFF_TIMER1);
  __SET_EXTERNAL(data__->,LIGHT4,,((__GET_VAR(data__->S_CREPUSCOLARE,) && __GET_VAR(data__->TP_RESETOFF_TIMER1.Q,)) || __GET_VAR(data__->B_LIGHT4,)));

  goto __end;

__end:
  return;
} // ILLUMINAZIONE_body__() 





void ANTIFURTO_init__(ANTIFURTO *data__, BOOL retain) {
  __INIT_VAR(data__->ANTI_THEFT1,0,retain)
  __INIT_VAR(data__->ANTI_THEFT2,0,retain)
  __INIT_VAR(data__->ANTI_THEFT3,0,retain)
  __INIT_VAR(data__->ANTI_THEFT4,0,retain)
  __INIT_VAR(data__->T_PROX1,0,retain)
  __INIT_EXTERNAL(BOOL,FOTOC1,data__->FOTOC1,retain)
  __INIT_EXTERNAL(BOOL,FOTOC2,data__->FOTOC2,retain)
  __INIT_EXTERNAL(BOOL,S_MOV1,data__->S_MOV1,retain)
  __INIT_VAR(data__->S_MOV2,0,retain)
  __INIT_VAR(data__->S_FUMO,0,retain)
  __INIT_EXTERNAL(BOOL,ALARM1,data__->ALARM1,retain)
  __INIT_EXTERNAL(BOOL,ALARM2,data__->ALARM2,retain)
  __INIT_EXTERNAL(BOOL,ALARM3,data__->ALARM3,retain)
  __INIT_EXTERNAL(BOOL,ALARM4,data__->ALARM4,retain)
  __INIT_VAR(data__->L_PORTA,0,retain)
  __INIT_VAR(data__->L_FINESTRE,0,retain)
  __INIT_EXTERNAL(BOOL,C_CHIUSO,data__->C_CHIUSO,retain)
  __INIT_EXTERNAL(BOOL,G_CHIUSO,data__->G_CHIUSO,retain)
  __INIT_EXTERNAL(BOOL,C_PEDONALE,data__->C_PEDONALE,retain)
  __INIT_VAR(data__->FARO1,0,retain)
  __INIT_VAR(data__->FARO2,0,retain)
  __INIT_VAR(data__->FARO3,0,retain)
  __INIT_VAR(data__->FARO4,0,retain)
  __INIT_VAR(data__->LIGHT5,0,retain)
  __INIT_VAR(data__->SPEAKER1,0,retain)
  __INIT_VAR(data__->SPRINKLER,0,retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  TON_init__(&data__->TON1,retain);
  TOF_init__(&data__->TOF1,retain);
  TON_init__(&data__->TON2,retain);
  TOF_init__(&data__->TOF2,retain);
  TON_init__(&data__->TON3,retain);
  TOF_init__(&data__->TOF3,retain);
  TON_init__(&data__->TON4,retain);
  TOF_init__(&data__->TOF4,retain);
}

// Code part
void ANTIFURTO_body__(ANTIFURTO *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,SPRINKLER,,(!(__GET_EXTERNAL(data__->ALARM4,)) && __GET_VAR(data__->S_FUMO,)));
  __SET_VAR(data__->,SPEAKER1,,(__BOOL_LITERAL(TRUE) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_VAR(data__->TON4.,IN,,((!(__GET_VAR(data__->LIGHT5,)) && !(__GET_EXTERNAL(data__->ALARM4,))) && __GET_VAR(data__->S_FUMO,)));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON4);
  __SET_VAR(data__->TOF4.,IN,,__GET_VAR(data__->TON4.Q,));
  __SET_VAR(data__->TOF4.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF4);
  __SET_VAR(data__->,LIGHT5,,__GET_VAR(data__->TOF4.Q,));
  __SET_VAR(data__->,L_PORTA,,(__BOOL_LITERAL(TRUE) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_VAR(data__->,L_FINESTRE,,(__BOOL_LITERAL(TRUE) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_EXTERNAL(data__->,ALARM1,,(__GET_VAR(data__->ANTI_THEFT1,) || __GET_VAR(data__->ANTI_THEFT4,)));
  __SET_VAR(data__->TON0.,IN,,((!(__GET_VAR(data__->FARO1,)) && __BOOL_LITERAL(TRUE)) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,FARO1,,__GET_VAR(data__->TOF0.Q,));
  __SET_EXTERNAL(data__->,ALARM2,,(__GET_VAR(data__->ANTI_THEFT2,) || __GET_VAR(data__->ANTI_THEFT4,)));
  __SET_EXTERNAL(data__->,ALARM3,,(__GET_VAR(data__->ANTI_THEFT3,) || __GET_VAR(data__->ANTI_THEFT4,)));
  __SET_VAR(data__->TON1.,IN,,((!(__GET_VAR(data__->FARO2,)) && __BOOL_LITERAL(TRUE)) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_VAR(data__->,FARO2,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->TON2.,IN,,((!(__GET_VAR(data__->FARO3,)) && __BOOL_LITERAL(TRUE)) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->TOF2.,IN,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->TOF2.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF2);
  __SET_VAR(data__->,FARO3,,__GET_VAR(data__->TOF2.Q,));
  __SET_VAR(data__->TON3.,IN,,((!(__GET_VAR(data__->FARO4,)) && __BOOL_LITERAL(TRUE)) && (((__GET_EXTERNAL(data__->ALARM1,) && (__GET_EXTERNAL(data__->FOTOC1,) || __GET_VAR(data__->T_PROX1,))) || (__GET_EXTERNAL(data__->ALARM2,) && (__GET_EXTERNAL(data__->FOTOC2,) || __GET_EXTERNAL(data__->S_MOV1,)))) || (__GET_EXTERNAL(data__->ALARM3,) && __GET_VAR(data__->S_MOV2,)))));
  __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->TOF3.,IN,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->TOF3.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF3);
  __SET_VAR(data__->,FARO4,,__GET_VAR(data__->TOF3.Q,));

  goto __end;

__end:
  return;
} // ANTIFURTO_body__() 





