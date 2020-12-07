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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->TIMEDUMMY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEDUMMY2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEDUMMY3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STEP201X,0,retain)
  __INIT_VAR(data__->STEP301X,0,retain)
  __INIT_VAR(data__->STARTCONV,0,retain)
  __INIT_VAR(data__->STARTPICK,0,retain)
  __INIT_VAR(data__->BOX,0,retain)
  __INIT_VAR(data__->STARTBUTTON,0,retain)
  __INIT_VAR(data__->EMERGENCYSTOP,1,retain)
  __INIT_VAR(data__->ROBOTXSETPOINT1,5,retain)
  __INIT_VAR(data__->ROBOTXSETPOINT2,4,retain)
  __INIT_VAR(data__->ROBOTZSETPOINT1,3,retain)
  __INIT_VAR(data__->ROBOTZSETPOINT2,2,retain)
  __INIT_VAR(data__->ROTATEROBOTCW1,0,retain)
  __INIT_VAR(data__->ROTATEROBOTCCW1,0,retain)
  __INIT_VAR(data__->ROTATEROBOTCW2,0,retain)
  __INIT_VAR(data__->ROTATEROBOTCCW2,0,retain)
  __INIT_VAR(data__->MOVECONVEYOR,0,retain)
  __INIT_VAR(data__->ROBOTGRAB1,0,retain)
  __INIT_VAR(data__->ROBOTGRAB2,0,retain)
  __INIT_VAR(data__->STARTLIGHT,0,retain)
  UINT i;
  data__->__nb_steps = 31;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[3].X,,1);
  __SET_VAR(data__->,__step_list[6].X,,1);
  __SET_VAR(data__->,__step_list[17].X,,1);
  __SET_VAR(data__->,__step_list[29].X,,1);
  data__->__nb_actions = 24;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 34;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define STEP3 __step_list[1]
#define __SFC_STEP3 1
#define STEP1 __step_list[2]
#define __SFC_STEP1 2
#define STEP100 __step_list[3]
#define __SFC_STEP100 3
#define STEP101 __step_list[4]
#define __SFC_STEP101 4
#define STEP102 __step_list[5]
#define __SFC_STEP102 5
#define STEP200 __step_list[6]
#define __SFC_STEP200 6
#define STEP201 __step_list[7]
#define __SFC_STEP201 7
#define STEP202 __step_list[8]
#define __SFC_STEP202 8
#define STEP203 __step_list[9]
#define __SFC_STEP203 9
#define STEP204 __step_list[10]
#define __SFC_STEP204 10
#define STEP205 __step_list[11]
#define __SFC_STEP205 11
#define STEP206 __step_list[12]
#define __SFC_STEP206 12
#define STEP207 __step_list[13]
#define __SFC_STEP207 13
#define STEP208 __step_list[14]
#define __SFC_STEP208 14
#define STEP209 __step_list[15]
#define __SFC_STEP209 15
#define D3 __step_list[16]
#define __SFC_D3 16
#define SEMAPHORE __step_list[17]
#define __SFC_SEMAPHORE 17
#define D1 __step_list[18]
#define __SFC_D1 18
#define D2 __step_list[19]
#define __SFC_D2 19
#define STEP302 __step_list[20]
#define __SFC_STEP302 20
#define STEP303 __step_list[21]
#define __SFC_STEP303 21
#define STEP304 __step_list[22]
#define __SFC_STEP304 22
#define STEP305 __step_list[23]
#define __SFC_STEP305 23
#define STEP306 __step_list[24]
#define __SFC_STEP306 24
#define STEP307 __step_list[25]
#define __SFC_STEP307 25
#define STEP308 __step_list[26]
#define __SFC_STEP308 26
#define STEP309 __step_list[27]
#define __SFC_STEP309 27
#define STEP301 __step_list[28]
#define __SFC_STEP301 28
#define STEP300 __step_list[29]
#define __SFC_STEP300 29
#define D4 __step_list[30]
#define __SFC_D4 30

// Actions definitions
#define __SFC_RESETROBOT 0
#define __SFC_GOUP 1
#define __SFC_GOFWD 2
#define __SFC_GOMIDDLE 3
#define __SFC_UNLOAD1 4
#define __SFC_GOUP2 5
#define __SFC_GOFWD2 6
#define __SFC_GOMIDDLE2 7
#define __SFC_UNLOAD2 8
#define __SFC_STARTLIGHT 9
#define __SFC_TIMEDUMMY 10
#define __SFC_STARTCONV 11
#define __SFC_STARTPICK 12
#define __SFC_MOVECONVEYOR 13
#define __SFC_STEP201X 14
#define __SFC_ROTATEROBOTCCW1 15
#define __SFC_TIMEDUMMY2 16
#define __SFC_ROBOTGRAB1 17
#define __SFC_ROTATEROBOTCW1 18
#define __SFC_ROTATEROBOTCW2 19
#define __SFC_TIMEDUMMY3 20
#define __SFC_ROBOTGRAB2 21
#define __SFC_ROTATEROBOTCCW2 22
#define __SFC_STEP301X 23

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
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
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->STARTBUTTON,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->STARTBUTTON,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->TIMEDUMMY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->TIMEDUMMY,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP100.X)) {
    __SET_VAR(data__->,__transition_list[3],,(__GET_VAR(data__->STARTCONV,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,(__GET_VAR(data__->STARTCONV,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP101.X)) {
    __SET_VAR(data__->,__transition_list[4],,(__GET_VAR(data__->BOX,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,(__GET_VAR(data__->BOX,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->STEP102.X)) {
    __SET_VAR(data__->,__transition_list[5],,(!(__GET_VAR(data__->BOX,)) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,(!(__GET_VAR(data__->BOX,)) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP102.X)) {
    __SET_VAR(data__->,__transition_list[6],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->STEP101.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP200.X)) {
    __SET_VAR(data__->,__transition_list[8],,(__GET_VAR(data__->STARTPICK,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,(__GET_VAR(data__->STARTPICK,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP201.X) && __GET_VAR(data__->D1.X)) {
    __SET_VAR(data__->,__transition_list[9],,(__GET_VAR(data__->BOX,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,(__GET_VAR(data__->BOX,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP202.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->STEP203.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP204.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->STEP205.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP206.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP207.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->STEP208.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->TIMEDUMMY2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->TIMEDUMMY2,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP209.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->EMERGENCYSTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->EMERGENCYSTOP,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP209.X)) {
    __SET_VAR(data__->,__transition_list[18],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->D3.X)) {
    __SET_VAR(data__->,__transition_list[19],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->SEMAPHORE.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->STEP201X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->STEP201X,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->SEMAPHORE.X)) {
    __SET_VAR(data__->,__transition_list[21],,(!(__GET_VAR(data__->STEP201X,)) && __GET_VAR(data__->STEP301X,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,(!(__GET_VAR(data__->STEP201X,)) && __GET_VAR(data__->STEP301X,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->D2.X) && __GET_VAR(data__->STEP301.X)) {
    __SET_VAR(data__->,__transition_list[22],,(__GET_VAR(data__->BOX,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,(__GET_VAR(data__->BOX,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP302.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP303.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP304.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP305.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP306.X)) {
    __SET_VAR(data__->,__transition_list[27],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP307.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP308.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_VAR(data__->TIMEDUMMY3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->TIMEDUMMY3,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP309.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_VAR(data__->EMERGENCYSTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->EMERGENCYSTOP,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP309.X)) {
    __SET_VAR(data__->,__transition_list[31],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,!(__GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP300.X)) {
    __SET_VAR(data__->,__transition_list[32],,(__GET_VAR(data__->STARTPICK,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,(__GET_VAR(data__->STARTPICK,) && __GET_VAR(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->D4.X)) {
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
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP100.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP101.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP102.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP102.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP101.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP200.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP201.X,,0);
    __SET_VAR(data__->,D1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP202.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP203.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP204.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP205.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP206.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP207.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP208.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP209.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP209.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,D3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,SEMAPHORE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,SEMAPHORE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,D2.X,,0);
    __SET_VAR(data__->,STEP301.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP302.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP303.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP304.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP305.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP306.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP307.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP308.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP309.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP309.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP300.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,D4.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP101.X,,1);
    data__->STEP101.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP102.X,,1);
    data__->STEP102.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP101.X,,1);
    data__->STEP101.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP100.X,,1);
    data__->STEP100.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP100.X,,1);
    data__->STEP100.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP201.X,,1);
    data__->STEP201.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP202.X,,1);
    data__->STEP202.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP203.X,,1);
    data__->STEP203.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP204.X,,1);
    data__->STEP204.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP205.X,,1);
    data__->STEP205.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP206.X,,1);
    data__->STEP206.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP207.X,,1);
    data__->STEP207.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,D3.X,,1);
    data__->D3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP208.X,,1);
    data__->STEP208.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP209.X,,1);
    data__->STEP209.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP201.X,,1);
    data__->STEP201.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP200.X,,1);
    data__->STEP200.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,SEMAPHORE.X,,1);
    data__->SEMAPHORE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,D1.X,,1);
    data__->D1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,D2.X,,1);
    data__->D2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP302.X,,1);
    data__->STEP302.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP303.X,,1);
    data__->STEP303.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP304.X,,1);
    data__->STEP304.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP305.X,,1);
    data__->STEP305.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP306.X,,1);
    data__->STEP306.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP307.X,,1);
    data__->STEP307.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,D4.X,,1);
    data__->D4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP308.X,,1);
    data__->STEP308.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP309.X,,1);
    data__->STEP309.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP301.X,,1);
    data__->STEP301.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP300.X,,1);
    data__->STEP300.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP301.X,,1);
    data__->STEP301.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,SEMAPHORE.X,,1);
    data__->SEMAPHORE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_STARTLIGHT].reset = 1;}

  }

  // STEP3 action associations
  {
    char active = __GET_VAR(data__->STEP3.X);
    char activated = active && !data__->STEP3.prev_state;
    char desactivated = !active && data__->STEP3.prev_state;

    if (active)       {data__->__action_list[__SFC_STARTLIGHT].set = 1;}

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_RESETROBOT].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_RESETROBOT].state,,0);};

    if (active && __time_cmp(data__->STEP3.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY,,0);};

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_VAR(data__->,STARTCONV,,1);};
    if (desactivated) {__SET_VAR(data__->,STARTCONV,,0);};

    if (active)       {__SET_VAR(data__->,STARTPICK,,1);};
    if (desactivated) {__SET_VAR(data__->,STARTPICK,,0);};

  }

  // STEP101 action associations
  {
    char active = __GET_VAR(data__->STEP101.X);
    char activated = active && !data__->STEP101.prev_state;
    char desactivated = !active && data__->STEP101.prev_state;

    if (active)       {__SET_VAR(data__->,MOVECONVEYOR,,1);};
    if (desactivated) {__SET_VAR(data__->,MOVECONVEYOR,,0);};

  }

  // STEP201 action associations
  {
    char active = __GET_VAR(data__->STEP201.X);
    char activated = active && !data__->STEP201.prev_state;
    char desactivated = !active && data__->STEP201.prev_state;

    if (active)       {__SET_VAR(data__->,STEP201X,,1);};
    if (desactivated) {__SET_VAR(data__->,STEP201X,,0);};

  }

  // STEP202 action associations
  {
    char active = __GET_VAR(data__->STEP202.X);
    char activated = active && !data__->STEP202.prev_state;
    char desactivated = !active && data__->STEP202.prev_state;

    if (active && __time_cmp(data__->STEP202.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCCW1,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCCW1,,0);};

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_GOUP].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_GOUP].state,,0);};

    if (active && __time_cmp(data__->STEP202.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP203 action associations
  {
    char active = __GET_VAR(data__->STEP203.X);
    char activated = active && !data__->STEP203.prev_state;
    char desactivated = !active && data__->STEP203.prev_state;

    if (active && __time_cmp(data__->STEP203.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCCW1,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCCW1,,0);};

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_GOFWD].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_GOFWD].state,,0);};

    if (active && __time_cmp(data__->STEP203.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP204 action associations
  {
    char active = __GET_VAR(data__->STEP204.X);
    char activated = active && !data__->STEP204.prev_state;
    char desactivated = !active && data__->STEP204.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOMIDDLE].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOMIDDLE].state,,0);};

    if (activated) {
      data__->__action_list[__SFC_ROBOTGRAB1].set_remaining_time = __time_to_timespec(1, 500, 0, 0, 0, 0);
    }

    if (active && __time_cmp(data__->STEP204.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP205 action associations
  {
    char active = __GET_VAR(data__->STEP205.X);
    char activated = active && !data__->STEP205.prev_state;
    char desactivated = !active && data__->STEP205.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_GOUP].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_GOUP].state,,0);};

    if (active && __time_cmp(data__->STEP205.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP206 action associations
  {
    char active = __GET_VAR(data__->STEP206.X);
    char activated = active && !data__->STEP206.prev_state;
    char desactivated = !active && data__->STEP206.prev_state;

    if (active && __time_cmp(data__->STEP206.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCW1,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCW1,,0);};

    if (active && __time_cmp(data__->STEP206.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP207 action associations
  {
    char active = __GET_VAR(data__->STEP207.X);
    char activated = active && !data__->STEP207.prev_state;
    char desactivated = !active && data__->STEP207.prev_state;

    if (active && __time_cmp(data__->STEP207.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCW1,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCW1,,0);};

    if (active && __time_cmp(data__->STEP207.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP208 action associations
  {
    char active = __GET_VAR(data__->STEP208.X);
    char activated = active && !data__->STEP208.prev_state;
    char desactivated = !active && data__->STEP208.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_UNLOAD1].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_UNLOAD1].state,,0);};

    if (active && __time_cmp(data__->STEP208.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

  }

  // STEP209 action associations
  {
    char active = __GET_VAR(data__->STEP209.X);
    char activated = active && !data__->STEP209.prev_state;
    char desactivated = !active && data__->STEP209.prev_state;

    if (active)       {data__->__action_list[__SFC_ROBOTGRAB1].reset = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOUP].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOUP].state,,0);};

  }

  // STEP302 action associations
  {
    char active = __GET_VAR(data__->STEP302.X);
    char activated = active && !data__->STEP302.prev_state;
    char desactivated = !active && data__->STEP302.prev_state;

    if (active && __time_cmp(data__->STEP302.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCW2,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCW2,,0);};

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_GOUP2].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_GOUP2].state,,0);};

    if (active && __time_cmp(data__->STEP302.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP303 action associations
  {
    char active = __GET_VAR(data__->STEP303.X);
    char activated = active && !data__->STEP303.prev_state;
    char desactivated = !active && data__->STEP303.prev_state;

    if (active && __time_cmp(data__->STEP303.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCW2,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCW2,,0);};

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_GOFWD2].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_GOFWD2].state,,0);};

    if (active && __time_cmp(data__->STEP303.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP304 action associations
  {
    char active = __GET_VAR(data__->STEP304.X);
    char activated = active && !data__->STEP304.prev_state;
    char desactivated = !active && data__->STEP304.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOMIDDLE2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOMIDDLE2].state,,0);};

    if (activated) {
      data__->__action_list[__SFC_ROBOTGRAB2].set_remaining_time = __time_to_timespec(1, 500, 0, 0, 0, 0);
    }

    if (active && __time_cmp(data__->STEP304.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP305 action associations
  {
    char active = __GET_VAR(data__->STEP305.X);
    char activated = active && !data__->STEP305.prev_state;
    char desactivated = !active && data__->STEP305.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_GOUP2].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_GOUP2].state,,0);};

    if (active && __time_cmp(data__->STEP305.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP306 action associations
  {
    char active = __GET_VAR(data__->STEP306.X);
    char activated = active && !data__->STEP306.prev_state;
    char desactivated = !active && data__->STEP306.prev_state;

    if (active && __time_cmp(data__->STEP306.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCCW2,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCCW2,,0);};

    if (active && __time_cmp(data__->STEP306.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP307 action associations
  {
    char active = __GET_VAR(data__->STEP307.X);
    char activated = active && !data__->STEP307.prev_state;
    char desactivated = !active && data__->STEP307.prev_state;

    if (active && __time_cmp(data__->STEP307.T.value, __time_to_timespec(1, 200, 0, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,ROTATEROBOTCCW2,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,ROTATEROBOTCCW2,,0);};

    if (active && __time_cmp(data__->STEP307.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP308 action associations
  {
    char active = __GET_VAR(data__->STEP308.X);
    char activated = active && !data__->STEP308.prev_state;
    char desactivated = !active && data__->STEP308.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_UNLOAD2].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_UNLOAD2].state,,0);};

    if (active && __time_cmp(data__->STEP308.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // STEP309 action associations
  {
    char active = __GET_VAR(data__->STEP309.X);
    char activated = active && !data__->STEP309.prev_state;
    char desactivated = !active && data__->STEP309.prev_state;

    if (active)       {data__->__action_list[__SFC_ROBOTGRAB2].reset = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOUP2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOUP2].state,,0);};

  }

  // STEP301 action associations
  {
    char active = __GET_VAR(data__->STEP301.X);
    char activated = active && !data__->STEP301.prev_state;
    char desactivated = !active && data__->STEP301.prev_state;

    if (active)       {__SET_VAR(data__->,STEP301X,,1);};
    if (desactivated) {__SET_VAR(data__->,STEP301X,,0);};

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
  if (data__->__action_list[__SFC_STARTLIGHT].reset) {
    __SET_VAR(data__->,STARTLIGHT,,0);
  }
  else if (data__->__action_list[__SFC_STARTLIGHT].set) {
    __SET_VAR(data__->,STARTLIGHT,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY].reset) {
    __SET_VAR(data__->,TIMEDUMMY,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY].set) {
    __SET_VAR(data__->,TIMEDUMMY,,1);
  }
  if (data__->__action_list[__SFC_STARTCONV].reset) {
    __SET_VAR(data__->,STARTCONV,,0);
  }
  else if (data__->__action_list[__SFC_STARTCONV].set) {
    __SET_VAR(data__->,STARTCONV,,1);
  }
  if (data__->__action_list[__SFC_STARTPICK].reset) {
    __SET_VAR(data__->,STARTPICK,,0);
  }
  else if (data__->__action_list[__SFC_STARTPICK].set) {
    __SET_VAR(data__->,STARTPICK,,1);
  }
  if (data__->__action_list[__SFC_MOVECONVEYOR].reset) {
    __SET_VAR(data__->,MOVECONVEYOR,,0);
  }
  else if (data__->__action_list[__SFC_MOVECONVEYOR].set) {
    __SET_VAR(data__->,MOVECONVEYOR,,1);
  }
  if (data__->__action_list[__SFC_STEP201X].reset) {
    __SET_VAR(data__->,STEP201X,,0);
  }
  else if (data__->__action_list[__SFC_STEP201X].set) {
    __SET_VAR(data__->,STEP201X,,1);
  }
  if (data__->__action_list[__SFC_ROTATEROBOTCCW1].reset) {
    __SET_VAR(data__->,ROTATEROBOTCCW1,,0);
  }
  else if (data__->__action_list[__SFC_ROTATEROBOTCCW1].set) {
    __SET_VAR(data__->,ROTATEROBOTCCW1,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY2].reset) {
    __SET_VAR(data__->,TIMEDUMMY2,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY2].set) {
    __SET_VAR(data__->,TIMEDUMMY2,,1);
  }
  if (data__->__action_list[__SFC_ROBOTGRAB1].reset) {
    __SET_VAR(data__->,ROBOTGRAB1,,0);
  }
  else if (data__->__action_list[__SFC_ROBOTGRAB1].set) {
    __SET_VAR(data__->,ROBOTGRAB1,,1);
  }
  if (data__->__action_list[__SFC_ROTATEROBOTCW1].reset) {
    __SET_VAR(data__->,ROTATEROBOTCW1,,0);
  }
  else if (data__->__action_list[__SFC_ROTATEROBOTCW1].set) {
    __SET_VAR(data__->,ROTATEROBOTCW1,,1);
  }
  if (data__->__action_list[__SFC_ROTATEROBOTCW2].reset) {
    __SET_VAR(data__->,ROTATEROBOTCW2,,0);
  }
  else if (data__->__action_list[__SFC_ROTATEROBOTCW2].set) {
    __SET_VAR(data__->,ROTATEROBOTCW2,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY3].reset) {
    __SET_VAR(data__->,TIMEDUMMY3,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY3].set) {
    __SET_VAR(data__->,TIMEDUMMY3,,1);
  }
  if (data__->__action_list[__SFC_ROBOTGRAB2].reset) {
    __SET_VAR(data__->,ROBOTGRAB2,,0);
  }
  else if (data__->__action_list[__SFC_ROBOTGRAB2].set) {
    __SET_VAR(data__->,ROBOTGRAB2,,1);
  }
  if (data__->__action_list[__SFC_ROTATEROBOTCCW2].reset) {
    __SET_VAR(data__->,ROTATEROBOTCCW2,,0);
  }
  else if (data__->__action_list[__SFC_ROTATEROBOTCCW2].set) {
    __SET_VAR(data__->,ROTATEROBOTCCW2,,1);
  }
  if (data__->__action_list[__SFC_STEP301X].reset) {
    __SET_VAR(data__->,STEP301X,,0);
  }
  else if (data__->__action_list[__SFC_STEP301X].set) {
    __SET_VAR(data__->,STEP301X,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_RESETROBOT].state)) {
    __SET_VAR(data__->,ROBOTXSETPOINT1,,0);
    __SET_VAR(data__->,ROBOTXSETPOINT2,,0);
    __SET_VAR(data__->,ROBOTZSETPOINT1,,0);
    __SET_VAR(data__->,ROBOTZSETPOINT2,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOUP].state)) {
    __SET_VAR(data__->,ROBOTZSETPOINT1,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOFWD].state)) {
    __SET_VAR(data__->,ROBOTXSETPOINT1,,10);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOMIDDLE].state)) {
    __SET_VAR(data__->,ROBOTZSETPOINT1,,3);
  }

  if(__GET_VAR(data__->__action_list[__SFC_UNLOAD1].state)) {
    __SET_VAR(data__->,ROBOTZSETPOINT1,,15);
    __SET_VAR(data__->,ROBOTXSETPOINT1,,3);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOUP2].state)) {
    __SET_VAR(data__->,ROBOTZSETPOINT2,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOFWD2].state)) {
    __SET_VAR(data__->,ROBOTXSETPOINT2,,12);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOMIDDLE2].state)) {
    __SET_VAR(data__->,ROBOTZSETPOINT2,,3);
  }

  if(__GET_VAR(data__->__action_list[__SFC_UNLOAD2].state)) {
    __SET_VAR(data__->,ROBOTZSETPOINT2,,15);
    __SET_VAR(data__->,ROBOTXSETPOINT2,,3);
  }



  goto __end;

__end:
  return;
} // PROGRAM0_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef STEP3
#undef __SFC_STEP3
#undef STEP1
#undef __SFC_STEP1
#undef STEP100
#undef __SFC_STEP100
#undef STEP101
#undef __SFC_STEP101
#undef STEP102
#undef __SFC_STEP102
#undef STEP200
#undef __SFC_STEP200
#undef STEP201
#undef __SFC_STEP201
#undef STEP202
#undef __SFC_STEP202
#undef STEP203
#undef __SFC_STEP203
#undef STEP204
#undef __SFC_STEP204
#undef STEP205
#undef __SFC_STEP205
#undef STEP206
#undef __SFC_STEP206
#undef STEP207
#undef __SFC_STEP207
#undef STEP208
#undef __SFC_STEP208
#undef STEP209
#undef __SFC_STEP209
#undef D3
#undef __SFC_D3
#undef SEMAPHORE
#undef __SFC_SEMAPHORE
#undef D1
#undef __SFC_D1
#undef D2
#undef __SFC_D2
#undef STEP302
#undef __SFC_STEP302
#undef STEP303
#undef __SFC_STEP303
#undef STEP304
#undef __SFC_STEP304
#undef STEP305
#undef __SFC_STEP305
#undef STEP306
#undef __SFC_STEP306
#undef STEP307
#undef __SFC_STEP307
#undef STEP308
#undef __SFC_STEP308
#undef STEP309
#undef __SFC_STEP309
#undef STEP301
#undef __SFC_STEP301
#undef STEP300
#undef __SFC_STEP300
#undef D4
#undef __SFC_D4

// Actions undefinitions
#undef __SFC_RESETROBOT
#undef __SFC_GOUP
#undef __SFC_GOFWD
#undef __SFC_GOMIDDLE
#undef __SFC_UNLOAD1
#undef __SFC_GOUP2
#undef __SFC_GOFWD2
#undef __SFC_GOMIDDLE2
#undef __SFC_UNLOAD2
#undef __SFC_STARTLIGHT
#undef __SFC_TIMEDUMMY
#undef __SFC_STARTCONV
#undef __SFC_STARTPICK
#undef __SFC_MOVECONVEYOR
#undef __SFC_STEP201X
#undef __SFC_ROTATEROBOTCCW1
#undef __SFC_TIMEDUMMY2
#undef __SFC_ROBOTGRAB1
#undef __SFC_ROTATEROBOTCW1
#undef __SFC_ROTATEROBOTCW2
#undef __SFC_TIMEDUMMY3
#undef __SFC_ROBOTGRAB2
#undef __SFC_ROTATEROBOTCCW2
#undef __SFC_STEP301X





