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





void CARRELLO_init__(CARRELLO *data__, BOOL retain) {
  __INIT_VAR(data__->START_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_EXTERNAL(BOOL,GO_RIGHT,data__->GO_RIGHT,retain)
  __INIT_EXTERNAL(BOOL,GO_LEFT,data__->GO_LEFT,retain)
  __INIT_EXTERNAL(BOOL,LOAD,data__->LOAD,retain)
  __INIT_EXTERNAL(BOOL,FD,data__->FD,retain)
  __INIT_EXTERNAL(BOOL,FS,data__->FS,retain)
  __INIT_EXTERNAL(BOOL,FR,data__->FR,retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  UINT i;
  data__->__nb_steps = 4;
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
  data__->__nb_transitions = 4;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define QUIETE __step_list[0]
#define __SFC_QUIETE 0
#define VAI_A_DX __step_list[1]
#define __SFC_VAI_A_DX 1
#define CARICA __step_list[2]
#define __SFC_CARICA 2
#define STEP0 __step_list[3]
#define __SFC_STEP0 3

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_GO_RIGHT 1
#define __SFC_LOAD 2
#define __SFC_GO_LEFT 3

// Code part
void CARRELLO_body__(CARRELLO *data__) {
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
  if (__GET_VAR(data__->QUIETE.X)) {
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
  if (__GET_VAR(data__->VAI_A_DX.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_EXTERNAL(data__->FD,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_EXTERNAL(data__->FD,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->CARICA.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_EXTERNAL(data__->FR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_EXTERNAL(data__->FR,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_EXTERNAL(data__->FS,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_EXTERNAL(data__->FS,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,QUIETE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,VAI_A_DX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,CARICA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,VAI_A_DX.X,,1);
    data__->VAI_A_DX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,CARICA.X,,1);
    data__->CARICA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,QUIETE.X,,1);
    data__->QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // QUIETE action associations
  {
    char active = __GET_VAR(data__->QUIETE.X);
    char activated = active && !data__->QUIETE.prev_state;
    char desactivated = !active && data__->QUIETE.prev_state;

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // VAI_A_DX action associations
  {
    char active = __GET_VAR(data__->VAI_A_DX.X);
    char activated = active && !data__->VAI_A_DX.prev_state;
    char desactivated = !active && data__->VAI_A_DX.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,GO_RIGHT,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,GO_RIGHT,,0);};

  }

  // CARICA action associations
  {
    char active = __GET_VAR(data__->CARICA.X);
    char activated = active && !data__->CARICA.prev_state;
    char desactivated = !active && data__->CARICA.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,LOAD,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,LOAD,,0);};

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,GO_LEFT,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,GO_LEFT,,0);};

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
  if (data__->__action_list[__SFC_GO_RIGHT].reset) {
    __SET_EXTERNAL(data__->,GO_RIGHT,,0);
  }
  else if (data__->__action_list[__SFC_GO_RIGHT].set) {
    __SET_EXTERNAL(data__->,GO_RIGHT,,1);
  }
  if (data__->__action_list[__SFC_LOAD].reset) {
    __SET_EXTERNAL(data__->,LOAD,,0);
  }
  else if (data__->__action_list[__SFC_LOAD].set) {
    __SET_EXTERNAL(data__->,LOAD,,1);
  }
  if (data__->__action_list[__SFC_GO_LEFT].reset) {
    __SET_EXTERNAL(data__->,GO_LEFT,,0);
  }
  else if (data__->__action_list[__SFC_GO_LEFT].set) {
    __SET_EXTERNAL(data__->,GO_LEFT,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->START_BUTTON,));
    R_TRIG_body__(&data__->R_TRIG1);
  }



  goto __end;

__end:
  return;
} // CARRELLO_body__() 

// Steps undefinitions
#undef QUIETE
#undef __SFC_QUIETE
#undef VAI_A_DX
#undef __SFC_VAI_A_DX
#undef CARICA
#undef __SFC_CARICA
#undef STEP0
#undef __SFC_STEP0

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_GO_RIGHT
#undef __SFC_LOAD
#undef __SFC_GO_LEFT





void SIMULAZIONE_CARRELLO_init__(SIMULAZIONE_CARRELLO *data__, BOOL retain) {
  __INIT_VAR(data__->DUMMY1,0,retain)
  __INIT_VAR(data__->DUMMY2,0,retain)
  __INIT_VAR(data__->DUMMY3,0,retain)
  __INIT_EXTERNAL(BOOL,GO_RIGHT,data__->GO_RIGHT,retain)
  __INIT_EXTERNAL(BOOL,GO_LEFT,data__->GO_LEFT,retain)
  __INIT_EXTERNAL(BOOL,LOAD,data__->LOAD,retain)
  __INIT_EXTERNAL(BOOL,FD,data__->FD,retain)
  __INIT_EXTERNAL(BOOL,FS,data__->FS,retain)
  __INIT_EXTERNAL(BOOL,FR,data__->FR,retain)
  UINT i;
  data__->__nb_steps = 7;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[4].X,,1);
  data__->__nb_actions = 6;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 7;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define FERMO_A_SX __step_list[0]
#define __SFC_FERMO_A_SX 0
#define VAI_A_DX __step_list[1]
#define __SFC_VAI_A_DX 1
#define FERMO_A_DX __step_list[2]
#define __SFC_FERMO_A_DX 2
#define VAI_A_SX __step_list[3]
#define __SFC_VAI_A_SX 3
#define QUIETE __step_list[4]
#define __SFC_QUIETE 4
#define SVUOTA __step_list[5]
#define __SFC_SVUOTA 5
#define VUOTO __step_list[6]
#define __SFC_VUOTO 6

// Actions definitions
#define __SFC_FS 0
#define __SFC_DUMMY1 1
#define __SFC_FD 2
#define __SFC_DUMMY2 3
#define __SFC_FR 4
#define __SFC_DUMMY3 5

// Code part
void SIMULAZIONE_CARRELLO_body__(SIMULAZIONE_CARRELLO *data__) {
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
  if (__GET_VAR(data__->FERMO_A_SX.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_EXTERNAL(data__->GO_RIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_EXTERNAL(data__->GO_RIGHT,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->VAI_A_DX.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->DUMMY1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->DUMMY1,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->FERMO_A_DX.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_EXTERNAL(data__->GO_LEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_EXTERNAL(data__->GO_LEFT,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->VAI_A_SX.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->DUMMY1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->DUMMY1,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->QUIETE.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_EXTERNAL(data__->LOAD,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_EXTERNAL(data__->LOAD,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->SVUOTA.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->DUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->DUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->VUOTO.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->DUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->DUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,FERMO_A_SX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,VAI_A_DX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,FERMO_A_DX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,VAI_A_SX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,QUIETE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,SVUOTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,VUOTO.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,VAI_A_DX.X,,1);
    data__->VAI_A_DX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,FERMO_A_DX.X,,1);
    data__->FERMO_A_DX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,VAI_A_SX.X,,1);
    data__->VAI_A_SX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,FERMO_A_SX.X,,1);
    data__->FERMO_A_SX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,SVUOTA.X,,1);
    data__->SVUOTA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,VUOTO.X,,1);
    data__->VUOTO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,QUIETE.X,,1);
    data__->QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // FERMO_A_SX action associations
  {
    char active = __GET_VAR(data__->FERMO_A_SX.X);
    char activated = active && !data__->FERMO_A_SX.prev_state;
    char desactivated = !active && data__->FERMO_A_SX.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,FS,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,FS,,0);};

  }

  // VAI_A_DX action associations
  {
    char active = __GET_VAR(data__->VAI_A_DX.X);
    char activated = active && !data__->VAI_A_DX.prev_state;
    char desactivated = !active && data__->VAI_A_DX.prev_state;

    if (active && __time_cmp(data__->VAI_A_DX.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,DUMMY1,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,DUMMY1,,0);};

  }

  // FERMO_A_DX action associations
  {
    char active = __GET_VAR(data__->FERMO_A_DX.X);
    char activated = active && !data__->FERMO_A_DX.prev_state;
    char desactivated = !active && data__->FERMO_A_DX.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,FD,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,FD,,0);};

  }

  // VAI_A_SX action associations
  {
    char active = __GET_VAR(data__->VAI_A_SX.X);
    char activated = active && !data__->VAI_A_SX.prev_state;
    char desactivated = !active && data__->VAI_A_SX.prev_state;

    if (active && __time_cmp(data__->VAI_A_SX.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,DUMMY1,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,DUMMY1,,0);};

  }

  // SVUOTA action associations
  {
    char active = __GET_VAR(data__->SVUOTA.X);
    char activated = active && !data__->SVUOTA.prev_state;
    char desactivated = !active && data__->SVUOTA.prev_state;

    if (active && __time_cmp(data__->SVUOTA.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,DUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,DUMMY2,,0);};

  }

  // VUOTO action associations
  {
    char active = __GET_VAR(data__->VUOTO.X);
    char activated = active && !data__->VUOTO.prev_state;
    char desactivated = !active && data__->VUOTO.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,FR,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,FR,,0);};

    if (active && __time_cmp(data__->VUOTO.T.value, __time_to_timespec(1, 500, 0, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,DUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,DUMMY3,,0);};

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
  if (data__->__action_list[__SFC_FS].reset) {
    __SET_EXTERNAL(data__->,FS,,0);
  }
  else if (data__->__action_list[__SFC_FS].set) {
    __SET_EXTERNAL(data__->,FS,,1);
  }
  if (data__->__action_list[__SFC_DUMMY1].reset) {
    __SET_VAR(data__->,DUMMY1,,0);
  }
  else if (data__->__action_list[__SFC_DUMMY1].set) {
    __SET_VAR(data__->,DUMMY1,,1);
  }
  if (data__->__action_list[__SFC_FD].reset) {
    __SET_EXTERNAL(data__->,FD,,0);
  }
  else if (data__->__action_list[__SFC_FD].set) {
    __SET_EXTERNAL(data__->,FD,,1);
  }
  if (data__->__action_list[__SFC_DUMMY2].reset) {
    __SET_VAR(data__->,DUMMY2,,0);
  }
  else if (data__->__action_list[__SFC_DUMMY2].set) {
    __SET_VAR(data__->,DUMMY2,,1);
  }
  if (data__->__action_list[__SFC_FR].reset) {
    __SET_EXTERNAL(data__->,FR,,0);
  }
  else if (data__->__action_list[__SFC_FR].set) {
    __SET_EXTERNAL(data__->,FR,,1);
  }
  if (data__->__action_list[__SFC_DUMMY3].reset) {
    __SET_VAR(data__->,DUMMY3,,0);
  }
  else if (data__->__action_list[__SFC_DUMMY3].set) {
    __SET_VAR(data__->,DUMMY3,,1);
  }


  goto __end;

__end:
  return;
} // SIMULAZIONE_CARRELLO_body__() 

// Steps undefinitions
#undef FERMO_A_SX
#undef __SFC_FERMO_A_SX
#undef VAI_A_DX
#undef __SFC_VAI_A_DX
#undef FERMO_A_DX
#undef __SFC_FERMO_A_DX
#undef VAI_A_SX
#undef __SFC_VAI_A_SX
#undef QUIETE
#undef __SFC_QUIETE
#undef SVUOTA
#undef __SFC_SVUOTA
#undef VUOTO
#undef __SFC_VUOTO

// Actions undefinitions
#undef __SFC_FS
#undef __SFC_DUMMY1
#undef __SFC_FD
#undef __SFC_DUMMY2
#undef __SFC_FR
#undef __SFC_DUMMY3





