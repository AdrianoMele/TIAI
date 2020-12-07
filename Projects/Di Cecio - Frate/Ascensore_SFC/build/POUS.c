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





void SENSORI_PIANI_init__(SENSORI_PIANI *data__, BOOL retain) {
  __INIT_EXTERNAL(GESTIONEPIANI,INFO,data__->INFO,retain)
  __INIT_EXTERNAL(TASTIERINO,DISPLAY,data__->DISPLAY,retain)
  __INIT_VAR(data__->SENSOR0,1,retain)
  __INIT_VAR(data__->SENSOR1,0,retain)
  __INIT_VAR(data__->SENSOR2,0,retain)
  __INIT_VAR(data__->SENSOR3,0,retain)
  UINT i;
  data__->__nb_steps = 5;
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
  data__->__nb_transitions = 8;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define PIANI __step_list[0]
#define __SFC_PIANI 0
#define PIANO0 __step_list[1]
#define __SFC_PIANO0 1
#define PIANO1 __step_list[2]
#define __SFC_PIANO1 2
#define PIANO2 __step_list[3]
#define __SFC_PIANO2 3
#define PIANO3 __step_list[4]
#define __SFC_PIANO3 4

// Actions definitions
#define __SFC_PIANO0_INLINE1 0
#define __SFC_PIANO1_INLINE2 1
#define __SFC_PIANO2_INLINE4 2
#define __SFC_PIANO3_INLINE3 3

// Code part
void SENSORI_PIANI_body__(SENSORI_PIANI *data__) {
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
  if (__GET_VAR(data__->PIANI.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->SENSOR0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->SENSOR0,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->PIANO0.X)) {
    __SET_VAR(data__->,__transition_list[1],,!(__GET_VAR(data__->SENSOR0,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,!(__GET_VAR(data__->SENSOR0,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->PIANI.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->SENSOR1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->SENSOR1,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->PIANO1.X)) {
    __SET_VAR(data__->,__transition_list[3],,!(__GET_VAR(data__->SENSOR1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!(__GET_VAR(data__->SENSOR1,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->PIANI.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->SENSOR2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->SENSOR2,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->PIANO2.X)) {
    __SET_VAR(data__->,__transition_list[5],,!(__GET_VAR(data__->SENSOR2,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,!(__GET_VAR(data__->SENSOR2,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->PIANI.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->SENSOR3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->SENSOR3,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->PIANO3.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_VAR(data__->SENSOR3,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_VAR(data__->SENSOR3,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PIANI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PIANO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PIANI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,PIANO1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PIANI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PIANO2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PIANI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PIANO3.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PIANO0.X,,1);
    data__->PIANO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PIANI.X,,1);
    data__->PIANI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PIANO1.X,,1);
    data__->PIANO1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,PIANI.X,,1);
    data__->PIANI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PIANO2.X,,1);
    data__->PIANO2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PIANI.X,,1);
    data__->PIANI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PIANO3.X,,1);
    data__->PIANO3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PIANI.X,,1);
    data__->PIANI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // PIANO0 action associations
  {
    char active = __GET_VAR(data__->PIANO0.X);
    char activated = active && !data__->PIANO0.prev_state;
    char desactivated = !active && data__->PIANO0.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PIANO0_INLINE1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PIANO0_INLINE1].state,,0);};

  }

  // PIANO1 action associations
  {
    char active = __GET_VAR(data__->PIANO1.X);
    char activated = active && !data__->PIANO1.prev_state;
    char desactivated = !active && data__->PIANO1.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PIANO1_INLINE2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PIANO1_INLINE2].state,,0);};

  }

  // PIANO2 action associations
  {
    char active = __GET_VAR(data__->PIANO2.X);
    char activated = active && !data__->PIANO2.prev_state;
    char desactivated = !active && data__->PIANO2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PIANO2_INLINE4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PIANO2_INLINE4].state,,0);};

  }

  // PIANO3 action associations
  {
    char active = __GET_VAR(data__->PIANO3.X);
    char activated = active && !data__->PIANO3.prev_state;
    char desactivated = !active && data__->PIANO3.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PIANO3_INLINE3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PIANO3_INLINE3].state,,0);};

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
  if(__GET_VAR(data__->__action_list[__SFC_PIANO0_INLINE1].state)) {
    __SET_EXTERNAL(data__->,INFO,.PIANO_CORRENTE,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_PIANO1_INLINE2].state)) {
    __SET_EXTERNAL(data__->,INFO,.PIANO_CORRENTE,1);
  }

  if(__GET_VAR(data__->__action_list[__SFC_PIANO2_INLINE4].state)) {
    __SET_EXTERNAL(data__->,INFO,.PIANO_CORRENTE,2);
  }

  if(__GET_VAR(data__->__action_list[__SFC_PIANO3_INLINE3].state)) {
    __SET_EXTERNAL(data__->,INFO,.PIANO_CORRENTE,3);
  }



  goto __end;

__end:
  return;
} // SENSORI_PIANI_body__() 

// Steps undefinitions
#undef PIANI
#undef __SFC_PIANI
#undef PIANO0
#undef __SFC_PIANO0
#undef PIANO1
#undef __SFC_PIANO1
#undef PIANO2
#undef __SFC_PIANO2
#undef PIANO3
#undef __SFC_PIANO3

// Actions undefinitions
#undef __SFC_PIANO0_INLINE1
#undef __SFC_PIANO1_INLINE2
#undef __SFC_PIANO2_INLINE4
#undef __SFC_PIANO3_INLINE3





// FUNCTION
RICHIESTE BOUBLESORT_CRESCENTE(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  USINT I = 0;
  SINT DUMMY = 0;
  BOOL CAMBIO = 1;
  RICHIESTE BOUBLESORT_CRESCENTE = {0,0,0,{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BOUBLESORT_CRESCENTE;
  }
  if ((CODA.DIM > 1)) {
    while (CAMBIO) {
      CAMBIO = 0;
      for(I = CODA.BOT; ((((20 == 0)?0:(1 % 20))) > 0)? (I <= ((CODA.TOP - 1))) : (I >= ((CODA.TOP - 1))); I += (((20 == 0)?0:(1 % 20)))) {
        if ((CODA.QUEUE.table[(I) - (0)] > CODA.QUEUE.table[((I + 1)) - (0)])) {
          DUMMY = CODA.QUEUE.table[(I) - (0)];
          CODA.QUEUE.table[(I) - (0)] = CODA.QUEUE.table[((I + 1)) - (0)];
          CODA.QUEUE.table[((I + 1)) - (0)] = DUMMY;
          CAMBIO = 1;
        };
      };
    };
    BOUBLESORT_CRESCENTE = CODA;
  };
  goto __end;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BOUBLESORT_CRESCENTE;
}


// FUNCTION
RICHIESTE INSERISCI_PIANO_SALITA(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA, 
  SINT PIANO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  RICHIESTE INSERISCI_PIANO_SALITA = {0,0,0,{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INSERISCI_PIANO_SALITA;
  }
  CODA.QUEUE.table[(CODA.TOP) - (0)] = PIANO;
  if ((CODA.DIM < 20)) {
    CODA.TOP = ((20 == 0)?0:((CODA.TOP + 1) % 20));
    CODA.DIM = (CODA.DIM + 1);
    CODA = BOUBLESORT_CRESCENTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)CODA);
  };
  INSERISCI_PIANO_SALITA = CODA;
  goto __end;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INSERISCI_PIANO_SALITA;
}


// FUNCTION
RICHIESTE BOUBLESORT_DECRESCENTE(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  USINT I = 0;
  SINT DUMMY = 0;
  BOOL CAMBIO = 1;
  RICHIESTE BOUBLESORT_DECRESCENTE = {0,0,0,{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BOUBLESORT_DECRESCENTE;
  }
  if ((CODA.DIM > 1)) {
    while (CAMBIO) {
      CAMBIO = 0;
      for(I = CODA.BOT; ((((20 == 0)?0:(1 % 20))) > 0)? (I <= ((CODA.TOP - 1))) : (I >= ((CODA.TOP - 1))); I += (((20 == 0)?0:(1 % 20)))) {
        if ((CODA.QUEUE.table[(I) - (0)] < CODA.QUEUE.table[((I + 1)) - (0)])) {
          DUMMY = CODA.QUEUE.table[(I) - (0)];
          CODA.QUEUE.table[(I) - (0)] = CODA.QUEUE.table[((I + 1)) - (0)];
          CODA.QUEUE.table[((I + 1)) - (0)] = DUMMY;
          CAMBIO = 1;
        };
      };
    };
    BOUBLESORT_DECRESCENTE = CODA;
  };
  goto __end;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BOUBLESORT_DECRESCENTE;
}


// FUNCTION
RICHIESTE INSERISCI_PIANO_DISCESA(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA, 
  SINT PIANO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  RICHIESTE INSERISCI_PIANO_DISCESA = {0,0,0,{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INSERISCI_PIANO_DISCESA;
  }
  CODA.QUEUE.table[(CODA.TOP) - (0)] = PIANO;
  if ((CODA.DIM < 20)) {
    CODA.TOP = ((20 == 0)?0:((CODA.TOP + 1) % 20));
    CODA.DIM = (CODA.DIM + 1);
    CODA = BOUBLESORT_DECRESCENTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)CODA);
  };
  INSERISCI_PIANO_DISCESA = CODA;
  goto __end;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INSERISCI_PIANO_DISCESA;
}


void PRENOTAZIONI_INTERNE_init__(PRENOTAZIONI_INTERNE *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,FLAG,data__->FLAG,retain)
  __INIT_EXTERNAL(RICHIESTE,RICHIESTE_SALITA,data__->RICHIESTE_SALITA,retain)
  __INIT_EXTERNAL(RICHIESTE,RICHIESTE_DISCESA,data__->RICHIESTE_DISCESA,retain)
  __INIT_EXTERNAL(TASTIERINO,DISPLAY,data__->DISPLAY,retain)
  __INIT_EXTERNAL(GESTIONEPIANI,INFO,data__->INFO,retain)
  UINT i;
  data__->__nb_steps = 6;
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
#define PRENOTAZIONE_INTERNA __step_list[0]
#define __SFC_PRENOTAZIONE_INTERNA 0
#define ABILITA_TASTIERINO __step_list[1]
#define __SFC_ABILITA_TASTIERINO 1
#define INSERISCI_PIANO0 __step_list[2]
#define __SFC_INSERISCI_PIANO0 2
#define INSERISCI_PIANO1 __step_list[3]
#define __SFC_INSERISCI_PIANO1 3
#define INSERISCI_PIANO2 __step_list[4]
#define __SFC_INSERISCI_PIANO2 4
#define INSERISCI_PIANO3 __step_list[5]
#define __SFC_INSERISCI_PIANO3 5

// Actions definitions
#define __SFC_INS_0 0
#define __SFC_INS_1 1
#define __SFC_INS_2 2
#define __SFC_INS_3 3

// Code part
void PRENOTAZIONI_INTERNE_body__(PRENOTAZIONI_INTERNE *data__) {
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
  if (__GET_VAR(data__->PRENOTAZIONE_INTERNA.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_EXTERNAL(data__->FLAG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_EXTERNAL(data__->FLAG,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->ABILITA_TASTIERINO.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_0) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_0) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 0)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->INSERISCI_PIANO0.X)) {
    __SET_VAR(data__->,__transition_list[2],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,1);
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->ABILITA_TASTIERINO.X)) {
    __SET_VAR(data__->,__transition_list[3],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_1) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_1) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 1)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->INSERISCI_PIANO1.X)) {
    __SET_VAR(data__->,__transition_list[4],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,1);
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->ABILITA_TASTIERINO.X)) {
    __SET_VAR(data__->,__transition_list[5],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_2) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 2)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_2) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 2)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INSERISCI_PIANO2.X)) {
    __SET_VAR(data__->,__transition_list[6],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,1);
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->ABILITA_TASTIERINO.X)) {
    __SET_VAR(data__->,__transition_list[7],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_3) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 3)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,(__GET_EXTERNAL(data__->DISPLAY,.PULS_3) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 3)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->INSERISCI_PIANO3.X)) {
    __SET_VAR(data__->,__transition_list[8],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,1);
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PRENOTAZIONE_INTERNA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,ABILITA_TASTIERINO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,INSERISCI_PIANO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,ABILITA_TASTIERINO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INSERISCI_PIANO1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,ABILITA_TASTIERINO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INSERISCI_PIANO2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,ABILITA_TASTIERINO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,INSERISCI_PIANO3.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,ABILITA_TASTIERINO.X,,1);
    data__->ABILITA_TASTIERINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,INSERISCI_PIANO0.X,,1);
    data__->INSERISCI_PIANO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PRENOTAZIONE_INTERNA.X,,1);
    data__->PRENOTAZIONE_INTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,INSERISCI_PIANO1.X,,1);
    data__->INSERISCI_PIANO1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PRENOTAZIONE_INTERNA.X,,1);
    data__->PRENOTAZIONE_INTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,INSERISCI_PIANO2.X,,1);
    data__->INSERISCI_PIANO2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PRENOTAZIONE_INTERNA.X,,1);
    data__->PRENOTAZIONE_INTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,INSERISCI_PIANO3.X,,1);
    data__->INSERISCI_PIANO3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,PRENOTAZIONE_INTERNA.X,,1);
    data__->PRENOTAZIONE_INTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INSERISCI_PIANO0 action associations
  {
    char active = __GET_VAR(data__->INSERISCI_PIANO0.X);
    char activated = active && !data__->INSERISCI_PIANO0.prev_state;
    char desactivated = !active && data__->INSERISCI_PIANO0.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_0].state,,0);};

  }

  // INSERISCI_PIANO1 action associations
  {
    char active = __GET_VAR(data__->INSERISCI_PIANO1.X);
    char activated = active && !data__->INSERISCI_PIANO1.prev_state;
    char desactivated = !active && data__->INSERISCI_PIANO1.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_1].state,,0);};

  }

  // INSERISCI_PIANO2 action associations
  {
    char active = __GET_VAR(data__->INSERISCI_PIANO2.X);
    char activated = active && !data__->INSERISCI_PIANO2.prev_state;
    char desactivated = !active && data__->INSERISCI_PIANO2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_2].state,,0);};

  }

  // INSERISCI_PIANO3 action associations
  {
    char active = __GET_VAR(data__->INSERISCI_PIANO3.X);
    char activated = active && !data__->INSERISCI_PIANO3.prev_state;
    char desactivated = !active && data__->INSERISCI_PIANO3.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_3].state,,0);};

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
  if(__GET_VAR(data__->__action_list[__SFC_INS_0].state)) {
    __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,INSERISCI_PIANO_DISCESA(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,),
      (SINT)0));
  }

  if(__GET_VAR(data__->__action_list[__SFC_INS_1].state)) {
    if ((__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) < 1)) {
      __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,INSERISCI_PIANO_SALITA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,),
        (SINT)1));
    } else {
      __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,INSERISCI_PIANO_DISCESA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,),
        (SINT)1));
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_INS_2].state)) {
    if ((__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) < 2)) {
      __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,INSERISCI_PIANO_SALITA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,),
        (SINT)2));
    } else {
      __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,INSERISCI_PIANO_DISCESA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,),
        (SINT)2));
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_INS_3].state)) {
    __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,INSERISCI_PIANO_SALITA(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,),
      (SINT)3));
  }



  goto __end;

__end:
  return;
} // PRENOTAZIONI_INTERNE_body__() 

// Steps undefinitions
#undef PRENOTAZIONE_INTERNA
#undef __SFC_PRENOTAZIONE_INTERNA
#undef ABILITA_TASTIERINO
#undef __SFC_ABILITA_TASTIERINO
#undef INSERISCI_PIANO0
#undef __SFC_INSERISCI_PIANO0
#undef INSERISCI_PIANO1
#undef __SFC_INSERISCI_PIANO1
#undef INSERISCI_PIANO2
#undef __SFC_INSERISCI_PIANO2
#undef INSERISCI_PIANO3
#undef __SFC_INSERISCI_PIANO3

// Actions undefinitions
#undef __SFC_INS_0
#undef __SFC_INS_1
#undef __SFC_INS_2
#undef __SFC_INS_3





// FUNCTION
RICHIESTE PRELEVA_PIANO(
  BOOL EN, 
  BOOL *__ENO, 
  RICHIESTE CODA)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  RICHIESTE PRELEVA_PIANO = {0,0,0,{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return PRELEVA_PIANO;
  }
  CODA.DIM = (CODA.DIM - 1);
  CODA.BOT = ((20 == 0)?0:((CODA.BOT + 1) % 20));
  PRELEVA_PIANO = CODA;
  goto __end;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return PRELEVA_PIANO;
}


void PRENOTAZIONI_ESTERNE_init__(PRENOTAZIONI_ESTERNE *data__, BOOL retain) {
  __INIT_VAR(data__->PULS_0_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_EXTERNAL(GESTIONEPIANI,INFO,data__->INFO,retain)
  __INIT_EXTERNAL(RICHIESTE,RICHIESTE_SALITA,data__->RICHIESTE_SALITA,retain)
  __INIT_EXTERNAL(RICHIESTE,RICHIESTE_DISCESA,data__->RICHIESTE_DISCESA,retain)
  __INIT_VAR(data__->PULS_1_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PULS_2_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PULS_3_E,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 5;
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
  data__->__nb_transitions = 8;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define PRENOTAZIONE_ESTERNA __step_list[0]
#define __SFC_PRENOTAZIONE_ESTERNA 0
#define PRENOTA0 __step_list[1]
#define __SFC_PRENOTA0 1
#define PRENOTA1 __step_list[2]
#define __SFC_PRENOTA1 2
#define PRENOTA2 __step_list[3]
#define __SFC_PRENOTA2 3
#define PRENOTA3 __step_list[4]
#define __SFC_PRENOTA3 4

// Actions definitions
#define __SFC_INS_0 0
#define __SFC_INS_1 1
#define __SFC_INS_2 2
#define __SFC_INS_3 3

// Code part
void PRENOTAZIONI_ESTERNE_body__(PRENOTAZIONI_ESTERNE *data__) {
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
  if (__GET_VAR(data__->PRENOTAZIONE_ESTERNA.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->PULS_0_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->PULS_0_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 0)));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->PRENOTA0.X)) {
    __SET_VAR(data__->,__transition_list[1],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,1);
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->PRENOTAZIONE_ESTERNA.X)) {
    __SET_VAR(data__->,__transition_list[2],,(__GET_VAR(data__->PULS_1_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,(__GET_VAR(data__->PULS_1_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 1)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->PRENOTA1.X)) {
    __SET_VAR(data__->,__transition_list[3],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,1);
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->PRENOTAZIONE_ESTERNA.X)) {
    __SET_VAR(data__->,__transition_list[4],,(__GET_VAR(data__->PULS_2_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 2)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,(__GET_VAR(data__->PULS_2_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 2)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->PRENOTA2.X)) {
    __SET_VAR(data__->,__transition_list[5],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,1);
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->PRENOTAZIONE_ESTERNA.X)) {
    __SET_VAR(data__->,__transition_list[6],,(__GET_VAR(data__->PULS_3_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 3)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,(__GET_VAR(data__->PULS_3_E,) && (__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) != 3)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->PRENOTA3.X)) {
    __SET_VAR(data__->,__transition_list[7],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,1);
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PRENOTA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,PRENOTA1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PRENOTA2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PRENOTA3.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PRENOTA0.X,,1);
    data__->PRENOTA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,1);
    data__->PRENOTAZIONE_ESTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PRENOTA1.X,,1);
    data__->PRENOTA1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,1);
    data__->PRENOTAZIONE_ESTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PRENOTA2.X,,1);
    data__->PRENOTA2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,1);
    data__->PRENOTAZIONE_ESTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PRENOTA3.X,,1);
    data__->PRENOTA3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PRENOTAZIONE_ESTERNA.X,,1);
    data__->PRENOTAZIONE_ESTERNA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // PRENOTA0 action associations
  {
    char active = __GET_VAR(data__->PRENOTA0.X);
    char activated = active && !data__->PRENOTA0.prev_state;
    char desactivated = !active && data__->PRENOTA0.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_0].state,,0);};

  }

  // PRENOTA1 action associations
  {
    char active = __GET_VAR(data__->PRENOTA1.X);
    char activated = active && !data__->PRENOTA1.prev_state;
    char desactivated = !active && data__->PRENOTA1.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_1].state,,0);};

  }

  // PRENOTA2 action associations
  {
    char active = __GET_VAR(data__->PRENOTA2.X);
    char activated = active && !data__->PRENOTA2.prev_state;
    char desactivated = !active && data__->PRENOTA2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_2].state,,0);};

  }

  // PRENOTA3 action associations
  {
    char active = __GET_VAR(data__->PRENOTA3.X);
    char activated = active && !data__->PRENOTA3.prev_state;
    char desactivated = !active && data__->PRENOTA3.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_INS_3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_INS_3].state,,0);};

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
  if(__GET_VAR(data__->__action_list[__SFC_INS_0].state)) {
    __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,INSERISCI_PIANO_DISCESA(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,),
      (SINT)0));
  }

  if(__GET_VAR(data__->__action_list[__SFC_INS_1].state)) {
    if ((__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) < 1)) {
      __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,INSERISCI_PIANO_SALITA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,),
        (SINT)1));
    } else {
      __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,INSERISCI_PIANO_DISCESA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,),
        (SINT)1));
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_INS_2].state)) {
    if ((__GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE) < 2)) {
      __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,INSERISCI_PIANO_SALITA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,),
        (SINT)2));
    } else {
      __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,INSERISCI_PIANO_DISCESA(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,),
        (SINT)2));
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_INS_3].state)) {
    __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,INSERISCI_PIANO_SALITA(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,),
      (SINT)3));
  }



  goto __end;

__end:
  return;
} // PRENOTAZIONI_ESTERNE_body__() 

// Steps undefinitions
#undef PRENOTAZIONE_ESTERNA
#undef __SFC_PRENOTAZIONE_ESTERNA
#undef PRENOTA0
#undef __SFC_PRENOTA0
#undef PRENOTA1
#undef __SFC_PRENOTA1
#undef PRENOTA2
#undef __SFC_PRENOTA2
#undef PRENOTA3
#undef __SFC_PRENOTA3

// Actions undefinitions
#undef __SFC_INS_0
#undef __SFC_INS_1
#undef __SFC_INS_2
#undef __SFC_INS_3





void GESTIONE_MOTORE_init__(GESTIONE_MOTORE *data__, BOOL retain) {
  __INIT_VAR(data__->ACTUATOR,0,retain)
  __INIT_VAR(data__->PORTE,0,retain)
  __INIT_VAR(data__->SENSOR_PORTE,0,retain)
  __INIT_EXTERNAL(BOOL,FLAG,data__->FLAG,retain)
  __INIT_EXTERNAL(GESTIONEPIANI,INFO,data__->INFO,retain)
  __INIT_EXTERNAL(RICHIESTE,RICHIESTE_SALITA,data__->RICHIESTE_SALITA,retain)
  __INIT_EXTERNAL(RICHIESTE,RICHIESTE_DISCESA,data__->RICHIESTE_DISCESA,retain)
  UINT i;
  data__->__nb_steps = 6;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 7;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 7;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define ATTESA __step_list[0]
#define __SFC_ATTESA 0
#define SALI __step_list[1]
#define __SFC_SALI 1
#define PRELEVA_SALITA __step_list[2]
#define __SFC_PRELEVA_SALITA 2
#define APRI __step_list[3]
#define __SFC_APRI 3
#define SCENDI __step_list[4]
#define __SFC_SCENDI 4
#define PRELEVA_DISCESA __step_list[5]
#define __SFC_PRELEVA_DISCESA 5

// Actions definitions
#define __SFC_CHECK 0
#define __SFC_SALI_INLINE1 1
#define __SFC_PRELEVA_SALITA_INLINE3 2
#define __SFC_SCENDI_INLINE2 3
#define __SFC_PRELEVA_DISCESA_INLINE4 4
#define __SFC_FLAG 5
#define __SFC_PORTE 6

// Code part
void GESTIONE_MOTORE_body__(GESTIONE_MOTORE *data__) {
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
  if (__GET_VAR(data__->ATTESA.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_EXTERNAL(data__->INFO,.DIR) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_EXTERNAL(data__->INFO,.DIR) == 1));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->SALI.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_EXTERNAL(data__->RICHIESTE_SALITA,.QUEUE.table[(__GET_EXTERNAL(data__->RICHIESTE_SALITA,.BOT)) - (0)]) == __GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_EXTERNAL(data__->RICHIESTE_SALITA,.QUEUE.table[(__GET_EXTERNAL(data__->RICHIESTE_SALITA,.BOT)) - (0)]) == __GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->PRELEVA_SALITA.X)) {
    __SET_VAR(data__->,__transition_list[2],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,1);
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->APRI.X)) {
    __SET_VAR(data__->,__transition_list[3],,!(__GET_VAR(data__->SENSOR_PORTE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!(__GET_VAR(data__->SENSOR_PORTE,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->ATTESA.X)) {
    __SET_VAR(data__->,__transition_list[4],,(__GET_EXTERNAL(data__->INFO,.DIR) == -1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,(__GET_EXTERNAL(data__->INFO,.DIR) == -1));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->SCENDI.X)) {
    __SET_VAR(data__->,__transition_list[5],,(__GET_EXTERNAL(data__->RICHIESTE_DISCESA,.QUEUE.table[(__GET_EXTERNAL(data__->RICHIESTE_DISCESA,.BOT)) - (0)]) == __GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,(__GET_EXTERNAL(data__->RICHIESTE_DISCESA,.QUEUE.table[(__GET_EXTERNAL(data__->RICHIESTE_DISCESA,.BOT)) - (0)]) == __GET_EXTERNAL(data__->INFO,.PIANO_CORRENTE)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->PRELEVA_DISCESA.X)) {
    __SET_VAR(data__->,__transition_list[6],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,1);
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,ATTESA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,SALI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,PRELEVA_SALITA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,APRI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,ATTESA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,SCENDI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PRELEVA_DISCESA.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,SALI.X,,1);
    data__->SALI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PRELEVA_SALITA.X,,1);
    data__->PRELEVA_SALITA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,APRI.X,,1);
    data__->APRI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,ATTESA.X,,1);
    data__->ATTESA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,SCENDI.X,,1);
    data__->SCENDI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PRELEVA_DISCESA.X,,1);
    data__->PRELEVA_DISCESA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,APRI.X,,1);
    data__->APRI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // ATTESA action associations
  {
    char active = __GET_VAR(data__->ATTESA.X);
    char activated = active && !data__->ATTESA.prev_state;
    char desactivated = !active && data__->ATTESA.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CHECK].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CHECK].state,,0);};

  }

  // SALI action associations
  {
    char active = __GET_VAR(data__->SALI.X);
    char activated = active && !data__->SALI.prev_state;
    char desactivated = !active && data__->SALI.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SALI_INLINE1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SALI_INLINE1].state,,0);};

    if (active)       {data__->__action_list[__SFC_FLAG].reset = 1;}

  }

  // PRELEVA_SALITA action associations
  {
    char active = __GET_VAR(data__->PRELEVA_SALITA.X);
    char activated = active && !data__->PRELEVA_SALITA.prev_state;
    char desactivated = !active && data__->PRELEVA_SALITA.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PRELEVA_SALITA_INLINE3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PRELEVA_SALITA_INLINE3].state,,0);};

  }

  // APRI action associations
  {
    char active = __GET_VAR(data__->APRI.X);
    char activated = active && !data__->APRI.prev_state;
    char desactivated = !active && data__->APRI.prev_state;

    if (active && __time_cmp(data__->APRI.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,PORTE,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,PORTE,,0);};

    if (active)       {data__->__action_list[__SFC_FLAG].set = 1;}

  }

  // SCENDI action associations
  {
    char active = __GET_VAR(data__->SCENDI.X);
    char activated = active && !data__->SCENDI.prev_state;
    char desactivated = !active && data__->SCENDI.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SCENDI_INLINE2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SCENDI_INLINE2].state,,0);};

    if (active)       {data__->__action_list[__SFC_FLAG].reset = 1;}

  }

  // PRELEVA_DISCESA action associations
  {
    char active = __GET_VAR(data__->PRELEVA_DISCESA.X);
    char activated = active && !data__->PRELEVA_DISCESA.prev_state;
    char desactivated = !active && data__->PRELEVA_DISCESA.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PRELEVA_DISCESA_INLINE4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PRELEVA_DISCESA_INLINE4].state,,0);};

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
  if (data__->__action_list[__SFC_FLAG].reset) {
    __SET_EXTERNAL(data__->,FLAG,,0);
  }
  else if (data__->__action_list[__SFC_FLAG].set) {
    __SET_EXTERNAL(data__->,FLAG,,1);
  }
  if (data__->__action_list[__SFC_PORTE].reset) {
    __SET_VAR(data__->,PORTE,,0);
  }
  else if (data__->__action_list[__SFC_PORTE].set) {
    __SET_VAR(data__->,PORTE,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_CHECK].state)) {
    while (1) {
      if (((__GET_EXTERNAL(data__->INFO,.DIR) == 1) && (__GET_EXTERNAL(data__->RICHIESTE_SALITA,.DIM) != 0))) {
        __SET_EXTERNAL(data__->,INFO,.DIR,1);
      } else if (((__GET_EXTERNAL(data__->INFO,.DIR) == -1) && (__GET_EXTERNAL(data__->RICHIESTE_DISCESA,.DIM) != 0))) {
        __SET_EXTERNAL(data__->,INFO,.DIR,-1);
      } else if ((__GET_EXTERNAL(data__->RICHIESTE_SALITA,.DIM) != 0)) {
        __SET_EXTERNAL(data__->,INFO,.DIR,1);
      } else if ((__GET_EXTERNAL(data__->RICHIESTE_DISCESA,.DIM) != 0)) {
        __SET_EXTERNAL(data__->,INFO,.DIR,-1);
      } else {
        __SET_EXTERNAL(data__->,INFO,.DIR,0);
      };
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_SALI_INLINE1].state)) {
    __SET_VAR(data__->,ACTUATOR,,1);
  }

  if(__GET_VAR(data__->__action_list[__SFC_PRELEVA_SALITA_INLINE3].state)) {
    __SET_EXTERNAL(data__->,RICHIESTE_SALITA,,PRELEVA_PIANO(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_SALITA,)));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SCENDI_INLINE2].state)) {
    __SET_VAR(data__->,ACTUATOR,,-1);
  }

  if(__GET_VAR(data__->__action_list[__SFC_PRELEVA_DISCESA_INLINE4].state)) {
    __SET_EXTERNAL(data__->,RICHIESTE_DISCESA,,PRELEVA_PIANO(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (RICHIESTE)__GET_EXTERNAL(data__->RICHIESTE_DISCESA,)));
  }



  goto __end;

__end:
  return;
} // GESTIONE_MOTORE_body__() 

// Steps undefinitions
#undef ATTESA
#undef __SFC_ATTESA
#undef SALI
#undef __SFC_SALI
#undef PRELEVA_SALITA
#undef __SFC_PRELEVA_SALITA
#undef APRI
#undef __SFC_APRI
#undef SCENDI
#undef __SFC_SCENDI
#undef PRELEVA_DISCESA
#undef __SFC_PRELEVA_DISCESA

// Actions undefinitions
#undef __SFC_CHECK
#undef __SFC_SALI_INLINE1
#undef __SFC_PRELEVA_SALITA_INLINE3
#undef __SFC_SCENDI_INLINE2
#undef __SFC_PRELEVA_DISCESA_INLINE4
#undef __SFC_FLAG
#undef __SFC_PORTE





