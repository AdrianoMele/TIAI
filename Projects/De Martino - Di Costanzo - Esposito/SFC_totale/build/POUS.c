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
  __INIT_VAR(data__->TEMP_SENS,0,retain)
  __INIT_VAR(data__->TEMP_RIF,10,retain)
  __INIT_VAR(data__->ATTERRAGGIO,0,retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->TEMP_OK,0,retain)
  __INIT_VAR(data__->GIORNI,0,retain)
  __INIT_VAR(data__->NA,0,retain)
  __INIT_VAR(data__->AR,0,retain)
  __INIT_VAR(data__->O,0,retain)
  __INIT_VAR(data__->NA_OK,0,retain)
  __INIT_VAR(data__->AR_OK,0,retain)
  __INIT_VAR(data__->O_OK,0,retain)
  __INIT_VAR(data__->UMIDITA_OK,0,retain)
  __INIT_VAR(data__->IRRIGAZIONE_OK_A,0,retain)
  __INIT_VAR(data__->IRRIGAZIONE_OK_E,0,retain)
  __INIT_VAR(data__->SEMINA_DES,0,retain)
  __INIT_VAR(data__->SEMINA_SIN,0,retain)
  __INIT_VAR(data__->SENS_LUCE_BUIO,0,retain)
  __INIT_VAR(data__->IRRIGATORE_ACQUA_A,0,retain)
  __INIT_VAR(data__->IRRIGATORE_ACQUA_E,0,retain)
  __INIT_VAR(data__->START2,0,retain)
  __INIT_VAR(data__->T_18,17,retain)
  __INIT_VAR(data__->T_24,23,retain)
  __INIT_VAR(data__->NOT_LUCE,0,retain)
  __INIT_VAR(data__->LUCI_EM,0,retain)
  __INIT_VAR(data__->EM_ROVER,0,retain)
  __INIT_VAR(data__->FINE_EM_LUCE,0,retain)
  __INIT_VAR(data__->ESTRAZIONE_OK,0,retain)
  __INIT_VAR(data__->A_MOTORE_AVANTI,0,retain)
  __INIT_VAR(data__->A_MOTORE_INDIETRO,0,retain)
  __INIT_VAR(data__->A_APRI_SPAZZOLA,0,retain)
  __INIT_VAR(data__->A_CHIUDI_SPAZZOLA,0,retain)
  __INIT_VAR(data__->A_DOCK_RICARICA,1,retain)
  __INIT_VAR(data__->SECCO1,0,retain)
  __INIT_VAR(data__->SECCO2,0,retain)
  __INIT_VAR(data__->A_AZIONA_SPAZZOLA,0,retain)
  __INIT_VAR(data__->SENSORE_P,0,retain)
  __INIT_VAR(data__->ESPULSIONE_OK,0,retain)
  __INIT_VAR(data__->SPORCO,0,retain)
  __INIT_VAR(data__->ESTRAZIONE_OSSIGENO,0,retain)
  __INIT_VAR(data__->ESPULSIONE_OSSIGENO,0,retain)
  __INIT_VAR(data__->VENTILATORE_A,0,retain)
  __INIT_VAR(data__->VENTILATORE_B,0,retain)
  __INIT_VAR(data__->GIORNO,0,retain)
  __INIT_VAR(data__->NOTTE,0,retain)
  __INIT_VAR(data__->DURATA_NOTTE,0,retain)
  __INIT_VAR(data__->DURATA_GIORNO,0,retain)
  __INIT_VAR(data__->TEMP1,0,retain)
  __INIT_VAR(data__->UMIDIFICATORE_ACQUA,0,retain)
  __INIT_VAR(data__->APERTURA,0,retain)
  __INIT_VAR(data__->APERTO,0,retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  UINT i;
  data__->__nb_steps = 39;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[12].X,,1);
  __SET_VAR(data__->,__step_list[18].X,,1);
  __SET_VAR(data__->,__step_list[21].X,,1);
  __SET_VAR(data__->,__step_list[31].X,,1);
  __SET_VAR(data__->,__step_list[35].X,,1);
  data__->__nb_actions = 46;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 39;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define S0 __step_list[0]
#define __SFC_S0 0
#define F0 __step_list[1]
#define __SFC_F0 1
#define S7 __step_list[2]
#define __SFC_S7 2
#define S01 __step_list[3]
#define __SFC_S01 3
#define S04 __step_list[4]
#define __SFC_S04 4
#define S08 __step_list[5]
#define __SFC_S08 5
#define SEMINA __step_list[6]
#define __SFC_SEMINA 6
#define S09 __step_list[7]
#define __SFC_S09 7
#define S02 __step_list[8]
#define __SFC_S02 8
#define S05 __step_list[9]
#define __SFC_S05 9
#define S03 __step_list[10]
#define __SFC_S03 10
#define S06 __step_list[11]
#define __SFC_S06 11
#define MANUTENZIONE_CUPOLA __step_list[12]
#define __SFC_MANUTENZIONE_CUPOLA 12
#define R0 __step_list[13]
#define __SFC_R0 13
#define R1 __step_list[14]
#define __SFC_R1 14
#define R2 __step_list[15]
#define __SFC_R2 15
#define R3 __step_list[16]
#define __SFC_R3 16
#define STEP3 __step_list[17]
#define __SFC_STEP3 17
#define S00 __step_list[18]
#define __SFC_S00 18
#define NOTTE0 __step_list[19]
#define __SFC_NOTTE0 19
#define GIORNO0 __step_list[20]
#define __SFC_GIORNO0 20
#define QUIETE_LUCE_BUIO0 __step_list[21]
#define __SFC_QUIETE_LUCE_BUIO0 21
#define Q1 __step_list[22]
#define __SFC_Q1 22
#define BUIO0 __step_list[23]
#define __SFC_BUIO0 23
#define LUCE0 __step_list[24]
#define __SFC_LUCE0 24
#define PRELIEVO0 __step_list[25]
#define __SFC_PRELIEVO0 25
#define ESPULSIONE0 __step_list[26]
#define __SFC_ESPULSIONE0 26
#define G1 __step_list[27]
#define __SFC_G1 27
#define STEP0 __step_list[28]
#define __SFC_STEP0 28
#define STEP1 __step_list[29]
#define __SFC_STEP1 29
#define STEP4 __step_list[30]
#define __SFC_STEP4 30
#define IRRIGAZIONE_ALOE0 __step_list[31]
#define __SFC_IRRIGAZIONE_ALOE0 31
#define I2 __step_list[32]
#define __SFC_I2 32
#define I3 __step_list[33]
#define __SFC_I3 33
#define I4 __step_list[34]
#define __SFC_I4 34
#define IRRIGAZIONE_EDERA0 __step_list[35]
#define __SFC_IRRIGAZIONE_EDERA0 35
#define I1 __step_list[36]
#define __SFC_I1 36
#define I5 __step_list[37]
#define __SFC_I5 37
#define I6 __step_list[38]
#define __SFC_I6 38

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_T_OK10 1
#define __SFC_TEMP_OK_0 2
#define __SFC_T_RIF_18 3
#define __SFC_T_RIF_24 4
#define __SFC_APERTURA 5
#define __SFC_APERTO 6
#define __SFC_NA 7
#define __SFC_AR 8
#define __SFC_O 9
#define __SFC_NA_OK 10
#define __SFC_AR_OK 11
#define __SFC_O_OK 12
#define __SFC_IRRIGAZIONE_OK_A 13
#define __SFC_IRRIGAZIONE_OK_E 14
#define __SFC_SEMINA_DES 15
#define __SFC_SEMINA_SIN 16
#define __SFC_START2 17
#define __SFC_UMIDIFICATORE_ACQUA 18
#define __SFC_UMIDITA_OK 19
#define __SFC_IRRIGATORE_ACQUA_A 20
#define __SFC_IRRIGATORE_ACQUA_E 21
#define __SFC_A_MOTORE_AVANTI 22
#define __SFC_SENSORE_P 23
#define __SFC_A_DOCK_RICARICA 24
#define __SFC_A_APRI_SPAZZOLA 25
#define __SFC_A_AZIONA_SPAZZOLA 26
#define __SFC_TEMP1 27
#define __SFC_SPORCO 28
#define __SFC_A_MOTORE_INDIETRO 29
#define __SFC_A_CHIUDI_SPAZZOLA 30
#define __SFC_EM_ROVER 31
#define __SFC_NOTTE 32
#define __SFC_DURATA_NOTTE 33
#define __SFC_GIORNO 34
#define __SFC_DURATA_GIORNO 35
#define __SFC_VENTILATORE_A 36
#define __SFC_VENTILATORE_B 37
#define __SFC_NOT_LUCE 38
#define __SFC_ESTRAZIONE_OSSIGENO 39
#define __SFC_ESTRAZIONE_OK 40
#define __SFC_ESPULSIONE_OSSIGENO 41
#define __SFC_ESPULSIONE_OK 42
#define __SFC_LUCI_EM 43
#define __SFC_SECCO1 44
#define __SFC_SECCO2 45

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
  if (__GET_VAR(data__->S0.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->START,) && __GET_VAR(data__->ATTERRAGGIO,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->START,) && __GET_VAR(data__->ATTERRAGGIO,)));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->F0.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->APERTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->APERTO,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->S7.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->TEMP_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->TEMP_OK,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->S01.X)) {
    __SET_VAR(data__->,__transition_list[3],,((__GET_VAR(data__->NA_OK,) && __GET_VAR(data__->AR_OK,)) && __GET_VAR(data__->O_OK,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,((__GET_VAR(data__->NA_OK,) && __GET_VAR(data__->AR_OK,)) && __GET_VAR(data__->O_OK,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->S04.X) && __GET_VAR(data__->S05.X) && __GET_VAR(data__->S06.X)) {
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
  if (__GET_VAR(data__->S08.X)) {
    __SET_VAR(data__->,__transition_list[5],,!(__GET_VAR(data__->TEMP_OK,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,!(__GET_VAR(data__->TEMP_OK,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->SEMINA.X)) {
    __SET_VAR(data__->,__transition_list[6],,(__GET_VAR(data__->SEMINA_DES,) && __GET_VAR(data__->SEMINA_SIN,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,(__GET_VAR(data__->SEMINA_DES,) && __GET_VAR(data__->SEMINA_SIN,)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->S02.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->UMIDITA_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->UMIDITA_OK,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->S03.X)) {
    __SET_VAR(data__->,__transition_list[8],,(__GET_VAR(data__->IRRIGAZIONE_OK_A,) && __GET_VAR(data__->IRRIGAZIONE_OK_E,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,(__GET_VAR(data__->IRRIGAZIONE_OK_A,) && __GET_VAR(data__->IRRIGAZIONE_OK_E,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MANUTENZIONE_CUPOLA.X)) {
    __SET_VAR(data__->,__transition_list[9],,((__GET_VAR(data__->SEMINA_SIN,) && __GET_VAR(data__->SEMINA_DES,)) && __GET_VAR(data__->R_TRIG1.Q,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,((__GET_VAR(data__->SEMINA_SIN,) && __GET_VAR(data__->SEMINA_DES,)) && __GET_VAR(data__->R_TRIG1.Q,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->R0.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->SENSORE_P,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->SENSORE_P,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->R1.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TEMP1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TEMP1,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->R2.X)) {
    __SET_VAR(data__->,__transition_list[12],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,1);
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->R3.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->A_DOCK_RICARICA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->A_DOCK_RICARICA,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[14],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,1);
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->S00.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->START2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->START2,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->NOTTE0.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->DURATA_NOTTE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->DURATA_NOTTE,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->GIORNO0.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->DURATA_GIORNO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->DURATA_GIORNO,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->QUIETE_LUCE_BUIO0.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_VAR(data__->START2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->START2,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->Q1.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->NOTTE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->NOTTE,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->BUIO0.X)) {
    __SET_VAR(data__->,__transition_list[20],,!(__GET_VAR(data__->NOTTE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,!(__GET_VAR(data__->NOTTE,)));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->Q1.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_VAR(data__->GIORNO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->GIORNO,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->LUCE0.X)) {
    __SET_VAR(data__->,__transition_list[22],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,1);
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->PRELIEVO0.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->ESTRAZIONE_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->ESTRAZIONE_OK,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->ESPULSIONE0.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_VAR(data__->ESPULSIONE_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->ESPULSIONE_OK,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->G1.X)) {
    __SET_VAR(data__->,__transition_list[25],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,1);
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->Q1.X)) {
    __SET_VAR(data__->,__transition_list[26],,(__GET_VAR(data__->GIORNO,) && __GET_VAR(data__->NOT_LUCE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,(__GET_VAR(data__->GIORNO,) && __GET_VAR(data__->NOT_LUCE,)));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[27],,!(__GET_VAR(data__->GIORNO,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,!(__GET_VAR(data__->GIORNO,)));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[28],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,1);
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[29],,(__GET_VAR(data__->GIORNO,) && !(__GET_VAR(data__->SPORCO,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,(__GET_VAR(data__->GIORNO,) && !(__GET_VAR(data__->SPORCO,))));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[30],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,1);
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->IRRIGAZIONE_ALOE0.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->START2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->START2,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->I2.X)) {
    __SET_VAR(data__->,__transition_list[32],,__GET_VAR(data__->SECCO1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->SECCO1,));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->I3.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_VAR(data__->IRRIGAZIONE_OK_A,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->IRRIGAZIONE_OK_A,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->I4.X)) {
    __SET_VAR(data__->,__transition_list[34],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,1);
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->IRRIGAZIONE_EDERA0.X)) {
    __SET_VAR(data__->,__transition_list[35],,__GET_VAR(data__->START2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->START2,));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->I1.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_VAR(data__->SECCO2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->SECCO2,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->I5.X)) {
    __SET_VAR(data__->,__transition_list[37],,__GET_VAR(data__->IRRIGAZIONE_OK_E,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->IRRIGAZIONE_OK_E,));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->I6.X)) {
    __SET_VAR(data__->,__transition_list[38],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,1);
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,S0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,F0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,S7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,S01.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,S04.X,,0);
    __SET_VAR(data__->,S05.X,,0);
    __SET_VAR(data__->,S06.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,S08.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,SEMINA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,S02.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,S03.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MANUTENZIONE_CUPOLA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,R0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,R1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,R2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,R3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,S00.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,NOTTE0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,GIORNO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,QUIETE_LUCE_BUIO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,Q1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,BUIO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,Q1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,LUCE0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,PRELIEVO0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,ESPULSIONE0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,G1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,Q1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,IRRIGAZIONE_ALOE0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,I2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,I3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,I4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,IRRIGAZIONE_EDERA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,I1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,I5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,I6.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,F0.X,,1);
    data__->F0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,S7.X,,1);
    data__->S7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,S01.X,,1);
    data__->S01.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,S02.X,,1);
    data__->S02.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,S03.X,,1);
    data__->S03.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,S04.X,,1);
    data__->S04.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,S08.X,,1);
    data__->S08.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,SEMINA.X,,1);
    data__->SEMINA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,S09.X,,1);
    data__->S09.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,S05.X,,1);
    data__->S05.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,S06.X,,1);
    data__->S06.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,R0.X,,1);
    data__->R0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,R1.X,,1);
    data__->R1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,R2.X,,1);
    data__->R2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,R3.X,,1);
    data__->R3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,MANUTENZIONE_CUPOLA.X,,1);
    data__->MANUTENZIONE_CUPOLA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,NOTTE0.X,,1);
    data__->NOTTE0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,GIORNO0.X,,1);
    data__->GIORNO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,NOTTE0.X,,1);
    data__->NOTTE0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,Q1.X,,1);
    data__->Q1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,BUIO0.X,,1);
    data__->BUIO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,QUIETE_LUCE_BUIO0.X,,1);
    data__->QUIETE_LUCE_BUIO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,LUCE0.X,,1);
    data__->LUCE0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,PRELIEVO0.X,,1);
    data__->PRELIEVO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,ESPULSIONE0.X,,1);
    data__->ESPULSIONE0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,G1.X,,1);
    data__->G1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,QUIETE_LUCE_BUIO0.X,,1);
    data__->QUIETE_LUCE_BUIO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,QUIETE_LUCE_BUIO0.X,,1);
    data__->QUIETE_LUCE_BUIO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,QUIETE_LUCE_BUIO0.X,,1);
    data__->QUIETE_LUCE_BUIO0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,I2.X,,1);
    data__->I2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,I3.X,,1);
    data__->I3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,I4.X,,1);
    data__->I4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,I2.X,,1);
    data__->I2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,I1.X,,1);
    data__->I1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,I5.X,,1);
    data__->I5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,I6.X,,1);
    data__->I6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,I1.X,,1);
    data__->I1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // S0 action associations
  {
    char active = __GET_VAR(data__->S0.X);
    char activated = active && !data__->S0.prev_state;
    char desactivated = !active && data__->S0.prev_state;

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // F0 action associations
  {
    char active = __GET_VAR(data__->F0.X);
    char activated = active && !data__->F0.prev_state;
    char desactivated = !active && data__->F0.prev_state;

    if (active)       {__SET_VAR(data__->,APERTURA,,1);};
    if (desactivated) {__SET_VAR(data__->,APERTURA,,0);};

    if (activated) {
      data__->__action_list[__SFC_APERTO].set_remaining_time = __time_to_timespec(1, 0, 5, 0, 0, 0);
    }

  }

  // S7 action associations
  {
    char active = __GET_VAR(data__->S7.X);
    char activated = active && !data__->S7.prev_state;
    char desactivated = !active && data__->S7.prev_state;

    if (activated) {
      data__->__action_list[__SFC_T_OK10].set_remaining_time = __time_to_timespec(1, 0, 5, 0, 0, 0);
    }

  }

  // S01 action associations
  {
    char active = __GET_VAR(data__->S01.X);
    char activated = active && !data__->S01.prev_state;
    char desactivated = !active && data__->S01.prev_state;

    if (active && __time_cmp(data__->S01.T.value, __time_to_timespec(1, 0, 70, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,NA,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,NA,,0);};

    if (active && __time_cmp(data__->S01.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,AR,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,AR,,0);};

    if (active && __time_cmp(data__->S01.T.value, __time_to_timespec(1, 0, 20, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,O,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,O,,0);};

    if (activated) {
      data__->__action_list[__SFC_NA_OK].set_remaining_time = __time_to_timespec(1, 0, 20, 0, 0, 0);
    }

    if (activated) {
      data__->__action_list[__SFC_AR_OK].set_remaining_time = __time_to_timespec(1, 0, 2, 0, 0, 0);
    }

    if (activated) {
      data__->__action_list[__SFC_O_OK].set_remaining_time = __time_to_timespec(1, 0, 22, 0, 0, 0);
    }

  }

  // S08 action associations
  {
    char active = __GET_VAR(data__->S08.X);
    char activated = active && !data__->S08.prev_state;
    char desactivated = !active && data__->S08.prev_state;

    if (active)       {data__->__action_list[__SFC_TEMP_OK_0].set = 1;}

    if (active)       {data__->__action_list[__SFC_IRRIGAZIONE_OK_A].reset = 1;}

    if (active)       {data__->__action_list[__SFC_IRRIGAZIONE_OK_E].reset = 1;}

  }

  // SEMINA action associations
  {
    char active = __GET_VAR(data__->SEMINA.X);
    char activated = active && !data__->SEMINA.prev_state;
    char desactivated = !active && data__->SEMINA.prev_state;

    if (activated) {
      data__->__action_list[__SFC_SEMINA_DES].set_remaining_time = __time_to_timespec(1, 0, 11, 0, 0, 0);
    }

    if (activated) {
      data__->__action_list[__SFC_SEMINA_SIN].set_remaining_time = __time_to_timespec(1, 0, 9, 0, 0, 0);
    }

  }

  // S09 action associations
  {
    char active = __GET_VAR(data__->S09.X);
    char activated = active && !data__->S09.prev_state;
    char desactivated = !active && data__->S09.prev_state;

    if (active)       {data__->__action_list[__SFC_START2].set = 1;}

  }

  // S02 action associations
  {
    char active = __GET_VAR(data__->S02.X);
    char activated = active && !data__->S02.prev_state;
    char desactivated = !active && data__->S02.prev_state;

    if (active)       {__SET_VAR(data__->,UMIDIFICATORE_ACQUA,,1);};
    if (desactivated) {__SET_VAR(data__->,UMIDIFICATORE_ACQUA,,0);};

    if (activated) {
      data__->__action_list[__SFC_UMIDITA_OK].set_remaining_time = __time_to_timespec(1, 0, 25, 0, 0, 0);
    }

  }

  // S03 action associations
  {
    char active = __GET_VAR(data__->S03.X);
    char activated = active && !data__->S03.prev_state;
    char desactivated = !active && data__->S03.prev_state;

    if (active)       {__SET_VAR(data__->,IRRIGATORE_ACQUA_A,,1);};
    if (desactivated) {__SET_VAR(data__->,IRRIGATORE_ACQUA_A,,0);};

    if (active)       {__SET_VAR(data__->,IRRIGATORE_ACQUA_E,,1);};
    if (desactivated) {__SET_VAR(data__->,IRRIGATORE_ACQUA_E,,0);};

    if (activated) {
      data__->__action_list[__SFC_IRRIGAZIONE_OK_A].set_remaining_time = __time_to_timespec(1, 0, 15, 0, 0, 0);
    }

    if (activated) {
      data__->__action_list[__SFC_IRRIGAZIONE_OK_E].set_remaining_time = __time_to_timespec(1, 0, 17, 0, 0, 0);
    }

  }

  // R0 action associations
  {
    char active = __GET_VAR(data__->R0.X);
    char activated = active && !data__->R0.prev_state;
    char desactivated = !active && data__->R0.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_AVANTI,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_AVANTI,,0);};

    if (activated) {
      data__->__action_list[__SFC_SENSORE_P].set_remaining_time = __time_to_timespec(1, 0, 6, 0, 0, 0);
    }

    if (active)       {data__->__action_list[__SFC_A_DOCK_RICARICA].reset = 1;}

  }

  // R1 action associations
  {
    char active = __GET_VAR(data__->R1.X);
    char activated = active && !data__->R1.prev_state;
    char desactivated = !active && data__->R1.prev_state;

    if (active)       {data__->__action_list[__SFC_A_APRI_SPAZZOLA].set = 1;}

    if (active && __time_cmp(data__->R1.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,A_AZIONA_SPAZZOLA,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,A_AZIONA_SPAZZOLA,,0);};

    if (active && __time_cmp(data__->R1.T.value, __time_to_timespec(1, 0, 12, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TEMP1,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TEMP1,,0);};

  }

  // R2 action associations
  {
    char active = __GET_VAR(data__->R2.X);
    char activated = active && !data__->R2.prev_state;
    char desactivated = !active && data__->R2.prev_state;

    if (active)       {data__->__action_list[__SFC_A_APRI_SPAZZOLA].reset = 1;}

    if (active)       {data__->__action_list[__SFC_SPORCO].reset = 1;}

  }

  // R3 action associations
  {
    char active = __GET_VAR(data__->R3.X);
    char activated = active && !data__->R3.prev_state;
    char desactivated = !active && data__->R3.prev_state;

    if (active)       {__SET_VAR(data__->,A_MOTORE_INDIETRO,,1);};
    if (desactivated) {__SET_VAR(data__->,A_MOTORE_INDIETRO,,0);};

    if (active)       {data__->__action_list[__SFC_SENSORE_P].reset = 1;}

    if (active)       {__SET_VAR(data__->,A_CHIUDI_SPAZZOLA,,1);};
    if (desactivated) {__SET_VAR(data__->,A_CHIUDI_SPAZZOLA,,0);};

    if (activated) {
      data__->__action_list[__SFC_A_DOCK_RICARICA].set_remaining_time = __time_to_timespec(1, 0, 10, 0, 0, 0);
    }

  }

  // STEP3 action associations
  {
    char active = __GET_VAR(data__->STEP3.X);
    char activated = active && !data__->STEP3.prev_state;
    char desactivated = !active && data__->STEP3.prev_state;

    if (active)       {data__->__action_list[__SFC_EM_ROVER].reset = 1;}

  }

  // NOTTE0 action associations
  {
    char active = __GET_VAR(data__->NOTTE0.X);
    char activated = active && !data__->NOTTE0.prev_state;
    char desactivated = !active && data__->NOTTE0.prev_state;

    if (active)       {data__->__action_list[__SFC_NOTTE].set = 1;}

    if (activated) {
      data__->__action_list[__SFC_DURATA_NOTTE].set_remaining_time = __time_to_timespec(1, 0, 90, 0, 0, 0);
    }

    if (active)       {data__->__action_list[__SFC_GIORNO].reset = 1;}

    if (active)       {data__->__action_list[__SFC_DURATA_GIORNO].reset = 1;}

  }

  // GIORNO0 action associations
  {
    char active = __GET_VAR(data__->GIORNO0.X);
    char activated = active && !data__->GIORNO0.prev_state;
    char desactivated = !active && data__->GIORNO0.prev_state;

    if (active)       {data__->__action_list[__SFC_GIORNO].set = 1;}

    if (activated) {
      data__->__action_list[__SFC_DURATA_GIORNO].set_remaining_time = __time_to_timespec(1, 0, 90, 0, 0, 0);
    }

    if (active)       {data__->__action_list[__SFC_NOTTE].reset = 1;}

    if (active)       {data__->__action_list[__SFC_DURATA_NOTTE].reset = 1;}

  }

  // BUIO0 action associations
  {
    char active = __GET_VAR(data__->BUIO0.X);
    char activated = active && !data__->BUIO0.prev_state;
    char desactivated = !active && data__->BUIO0.prev_state;

    if (active)       {data__->__action_list[__SFC_VENTILATORE_A].set = 1;}

    if (active)       {data__->__action_list[__SFC_VENTILATORE_B].reset = 1;}

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_T_RIF_18].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_T_RIF_18].state,,0);};

  }

  // LUCE0 action associations
  {
    char active = __GET_VAR(data__->LUCE0.X);
    char activated = active && !data__->LUCE0.prev_state;
    char desactivated = !active && data__->LUCE0.prev_state;

    if (active)       {data__->__action_list[__SFC_VENTILATORE_B].set = 1;}

    if (active)       {data__->__action_list[__SFC_NOT_LUCE].reset = 1;}

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_T_RIF_24].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_T_RIF_24].state,,0);};

  }

  // PRELIEVO0 action associations
  {
    char active = __GET_VAR(data__->PRELIEVO0.X);
    char activated = active && !data__->PRELIEVO0.prev_state;
    char desactivated = !active && data__->PRELIEVO0.prev_state;

    if (active)       {data__->__action_list[__SFC_ESTRAZIONE_OSSIGENO].set = 1;}

    if (activated) {
      data__->__action_list[__SFC_ESTRAZIONE_OK].set_remaining_time = __time_to_timespec(1, 0, 10, 0, 0, 0);
    }

  }

  // ESPULSIONE0 action associations
  {
    char active = __GET_VAR(data__->ESPULSIONE0.X);
    char activated = active && !data__->ESPULSIONE0.prev_state;
    char desactivated = !active && data__->ESPULSIONE0.prev_state;

    if (active)       {data__->__action_list[__SFC_ESPULSIONE_OSSIGENO].set = 1;}

    if (active)       {data__->__action_list[__SFC_ESTRAZIONE_OSSIGENO].reset = 1;}

    if (activated) {
      data__->__action_list[__SFC_ESPULSIONE_OK].set_remaining_time = __time_to_timespec(1, 0, 10, 0, 0, 0);
    }

  }

  // G1 action associations
  {
    char active = __GET_VAR(data__->G1.X);
    char activated = active && !data__->G1.prev_state;
    char desactivated = !active && data__->G1.prev_state;

    if (active)       {data__->__action_list[__SFC_ESTRAZIONE_OK].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ESPULSIONE_OSSIGENO].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ESTRAZIONE_OSSIGENO].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ESPULSIONE_OK].reset = 1;}

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_SPORCO].set = 1;}

    if (active)       {data__->__action_list[__SFC_LUCI_EM].set = 1;}

    if (active)       {data__->__action_list[__SFC_EM_ROVER].set = 1;}

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {data__->__action_list[__SFC_LUCI_EM].reset = 1;}

  }

  // STEP4 action associations
  {
    char active = __GET_VAR(data__->STEP4.X);
    char activated = active && !data__->STEP4.prev_state;
    char desactivated = !active && data__->STEP4.prev_state;

    if (active)       {data__->__action_list[__SFC_NOT_LUCE].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LUCI_EM].reset = 1;}

  }

  // I2 action associations
  {
    char active = __GET_VAR(data__->I2.X);
    char activated = active && !data__->I2.prev_state;
    char desactivated = !active && data__->I2.prev_state;

    if (activated) {
      data__->__action_list[__SFC_SECCO1].set_remaining_time = __time_to_timespec(1, 0, 28, 0, 0, 0);
    }

  }

  // I3 action associations
  {
    char active = __GET_VAR(data__->I3.X);
    char activated = active && !data__->I3.prev_state;
    char desactivated = !active && data__->I3.prev_state;

    if (active)       {__SET_VAR(data__->,IRRIGATORE_ACQUA_A,,1);};
    if (desactivated) {__SET_VAR(data__->,IRRIGATORE_ACQUA_A,,0);};

    if (activated) {
      data__->__action_list[__SFC_IRRIGAZIONE_OK_A].set_remaining_time = __time_to_timespec(1, 0, 10, 0, 0, 0);
    }

  }

  // I4 action associations
  {
    char active = __GET_VAR(data__->I4.X);
    char activated = active && !data__->I4.prev_state;
    char desactivated = !active && data__->I4.prev_state;

    if (active)       {data__->__action_list[__SFC_SECCO1].reset = 1;}

    if (active)       {data__->__action_list[__SFC_IRRIGAZIONE_OK_A].reset = 1;}

  }

  // I1 action associations
  {
    char active = __GET_VAR(data__->I1.X);
    char activated = active && !data__->I1.prev_state;
    char desactivated = !active && data__->I1.prev_state;

    if (activated) {
      data__->__action_list[__SFC_SECCO2].set_remaining_time = __time_to_timespec(1, 0, 12, 0, 0, 0);
    }

  }

  // I5 action associations
  {
    char active = __GET_VAR(data__->I5.X);
    char activated = active && !data__->I5.prev_state;
    char desactivated = !active && data__->I5.prev_state;

    if (active)       {__SET_VAR(data__->,IRRIGATORE_ACQUA_E,,1);};
    if (desactivated) {__SET_VAR(data__->,IRRIGATORE_ACQUA_E,,0);};

    if (activated) {
      data__->__action_list[__SFC_IRRIGAZIONE_OK_E].set_remaining_time = __time_to_timespec(1, 0, 10, 0, 0, 0);
    }

  }

  // I6 action associations
  {
    char active = __GET_VAR(data__->I6.X);
    char activated = active && !data__->I6.prev_state;
    char desactivated = !active && data__->I6.prev_state;

    if (active)       {data__->__action_list[__SFC_SECCO2].reset = 1;}

    if (active)       {data__->__action_list[__SFC_IRRIGAZIONE_OK_E].reset = 1;}

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
  if (data__->__action_list[__SFC_APERTURA].reset) {
    __SET_VAR(data__->,APERTURA,,0);
  }
  else if (data__->__action_list[__SFC_APERTURA].set) {
    __SET_VAR(data__->,APERTURA,,1);
  }
  if (data__->__action_list[__SFC_APERTO].reset) {
    __SET_VAR(data__->,APERTO,,0);
  }
  else if (data__->__action_list[__SFC_APERTO].set) {
    __SET_VAR(data__->,APERTO,,1);
  }
  if (data__->__action_list[__SFC_NA].reset) {
    __SET_VAR(data__->,NA,,0);
  }
  else if (data__->__action_list[__SFC_NA].set) {
    __SET_VAR(data__->,NA,,1);
  }
  if (data__->__action_list[__SFC_AR].reset) {
    __SET_VAR(data__->,AR,,0);
  }
  else if (data__->__action_list[__SFC_AR].set) {
    __SET_VAR(data__->,AR,,1);
  }
  if (data__->__action_list[__SFC_O].reset) {
    __SET_VAR(data__->,O,,0);
  }
  else if (data__->__action_list[__SFC_O].set) {
    __SET_VAR(data__->,O,,1);
  }
  if (data__->__action_list[__SFC_NA_OK].reset) {
    __SET_VAR(data__->,NA_OK,,0);
  }
  else if (data__->__action_list[__SFC_NA_OK].set) {
    __SET_VAR(data__->,NA_OK,,1);
  }
  if (data__->__action_list[__SFC_AR_OK].reset) {
    __SET_VAR(data__->,AR_OK,,0);
  }
  else if (data__->__action_list[__SFC_AR_OK].set) {
    __SET_VAR(data__->,AR_OK,,1);
  }
  if (data__->__action_list[__SFC_O_OK].reset) {
    __SET_VAR(data__->,O_OK,,0);
  }
  else if (data__->__action_list[__SFC_O_OK].set) {
    __SET_VAR(data__->,O_OK,,1);
  }
  if (data__->__action_list[__SFC_IRRIGAZIONE_OK_A].reset) {
    __SET_VAR(data__->,IRRIGAZIONE_OK_A,,0);
  }
  else if (data__->__action_list[__SFC_IRRIGAZIONE_OK_A].set) {
    __SET_VAR(data__->,IRRIGAZIONE_OK_A,,1);
  }
  if (data__->__action_list[__SFC_IRRIGAZIONE_OK_E].reset) {
    __SET_VAR(data__->,IRRIGAZIONE_OK_E,,0);
  }
  else if (data__->__action_list[__SFC_IRRIGAZIONE_OK_E].set) {
    __SET_VAR(data__->,IRRIGAZIONE_OK_E,,1);
  }
  if (data__->__action_list[__SFC_SEMINA_DES].reset) {
    __SET_VAR(data__->,SEMINA_DES,,0);
  }
  else if (data__->__action_list[__SFC_SEMINA_DES].set) {
    __SET_VAR(data__->,SEMINA_DES,,1);
  }
  if (data__->__action_list[__SFC_SEMINA_SIN].reset) {
    __SET_VAR(data__->,SEMINA_SIN,,0);
  }
  else if (data__->__action_list[__SFC_SEMINA_SIN].set) {
    __SET_VAR(data__->,SEMINA_SIN,,1);
  }
  if (data__->__action_list[__SFC_START2].reset) {
    __SET_VAR(data__->,START2,,0);
  }
  else if (data__->__action_list[__SFC_START2].set) {
    __SET_VAR(data__->,START2,,1);
  }
  if (data__->__action_list[__SFC_UMIDIFICATORE_ACQUA].reset) {
    __SET_VAR(data__->,UMIDIFICATORE_ACQUA,,0);
  }
  else if (data__->__action_list[__SFC_UMIDIFICATORE_ACQUA].set) {
    __SET_VAR(data__->,UMIDIFICATORE_ACQUA,,1);
  }
  if (data__->__action_list[__SFC_UMIDITA_OK].reset) {
    __SET_VAR(data__->,UMIDITA_OK,,0);
  }
  else if (data__->__action_list[__SFC_UMIDITA_OK].set) {
    __SET_VAR(data__->,UMIDITA_OK,,1);
  }
  if (data__->__action_list[__SFC_IRRIGATORE_ACQUA_A].reset) {
    __SET_VAR(data__->,IRRIGATORE_ACQUA_A,,0);
  }
  else if (data__->__action_list[__SFC_IRRIGATORE_ACQUA_A].set) {
    __SET_VAR(data__->,IRRIGATORE_ACQUA_A,,1);
  }
  if (data__->__action_list[__SFC_IRRIGATORE_ACQUA_E].reset) {
    __SET_VAR(data__->,IRRIGATORE_ACQUA_E,,0);
  }
  else if (data__->__action_list[__SFC_IRRIGATORE_ACQUA_E].set) {
    __SET_VAR(data__->,IRRIGATORE_ACQUA_E,,1);
  }
  if (data__->__action_list[__SFC_A_MOTORE_AVANTI].reset) {
    __SET_VAR(data__->,A_MOTORE_AVANTI,,0);
  }
  else if (data__->__action_list[__SFC_A_MOTORE_AVANTI].set) {
    __SET_VAR(data__->,A_MOTORE_AVANTI,,1);
  }
  if (data__->__action_list[__SFC_SENSORE_P].reset) {
    __SET_VAR(data__->,SENSORE_P,,0);
  }
  else if (data__->__action_list[__SFC_SENSORE_P].set) {
    __SET_VAR(data__->,SENSORE_P,,1);
  }
  if (data__->__action_list[__SFC_A_DOCK_RICARICA].reset) {
    __SET_VAR(data__->,A_DOCK_RICARICA,,0);
  }
  else if (data__->__action_list[__SFC_A_DOCK_RICARICA].set) {
    __SET_VAR(data__->,A_DOCK_RICARICA,,1);
  }
  if (data__->__action_list[__SFC_A_APRI_SPAZZOLA].reset) {
    __SET_VAR(data__->,A_APRI_SPAZZOLA,,0);
  }
  else if (data__->__action_list[__SFC_A_APRI_SPAZZOLA].set) {
    __SET_VAR(data__->,A_APRI_SPAZZOLA,,1);
  }
  if (data__->__action_list[__SFC_A_AZIONA_SPAZZOLA].reset) {
    __SET_VAR(data__->,A_AZIONA_SPAZZOLA,,0);
  }
  else if (data__->__action_list[__SFC_A_AZIONA_SPAZZOLA].set) {
    __SET_VAR(data__->,A_AZIONA_SPAZZOLA,,1);
  }
  if (data__->__action_list[__SFC_TEMP1].reset) {
    __SET_VAR(data__->,TEMP1,,0);
  }
  else if (data__->__action_list[__SFC_TEMP1].set) {
    __SET_VAR(data__->,TEMP1,,1);
  }
  if (data__->__action_list[__SFC_SPORCO].reset) {
    __SET_VAR(data__->,SPORCO,,0);
  }
  else if (data__->__action_list[__SFC_SPORCO].set) {
    __SET_VAR(data__->,SPORCO,,1);
  }
  if (data__->__action_list[__SFC_A_MOTORE_INDIETRO].reset) {
    __SET_VAR(data__->,A_MOTORE_INDIETRO,,0);
  }
  else if (data__->__action_list[__SFC_A_MOTORE_INDIETRO].set) {
    __SET_VAR(data__->,A_MOTORE_INDIETRO,,1);
  }
  if (data__->__action_list[__SFC_A_CHIUDI_SPAZZOLA].reset) {
    __SET_VAR(data__->,A_CHIUDI_SPAZZOLA,,0);
  }
  else if (data__->__action_list[__SFC_A_CHIUDI_SPAZZOLA].set) {
    __SET_VAR(data__->,A_CHIUDI_SPAZZOLA,,1);
  }
  if (data__->__action_list[__SFC_EM_ROVER].reset) {
    __SET_VAR(data__->,EM_ROVER,,0);
  }
  else if (data__->__action_list[__SFC_EM_ROVER].set) {
    __SET_VAR(data__->,EM_ROVER,,1);
  }
  if (data__->__action_list[__SFC_NOTTE].reset) {
    __SET_VAR(data__->,NOTTE,,0);
  }
  else if (data__->__action_list[__SFC_NOTTE].set) {
    __SET_VAR(data__->,NOTTE,,1);
  }
  if (data__->__action_list[__SFC_DURATA_NOTTE].reset) {
    __SET_VAR(data__->,DURATA_NOTTE,,0);
  }
  else if (data__->__action_list[__SFC_DURATA_NOTTE].set) {
    __SET_VAR(data__->,DURATA_NOTTE,,1);
  }
  if (data__->__action_list[__SFC_GIORNO].reset) {
    __SET_VAR(data__->,GIORNO,,0);
  }
  else if (data__->__action_list[__SFC_GIORNO].set) {
    __SET_VAR(data__->,GIORNO,,1);
  }
  if (data__->__action_list[__SFC_DURATA_GIORNO].reset) {
    __SET_VAR(data__->,DURATA_GIORNO,,0);
  }
  else if (data__->__action_list[__SFC_DURATA_GIORNO].set) {
    __SET_VAR(data__->,DURATA_GIORNO,,1);
  }
  if (data__->__action_list[__SFC_VENTILATORE_A].reset) {
    __SET_VAR(data__->,VENTILATORE_A,,0);
  }
  else if (data__->__action_list[__SFC_VENTILATORE_A].set) {
    __SET_VAR(data__->,VENTILATORE_A,,1);
  }
  if (data__->__action_list[__SFC_VENTILATORE_B].reset) {
    __SET_VAR(data__->,VENTILATORE_B,,0);
  }
  else if (data__->__action_list[__SFC_VENTILATORE_B].set) {
    __SET_VAR(data__->,VENTILATORE_B,,1);
  }
  if (data__->__action_list[__SFC_NOT_LUCE].reset) {
    __SET_VAR(data__->,NOT_LUCE,,0);
  }
  else if (data__->__action_list[__SFC_NOT_LUCE].set) {
    __SET_VAR(data__->,NOT_LUCE,,1);
  }
  if (data__->__action_list[__SFC_ESTRAZIONE_OSSIGENO].reset) {
    __SET_VAR(data__->,ESTRAZIONE_OSSIGENO,,0);
  }
  else if (data__->__action_list[__SFC_ESTRAZIONE_OSSIGENO].set) {
    __SET_VAR(data__->,ESTRAZIONE_OSSIGENO,,1);
  }
  if (data__->__action_list[__SFC_ESTRAZIONE_OK].reset) {
    __SET_VAR(data__->,ESTRAZIONE_OK,,0);
  }
  else if (data__->__action_list[__SFC_ESTRAZIONE_OK].set) {
    __SET_VAR(data__->,ESTRAZIONE_OK,,1);
  }
  if (data__->__action_list[__SFC_ESPULSIONE_OSSIGENO].reset) {
    __SET_VAR(data__->,ESPULSIONE_OSSIGENO,,0);
  }
  else if (data__->__action_list[__SFC_ESPULSIONE_OSSIGENO].set) {
    __SET_VAR(data__->,ESPULSIONE_OSSIGENO,,1);
  }
  if (data__->__action_list[__SFC_ESPULSIONE_OK].reset) {
    __SET_VAR(data__->,ESPULSIONE_OK,,0);
  }
  else if (data__->__action_list[__SFC_ESPULSIONE_OK].set) {
    __SET_VAR(data__->,ESPULSIONE_OK,,1);
  }
  if (data__->__action_list[__SFC_LUCI_EM].reset) {
    __SET_VAR(data__->,LUCI_EM,,0);
  }
  else if (data__->__action_list[__SFC_LUCI_EM].set) {
    __SET_VAR(data__->,LUCI_EM,,1);
  }
  if (data__->__action_list[__SFC_SECCO1].reset) {
    __SET_VAR(data__->,SECCO1,,0);
  }
  else if (data__->__action_list[__SFC_SECCO1].set) {
    __SET_VAR(data__->,SECCO1,,1);
  }
  if (data__->__action_list[__SFC_SECCO2].reset) {
    __SET_VAR(data__->,SECCO2,,0);
  }
  else if (data__->__action_list[__SFC_SECCO2].set) {
    __SET_VAR(data__->,SECCO2,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->EM_ROVER,));
    R_TRIG_body__(&data__->R_TRIG1);
  }

  if(__GET_VAR(data__->__action_list[__SFC_T_OK10].state)) {
    __SET_VAR(data__->,TEMP_OK,,GE__BOOL__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (INT)__GET_VAR(data__->TEMP_SENS,),
      (INT)10));
  }

  if(__GET_VAR(data__->__action_list[__SFC_TEMP_OK_0].state)) {
    __SET_VAR(data__->,TEMP_OK,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_T_RIF_18].state)) {
    __SET_VAR(data__->,TEMP_RIF,,18);
  }

  if(__GET_VAR(data__->__action_list[__SFC_T_RIF_24].state)) {
    __SET_VAR(data__->,TEMP_RIF,,24);
  }



  goto __end;

__end:
  return;
} // PROGRAM0_body__() 

// Steps undefinitions
#undef S0
#undef __SFC_S0
#undef F0
#undef __SFC_F0
#undef S7
#undef __SFC_S7
#undef S01
#undef __SFC_S01
#undef S04
#undef __SFC_S04
#undef S08
#undef __SFC_S08
#undef SEMINA
#undef __SFC_SEMINA
#undef S09
#undef __SFC_S09
#undef S02
#undef __SFC_S02
#undef S05
#undef __SFC_S05
#undef S03
#undef __SFC_S03
#undef S06
#undef __SFC_S06
#undef MANUTENZIONE_CUPOLA
#undef __SFC_MANUTENZIONE_CUPOLA
#undef R0
#undef __SFC_R0
#undef R1
#undef __SFC_R1
#undef R2
#undef __SFC_R2
#undef R3
#undef __SFC_R3
#undef STEP3
#undef __SFC_STEP3
#undef S00
#undef __SFC_S00
#undef NOTTE0
#undef __SFC_NOTTE0
#undef GIORNO0
#undef __SFC_GIORNO0
#undef QUIETE_LUCE_BUIO0
#undef __SFC_QUIETE_LUCE_BUIO0
#undef Q1
#undef __SFC_Q1
#undef BUIO0
#undef __SFC_BUIO0
#undef LUCE0
#undef __SFC_LUCE0
#undef PRELIEVO0
#undef __SFC_PRELIEVO0
#undef ESPULSIONE0
#undef __SFC_ESPULSIONE0
#undef G1
#undef __SFC_G1
#undef STEP0
#undef __SFC_STEP0
#undef STEP1
#undef __SFC_STEP1
#undef STEP4
#undef __SFC_STEP4
#undef IRRIGAZIONE_ALOE0
#undef __SFC_IRRIGAZIONE_ALOE0
#undef I2
#undef __SFC_I2
#undef I3
#undef __SFC_I3
#undef I4
#undef __SFC_I4
#undef IRRIGAZIONE_EDERA0
#undef __SFC_IRRIGAZIONE_EDERA0
#undef I1
#undef __SFC_I1
#undef I5
#undef __SFC_I5
#undef I6
#undef __SFC_I6

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_T_OK10
#undef __SFC_TEMP_OK_0
#undef __SFC_T_RIF_18
#undef __SFC_T_RIF_24
#undef __SFC_APERTURA
#undef __SFC_APERTO
#undef __SFC_NA
#undef __SFC_AR
#undef __SFC_O
#undef __SFC_NA_OK
#undef __SFC_AR_OK
#undef __SFC_O_OK
#undef __SFC_IRRIGAZIONE_OK_A
#undef __SFC_IRRIGAZIONE_OK_E
#undef __SFC_SEMINA_DES
#undef __SFC_SEMINA_SIN
#undef __SFC_START2
#undef __SFC_UMIDIFICATORE_ACQUA
#undef __SFC_UMIDITA_OK
#undef __SFC_IRRIGATORE_ACQUA_A
#undef __SFC_IRRIGATORE_ACQUA_E
#undef __SFC_A_MOTORE_AVANTI
#undef __SFC_SENSORE_P
#undef __SFC_A_DOCK_RICARICA
#undef __SFC_A_APRI_SPAZZOLA
#undef __SFC_A_AZIONA_SPAZZOLA
#undef __SFC_TEMP1
#undef __SFC_SPORCO
#undef __SFC_A_MOTORE_INDIETRO
#undef __SFC_A_CHIUDI_SPAZZOLA
#undef __SFC_EM_ROVER
#undef __SFC_NOTTE
#undef __SFC_DURATA_NOTTE
#undef __SFC_GIORNO
#undef __SFC_DURATA_GIORNO
#undef __SFC_VENTILATORE_A
#undef __SFC_VENTILATORE_B
#undef __SFC_NOT_LUCE
#undef __SFC_ESTRAZIONE_OSSIGENO
#undef __SFC_ESTRAZIONE_OK
#undef __SFC_ESPULSIONE_OSSIGENO
#undef __SFC_ESPULSIONE_OK
#undef __SFC_LUCI_EM
#undef __SFC_SECCO1
#undef __SFC_SECCO2





