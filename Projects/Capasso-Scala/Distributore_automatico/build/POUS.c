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





void RESET_init__(RESET *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(REAL,CREDITO,data__->CREDITO,retain)
  __INIT_EXTERNAL(REAL,RESTO,data__->RESTO,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EN_O,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void RESET_body__(RESET *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->ENABLE,)) {
    __SET_EXTERNAL(data__->,RESTO,,__GET_EXTERNAL(data__->CREDITO,));
    __SET_EXTERNAL(data__->,CREDITO,,0.0);
    __SET_VAR(data__->,EN_O,,1);
  };

  goto __end;

__end:
  return;
} // RESET_body__() 





void ASSEGNAZIONE_SENSORI_init__(ASSEGNAZIONE_SENSORI *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0A,data__->PRODOTTO_0A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0B,data__->PRODOTTO_0B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0C,data__->PRODOTTO_0C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0D,data__->PRODOTTO_0D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1A,data__->PRODOTTO_1A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1B,data__->PRODOTTO_1B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1C,data__->PRODOTTO_1C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1D,data__->PRODOTTO_1D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2A,data__->PRODOTTO_2A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2B,data__->PRODOTTO_2B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2C,data__->PRODOTTO_2C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2D,data__->PRODOTTO_2D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3A,data__->PRODOTTO_3A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3B,data__->PRODOTTO_3B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3C,data__->PRODOTTO_3C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3D,data__->PRODOTTO_3D,retain)
  __INIT_EXTERNAL(BOOL,S_0A,data__->S_0A,retain)
  __INIT_EXTERNAL(BOOL,S_0B,data__->S_0B,retain)
  __INIT_EXTERNAL(BOOL,S_0C,data__->S_0C,retain)
  __INIT_EXTERNAL(BOOL,S_0D,data__->S_0D,retain)
  __INIT_EXTERNAL(BOOL,S_1A,data__->S_1A,retain)
  __INIT_EXTERNAL(BOOL,S_1B,data__->S_1B,retain)
  __INIT_EXTERNAL(BOOL,S_1C,data__->S_1C,retain)
  __INIT_EXTERNAL(BOOL,S_1D,data__->S_1D,retain)
  __INIT_EXTERNAL(BOOL,S_2A,data__->S_2A,retain)
  __INIT_EXTERNAL(BOOL,S_2B,data__->S_2B,retain)
  __INIT_EXTERNAL(BOOL,S_2C,data__->S_2C,retain)
  __INIT_EXTERNAL(BOOL,S_2D,data__->S_2D,retain)
  __INIT_EXTERNAL(BOOL,S_3A,data__->S_3A,retain)
  __INIT_EXTERNAL(BOOL,S_3B,data__->S_3B,retain)
  __INIT_EXTERNAL(BOOL,S_3C,data__->S_3C,retain)
  __INIT_EXTERNAL(BOOL,S_3D,data__->S_3D,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EN_O,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void ASSEGNAZIONE_SENSORI_body__(ASSEGNAZIONE_SENSORI *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->ENABLE,)) {
    __SET_EXTERNAL(data__->,S_0A,,__GET_EXTERNAL(data__->PRODOTTO_0A,.SENSORE));
    __SET_EXTERNAL(data__->,S_0B,,__GET_EXTERNAL(data__->PRODOTTO_0B,.SENSORE));
    __SET_EXTERNAL(data__->,S_0C,,__GET_EXTERNAL(data__->PRODOTTO_0C,.SENSORE));
    __SET_EXTERNAL(data__->,S_0D,,__GET_EXTERNAL(data__->PRODOTTO_0D,.SENSORE));
    __SET_EXTERNAL(data__->,S_1A,,__GET_EXTERNAL(data__->PRODOTTO_1A,.SENSORE));
    __SET_EXTERNAL(data__->,S_1B,,__GET_EXTERNAL(data__->PRODOTTO_1B,.SENSORE));
    __SET_EXTERNAL(data__->,S_1C,,__GET_EXTERNAL(data__->PRODOTTO_1C,.SENSORE));
    __SET_EXTERNAL(data__->,S_1D,,__GET_EXTERNAL(data__->PRODOTTO_1D,.SENSORE));
    __SET_EXTERNAL(data__->,S_2A,,__GET_EXTERNAL(data__->PRODOTTO_2A,.SENSORE));
    __SET_EXTERNAL(data__->,S_2B,,__GET_EXTERNAL(data__->PRODOTTO_2B,.SENSORE));
    __SET_EXTERNAL(data__->,S_2C,,__GET_EXTERNAL(data__->PRODOTTO_2C,.SENSORE));
    __SET_EXTERNAL(data__->,S_2D,,__GET_EXTERNAL(data__->PRODOTTO_2D,.SENSORE));
    __SET_EXTERNAL(data__->,S_3A,,__GET_EXTERNAL(data__->PRODOTTO_3A,.SENSORE));
    __SET_EXTERNAL(data__->,S_3B,,__GET_EXTERNAL(data__->PRODOTTO_3B,.SENSORE));
    __SET_EXTERNAL(data__->,S_3C,,__GET_EXTERNAL(data__->PRODOTTO_3C,.SENSORE));
    __SET_EXTERNAL(data__->,S_3D,,__GET_EXTERNAL(data__->PRODOTTO_3D,.SENSORE));
    __SET_VAR(data__->,EN_O,,1);
  };

  goto __end;

__end:
  return;
} // ASSEGNAZIONE_SENSORI_body__() 





void SENSORI_RIFORNIMENTO_init__(SENSORI_RIFORNIMENTO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(BOOL,S_0A,data__->S_0A,retain)
  __INIT_EXTERNAL(BOOL,S_0B,data__->S_0B,retain)
  __INIT_EXTERNAL(BOOL,S_0C,data__->S_0C,retain)
  __INIT_EXTERNAL(BOOL,S_0D,data__->S_0D,retain)
  __INIT_EXTERNAL(BOOL,S_1A,data__->S_1A,retain)
  __INIT_EXTERNAL(BOOL,S_1B,data__->S_1B,retain)
  __INIT_EXTERNAL(BOOL,S_1C,data__->S_1C,retain)
  __INIT_EXTERNAL(BOOL,S_1D,data__->S_1D,retain)
  __INIT_EXTERNAL(BOOL,S_2A,data__->S_2A,retain)
  __INIT_EXTERNAL(BOOL,S_2B,data__->S_2B,retain)
  __INIT_EXTERNAL(BOOL,S_2C,data__->S_2C,retain)
  __INIT_EXTERNAL(BOOL,S_2D,data__->S_2D,retain)
  __INIT_EXTERNAL(BOOL,S_3A,data__->S_3A,retain)
  __INIT_EXTERNAL(BOOL,S_3B,data__->S_3B,retain)
  __INIT_EXTERNAL(BOOL,S_3C,data__->S_3C,retain)
  __INIT_EXTERNAL(BOOL,S_3D,data__->S_3D,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INVIA_SEGNALE,__BOOL_LITERAL(FALSE),retain)
  ASSEGNAZIONE_SENSORI_init__(&data__->ASSEGNAZIONE_SENSORI0,retain);
}

// Code part
void SENSORI_RIFORNIMENTO_body__(SENSORI_RIFORNIMENTO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->ASSEGNAZIONE_SENSORI0.,ENABLE,,__GET_VAR(data__->ENABLE,));
  ASSEGNAZIONE_SENSORI_body__(&data__->ASSEGNAZIONE_SENSORI0);
  __SET_VAR(data__->,INVIA_SEGNALE,,((((((((!(__GET_EXTERNAL(data__->S_3A,)) && !(__GET_EXTERNAL(data__->S_2A,))) && !(__GET_EXTERNAL(data__->S_1A,))) && !(__GET_EXTERNAL(data__->S_0A,))) || (((!(__GET_EXTERNAL(data__->S_3B,)) && !(__GET_EXTERNAL(data__->S_2B,))) && !(__GET_EXTERNAL(data__->S_1B,))) && !(__GET_EXTERNAL(data__->S_0B,)))) || (((!(__GET_EXTERNAL(data__->S_3C,)) && !(__GET_EXTERNAL(data__->S_2C,))) && !(__GET_EXTERNAL(data__->S_1C,))) && !(__GET_EXTERNAL(data__->S_0C,)))) || (((!(__GET_EXTERNAL(data__->S_3D,)) && !(__GET_EXTERNAL(data__->S_2D,))) && !(__GET_EXTERNAL(data__->S_1D,))) && !(__GET_EXTERNAL(data__->S_0D,)))) && ((((((!(__GET_EXTERNAL(data__->S_0D,)) && !(__GET_EXTERNAL(data__->S_0C,))) && !(__GET_EXTERNAL(data__->S_0B,))) && !(__GET_EXTERNAL(data__->S_0A,))) || (((!(__GET_EXTERNAL(data__->S_1D,)) && !(__GET_EXTERNAL(data__->S_1C,))) && !(__GET_EXTERNAL(data__->S_1B,))) && !(__GET_EXTERNAL(data__->S_1A,)))) || (((!(__GET_EXTERNAL(data__->S_2D,)) && !(__GET_EXTERNAL(data__->S_2C,))) && !(__GET_EXTERNAL(data__->S_2B,))) && !(__GET_EXTERNAL(data__->S_2A,)))) || (((!(__GET_EXTERNAL(data__->S_3D,)) && !(__GET_EXTERNAL(data__->S_3C,))) && !(__GET_EXTERNAL(data__->S_3B,))) && !(__GET_EXTERNAL(data__->S_3A,))))) && __GET_VAR(data__->ASSEGNAZIONE_SENSORI0.EN_O,)));

  goto __end;

__end:
  return;
} // SENSORI_RIFORNIMENTO_body__() 





void ASSEGNAZIONE_PRODOTTO_init__(ASSEGNAZIONE_PRODOTTO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(STRING,NUMERO,data__->NUMERO,retain)
  __INIT_EXTERNAL(REAL,PREZZO,data__->PREZZO,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0A,data__->PRODOTTO_0A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0B,data__->PRODOTTO_0B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0C,data__->PRODOTTO_0C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0D,data__->PRODOTTO_0D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1A,data__->PRODOTTO_1A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1B,data__->PRODOTTO_1B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1C,data__->PRODOTTO_1C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1D,data__->PRODOTTO_1D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2A,data__->PRODOTTO_2A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2B,data__->PRODOTTO_2B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2C,data__->PRODOTTO_2C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2D,data__->PRODOTTO_2D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3A,data__->PRODOTTO_3A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3B,data__->PRODOTTO_3B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3C,data__->PRODOTTO_3C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3D,data__->PRODOTTO_3D,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SELECTED,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->EN_O,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void ASSEGNAZIONE_PRODOTTO_body__(ASSEGNAZIONE_PRODOTTO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->ENABLE,)) {
    if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"0A"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_0A,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"0B"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_0B,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"0C"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_0C,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"0D"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_0D,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"1A"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_1A,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"1B"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_1B,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"1C"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_1C,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"1D"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_1D,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"2A"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_2A,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"2B"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_2B,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"2C"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_2C,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"2D"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_2D,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"3A"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_3A,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"3B"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_3B,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"3C"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_3C,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELECTED,), __STRING_LITERAL(2,"3D"))) {
      __SET_EXTERNAL(data__->,NUMERO,,__GET_VAR(data__->SELECTED,));
      __SET_EXTERNAL(data__->,PREZZO,,__GET_EXTERNAL(data__->PRODOTTO_3D,.PREZZO));
      __SET_VAR(data__->,EN_O,,1);
    };
  };

  goto __end;

__end:
  return;
} // ASSEGNAZIONE_PRODOTTO_body__() 





void INIZIALIZZAZIONE_init__(INIZIALIZZAZIONE *data__, BOOL retain) {
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0A,data__->PRODOTTO_0A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0B,data__->PRODOTTO_0B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0C,data__->PRODOTTO_0C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0D,data__->PRODOTTO_0D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1A,data__->PRODOTTO_1A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1B,data__->PRODOTTO_1B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1C,data__->PRODOTTO_1C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1D,data__->PRODOTTO_1D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2A,data__->PRODOTTO_2A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2B,data__->PRODOTTO_2B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2C,data__->PRODOTTO_2C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2D,data__->PRODOTTO_2D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3A,data__->PRODOTTO_3A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3B,data__->PRODOTTO_3B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3C,data__->PRODOTTO_3C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3D,data__->PRODOTTO_3D,retain)
  __INIT_EXTERNAL(BOOL,SINGLE_EX,data__->SINGLE_EX,retain)
}

// Code part
void INIZIALIZZAZIONE_body__(INIZIALIZZAZIONE *data__) {
  // Initialise TEMP variables

  if (__GET_EXTERNAL(data__->SINGLE_EX,)) {
    __SET_EXTERNAL(data__->,PRODOTTO_0A,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_0A,.PREZZO,0.70);
    __SET_EXTERNAL(data__->,PRODOTTO_0A,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_0B,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_0B,.PREZZO,0.80);
    __SET_EXTERNAL(data__->,PRODOTTO_0B,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_0C,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_0C,.PREZZO,0.80);
    __SET_EXTERNAL(data__->,PRODOTTO_0C,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_0D,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_0D,.PREZZO,0.90);
    __SET_EXTERNAL(data__->,PRODOTTO_0D,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_1A,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_1A,.PREZZO,1.0);
    __SET_EXTERNAL(data__->,PRODOTTO_1A,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_1B,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_1B,.PREZZO,1.10);
    __SET_EXTERNAL(data__->,PRODOTTO_1B,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_1C,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_1C,.PREZZO,1.10);
    __SET_EXTERNAL(data__->,PRODOTTO_1C,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_1D,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_1D,.PREZZO,1.20);
    __SET_EXTERNAL(data__->,PRODOTTO_1D,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_2A,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_2A,.PREZZO,1.50);
    __SET_EXTERNAL(data__->,PRODOTTO_2A,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_2B,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_2B,.PREZZO,1.50);
    __SET_EXTERNAL(data__->,PRODOTTO_2B,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_2C,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_2C,.PREZZO,1.80);
    __SET_EXTERNAL(data__->,PRODOTTO_2C,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_2D,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_2D,.PREZZO,1.80);
    __SET_EXTERNAL(data__->,PRODOTTO_2D,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_3A,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_3A,.PREZZO,0.80);
    __SET_EXTERNAL(data__->,PRODOTTO_3A,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_3B,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_3B,.PREZZO,1.50);
    __SET_EXTERNAL(data__->,PRODOTTO_3B,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_3C,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_3C,.PREZZO,0.50);
    __SET_EXTERNAL(data__->,PRODOTTO_3C,.SENSORE,1);
    __SET_EXTERNAL(data__->,PRODOTTO_3D,.MOTORE,0);
    __SET_EXTERNAL(data__->,PRODOTTO_3D,.PREZZO,0.50);
    __SET_EXTERNAL(data__->,PRODOTTO_3D,.SENSORE,1);
    __SET_EXTERNAL(data__->,SINGLE_EX,,0);
  };

  goto __end;

__end:
  return;
} // INIZIALIZZAZIONE_body__() 





void EROGA_PRODOTTO_init__(EROGA_PRODOTTO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(STRING,NUMERO,data__->NUMERO,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0A,data__->PRODOTTO_0A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0B,data__->PRODOTTO_0B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0C,data__->PRODOTTO_0C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0D,data__->PRODOTTO_0D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1A,data__->PRODOTTO_1A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1B,data__->PRODOTTO_1B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1C,data__->PRODOTTO_1C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_1D,data__->PRODOTTO_1D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2A,data__->PRODOTTO_2A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2B,data__->PRODOTTO_2B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2C,data__->PRODOTTO_2C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_2D,data__->PRODOTTO_2D,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3A,data__->PRODOTTO_3A,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3B,data__->PRODOTTO_3B,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3C,data__->PRODOTTO_3C,retain)
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_3D,data__->PRODOTTO_3D,retain)
  __INIT_VAR(data__->EN_O,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void EROGA_PRODOTTO_body__(EROGA_PRODOTTO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"0A"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_0A,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"0B"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_0B,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"0C"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_0C,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"0D"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_0D,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"1A"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_1A,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"1B"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_1B,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"1C"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_1C,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"1D"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_1D,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"2A"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_2A,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"2B"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_2B,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"2C"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_2C,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"2D"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_2D,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"3A"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_3A,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"3B"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_3B,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"3C"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_3C,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  } else if (EQ_STRING(__BOOL_LITERAL(TRUE), NULL, 2, __GET_EXTERNAL(data__->NUMERO,), __STRING_LITERAL(2,"3D"))) {
    __SET_EXTERNAL(data__->,PRODOTTO_3D,.MOTORE,1);
    __SET_VAR(data__->,EN_O,,1);
  };

  goto __end;

__end:
  return;
} // EROGA_PRODOTTO_body__() 





void SCELTA_PRODOTTO_init__(SCELTA_PRODOTTO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->EN_TASTIERINO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EN_O,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_A,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_B,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_C,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_D,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON_R,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SELECTED,__STRING_LITERAL(0,""),retain)
  RESET_init__(&data__->RESET0,retain);
  __INIT_VAR(data__->EROGA_RESTO,__BOOL_LITERAL(FALSE),retain)
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE0,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE1,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE2,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE3,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE4,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE5,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE6,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE7,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE8,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE9,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE10,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE11,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE12,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE13,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE14,retain);
  ASSEGNAZIONE_PRODOTTO_init__(&data__->ASSEGNAZIONE15,retain);
}

// Code part
void SCELTA_PRODOTTO_body__(SCELTA_PRODOTTO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->ASSEGNAZIONE0.,ENABLE,,((__GET_VAR(data__->BUTTON_A,) && __GET_VAR(data__->BUTTON_0,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE0.,SELECTED,,__STRING_LITERAL(2,"0A"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE0);
  __SET_VAR(data__->ASSEGNAZIONE1.,ENABLE,,((__GET_VAR(data__->BUTTON_B,) && __GET_VAR(data__->BUTTON_0,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE1.,SELECTED,,__STRING_LITERAL(2,"0B"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE1);
  __SET_VAR(data__->ASSEGNAZIONE2.,ENABLE,,((__GET_VAR(data__->BUTTON_C,) && __GET_VAR(data__->BUTTON_0,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE2.,SELECTED,,__STRING_LITERAL(2,"0C"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE2);
  __SET_VAR(data__->ASSEGNAZIONE3.,ENABLE,,((__GET_VAR(data__->BUTTON_D,) && __GET_VAR(data__->BUTTON_0,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE3.,SELECTED,,__STRING_LITERAL(2,"0D"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE3);
  __SET_VAR(data__->ASSEGNAZIONE4.,ENABLE,,((__GET_VAR(data__->BUTTON_A,) && __GET_VAR(data__->BUTTON_1,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE4.,SELECTED,,__STRING_LITERAL(2,"1A"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE4);
  __SET_VAR(data__->ASSEGNAZIONE5.,ENABLE,,((__GET_VAR(data__->BUTTON_B,) && __GET_VAR(data__->BUTTON_1,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE5.,SELECTED,,__STRING_LITERAL(2,"1B"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE5);
  __SET_VAR(data__->ASSEGNAZIONE6.,ENABLE,,((__GET_VAR(data__->BUTTON_C,) && __GET_VAR(data__->BUTTON_1,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE6.,SELECTED,,__STRING_LITERAL(2,"1C"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE6);
  __SET_VAR(data__->ASSEGNAZIONE7.,ENABLE,,((__GET_VAR(data__->BUTTON_D,) && __GET_VAR(data__->BUTTON_1,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE7.,SELECTED,,__STRING_LITERAL(2,"1D"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE7);
  __SET_VAR(data__->ASSEGNAZIONE8.,ENABLE,,((__GET_VAR(data__->BUTTON_A,) && __GET_VAR(data__->BUTTON_2,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE8.,SELECTED,,__STRING_LITERAL(2,"2A"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE8);
  __SET_VAR(data__->ASSEGNAZIONE9.,ENABLE,,((__GET_VAR(data__->BUTTON_B,) && __GET_VAR(data__->BUTTON_2,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE9.,SELECTED,,__STRING_LITERAL(2,"2B"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE9);
  __SET_VAR(data__->ASSEGNAZIONE10.,ENABLE,,((__GET_VAR(data__->BUTTON_C,) && __GET_VAR(data__->BUTTON_2,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE10.,SELECTED,,__STRING_LITERAL(2,"2C"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE10);
  __SET_VAR(data__->ASSEGNAZIONE11.,ENABLE,,((__GET_VAR(data__->BUTTON_D,) && __GET_VAR(data__->BUTTON_2,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE11.,SELECTED,,__STRING_LITERAL(2,"2D"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE11);
  __SET_VAR(data__->ASSEGNAZIONE12.,ENABLE,,((__GET_VAR(data__->BUTTON_A,) && __GET_VAR(data__->BUTTON_3,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE12.,SELECTED,,__STRING_LITERAL(2,"3A"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE12);
  __SET_VAR(data__->ASSEGNAZIONE13.,ENABLE,,((__GET_VAR(data__->BUTTON_B,) && __GET_VAR(data__->BUTTON_3,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE13.,SELECTED,,__STRING_LITERAL(2,"3B"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE13);
  __SET_VAR(data__->ASSEGNAZIONE14.,ENABLE,,((__GET_VAR(data__->BUTTON_C,) && __GET_VAR(data__->BUTTON_3,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE14.,SELECTED,,__STRING_LITERAL(2,"3C"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE14);
  __SET_VAR(data__->ASSEGNAZIONE15.,ENABLE,,((__GET_VAR(data__->BUTTON_D,) && __GET_VAR(data__->BUTTON_3,)) && __GET_VAR(data__->EN_TASTIERINO,)));
  __SET_VAR(data__->ASSEGNAZIONE15.,SELECTED,,__STRING_LITERAL(2,"3D"));
  ASSEGNAZIONE_PRODOTTO_body__(&data__->ASSEGNAZIONE15);
  __SET_VAR(data__->,EN_O,,(((((((((((((((__GET_VAR(data__->ASSEGNAZIONE0.EN_O,) || __GET_VAR(data__->ASSEGNAZIONE1.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE10.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE11.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE12.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE13.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE14.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE15.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE2.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE3.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE4.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE5.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE6.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE7.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE8.EN_O,)) || __GET_VAR(data__->ASSEGNAZIONE9.EN_O,)));
  __SET_VAR(data__->RESET0.,ENABLE,,(__GET_VAR(data__->BUTTON_R,) && __GET_VAR(data__->EN_TASTIERINO,)));
  RESET_body__(&data__->RESET0);
  __SET_VAR(data__->,EROGA_RESTO,,__GET_VAR(data__->RESET0.EN_O,));

  goto __end;

__end:
  return;
} // SCELTA_PRODOTTO_body__() 





void GETTONIERA_init__(GETTONIERA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(REAL,CREDITO,data__->CREDITO,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_05,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_10,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EN_TASTIERINO,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->BOOL_TO_REAL5_OUT,0,retain)
  __INIT_VAR(data__->MUL6_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_REAL13_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_REAL16_OUT,0,retain)
  __INIT_VAR(data__->MUL17_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_REAL21_OUT,0,retain)
  __INIT_VAR(data__->MUL22_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_REAL33_OUT,0,retain)
  __INIT_VAR(data__->MUL34_OUT,0,retain)
  __INIT_VAR(data__->ADD8_OUT,0,retain)
  __INIT_VAR(data__->REAL_TO_BOOL43_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void GETTONIERA_body__(GETTONIERA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG0.,CLK,,(__GET_VAR(data__->MONETA_05,) && __GET_VAR(data__->ENABLE,)));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,BOOL_TO_REAL5_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,)));
  __SET_VAR(data__->,MUL6_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL5_OUT,),
    (REAL)0.5));
  __SET_VAR(data__->R_TRIG1.,CLK,,(__GET_VAR(data__->MONETA_1,) && __GET_VAR(data__->ENABLE,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,BOOL_TO_REAL13_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,)));
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->MONETA_2,) && __GET_VAR(data__->ENABLE,)));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,BOOL_TO_REAL16_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG2.Q,)));
  __SET_VAR(data__->,MUL17_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL16_OUT,),
    (REAL)2.0));
  __SET_VAR(data__->R_TRIG3.,CLK,,(__GET_VAR(data__->MONETA_5,) && __GET_VAR(data__->ENABLE,)));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->,BOOL_TO_REAL21_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG3.Q,)));
  __SET_VAR(data__->,MUL22_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL21_OUT,),
    (REAL)5.0));
  __SET_VAR(data__->R_TRIG4.,CLK,,(__GET_VAR(data__->MONETA_10,) && __GET_VAR(data__->ENABLE,)));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->,BOOL_TO_REAL33_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG4.Q,)));
  __SET_VAR(data__->,MUL34_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL33_OUT,),
    (REAL)10.0));
  __SET_VAR(data__->,ADD8_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)6,
    (REAL)__GET_VAR(data__->MUL6_OUT,),
    (REAL)__GET_VAR(data__->BOOL_TO_REAL13_OUT,),
    (REAL)__GET_VAR(data__->MUL17_OUT,),
    (REAL)__GET_VAR(data__->MUL22_OUT,),
    (REAL)__GET_VAR(data__->MUL34_OUT,),
    (REAL)__GET_EXTERNAL(data__->CREDITO,)));
  __SET_VAR(data__->,REAL_TO_BOOL43_OUT,,REAL_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->ADD8_OUT,)));
  __SET_VAR(data__->,EN_TASTIERINO,,__GET_VAR(data__->REAL_TO_BOOL43_OUT,));
  __SET_EXTERNAL(data__->,CREDITO,,__GET_VAR(data__->ADD8_OUT,));

  goto __end;

__end:
  return;
} // GETTONIERA_body__() 





inline BOOL __MAIN_GE__BOOL__REAL1(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  MAIN *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->GE10_ENO,);
  __res = GE__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->GE10_ENO,,__TMP_ENO);
  return __res;
}

inline REAL __MAIN_SUB__REAL__REAL__REAL2(BOOL EN,
  REAL IN1,
  REAL IN2,
  MAIN *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->SUB12_ENO,);
  __res = SUB__REAL__REAL__REAL(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->SUB12_ENO,,__TMP_ENO);
  return __res;
}

void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_EXTERNAL(REAL,CREDITO,data__->CREDITO,retain)
  __INIT_EXTERNAL(STRING,NUMERO,data__->NUMERO,retain)
  __INIT_EXTERNAL(REAL,PREZZO,data__->PREZZO,retain)
  __INIT_EXTERNAL(REAL,RESTO,data__->RESTO,retain)
  __INIT_VAR(data__->START,1,retain)
  __INIT_VAR(data__->MONETA_05,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MONETA_10,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMPO,__time_to_timespec(1, 0, 30, 0, 0, 0),retain)
  __INIT_VAR(data__->EN_RIFORNIMENTO,1,retain)
  __INIT_VAR(data__->AVVISA_CENTRALE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SBLOCCA_VANO,0,retain)
  __INIT_VAR(data__->LETTURA_CARTA,0,retain)
  __INIT_VAR(data__->ADDEBITA_CARTA,0,retain)
  GETTONIERA_init__(&data__->GETTONIERA0,retain);
  SCELTA_PRODOTTO_init__(&data__->SCELTA_PRODOTTO0,retain);
  EROGA_PRODOTTO_init__(&data__->EROGA_PRODOTTO0,retain);
  __INIT_VAR(data__->EROGA_RESTO,0,retain)
  TON_init__(&data__->TON0,retain);
  EROGA_PRODOTTO_init__(&data__->EROGA_PRODOTTO1,retain);
  SCELTA_PRODOTTO_init__(&data__->SCELTA_PRODOTTO1,retain);
  TON_init__(&data__->TON1,retain);
  SENSORI_RIFORNIMENTO_init__(&data__->SENSORI_RIFORNIMENTO0,retain);
  __INIT_EXTERNAL(PRODOTTO,PRODOTTO_0A,data__->PRODOTTO_0A,retain)
  __INIT_VAR(data__->GE10_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GE10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUB12_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUB12_OUT,0,retain)
  __INIT_VAR(data__->REAL_TO_BOOL23_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->GETTONIERA0.,ENABLE,,__GET_VAR(data__->START,));
  __SET_VAR(data__->GETTONIERA0.,MONETA_05,,(__GET_VAR(data__->MONETA_05,) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,MONETA_1,,(__GET_VAR(data__->MONETA_1,) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,MONETA_2,,(__GET_VAR(data__->MONETA_2,) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,MONETA_5,,(__GET_VAR(data__->MONETA_5,) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,MONETA_10,,(__GET_VAR(data__->MONETA_10,) && __GET_VAR(data__->START,)));
  GETTONIERA_body__(&data__->GETTONIERA0);
  __SET_VAR(data__->SCELTA_PRODOTTO0.,EN_TASTIERINO,,__GET_VAR(data__->GETTONIERA0.EN_TASTIERINO,));
  SCELTA_PRODOTTO_body__(&data__->SCELTA_PRODOTTO0);
  __SET_VAR(data__->,GE10_OUT,,__MAIN_GE__BOOL__REAL1(
    (BOOL)__GET_VAR(data__->SCELTA_PRODOTTO0.EN_O,),
    (UINT)2,
    (REAL)__GET_EXTERNAL(data__->CREDITO,),
    (REAL)__GET_EXTERNAL(data__->PREZZO,),
    data__));
  __SET_VAR(data__->,SUB12_OUT,,__MAIN_SUB__REAL__REAL__REAL2(
    (BOOL)__GET_VAR(data__->GE10_OUT,),
    (REAL)__GET_EXTERNAL(data__->CREDITO,),
    (REAL)__GET_EXTERNAL(data__->PREZZO,),
    data__));
  __SET_VAR(data__->EROGA_PRODOTTO0.,EN,,__GET_VAR(data__->SUB12_ENO,));
  EROGA_PRODOTTO_body__(&data__->EROGA_PRODOTTO0);
  __SET_VAR(data__->,SBLOCCA_VANO,,__GET_VAR(data__->EROGA_PRODOTTO0.EN_O,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->EROGA_PRODOTTO0.EN_O,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->TEMPO,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,SBLOCCA_VANO,,!(__GET_VAR(data__->TON0.Q,)));
  if (__GET_VAR(data__->SUB12_ENO,)) {
    __SET_EXTERNAL(data__->,RESTO,,__GET_VAR(data__->SUB12_OUT,));
  };
  __SET_VAR(data__->,REAL_TO_BOOL23_OUT,,REAL_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->SUB12_OUT,)));
  __SET_VAR(data__->,EROGA_RESTO,,__GET_VAR(data__->REAL_TO_BOOL23_OUT,));
  __SET_VAR(data__->SCELTA_PRODOTTO1.,EN_TASTIERINO,,(__GET_VAR(data__->LETTURA_CARTA,) && __GET_VAR(data__->START,)));
  SCELTA_PRODOTTO_body__(&data__->SCELTA_PRODOTTO1);
  __SET_VAR(data__->EROGA_PRODOTTO1.,EN,,__GET_VAR(data__->SCELTA_PRODOTTO1.EN_O,));
  EROGA_PRODOTTO_body__(&data__->EROGA_PRODOTTO1);
  __SET_VAR(data__->,SBLOCCA_VANO,,__GET_VAR(data__->EROGA_PRODOTTO1.EN_O,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->EROGA_PRODOTTO1.EN_O,));
  __SET_VAR(data__->TON1.,PT,,__GET_VAR(data__->TEMPO,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,SBLOCCA_VANO,,!(__GET_VAR(data__->TON1.Q,)));
  __SET_VAR(data__->,ADDEBITA_CARTA,,__GET_VAR(data__->EROGA_PRODOTTO1.EN_O,));
  __SET_VAR(data__->SENSORI_RIFORNIMENTO0.,ENABLE,,__GET_VAR(data__->START,));
  SENSORI_RIFORNIMENTO_body__(&data__->SENSORI_RIFORNIMENTO0);
  __SET_VAR(data__->,AVVISA_CENTRALE,,__GET_VAR(data__->SENSORI_RIFORNIMENTO0.INVIA_SEGNALE,));

  goto __end;

__end:
  return;
} // MAIN_body__() 





