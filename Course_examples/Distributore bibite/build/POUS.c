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





void DISTRIBUTORE_init__(DISTRIBUTORE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ATTIVA_SA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EROGA_PRODOTTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RICARICA_PRODOTTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRELEVA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SVUOTA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRODOTTI_DA_PRELEVARE,0,retain)
  __INIT_VAR(data__->PRODOTTI_DISP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->N_PRODOTTI,10,retain)
  __INIT_VAR(data__->PRODOTTI_BUFFER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EROGA_TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUFFER_TRIG,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->RTRIG_EROGA,retain);
  R_TRIG_init__(&data__->RTRIG_BUFFER,retain);
}

// Code part
void DISTRIBUTORE_body__(DISTRIBUTORE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,PRODOTTI_DISP,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->N_PRODOTTI,),
    (INT)0));
  __SET_VAR(data__->RTRIG_EROGA.,CLK,,__GET_VAR(data__->EROGA_PRODOTTO,));
  R_TRIG_body__(&data__->RTRIG_EROGA);
  __SET_VAR(data__->,EROGA_TRIG,,__GET_VAR(data__->RTRIG_EROGA.Q));
  __SET_VAR(data__->RTRIG_BUFFER.,CLK,,__GET_VAR(data__->ATTIVA_SA,));
  R_TRIG_body__(&data__->RTRIG_BUFFER);
  __SET_VAR(data__->,BUFFER_TRIG,,__GET_VAR(data__->RTRIG_BUFFER.Q));
  if ((__GET_VAR(data__->BUFFER_TRIG,) && __GET_VAR(data__->PRODOTTI_DISP,))) {
    __SET_VAR(data__->,N_PRODOTTI,,(__GET_VAR(data__->N_PRODOTTI,) - 1));
    __SET_VAR(data__->,PRODOTTI_BUFFER,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->EROGA_TRIG,) && __GET_VAR(data__->PRODOTTI_BUFFER,))) {
    __SET_VAR(data__->,PRODOTTI_BUFFER,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,PRODOTTI_DA_PRELEVARE,,(__GET_VAR(data__->PRODOTTI_DA_PRELEVARE,) + 1));
  };
  if (__GET_VAR(data__->RICARICA_PRODOTTO,)) {
    __SET_VAR(data__->,N_PRODOTTI,,10);
  };
  if (__GET_VAR(data__->PRELEVA,)) {
    __SET_VAR(data__->,PRODOTTI_DA_PRELEVARE,,0);
  };
  if (__GET_VAR(data__->SVUOTA,)) {
    __SET_VAR(data__->,PRODOTTI_DA_PRELEVARE,,(__GET_VAR(data__->PRODOTTI_DA_PRELEVARE,) + __GET_VAR(data__->N_PRODOTTI,)));
    __SET_VAR(data__->,N_PRODOTTI,,0);
  };

  goto __end;

__end:
  return;
} // DISTRIBUTORE_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,MONETA,data__->MONETA,retain)
  __INIT_EXTERNAL(BOOL,SA,data__->SA,retain)
  __INIT_EXTERNAL(BOOL,SB,data__->SB,retain)
  __INIT_EXTERNAL(BOOL,APERTO,data__->APERTO,retain)
  __INIT_EXTERNAL(BOOL,BLOCCA,data__->BLOCCA,retain)
  __INIT_EXTERNAL(BOOL,SBLOCCA,data__->SBLOCCA,retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  UINT i;
  data__->__nb_steps = 6;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 5;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 5;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define F0 __step_list[0]
#define __SFC_F0 0
#define F11 __step_list[1]
#define __SFC_F11 1
#define F12 __step_list[2]
#define __SFC_F12 2
#define F21 __step_list[3]
#define __SFC_F21 3
#define F22 __step_list[4]
#define __SFC_F22 4
#define F23 __step_list[5]
#define __SFC_F23 5

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_BLOCCA 1
#define __SFC_SBLOCCA 2
#define __SFC_SB 3
#define __SFC_SA 4

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
  if (__GET_VAR(data__->F0.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->R_TRIG1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->R_TRIG1.Q,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->F11.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_EXTERNAL(data__->APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_EXTERNAL(data__->APERTO,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->F12.X) && __GET_VAR(data__->F23.X)) {
    __SET_VAR(data__->,__transition_list[2],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->F21.X)) {
    __SET_VAR(data__->,__transition_list[3],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F21.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F21.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->F22.X)) {
    __SET_VAR(data__->,__transition_list[4],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F22.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->F22.T,), __time_to_timespec(1, 0, 2, 0, 0, 0)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F12.X,,0);
    __SET_VAR(data__->,F23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F22.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F11.X,,1);
    data__->F11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,F21.X,,1);
    data__->F21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F12.X,,1);
    data__->F12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,F0.X,,1);
    data__->F0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,F22.X,,1);
    data__->F22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,F23.X,,1);
    data__->F23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // F0 action associations
  {
    char active = __GET_VAR(data__->F0.X);
    char activated = active && !data__->F0.prev_state;
    char desactivated = !active && data__->F0.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,BLOCCA,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,BLOCCA,,0);};

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // F11 action associations
  {
    char active = __GET_VAR(data__->F11.X);
    char activated = active && !data__->F11.prev_state;
    char desactivated = !active && data__->F11.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SBLOCCA,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SBLOCCA,,0);};

  }

  // F21 action associations
  {
    char active = __GET_VAR(data__->F21.X);
    char activated = active && !data__->F21.prev_state;
    char desactivated = !active && data__->F21.prev_state;

    if (active && __time_cmp(data__->F21.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) < 0) 
                      {__SET_EXTERNAL(data__->,SB,,1);}
    else if (desactivated || active)
                      {__SET_EXTERNAL(data__->,SB,,0);};

  }

  // F22 action associations
  {
    char active = __GET_VAR(data__->F22.X);
    char activated = active && !data__->F22.prev_state;
    char desactivated = !active && data__->F22.prev_state;

    if (active && __time_cmp(data__->F22.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) < 0) 
                      {__SET_EXTERNAL(data__->,SA,,1);}
    else if (desactivated || active)
                      {__SET_EXTERNAL(data__->,SA,,0);};

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
  if (data__->__action_list[__SFC_BLOCCA].reset) {
    __SET_EXTERNAL(data__->,BLOCCA,,0);
  }
  else if (data__->__action_list[__SFC_BLOCCA].set) {
    __SET_EXTERNAL(data__->,BLOCCA,,1);
  }
  if (data__->__action_list[__SFC_SBLOCCA].reset) {
    __SET_EXTERNAL(data__->,SBLOCCA,,0);
  }
  else if (data__->__action_list[__SFC_SBLOCCA].set) {
    __SET_EXTERNAL(data__->,SBLOCCA,,1);
  }
  if (data__->__action_list[__SFC_SB].reset) {
    __SET_EXTERNAL(data__->,SB,,0);
  }
  else if (data__->__action_list[__SFC_SB].set) {
    __SET_EXTERNAL(data__->,SB,,1);
  }
  if (data__->__action_list[__SFC_SA].reset) {
    __SET_EXTERNAL(data__->,SA,,0);
  }
  else if (data__->__action_list[__SFC_SA].set) {
    __SET_EXTERNAL(data__->,SA,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->R_TRIG1.,CLK,,__GET_EXTERNAL(data__->MONETA,));
    R_TRIG_body__(&data__->R_TRIG1);
  }



  goto __end;

__end:
  return;
} // MAIN_body__() 

// Steps undefinitions
#undef F0
#undef __SFC_F0
#undef F11
#undef __SFC_F11
#undef F12
#undef __SFC_F12
#undef F21
#undef __SFC_F21
#undef F22
#undef __SFC_F22
#undef F23
#undef __SFC_F23

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_BLOCCA
#undef __SFC_SBLOCCA
#undef __SFC_SB
#undef __SFC_SA





void PISTONE_init__(PISTONE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->APRI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->APERTO,0,retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
}

// Code part
void PISTONE_body__(PISTONE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,(!(__GET_VAR(data__->APERTO,)) && __GET_VAR(data__->APRI,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 300, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,APERTO,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON1.,IN,,!(__GET_VAR(data__->APRI,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 300, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,APERTO,,!(__GET_VAR(data__->TON1.Q,)));

  goto __end;

__end:
  return;
} // PISTONE_body__() 





void SIMULATOR_init__(SIMULATOR *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,MONETA,data__->MONETA,retain)
  __INIT_EXTERNAL(BOOL,SB,data__->SB,retain)
  __INIT_EXTERNAL(BOOL,SA,data__->SA,retain)
  __INIT_EXTERNAL(BOOL,SBLOCCA,data__->SBLOCCA,retain)
  __INIT_EXTERNAL(BOOL,BLOCCA,data__->BLOCCA,retain)
  __INIT_EXTERNAL(BOOL,APERTO,data__->APERTO,retain)
  __INIT_VAR(data__->A_APERTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B_APERTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRELEVA_PRODOTTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RICARICA_PRODOTTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CREDITO_DISPONIBILE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRODOTTI_NEL_VANO,0,retain)
  __INIT_VAR(data__->PRODOTTI_DISPONIBILI,__BOOL_LITERAL(FALSE),retain)
  DISTRIBUTORE_init__(&data__->DISTRIBUTORE0,retain);
  PISTONE_init__(&data__->PISTONE0,retain);
  PISTONE_init__(&data__->PISTONE1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
}

// Code part
void SIMULATOR_body__(SIMULATOR *data__) {
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,APERTO,,!(__GET_EXTERNAL(data__->BLOCCA,)));
  __SET_EXTERNAL(data__->,APERTO,,(!(__GET_EXTERNAL(data__->BLOCCA,)) && __GET_EXTERNAL(data__->SBLOCCA,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->RICARICA_PRODOTTO,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->PRELEVA_PRODOTTO,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->DISTRIBUTORE0.,ATTIVA_SA,,(!(__GET_VAR(data__->B_APERTO,)) && __GET_VAR(data__->A_APERTO,)));
  __SET_VAR(data__->DISTRIBUTORE0.,EROGA_PRODOTTO,,((__GET_VAR(data__->CREDITO_DISPONIBILE,) && __GET_VAR(data__->B_APERTO,)) && !(__GET_VAR(data__->A_APERTO,))));
  __SET_VAR(data__->DISTRIBUTORE0.,RICARICA_PRODOTTO,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->DISTRIBUTORE0.,PRELEVA,,(__GET_EXTERNAL(data__->APERTO,) && __GET_VAR(data__->R_TRIG2.Q,)));
  __SET_VAR(data__->DISTRIBUTORE0.,SVUOTA,,(__GET_VAR(data__->B_APERTO,) && __GET_VAR(data__->A_APERTO,)));
  DISTRIBUTORE_body__(&data__->DISTRIBUTORE0);
  __SET_VAR(data__->,PRODOTTI_NEL_VANO,,__GET_VAR(data__->DISTRIBUTORE0.PRODOTTI_DA_PRELEVARE,));
  __SET_VAR(data__->,PRODOTTI_DISPONIBILI,,__GET_VAR(data__->DISTRIBUTORE0.PRODOTTI_DISP,));
  __SET_VAR(data__->PISTONE0.,APRI,,__GET_EXTERNAL(data__->SA,));
  PISTONE_body__(&data__->PISTONE0);
  __SET_VAR(data__->,A_APERTO,,__GET_VAR(data__->PISTONE0.APERTO,));
  __SET_VAR(data__->PISTONE1.,APRI,,__GET_EXTERNAL(data__->SB,));
  PISTONE_body__(&data__->PISTONE1);
  __SET_VAR(data__->,B_APERTO,,__GET_VAR(data__->PISTONE1.APERTO,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_EXTERNAL(data__->MONETA,));
  R_TRIG_body__(&data__->R_TRIG3);
  if (__GET_VAR(data__->R_TRIG3.Q,)) {
    __SET_VAR(data__->,CREDITO_DISPONIBILE,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->B_APERTO,)) {
    __SET_VAR(data__->,CREDITO_DISPONIBILE,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // SIMULATOR_body__() 





