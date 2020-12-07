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





void MAINLD_init__(MAINLD *data__, BOOL retain) {
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORW_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETR_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUIETE_STORE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUIETE_RET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUIETE_FORW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUIETE_CAR_SCAR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUIETE_CAR_ENT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PROVA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PROVA2,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAINLD_body__(MAINLD *data__) {
  // Initialise TEMP variables

  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,START_0,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,FORW_0,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,RETR_0,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,QUIETE_STORE,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,QUIETE_RET,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,QUIETE_FORW,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,PROVA,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,QUIETE_CAR_ENT,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,PROVA2,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,QUIETE_CAR_SCAR,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // MAINLD_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->START_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AT_ENTRY_SENSOR,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->AT_LOAD_SENSOR,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->AT_MIDDLE_SENSOR,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Z_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORW_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_EXTERNAL(BOOL,AT_UNLOAD_SENSOR,data__->AT_UNLOAD_SENSOR,retain)
  __INIT_VAR(data__->AT_EXIT_SENSOR,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RETRIEVE_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARRELLO_ENTRATA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARRELLO_CARICO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARICA_PALLET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LIFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SCARICA_PALLET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORW_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ERRORE_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARRELLO_USCITA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARRELLO_SCARICO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETR_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSITION,0,retain)
  __INIT_VAR(data__->MANUAL_POSITION,0,retain)
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->SYNC0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SYNC1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SYNC2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SYNC3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SYNC4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRAS_FERMO,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_BOOL_54 temp = {{__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)}};
    __SET_VAR(data__->,MAGAZZINO,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->TROVATO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->MAX_DIM,54,retain)
  __INIT_VAR(data__->CONT_MAG,0,retain)
  __INIT_VAR(data__->OK_RETRIEVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OK_INS,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->OK_RET_POS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SISTEMA_AVVIATO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STORE_AVVIATO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRIEVE_AVVIATO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARD_AVVIATO,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 49;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[15].X,,1);
  __SET_VAR(data__->,__step_list[18].X,,1);
  __SET_VAR(data__->,__step_list[21].X,,1);
  __SET_VAR(data__->,__step_list[24].X,,1);
  __SET_VAR(data__->,__step_list[34].X,,1);
  __SET_VAR(data__->,__step_list[37].X,,1);
  __SET_VAR(data__->,__step_list[42].X,,1);
  data__->__nb_actions = 29;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 52;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define QUIETE_STORE __step_list[0]
#define __SFC_QUIETE_STORE 0
#define VER_ST_FASI __step_list[1]
#define __SFC_VER_ST_FASI 1
#define STORE __step_list[2]
#define __SFC_STORE 2
#define CARICA_PAL __step_list[3]
#define __SFC_CARICA_PAL 3
#define SCARICA_PA __step_list[4]
#define __SFC_SCARICA_PA 4
#define AUTO_MODE __step_list[5]
#define __SFC_AUTO_MODE 5
#define ABBASSA_LIF __step_list[6]
#define __SFC_ABBASSA_LIF 6
#define INTER_0 __step_list[7]
#define __SFC_INTER_0 7
#define STOC __step_list[8]
#define __SFC_STOC 8
#define TIME_W0 __step_list[9]
#define __SFC_TIME_W0 9
#define ABBASSA_SCAR_PAL __step_list[10]
#define __SFC_ABBASSA_SCAR_PAL 10
#define MAG_PLUS __step_list[11]
#define __SFC_MAG_PLUS 11
#define MANUAL_MODE __step_list[12]
#define __SFC_MANUAL_MODE 12
#define ABBASSA_LIF_MAN __step_list[13]
#define __SFC_ABBASSA_LIF_MAN 13
#define ANNULLA_INS __step_list[14]
#define __SFC_ANNULLA_INS 14
#define FORW_0 __step_list[15]
#define __SFC_FORW_0 15
#define FORW_ON __step_list[16]
#define __SFC_FORW_ON 16
#define FORW_OFF __step_list[17]
#define __SFC_FORW_OFF 17
#define RETR_0 __step_list[18]
#define __SFC_RETR_0 18
#define RETR_ON __step_list[19]
#define __SFC_RETR_ON 19
#define STEP0 __step_list[20]
#define __SFC_STEP0 20
#define START_0 __step_list[21]
#define __SFC_START_0 21
#define START_ON __step_list[22]
#define __SFC_START_ON 22
#define START_OFF __step_list[23]
#define __SFC_START_OFF 23
#define QUIETE_RET __step_list[24]
#define __SFC_QUIETE_RET 24
#define VER_RET_FASI __step_list[25]
#define __SFC_VER_RET_FASI 25
#define RETR_START __step_list[26]
#define __SFC_RETR_START 26
#define CONTROLLO_POSIZIONE __step_list[27]
#define __SFC_CONTROLLO_POSIZIONE 27
#define WAIT_DUMMY __step_list[28]
#define __SFC_WAIT_DUMMY 28
#define RETR __step_list[29]
#define __SFC_RETR 29
#define BACK_0 __step_list[30]
#define __SFC_BACK_0 30
#define SCAR_RET __step_list[31]
#define __SFC_SCAR_RET 31
#define MAG_SUB __step_list[32]
#define __SFC_MAG_SUB 32
#define ANNULLA_RETR __step_list[33]
#define __SFC_ANNULLA_RETR 33
#define QUIETE_CAR_SCAR __step_list[34]
#define __SFC_QUIETE_CAR_SCAR 34
#define MUOVI_CAR_SCAR0 __step_list[35]
#define __SFC_MUOVI_CAR_SCAR0 35
#define RISORSA_OCC __step_list[36]
#define __SFC_RISORSA_OCC 36
#define QUIETE_CAR_ENT __step_list[37]
#define __SFC_QUIETE_CAR_ENT 37
#define ATTESA_AVVIO_0 __step_list[38]
#define __SFC_ATTESA_AVVIO_0 38
#define STEP1 __step_list[39]
#define __SFC_STEP1 39
#define MUOVI_CAR_ENT __step_list[40]
#define __SFC_MUOVI_CAR_ENT 40
#define FERMA_CAR_ENT __step_list[41]
#define __SFC_FERMA_CAR_ENT 41
#define QUIETE_FORW __step_list[42]
#define __SFC_QUIETE_FORW 42
#define VER_FORW_FASI __step_list[43]
#define __SFC_VER_FORW_FASI 43
#define FORW_START __step_list[44]
#define __SFC_FORW_START 44
#define CARICA_PAL_FW __step_list[45]
#define __SFC_CARICA_PAL_FW 45
#define SCARICA_PAL_FW __step_list[46]
#define __SFC_SCARICA_PAL_FW 46
#define DUMMY_TMP __step_list[47]
#define __SFC_DUMMY_TMP 47
#define FORW_START0 __step_list[48]
#define __SFC_FORW_START0 48

// Actions definitions
#define __SFC_RICERCA_PRIMO_LIBERO 0
#define __SFC_ABBASSA_LIF_INLINE1 1
#define __SFC_ABBASSA_SCAR_PAL_INLINE2 2
#define __SFC_MAG_PLUS_INLINE3 3
#define __SFC_MAG_PLUS_INLINE4 4
#define __SFC_CHECK_MANUAL_POSITION 5
#define __SFC_CHECK_RETRIEVE_POSITION 6
#define __SFC_BACK_0_INLINE5 7
#define __SFC_MAG_SUB_INLINE6 8
#define __SFC_MAG_SUB_INLINE7 9
#define __SFC_STORE_AVVIATO 10
#define __SFC_CARICA_PALLET 11
#define __SFC_LIFT 12
#define __SFC_SYNC0 13
#define __SFC_SCARICA_PALLET 14
#define __SFC_FORW_LIGHT 15
#define __SFC_SISTEMA_AVVIATO 16
#define __SFC_RETR_LIGHT 17
#define __SFC_START_LIGHT 18
#define __SFC_RETRIEVE_AVVIATO 19
#define __SFC_SYNC2 20
#define __SFC_CARRELLO_SCARICO 21
#define __SFC_SYNC4 22
#define __SFC_CARRELLO_USCITA 23
#define __SFC_SYNC1 24
#define __SFC_CARRELLO_CARICO 25
#define __SFC_CARRELLO_ENTRATA 26
#define __SFC_FORWARD_AVVIATO 27
#define __SFC_SYNC3 28

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
  if (__GET_VAR(data__->QUIETE_STORE.X)) {
    __SET_VAR(data__->,__transition_list[0],,((__GET_VAR(data__->START_BUTTON,) && !(__GET_VAR(data__->RETRIEVE_BUTTON,))) && !(__GET_VAR(data__->FORW_BUTTON,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,((__GET_VAR(data__->START_BUTTON,) && !(__GET_VAR(data__->RETRIEVE_BUTTON,))) && !(__GET_VAR(data__->FORW_BUTTON,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->VER_ST_FASI.X)) {
    __SET_VAR(data__->,__transition_list[1],,(!(__GET_VAR(data__->RETRIEVE_AVVIATO,)) && !(__GET_VAR(data__->FORWARD_AVVIATO,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(!(__GET_VAR(data__->RETRIEVE_AVVIATO,)) && !(__GET_VAR(data__->FORWARD_AVVIATO,))));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STORE.X)) {
    __SET_VAR(data__->,__transition_list[2],,((__GET_VAR(data__->CONT_MAG,) != __GET_VAR(data__->MAX_DIM,)) && !(__GET_VAR(data__->AT_LOAD_SENSOR,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,((__GET_VAR(data__->CONT_MAG,) != __GET_VAR(data__->MAX_DIM,)) && !(__GET_VAR(data__->AT_LOAD_SENSOR,))));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->CARICA_PAL.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->SYNC0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->SYNC0,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->SCARICA_PA.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->AUTO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->AUTO,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->AUTO_MODE.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->AT_MIDDLE_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->AT_MIDDLE_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->ABBASSA_LIF.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->SYNC0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->SYNC0,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->INTER_0.X)) {
    __SET_VAR(data__->,__transition_list[7],,(!(__GET_VAR(data__->X_SENSOR,)) && !(__GET_VAR(data__->Z_SENSOR,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,(!(__GET_VAR(data__->X_SENSOR,)) && !(__GET_VAR(data__->Z_SENSOR,))));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STOC.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->SYNC0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->SYNC0,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->TIME_W0.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->SYNC0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->SYNC0,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->ABBASSA_SCAR_PAL.X)) {
    __SET_VAR(data__->,__transition_list[10],,((__GET_VAR(data__->SYNC0,) && !(__GET_VAR(data__->X_SENSOR,))) && !(__GET_VAR(data__->Z_SENSOR,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,((__GET_VAR(data__->SYNC0,) && !(__GET_VAR(data__->X_SENSOR,))) && !(__GET_VAR(data__->Z_SENSOR,))));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MAG_PLUS.X)) {
    __SET_VAR(data__->,__transition_list[11],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,1);
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->SCARICA_PA.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->MANUAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->MANUAL,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->MANUAL_MODE.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->AT_MIDDLE_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->AT_MIDDLE_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->ABBASSA_LIF_MAN.X)) {
    __SET_VAR(data__->,__transition_list[14],,((__GET_VAR(data__->POSITION,) != 0) && (__GET_VAR(data__->POSITION,) != 2167)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,((__GET_VAR(data__->POSITION,) != 0) && (__GET_VAR(data__->POSITION,) != 2167)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STORE.X)) {
    __SET_VAR(data__->,__transition_list[15],,(__GET_VAR(data__->CONT_MAG,) == __GET_VAR(data__->MAX_DIM,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,(__GET_VAR(data__->CONT_MAG,) == __GET_VAR(data__->MAX_DIM,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->ANNULLA_INS.X)) {
    __SET_VAR(data__->,__transition_list[16],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,1);
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->FORW_0.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->FORW_BUTTON,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->FORW_BUTTON,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->FORW_ON.X)) {
    __SET_VAR(data__->,__transition_list[18],,!(__GET_VAR(data__->FORW_BUTTON,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,!(__GET_VAR(data__->FORW_BUTTON,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->FORW_OFF.X)) {
    __SET_VAR(data__->,__transition_list[19],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,1);
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->RETR_0.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->RETRIEVE_BUTTON,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->RETRIEVE_BUTTON,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->RETR_ON.X)) {
    __SET_VAR(data__->,__transition_list[21],,!(__GET_VAR(data__->RETRIEVE_BUTTON,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,!(__GET_VAR(data__->RETRIEVE_BUTTON,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
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
  if (__GET_VAR(data__->START_0.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->START_BUTTON,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->START_BUTTON,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->START_ON.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_VAR(data__->START_BUTTON,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_VAR(data__->START_BUTTON,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->START_OFF.X)) {
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
  if (__GET_VAR(data__->QUIETE_RET.X)) {
    __SET_VAR(data__->,__transition_list[26],,((__GET_VAR(data__->RETRIEVE_BUTTON,) && !(__GET_VAR(data__->START_BUTTON,))) && !(__GET_VAR(data__->FORW_BUTTON,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,((__GET_VAR(data__->RETRIEVE_BUTTON,) && !(__GET_VAR(data__->START_BUTTON,))) && !(__GET_VAR(data__->FORW_BUTTON,))));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->VER_RET_FASI.X)) {
    __SET_VAR(data__->,__transition_list[27],,(!(__GET_VAR(data__->STORE_AVVIATO,)) && !(__GET_VAR(data__->FORWARD_AVVIATO,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,(!(__GET_VAR(data__->STORE_AVVIATO,)) && !(__GET_VAR(data__->FORWARD_AVVIATO,))));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->RETR_START.X)) {
    __SET_VAR(data__->,__transition_list[28],,(__GET_VAR(data__->CONT_MAG,) != 0));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,(__GET_VAR(data__->CONT_MAG,) != 0));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->CONTROLLO_POSIZIONE.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_VAR(data__->OK_RET_POS,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->OK_RET_POS,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->WAIT_DUMMY.X)) {
    __SET_VAR(data__->,__transition_list[30],,((!(__GET_VAR(data__->X_SENSOR,)) && !(__GET_VAR(data__->Z_SENSOR,))) && __GET_VAR(data__->SYNC2,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,((!(__GET_VAR(data__->X_SENSOR,)) && !(__GET_VAR(data__->Z_SENSOR,))) && __GET_VAR(data__->SYNC2,)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->RETR.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->SYNC2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->SYNC2,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->BACK_0.X)) {
    __SET_VAR(data__->,__transition_list[32],,(((__GET_VAR(data__->SYNC2,) && !(__GET_VAR(data__->X_SENSOR,))) && !(__GET_VAR(data__->Z_SENSOR,))) && __GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,(((__GET_VAR(data__->SYNC2,) && !(__GET_VAR(data__->X_SENSOR,))) && !(__GET_VAR(data__->Z_SENSOR,))) && __GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->SCAR_RET.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_VAR(data__->SYNC2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->SYNC2,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->MAG_SUB.X)) {
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
  if (__GET_VAR(data__->RETR_START.X)) {
    __SET_VAR(data__->,__transition_list[35],,(__GET_VAR(data__->CONT_MAG,) == 0));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,(__GET_VAR(data__->CONT_MAG,) == 0));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->ANNULLA_RETR.X)) {
    __SET_VAR(data__->,__transition_list[36],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,1);
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->QUIETE_CAR_SCAR.X)) {
    __SET_VAR(data__->,__transition_list[37],,!(__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,!(__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->MUOVI_CAR_SCAR0.X)) {
    __SET_VAR(data__->,__transition_list[38],,__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->RISORSA_OCC.X)) {
    __SET_VAR(data__->,__transition_list[39],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,1);
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->QUIETE_CAR_ENT.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_VAR(data__->SISTEMA_AVVIATO,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->SISTEMA_AVVIATO,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->ATTESA_AVVIO_0.X)) {
    __SET_VAR(data__->,__transition_list[41],,(!(__GET_VAR(data__->AT_ENTRY_SENSOR,)) && __GET_VAR(data__->AT_LOAD_SENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,(!(__GET_VAR(data__->AT_ENTRY_SENSOR,)) && __GET_VAR(data__->AT_LOAD_SENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[42],,__GET_VAR(data__->SYNC1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->SYNC1,));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->MUOVI_CAR_ENT.X)) {
    __SET_VAR(data__->,__transition_list[43],,!(__GET_VAR(data__->AT_LOAD_SENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,!(__GET_VAR(data__->AT_LOAD_SENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->FERMA_CAR_ENT.X)) {
    __SET_VAR(data__->,__transition_list[44],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,1);
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->QUIETE_FORW.X)) {
    __SET_VAR(data__->,__transition_list[45],,((__GET_VAR(data__->FORW_BUTTON,) && !(__GET_VAR(data__->RETRIEVE_BUTTON,))) && !(__GET_VAR(data__->START_BUTTON,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,((__GET_VAR(data__->FORW_BUTTON,) && !(__GET_VAR(data__->RETRIEVE_BUTTON,))) && !(__GET_VAR(data__->START_BUTTON,))));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->VER_FORW_FASI.X)) {
    __SET_VAR(data__->,__transition_list[46],,(!(__GET_VAR(data__->STORE_AVVIATO,)) && !(__GET_VAR(data__->RETRIEVE_AVVIATO,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,(!(__GET_VAR(data__->STORE_AVVIATO,)) && !(__GET_VAR(data__->RETRIEVE_AVVIATO,))));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->FORW_START.X)) {
    __SET_VAR(data__->,__transition_list[47],,!(__GET_VAR(data__->AT_LOAD_SENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,!(__GET_VAR(data__->AT_LOAD_SENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->CARICA_PAL_FW.X)) {
    __SET_VAR(data__->,__transition_list[48],,(__GET_VAR(data__->SYNC3,) && __GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,(__GET_VAR(data__->SYNC3,) && __GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->SCARICA_PAL_FW.X)) {
    __SET_VAR(data__->,__transition_list[49],,__GET_VAR(data__->SYNC3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->SYNC3,));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->DUMMY_TMP.X)) {
    __SET_VAR(data__->,__transition_list[50],,__GET_VAR(data__->SYNC3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->SYNC3,));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->FORW_START0.X)) {
    __SET_VAR(data__->,__transition_list[51],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,1);
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,QUIETE_STORE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,VER_ST_FASI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STORE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,CARICA_PAL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,SCARICA_PA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,AUTO_MODE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,ABBASSA_LIF.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,INTER_0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STOC.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TIME_W0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,ABBASSA_SCAR_PAL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MAG_PLUS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,SCARICA_PA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,MANUAL_MODE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,ABBASSA_LIF_MAN.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STORE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,ANNULLA_INS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,FORW_0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,FORW_ON.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,FORW_OFF.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,RETR_0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,RETR_ON.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,START_0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,START_ON.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,START_OFF.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,QUIETE_RET.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,VER_RET_FASI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,RETR_START.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,CONTROLLO_POSIZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,WAIT_DUMMY.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,RETR.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,BACK_0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,SCAR_RET.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,MAG_SUB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,RETR_START.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,ANNULLA_RETR.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,QUIETE_CAR_SCAR.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,MUOVI_CAR_SCAR0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,RISORSA_OCC.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,QUIETE_CAR_ENT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,ATTESA_AVVIO_0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,MUOVI_CAR_ENT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,FERMA_CAR_ENT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,QUIETE_FORW.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,VER_FORW_FASI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,FORW_START.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,CARICA_PAL_FW.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,SCARICA_PAL_FW.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,DUMMY_TMP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,FORW_START0.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,VER_ST_FASI.X,,1);
    data__->VER_ST_FASI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STORE.X,,1);
    data__->STORE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,CARICA_PAL.X,,1);
    data__->CARICA_PAL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,SCARICA_PA.X,,1);
    data__->SCARICA_PA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,AUTO_MODE.X,,1);
    data__->AUTO_MODE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,ABBASSA_LIF.X,,1);
    data__->ABBASSA_LIF.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INTER_0.X,,1);
    data__->INTER_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STOC.X,,1);
    data__->STOC.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,TIME_W0.X,,1);
    data__->TIME_W0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,ABBASSA_SCAR_PAL.X,,1);
    data__->ABBASSA_SCAR_PAL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,MAG_PLUS.X,,1);
    data__->MAG_PLUS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,QUIETE_STORE.X,,1);
    data__->QUIETE_STORE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,MANUAL_MODE.X,,1);
    data__->MANUAL_MODE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,ABBASSA_LIF_MAN.X,,1);
    data__->ABBASSA_LIF_MAN.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,INTER_0.X,,1);
    data__->INTER_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,ANNULLA_INS.X,,1);
    data__->ANNULLA_INS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,QUIETE_STORE.X,,1);
    data__->QUIETE_STORE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,FORW_ON.X,,1);
    data__->FORW_ON.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,FORW_OFF.X,,1);
    data__->FORW_OFF.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,FORW_0.X,,1);
    data__->FORW_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,RETR_ON.X,,1);
    data__->RETR_ON.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,RETR_0.X,,1);
    data__->RETR_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,START_ON.X,,1);
    data__->START_ON.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,START_OFF.X,,1);
    data__->START_OFF.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,START_0.X,,1);
    data__->START_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,VER_RET_FASI.X,,1);
    data__->VER_RET_FASI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RETR_START.X,,1);
    data__->RETR_START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,CONTROLLO_POSIZIONE.X,,1);
    data__->CONTROLLO_POSIZIONE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,WAIT_DUMMY.X,,1);
    data__->WAIT_DUMMY.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,RETR.X,,1);
    data__->RETR.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,BACK_0.X,,1);
    data__->BACK_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,SCAR_RET.X,,1);
    data__->SCAR_RET.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,MAG_SUB.X,,1);
    data__->MAG_SUB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,QUIETE_RET.X,,1);
    data__->QUIETE_RET.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,ANNULLA_RETR.X,,1);
    data__->ANNULLA_RETR.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,QUIETE_RET.X,,1);
    data__->QUIETE_RET.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,MUOVI_CAR_SCAR0.X,,1);
    data__->MUOVI_CAR_SCAR0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,RISORSA_OCC.X,,1);
    data__->RISORSA_OCC.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,QUIETE_CAR_SCAR.X,,1);
    data__->QUIETE_CAR_SCAR.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,ATTESA_AVVIO_0.X,,1);
    data__->ATTESA_AVVIO_0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,MUOVI_CAR_ENT.X,,1);
    data__->MUOVI_CAR_ENT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,FERMA_CAR_ENT.X,,1);
    data__->FERMA_CAR_ENT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,QUIETE_CAR_ENT.X,,1);
    data__->QUIETE_CAR_ENT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,VER_FORW_FASI.X,,1);
    data__->VER_FORW_FASI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,FORW_START.X,,1);
    data__->FORW_START.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,CARICA_PAL_FW.X,,1);
    data__->CARICA_PAL_FW.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,SCARICA_PAL_FW.X,,1);
    data__->SCARICA_PAL_FW.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,DUMMY_TMP.X,,1);
    data__->DUMMY_TMP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,FORW_START0.X,,1);
    data__->FORW_START0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,QUIETE_FORW.X,,1);
    data__->QUIETE_FORW.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STORE action associations
  {
    char active = __GET_VAR(data__->STORE.X);
    char activated = active && !data__->STORE.prev_state;
    char desactivated = !active && data__->STORE.prev_state;

    if (active)       {data__->__action_list[__SFC_STORE_AVVIATO].set = 1;}

  }

  // CARICA_PAL action associations
  {
    char active = __GET_VAR(data__->CARICA_PAL.X);
    char activated = active && !data__->CARICA_PAL.prev_state;
    char desactivated = !active && data__->CARICA_PAL.prev_state;

    if (active && __time_cmp(data__->CARICA_PAL.T.value, __time_to_timespec(1, 0, 6, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,CARICA_PALLET,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,CARICA_PALLET,,0);};

    if (active && __time_cmp(data__->CARICA_PAL.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,LIFT,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,LIFT,,0);};

    if (active && __time_cmp(data__->CARICA_PAL.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC0,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC0,,0);};

  }

  // ABBASSA_LIF action associations
  {
    char active = __GET_VAR(data__->ABBASSA_LIF.X);
    char activated = active && !data__->ABBASSA_LIF.prev_state;
    char desactivated = !active && data__->ABBASSA_LIF.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_RICERCA_PRIMO_LIBERO].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_RICERCA_PRIMO_LIBERO].state,,0);};

    if (active && __time_cmp(data__->ABBASSA_LIF.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,__action_list[__SFC_ABBASSA_LIF_INLINE1].state,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,__action_list[__SFC_ABBASSA_LIF_INLINE1].state,,0);};

    if (active && __time_cmp(data__->ABBASSA_LIF.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC0,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC0,,0);};

  }

  // STOC action associations
  {
    char active = __GET_VAR(data__->STOC.X);
    char activated = active && !data__->STOC.prev_state;
    char desactivated = !active && data__->STOC.prev_state;

    if (activated) {
      data__->__action_list[__SFC_SCARICA_PALLET].set_remaining_time = __time_to_timespec(1, 0, 6, 0, 0, 0);
    }

    if (active && __time_cmp(data__->STOC.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,LIFT,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,LIFT,,0);};

    if (active && __time_cmp(data__->STOC.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC0,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC0,,0);};

  }

  // TIME_W0 action associations
  {
    char active = __GET_VAR(data__->TIME_W0.X);
    char activated = active && !data__->TIME_W0.prev_state;
    char desactivated = !active && data__->TIME_W0.prev_state;

    if (active && __time_cmp(data__->TIME_W0.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC0,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC0,,0);};

  }

  // ABBASSA_SCAR_PAL action associations
  {
    char active = __GET_VAR(data__->ABBASSA_SCAR_PAL.X);
    char activated = active && !data__->ABBASSA_SCAR_PAL.prev_state;
    char desactivated = !active && data__->ABBASSA_SCAR_PAL.prev_state;

    if (active)       {data__->__action_list[__SFC_SCARICA_PALLET].reset = 1;}

    if (active && __time_cmp(data__->ABBASSA_SCAR_PAL.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,__action_list[__SFC_ABBASSA_SCAR_PAL_INLINE2].state,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,__action_list[__SFC_ABBASSA_SCAR_PAL_INLINE2].state,,0);};

    if (active && __time_cmp(data__->ABBASSA_SCAR_PAL.T.value, __time_to_timespec(1, 0, 6, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC0,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC0,,0);};

  }

  // MAG_PLUS action associations
  {
    char active = __GET_VAR(data__->MAG_PLUS.X);
    char activated = active && !data__->MAG_PLUS.prev_state;
    char desactivated = !active && data__->MAG_PLUS.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_MAG_PLUS_INLINE3].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_MAG_PLUS_INLINE3].state,,0);};

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_MAG_PLUS_INLINE4].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_MAG_PLUS_INLINE4].state,,0);};

    if (active)       {data__->__action_list[__SFC_STORE_AVVIATO].reset = 1;}

  }

  // ABBASSA_LIF_MAN action associations
  {
    char active = __GET_VAR(data__->ABBASSA_LIF_MAN.X);
    char activated = active && !data__->ABBASSA_LIF_MAN.prev_state;
    char desactivated = !active && data__->ABBASSA_LIF_MAN.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CHECK_MANUAL_POSITION].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CHECK_MANUAL_POSITION].state,,0);};

  }

  // ANNULLA_INS action associations
  {
    char active = __GET_VAR(data__->ANNULLA_INS.X);
    char activated = active && !data__->ANNULLA_INS.prev_state;
    char desactivated = !active && data__->ANNULLA_INS.prev_state;

    if (active)       {data__->__action_list[__SFC_STORE_AVVIATO].reset = 1;}

  }

  // FORW_ON action associations
  {
    char active = __GET_VAR(data__->FORW_ON.X);
    char activated = active && !data__->FORW_ON.prev_state;
    char desactivated = !active && data__->FORW_ON.prev_state;

    if (active)       {data__->__action_list[__SFC_FORW_LIGHT].set = 1;}

    if (active)       {data__->__action_list[__SFC_SISTEMA_AVVIATO].set = 1;}

  }

  // FORW_OFF action associations
  {
    char active = __GET_VAR(data__->FORW_OFF.X);
    char activated = active && !data__->FORW_OFF.prev_state;
    char desactivated = !active && data__->FORW_OFF.prev_state;

    if (active)       {data__->__action_list[__SFC_FORW_LIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_SISTEMA_AVVIATO].reset = 1;}

  }

  // RETR_ON action associations
  {
    char active = __GET_VAR(data__->RETR_ON.X);
    char activated = active && !data__->RETR_ON.prev_state;
    char desactivated = !active && data__->RETR_ON.prev_state;

    if (active)       {data__->__action_list[__SFC_RETR_LIGHT].set = 1;}

    if (active)       {data__->__action_list[__SFC_SISTEMA_AVVIATO].set = 1;}

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_RETR_LIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_SISTEMA_AVVIATO].reset = 1;}

  }

  // START_ON action associations
  {
    char active = __GET_VAR(data__->START_ON.X);
    char activated = active && !data__->START_ON.prev_state;
    char desactivated = !active && data__->START_ON.prev_state;

    if (active)       {data__->__action_list[__SFC_START_LIGHT].set = 1;}

    if (active)       {data__->__action_list[__SFC_SISTEMA_AVVIATO].set = 1;}

  }

  // START_OFF action associations
  {
    char active = __GET_VAR(data__->START_OFF.X);
    char activated = active && !data__->START_OFF.prev_state;
    char desactivated = !active && data__->START_OFF.prev_state;

    if (active)       {data__->__action_list[__SFC_START_LIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_SISTEMA_AVVIATO].reset = 1;}

  }

  // RETR_START action associations
  {
    char active = __GET_VAR(data__->RETR_START.X);
    char activated = active && !data__->RETR_START.prev_state;
    char desactivated = !active && data__->RETR_START.prev_state;

    if (active)       {data__->__action_list[__SFC_RETRIEVE_AVVIATO].set = 1;}

  }

  // CONTROLLO_POSIZIONE action associations
  {
    char active = __GET_VAR(data__->CONTROLLO_POSIZIONE.X);
    char activated = active && !data__->CONTROLLO_POSIZIONE.prev_state;
    char desactivated = !active && data__->CONTROLLO_POSIZIONE.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CHECK_RETRIEVE_POSITION].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CHECK_RETRIEVE_POSITION].state,,0);};

    if (active)       {data__->__action_list[__SFC_RETRIEVE_AVVIATO].set = 1;}

  }

  // WAIT_DUMMY action associations
  {
    char active = __GET_VAR(data__->WAIT_DUMMY.X);
    char activated = active && !data__->WAIT_DUMMY.prev_state;
    char desactivated = !active && data__->WAIT_DUMMY.prev_state;

    if (active && __time_cmp(data__->WAIT_DUMMY.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC2,,0);};

  }

  // RETR action associations
  {
    char active = __GET_VAR(data__->RETR.X);
    char activated = active && !data__->RETR.prev_state;
    char desactivated = !active && data__->RETR.prev_state;

    if (active && __time_cmp(data__->RETR.T.value, __time_to_timespec(1, 0, 6, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,SCARICA_PALLET,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,SCARICA_PALLET,,0);};

    if (active && __time_cmp(data__->RETR.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,LIFT,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,LIFT,,0);};

    if (active && __time_cmp(data__->RETR.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC2,,0);};

  }

  // BACK_0 action associations
  {
    char active = __GET_VAR(data__->BACK_0.X);
    char activated = active && !data__->BACK_0.prev_state;
    char desactivated = !active && data__->BACK_0.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_BACK_0_INLINE5].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_BACK_0_INLINE5].state,,0);};

    if (active && __time_cmp(data__->BACK_0.T.value, __time_to_timespec(1, 0, 4, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC2,,0);};

  }

  // SCAR_RET action associations
  {
    char active = __GET_VAR(data__->SCAR_RET.X);
    char activated = active && !data__->SCAR_RET.prev_state;
    char desactivated = !active && data__->SCAR_RET.prev_state;

    if (active && __time_cmp(data__->SCAR_RET.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SCARICA_PALLET,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SCARICA_PALLET,,0);};

    if (active && __time_cmp(data__->SCAR_RET.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,LIFT,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,LIFT,,0);};

    if (active && __time_cmp(data__->SCAR_RET.T.value, __time_to_timespec(1, 0, 6, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC2,,0);};

  }

  // MAG_SUB action associations
  {
    char active = __GET_VAR(data__->MAG_SUB.X);
    char activated = active && !data__->MAG_SUB.prev_state;
    char desactivated = !active && data__->MAG_SUB.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_MAG_SUB_INLINE6].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_MAG_SUB_INLINE6].state,,0);};

    if (active && __time_cmp(data__->MAG_SUB.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC2,,0);};

    if (active)       {data__->__action_list[__SFC_RETRIEVE_AVVIATO].reset = 1;}

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_MAG_SUB_INLINE7].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_MAG_SUB_INLINE7].state,,0);};

  }

  // ANNULLA_RETR action associations
  {
    char active = __GET_VAR(data__->ANNULLA_RETR.X);
    char activated = active && !data__->ANNULLA_RETR.prev_state;
    char desactivated = !active && data__->ANNULLA_RETR.prev_state;

    if (active)       {data__->__action_list[__SFC_RETRIEVE_AVVIATO].reset = 1;}

  }

  // MUOVI_CAR_SCAR0 action associations
  {
    char active = __GET_VAR(data__->MUOVI_CAR_SCAR0.X);
    char activated = active && !data__->MUOVI_CAR_SCAR0.prev_state;
    char desactivated = !active && data__->MUOVI_CAR_SCAR0.prev_state;

    if (active)       {data__->__action_list[__SFC_CARRELLO_SCARICO].set = 1;}

    if (active && __time_cmp(data__->MUOVI_CAR_SCAR0.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC4,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC4,,0);};

    if (active)       {data__->__action_list[__SFC_CARRELLO_USCITA].set = 1;}

  }

  // RISORSA_OCC action associations
  {
    char active = __GET_VAR(data__->RISORSA_OCC.X);
    char activated = active && !data__->RISORSA_OCC.prev_state;
    char desactivated = !active && data__->RISORSA_OCC.prev_state;

    if (active)       {data__->__action_list[__SFC_CARRELLO_SCARICO].reset = 1;}

    if (active)       {data__->__action_list[__SFC_CARRELLO_USCITA].reset = 1;}

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active && __time_cmp(data__->STEP1.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC1,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC1,,0);};

  }

  // MUOVI_CAR_ENT action associations
  {
    char active = __GET_VAR(data__->MUOVI_CAR_ENT.X);
    char activated = active && !data__->MUOVI_CAR_ENT.prev_state;
    char desactivated = !active && data__->MUOVI_CAR_ENT.prev_state;

    if (active)       {data__->__action_list[__SFC_CARRELLO_CARICO].set = 1;}

    if (active)       {data__->__action_list[__SFC_CARRELLO_ENTRATA].set = 1;}

  }

  // FERMA_CAR_ENT action associations
  {
    char active = __GET_VAR(data__->FERMA_CAR_ENT.X);
    char activated = active && !data__->FERMA_CAR_ENT.prev_state;
    char desactivated = !active && data__->FERMA_CAR_ENT.prev_state;

    if (active)       {data__->__action_list[__SFC_CARRELLO_CARICO].reset = 1;}

    if (active)       {data__->__action_list[__SFC_CARRELLO_ENTRATA].reset = 1;}

  }

  // FORW_START action associations
  {
    char active = __GET_VAR(data__->FORW_START.X);
    char activated = active && !data__->FORW_START.prev_state;
    char desactivated = !active && data__->FORW_START.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARD_AVVIATO].set = 1;}

  }

  // CARICA_PAL_FW action associations
  {
    char active = __GET_VAR(data__->CARICA_PAL_FW.X);
    char activated = active && !data__->CARICA_PAL_FW.prev_state;
    char desactivated = !active && data__->CARICA_PAL_FW.prev_state;

    if (active && __time_cmp(data__->CARICA_PAL_FW.T.value, __time_to_timespec(1, 0, 6, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,CARICA_PALLET,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,CARICA_PALLET,,0);};

    if (active && __time_cmp(data__->CARICA_PAL_FW.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,LIFT,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,LIFT,,0);};

    if (active && __time_cmp(data__->CARICA_PAL_FW.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC3,,0);};

  }

  // SCARICA_PAL_FW action associations
  {
    char active = __GET_VAR(data__->SCARICA_PAL_FW.X);
    char activated = active && !data__->SCARICA_PAL_FW.prev_state;
    char desactivated = !active && data__->SCARICA_PAL_FW.prev_state;

    if (active && __time_cmp(data__->SCARICA_PAL_FW.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SCARICA_PALLET,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SCARICA_PALLET,,0);};

    if (active && __time_cmp(data__->SCARICA_PAL_FW.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) < 0) 
                      {__SET_VAR(data__->,LIFT,,1);}
    else if (desactivated || active)
                      {__SET_VAR(data__->,LIFT,,0);};

    if (active && __time_cmp(data__->SCARICA_PAL_FW.T.value, __time_to_timespec(1, 0, 6, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC3,,0);};

  }

  // DUMMY_TMP action associations
  {
    char active = __GET_VAR(data__->DUMMY_TMP.X);
    char activated = active && !data__->DUMMY_TMP.prev_state;
    char desactivated = !active && data__->DUMMY_TMP.prev_state;

    if (active && __time_cmp(data__->DUMMY_TMP.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,SYNC3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,SYNC3,,0);};

  }

  // FORW_START0 action associations
  {
    char active = __GET_VAR(data__->FORW_START0.X);
    char activated = active && !data__->FORW_START0.prev_state;
    char desactivated = !active && data__->FORW_START0.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARD_AVVIATO].reset = 1;}

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
  if (data__->__action_list[__SFC_STORE_AVVIATO].reset) {
    __SET_VAR(data__->,STORE_AVVIATO,,0);
  }
  else if (data__->__action_list[__SFC_STORE_AVVIATO].set) {
    __SET_VAR(data__->,STORE_AVVIATO,,1);
  }
  if (data__->__action_list[__SFC_CARICA_PALLET].reset) {
    __SET_VAR(data__->,CARICA_PALLET,,0);
  }
  else if (data__->__action_list[__SFC_CARICA_PALLET].set) {
    __SET_VAR(data__->,CARICA_PALLET,,1);
  }
  if (data__->__action_list[__SFC_LIFT].reset) {
    __SET_VAR(data__->,LIFT,,0);
  }
  else if (data__->__action_list[__SFC_LIFT].set) {
    __SET_VAR(data__->,LIFT,,1);
  }
  if (data__->__action_list[__SFC_SYNC0].reset) {
    __SET_VAR(data__->,SYNC0,,0);
  }
  else if (data__->__action_list[__SFC_SYNC0].set) {
    __SET_VAR(data__->,SYNC0,,1);
  }
  if (data__->__action_list[__SFC_SCARICA_PALLET].reset) {
    __SET_VAR(data__->,SCARICA_PALLET,,0);
  }
  else if (data__->__action_list[__SFC_SCARICA_PALLET].set) {
    __SET_VAR(data__->,SCARICA_PALLET,,1);
  }
  if (data__->__action_list[__SFC_FORW_LIGHT].reset) {
    __SET_VAR(data__->,FORW_LIGHT,,0);
  }
  else if (data__->__action_list[__SFC_FORW_LIGHT].set) {
    __SET_VAR(data__->,FORW_LIGHT,,1);
  }
  if (data__->__action_list[__SFC_SISTEMA_AVVIATO].reset) {
    __SET_VAR(data__->,SISTEMA_AVVIATO,,0);
  }
  else if (data__->__action_list[__SFC_SISTEMA_AVVIATO].set) {
    __SET_VAR(data__->,SISTEMA_AVVIATO,,1);
  }
  if (data__->__action_list[__SFC_RETR_LIGHT].reset) {
    __SET_VAR(data__->,RETR_LIGHT,,0);
  }
  else if (data__->__action_list[__SFC_RETR_LIGHT].set) {
    __SET_VAR(data__->,RETR_LIGHT,,1);
  }
  if (data__->__action_list[__SFC_START_LIGHT].reset) {
    __SET_VAR(data__->,START_LIGHT,,0);
  }
  else if (data__->__action_list[__SFC_START_LIGHT].set) {
    __SET_VAR(data__->,START_LIGHT,,1);
  }
  if (data__->__action_list[__SFC_RETRIEVE_AVVIATO].reset) {
    __SET_VAR(data__->,RETRIEVE_AVVIATO,,0);
  }
  else if (data__->__action_list[__SFC_RETRIEVE_AVVIATO].set) {
    __SET_VAR(data__->,RETRIEVE_AVVIATO,,1);
  }
  if (data__->__action_list[__SFC_SYNC2].reset) {
    __SET_VAR(data__->,SYNC2,,0);
  }
  else if (data__->__action_list[__SFC_SYNC2].set) {
    __SET_VAR(data__->,SYNC2,,1);
  }
  if (data__->__action_list[__SFC_CARRELLO_SCARICO].reset) {
    __SET_VAR(data__->,CARRELLO_SCARICO,,0);
  }
  else if (data__->__action_list[__SFC_CARRELLO_SCARICO].set) {
    __SET_VAR(data__->,CARRELLO_SCARICO,,1);
  }
  if (data__->__action_list[__SFC_SYNC4].reset) {
    __SET_VAR(data__->,SYNC4,,0);
  }
  else if (data__->__action_list[__SFC_SYNC4].set) {
    __SET_VAR(data__->,SYNC4,,1);
  }
  if (data__->__action_list[__SFC_CARRELLO_USCITA].reset) {
    __SET_VAR(data__->,CARRELLO_USCITA,,0);
  }
  else if (data__->__action_list[__SFC_CARRELLO_USCITA].set) {
    __SET_VAR(data__->,CARRELLO_USCITA,,1);
  }
  if (data__->__action_list[__SFC_SYNC1].reset) {
    __SET_VAR(data__->,SYNC1,,0);
  }
  else if (data__->__action_list[__SFC_SYNC1].set) {
    __SET_VAR(data__->,SYNC1,,1);
  }
  if (data__->__action_list[__SFC_CARRELLO_CARICO].reset) {
    __SET_VAR(data__->,CARRELLO_CARICO,,0);
  }
  else if (data__->__action_list[__SFC_CARRELLO_CARICO].set) {
    __SET_VAR(data__->,CARRELLO_CARICO,,1);
  }
  if (data__->__action_list[__SFC_CARRELLO_ENTRATA].reset) {
    __SET_VAR(data__->,CARRELLO_ENTRATA,,0);
  }
  else if (data__->__action_list[__SFC_CARRELLO_ENTRATA].set) {
    __SET_VAR(data__->,CARRELLO_ENTRATA,,1);
  }
  if (data__->__action_list[__SFC_FORWARD_AVVIATO].reset) {
    __SET_VAR(data__->,FORWARD_AVVIATO,,0);
  }
  else if (data__->__action_list[__SFC_FORWARD_AVVIATO].set) {
    __SET_VAR(data__->,FORWARD_AVVIATO,,1);
  }
  if (data__->__action_list[__SFC_SYNC3].reset) {
    __SET_VAR(data__->,SYNC3,,0);
  }
  else if (data__->__action_list[__SFC_SYNC3].set) {
    __SET_VAR(data__->,SYNC3,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_RICERCA_PRIMO_LIBERO].state)) {
    __SET_VAR(data__->,I,,1);
    __SET_VAR(data__->,TROVATO,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,POS,,-1);
    while ((!(__GET_VAR(data__->TROVATO,)) && (__GET_VAR(data__->I,) <= __GET_VAR(data__->MAX_DIM,)))) {
      if ((__GET_VAR(data__->MAGAZZINO,.table[(__GET_VAR(data__->I,)) - (1)]) == __BOOL_LITERAL(FALSE))) {
        __SET_VAR(data__->,POS,,__GET_VAR(data__->I,));
        __SET_VAR(data__->,TROVATO,,__BOOL_LITERAL(TRUE));
      } else {
        __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) + 1));
      };
    };
    __SET_VAR(data__->,MAGAZZINO,.table[(__GET_VAR(data__->POS,)) - (1)],__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->POS,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_ABBASSA_LIF_INLINE1].state)) {
    __SET_VAR(data__->,POSITION,,__GET_VAR(data__->COUNTER,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_ABBASSA_SCAR_PAL_INLINE2].state)) {
    __SET_VAR(data__->,POSITION,,2147);
  }

  if(__GET_VAR(data__->__action_list[__SFC_MAG_PLUS_INLINE3].state)) {
    __SET_VAR(data__->,CONT_MAG,,(__GET_VAR(data__->CONT_MAG,) + 1));
  }

  if(__GET_VAR(data__->__action_list[__SFC_MAG_PLUS_INLINE4].state)) {
    __SET_VAR(data__->,MANUAL_POSITION,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_CHECK_MANUAL_POSITION].state)) {
    if (((__GET_VAR(data__->MANUAL_POSITION,) < 1) || (__GET_VAR(data__->MANUAL_POSITION,) > __GET_VAR(data__->MAX_DIM,)))) {
      __SET_VAR(data__->,POSITION,,0);
      __SET_VAR(data__->,ERRORE_0,,1);
    } else {
      if ((__GET_VAR(data__->MAGAZZINO,.table[(__GET_VAR(data__->MANUAL_POSITION,)) - (1)]) == __BOOL_LITERAL(TRUE))) {
        __SET_VAR(data__->,POSITION,,0);
        __SET_VAR(data__->,ERRORE_0,,1);
      } else {
        __SET_VAR(data__->,POSITION,,__GET_VAR(data__->MANUAL_POSITION,));
        __SET_VAR(data__->,MAGAZZINO,.table[(__GET_VAR(data__->MANUAL_POSITION,)) - (1)],__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,ERRORE_0,,0);
      };
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_CHECK_RETRIEVE_POSITION].state)) {
    if (((__GET_VAR(data__->MANUAL_POSITION,) < 1) || (__GET_VAR(data__->MANUAL_POSITION,) > __GET_VAR(data__->MAX_DIM,)))) {
      __SET_VAR(data__->,OK_RET_POS,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ERRORE_0,,1);
    } else {
      if ((__GET_VAR(data__->MAGAZZINO,.table[(__GET_VAR(data__->MANUAL_POSITION,)) - (1)]) == __BOOL_LITERAL(FALSE))) {
        __SET_VAR(data__->,OK_RET_POS,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,ERRORE_0,,1);
      } else {
        __SET_VAR(data__->,POSITION,,__GET_VAR(data__->MANUAL_POSITION,));
        __SET_VAR(data__->,MAGAZZINO,.table[(__GET_VAR(data__->MANUAL_POSITION,)) - (1)],__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,OK_RET_POS,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,ERRORE_0,,0);
      };
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_BACK_0_INLINE5].state)) {
    __SET_VAR(data__->,POSITION,,2147);
  }

  if(__GET_VAR(data__->__action_list[__SFC_MAG_SUB_INLINE6].state)) {
    __SET_VAR(data__->,CONT_MAG,,(__GET_VAR(data__->CONT_MAG,) - 1));
  }

  if(__GET_VAR(data__->__action_list[__SFC_MAG_SUB_INLINE7].state)) {
    __SET_VAR(data__->,MANUAL_POSITION,,0);
  }



  goto __end;

__end:
  return;
} // MAIN_body__() 

// Steps undefinitions
#undef QUIETE_STORE
#undef __SFC_QUIETE_STORE
#undef VER_ST_FASI
#undef __SFC_VER_ST_FASI
#undef STORE
#undef __SFC_STORE
#undef CARICA_PAL
#undef __SFC_CARICA_PAL
#undef SCARICA_PA
#undef __SFC_SCARICA_PA
#undef AUTO_MODE
#undef __SFC_AUTO_MODE
#undef ABBASSA_LIF
#undef __SFC_ABBASSA_LIF
#undef INTER_0
#undef __SFC_INTER_0
#undef STOC
#undef __SFC_STOC
#undef TIME_W0
#undef __SFC_TIME_W0
#undef ABBASSA_SCAR_PAL
#undef __SFC_ABBASSA_SCAR_PAL
#undef MAG_PLUS
#undef __SFC_MAG_PLUS
#undef MANUAL_MODE
#undef __SFC_MANUAL_MODE
#undef ABBASSA_LIF_MAN
#undef __SFC_ABBASSA_LIF_MAN
#undef ANNULLA_INS
#undef __SFC_ANNULLA_INS
#undef FORW_0
#undef __SFC_FORW_0
#undef FORW_ON
#undef __SFC_FORW_ON
#undef FORW_OFF
#undef __SFC_FORW_OFF
#undef RETR_0
#undef __SFC_RETR_0
#undef RETR_ON
#undef __SFC_RETR_ON
#undef STEP0
#undef __SFC_STEP0
#undef START_0
#undef __SFC_START_0
#undef START_ON
#undef __SFC_START_ON
#undef START_OFF
#undef __SFC_START_OFF
#undef QUIETE_RET
#undef __SFC_QUIETE_RET
#undef VER_RET_FASI
#undef __SFC_VER_RET_FASI
#undef RETR_START
#undef __SFC_RETR_START
#undef CONTROLLO_POSIZIONE
#undef __SFC_CONTROLLO_POSIZIONE
#undef WAIT_DUMMY
#undef __SFC_WAIT_DUMMY
#undef RETR
#undef __SFC_RETR
#undef BACK_0
#undef __SFC_BACK_0
#undef SCAR_RET
#undef __SFC_SCAR_RET
#undef MAG_SUB
#undef __SFC_MAG_SUB
#undef ANNULLA_RETR
#undef __SFC_ANNULLA_RETR
#undef QUIETE_CAR_SCAR
#undef __SFC_QUIETE_CAR_SCAR
#undef MUOVI_CAR_SCAR0
#undef __SFC_MUOVI_CAR_SCAR0
#undef RISORSA_OCC
#undef __SFC_RISORSA_OCC
#undef QUIETE_CAR_ENT
#undef __SFC_QUIETE_CAR_ENT
#undef ATTESA_AVVIO_0
#undef __SFC_ATTESA_AVVIO_0
#undef STEP1
#undef __SFC_STEP1
#undef MUOVI_CAR_ENT
#undef __SFC_MUOVI_CAR_ENT
#undef FERMA_CAR_ENT
#undef __SFC_FERMA_CAR_ENT
#undef QUIETE_FORW
#undef __SFC_QUIETE_FORW
#undef VER_FORW_FASI
#undef __SFC_VER_FORW_FASI
#undef FORW_START
#undef __SFC_FORW_START
#undef CARICA_PAL_FW
#undef __SFC_CARICA_PAL_FW
#undef SCARICA_PAL_FW
#undef __SFC_SCARICA_PAL_FW
#undef DUMMY_TMP
#undef __SFC_DUMMY_TMP
#undef FORW_START0
#undef __SFC_FORW_START0

// Actions undefinitions
#undef __SFC_RICERCA_PRIMO_LIBERO
#undef __SFC_ABBASSA_LIF_INLINE1
#undef __SFC_ABBASSA_SCAR_PAL_INLINE2
#undef __SFC_MAG_PLUS_INLINE3
#undef __SFC_MAG_PLUS_INLINE4
#undef __SFC_CHECK_MANUAL_POSITION
#undef __SFC_CHECK_RETRIEVE_POSITION
#undef __SFC_BACK_0_INLINE5
#undef __SFC_MAG_SUB_INLINE6
#undef __SFC_MAG_SUB_INLINE7
#undef __SFC_STORE_AVVIATO
#undef __SFC_CARICA_PALLET
#undef __SFC_LIFT
#undef __SFC_SYNC0
#undef __SFC_SCARICA_PALLET
#undef __SFC_FORW_LIGHT
#undef __SFC_SISTEMA_AVVIATO
#undef __SFC_RETR_LIGHT
#undef __SFC_START_LIGHT
#undef __SFC_RETRIEVE_AVVIATO
#undef __SFC_SYNC2
#undef __SFC_CARRELLO_SCARICO
#undef __SFC_SYNC4
#undef __SFC_CARRELLO_USCITA
#undef __SFC_SYNC1
#undef __SFC_CARRELLO_CARICO
#undef __SFC_CARRELLO_ENTRATA
#undef __SFC_FORWARD_AVVIATO
#undef __SFC_SYNC3





void SMISTATORE_init__(SMISTATORE *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,AT_UNLOAD_SENSOR,data__->AT_UNLOAD_SENSOR,retain)
  __INIT_VAR(data__->TURN_ENTRY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AT_FRONT,0,retain)
  __INIT_VAR(data__->PALLET_SENSOR,0,retain)
  __INIT_VAR(data__->LOW,0,retain)
  __INIT_VAR(data__->MEDIUM,0,retain)
  __INIT_VAR(data__->HIGHT,0,retain)
  __INIT_VAR(data__->AT_RIGHT,0,retain)
  __INIT_VAR(data__->AT_RIGHT_EXIT,0,retain)
  __INIT_VAR(data__->AT_LEFT,0,retain)
  __INIT_VAR(data__->AT_LEFT_EXIT,0,retain)
  __INIT_VAR(data__->AT_FWD,0,retain)
  __INIT_VAR(data__->AT_FWD_EXIT,0,retain)
  __INIT_VAR(data__->ENTERCONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENTERCONVEYOR1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOADED_TURN,0,retain)
  __INIT_VAR(data__->RIGHTCONVEYOR,0,retain)
  __INIT_VAR(data__->TURN,0,retain)
  __INIT_VAR(data__->LOADED_TURN_RIGHT,0,retain)
  __INIT_VAR(data__->LEFTCONVEYOR,0,retain)
  __INIT_VAR(data__->FRCONVEYOR,0,retain)
  __INIT_VAR(data__->WAIT,0,retain)
  __INIT_VAR(data__->WAIT1,0,retain)
  __INIT_VAR(data__->WAIT2,0,retain)
  __INIT_VAR(data__->WAIT3,0,retain)
  __INIT_VAR(data__->LEFT_OK,0,retain)
  __INIT_VAR(data__->RIGHT_OK,0,retain)
  __INIT_VAR(data__->FWD_OK,0,retain)
  __INIT_VAR(data__->CONT,0,retain)
  UINT i;
  data__->__nb_steps = 36;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[13].X,,1);
  __SET_VAR(data__->,__step_list[18].X,,1);
  __SET_VAR(data__->,__step_list[23].X,,1);
  __SET_VAR(data__->,__step_list[27].X,,1);
  __SET_VAR(data__->,__step_list[32].X,,1);
  __SET_VAR(data__->,__step_list[34].X,,1);
  data__->__nb_actions = 16;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 39;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define CHECK_QUIETE __step_list[0]
#define __SFC_CHECK_QUIETE 0
#define SCELTA __step_list[1]
#define __SFC_SCELTA 1
#define CHECK_PROCESSING0 __step_list[2]
#define __SFC_CHECK_PROCESSING0 2
#define CARICA0 __step_list[3]
#define __SFC_CARICA0 3
#define FERMA_CARR __step_list[4]
#define __SFC_FERMA_CARR 4
#define GIRA __step_list[5]
#define __SFC_GIRA 5
#define CHECK_PROCESSING1 __step_list[6]
#define __SFC_CHECK_PROCESSING1 6
#define CARICA1 __step_list[7]
#define __SFC_CARICA1 7
#define FERMA_CARR1 __step_list[8]
#define __SFC_FERMA_CARR1 8
#define CHECK_PROCESSING2 __step_list[9]
#define __SFC_CHECK_PROCESSING2 9
#define CARICA2 __step_list[10]
#define __SFC_CARICA2 10
#define FERMA_CARR2 __step_list[11]
#define __SFC_FERMA_CARR2 11
#define GIRA1 __step_list[12]
#define __SFC_GIRA1 12
#define FWD_QUIETE __step_list[13]
#define __SFC_FWD_QUIETE 13
#define DI_FRONTE1 __step_list[14]
#define __SFC_DI_FRONTE1 14
#define RESETTA_FRONT1 __step_list[15]
#define __SFC_RESETTA_FRONT1 15
#define PAUSE1 __step_list[16]
#define __SFC_PAUSE1 16
#define RIPOS_DESTRA2 __step_list[17]
#define __SFC_RIPOS_DESTRA2 17
#define LEFT_QUIETE __step_list[18]
#define __SFC_LEFT_QUIETE 18
#define SINISTRA0 __step_list[19]
#define __SFC_SINISTRA0 19
#define RIPOS_SINISTRA0 __step_list[20]
#define __SFC_RIPOS_SINISTRA0 20
#define PAUSE __step_list[21]
#define __SFC_PAUSE 21
#define RIPOS_DESTRA1 __step_list[22]
#define __SFC_RIPOS_DESTRA1 22
#define RIGHT_QUIETE __step_list[23]
#define __SFC_RIGHT_QUIETE 23
#define DESTRA1 __step_list[24]
#define __SFC_DESTRA1 24
#define RIPOS_DESTRA __step_list[25]
#define __SFC_RIPOS_DESTRA 25
#define RIPOS_DESTRA0 __step_list[26]
#define __SFC_RIPOS_DESTRA0 26
#define START_CONVERYORS __step_list[27]
#define __SFC_START_CONVERYORS 27
#define ATTIVA_CARRELLI __step_list[28]
#define __SFC_ATTIVA_CARRELLI 28
#define DISATTIVA_CARRELLI0 __step_list[29]
#define __SFC_DISATTIVA_CARRELLI0 29
#define DISATTIVA_CARRELLI __step_list[30]
#define __SFC_DISATTIVA_CARRELLI 30
#define INTER_FASE __step_list[31]
#define __SFC_INTER_FASE 31
#define CONT_PLUS __step_list[32]
#define __SFC_CONT_PLUS 32
#define PLUSS __step_list[33]
#define __SFC_PLUSS 33
#define CONT_SUB __step_list[34]
#define __SFC_CONT_SUB 34
#define SUBB __step_list[35]
#define __SFC_SUBB 35

// Actions definitions
#define __SFC_PLUSS_INLINE1 0
#define __SFC_SUBB_INLINE2 1
#define __SFC_LOADED_TURN 2
#define __SFC_TURN 3
#define __SFC_LEFT_OK 4
#define __SFC_FWD_OK 5
#define __SFC_RIGHT_OK 6
#define __SFC_FRCONVEYOR 7
#define __SFC_LEFTCONVEYOR 8
#define __SFC_RIGHTCONVEYOR 9
#define __SFC_LOADED_TURN_RIGHT 10
#define __SFC_WAIT3 11
#define __SFC_ENTERCONVEYOR 12
#define __SFC_ENTERCONVEYOR1 13
#define __SFC_WAIT1 14
#define __SFC_WAIT2 15

// Code part
void SMISTATORE_body__(SMISTATORE *data__) {
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
  if (__GET_VAR(data__->CHECK_QUIETE.X)) {
    __SET_VAR(data__->,__transition_list[0],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,1);
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->SCELTA.X)) {
    __SET_VAR(data__->,__transition_list[1],,(((__GET_VAR(data__->PALLET_SENSOR,) && __GET_VAR(data__->LOW,)) && __GET_VAR(data__->MEDIUM,)) && __GET_VAR(data__->HIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(((__GET_VAR(data__->PALLET_SENSOR,) && __GET_VAR(data__->LOW,)) && __GET_VAR(data__->MEDIUM,)) && __GET_VAR(data__->HIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->CHECK_PROCESSING0.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->TURN_ENTRY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->TURN_ENTRY,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->CARICA0.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->AT_FRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->AT_FRONT,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->FERMA_CARR.X)) {
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
  if (__GET_VAR(data__->GIRA.X)) {
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
  if (__GET_VAR(data__->SCELTA.X)) {
    __SET_VAR(data__->,__transition_list[6],,(((__GET_VAR(data__->PALLET_SENSOR,) && __GET_VAR(data__->LOW,)) && __GET_VAR(data__->MEDIUM,)) && !(__GET_VAR(data__->HIGHT,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,(((__GET_VAR(data__->PALLET_SENSOR,) && __GET_VAR(data__->LOW,)) && __GET_VAR(data__->MEDIUM,)) && !(__GET_VAR(data__->HIGHT,))));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->CHECK_PROCESSING1.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->TURN_ENTRY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->TURN_ENTRY,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->CARICA1.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->AT_FRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->AT_FRONT,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->FERMA_CARR1.X)) {
    __SET_VAR(data__->,__transition_list[9],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,1);
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->SCELTA.X)) {
    __SET_VAR(data__->,__transition_list[10],,(((__GET_VAR(data__->PALLET_SENSOR,) && __GET_VAR(data__->LOW,)) && !(__GET_VAR(data__->MEDIUM,))) && !(__GET_VAR(data__->HIGHT,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,(((__GET_VAR(data__->PALLET_SENSOR,) && __GET_VAR(data__->LOW,)) && !(__GET_VAR(data__->MEDIUM,))) && !(__GET_VAR(data__->HIGHT,))));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->CHECK_PROCESSING2.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TURN_ENTRY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TURN_ENTRY,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->CARICA2.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->AT_FRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->AT_FRONT,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->FERMA_CARR2.X)) {
    __SET_VAR(data__->,__transition_list[13],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,1);
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->GIRA1.X)) {
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
  if (__GET_VAR(data__->FWD_QUIETE.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->FWD_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->FWD_OK,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->DI_FRONTE1.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->AT_FWD,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->AT_FWD,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->RESETTA_FRONT1.X)) {
    __SET_VAR(data__->,__transition_list[17],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,1);
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->PAUSE1.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_VAR(data__->AT_FWD_EXIT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->AT_FWD_EXIT,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->RIPOS_DESTRA2.X)) {
    __SET_VAR(data__->,__transition_list[19],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,1);
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->LEFT_QUIETE.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->LEFT_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->LEFT_OK,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->SINISTRA0.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_VAR(data__->AT_LEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->AT_LEFT,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->RIPOS_SINISTRA0.X)) {
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
  if (__GET_VAR(data__->PAUSE.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->AT_LEFT_EXIT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->AT_LEFT_EXIT,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->RIPOS_DESTRA1.X)) {
    __SET_VAR(data__->,__transition_list[24],,1);
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,1);
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->RIGHT_QUIETE.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->RIGHT_OK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->RIGHT_OK,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->DESTRA1.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_VAR(data__->AT_RIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->AT_RIGHT,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->RIPOS_DESTRA.X)) {
    __SET_VAR(data__->,__transition_list[27],,__GET_VAR(data__->AT_RIGHT_EXIT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->AT_RIGHT_EXIT,));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->RIPOS_DESTRA0.X)) {
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
  if (__GET_VAR(data__->START_CONVERYORS.X)) {
    __SET_VAR(data__->,__transition_list[29],,(!(__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)) && __GET_VAR(data__->WAIT3,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,(!(__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)) && __GET_VAR(data__->WAIT3,)));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->ATTIVA_CARRELLI.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_VAR(data__->TURN_ENTRY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->TURN_ENTRY,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->DISATTIVA_CARRELLI0.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->WAIT3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->WAIT3,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->DISATTIVA_CARRELLI.X)) {
    __SET_VAR(data__->,__transition_list[32],,!(__GET_VAR(data__->TURN,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,!(__GET_VAR(data__->TURN,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->INTER_FASE.X)) {
    __SET_VAR(data__->,__transition_list[33],,(((__GET_VAR(data__->AT_FWD,) || __GET_VAR(data__->AT_RIGHT,)) || __GET_VAR(data__->AT_LEFT,)) && (__GET_VAR(data__->CONT,) != 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,(((__GET_VAR(data__->AT_FWD,) || __GET_VAR(data__->AT_RIGHT,)) || __GET_VAR(data__->AT_LEFT,)) && (__GET_VAR(data__->CONT,) != 0)));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->INTER_FASE.X)) {
    __SET_VAR(data__->,__transition_list[34],,(((__GET_VAR(data__->AT_FWD,) || __GET_VAR(data__->AT_RIGHT,)) || __GET_VAR(data__->AT_LEFT,)) && (__GET_VAR(data__->CONT,) == 0)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,(((__GET_VAR(data__->AT_FWD,) || __GET_VAR(data__->AT_RIGHT,)) || __GET_VAR(data__->AT_LEFT,)) && (__GET_VAR(data__->CONT,) == 0)));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->CONT_PLUS.X)) {
    __SET_VAR(data__->,__transition_list[35],,(!(__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)) && __GET_VAR(data__->WAIT1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,(!(__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,)) && __GET_VAR(data__->WAIT1,)));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->PLUSS.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_EXTERNAL(data__->AT_UNLOAD_SENSOR,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->CONT_SUB.X)) {
    __SET_VAR(data__->,__transition_list[37],,(__GET_VAR(data__->TURN_ENTRY,) && __GET_VAR(data__->WAIT2,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,(__GET_VAR(data__->TURN_ENTRY,) && __GET_VAR(data__->WAIT2,)));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->SUBB.X)) {
    __SET_VAR(data__->,__transition_list[38],,!(__GET_VAR(data__->TURN_ENTRY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,!(__GET_VAR(data__->TURN_ENTRY,)));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,CHECK_QUIETE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,SCELTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,CHECK_PROCESSING0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,CARICA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,FERMA_CARR.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,GIRA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,SCELTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,CHECK_PROCESSING1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,CARICA1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,FERMA_CARR1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,SCELTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,CHECK_PROCESSING2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,CARICA2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,FERMA_CARR2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,GIRA1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,FWD_QUIETE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,DI_FRONTE1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,RESETTA_FRONT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,PAUSE1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,RIPOS_DESTRA2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,LEFT_QUIETE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,SINISTRA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,RIPOS_SINISTRA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,PAUSE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,RIPOS_DESTRA1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,RIGHT_QUIETE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,DESTRA1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RIPOS_DESTRA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,RIPOS_DESTRA0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,START_CONVERYORS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,ATTIVA_CARRELLI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,DISATTIVA_CARRELLI0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,DISATTIVA_CARRELLI.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,INTER_FASE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,INTER_FASE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,CONT_PLUS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,PLUSS.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,CONT_SUB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,SUBB.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,SCELTA.X,,1);
    data__->SCELTA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,CHECK_PROCESSING0.X,,1);
    data__->CHECK_PROCESSING0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,CARICA0.X,,1);
    data__->CARICA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,FERMA_CARR.X,,1);
    data__->FERMA_CARR.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,GIRA.X,,1);
    data__->GIRA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,CHECK_QUIETE.X,,1);
    data__->CHECK_QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,CHECK_PROCESSING1.X,,1);
    data__->CHECK_PROCESSING1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,CARICA1.X,,1);
    data__->CARICA1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,FERMA_CARR1.X,,1);
    data__->FERMA_CARR1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,CHECK_QUIETE.X,,1);
    data__->CHECK_QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,CHECK_PROCESSING2.X,,1);
    data__->CHECK_PROCESSING2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,CARICA2.X,,1);
    data__->CARICA2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,FERMA_CARR2.X,,1);
    data__->FERMA_CARR2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,GIRA1.X,,1);
    data__->GIRA1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,CHECK_QUIETE.X,,1);
    data__->CHECK_QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,DI_FRONTE1.X,,1);
    data__->DI_FRONTE1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,RESETTA_FRONT1.X,,1);
    data__->RESETTA_FRONT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,PAUSE1.X,,1);
    data__->PAUSE1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,RIPOS_DESTRA2.X,,1);
    data__->RIPOS_DESTRA2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,FWD_QUIETE.X,,1);
    data__->FWD_QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,SINISTRA0.X,,1);
    data__->SINISTRA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,RIPOS_SINISTRA0.X,,1);
    data__->RIPOS_SINISTRA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,PAUSE.X,,1);
    data__->PAUSE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,RIPOS_DESTRA1.X,,1);
    data__->RIPOS_DESTRA1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,LEFT_QUIETE.X,,1);
    data__->LEFT_QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,DESTRA1.X,,1);
    data__->DESTRA1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,RIPOS_DESTRA.X,,1);
    data__->RIPOS_DESTRA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RIPOS_DESTRA0.X,,1);
    data__->RIPOS_DESTRA0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,RIGHT_QUIETE.X,,1);
    data__->RIGHT_QUIETE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,ATTIVA_CARRELLI.X,,1);
    data__->ATTIVA_CARRELLI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,DISATTIVA_CARRELLI0.X,,1);
    data__->DISATTIVA_CARRELLI0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,DISATTIVA_CARRELLI.X,,1);
    data__->DISATTIVA_CARRELLI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,INTER_FASE.X,,1);
    data__->INTER_FASE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,ATTIVA_CARRELLI.X,,1);
    data__->ATTIVA_CARRELLI.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,START_CONVERYORS.X,,1);
    data__->START_CONVERYORS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,PLUSS.X,,1);
    data__->PLUSS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,CONT_PLUS.X,,1);
    data__->CONT_PLUS.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,SUBB.X,,1);
    data__->SUBB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,CONT_SUB.X,,1);
    data__->CONT_SUB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // CARICA0 action associations
  {
    char active = __GET_VAR(data__->CARICA0.X);
    char activated = active && !data__->CARICA0.prev_state;
    char desactivated = !active && data__->CARICA0.prev_state;

    if (active)       {__SET_VAR(data__->,LOADED_TURN,,1);};
    if (desactivated) {__SET_VAR(data__->,LOADED_TURN,,0);};

  }

  // GIRA action associations
  {
    char active = __GET_VAR(data__->GIRA.X);
    char activated = active && !data__->GIRA.prev_state;
    char desactivated = !active && data__->GIRA.prev_state;

    if (active)       {data__->__action_list[__SFC_TURN].set = 1;}

    if (active)       {data__->__action_list[__SFC_LEFT_OK].set = 1;}

  }

  // CARICA1 action associations
  {
    char active = __GET_VAR(data__->CARICA1.X);
    char activated = active && !data__->CARICA1.prev_state;
    char desactivated = !active && data__->CARICA1.prev_state;

    if (active)       {__SET_VAR(data__->,LOADED_TURN,,1);};
    if (desactivated) {__SET_VAR(data__->,LOADED_TURN,,0);};

  }

  // FERMA_CARR1 action associations
  {
    char active = __GET_VAR(data__->FERMA_CARR1.X);
    char activated = active && !data__->FERMA_CARR1.prev_state;
    char desactivated = !active && data__->FERMA_CARR1.prev_state;

    if (active)       {data__->__action_list[__SFC_FWD_OK].set = 1;}

  }

  // CARICA2 action associations
  {
    char active = __GET_VAR(data__->CARICA2.X);
    char activated = active && !data__->CARICA2.prev_state;
    char desactivated = !active && data__->CARICA2.prev_state;

    if (active)       {__SET_VAR(data__->,LOADED_TURN,,1);};
    if (desactivated) {__SET_VAR(data__->,LOADED_TURN,,0);};

  }

  // GIRA1 action associations
  {
    char active = __GET_VAR(data__->GIRA1.X);
    char activated = active && !data__->GIRA1.prev_state;
    char desactivated = !active && data__->GIRA1.prev_state;

    if (active)       {data__->__action_list[__SFC_TURN].set = 1;}

    if (active)       {data__->__action_list[__SFC_RIGHT_OK].set = 1;}

  }

  // DI_FRONTE1 action associations
  {
    char active = __GET_VAR(data__->DI_FRONTE1.X);
    char activated = active && !data__->DI_FRONTE1.prev_state;
    char desactivated = !active && data__->DI_FRONTE1.prev_state;

    if (active)       {data__->__action_list[__SFC_FRCONVEYOR].set = 1;}

    if (active)       {data__->__action_list[__SFC_FWD_OK].reset = 1;}

    if (activated) {
      data__->__action_list[__SFC_LOADED_TURN].set_remaining_time = __time_to_timespec(1, 0, 3, 0, 0, 0);
    }

  }

  // RESETTA_FRONT1 action associations
  {
    char active = __GET_VAR(data__->RESETTA_FRONT1.X);
    char activated = active && !data__->RESETTA_FRONT1.prev_state;
    char desactivated = !active && data__->RESETTA_FRONT1.prev_state;

    if (active)       {data__->__action_list[__SFC_LOADED_TURN].reset = 1;}

  }

  // RIPOS_DESTRA2 action associations
  {
    char active = __GET_VAR(data__->RIPOS_DESTRA2.X);
    char activated = active && !data__->RIPOS_DESTRA2.prev_state;
    char desactivated = !active && data__->RIPOS_DESTRA2.prev_state;

    if (active)       {data__->__action_list[__SFC_FRCONVEYOR].reset = 1;}

  }

  // SINISTRA0 action associations
  {
    char active = __GET_VAR(data__->SINISTRA0.X);
    char activated = active && !data__->SINISTRA0.prev_state;
    char desactivated = !active && data__->SINISTRA0.prev_state;

    if (active)       {data__->__action_list[__SFC_LEFTCONVEYOR].set = 1;}

    if (activated) {
      data__->__action_list[__SFC_LOADED_TURN].set_remaining_time = __time_to_timespec(1, 0, 5, 0, 0, 0);
    }

  }

  // RIPOS_SINISTRA0 action associations
  {
    char active = __GET_VAR(data__->RIPOS_SINISTRA0.X);
    char activated = active && !data__->RIPOS_SINISTRA0.prev_state;
    char desactivated = !active && data__->RIPOS_SINISTRA0.prev_state;

    if (active)       {data__->__action_list[__SFC_TURN].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LOADED_TURN].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LEFT_OK].reset = 1;}

  }

  // RIPOS_DESTRA1 action associations
  {
    char active = __GET_VAR(data__->RIPOS_DESTRA1.X);
    char activated = active && !data__->RIPOS_DESTRA1.prev_state;
    char desactivated = !active && data__->RIPOS_DESTRA1.prev_state;

    if (active)       {data__->__action_list[__SFC_LEFTCONVEYOR].reset = 1;}

  }

  // DESTRA1 action associations
  {
    char active = __GET_VAR(data__->DESTRA1.X);
    char activated = active && !data__->DESTRA1.prev_state;
    char desactivated = !active && data__->DESTRA1.prev_state;

    if (active)       {data__->__action_list[__SFC_RIGHTCONVEYOR].set = 1;}

    if (activated) {
      data__->__action_list[__SFC_LOADED_TURN_RIGHT].set_remaining_time = __time_to_timespec(1, 0, 5, 0, 0, 0);
    }

  }

  // RIPOS_DESTRA action associations
  {
    char active = __GET_VAR(data__->RIPOS_DESTRA.X);
    char activated = active && !data__->RIPOS_DESTRA.prev_state;
    char desactivated = !active && data__->RIPOS_DESTRA.prev_state;

    if (active)       {data__->__action_list[__SFC_TURN].reset = 1;}

    if (active)       {data__->__action_list[__SFC_RIGHT_OK].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LOADED_TURN_RIGHT].reset = 1;}

  }

  // RIPOS_DESTRA0 action associations
  {
    char active = __GET_VAR(data__->RIPOS_DESTRA0.X);
    char activated = active && !data__->RIPOS_DESTRA0.prev_state;
    char desactivated = !active && data__->RIPOS_DESTRA0.prev_state;

    if (active)       {data__->__action_list[__SFC_RIGHTCONVEYOR].reset = 1;}

  }

  // START_CONVERYORS action associations
  {
    char active = __GET_VAR(data__->START_CONVERYORS.X);
    char activated = active && !data__->START_CONVERYORS.prev_state;
    char desactivated = !active && data__->START_CONVERYORS.prev_state;

    if (active && __time_cmp(data__->START_CONVERYORS.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,WAIT3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,WAIT3,,0);};

  }

  // ATTIVA_CARRELLI action associations
  {
    char active = __GET_VAR(data__->ATTIVA_CARRELLI.X);
    char activated = active && !data__->ATTIVA_CARRELLI.prev_state;
    char desactivated = !active && data__->ATTIVA_CARRELLI.prev_state;

    if (active)       {data__->__action_list[__SFC_ENTERCONVEYOR].set = 1;}

    if (active)       {data__->__action_list[__SFC_ENTERCONVEYOR1].set = 1;}

  }

  // DISATTIVA_CARRELLI0 action associations
  {
    char active = __GET_VAR(data__->DISATTIVA_CARRELLI0.X);
    char activated = active && !data__->DISATTIVA_CARRELLI0.prev_state;
    char desactivated = !active && data__->DISATTIVA_CARRELLI0.prev_state;

    if (active && __time_cmp(data__->DISATTIVA_CARRELLI0.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,WAIT3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,WAIT3,,0);};

  }

  // DISATTIVA_CARRELLI action associations
  {
    char active = __GET_VAR(data__->DISATTIVA_CARRELLI.X);
    char activated = active && !data__->DISATTIVA_CARRELLI.prev_state;
    char desactivated = !active && data__->DISATTIVA_CARRELLI.prev_state;

    if (active)       {data__->__action_list[__SFC_ENTERCONVEYOR].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ENTERCONVEYOR1].reset = 1;}

  }

  // CONT_PLUS action associations
  {
    char active = __GET_VAR(data__->CONT_PLUS.X);
    char activated = active && !data__->CONT_PLUS.prev_state;
    char desactivated = !active && data__->CONT_PLUS.prev_state;

    if (active && __time_cmp(data__->CONT_PLUS.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,WAIT1,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,WAIT1,,0);};

  }

  // PLUSS action associations
  {
    char active = __GET_VAR(data__->PLUSS.X);
    char activated = active && !data__->PLUSS.prev_state;
    char desactivated = !active && data__->PLUSS.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_PLUSS_INLINE1].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_PLUSS_INLINE1].state,,0);};

  }

  // CONT_SUB action associations
  {
    char active = __GET_VAR(data__->CONT_SUB.X);
    char activated = active && !data__->CONT_SUB.prev_state;
    char desactivated = !active && data__->CONT_SUB.prev_state;

    if (active && __time_cmp(data__->CONT_SUB.T.value, __time_to_timespec(1, 0, 2, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,WAIT2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,WAIT2,,0);};

  }

  // SUBB action associations
  {
    char active = __GET_VAR(data__->SUBB.X);
    char activated = active && !data__->SUBB.prev_state;
    char desactivated = !active && data__->SUBB.prev_state;

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_SUBB_INLINE2].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_SUBB_INLINE2].state,,0);};

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
  if (data__->__action_list[__SFC_LOADED_TURN].reset) {
    __SET_VAR(data__->,LOADED_TURN,,0);
  }
  else if (data__->__action_list[__SFC_LOADED_TURN].set) {
    __SET_VAR(data__->,LOADED_TURN,,1);
  }
  if (data__->__action_list[__SFC_TURN].reset) {
    __SET_VAR(data__->,TURN,,0);
  }
  else if (data__->__action_list[__SFC_TURN].set) {
    __SET_VAR(data__->,TURN,,1);
  }
  if (data__->__action_list[__SFC_LEFT_OK].reset) {
    __SET_VAR(data__->,LEFT_OK,,0);
  }
  else if (data__->__action_list[__SFC_LEFT_OK].set) {
    __SET_VAR(data__->,LEFT_OK,,1);
  }
  if (data__->__action_list[__SFC_FWD_OK].reset) {
    __SET_VAR(data__->,FWD_OK,,0);
  }
  else if (data__->__action_list[__SFC_FWD_OK].set) {
    __SET_VAR(data__->,FWD_OK,,1);
  }
  if (data__->__action_list[__SFC_RIGHT_OK].reset) {
    __SET_VAR(data__->,RIGHT_OK,,0);
  }
  else if (data__->__action_list[__SFC_RIGHT_OK].set) {
    __SET_VAR(data__->,RIGHT_OK,,1);
  }
  if (data__->__action_list[__SFC_FRCONVEYOR].reset) {
    __SET_VAR(data__->,FRCONVEYOR,,0);
  }
  else if (data__->__action_list[__SFC_FRCONVEYOR].set) {
    __SET_VAR(data__->,FRCONVEYOR,,1);
  }
  if (data__->__action_list[__SFC_LEFTCONVEYOR].reset) {
    __SET_VAR(data__->,LEFTCONVEYOR,,0);
  }
  else if (data__->__action_list[__SFC_LEFTCONVEYOR].set) {
    __SET_VAR(data__->,LEFTCONVEYOR,,1);
  }
  if (data__->__action_list[__SFC_RIGHTCONVEYOR].reset) {
    __SET_VAR(data__->,RIGHTCONVEYOR,,0);
  }
  else if (data__->__action_list[__SFC_RIGHTCONVEYOR].set) {
    __SET_VAR(data__->,RIGHTCONVEYOR,,1);
  }
  if (data__->__action_list[__SFC_LOADED_TURN_RIGHT].reset) {
    __SET_VAR(data__->,LOADED_TURN_RIGHT,,0);
  }
  else if (data__->__action_list[__SFC_LOADED_TURN_RIGHT].set) {
    __SET_VAR(data__->,LOADED_TURN_RIGHT,,1);
  }
  if (data__->__action_list[__SFC_WAIT3].reset) {
    __SET_VAR(data__->,WAIT3,,0);
  }
  else if (data__->__action_list[__SFC_WAIT3].set) {
    __SET_VAR(data__->,WAIT3,,1);
  }
  if (data__->__action_list[__SFC_ENTERCONVEYOR].reset) {
    __SET_VAR(data__->,ENTERCONVEYOR,,0);
  }
  else if (data__->__action_list[__SFC_ENTERCONVEYOR].set) {
    __SET_VAR(data__->,ENTERCONVEYOR,,1);
  }
  if (data__->__action_list[__SFC_ENTERCONVEYOR1].reset) {
    __SET_VAR(data__->,ENTERCONVEYOR1,,0);
  }
  else if (data__->__action_list[__SFC_ENTERCONVEYOR1].set) {
    __SET_VAR(data__->,ENTERCONVEYOR1,,1);
  }
  if (data__->__action_list[__SFC_WAIT1].reset) {
    __SET_VAR(data__->,WAIT1,,0);
  }
  else if (data__->__action_list[__SFC_WAIT1].set) {
    __SET_VAR(data__->,WAIT1,,1);
  }
  if (data__->__action_list[__SFC_WAIT2].reset) {
    __SET_VAR(data__->,WAIT2,,0);
  }
  else if (data__->__action_list[__SFC_WAIT2].set) {
    __SET_VAR(data__->,WAIT2,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_PLUSS_INLINE1].state)) {
    __SET_VAR(data__->,CONT,,(__GET_VAR(data__->CONT,) + 1));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SUBB_INLINE2].state)) {
    __SET_VAR(data__->,CONT,,(__GET_VAR(data__->CONT,) - 1));
  }



  goto __end;

__end:
  return;
} // SMISTATORE_body__() 

// Steps undefinitions
#undef CHECK_QUIETE
#undef __SFC_CHECK_QUIETE
#undef SCELTA
#undef __SFC_SCELTA
#undef CHECK_PROCESSING0
#undef __SFC_CHECK_PROCESSING0
#undef CARICA0
#undef __SFC_CARICA0
#undef FERMA_CARR
#undef __SFC_FERMA_CARR
#undef GIRA
#undef __SFC_GIRA
#undef CHECK_PROCESSING1
#undef __SFC_CHECK_PROCESSING1
#undef CARICA1
#undef __SFC_CARICA1
#undef FERMA_CARR1
#undef __SFC_FERMA_CARR1
#undef CHECK_PROCESSING2
#undef __SFC_CHECK_PROCESSING2
#undef CARICA2
#undef __SFC_CARICA2
#undef FERMA_CARR2
#undef __SFC_FERMA_CARR2
#undef GIRA1
#undef __SFC_GIRA1
#undef FWD_QUIETE
#undef __SFC_FWD_QUIETE
#undef DI_FRONTE1
#undef __SFC_DI_FRONTE1
#undef RESETTA_FRONT1
#undef __SFC_RESETTA_FRONT1
#undef PAUSE1
#undef __SFC_PAUSE1
#undef RIPOS_DESTRA2
#undef __SFC_RIPOS_DESTRA2
#undef LEFT_QUIETE
#undef __SFC_LEFT_QUIETE
#undef SINISTRA0
#undef __SFC_SINISTRA0
#undef RIPOS_SINISTRA0
#undef __SFC_RIPOS_SINISTRA0
#undef PAUSE
#undef __SFC_PAUSE
#undef RIPOS_DESTRA1
#undef __SFC_RIPOS_DESTRA1
#undef RIGHT_QUIETE
#undef __SFC_RIGHT_QUIETE
#undef DESTRA1
#undef __SFC_DESTRA1
#undef RIPOS_DESTRA
#undef __SFC_RIPOS_DESTRA
#undef RIPOS_DESTRA0
#undef __SFC_RIPOS_DESTRA0
#undef START_CONVERYORS
#undef __SFC_START_CONVERYORS
#undef ATTIVA_CARRELLI
#undef __SFC_ATTIVA_CARRELLI
#undef DISATTIVA_CARRELLI0
#undef __SFC_DISATTIVA_CARRELLI0
#undef DISATTIVA_CARRELLI
#undef __SFC_DISATTIVA_CARRELLI
#undef INTER_FASE
#undef __SFC_INTER_FASE
#undef CONT_PLUS
#undef __SFC_CONT_PLUS
#undef PLUSS
#undef __SFC_PLUSS
#undef CONT_SUB
#undef __SFC_CONT_SUB
#undef SUBB
#undef __SFC_SUBB

// Actions undefinitions
#undef __SFC_PLUSS_INLINE1
#undef __SFC_SUBB_INLINE2
#undef __SFC_LOADED_TURN
#undef __SFC_TURN
#undef __SFC_LEFT_OK
#undef __SFC_FWD_OK
#undef __SFC_RIGHT_OK
#undef __SFC_FRCONVEYOR
#undef __SFC_LEFTCONVEYOR
#undef __SFC_RIGHTCONVEYOR
#undef __SFC_LOADED_TURN_RIGHT
#undef __SFC_WAIT3
#undef __SFC_ENTERCONVEYOR
#undef __SFC_ENTERCONVEYOR1
#undef __SFC_WAIT1
#undef __SFC_WAIT2





