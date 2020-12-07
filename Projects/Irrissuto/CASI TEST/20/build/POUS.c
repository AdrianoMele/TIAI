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





void TP_WITH_RESET_init__(TP_WITH_RESET *data__, BOOL retain) {
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
void TP_WITH_RESET_body__(TP_WITH_RESET *data__) {
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
} // TP_WITH_RESET_body__() 





void RISPRMIOENERGETICO_init__(RISPRMIOENERGETICO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->USCITA,0,retain)
  __INIT_VAR(data__->AUX,0,retain)
  __INIT_VAR(data__->INGRESSO,0,retain)
  __INIT_VAR(data__->RESET,0,retain)
  __INIT_VAR(data__->TEMPO,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TEMPO2,__time_to_timespec(1, 0, 4, 0, 0, 0),retain)
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET0,retain);
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
}

// Code part
void RISPRMIOENERGETICO_body__(RISPRMIOENERGETICO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->INGRESSO,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->TP_WITH_RESET0.,IN,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET0.,PT,,__GET_VAR(data__->TEMPO,));
  __SET_VAR(data__->TP_WITH_RESET0.,RESET,,__GET_VAR(data__->RESET,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET0);
  __SET_VAR(data__->,AUX,,__GET_VAR(data__->TP_WITH_RESET0.Q,));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->AUX,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->TP_WITH_RESET1.,IN,,__GET_VAR(data__->F_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET1.,PT,,__GET_VAR(data__->TEMPO2,));
  __SET_VAR(data__->TP_WITH_RESET1.,RESET,,__GET_VAR(data__->RESET,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET1);
  __SET_VAR(data__->,USCITA,,__GET_VAR(data__->TP_WITH_RESET1.Q,));

  goto __end;

__end:
  return;
} // RISPRMIOENERGETICO_body__() 





void NASTRO1_init__(NASTRO1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TEMPOESECUZIONE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TEMPOINTERNO,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->INGRESSO,0,retain)
  __INIT_VAR(data__->RESET,0,retain)
  __INIT_VAR(data__->USCITANASTRO,0,retain)
  __INIT_VAR(data__->AUX,__BOOL_LITERAL(FALSE),retain)
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET1,retain);
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET2,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
}

// Code part
void NASTRO1_body__(NASTRO1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->INGRESSO,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->RESET,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->TP_WITH_RESET2.,IN,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET2.,PT,,__GET_VAR(data__->TEMPOINTERNO,));
  __SET_VAR(data__->TP_WITH_RESET2.,RESET,,__GET_VAR(data__->R_TRIG2.Q,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET2);
  __SET_VAR(data__->,AUX,,__GET_VAR(data__->TP_WITH_RESET2.Q,));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->AUX,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->RESET,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->TP_WITH_RESET1.,IN,,__GET_VAR(data__->F_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET1.,PT,,__GET_VAR(data__->TEMPOESECUZIONE,));
  __SET_VAR(data__->TP_WITH_RESET1.,RESET,,__GET_VAR(data__->R_TRIG3.Q,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET1);
  __SET_VAR(data__->,USCITANASTRO,,__GET_VAR(data__->TP_WITH_RESET1.Q,));

  goto __end;

__end:
  return;
} // NASTRO1_body__() 





void MACCHINE_init__(MACCHINE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TEMPODILAVORAZIONE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INGRESSO,0,retain)
  __INIT_VAR(data__->RESET,0,retain)
  __INIT_VAR(data__->USCITAMACCHINA,0,retain)
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
}

// Code part
void MACCHINE_body__(MACCHINE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->INGRESSO,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->RESET,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->TP_WITH_RESET0.,IN,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET0.,PT,,__GET_VAR(data__->TEMPODILAVORAZIONE,));
  __SET_VAR(data__->TP_WITH_RESET0.,RESET,,__GET_VAR(data__->R_TRIG2.Q,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET0);
  __SET_VAR(data__->,USCITAMACCHINA,,(__GET_VAR(data__->TP_WITH_RESET0.Q,) && __GET_VAR(data__->TP_WITH_RESET0.Q,)));

  goto __end;

__end:
  return;
} // MACCHINE_body__() 





void ACCENSIONEPROGRAMMATA_init__(ACCENSIONEPROGRAMMATA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET0,retain);
  __INIT_VAR(data__->AUX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMPO0,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->OREDALLACCENSIONE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INGRESSO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->USCITAON,__BOOL_LITERAL(FALSE),retain)
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
}

// Code part
void ACCENSIONEPROGRAMMATA_body__(ACCENSIONEPROGRAMMATA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->INGRESSO,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->RESET,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->TP_WITH_RESET0.,IN,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET0.,PT,,__GET_VAR(data__->OREDALLACCENSIONE,));
  __SET_VAR(data__->TP_WITH_RESET0.,RESET,,__GET_VAR(data__->R_TRIG2.Q,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET0);
  __SET_VAR(data__->,AUX,,__GET_VAR(data__->TP_WITH_RESET0.Q,));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->AUX,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->RESET,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->TP_WITH_RESET1.,IN,,__GET_VAR(data__->F_TRIG1.Q,));
  __SET_VAR(data__->TP_WITH_RESET1.,PT,,__GET_VAR(data__->TEMPO0,));
  __SET_VAR(data__->TP_WITH_RESET1.,RESET,,__GET_VAR(data__->R_TRIG3.Q,));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET1);
  __SET_VAR(data__->,USCITAON,,__GET_VAR(data__->TP_WITH_RESET1.Q,));

  goto __end;

__end:
  return;
} // ACCENSIONEPROGRAMMATA_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->TASTOON,0,retain)
  __INIT_VAR(data__->ACCENSIONEMAN,0,1)
  __INIT_VAR(data__->ACCENSIONEAUT,0,1)
  __INIT_VAR(data__->RIPRISTINOX,0,retain)
  __INIT_VAR(data__->RISPARMIOENERGETICO1,0,retain)
  __INIT_VAR(data__->RISPARMIOENERGETICO2,0,retain)
  __INIT_VAR(data__->ATTIVARESET,0,retain)
  __INIT_VAR(data__->ATTIVARESETRIPR,0,retain)
  __INIT_VAR(data__->ATTIVARESET0,0,retain)
  __INIT_VAR(data__->ATTIVARESET2,0,retain)
  __INIT_VAR(data__->ATTIVARESET3,0,retain)
  __INIT_VAR(data__->ATTIVARESET4,0,retain)
  __INIT_VAR(data__->ATTIVARESET5,0,retain)
  __INIT_VAR(data__->ATTIVARESET6,0,retain)
  __INIT_VAR(data__->ATTIVARESET7,0,retain)
  __INIT_VAR(data__->TEMPOATTESA,0,retain)
  __INIT_VAR(data__->TEMPOATTESA2,0,retain)
  __INIT_VAR(data__->TEMPOATTESA3,0,retain)
  __INIT_VAR(data__->TIMEDUMMY1,0,retain)
  __INIT_VAR(data__->TIMEDUMMY2,0,retain)
  __INIT_VAR(data__->TIMEDUMMY3,0,retain)
  __INIT_VAR(data__->TIMEDUMMY4,0,retain)
  __INIT_VAR(data__->TIMEDUMMY5,0,retain)
  __INIT_VAR(data__->TIMEDUMMY6,0,retain)
  __INIT_VAR(data__->TIMEDUMMY7,0,retain)
  __INIT_VAR(data__->MACCHINARISCALDATA,0,retain)
  __INIT_VAR(data__->TIME3,__time_to_timespec(1, 0, 5, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME5,__time_to_timespec(1, 0, 7, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME6,__time_to_timespec(1, 0, 12, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME7,__time_to_timespec(1, 0, 900, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME8,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->TIME9,__time_to_timespec(1, 0, 60, 0, 0, 0),retain)
  __INIT_VAR(data__->TEMPOPROGRAMMATO,__time_to_timespec(1, 0, 20, 0, 0, 0),1)
  __INIT_VAR(data__->LEDVERDE,0,retain)
  __INIT_VAR(data__->LEDGIALLO,0,retain)
  __INIT_VAR(data__->LEDBIANCO,0,retain)
  __INIT_VAR(data__->ERROREMACCHINA2,0,retain)
  __INIT_VAR(data__->ERROREMACCHINA1,0,retain)
  __INIT_VAR(data__->LEDNERO,0,retain)
  __INIT_VAR(data__->LEDROSSO,0,retain)
  __INIT_VAR(data__->TASTOCARICOBUSTA,0,retain)
  __INIT_VAR(data__->TASTOOFF,0,retain)
  __INIT_VAR(data__->STARTLAVORAZIONE,0,retain)
  __INIT_VAR(data__->VANO,1,retain)
  __INIT_VAR(data__->TASTOEMERGENZA,1,retain)
  __INIT_VAR(data__->STATOFUSTELLATRICE,0,retain)
  __INIT_VAR(data__->STATOSTAMPAACALDO,0,retain)
  __INIT_VAR(data__->NASTRO,0,retain)
  __INIT_VAR(data__->SENSOREFOIL,0,retain)
  __INIT_VAR(data__->SENSORETEMP,0,retain)
  __INIT_VAR(data__->SENSORELAMA,0,retain)
  RISPRMIOENERGETICO_init__(&data__->RISPRMIOENERGETICO1,retain);
  RISPRMIOENERGETICO_init__(&data__->RISPRMIOENERGETICO0,retain);
  NASTRO1_init__(&data__->NASTRO11,retain);
  MACCHINE_init__(&data__->MACCHINE0,retain);
  MACCHINE_init__(&data__->MACCHINE1,retain);
  NASTRO1_init__(&data__->NASTRO12,retain);
  NASTRO1_init__(&data__->NASTRO10,retain);
  ACCENSIONEPROGRAMMATA_init__(&data__->ACCENSIONEPROGRAMMATA0,retain);
  NASTRO1_init__(&data__->NASTRO13,retain);
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  RISPRMIOENERGETICO_init__(&data__->RISPRMIOENERGETICO2,retain);
  TP_init__(&data__->TP2,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
  UINT i;
  data__->__nb_steps = 17;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 44;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 32;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define ACCENSIONEMANUALE __step_list[1]
#define __SFC_ACCENSIONEMANUALE 1
#define ATTESA __step_list[2]
#define __SFC_ATTESA 2
#define RIPRISTINO __step_list[3]
#define __SFC_RIPRISTINO 3
#define DIAGNOSTICA __step_list[4]
#define __SFC_DIAGNOSTICA 4
#define FINERIPRISTINO __step_list[5]
#define __SFC_FINERIPRISTINO 5
#define CONTOLLO_MACCHINA __step_list[6]
#define __SFC_CONTOLLO_MACCHINA 6
#define CARICOBUSTA __step_list[7]
#define __SFC_CARICOBUSTA 7
#define PRONTALAVORAZIONE __step_list[8]
#define __SFC_PRONTALAVORAZIONE 8
#define PRELAVORAZIONE1 __step_list[9]
#define __SFC_PRELAVORAZIONE1 9
#define FUSTELLA __step_list[10]
#define __SFC_FUSTELLA 10
#define PRELAVORAZIONE2 __step_list[11]
#define __SFC_PRELAVORAZIONE2 11
#define STAMPAACALDO __step_list[12]
#define __SFC_STAMPAACALDO 12
#define PREFINELAVORAZIONE __step_list[13]
#define __SFC_PREFINELAVORAZIONE 13
#define FINELAVORAZIONE __step_list[14]
#define __SFC_FINELAVORAZIONE 14
#define DISATTIVAZIONEMOD __step_list[15]
#define __SFC_DISATTIVAZIONEMOD 15
#define ACCENSIONEAUTOMATICA __step_list[16]
#define __SFC_ACCENSIONEAUTOMATICA 16

// Actions definitions
#define __SFC_RESETVARIABILI 0
#define __SFC_SIMACCAUT 1
#define __SFC_RISCALDAMENTOMACCHINA 2
#define __SFC_SVUOTANASTRO 3
#define __SFC_CONTROLLOLAMA 4
#define __SFC_CONTROLLOSTAMPAACALDO 5
#define __SFC_CARICO_BUSTA 6
#define __SFC_SIMULAZIONETASTOEMERGENZA 7
#define __SFC_PRONTA_LAVORAZIONE 8
#define __SFC_PRELAVORAZIONE1NASTRO 9
#define __SFC_FUSTELLATRICE 10
#define __SFC_PRELAVORAZIONE2NASTRO 11
#define __SFC_STAMPACALDO 12
#define __SFC_PREFINELAVORAZIONENASTRO 13
#define __SFC_ACCPROGRAMMATA 14
#define __SFC_LEDROSSO 15
#define __SFC_ATTIVARESETRIPR 16
#define __SFC_ATTIVARESET0 17
#define __SFC_LEDGIALLO 18
#define __SFC_RIPRISTINOX 19
#define __SFC_TEMPOATTESA 20
#define __SFC_VANO 21
#define __SFC_TEMPOATTESA2 22
#define __SFC_TASTOEMERGENZA 23
#define __SFC_TEMPOATTESA3 24
#define __SFC_TASTOON 25
#define __SFC_ATTIVARESET6 26
#define __SFC_TIMEDUMMY1 27
#define __SFC_LEDVERDE 28
#define __SFC_ATTIVARESET7 29
#define __SFC_TIMEDUMMY2 30
#define __SFC_STARTLAVORAZIONE 31
#define __SFC_ATTIVARESET 32
#define __SFC_TIMEDUMMY3 33
#define __SFC_ATTIVARESET2 34
#define __SFC_TIMEDUMMY4 35
#define __SFC_ATTIVARESET3 36
#define __SFC_TIMEDUMMY5 37
#define __SFC_ATTIVARESET4 38
#define __SFC_TIMEDUMMY6 39
#define __SFC_ATTIVARESET5 40
#define __SFC_TIMEDUMMY7 41
#define __SFC_ACCENSIONEMAN 42
#define __SFC_ACCENSIONEAUT 43

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
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->ACCENSIONEMAN,) && !(__GET_VAR(data__->ACCENSIONEAUT,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->ACCENSIONEMAN,) && !(__GET_VAR(data__->ACCENSIONEAUT,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->ACCENSIONEMANUALE.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_VAR(data__->TASTOON,) && !(__GET_VAR(data__->RIPRISTINOX,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_VAR(data__->TASTOON,) && !(__GET_VAR(data__->RIPRISTINOX,))));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->ATTESA.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->RIPRISTINO.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->TEMPOATTESA,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->TEMPOATTESA,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->DIAGNOSTICA.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->TEMPOATTESA2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->TEMPOATTESA2,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->FINERIPRISTINO.X)) {
    __SET_VAR(data__->,__transition_list[5],,((__GET_VAR(data__->TEMPOATTESA3,) && !(__GET_VAR(data__->RIPRISTINOX,))) && __GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,((__GET_VAR(data__->TEMPOATTESA3,) && !(__GET_VAR(data__->RIPRISTINOX,))) && __GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->ATTESA.X)) {
    __SET_VAR(data__->,__transition_list[6],,((!(__GET_VAR(data__->RIPRISTINOX,)) && __GET_VAR(data__->TASTOEMERGENZA,)) && __GET_VAR(data__->MACCHINARISCALDATA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,((!(__GET_VAR(data__->RIPRISTINOX,)) && __GET_VAR(data__->TASTOEMERGENZA,)) && __GET_VAR(data__->MACCHINARISCALDATA,)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->CONTOLLO_MACCHINA.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->CONTOLLO_MACCHINA.X)) {
    __SET_VAR(data__->,__transition_list[8],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->ERROREMACCHINA1,))) && !(__GET_VAR(data__->ERROREMACCHINA2,)))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->ERROREMACCHINA1,))) && !(__GET_VAR(data__->ERROREMACCHINA2,)))));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->CARICOBUSTA.X)) {
    __SET_VAR(data__->,__transition_list[9],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->CARICOBUSTA.X)) {
    __SET_VAR(data__->,__transition_list[10],,((!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TASTOOFF,))) || (__GET_VAR(data__->RISPARMIOENERGETICO1,) && !(__GET_VAR(data__->TASTOCARICOBUSTA,)))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,((!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TASTOOFF,))) || (__GET_VAR(data__->RISPARMIOENERGETICO1,) && !(__GET_VAR(data__->TASTOCARICOBUSTA,)))));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->CARICOBUSTA.X)) {
    __SET_VAR(data__->,__transition_list[11],,((!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->TASTOOFF,))) && __GET_VAR(data__->TASTOCARICOBUSTA,))) && __GET_VAR(data__->TIMEDUMMY1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,((!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->TASTOOFF,))) && __GET_VAR(data__->TASTOCARICOBUSTA,))) && __GET_VAR(data__->TIMEDUMMY1,)));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->PRONTALAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[12],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->PRONTALAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[13],,((!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TASTOOFF,))) || ((__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->RISPARMIOENERGETICO2,)) && !(__GET_VAR(data__->STARTLAVORAZIONE,)))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,((!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TASTOOFF,))) || ((__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->RISPARMIOENERGETICO2,)) && !(__GET_VAR(data__->STARTLAVORAZIONE,)))));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->PRONTALAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[14],,((!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->TASTOOFF,))) && __GET_VAR(data__->STARTLAVORAZIONE,))) && __GET_VAR(data__->TIMEDUMMY2,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,((!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->TASTOOFF,))) && __GET_VAR(data__->STARTLAVORAZIONE,))) && __GET_VAR(data__->TIMEDUMMY2,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->PRELAVORAZIONE1.X)) {
    __SET_VAR(data__->,__transition_list[15],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->PRELAVORAZIONE1.X)) {
    __SET_VAR(data__->,__transition_list[16],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->NASTRO,))) && __GET_VAR(data__->TIMEDUMMY3,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->NASTRO,))) && __GET_VAR(data__->TIMEDUMMY3,))));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->FUSTELLA.X)) {
    __SET_VAR(data__->,__transition_list[17],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->FUSTELLA.X)) {
    __SET_VAR(data__->,__transition_list[18],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->STATOFUSTELLATRICE,))) && __GET_VAR(data__->TIMEDUMMY4,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->STATOFUSTELLATRICE,))) && __GET_VAR(data__->TIMEDUMMY4,))));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->PRELAVORAZIONE2.X)) {
    __SET_VAR(data__->,__transition_list[19],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->PRELAVORAZIONE2.X)) {
    __SET_VAR(data__->,__transition_list[20],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->SENSORETEMP,))) && !(__GET_VAR(data__->NASTRO,))) && __GET_VAR(data__->TIMEDUMMY5,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->SENSORETEMP,))) && !(__GET_VAR(data__->NASTRO,))) && __GET_VAR(data__->TIMEDUMMY5,))));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STAMPAACALDO.X)) {
    __SET_VAR(data__->,__transition_list[21],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STAMPAACALDO.X)) {
    __SET_VAR(data__->,__transition_list[22],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->STATOSTAMPAACALDO,))) && __GET_VAR(data__->TIMEDUMMY6,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,(!(__GET_VAR(data__->RIPRISTINOX,)) && ((__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->STATOSTAMPAACALDO,))) && __GET_VAR(data__->TIMEDUMMY6,))));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->PREFINELAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[23],,(__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TIMEDUMMY7,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,(__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TIMEDUMMY7,)));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->FINELAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->FINELAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[25],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TASTOOFF,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->TASTOOFF,))));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->DISATTIVAZIONEMOD.X)) {
    __SET_VAR(data__->,__transition_list[26],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->FINELAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[27],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->TASTOOFF,)))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && !(__GET_VAR(data__->TASTOOFF,)))));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->PREFINELAVORAZIONE.X)) {
    __SET_VAR(data__->,__transition_list[28],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,!(__GET_VAR(data__->TASTOEMERGENZA,)));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->PRELAVORAZIONE2.X)) {
    __SET_VAR(data__->,__transition_list[29],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->SENSORETEMP,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,(!(__GET_VAR(data__->RIPRISTINOX,)) && (__GET_VAR(data__->TASTOEMERGENZA,) && __GET_VAR(data__->SENSORETEMP,))));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[30],,(__GET_VAR(data__->ACCENSIONEAUT,) && !(__GET_VAR(data__->ACCENSIONEMAN,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,(__GET_VAR(data__->ACCENSIONEAUT,) && !(__GET_VAR(data__->ACCENSIONEMAN,))));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->ACCENSIONEAUTOMATICA.X)) {
    __SET_VAR(data__->,__transition_list[31],,(__GET_VAR(data__->TASTOON,) && !(__GET_VAR(data__->RIPRISTINOX,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,(__GET_VAR(data__->TASTOON,) && !(__GET_VAR(data__->RIPRISTINOX,))));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,ACCENSIONEMANUALE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,ATTESA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,RIPRISTINO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,DIAGNOSTICA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,FINERIPRISTINO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,ATTESA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,CONTOLLO_MACCHINA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,CONTOLLO_MACCHINA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,CARICOBUSTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,CARICOBUSTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,CARICOBUSTA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,PRONTALAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,PRONTALAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,PRONTALAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,PRELAVORAZIONE1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,PRELAVORAZIONE1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,FUSTELLA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,FUSTELLA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,PRELAVORAZIONE2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,PRELAVORAZIONE2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STAMPAACALDO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STAMPAACALDO.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,PREFINELAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,FINELAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,FINELAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,DISATTIVAZIONEMOD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,FINELAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,PREFINELAVORAZIONE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,PRELAVORAZIONE2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,ACCENSIONEAUTOMATICA.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,ACCENSIONEMANUALE.X,,1);
    data__->ACCENSIONEMANUALE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,ATTESA.X,,1);
    data__->ATTESA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,DIAGNOSTICA.X,,1);
    data__->DIAGNOSTICA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,FINERIPRISTINO.X,,1);
    data__->FINERIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,ATTESA.X,,1);
    data__->ATTESA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,CONTOLLO_MACCHINA.X,,1);
    data__->CONTOLLO_MACCHINA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,CARICOBUSTA.X,,1);
    data__->CARICOBUSTA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,PRONTALAVORAZIONE.X,,1);
    data__->PRONTALAVORAZIONE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,PRELAVORAZIONE1.X,,1);
    data__->PRELAVORAZIONE1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,FUSTELLA.X,,1);
    data__->FUSTELLA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,PRELAVORAZIONE2.X,,1);
    data__->PRELAVORAZIONE2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STAMPAACALDO.X,,1);
    data__->STAMPAACALDO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,PREFINELAVORAZIONE.X,,1);
    data__->PREFINELAVORAZIONE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,FINELAVORAZIONE.X,,1);
    data__->FINELAVORAZIONE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,DISATTIVAZIONEMOD.X,,1);
    data__->DISATTIVAZIONEMOD.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,CONTOLLO_MACCHINA.X,,1);
    data__->CONTOLLO_MACCHINA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,RIPRISTINO.X,,1);
    data__->RIPRISTINO.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,ACCENSIONEAUTOMATICA.X,,1);
    data__->ACCENSIONEAUTOMATICA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,ATTESA.X,,1);
    data__->ATTESA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETVARIABILI].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETVARIABILI].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SIMACCAUT].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SIMACCAUT].state,,0);};

  }

  // ATTESA action associations
  {
    char active = __GET_VAR(data__->ATTESA.X);
    char activated = active && !data__->ATTESA.prev_state;
    char desactivated = !active && data__->ATTESA.prev_state;

    if (active)       {data__->__action_list[__SFC_LEDROSSO].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RISCALDAMENTOMACCHINA].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RISCALDAMENTOMACCHINA].state,,0);};

    if (active)       {data__->__action_list[__SFC_ATTIVARESETRIPR].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ATTIVARESET0].reset = 1;}

  }

  // RIPRISTINO action associations
  {
    char active = __GET_VAR(data__->RIPRISTINO.X);
    char activated = active && !data__->RIPRISTINO.prev_state;
    char desactivated = !active && data__->RIPRISTINO.prev_state;

    if (active)       {data__->__action_list[__SFC_LEDGIALLO].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETVARIABILI].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETVARIABILI].state,,0);};

    if (active)       {__SET_VAR(data__->,LEDROSSO,,1);};
    if (desactivated) {__SET_VAR(data__->,LEDROSSO,,0);};

    if (active)       {data__->__action_list[__SFC_RIPRISTINOX].set = 1;}

    if (active && __time_cmp(data__->RIPRISTINO.T.value, __time_to_timespec(1, 0, 4, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TEMPOATTESA,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TEMPOATTESA,,0);};

  }

  // DIAGNOSTICA action associations
  {
    char active = __GET_VAR(data__->DIAGNOSTICA.X);
    char activated = active && !data__->DIAGNOSTICA.prev_state;
    char desactivated = !active && data__->DIAGNOSTICA.prev_state;

    if (active)       {data__->__action_list[__SFC_VANO].reset = 1;}

    if (active && __time_cmp(data__->DIAGNOSTICA.T.value, __time_to_timespec(1, 0, 3, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,__action_list[__SFC_SVUOTANASTRO].state,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,__action_list[__SFC_SVUOTANASTRO].state,,0);};

    if (active && __time_cmp(data__->DIAGNOSTICA.T.value, __time_to_timespec(1, 0, 17, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,ATTIVARESETRIPR,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,ATTIVARESETRIPR,,0);};

    if (active && __time_cmp(data__->DIAGNOSTICA.T.value, __time_to_timespec(1, 0, 20, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TEMPOATTESA2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TEMPOATTESA2,,0);};

  }

  // FINERIPRISTINO action associations
  {
    char active = __GET_VAR(data__->FINERIPRISTINO.X);
    char activated = active && !data__->FINERIPRISTINO.prev_state;
    char desactivated = !active && data__->FINERIPRISTINO.prev_state;

    if (active)       {data__->__action_list[__SFC_RIPRISTINOX].reset = 1;}

    if (active)       {data__->__action_list[__SFC_LEDROSSO].reset = 1;}

    if (active)       {data__->__action_list[__SFC_VANO].set = 1;}

    if (active)       {data__->__action_list[__SFC_TASTOEMERGENZA].set = 1;}

    if (active)       {data__->__action_list[__SFC_LEDGIALLO].reset = 1;}

    if (active && __time_cmp(data__->FINERIPRISTINO.T.value, __time_to_timespec(1, 0, 7, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TEMPOATTESA3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TEMPOATTESA3,,0);};

  }

  // CONTOLLO_MACCHINA action associations
  {
    char active = __GET_VAR(data__->CONTOLLO_MACCHINA.X);
    char activated = active && !data__->CONTOLLO_MACCHINA.prev_state;
    char desactivated = !active && data__->CONTOLLO_MACCHINA.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CONTROLLOLAMA].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CONTROLLOLAMA].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CONTROLLOSTAMPAACALDO].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CONTROLLOSTAMPAACALDO].state,,0);};

    if (active)       {data__->__action_list[__SFC_TASTOON].reset = 1;}

  }

  // CARICOBUSTA action associations
  {
    char active = __GET_VAR(data__->CARICOBUSTA.X);
    char activated = active && !data__->CARICOBUSTA.prev_state;
    char desactivated = !active && data__->CARICOBUSTA.prev_state;

    if (active)       {__SET_VAR(data__->,LEDGIALLO,,1);};
    if (desactivated) {__SET_VAR(data__->,LEDGIALLO,,0);};

    if (active)       {data__->__action_list[__SFC_LEDROSSO].reset = 1;}

    if (activated)    {__SET_VAR(data__->,ATTIVARESET6,,1);}
    else              {__SET_VAR(data__->,ATTIVARESET6,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CARICO_BUSTA].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CARICO_BUSTA].state,,0);};

    if (active && __time_cmp(data__->CARICOBUSTA.T.value, __time_to_timespec(1, 0, 20, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY1,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY1,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SIMULAZIONETASTOEMERGENZA].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SIMULAZIONETASTOEMERGENZA].state,,0);};

  }

  // PRONTALAVORAZIONE action associations
  {
    char active = __GET_VAR(data__->PRONTALAVORAZIONE.X);
    char activated = active && !data__->PRONTALAVORAZIONE.prev_state;
    char desactivated = !active && data__->PRONTALAVORAZIONE.prev_state;

    if (active)       {__SET_VAR(data__->,LEDVERDE,,1);};
    if (desactivated) {__SET_VAR(data__->,LEDVERDE,,0);};

    if (active)       {data__->__action_list[__SFC_VANO].reset = 1;}

    if (activated)    {__SET_VAR(data__->,ATTIVARESET7,,1);}
    else              {__SET_VAR(data__->,ATTIVARESET7,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PRONTA_LAVORAZIONE].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PRONTA_LAVORAZIONE].state,,0);};

    if (active && __time_cmp(data__->PRONTALAVORAZIONE.T.value, __time_to_timespec(1, 0, 20, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY2,,0);};

    if (active)       {__SET_VAR(data__->,STARTLAVORAZIONE,,1);};
    if (desactivated) {__SET_VAR(data__->,STARTLAVORAZIONE,,0);};

  }

  // PRELAVORAZIONE1 action associations
  {
    char active = __GET_VAR(data__->PRELAVORAZIONE1.X);
    char activated = active && !data__->PRELAVORAZIONE1.prev_state;
    char desactivated = !active && data__->PRELAVORAZIONE1.prev_state;

    if (active)       {data__->__action_list[__SFC_LEDROSSO].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PRELAVORAZIONE1NASTRO].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PRELAVORAZIONE1NASTRO].state,,0);};

    if (active && __time_cmp(data__->PRELAVORAZIONE1.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,ATTIVARESET,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,ATTIVARESET,,0);};

    if (active && __time_cmp(data__->PRELAVORAZIONE1.T.value, __time_to_timespec(1, 0, 12, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY3,,0);};

  }

  // FUSTELLA action associations
  {
    char active = __GET_VAR(data__->FUSTELLA.X);
    char activated = active && !data__->FUSTELLA.prev_state;
    char desactivated = !active && data__->FUSTELLA.prev_state;

    if (active)       {data__->__action_list[__SFC_VANO].set = 1;}

    if (active && __time_cmp(data__->FUSTELLA.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,__action_list[__SFC_FUSTELLATRICE].state,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,__action_list[__SFC_FUSTELLATRICE].state,,0);};

    if (active && __time_cmp(data__->FUSTELLA.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,ATTIVARESET2,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,ATTIVARESET2,,0);};

    if (active && __time_cmp(data__->FUSTELLA.T.value, __time_to_timespec(1, 0, 12, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY4,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY4,,0);};

  }

  // PRELAVORAZIONE2 action associations
  {
    char active = __GET_VAR(data__->PRELAVORAZIONE2.X);
    char activated = active && !data__->PRELAVORAZIONE2.prev_state;
    char desactivated = !active && data__->PRELAVORAZIONE2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PRELAVORAZIONE2NASTRO].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PRELAVORAZIONE2NASTRO].state,,0);};

    if (active && __time_cmp(data__->PRELAVORAZIONE2.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,ATTIVARESET3,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,ATTIVARESET3,,0);};

    if (active && __time_cmp(data__->PRELAVORAZIONE2.T.value, __time_to_timespec(1, 0, 12, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY5,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY5,,0);};

  }

  // STAMPAACALDO action associations
  {
    char active = __GET_VAR(data__->STAMPAACALDO.X);
    char activated = active && !data__->STAMPAACALDO.prev_state;
    char desactivated = !active && data__->STAMPAACALDO.prev_state;

    if (active && __time_cmp(data__->STAMPAACALDO.T.value, __time_to_timespec(1, 0, 1, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,__action_list[__SFC_STAMPACALDO].state,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,__action_list[__SFC_STAMPACALDO].state,,0);};

    if (active && __time_cmp(data__->STAMPAACALDO.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,ATTIVARESET4,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,ATTIVARESET4,,0);};

    if (active && __time_cmp(data__->STAMPAACALDO.T.value, __time_to_timespec(1, 0, 12, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY6,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY6,,0);};

  }

  // PREFINELAVORAZIONE action associations
  {
    char active = __GET_VAR(data__->PREFINELAVORAZIONE.X);
    char activated = active && !data__->PREFINELAVORAZIONE.prev_state;
    char desactivated = !active && data__->PREFINELAVORAZIONE.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_PREFINELAVORAZIONENASTRO].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_PREFINELAVORAZIONENASTRO].state,,0);};

    if (active && __time_cmp(data__->PREFINELAVORAZIONE.T.value, __time_to_timespec(1, 0, 10, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,ATTIVARESET5,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,ATTIVARESET5,,0);};

    if (active && __time_cmp(data__->PREFINELAVORAZIONE.T.value, __time_to_timespec(1, 0, 12, 0, 0, 0)) >= 0) 
                      {__SET_VAR(data__->,TIMEDUMMY7,,1);}
    else if (desactivated)
                      {__SET_VAR(data__->,TIMEDUMMY7,,0);};

  }

  // FINELAVORAZIONE action associations
  {
    char active = __GET_VAR(data__->FINELAVORAZIONE.X);
    char activated = active && !data__->FINELAVORAZIONE.prev_state;
    char desactivated = !active && data__->FINELAVORAZIONE.prev_state;

    if (active)       {data__->__action_list[__SFC_LEDROSSO].reset = 1;}

  }

  // DISATTIVAZIONEMOD action associations
  {
    char active = __GET_VAR(data__->DISATTIVAZIONEMOD.X);
    char activated = active && !data__->DISATTIVAZIONEMOD.prev_state;
    char desactivated = !active && data__->DISATTIVAZIONEMOD.prev_state;

    if (active)       {data__->__action_list[__SFC_ACCENSIONEMAN].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ACCENSIONEAUT].reset = 1;}

  }

  // ACCENSIONEAUTOMATICA action associations
  {
    char active = __GET_VAR(data__->ACCENSIONEAUTOMATICA.X);
    char activated = active && !data__->ACCENSIONEAUTOMATICA.prev_state;
    char desactivated = !active && data__->ACCENSIONEAUTOMATICA.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_ACCPROGRAMMATA].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_ACCPROGRAMMATA].state,,0);};

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
  if (data__->__action_list[__SFC_LEDROSSO].reset) {
    __SET_VAR(data__->,LEDROSSO,,0);
  }
  else if (data__->__action_list[__SFC_LEDROSSO].set) {
    __SET_VAR(data__->,LEDROSSO,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESETRIPR].reset) {
    __SET_VAR(data__->,ATTIVARESETRIPR,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESETRIPR].set) {
    __SET_VAR(data__->,ATTIVARESETRIPR,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET0].reset) {
    __SET_VAR(data__->,ATTIVARESET0,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET0].set) {
    __SET_VAR(data__->,ATTIVARESET0,,1);
  }
  if (data__->__action_list[__SFC_LEDGIALLO].reset) {
    __SET_VAR(data__->,LEDGIALLO,,0);
  }
  else if (data__->__action_list[__SFC_LEDGIALLO].set) {
    __SET_VAR(data__->,LEDGIALLO,,1);
  }
  if (data__->__action_list[__SFC_RIPRISTINOX].reset) {
    __SET_VAR(data__->,RIPRISTINOX,,0);
  }
  else if (data__->__action_list[__SFC_RIPRISTINOX].set) {
    __SET_VAR(data__->,RIPRISTINOX,,1);
  }
  if (data__->__action_list[__SFC_TEMPOATTESA].reset) {
    __SET_VAR(data__->,TEMPOATTESA,,0);
  }
  else if (data__->__action_list[__SFC_TEMPOATTESA].set) {
    __SET_VAR(data__->,TEMPOATTESA,,1);
  }
  if (data__->__action_list[__SFC_VANO].reset) {
    __SET_VAR(data__->,VANO,,0);
  }
  else if (data__->__action_list[__SFC_VANO].set) {
    __SET_VAR(data__->,VANO,,1);
  }
  if (data__->__action_list[__SFC_TEMPOATTESA2].reset) {
    __SET_VAR(data__->,TEMPOATTESA2,,0);
  }
  else if (data__->__action_list[__SFC_TEMPOATTESA2].set) {
    __SET_VAR(data__->,TEMPOATTESA2,,1);
  }
  if (data__->__action_list[__SFC_TASTOEMERGENZA].reset) {
    __SET_VAR(data__->,TASTOEMERGENZA,,0);
  }
  else if (data__->__action_list[__SFC_TASTOEMERGENZA].set) {
    __SET_VAR(data__->,TASTOEMERGENZA,,1);
  }
  if (data__->__action_list[__SFC_TEMPOATTESA3].reset) {
    __SET_VAR(data__->,TEMPOATTESA3,,0);
  }
  else if (data__->__action_list[__SFC_TEMPOATTESA3].set) {
    __SET_VAR(data__->,TEMPOATTESA3,,1);
  }
  if (data__->__action_list[__SFC_TASTOON].reset) {
    __SET_VAR(data__->,TASTOON,,0);
  }
  else if (data__->__action_list[__SFC_TASTOON].set) {
    __SET_VAR(data__->,TASTOON,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET6].reset) {
    __SET_VAR(data__->,ATTIVARESET6,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET6].set) {
    __SET_VAR(data__->,ATTIVARESET6,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY1].reset) {
    __SET_VAR(data__->,TIMEDUMMY1,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY1].set) {
    __SET_VAR(data__->,TIMEDUMMY1,,1);
  }
  if (data__->__action_list[__SFC_LEDVERDE].reset) {
    __SET_VAR(data__->,LEDVERDE,,0);
  }
  else if (data__->__action_list[__SFC_LEDVERDE].set) {
    __SET_VAR(data__->,LEDVERDE,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET7].reset) {
    __SET_VAR(data__->,ATTIVARESET7,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET7].set) {
    __SET_VAR(data__->,ATTIVARESET7,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY2].reset) {
    __SET_VAR(data__->,TIMEDUMMY2,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY2].set) {
    __SET_VAR(data__->,TIMEDUMMY2,,1);
  }
  if (data__->__action_list[__SFC_STARTLAVORAZIONE].reset) {
    __SET_VAR(data__->,STARTLAVORAZIONE,,0);
  }
  else if (data__->__action_list[__SFC_STARTLAVORAZIONE].set) {
    __SET_VAR(data__->,STARTLAVORAZIONE,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET].reset) {
    __SET_VAR(data__->,ATTIVARESET,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET].set) {
    __SET_VAR(data__->,ATTIVARESET,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY3].reset) {
    __SET_VAR(data__->,TIMEDUMMY3,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY3].set) {
    __SET_VAR(data__->,TIMEDUMMY3,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET2].reset) {
    __SET_VAR(data__->,ATTIVARESET2,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET2].set) {
    __SET_VAR(data__->,ATTIVARESET2,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY4].reset) {
    __SET_VAR(data__->,TIMEDUMMY4,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY4].set) {
    __SET_VAR(data__->,TIMEDUMMY4,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET3].reset) {
    __SET_VAR(data__->,ATTIVARESET3,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET3].set) {
    __SET_VAR(data__->,ATTIVARESET3,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY5].reset) {
    __SET_VAR(data__->,TIMEDUMMY5,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY5].set) {
    __SET_VAR(data__->,TIMEDUMMY5,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET4].reset) {
    __SET_VAR(data__->,ATTIVARESET4,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET4].set) {
    __SET_VAR(data__->,ATTIVARESET4,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY6].reset) {
    __SET_VAR(data__->,TIMEDUMMY6,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY6].set) {
    __SET_VAR(data__->,TIMEDUMMY6,,1);
  }
  if (data__->__action_list[__SFC_ATTIVARESET5].reset) {
    __SET_VAR(data__->,ATTIVARESET5,,0);
  }
  else if (data__->__action_list[__SFC_ATTIVARESET5].set) {
    __SET_VAR(data__->,ATTIVARESET5,,1);
  }
  if (data__->__action_list[__SFC_TIMEDUMMY7].reset) {
    __SET_VAR(data__->,TIMEDUMMY7,,0);
  }
  else if (data__->__action_list[__SFC_TIMEDUMMY7].set) {
    __SET_VAR(data__->,TIMEDUMMY7,,1);
  }
  if (data__->__action_list[__SFC_ACCENSIONEMAN].reset) {
    __SET_VAR(data__->,ACCENSIONEMAN,,0);
  }
  else if (data__->__action_list[__SFC_ACCENSIONEMAN].set) {
    __SET_VAR(data__->,ACCENSIONEMAN,,1);
  }
  if (data__->__action_list[__SFC_ACCENSIONEAUT].reset) {
    __SET_VAR(data__->,ACCENSIONEAUT,,0);
  }
  else if (data__->__action_list[__SFC_ACCENSIONEAUT].set) {
    __SET_VAR(data__->,ACCENSIONEAUT,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_RESETVARIABILI].state)) {
    __SET_VAR(data__->,RISPARMIOENERGETICO1,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,RISPARMIOENERGETICO2,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,LEDVERDE,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,LEDBIANCO,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,LEDNERO,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,ERROREMACCHINA1,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,ERROREMACCHINA2,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,TASTOOFF,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,TASTOON,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,VANO,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATOSTAMPAACALDO,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,STATOFUSTELLATRICE,,!(__BOOL_LITERAL(TRUE)));
    __SET_VAR(data__->,NASTRO,,!(__BOOL_LITERAL(TRUE)));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SIMACCAUT].state)) {
    __SET_VAR(data__->,ACCENSIONEAUT,,__BOOL_LITERAL(TRUE));
  }

  if(__GET_VAR(data__->__action_list[__SFC_RISCALDAMENTOMACCHINA].state)) {
    __SET_VAR(data__->RISPRMIOENERGETICO2.,INGRESSO,,!(__GET_VAR(data__->RIPRISTINOX,)));
    __SET_VAR(data__->RISPRMIOENERGETICO2.,RESET,,__GET_VAR(data__->RIPRISTINOX,));
    __SET_VAR(data__->RISPRMIOENERGETICO2.,TEMPO,,__GET_VAR(data__->TIME9,));
    RISPRMIOENERGETICO_body__(&data__->RISPRMIOENERGETICO2);
    if (__GET_VAR(data__->RISPRMIOENERGETICO2.USCITA,)) {
      __SET_VAR(data__->,MACCHINARISCALDATA,,__BOOL_LITERAL(TRUE));
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_SVUOTANASTRO].state)) {
    __SET_VAR(data__->NASTRO13.,TEMPOESECUZIONE,,__GET_VAR(data__->TIME6,));
    __SET_VAR(data__->NASTRO13.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESETRIPR,)));
    __SET_VAR(data__->NASTRO13.,RESET,,__GET_VAR(data__->ATTIVARESETRIPR,));
    NASTRO1_body__(&data__->NASTRO13);
    __SET_VAR(data__->,NASTRO,,__GET_VAR(data__->NASTRO13.USCITANASTRO,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_CONTROLLOLAMA].state)) {
    __SET_VAR(data__->,ERROREMACCHINA1,,__GET_VAR(data__->SENSORELAMA,));
    __SET_VAR(data__->,LEDNERO,,__GET_VAR(data__->SENSORELAMA,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_CONTROLLOSTAMPAACALDO].state)) {
    __SET_VAR(data__->,ERROREMACCHINA2,,(__GET_VAR(data__->SENSOREFOIL,) || __GET_VAR(data__->SENSORETEMP,)));
    __SET_VAR(data__->,LEDBIANCO,,(__GET_VAR(data__->SENSORETEMP,) && __GET_VAR(data__->SENSOREFOIL,)));
  }

  if(__GET_VAR(data__->__action_list[__SFC_CARICO_BUSTA].state)) {
    __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->ATTIVARESET6,));
    F_TRIG_body__(&data__->F_TRIG1);
    __SET_VAR(data__->RISPRMIOENERGETICO0.,INGRESSO,,__GET_VAR(data__->F_TRIG1.Q,));
    __SET_VAR(data__->RISPRMIOENERGETICO0.,RESET,,__GET_VAR(data__->ATTIVARESET6,));
    __SET_VAR(data__->RISPRMIOENERGETICO0.,TEMPO,,__GET_VAR(data__->TIME9,));
    RISPRMIOENERGETICO_body__(&data__->RISPRMIOENERGETICO0);
    __SET_VAR(data__->,RISPARMIOENERGETICO1,,__GET_VAR(data__->RISPRMIOENERGETICO0.USCITA,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SIMULAZIONETASTOEMERGENZA].state)) {
    __SET_VAR(data__->TP1.,IN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->TP1.,PT,,__GET_VAR(data__->TIME3,));
    TP_body__(&data__->TP1);
    __SET_VAR(data__->,TASTOEMERGENZA,,!(__GET_VAR(data__->TP1.Q,)));
  }

  if(__GET_VAR(data__->__action_list[__SFC_PRONTA_LAVORAZIONE].state)) {
    __SET_VAR(data__->F_TRIG2.,CLK,,__GET_VAR(data__->ATTIVARESET7,));
    F_TRIG_body__(&data__->F_TRIG2);
    __SET_VAR(data__->RISPRMIOENERGETICO1.,INGRESSO,,__GET_VAR(data__->F_TRIG2.Q,));
    __SET_VAR(data__->RISPRMIOENERGETICO1.,RESET,,__GET_VAR(data__->ATTIVARESET7,));
    __SET_VAR(data__->RISPRMIOENERGETICO1.,TEMPO,,__GET_VAR(data__->TIME9,));
    RISPRMIOENERGETICO_body__(&data__->RISPRMIOENERGETICO1);
    __SET_VAR(data__->,RISPARMIOENERGETICO2,,__GET_VAR(data__->RISPRMIOENERGETICO1.USCITA,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_PRELAVORAZIONE1NASTRO].state)) {
    __SET_VAR(data__->NASTRO10.,TEMPOESECUZIONE,,__GET_VAR(data__->TIME3,));
    __SET_VAR(data__->NASTRO10.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESET,)));
    __SET_VAR(data__->NASTRO10.,RESET,,__GET_VAR(data__->ATTIVARESET,));
    NASTRO1_body__(&data__->NASTRO10);
    __SET_VAR(data__->,NASTRO,,__GET_VAR(data__->NASTRO10.USCITANASTRO,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_FUSTELLATRICE].state)) {
    __SET_VAR(data__->MACCHINE0.,TEMPODILAVORAZIONE,,__GET_VAR(data__->TIME5,));
    __SET_VAR(data__->MACCHINE0.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESET2,)));
    __SET_VAR(data__->MACCHINE0.,RESET,,__GET_VAR(data__->ATTIVARESET2,));
    MACCHINE_body__(&data__->MACCHINE0);
    __SET_VAR(data__->,STATOFUSTELLATRICE,,__GET_VAR(data__->MACCHINE0.USCITAMACCHINA,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_PRELAVORAZIONE2NASTRO].state)) {
    __SET_VAR(data__->NASTRO11.,TEMPOESECUZIONE,,__GET_VAR(data__->TIME5,));
    __SET_VAR(data__->NASTRO11.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESET3,)));
    __SET_VAR(data__->NASTRO11.,RESET,,__GET_VAR(data__->ATTIVARESET3,));
    NASTRO1_body__(&data__->NASTRO11);
    __SET_VAR(data__->,NASTRO,,__GET_VAR(data__->NASTRO11.USCITANASTRO,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_STAMPACALDO].state)) {
    __SET_VAR(data__->MACCHINE1.,TEMPODILAVORAZIONE,,__GET_VAR(data__->TIME5,));
    __SET_VAR(data__->MACCHINE1.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESET4,)));
    __SET_VAR(data__->MACCHINE1.,RESET,,__GET_VAR(data__->ATTIVARESET4,));
    MACCHINE_body__(&data__->MACCHINE1);
    __SET_VAR(data__->,STATOSTAMPAACALDO,,__GET_VAR(data__->MACCHINE1.USCITAMACCHINA,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_PREFINELAVORAZIONENASTRO].state)) {
    __SET_VAR(data__->NASTRO12.,TEMPOESECUZIONE,,__GET_VAR(data__->TIME3,));
    __SET_VAR(data__->NASTRO12.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESET5,)));
    __SET_VAR(data__->NASTRO12.,RESET,,__GET_VAR(data__->ATTIVARESET5,));
    NASTRO1_body__(&data__->NASTRO12);
    __SET_VAR(data__->,NASTRO,,__GET_VAR(data__->NASTRO12.USCITANASTRO,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_ACCPROGRAMMATA].state)) {
    __SET_VAR(data__->ACCENSIONEPROGRAMMATA0.,OREDALLACCENSIONE,,__GET_VAR(data__->TEMPOPROGRAMMATO,));
    __SET_VAR(data__->ACCENSIONEPROGRAMMATA0.,INGRESSO,,!(__GET_VAR(data__->ATTIVARESET0,)));
    __SET_VAR(data__->ACCENSIONEPROGRAMMATA0.,RESET,,__GET_VAR(data__->ATTIVARESET,));
    ACCENSIONEPROGRAMMATA_body__(&data__->ACCENSIONEPROGRAMMATA0);
    __SET_VAR(data__->,TASTOON,,__GET_VAR(data__->ACCENSIONEPROGRAMMATA0.USCITAON,));
    if (__GET_VAR(data__->TASTOON,)) {
      __SET_VAR(data__->,ATTIVARESET0,,__BOOL_LITERAL(TRUE));
    };
  }



  goto __end;

__end:
  return;
} // PROGRAM0_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef ACCENSIONEMANUALE
#undef __SFC_ACCENSIONEMANUALE
#undef ATTESA
#undef __SFC_ATTESA
#undef RIPRISTINO
#undef __SFC_RIPRISTINO
#undef DIAGNOSTICA
#undef __SFC_DIAGNOSTICA
#undef FINERIPRISTINO
#undef __SFC_FINERIPRISTINO
#undef CONTOLLO_MACCHINA
#undef __SFC_CONTOLLO_MACCHINA
#undef CARICOBUSTA
#undef __SFC_CARICOBUSTA
#undef PRONTALAVORAZIONE
#undef __SFC_PRONTALAVORAZIONE
#undef PRELAVORAZIONE1
#undef __SFC_PRELAVORAZIONE1
#undef FUSTELLA
#undef __SFC_FUSTELLA
#undef PRELAVORAZIONE2
#undef __SFC_PRELAVORAZIONE2
#undef STAMPAACALDO
#undef __SFC_STAMPAACALDO
#undef PREFINELAVORAZIONE
#undef __SFC_PREFINELAVORAZIONE
#undef FINELAVORAZIONE
#undef __SFC_FINELAVORAZIONE
#undef DISATTIVAZIONEMOD
#undef __SFC_DISATTIVAZIONEMOD
#undef ACCENSIONEAUTOMATICA
#undef __SFC_ACCENSIONEAUTOMATICA

// Actions undefinitions
#undef __SFC_RESETVARIABILI
#undef __SFC_SIMACCAUT
#undef __SFC_RISCALDAMENTOMACCHINA
#undef __SFC_SVUOTANASTRO
#undef __SFC_CONTROLLOLAMA
#undef __SFC_CONTROLLOSTAMPAACALDO
#undef __SFC_CARICO_BUSTA
#undef __SFC_SIMULAZIONETASTOEMERGENZA
#undef __SFC_PRONTA_LAVORAZIONE
#undef __SFC_PRELAVORAZIONE1NASTRO
#undef __SFC_FUSTELLATRICE
#undef __SFC_PRELAVORAZIONE2NASTRO
#undef __SFC_STAMPACALDO
#undef __SFC_PREFINELAVORAZIONENASTRO
#undef __SFC_ACCPROGRAMMATA
#undef __SFC_LEDROSSO
#undef __SFC_ATTIVARESETRIPR
#undef __SFC_ATTIVARESET0
#undef __SFC_LEDGIALLO
#undef __SFC_RIPRISTINOX
#undef __SFC_TEMPOATTESA
#undef __SFC_VANO
#undef __SFC_TEMPOATTESA2
#undef __SFC_TASTOEMERGENZA
#undef __SFC_TEMPOATTESA3
#undef __SFC_TASTOON
#undef __SFC_ATTIVARESET6
#undef __SFC_TIMEDUMMY1
#undef __SFC_LEDVERDE
#undef __SFC_ATTIVARESET7
#undef __SFC_TIMEDUMMY2
#undef __SFC_STARTLAVORAZIONE
#undef __SFC_ATTIVARESET
#undef __SFC_TIMEDUMMY3
#undef __SFC_ATTIVARESET2
#undef __SFC_TIMEDUMMY4
#undef __SFC_ATTIVARESET3
#undef __SFC_TIMEDUMMY5
#undef __SFC_ATTIVARESET4
#undef __SFC_TIMEDUMMY6
#undef __SFC_ATTIVARESET5
#undef __SFC_TIMEDUMMY7
#undef __SFC_ACCENSIONEMAN
#undef __SFC_ACCENSIONEAUT





