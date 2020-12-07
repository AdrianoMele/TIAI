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





void MANAGEBUTTONLIGHTS_init__(MANAGEBUTTONLIGHTS *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,STARTBUTTON,data__->STARTBUTTON,retain)
  __INIT_EXTERNAL(BOOL,RESETBUTTON,data__->RESETBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STOPBUTTON,data__->STOPBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STOPINTERNAL,data__->STOPINTERNAL,retain)
  __INIT_EXTERNAL(BOOL,STARTLIGHT,data__->STARTLIGHT,retain)
  __INIT_EXTERNAL(BOOL,RESETLIGHT,data__->RESETLIGHT,retain)
  __INIT_EXTERNAL(BOOL,STOPLIGHT,data__->STOPLIGHT,retain)
  __INIT_EXTERNAL(BOOL,EMERGENCYSTOP,data__->EMERGENCYSTOP,retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
}

// Code part
void MANAGEBUTTONLIGHTS_body__(MANAGEBUTTONLIGHTS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_EXTERNAL(data__->STARTBUTTON,));
  R_TRIG_body__(&data__->R_TRIG1);
  if ((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG1.Q,))) {
    __SET_EXTERNAL(data__->,STARTLIGHT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_EXTERNAL(data__->STOPBUTTON,));
  F_TRIG_body__(&data__->F_TRIG1);
  if ((__GET_VAR(data__->F_TRIG1.Q,) || __GET_EXTERNAL(data__->STOPINTERNAL,))) {
    __SET_EXTERNAL(data__->,STOPLIGHT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_EXTERNAL(data__->STOPBUTTON,));
  F_TRIG_body__(&data__->F_TRIG2);
  if ((__GET_VAR(data__->F_TRIG2.Q,) || __GET_EXTERNAL(data__->STOPINTERNAL,))) {
    __SET_EXTERNAL(data__->,STARTLIGHT,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_EXTERNAL(data__->STARTBUTTON,));
  R_TRIG_body__(&data__->R_TRIG2);
  if ((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG2.Q,))) {
    __SET_EXTERNAL(data__->,STOPLIGHT,,__BOOL_LITERAL(FALSE));
  };
  __SET_EXTERNAL(data__->,RESETLIGHT,,(__GET_EXTERNAL(data__->STOPLIGHT,) && __GET_EXTERNAL(data__->RESETBUTTON,)));

  goto __end;

__end:
  return;
} // MANAGEBUTTONLIGHTS_body__() 





void DOUBLETRIG_init__(DOUBLETRIG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUX,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
}

// Code part
void DOUBLETRIG_body__(DOUBLETRIG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->IN,));
  F_TRIG_body__(&data__->F_TRIG1);
  if (__GET_VAR(data__->F_TRIG1.Q,)) {
    __SET_VAR(data__->,AUX,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->IN,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,OUT,,(__GET_VAR(data__->AUX,) && __GET_VAR(data__->R_TRIG1.Q,)));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->IN,));
  R_TRIG_body__(&data__->R_TRIG2);
  if ((__GET_VAR(data__->AUX,) && __GET_VAR(data__->R_TRIG2.Q,))) {
    __SET_VAR(data__->,AUX,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // DOUBLETRIG_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,HIGHSENS,data__->HIGHSENS,retain)
  __INIT_EXTERNAL(BOOL,LOWSENS,data__->LOWSENS,retain)
  __INIT_EXTERNAL(BOOL,PALLETSENS,data__->PALLETSENS,retain)
  __INIT_EXTERNAL(BOOL,LOADED,data__->LOADED,retain)
  __INIT_EXTERNAL(BOOL,LEFTENTRY,data__->LEFTENTRY,retain)
  __INIT_EXTERNAL(BOOL,LEFTEXIT,data__->LEFTEXIT,retain)
  __INIT_EXTERNAL(BOOL,RIGHTENTRY,data__->RIGHTENTRY,retain)
  __INIT_EXTERNAL(BOOL,RIGHTEXIT,data__->RIGHTEXIT,retain)
  __INIT_EXTERNAL(BOOL,STARTBUTTON,data__->STARTBUTTON,retain)
  __INIT_EXTERNAL(BOOL,RESETBUTTON,data__->RESETBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STOPBUTTON,data__->STOPBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STOPINTERNAL,data__->STOPINTERNAL,retain)
  __INIT_EXTERNAL(BOOL,RESETINTERNAL,data__->RESETINTERNAL,retain)
  __INIT_EXTERNAL(BOOL,STOPLIGHT,data__->STOPLIGHT,retain)
  __INIT_EXTERNAL(BOOL,STARTLIGHT,data__->STARTLIGHT,retain)
  __INIT_EXTERNAL(BOOL,EMERGENCYSTOP,data__->EMERGENCYSTOP,retain)
  __INIT_EXTERNAL(BOOL,AUTOMODE,data__->AUTOMODE,retain)
  __INIT_EXTERNAL(BOOL,CONVENTRY,data__->CONVENTRY,retain)
  __INIT_EXTERNAL(BOOL,LOAD,data__->LOAD,retain)
  __INIT_EXTERNAL(BOOL,UNLOAD,data__->UNLOAD,retain)
  __INIT_EXTERNAL(BOOL,TRANSFLEFT,data__->TRANSFLEFT,retain)
  __INIT_EXTERNAL(BOOL,TRANSFRIGHT,data__->TRANSFRIGHT,retain)
  __INIT_EXTERNAL(BOOL,CONVLEFT,data__->CONVLEFT,retain)
  __INIT_EXTERNAL(BOOL,CONVRIGHT,data__->CONVRIGHT,retain)
  __INIT_EXTERNAL(BOOL,WARNLIGHT,data__->WARNLIGHT,retain)
  __INIT_VAR(data__->PALLETMAXWAIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PROCESSING,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  R_TRIG_init__(&data__->R_TRIG6,retain);
  R_TRIG_init__(&data__->R_TRIG7,retain);
  R_TRIG_init__(&data__->R_TRIG8,retain);
  UINT i;
  data__->__nb_steps = 14;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 12;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 32;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define START __step_list[0]
#define __SFC_START 0
#define MOVECONVEYORS __step_list[1]
#define __SFC_MOVECONVEYORS 1
#define CHECKBOX __step_list[2]
#define __SFC_CHECKBOX 2
#define ERROR __step_list[3]
#define __SFC_ERROR 3
#define LOWBOX __step_list[4]
#define __SFC_LOWBOX 4
#define GORIGHT __step_list[5]
#define __SFC_GORIGHT 5
#define WAITRIGHT __step_list[6]
#define __SFC_WAITRIGHT 6
#define FAULT __step_list[7]
#define __SFC_FAULT 7
#define WAIT __step_list[8]
#define __SFC_WAIT 8
#define HIGHBOX __step_list[9]
#define __SFC_HIGHBOX 9
#define GOLEFT __step_list[10]
#define __SFC_GOLEFT 10
#define WAITLEFT __step_list[11]
#define __SFC_WAITLEFT 11
#define STOPPING __step_list[12]
#define __SFC_STOPPING 12
#define PENDINGJOB __step_list[13]
#define __SFC_PENDINGJOB 13

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_CONVLEFT 1
#define __SFC_CONVRIGHT 2
#define __SFC_STOPINTERNAL 3
#define __SFC_PROCESSING 4
#define __SFC_WARNLIGHT 5
#define __SFC_CONVENTRY 6
#define __SFC_LOAD 7
#define __SFC_PALLETMAXWAIT 8
#define __SFC_TRANSFRIGHT 9
#define __SFC_UNLOAD 10
#define __SFC_TRANSFLEFT 11

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
  if (__GET_VAR(data__->START.X)) {
    __SET_VAR(data__->,__transition_list[0],,((__GET_EXTERNAL(data__->STARTLIGHT,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)) && !(__GET_EXTERNAL(data__->LOADED,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,((__GET_EXTERNAL(data__->STARTLIGHT,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)) && !(__GET_EXTERNAL(data__->LOADED,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->MOVECONVEYORS.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_EXTERNAL(data__->PALLETSENS,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_EXTERNAL(data__->PALLETSENS,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->CHECKBOX.X)) {
    __SET_VAR(data__->,__transition_list[2],,(((__GET_VAR(data__->PALLETMAXWAIT,) || __GET_EXTERNAL(data__->LOADED,)) && !(__GET_EXTERNAL(data__->LOWSENS,))) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,(((__GET_VAR(data__->PALLETMAXWAIT,) || __GET_EXTERNAL(data__->LOADED,)) && !(__GET_EXTERNAL(data__->LOWSENS,))) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->ERROR.X)) {
    __SET_VAR(data__->,__transition_list[3],,!((__GET_EXTERNAL(data__->PALLETSENS,) || __GET_EXTERNAL(data__->LOADED,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!((__GET_EXTERNAL(data__->PALLETSENS,) || __GET_EXTERNAL(data__->LOADED,))));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->CHECKBOX.X)) {
    __SET_VAR(data__->,__transition_list[4],,((__GET_EXTERNAL(data__->LOWSENS,) && !(__GET_EXTERNAL(data__->HIGHSENS,))) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,((__GET_EXTERNAL(data__->LOWSENS,) && !(__GET_EXTERNAL(data__->HIGHSENS,))) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->LOWBOX.X)) {
    __SET_VAR(data__->,__transition_list[5],,(__GET_EXTERNAL(data__->LOADED,) && __GET_EXTERNAL(data__->AUTOMODE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,(__GET_EXTERNAL(data__->LOADED,) && __GET_EXTERNAL(data__->AUTOMODE,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->GORIGHT.X)) {
    __SET_VAR(data__->,__transition_list[6],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG1.Q,)) && !(__GET_EXTERNAL(data__->STOPLIGHT,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG1.Q,)) && !(__GET_EXTERNAL(data__->STOPLIGHT,))));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->GORIGHT.X)) {
    __SET_VAR(data__->,__transition_list[7],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_EXTERNAL(data__->STOPLIGHT,)) && __GET_VAR(data__->R_TRIG4.Q,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_EXTERNAL(data__->STOPLIGHT,)) && __GET_VAR(data__->R_TRIG4.Q,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->WAITRIGHT.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->R_TRIG5.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->R_TRIG5.Q,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->WAITRIGHT.X)) {
    __SET_VAR(data__->,__transition_list[9],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->FAULT.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_EXTERNAL(data__->EMERGENCYSTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_EXTERNAL(data__->EMERGENCYSTOP,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->GORIGHT.X)) {
    __SET_VAR(data__->,__transition_list[11],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->LOWBOX.X)) {
    __SET_VAR(data__->,__transition_list[12],,(__GET_EXTERNAL(data__->LOADED,) && !(__GET_EXTERNAL(data__->AUTOMODE,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,(__GET_EXTERNAL(data__->LOADED,) && !(__GET_EXTERNAL(data__->AUTOMODE,))));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->WAIT.X)) {
    __SET_VAR(data__->,__transition_list[13],,(!(__GET_EXTERNAL(data__->LOADED,)) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,(!(__GET_EXTERNAL(data__->LOADED,)) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->WAIT.X)) {
    __SET_VAR(data__->,__transition_list[14],,(__GET_EXTERNAL(data__->STOPLIGHT,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,(__GET_EXTERNAL(data__->STOPLIGHT,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->WAIT.X)) {
    __SET_VAR(data__->,__transition_list[15],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->CHECKBOX.X)) {
    __SET_VAR(data__->,__transition_list[16],,((__GET_EXTERNAL(data__->LOWSENS,) && __GET_EXTERNAL(data__->HIGHSENS,)) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,((__GET_EXTERNAL(data__->LOWSENS,) && __GET_EXTERNAL(data__->HIGHSENS,)) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->HIGHBOX.X)) {
    __SET_VAR(data__->,__transition_list[17],,(__GET_EXTERNAL(data__->LOADED,) && !(__GET_EXTERNAL(data__->AUTOMODE,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,(__GET_EXTERNAL(data__->LOADED,) && !(__GET_EXTERNAL(data__->AUTOMODE,))));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->HIGHBOX.X)) {
    __SET_VAR(data__->,__transition_list[18],,(__GET_EXTERNAL(data__->LOADED,) && __GET_EXTERNAL(data__->AUTOMODE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,(__GET_EXTERNAL(data__->LOADED,) && __GET_EXTERNAL(data__->AUTOMODE,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->GOLEFT.X)) {
    __SET_VAR(data__->,__transition_list[19],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG6.Q,)) && !(__GET_EXTERNAL(data__->STOPLIGHT,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG6.Q,)) && !(__GET_EXTERNAL(data__->STOPLIGHT,))));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->GOLEFT.X)) {
    __SET_VAR(data__->,__transition_list[20],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_EXTERNAL(data__->STOPLIGHT,)) && __GET_VAR(data__->R_TRIG7.Q,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,((__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_EXTERNAL(data__->STOPLIGHT,)) && __GET_VAR(data__->R_TRIG7.Q,)));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->WAITLEFT.X)) {
    __SET_VAR(data__->,__transition_list[21],,(__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG8.Q,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,(__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->R_TRIG8.Q,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->WAITLEFT.X)) {
    __SET_VAR(data__->,__transition_list[22],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->GOLEFT.X)) {
    __SET_VAR(data__->,__transition_list[23],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->CHECKBOX.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->MOVECONVEYORS.X)) {
    __SET_VAR(data__->,__transition_list[25],,(__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->F_TRIG1.Q,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,(__GET_EXTERNAL(data__->EMERGENCYSTOP,) && __GET_VAR(data__->F_TRIG1.Q,)));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STOPPING.X)) {
    __SET_VAR(data__->,__transition_list[26],,(__GET_VAR(data__->PROCESSING,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,(__GET_VAR(data__->PROCESSING,) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->PENDINGJOB.X)) {
    __SET_VAR(data__->,__transition_list[27],,(__GET_EXTERNAL(data__->EMERGENCYSTOP,) && (__GET_VAR(data__->R_TRIG2.Q,) || __GET_VAR(data__->R_TRIG3.Q,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,(__GET_EXTERNAL(data__->EMERGENCYSTOP,) && (__GET_VAR(data__->R_TRIG2.Q,) || __GET_VAR(data__->R_TRIG3.Q,))));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->PENDINGJOB.X)) {
    __SET_VAR(data__->,__transition_list[28],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STOPPING.X)) {
    __SET_VAR(data__->,__transition_list[29],,(!(__GET_VAR(data__->PROCESSING,)) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,(!(__GET_VAR(data__->PROCESSING,)) && __GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STOPPING.X)) {
    __SET_VAR(data__->,__transition_list[30],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->MOVECONVEYORS.X)) {
    __SET_VAR(data__->,__transition_list[31],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,!(__GET_EXTERNAL(data__->EMERGENCYSTOP,)));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,START.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,CHECKBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,ERROR.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,CHECKBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,LOWBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,GORIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,GORIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,WAITRIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,WAITRIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,FAULT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,GORIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,LOWBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,WAIT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,WAIT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,WAIT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,CHECKBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,HIGHBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,HIGHBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,GOLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,GOLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,WAITLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,WAITLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,GOLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,CHECKBOX.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STOPPING.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,PENDINGJOB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,PENDINGJOB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STOPPING.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STOPPING.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,1);
    data__->MOVECONVEYORS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,CHECKBOX.X,,1);
    data__->CHECKBOX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,ERROR.X,,1);
    data__->ERROR.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,LOWBOX.X,,1);
    data__->LOWBOX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,GORIGHT.X,,1);
    data__->GORIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,1);
    data__->MOVECONVEYORS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,WAITRIGHT.X,,1);
    data__->WAITRIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,WAIT.X,,1);
    data__->WAIT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,1);
    data__->MOVECONVEYORS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,HIGHBOX.X,,1);
    data__->HIGHBOX.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,WAIT.X,,1);
    data__->WAIT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,GOLEFT.X,,1);
    data__->GOLEFT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,MOVECONVEYORS.X,,1);
    data__->MOVECONVEYORS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,WAITLEFT.X,,1);
    data__->WAITLEFT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STOPPING.X,,1);
    data__->STOPPING.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,PENDINGJOB.X,,1);
    data__->PENDINGJOB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,START.X,,1);
    data__->START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,FAULT.X,,1);
    data__->FAULT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // START action associations
  {
    char active = __GET_VAR(data__->START.X);
    char activated = active && !data__->START.prev_state;
    char desactivated = !active && data__->START.prev_state;

    if (active)       {data__->__action_list[__SFC_CONVLEFT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_CONVRIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_STOPINTERNAL].reset = 1;}

    if (active)       {data__->__action_list[__SFC_PROCESSING].reset = 1;}

    if (active)       {data__->__action_list[__SFC_WARNLIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // MOVECONVEYORS action associations
  {
    char active = __GET_VAR(data__->MOVECONVEYORS.X);
    char activated = active && !data__->MOVECONVEYORS.prev_state;
    char desactivated = !active && data__->MOVECONVEYORS.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,CONVENTRY,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,CONVENTRY,,0);};

    if (active)       {__SET_EXTERNAL(data__->,LOAD,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,LOAD,,0);};

    if (active)       {data__->__action_list[__SFC_CONVLEFT].set = 1;}

    if (active)       {data__->__action_list[__SFC_CONVRIGHT].set = 1;}

  }

  // CHECKBOX action associations
  {
    char active = __GET_VAR(data__->CHECKBOX.X);
    char activated = active && !data__->CHECKBOX.prev_state;
    char desactivated = !active && data__->CHECKBOX.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,CONVENTRY,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,CONVENTRY,,0);};

    if (active)       {__SET_EXTERNAL(data__->,LOAD,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,LOAD,,0);};

    if (active)       {data__->__action_list[__SFC_PROCESSING].reset = 1;}

    if (active && __time_cmp(data__->CHECKBOX.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,PALLETMAXWAIT,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,PALLETMAXWAIT,,0);};

  }

  // ERROR action associations
  {
    char active = __GET_VAR(data__->ERROR.X);
    char activated = active && !data__->ERROR.prev_state;
    char desactivated = !active && data__->ERROR.prev_state;

    if (active)       {data__->__action_list[__SFC_WARNLIGHT].set = 1;}

    if (active)       {data__->__action_list[__SFC_STOPINTERNAL].set = 1;}

  }

  // LOWBOX action associations
  {
    char active = __GET_VAR(data__->LOWBOX.X);
    char activated = active && !data__->LOWBOX.prev_state;
    char desactivated = !active && data__->LOWBOX.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,CONVENTRY,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,CONVENTRY,,0);};

    if (active)       {__SET_EXTERNAL(data__->,LOAD,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,LOAD,,0);};

  }

  // GORIGHT action associations
  {
    char active = __GET_VAR(data__->GORIGHT.X);
    char activated = active && !data__->GORIGHT.prev_state;
    char desactivated = !active && data__->GORIGHT.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TRANSFRIGHT,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TRANSFRIGHT,,0);};

    if (active)       {data__->__action_list[__SFC_PROCESSING].set = 1;}

  }

  // FAULT action associations
  {
    char active = __GET_VAR(data__->FAULT.X);
    char activated = active && !data__->FAULT.prev_state;
    char desactivated = !active && data__->FAULT.prev_state;

    if (active)       {data__->__action_list[__SFC_LOAD].reset = 1;}

    if (active)       {data__->__action_list[__SFC_UNLOAD].reset = 1;}

    if (active)       {data__->__action_list[__SFC_CONVLEFT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_CONVRIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_CONVENTRY].reset = 1;}

    if (active)       {data__->__action_list[__SFC_STOPINTERNAL].set = 1;}

    if (active)       {data__->__action_list[__SFC_WARNLIGHT].set = 1;}

  }

  // HIGHBOX action associations
  {
    char active = __GET_VAR(data__->HIGHBOX.X);
    char activated = active && !data__->HIGHBOX.prev_state;
    char desactivated = !active && data__->HIGHBOX.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,CONVENTRY,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,CONVENTRY,,0);};

    if (active)       {__SET_EXTERNAL(data__->,LOAD,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,LOAD,,0);};

  }

  // GOLEFT action associations
  {
    char active = __GET_VAR(data__->GOLEFT.X);
    char activated = active && !data__->GOLEFT.prev_state;
    char desactivated = !active && data__->GOLEFT.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TRANSFLEFT,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TRANSFLEFT,,0);};

    if (active)       {data__->__action_list[__SFC_PROCESSING].set = 1;}

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
  if (data__->__action_list[__SFC_CONVLEFT].reset) {
    __SET_EXTERNAL(data__->,CONVLEFT,,0);
  }
  else if (data__->__action_list[__SFC_CONVLEFT].set) {
    __SET_EXTERNAL(data__->,CONVLEFT,,1);
  }
  if (data__->__action_list[__SFC_CONVRIGHT].reset) {
    __SET_EXTERNAL(data__->,CONVRIGHT,,0);
  }
  else if (data__->__action_list[__SFC_CONVRIGHT].set) {
    __SET_EXTERNAL(data__->,CONVRIGHT,,1);
  }
  if (data__->__action_list[__SFC_STOPINTERNAL].reset) {
    __SET_EXTERNAL(data__->,STOPINTERNAL,,0);
  }
  else if (data__->__action_list[__SFC_STOPINTERNAL].set) {
    __SET_EXTERNAL(data__->,STOPINTERNAL,,1);
  }
  if (data__->__action_list[__SFC_PROCESSING].reset) {
    __SET_VAR(data__->,PROCESSING,,0);
  }
  else if (data__->__action_list[__SFC_PROCESSING].set) {
    __SET_VAR(data__->,PROCESSING,,1);
  }
  if (data__->__action_list[__SFC_WARNLIGHT].reset) {
    __SET_EXTERNAL(data__->,WARNLIGHT,,0);
  }
  else if (data__->__action_list[__SFC_WARNLIGHT].set) {
    __SET_EXTERNAL(data__->,WARNLIGHT,,1);
  }
  if (data__->__action_list[__SFC_CONVENTRY].reset) {
    __SET_EXTERNAL(data__->,CONVENTRY,,0);
  }
  else if (data__->__action_list[__SFC_CONVENTRY].set) {
    __SET_EXTERNAL(data__->,CONVENTRY,,1);
  }
  if (data__->__action_list[__SFC_LOAD].reset) {
    __SET_EXTERNAL(data__->,LOAD,,0);
  }
  else if (data__->__action_list[__SFC_LOAD].set) {
    __SET_EXTERNAL(data__->,LOAD,,1);
  }
  if (data__->__action_list[__SFC_PALLETMAXWAIT].reset) {
    __SET_VAR(data__->,PALLETMAXWAIT,,0);
  }
  else if (data__->__action_list[__SFC_PALLETMAXWAIT].set) {
    __SET_VAR(data__->,PALLETMAXWAIT,,1);
  }
  if (data__->__action_list[__SFC_TRANSFRIGHT].reset) {
    __SET_EXTERNAL(data__->,TRANSFRIGHT,,0);
  }
  else if (data__->__action_list[__SFC_TRANSFRIGHT].set) {
    __SET_EXTERNAL(data__->,TRANSFRIGHT,,1);
  }
  if (data__->__action_list[__SFC_UNLOAD].reset) {
    __SET_EXTERNAL(data__->,UNLOAD,,0);
  }
  else if (data__->__action_list[__SFC_UNLOAD].set) {
    __SET_EXTERNAL(data__->,UNLOAD,,1);
  }
  if (data__->__action_list[__SFC_TRANSFLEFT].reset) {
    __SET_EXTERNAL(data__->,TRANSFLEFT,,0);
  }
  else if (data__->__action_list[__SFC_TRANSFLEFT].set) {
    __SET_EXTERNAL(data__->,TRANSFLEFT,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->R_TRIG1.,CLK,,__GET_EXTERNAL(data__->RIGHTENTRY,));
    R_TRIG_body__(&data__->R_TRIG1);
    __SET_VAR(data__->F_TRIG1.,CLK,,__GET_EXTERNAL(data__->STOPBUTTON,));
    F_TRIG_body__(&data__->F_TRIG1);
    __SET_VAR(data__->R_TRIG2.,CLK,,__GET_EXTERNAL(data__->LEFTEXIT,));
    R_TRIG_body__(&data__->R_TRIG2);
    __SET_VAR(data__->R_TRIG3.,CLK,,__GET_EXTERNAL(data__->RIGHTEXIT,));
    R_TRIG_body__(&data__->R_TRIG3);
    __SET_VAR(data__->R_TRIG4.,CLK,,__GET_EXTERNAL(data__->RIGHTENTRY,));
    R_TRIG_body__(&data__->R_TRIG4);
    __SET_VAR(data__->R_TRIG5.,CLK,,__GET_EXTERNAL(data__->RIGHTEXIT,));
    R_TRIG_body__(&data__->R_TRIG5);
    __SET_VAR(data__->R_TRIG6.,CLK,,__GET_EXTERNAL(data__->LEFTENTRY,));
    R_TRIG_body__(&data__->R_TRIG6);
    __SET_VAR(data__->R_TRIG7.,CLK,,__GET_EXTERNAL(data__->LEFTENTRY,));
    R_TRIG_body__(&data__->R_TRIG7);
    __SET_VAR(data__->R_TRIG8.,CLK,,__GET_EXTERNAL(data__->LEFTEXIT,));
    R_TRIG_body__(&data__->R_TRIG8);
  }



  goto __end;

__end:
  return;
} // MAIN_body__() 

// Steps undefinitions
#undef START
#undef __SFC_START
#undef MOVECONVEYORS
#undef __SFC_MOVECONVEYORS
#undef CHECKBOX
#undef __SFC_CHECKBOX
#undef ERROR
#undef __SFC_ERROR
#undef LOWBOX
#undef __SFC_LOWBOX
#undef GORIGHT
#undef __SFC_GORIGHT
#undef WAITRIGHT
#undef __SFC_WAITRIGHT
#undef FAULT
#undef __SFC_FAULT
#undef WAIT
#undef __SFC_WAIT
#undef HIGHBOX
#undef __SFC_HIGHBOX
#undef GOLEFT
#undef __SFC_GOLEFT
#undef WAITLEFT
#undef __SFC_WAITLEFT
#undef STOPPING
#undef __SFC_STOPPING
#undef PENDINGJOB
#undef __SFC_PENDINGJOB

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_CONVLEFT
#undef __SFC_CONVRIGHT
#undef __SFC_STOPINTERNAL
#undef __SFC_PROCESSING
#undef __SFC_WARNLIGHT
#undef __SFC_CONVENTRY
#undef __SFC_LOAD
#undef __SFC_PALLETMAXWAIT
#undef __SFC_TRANSFRIGHT
#undef __SFC_UNLOAD
#undef __SFC_TRANSFLEFT





void MANAGECOUNTERS_init__(MANAGECOUNTERS *data__, BOOL retain) {
  CTU_init__(&data__->CTU0,retain);
  CTU_init__(&data__->CTU1,retain);
  __INIT_EXTERNAL(BOOL,LEFTEXIT,data__->LEFTEXIT,retain)
  __INIT_EXTERNAL(BOOL,RIGHTEXIT,data__->RIGHTEXIT,retain)
  __INIT_EXTERNAL(BOOL,RESETBUTTON,data__->RESETBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STOPLIGHT,data__->STOPLIGHT,retain)
  __INIT_EXTERNAL(INT,COUNTHIGH,data__->COUNTHIGH,retain)
  __INIT_EXTERNAL(INT,COUNTLOW,data__->COUNTLOW,retain)
  __INIT_VAR(data__->PRESETVALUE,1000,retain)
  __INIT_EXTERNAL(BOOL,RESETINTERNAL,data__->RESETINTERNAL,retain)
  DOUBLETRIG_init__(&data__->DOUBLETRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->AND9_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
}

// Code part
void MANAGECOUNTERS_body__(MANAGECOUNTERS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_EXTERNAL(data__->LEFTEXIT,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,AND9_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_EXTERNAL(data__->RESETBUTTON,),
    (BOOL)__GET_EXTERNAL(data__->STOPLIGHT,)));
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->AND9_OUT,));
  __SET_VAR(data__->CTU0.,PV,,__GET_VAR(data__->PRESETVALUE,));
  CTU_body__(&data__->CTU0);
  __SET_EXTERNAL(data__->,COUNTHIGH,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->DOUBLETRIG1.,IN,,__GET_EXTERNAL(data__->RIGHTEXIT,));
  DOUBLETRIG_body__(&data__->DOUBLETRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->DOUBLETRIG1.OUT,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->AND9_OUT,));
  __SET_VAR(data__->CTU1.,PV,,__GET_VAR(data__->PRESETVALUE,));
  CTU_body__(&data__->CTU1);
  __SET_EXTERNAL(data__->,COUNTLOW,,__GET_VAR(data__->CTU1.CV,));

  goto __end;

__end:
  return;
} // MANAGECOUNTERS_body__() 





