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
  __INIT_VAR(data__->A_START,0,retain)
  __INIT_VAR(data__->S3X,0,retain)
  __INIT_VAR(data__->S3_BX,0,retain)
  __INIT_VAR(data__->S16X,0,retain)
  __INIT_VAR(data__->S16_BX,0,retain)
  __INIT_VAR(data__->A_TEMPO_SEMINA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B_TEMPO_SEMINA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->A_MOTORE_AVANTI,0,retain)
  __INIT_VAR(data__->A_MOTORE_DIETRO,0,retain)
  __INIT_VAR(data__->A_MOTORE_SINISTRA,0,retain)
  __INIT_VAR(data__->A_ANDATA,0,retain)
  __INIT_VAR(data__->A_RILASCIO,0,retain)
  __INIT_VAR(data__->A_DOCK_RICARICA,0,retain)
  __INIT_VAR(data__->B_START,0,retain)
  __INIT_VAR(data__->B_MOTORE_AVANTI,0,retain)
  __INIT_VAR(data__->B_MOTORE_DIETRO,0,retain)
  __INIT_VAR(data__->B_MOTORE_DESTRA,0,retain)
  __INIT_VAR(data__->B_DOCK_RICARICA,0,retain)
  __INIT_VAR(data__->B_ANDATA,0,retain)
  __INIT_VAR(data__->B_RILASCIO,0,retain)
  __INIT_VAR(data__->C_SENSOR,0,retain)
  __INIT_VAR(data__->D_SENSOR,0,retain)
  __INIT_VAR(data__->E_SENSOR,0,retain)
  __INIT_VAR(data__->F_SENSOR,0,retain)
  __INIT_VAR(data__->G_SX_SENSOR,0,retain)
  __INIT_VAR(data__->G_DX_SENSOR,0,retain)
  __INIT_VAR(data__->PRESSIONE_GIU,0,retain)
  __INIT_VAR(data__->PRESSIONE_MIN,0,retain)
  __INIT_VAR(data__->PRESSIONE_SU,0,retain)
  __INIT_VAR(data__->PRESSIONE_MAX,0,retain)
  __INIT_VAR(data__->PORTELLO_A_APRI,0,retain)
  __INIT_VAR(data__->PORTELLO_A_CHIUDI,0,retain)
  __INIT_VAR(data__->PORTELLO_A_APERTO,0,retain)
  __INIT_VAR(data__->PORTELLO_A_CHIUSO,0,retain)
  __INIT_VAR(data__->PORTELLO_B_CHIUSO,0,retain)
  __INIT_VAR(data__->PORTELLO_B_CHIUDI,0,retain)
  __INIT_VAR(data__->PORTELLO_B_APRI,0,retain)
  __INIT_VAR(data__->PORTELLO_B_APERTO,0,retain)
  __INIT_VAR(data__->SEMINA_A_OK,0,retain)
  __INIT_VAR(data__->SEMINA_B_OK,0,retain)
  UINT i;
  data__->__nb_steps = 63;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[28].X,,1);
  __SET_VAR(data__->,__step_list[43].X,,1);
  data__->__nb_actions = 24;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 62;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define S1 __step_list[0]
#define __SFC_S1 0
#define S2 __step_list[1]
#define __SFC_S2 1
#define S3 __step_list[2]
#define __SFC_S3 2
#define S4 __step_list[3]
#define __SFC_S4 3
#define S5 __step_list[4]
#define __SFC_S5 4
#define S6 __step_list[5]
#define __SFC_S6 5
#define S7 __step_list[6]
#define __SFC_S7 6
#define S8 __step_list[7]
#define __SFC_S8 7
#define S9 __step_list[8]
#define __SFC_S9 8
#define S10 __step_list[9]
#define __SFC_S10 9
#define S11 __step_list[10]
#define __SFC_S11 10
#define S12 __step_list[11]
#define __SFC_S12 11
#define S13 __step_list[12]
#define __SFC_S13 12
#define S14 __step_list[13]
#define __SFC_S14 13
#define S15 __step_list[14]
#define __SFC_S15 14
#define S16 __step_list[15]
#define __SFC_S16 15
#define S17 __step_list[16]
#define __SFC_S17 16
#define S18 __step_list[17]
#define __SFC_S18 17
#define S19 __step_list[18]
#define __SFC_S19 18
#define S20 __step_list[19]
#define __SFC_S20 19
#define S21 __step_list[20]
#define __SFC_S21 20
#define S22 __step_list[21]
#define __SFC_S22 21
#define S23 __step_list[22]
#define __SFC_S23 22
#define S24 __step_list[23]
#define __SFC_S24 23
#define S25 __step_list[24]
#define __SFC_S25 24
#define S26 __step_list[25]
#define __SFC_S26 25
#define S27 __step_list[26]
#define __SFC_S27 26
#define D7 __step_list[27]
#define __SFC_D7 27
#define SEMAFORO __step_list[28]
#define __SFC_SEMAFORO 28
#define D1 __step_list[29]
#define __SFC_D1 29
#define D3 __step_list[30]
#define __SFC_D3 30
#define D4 __step_list[31]
#define __SFC_D4 31
#define S17_B __step_list[32]
#define __SFC_S17_B 32
#define S18_B __step_list[33]
#define __SFC_S18_B 33
#define S19_B __step_list[34]
#define __SFC_S19_B 34
#define S20_B __step_list[35]
#define __SFC_S20_B 35
#define S21_B __step_list[36]
#define __SFC_S21_B 36
#define S22_B __step_list[37]
#define __SFC_S22_B 37
#define S23_B __step_list[38]
#define __SFC_S23_B 38
#define S24_B __step_list[39]
#define __SFC_S24_B 39
#define S25_B __step_list[40]
#define __SFC_S25_B 40
#define S26_B __step_list[41]
#define __SFC_S26_B 41
#define S27_B __step_list[42]
#define __SFC_S27_B 42
#define S1_B __step_list[43]
#define __SFC_S1_B 43
#define S2_B __step_list[44]
#define __SFC_S2_B 44
#define S3_B __step_list[45]
#define __SFC_S3_B 45
#define S4_B __step_list[46]
#define __SFC_S4_B 46
#define S5_B __step_list[47]
#define __SFC_S5_B 47
#define S6_B __step_list[48]
#define __SFC_S6_B 48
#define S7_B __step_list[49]
#define __SFC_S7_B 49
#define S8_B __step_list[50]
#define __SFC_S8_B 50
#define S9_B __step_list[51]
#define __SFC_S9_B 51
#define S10_B __step_list[52]
#define __SFC_S10_B 52
#define S11_B __step_list[53]
#define __SFC_S11_B 53
#define S12_B __step_list[54]
#define __SFC_S12_B 54
#define S13_B __step_list[55]
#define __SFC_S13_B 55
#define S14_B __step_list[56]
#define __SFC_S14_B 56
#define S15_B __step_list[57]
#define __SFC_S15_B 57
#define S16_B __step_list[58]
#define __SFC_S16_B 58
#define D6 __step_list[59]
#define __SFC_D6 59
#define D8 __step_list[60]
#define __SFC_D8 60
#define D2 __step_list[61]
#define __SFC_D2 61
#define D5 __step_list[62]
#define __SFC_D5 62

// Actions definitions
#define __SFC_A_MOTORE_AVANTI 0
#define __SFC_S3X 1
#define __SFC_B_MOTORE_AVANTI 2
#define __SFC_PRESSIONE_GIU 3
#define __SFC_PORTELLO_A_APRI 4
#define __SFC_PORTELLO_A_CHIUDI 5
#define __SFC_PRESSIONE_SU 6
#define __SFC_PORTELLO_B_APRI 7
#define __SFC_PORTELLO_B_CHIUDI 8
#define __SFC_A_MOTORE_SINISTRA 9
#define __SFC_A_RILASCIO 10
#define __SFC_A_TEMPO_SEMINA 11
#define __SFC_A_MOTORE_DIETRO 12
#define __SFC_S16X 13
#define __SFC_SEMINA_A_OK 14
#define __SFC_A_START 15
#define __SFC_B_MOTORE_DIETRO 16
#define __SFC_SEMINA_B_OK 17
#define __SFC_B_START 18
#define __SFC_S3_BX 19
#define __SFC_B_MOTORE_DESTRA 20
#define __SFC_B_RILASCIO 21
#define __SFC_B_TEMPO_SEMINA 22
#define __SFC_S16_BX 23

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
  if (__GET_VAR(data__->S1.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->A_START,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->A_START,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->S2.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->A_ANDATA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->A_ANDATA,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->S3.X) && __GET_VAR(data__->D1.X)) {
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
  if (__GET_VAR(data__->S4.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->C_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->C_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->S5.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->PRESSIONE_MIN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->PRESSIONE_MIN,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->S6.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->S7.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->D_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->D_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->S8.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->S9.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->E_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->E_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->S10.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->PRESSIONE_MAX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->PRESSIONE_MAX,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->S11.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->S12.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->F_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->F_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->S13.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->S14.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->G_SX_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->G_SX_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->S15.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->A_TEMPO_SEMINA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->A_TEMPO_SEMINA,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->S16.X) && __GET_VAR(data__->D3.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->F_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->F_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->S17.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->PRESSIONE_MAX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->PRESSIONE_MAX,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->S18.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->S19.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_VAR(data__->E_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->E_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->S20.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->S21.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->PRESSIONE_MIN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->PRESSIONE_MIN,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->S22.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_VAR(data__->D_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->D_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->S23.X)) {
    __SET_VAR(data__->,__transition_list[22],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->S24.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->C_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->C_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->S25.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->S26.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->A_DOCK_RICARICA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->A_DOCK_RICARICA,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->S27.X)) {
    __SET_VAR(data__->,__transition_list[26],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,1);
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->D7.X)) {
    __SET_VAR(data__->,__transition_list[27],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,1);
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->SEMAFORO.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->S3X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->S3X,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->SEMAFORO.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_VAR(data__->S16X,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->S16X,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->SEMAFORO.X)) {
    __SET_VAR(data__->,__transition_list[30],,((!(__GET_VAR(data__->S16X,)) && __GET_VAR(data__->S16_BX,)) && !(__GET_VAR(data__->S3X,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,((!(__GET_VAR(data__->S16X,)) && __GET_VAR(data__->S16_BX,)) && !(__GET_VAR(data__->S3X,))));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->D4.X) && __GET_VAR(data__->S16_B.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->F_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->F_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->S17_B.X)) {
    __SET_VAR(data__->,__transition_list[32],,__GET_VAR(data__->PRESSIONE_MAX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->PRESSIONE_MAX,));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->S18_B.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->S19_B.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_VAR(data__->E_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->E_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->S20_B.X)) {
    __SET_VAR(data__->,__transition_list[35],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->S21_B.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_VAR(data__->PRESSIONE_MIN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->PRESSIONE_MIN,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->S22_B.X)) {
    __SET_VAR(data__->,__transition_list[37],,__GET_VAR(data__->D_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->D_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->S23_B.X)) {
    __SET_VAR(data__->,__transition_list[38],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->S24_B.X)) {
    __SET_VAR(data__->,__transition_list[39],,__GET_VAR(data__->C_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->C_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->S25_B.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->S26_B.X)) {
    __SET_VAR(data__->,__transition_list[41],,__GET_VAR(data__->B_DOCK_RICARICA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->B_DOCK_RICARICA,));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->S27_B.X)) {
    __SET_VAR(data__->,__transition_list[42],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,1);
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->S1_B.X)) {
    __SET_VAR(data__->,__transition_list[43],,__GET_VAR(data__->B_START,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->B_START,));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->S2_B.X)) {
    __SET_VAR(data__->,__transition_list[44],,__GET_VAR(data__->B_ANDATA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->B_ANDATA,));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->D2.X) && __GET_VAR(data__->S3_B.X)) {
    __SET_VAR(data__->,__transition_list[45],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,1);
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->S4_B.X)) {
    __SET_VAR(data__->,__transition_list[46],,__GET_VAR(data__->C_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->C_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->S5_B.X)) {
    __SET_VAR(data__->,__transition_list[47],,__GET_VAR(data__->PRESSIONE_MIN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->PRESSIONE_MIN,));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->S6_B.X)) {
    __SET_VAR(data__->,__transition_list[48],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->PORTELLO_A_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->S7_B.X)) {
    __SET_VAR(data__->,__transition_list[49],,__GET_VAR(data__->D_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->D_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->S8_B.X)) {
    __SET_VAR(data__->,__transition_list[50],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->PORTELLO_A_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->S9_B.X)) {
    __SET_VAR(data__->,__transition_list[51],,__GET_VAR(data__->E_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->E_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->S10_B.X)) {
    __SET_VAR(data__->,__transition_list[52],,__GET_VAR(data__->PRESSIONE_MAX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->PRESSIONE_MAX,));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }
  if (__GET_VAR(data__->S11_B.X)) {
    __SET_VAR(data__->,__transition_list[53],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->__transition_list[53]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->PORTELLO_B_APERTO,));
    }
    __SET_VAR(data__->,__transition_list[53],,0);
  }
  if (__GET_VAR(data__->S12_B.X)) {
    __SET_VAR(data__->,__transition_list[54],,__GET_VAR(data__->F_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->__transition_list[54]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->F_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[54],,0);
  }
  if (__GET_VAR(data__->S13_B.X)) {
    __SET_VAR(data__->,__transition_list[55],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->__transition_list[55]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->PORTELLO_B_CHIUSO,));
    }
    __SET_VAR(data__->,__transition_list[55],,0);
  }
  if (__GET_VAR(data__->S14_B.X)) {
    __SET_VAR(data__->,__transition_list[56],,__GET_VAR(data__->G_DX_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[56],,__GET_VAR(data__->__transition_list[56]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[56],,__GET_VAR(data__->G_DX_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[56],,0);
  }
  if (__GET_VAR(data__->S15_B.X)) {
    __SET_VAR(data__->,__transition_list[57],,__GET_VAR(data__->B_TEMPO_SEMINA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_VAR(data__->__transition_list[57]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_VAR(data__->B_TEMPO_SEMINA,));
    }
    __SET_VAR(data__->,__transition_list[57],,0);
  }
  if (__GET_VAR(data__->D6.X)) {
    __SET_VAR(data__->,__transition_list[58],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,__GET_VAR(data__->__transition_list[58]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,1);
    }
    __SET_VAR(data__->,__transition_list[58],,0);
  }
  if (__GET_VAR(data__->D8.X)) {
    __SET_VAR(data__->,__transition_list[59],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_VAR(data__->__transition_list[59]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,1);
    }
    __SET_VAR(data__->,__transition_list[59],,0);
  }
  if (__GET_VAR(data__->SEMAFORO.X)) {
    __SET_VAR(data__->,__transition_list[60],,((!(__GET_VAR(data__->S3.X,)) && __GET_VAR(data__->S3_B.X,)) && !(__GET_VAR(data__->S16.X,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,__GET_VAR(data__->__transition_list[60]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,((!(__GET_VAR(data__->S3.X,)) && __GET_VAR(data__->S3_B.X,)) && !(__GET_VAR(data__->S16.X,))));
    }
    __SET_VAR(data__->,__transition_list[60],,0);
  }
  if (__GET_VAR(data__->D5.X)) {
    __SET_VAR(data__->,__transition_list[61],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_VAR(data__->__transition_list[61]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,1);
    }
    __SET_VAR(data__->,__transition_list[61],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,S1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,S2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,S3.X,,0);
    __SET_VAR(data__->,D1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,S4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,S5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,S6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,S7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,S8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,S9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,S10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,S11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,S12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,S13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,S14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,S15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,S16.X,,0);
    __SET_VAR(data__->,D3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,S17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,S18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,S19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,S20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,S21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,S22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,S23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,S24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,S25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,S26.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,S27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,D7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,SEMAFORO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,SEMAFORO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,SEMAFORO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,D4.X,,0);
    __SET_VAR(data__->,S16_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,S17_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,S18_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,S19_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,S20_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,S21_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,S22_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,S23_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,S24_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,S25_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,S26_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,S27_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,S1_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,S2_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,D2.X,,0);
    __SET_VAR(data__->,S3_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,S4_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,S5_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,S6_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,S7_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,S8_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,S9_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,S10_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,S11_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,S12_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,S13_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,S14_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,S15_B.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,D6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,D8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,SEMAFORO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,D5.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,S2.X,,1);
    data__->S2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,S3.X,,1);
    data__->S3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,S4.X,,1);
    data__->S4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,S5.X,,1);
    data__->S5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,S6.X,,1);
    data__->S6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,S7.X,,1);
    data__->S7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,S8.X,,1);
    data__->S8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,S9.X,,1);
    data__->S9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,S10.X,,1);
    data__->S10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,S11.X,,1);
    data__->S11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,S12.X,,1);
    data__->S12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,S13.X,,1);
    data__->S13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,S14.X,,1);
    data__->S14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,S15.X,,1);
    data__->S15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,D5.X,,1);
    data__->D5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,S16.X,,1);
    data__->S16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,S17.X,,1);
    data__->S17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,S18.X,,1);
    data__->S18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,S19.X,,1);
    data__->S19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,S20.X,,1);
    data__->S20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,S21.X,,1);
    data__->S21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,S22.X,,1);
    data__->S22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,S23.X,,1);
    data__->S23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,S24.X,,1);
    data__->S24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,S25.X,,1);
    data__->S25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,D7.X,,1);
    data__->D7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,S26.X,,1);
    data__->S26.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,S27.X,,1);
    data__->S27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,S1.X,,1);
    data__->S1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,SEMAFORO.X,,1);
    data__->SEMAFORO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,D1.X,,1);
    data__->D1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,D3.X,,1);
    data__->D3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,D4.X,,1);
    data__->D4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,S17_B.X,,1);
    data__->S17_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,S18_B.X,,1);
    data__->S18_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,S19_B.X,,1);
    data__->S19_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,S20_B.X,,1);
    data__->S20_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,S21_B.X,,1);
    data__->S21_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,S22_B.X,,1);
    data__->S22_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,S23_B.X,,1);
    data__->S23_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,S24_B.X,,1);
    data__->S24_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,S25_B.X,,1);
    data__->S25_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,D8.X,,1);
    data__->D8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,S26_B.X,,1);
    data__->S26_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,S27_B.X,,1);
    data__->S27_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,S1_B.X,,1);
    data__->S1_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,S2_B.X,,1);
    data__->S2_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,S3_B.X,,1);
    data__->S3_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,S4_B.X,,1);
    data__->S4_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,S5_B.X,,1);
    data__->S5_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,S6_B.X,,1);
    data__->S6_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,S7_B.X,,1);
    data__->S7_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,S8_B.X,,1);
    data__->S8_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,S9_B.X,,1);
    data__->S9_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,S10_B.X,,1);
    data__->S10_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,S11_B.X,,1);
    data__->S11_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,S12_B.X,,1);
    data__->S12_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,S13_B.X,,1);
    data__->S13_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,S14_B.X,,1);
    data__->S14_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,S15_B.X,,1);
    data__->S15_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,D6.X,,1);
    data__->D6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,S16_B.X,,1);
    data__->S16_B.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,SEMAFORO.X,,1);
    data__->SEMAFORO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,SEMAFORO.X,,1);
    data__->SEMAFORO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,D2.X,,1);
    data__->D2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,SEMAFORO.X,,1);
    data__->SEMAFORO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // S2 action associations
  {
    char active = __GET_VAR(data__->S2.X);
    char activated = active && !data__->S2.prev_state;
    char desactivated = !active && data__->S2.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_AVANTI,,0);};

  }

  // S3 action associations
  {
    char active = __GET_VAR(data__->S3.X);
    char activated = active && !data__->S3.prev_state;
    char desactivated = !active && data__->S3.prev_state;

    if (active)       {__SET_VAR(data__->,S3X,,1);};
    if (desactivated) {__SET_VAR(data__->,S3X,,0);};

  }

  // S4 action associations
  {
    char active = __GET_VAR(data__->S4.X);
    char activated = active && !data__->S4.prev_state;
    char desactivated = !active && data__->S4.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_AVANTI,,0);};

  }

  // S5 action associations
  {
    char active = __GET_VAR(data__->S5.X);
    char activated = active && !data__->S5.prev_state;
    char desactivated = !active && data__->S5.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_GIU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_GIU,,0);};

  }

  // S6 action associations
  {
    char active = __GET_VAR(data__->S6.X);
    char activated = active && !data__->S6.prev_state;
    char desactivated = !active && data__->S6.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_APRI,,0);};

  }

  // S7 action associations
  {
    char active = __GET_VAR(data__->S7.X);
    char activated = active && !data__->S7.prev_state;
    char desactivated = !active && data__->S7.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_AVANTI,,0);};

  }

  // S8 action associations
  {
    char active = __GET_VAR(data__->S8.X);
    char activated = active && !data__->S8.prev_state;
    char desactivated = !active && data__->S8.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,0);};

  }

  // S9 action associations
  {
    char active = __GET_VAR(data__->S9.X);
    char activated = active && !data__->S9.prev_state;
    char desactivated = !active && data__->S9.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_AVANTI,,0);};

  }

  // S10 action associations
  {
    char active = __GET_VAR(data__->S10.X);
    char activated = active && !data__->S10.prev_state;
    char desactivated = !active && data__->S10.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_SU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_SU,,0);};

  }

  // S11 action associations
  {
    char active = __GET_VAR(data__->S11.X);
    char activated = active && !data__->S11.prev_state;
    char desactivated = !active && data__->S11.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_APRI,,0);};

  }

  // S12 action associations
  {
    char active = __GET_VAR(data__->S12.X);
    char activated = active && !data__->S12.prev_state;
    char desactivated = !active && data__->S12.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_AVANTI,,0);};

  }

  // S13 action associations
  {
    char active = __GET_VAR(data__->S13.X);
    char activated = active && !data__->S13.prev_state;
    char desactivated = !active && data__->S13.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,0);};

  }

  // S14 action associations
  {
    char active = __GET_VAR(data__->S14.X);
    char activated = active && !data__->S14.prev_state;
    char desactivated = !active && data__->S14.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_SINISTRA,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_SINISTRA,,0);};

  }

  // S15 action associations
  {
    char active = __GET_VAR(data__->S15.X);
    char activated = active && !data__->S15.prev_state;
    char desactivated = !active && data__->S15.prev_state;

    if (active)       {__SET_VAR(data__->,A_RILASCIO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_RILASCIO,,0);};

    if (activated) {
      data__->__action_list[__SFC_A_TEMPO_SEMINA].set_remaining_time = __time_to_timespec(1, 0, 30, 0, 0, 0);
    }

  }

  // S16 action associations
  {
    char active = __GET_VAR(data__->S16.X);
    char activated = active && !data__->S16.prev_state;
    char desactivated = !active && data__->S16.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_DIETRO,,0);};

    if (active)       {__SET_VAR(data__->,S16X,,1);};
    if (desactivated) {__SET_VAR(data__->,S16X,,0);};

  }

  // S17 action associations
  {
    char active = __GET_VAR(data__->S17.X);
    char activated = active && !data__->S17.prev_state;
    char desactivated = !active && data__->S17.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_SU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_SU,,0);};

  }

  // S18 action associations
  {
    char active = __GET_VAR(data__->S18.X);
    char activated = active && !data__->S18.prev_state;
    char desactivated = !active && data__->S18.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_APRI,,0);};

  }

  // S19 action associations
  {
    char active = __GET_VAR(data__->S19.X);
    char activated = active && !data__->S19.prev_state;
    char desactivated = !active && data__->S19.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_DIETRO,,0);};

  }

  // S20 action associations
  {
    char active = __GET_VAR(data__->S20.X);
    char activated = active && !data__->S20.prev_state;
    char desactivated = !active && data__->S20.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,0);};

  }

  // S21 action associations
  {
    char active = __GET_VAR(data__->S21.X);
    char activated = active && !data__->S21.prev_state;
    char desactivated = !active && data__->S21.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_GIU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_GIU,,0);};

  }

  // S22 action associations
  {
    char active = __GET_VAR(data__->S22.X);
    char activated = active && !data__->S22.prev_state;
    char desactivated = !active && data__->S22.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_DIETRO,,0);};

  }

  // S23 action associations
  {
    char active = __GET_VAR(data__->S23.X);
    char activated = active && !data__->S23.prev_state;
    char desactivated = !active && data__->S23.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_APRI,,0);};

  }

  // S24 action associations
  {
    char active = __GET_VAR(data__->S24.X);
    char activated = active && !data__->S24.prev_state;
    char desactivated = !active && data__->S24.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_DIETRO,,0);};

  }

  // S25 action associations
  {
    char active = __GET_VAR(data__->S25.X);
    char activated = active && !data__->S25.prev_state;
    char desactivated = !active && data__->S25.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,0);};

  }

  // S26 action associations
  {
    char active = __GET_VAR(data__->S26.X);
    char activated = active && !data__->S26.prev_state;
    char desactivated = !active && data__->S26.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_DIETRO,,0);};

  }

  // S27 action associations
  {
    char active = __GET_VAR(data__->S27.X);
    char activated = active && !data__->S27.prev_state;
    char desactivated = !active && data__->S27.prev_state;

    if (active)       {data__->__action_list[__SFC_SEMINA_A_OK].set = 1;}

    if (active)       {data__->__action_list[__SFC_A_START].reset = 1;}

  }

  // S17_B action associations
  {
    char active = __GET_VAR(data__->S17_B.X);
    char activated = active && !data__->S17_B.prev_state;
    char desactivated = !active && data__->S17_B.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_SU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_SU,,0);};

  }

  // S18_B action associations
  {
    char active = __GET_VAR(data__->S18_B.X);
    char activated = active && !data__->S18_B.prev_state;
    char desactivated = !active && data__->S18_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_APRI,,0);};

  }

  // S19_B action associations
  {
    char active = __GET_VAR(data__->S19_B.X);
    char activated = active && !data__->S19_B.prev_state;
    char desactivated = !active && data__->S19_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_DIETRO,,0);};

  }

  // S20_B action associations
  {
    char active = __GET_VAR(data__->S20_B.X);
    char activated = active && !data__->S20_B.prev_state;
    char desactivated = !active && data__->S20_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,0);};

  }

  // S21_B action associations
  {
    char active = __GET_VAR(data__->S21_B.X);
    char activated = active && !data__->S21_B.prev_state;
    char desactivated = !active && data__->S21_B.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_GIU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_GIU,,0);};

  }

  // S22_B action associations
  {
    char active = __GET_VAR(data__->S22_B.X);
    char activated = active && !data__->S22_B.prev_state;
    char desactivated = !active && data__->S22_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_DIETRO,,0);};

  }

  // S23_B action associations
  {
    char active = __GET_VAR(data__->S23_B.X);
    char activated = active && !data__->S23_B.prev_state;
    char desactivated = !active && data__->S23_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_APRI,,0);};

  }

  // S24_B action associations
  {
    char active = __GET_VAR(data__->S24_B.X);
    char activated = active && !data__->S24_B.prev_state;
    char desactivated = !active && data__->S24_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_DIETRO,,0);};

  }

  // S25_B action associations
  {
    char active = __GET_VAR(data__->S25_B.X);
    char activated = active && !data__->S25_B.prev_state;
    char desactivated = !active && data__->S25_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,0);};

  }

  // S26_B action associations
  {
    char active = __GET_VAR(data__->S26_B.X);
    char activated = active && !data__->S26_B.prev_state;
    char desactivated = !active && data__->S26_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_DIETRO,,0);};

  }

  // S27_B action associations
  {
    char active = __GET_VAR(data__->S27_B.X);
    char activated = active && !data__->S27_B.prev_state;
    char desactivated = !active && data__->S27_B.prev_state;

    if (active)       {data__->__action_list[__SFC_SEMINA_B_OK].set = 1;}

    if (active)       {data__->__action_list[__SFC_B_START].reset = 1;}

  }

  // S2_B action associations
  {
    char active = __GET_VAR(data__->S2_B.X);
    char activated = active && !data__->S2_B.prev_state;
    char desactivated = !active && data__->S2_B.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_AVANTI,,0);};

  }

  // S3_B action associations
  {
    char active = __GET_VAR(data__->S3_B.X);
    char activated = active && !data__->S3_B.prev_state;
    char desactivated = !active && data__->S3_B.prev_state;

    if (active)       {__SET_VAR(data__->,S3_BX,,1);};
    if (desactivated) {__SET_VAR(data__->,S3_BX,,0);};

  }

  // S4_B action associations
  {
    char active = __GET_VAR(data__->S4_B.X);
    char activated = active && !data__->S4_B.prev_state;
    char desactivated = !active && data__->S4_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_AVANTI,,0);};

  }

  // S5_B action associations
  {
    char active = __GET_VAR(data__->S5_B.X);
    char activated = active && !data__->S5_B.prev_state;
    char desactivated = !active && data__->S5_B.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_GIU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_GIU,,0);};

  }

  // S6_B action associations
  {
    char active = __GET_VAR(data__->S6_B.X);
    char activated = active && !data__->S6_B.prev_state;
    char desactivated = !active && data__->S6_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_APRI,,0);};

  }

  // S7_B action associations
  {
    char active = __GET_VAR(data__->S7_B.X);
    char activated = active && !data__->S7_B.prev_state;
    char desactivated = !active && data__->S7_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_AVANTI,,0);};

  }

  // S8_B action associations
  {
    char active = __GET_VAR(data__->S8_B.X);
    char activated = active && !data__->S8_B.prev_state;
    char desactivated = !active && data__->S8_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_A_CHIUDI,,0);};

  }

  // S9_B action associations
  {
    char active = __GET_VAR(data__->S9_B.X);
    char activated = active && !data__->S9_B.prev_state;
    char desactivated = !active && data__->S9_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_AVANTI,,0);};

  }

  // S10_B action associations
  {
    char active = __GET_VAR(data__->S10_B.X);
    char activated = active && !data__->S10_B.prev_state;
    char desactivated = !active && data__->S10_B.prev_state;

    if (active)       {__SET_VAR(data__->,PRESSIONE_SU,,1);};
    if (desactivated) {__SET_VAR(data__->,PRESSIONE_SU,,0);};

  }

  // S11_B action associations
  {
    char active = __GET_VAR(data__->S11_B.X);
    char activated = active && !data__->S11_B.prev_state;
    char desactivated = !active && data__->S11_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_APRI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_APRI,,0);};

  }

  // S12_B action associations
  {
    char active = __GET_VAR(data__->S12_B.X);
    char activated = active && !data__->S12_B.prev_state;
    char desactivated = !active && data__->S12_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_AVANTI,,0);};

  }

  // S13_B action associations
  {
    char active = __GET_VAR(data__->S13_B.X);
    char activated = active && !data__->S13_B.prev_state;
    char desactivated = !active && data__->S13_B.prev_state;

    if (active)       {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,1);};
    if (desactivated) {__SET_VAR(data__->,PORTELLO_B_CHIUDI,,0);};

  }

  // S14_B action associations
  {
    char active = __GET_VAR(data__->S14_B.X);
    char activated = active && !data__->S14_B.prev_state;
    char desactivated = !active && data__->S14_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_DESTRA,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_DESTRA,,0);};

  }

  // S15_B action associations
  {
    char active = __GET_VAR(data__->S15_B.X);
    char activated = active && !data__->S15_B.prev_state;
    char desactivated = !active && data__->S15_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_RILASCIO,,1);};
    if (desactivated) {__SET_VAR(data__->,B_RILASCIO,,0);};

    if (activated) {
      data__->__action_list[__SFC_B_TEMPO_SEMINA].set_remaining_time = __time_to_timespec(1, 0, 20, 0, 0, 0);
    }

  }

  // S16_B action associations
  {
    char active = __GET_VAR(data__->S16_B.X);
    char activated = active && !data__->S16_B.prev_state;
    char desactivated = !active && data__->S16_B.prev_state;

    if (active)       {__SET_VAR(data__->,B_MOTORE_DIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,B_MOTORE_DIETRO,,0);};

    if (active)       {__SET_VAR(data__->,S16_BX,,1);};
    if (desactivated) {__SET_VAR(data__->,S16_BX,,0);};

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
  if (data__->__action_list[__SFC_A_MOTORE_AVANTI].reset) {
    __SET_VAR(data__->,A_MOTORE_AVANTI,,0);
  }
  else if (data__->__action_list[__SFC_A_MOTORE_AVANTI].set) {
    __SET_VAR(data__->,A_MOTORE_AVANTI,,1);
  }
  if (data__->__action_list[__SFC_S3X].reset) {
    __SET_VAR(data__->,S3X,,0);
  }
  else if (data__->__action_list[__SFC_S3X].set) {
    __SET_VAR(data__->,S3X,,1);
  }
  if (data__->__action_list[__SFC_B_MOTORE_AVANTI].reset) {
    __SET_VAR(data__->,B_MOTORE_AVANTI,,0);
  }
  else if (data__->__action_list[__SFC_B_MOTORE_AVANTI].set) {
    __SET_VAR(data__->,B_MOTORE_AVANTI,,1);
  }
  if (data__->__action_list[__SFC_PRESSIONE_GIU].reset) {
    __SET_VAR(data__->,PRESSIONE_GIU,,0);
  }
  else if (data__->__action_list[__SFC_PRESSIONE_GIU].set) {
    __SET_VAR(data__->,PRESSIONE_GIU,,1);
  }
  if (data__->__action_list[__SFC_PORTELLO_A_APRI].reset) {
    __SET_VAR(data__->,PORTELLO_A_APRI,,0);
  }
  else if (data__->__action_list[__SFC_PORTELLO_A_APRI].set) {
    __SET_VAR(data__->,PORTELLO_A_APRI,,1);
  }
  if (data__->__action_list[__SFC_PORTELLO_A_CHIUDI].reset) {
    __SET_VAR(data__->,PORTELLO_A_CHIUDI,,0);
  }
  else if (data__->__action_list[__SFC_PORTELLO_A_CHIUDI].set) {
    __SET_VAR(data__->,PORTELLO_A_CHIUDI,,1);
  }
  if (data__->__action_list[__SFC_PRESSIONE_SU].reset) {
    __SET_VAR(data__->,PRESSIONE_SU,,0);
  }
  else if (data__->__action_list[__SFC_PRESSIONE_SU].set) {
    __SET_VAR(data__->,PRESSIONE_SU,,1);
  }
  if (data__->__action_list[__SFC_PORTELLO_B_APRI].reset) {
    __SET_VAR(data__->,PORTELLO_B_APRI,,0);
  }
  else if (data__->__action_list[__SFC_PORTELLO_B_APRI].set) {
    __SET_VAR(data__->,PORTELLO_B_APRI,,1);
  }
  if (data__->__action_list[__SFC_PORTELLO_B_CHIUDI].reset) {
    __SET_VAR(data__->,PORTELLO_B_CHIUDI,,0);
  }
  else if (data__->__action_list[__SFC_PORTELLO_B_CHIUDI].set) {
    __SET_VAR(data__->,PORTELLO_B_CHIUDI,,1);
  }
  if (data__->__action_list[__SFC_A_MOTORE_SINISTRA].reset) {
    __SET_VAR(data__->,A_MOTORE_SINISTRA,,0);
  }
  else if (data__->__action_list[__SFC_A_MOTORE_SINISTRA].set) {
    __SET_VAR(data__->,A_MOTORE_SINISTRA,,1);
  }
  if (data__->__action_list[__SFC_A_RILASCIO].reset) {
    __SET_VAR(data__->,A_RILASCIO,,0);
  }
  else if (data__->__action_list[__SFC_A_RILASCIO].set) {
    __SET_VAR(data__->,A_RILASCIO,,1);
  }
  if (data__->__action_list[__SFC_A_TEMPO_SEMINA].reset) {
    __SET_VAR(data__->,A_TEMPO_SEMINA,,0);
  }
  else if (data__->__action_list[__SFC_A_TEMPO_SEMINA].set) {
    __SET_VAR(data__->,A_TEMPO_SEMINA,,1);
  }
  if (data__->__action_list[__SFC_A_MOTORE_DIETRO].reset) {
    __SET_VAR(data__->,A_MOTORE_DIETRO,,0);
  }
  else if (data__->__action_list[__SFC_A_MOTORE_DIETRO].set) {
    __SET_VAR(data__->,A_MOTORE_DIETRO,,1);
  }
  if (data__->__action_list[__SFC_S16X].reset) {
    __SET_VAR(data__->,S16X,,0);
  }
  else if (data__->__action_list[__SFC_S16X].set) {
    __SET_VAR(data__->,S16X,,1);
  }
  if (data__->__action_list[__SFC_SEMINA_A_OK].reset) {
    __SET_VAR(data__->,SEMINA_A_OK,,0);
  }
  else if (data__->__action_list[__SFC_SEMINA_A_OK].set) {
    __SET_VAR(data__->,SEMINA_A_OK,,1);
  }
  if (data__->__action_list[__SFC_A_START].reset) {
    __SET_VAR(data__->,A_START,,0);
  }
  else if (data__->__action_list[__SFC_A_START].set) {
    __SET_VAR(data__->,A_START,,1);
  }
  if (data__->__action_list[__SFC_B_MOTORE_DIETRO].reset) {
    __SET_VAR(data__->,B_MOTORE_DIETRO,,0);
  }
  else if (data__->__action_list[__SFC_B_MOTORE_DIETRO].set) {
    __SET_VAR(data__->,B_MOTORE_DIETRO,,1);
  }
  if (data__->__action_list[__SFC_SEMINA_B_OK].reset) {
    __SET_VAR(data__->,SEMINA_B_OK,,0);
  }
  else if (data__->__action_list[__SFC_SEMINA_B_OK].set) {
    __SET_VAR(data__->,SEMINA_B_OK,,1);
  }
  if (data__->__action_list[__SFC_B_START].reset) {
    __SET_VAR(data__->,B_START,,0);
  }
  else if (data__->__action_list[__SFC_B_START].set) {
    __SET_VAR(data__->,B_START,,1);
  }
  if (data__->__action_list[__SFC_S3_BX].reset) {
    __SET_VAR(data__->,S3_BX,,0);
  }
  else if (data__->__action_list[__SFC_S3_BX].set) {
    __SET_VAR(data__->,S3_BX,,1);
  }
  if (data__->__action_list[__SFC_B_MOTORE_DESTRA].reset) {
    __SET_VAR(data__->,B_MOTORE_DESTRA,,0);
  }
  else if (data__->__action_list[__SFC_B_MOTORE_DESTRA].set) {
    __SET_VAR(data__->,B_MOTORE_DESTRA,,1);
  }
  if (data__->__action_list[__SFC_B_RILASCIO].reset) {
    __SET_VAR(data__->,B_RILASCIO,,0);
  }
  else if (data__->__action_list[__SFC_B_RILASCIO].set) {
    __SET_VAR(data__->,B_RILASCIO,,1);
  }
  if (data__->__action_list[__SFC_B_TEMPO_SEMINA].reset) {
    __SET_VAR(data__->,B_TEMPO_SEMINA,,0);
  }
  else if (data__->__action_list[__SFC_B_TEMPO_SEMINA].set) {
    __SET_VAR(data__->,B_TEMPO_SEMINA,,1);
  }
  if (data__->__action_list[__SFC_S16_BX].reset) {
    __SET_VAR(data__->,S16_BX,,0);
  }
  else if (data__->__action_list[__SFC_S16_BX].set) {
    __SET_VAR(data__->,S16_BX,,1);
  }


  goto __end;

__end:
  return;
} // PROGRAM0_body__() 

// Steps undefinitions
#undef S1
#undef __SFC_S1
#undef S2
#undef __SFC_S2
#undef S3
#undef __SFC_S3
#undef S4
#undef __SFC_S4
#undef S5
#undef __SFC_S5
#undef S6
#undef __SFC_S6
#undef S7
#undef __SFC_S7
#undef S8
#undef __SFC_S8
#undef S9
#undef __SFC_S9
#undef S10
#undef __SFC_S10
#undef S11
#undef __SFC_S11
#undef S12
#undef __SFC_S12
#undef S13
#undef __SFC_S13
#undef S14
#undef __SFC_S14
#undef S15
#undef __SFC_S15
#undef S16
#undef __SFC_S16
#undef S17
#undef __SFC_S17
#undef S18
#undef __SFC_S18
#undef S19
#undef __SFC_S19
#undef S20
#undef __SFC_S20
#undef S21
#undef __SFC_S21
#undef S22
#undef __SFC_S22
#undef S23
#undef __SFC_S23
#undef S24
#undef __SFC_S24
#undef S25
#undef __SFC_S25
#undef S26
#undef __SFC_S26
#undef S27
#undef __SFC_S27
#undef D7
#undef __SFC_D7
#undef SEMAFORO
#undef __SFC_SEMAFORO
#undef D1
#undef __SFC_D1
#undef D3
#undef __SFC_D3
#undef D4
#undef __SFC_D4
#undef S17_B
#undef __SFC_S17_B
#undef S18_B
#undef __SFC_S18_B
#undef S19_B
#undef __SFC_S19_B
#undef S20_B
#undef __SFC_S20_B
#undef S21_B
#undef __SFC_S21_B
#undef S22_B
#undef __SFC_S22_B
#undef S23_B
#undef __SFC_S23_B
#undef S24_B
#undef __SFC_S24_B
#undef S25_B
#undef __SFC_S25_B
#undef S26_B
#undef __SFC_S26_B
#undef S27_B
#undef __SFC_S27_B
#undef S1_B
#undef __SFC_S1_B
#undef S2_B
#undef __SFC_S2_B
#undef S3_B
#undef __SFC_S3_B
#undef S4_B
#undef __SFC_S4_B
#undef S5_B
#undef __SFC_S5_B
#undef S6_B
#undef __SFC_S6_B
#undef S7_B
#undef __SFC_S7_B
#undef S8_B
#undef __SFC_S8_B
#undef S9_B
#undef __SFC_S9_B
#undef S10_B
#undef __SFC_S10_B
#undef S11_B
#undef __SFC_S11_B
#undef S12_B
#undef __SFC_S12_B
#undef S13_B
#undef __SFC_S13_B
#undef S14_B
#undef __SFC_S14_B
#undef S15_B
#undef __SFC_S15_B
#undef S16_B
#undef __SFC_S16_B
#undef D6
#undef __SFC_D6
#undef D8
#undef __SFC_D8
#undef D2
#undef __SFC_D2
#undef D5
#undef __SFC_D5

// Actions undefinitions
#undef __SFC_A_MOTORE_AVANTI
#undef __SFC_S3X
#undef __SFC_B_MOTORE_AVANTI
#undef __SFC_PRESSIONE_GIU
#undef __SFC_PORTELLO_A_APRI
#undef __SFC_PORTELLO_A_CHIUDI
#undef __SFC_PRESSIONE_SU
#undef __SFC_PORTELLO_B_APRI
#undef __SFC_PORTELLO_B_CHIUDI
#undef __SFC_A_MOTORE_SINISTRA
#undef __SFC_A_RILASCIO
#undef __SFC_A_TEMPO_SEMINA
#undef __SFC_A_MOTORE_DIETRO
#undef __SFC_S16X
#undef __SFC_SEMINA_A_OK
#undef __SFC_A_START
#undef __SFC_B_MOTORE_DIETRO
#undef __SFC_SEMINA_B_OK
#undef __SFC_B_START
#undef __SFC_S3_BX
#undef __SFC_B_MOTORE_DESTRA
#undef __SFC_B_RILASCIO
#undef __SFC_B_TEMPO_SEMINA
#undef __SFC_S16_BX





