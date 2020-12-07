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





void OUT_USINT_QUEUE_init__(OUT_USINT_QUEUE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(USINT_QUEUE,QUEUE,data__->QUEUE,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DATA,0,retain)
}

// Code part
void OUT_USINT_QUEUE_body__(OUT_USINT_QUEUE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,DATA,,__GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_EXTERNAL(data__->QUEUE,.BOT)) - (0)]));
    __SET_EXTERNAL(data__->,QUEUE,.BOT,((20 == 0)?0:((__GET_EXTERNAL(data__->QUEUE,.BOT) + 1) % 20)));
    __SET_EXTERNAL(data__->,QUEUE,.DIM,(__GET_EXTERNAL(data__->QUEUE,.DIM) - 1));
  };

  goto __end;

__end:
  return;
} // OUT_USINT_QUEUE_body__() 





void EN_USINT_STATE_init__(EN_USINT_STATE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(USINT,STATE,data__->STATE,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DATA,0,retain)
}

// Code part
void EN_USINT_STATE_body__(EN_USINT_STATE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->IN,)) {
    __SET_EXTERNAL(data__->,STATE,,__GET_VAR(data__->DATA,));
  };

  goto __end;

__end:
  return;
} // EN_USINT_STATE_body__() 





void ENCODER_init__(ENCODER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DATA0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DATA1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DATA,0,retain)
  __INIT_VAR(data__->BOOL_TO_USINT22_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_USINT6_OUT,0,retain)
  __INIT_VAR(data__->MUL25_OUT,0,retain)
  __INIT_VAR(data__->ADD35_OUT,0,retain)
}

// Code part
void ENCODER_body__(ENCODER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->IN0,)) {
    __SET_VAR(data__->,DATA1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->IN0,)) {
    __SET_VAR(data__->,DATA0,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->IN1,)) {
    __SET_VAR(data__->,DATA1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->IN1,)) {
    __SET_VAR(data__->,DATA0,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->IN2,)) {
    __SET_VAR(data__->,DATA1,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->IN2,)) {
    __SET_VAR(data__->,DATA0,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->IN3,)) {
    __SET_VAR(data__->,DATA1,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->IN3,)) {
    __SET_VAR(data__->,DATA0,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,BOOL_TO_USINT22_OUT,,BOOL_TO_USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->DATA0,)));
  __SET_VAR(data__->,BOOL_TO_USINT6_OUT,,BOOL_TO_USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->DATA1,)));
  __SET_VAR(data__->,MUL25_OUT,,MUL__USINT__USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (USINT)__GET_VAR(data__->BOOL_TO_USINT6_OUT,),
    (USINT)2));
  __SET_VAR(data__->,ADD35_OUT,,ADD__USINT__USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (USINT)__GET_VAR(data__->BOOL_TO_USINT22_OUT,),
    (USINT)__GET_VAR(data__->MUL25_OUT,)));
  __SET_VAR(data__->,DATA,,__GET_VAR(data__->ADD35_OUT,));
  __SET_VAR(data__->,OUT,,(((__GET_VAR(data__->IN0,) || __GET_VAR(data__->IN1,)) || __GET_VAR(data__->IN2,)) || __GET_VAR(data__->IN3,)));

  goto __end;

__end:
  return;
} // ENCODER_body__() 





void IN_USINT_QUEUE_init__(IN_USINT_QUEUE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(USINT_QUEUE,QUEUE,data__->QUEUE,retain)
  __INIT_EXTERNAL(USINT,STATE,data__->STATE,retain)
  __INIT_EXTERNAL(BOOL,DIR,data__->DIR,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->J,0,retain)
  __INIT_VAR(data__->H,0,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DATA,0,retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void IN_USINT_QUEUE_body__(IN_USINT_QUEUE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->IN,)) {
    if ((__GET_VAR(data__->DATA,) > __GET_EXTERNAL(data__->STATE,))) {
      __SET_VAR(data__->,I,,__GET_EXTERNAL(data__->QUEUE,.BOT));
      for(__GET_VAR(data__->H,) = 0; __GET_VAR(data__->H,) <= (__GET_EXTERNAL(data__->QUEUE,.DIM) - 1); __GET_VAR(data__->H,)++) {
        if (((__GET_VAR(data__->DATA,) < __GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_VAR(data__->I,)) - (0)])) || ((__GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_VAR(data__->I,)) - (0)]) < __GET_EXTERNAL(data__->STATE,)) && (__GET_EXTERNAL(data__->DIR,) == 1)))) {
          break;
        };
        __SET_VAR(data__->,I,,((20 == 0)?0:((__GET_VAR(data__->I,) + 1) % 20)));
      };
    } else if ((__GET_VAR(data__->DATA,) < __GET_EXTERNAL(data__->STATE,))) {
      __SET_VAR(data__->,I,,__GET_EXTERNAL(data__->QUEUE,.BOT));
      for(__GET_VAR(data__->H,) = 0; __GET_VAR(data__->H,) <= (__GET_EXTERNAL(data__->QUEUE,.DIM) - 1); __GET_VAR(data__->H,)++) {
        if (((__GET_VAR(data__->DATA,) > __GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_VAR(data__->I,)) - (0)])) || ((__GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_VAR(data__->I,)) - (0)]) > __GET_EXTERNAL(data__->STATE,)) && (__GET_EXTERNAL(data__->DIR,) == 0)))) {
          break;
        };
        __SET_VAR(data__->,I,,((20 == 0)?0:((__GET_VAR(data__->I,) + 1) % 20)));
      };
    };
    for(__GET_VAR(data__->J,) = __GET_EXTERNAL(data__->QUEUE,.TOP); __GET_VAR(data__->J,) <= (__GET_VAR(data__->I,) + 1); __GET_VAR(data__->J,)++) {
      __SET_EXTERNAL(data__->,QUEUE,.ARR.table[(__GET_VAR(data__->J,)) - (0)],__GET_EXTERNAL(data__->QUEUE,.ARR.table[((__GET_VAR(data__->J,) - 1)) - (0)]));
    };
    __SET_EXTERNAL(data__->,QUEUE,.ARR.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->DATA,));
    __SET_EXTERNAL(data__->,QUEUE,.TOP,((20 == 0)?0:((__GET_EXTERNAL(data__->QUEUE,.TOP) + 1) % 20)));
    __SET_EXTERNAL(data__->,QUEUE,.DIM,(__GET_EXTERNAL(data__->QUEUE,.DIM) + 1));
  };
  __SET_VAR(data__->,OUT,,(__GET_EXTERNAL(data__->QUEUE,.DIM) > 0));

  goto __end;

__end:
  return;
} // IN_USINT_QUEUE_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_EXTERNAL(USINT_QUEUE,QUEUE,data__->QUEUE,retain)
  __INIT_EXTERNAL(USINT,STATE,data__->STATE,retain)
  __INIT_EXTERNAL(BOOL,DIR,data__->DIR,retain)
  __INIT_VAR(data__->READY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SNS0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SNS1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SNS2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SNS3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IND0,1,retain)
  __INIT_VAR(data__->IND1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IND2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IND3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ00,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ11,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ22,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ33,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPEN,__BOOL_LITERAL(FALSE),retain)
  ENCODER_init__(&data__->ENCODER0,retain);
  EN_USINT_STATE_init__(&data__->EN_USINT_STATE0,retain);
  ENCODER_init__(&data__->ENCODER1,retain);
  IN_USINT_QUEUE_init__(&data__->IN_USINT_QUEUE0,retain);
  TON_init__(&data__->TON0,retain);
  OUT_USINT_QUEUE_init__(&data__->OUT_USINT_QUEUE0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  R_TRIG_init__(&data__->R_TRIG6,retain);
  R_TRIG_init__(&data__->R_TRIG7,retain);
  R_TRIG_init__(&data__->R_TRIG8,retain);
  R_TRIG_init__(&data__->R_TRIG9,retain);
  R_TRIG_init__(&data__->R_TRIG10,retain);
  R_TRIG_init__(&data__->R_TRIG11,retain);
  R_TRIG_init__(&data__->R_TRIG12,retain);
  R_TRIG_init__(&data__->R_TRIG13,retain);
  R_TRIG_init__(&data__->R_TRIG14,retain);
  R_TRIG_init__(&data__->R_TRIG15,retain);
  R_TRIG_init__(&data__->R_TRIG16,retain);
  R_TRIG_init__(&data__->R_TRIG17,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG18,retain);
  R_TRIG_init__(&data__->R_TRIG19,retain);
  R_TRIG_init__(&data__->R_TRIG20,retain);
  R_TRIG_init__(&data__->R_TRIG21,retain);
  R_TRIG_init__(&data__->R_TRIG22,retain);
  R_TRIG_init__(&data__->R_TRIG23,retain);
  R_TRIG_init__(&data__->R_TRIG24,retain);
  __INIT_VAR(data__->EQ103_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT44_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT50_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG25,retain);
  R_TRIG_init__(&data__->R_TRIG26,retain);
  R_TRIG_init__(&data__->R_TRIG27,retain);
  R_TRIG_init__(&data__->R_TRIG28,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->SNS0,));
  R_TRIG_body__(&data__->R_TRIG1);
  if (__GET_VAR(data__->R_TRIG1.Q,)) {
    __SET_VAR(data__->,IND0,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->SNS0,));
  R_TRIG_body__(&data__->R_TRIG2);
  if (__GET_VAR(data__->R_TRIG2.Q,)) {
    __SET_VAR(data__->,IND1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->SNS0,));
  R_TRIG_body__(&data__->R_TRIG3);
  if (__GET_VAR(data__->R_TRIG3.Q,)) {
    __SET_VAR(data__->,IND2,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->SNS0,));
  R_TRIG_body__(&data__->R_TRIG4);
  if (__GET_VAR(data__->R_TRIG4.Q,)) {
    __SET_VAR(data__->,IND3,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_VAR(data__->SNS1,));
  R_TRIG_body__(&data__->R_TRIG5);
  if (__GET_VAR(data__->R_TRIG5.Q,)) {
    __SET_VAR(data__->,IND0,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_VAR(data__->SNS1,));
  R_TRIG_body__(&data__->R_TRIG6);
  if (__GET_VAR(data__->R_TRIG6.Q,)) {
    __SET_VAR(data__->,IND1,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG7.,CLK,,__GET_VAR(data__->SNS1,));
  R_TRIG_body__(&data__->R_TRIG7);
  if (__GET_VAR(data__->R_TRIG7.Q,)) {
    __SET_VAR(data__->,IND2,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG8.,CLK,,__GET_VAR(data__->SNS1,));
  R_TRIG_body__(&data__->R_TRIG8);
  if (__GET_VAR(data__->R_TRIG8.Q,)) {
    __SET_VAR(data__->,IND3,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG9.,CLK,,__GET_VAR(data__->SNS2,));
  R_TRIG_body__(&data__->R_TRIG9);
  if (__GET_VAR(data__->R_TRIG9.Q,)) {
    __SET_VAR(data__->,IND0,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG10.,CLK,,__GET_VAR(data__->SNS2,));
  R_TRIG_body__(&data__->R_TRIG10);
  if (__GET_VAR(data__->R_TRIG10.Q,)) {
    __SET_VAR(data__->,IND1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG11.,CLK,,__GET_VAR(data__->SNS2,));
  R_TRIG_body__(&data__->R_TRIG11);
  if (__GET_VAR(data__->R_TRIG11.Q,)) {
    __SET_VAR(data__->,IND2,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG12.,CLK,,__GET_VAR(data__->SNS2,));
  R_TRIG_body__(&data__->R_TRIG12);
  if (__GET_VAR(data__->R_TRIG12.Q,)) {
    __SET_VAR(data__->,IND3,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG13.,CLK,,__GET_VAR(data__->SNS3,));
  R_TRIG_body__(&data__->R_TRIG13);
  if (__GET_VAR(data__->R_TRIG13.Q,)) {
    __SET_VAR(data__->,IND0,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG14.,CLK,,__GET_VAR(data__->SNS3,));
  R_TRIG_body__(&data__->R_TRIG14);
  if (__GET_VAR(data__->R_TRIG14.Q,)) {
    __SET_VAR(data__->,IND1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG15.,CLK,,__GET_VAR(data__->SNS3,));
  R_TRIG_body__(&data__->R_TRIG15);
  if (__GET_VAR(data__->R_TRIG15.Q,)) {
    __SET_VAR(data__->,IND2,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG16.,CLK,,__GET_VAR(data__->SNS3,));
  R_TRIG_body__(&data__->R_TRIG16);
  if (__GET_VAR(data__->R_TRIG16.Q,)) {
    __SET_VAR(data__->,IND3,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG17.,CLK,,__GET_VAR(data__->REQ00,));
  R_TRIG_body__(&data__->R_TRIG17);
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->READY,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->R_TRIG18.,CLK,,__GET_VAR(data__->REQ0,));
  R_TRIG_body__(&data__->R_TRIG18);
  __SET_VAR(data__->R_TRIG19.,CLK,,__GET_VAR(data__->REQ11,));
  R_TRIG_body__(&data__->R_TRIG19);
  __SET_VAR(data__->R_TRIG20.,CLK,,__GET_VAR(data__->REQ1,));
  R_TRIG_body__(&data__->R_TRIG20);
  __SET_VAR(data__->R_TRIG21.,CLK,,__GET_VAR(data__->REQ22,));
  R_TRIG_body__(&data__->R_TRIG21);
  __SET_VAR(data__->R_TRIG22.,CLK,,__GET_VAR(data__->REQ2,));
  R_TRIG_body__(&data__->R_TRIG22);
  __SET_VAR(data__->R_TRIG23.,CLK,,__GET_VAR(data__->REQ33,));
  R_TRIG_body__(&data__->R_TRIG23);
  __SET_VAR(data__->R_TRIG24.,CLK,,__GET_VAR(data__->REQ3,));
  R_TRIG_body__(&data__->R_TRIG24);
  __SET_VAR(data__->ENCODER1.,IN0,,(((!(__GET_VAR(data__->IND0,)) && __GET_VAR(data__->R_TRIG18.Q,)) && (((__GET_VAR(data__->IND0,) || __GET_VAR(data__->IND1,)) || __GET_VAR(data__->IND2,)) || __GET_VAR(data__->IND3,))) || ((__GET_VAR(data__->F_TRIG1.Q,) || __GET_VAR(data__->R_TRIG17.Q,)) && !(__GET_VAR(data__->IND0,)))));
  __SET_VAR(data__->ENCODER1.,IN1,,(((!(__GET_VAR(data__->IND1,)) && __GET_VAR(data__->R_TRIG20.Q,)) && (((__GET_VAR(data__->IND0,) || __GET_VAR(data__->IND1,)) || __GET_VAR(data__->IND2,)) || __GET_VAR(data__->IND3,))) || (__GET_VAR(data__->R_TRIG19.Q,) && !(__GET_VAR(data__->IND1,)))));
  __SET_VAR(data__->ENCODER1.,IN2,,(((!(__GET_VAR(data__->IND2,)) && __GET_VAR(data__->R_TRIG22.Q,)) && ((((__GET_VAR(data__->IND0,) || __GET_VAR(data__->IND0,)) || __GET_VAR(data__->IND1,)) || __GET_VAR(data__->IND2,)) || __GET_VAR(data__->IND3,))) || (__GET_VAR(data__->R_TRIG21.Q,) && !(__GET_VAR(data__->IND2,)))));
  __SET_VAR(data__->ENCODER1.,IN3,,(((!(__GET_VAR(data__->IND3,)) && __GET_VAR(data__->R_TRIG24.Q,)) && (((__GET_VAR(data__->IND0,) || __GET_VAR(data__->IND1,)) || __GET_VAR(data__->IND2,)) || __GET_VAR(data__->IND3,))) || (__GET_VAR(data__->R_TRIG23.Q,) && !(__GET_VAR(data__->IND3,)))));
  ENCODER_body__(&data__->ENCODER1);
  __SET_VAR(data__->IN_USINT_QUEUE0.,IN,,__GET_VAR(data__->ENCODER1.OUT,));
  __SET_VAR(data__->IN_USINT_QUEUE0.,DATA,,__GET_VAR(data__->ENCODER1.DATA,));
  IN_USINT_QUEUE_body__(&data__->IN_USINT_QUEUE0);
  __SET_VAR(data__->,READY,,__GET_VAR(data__->IN_USINT_QUEUE0.OUT,));
  __SET_VAR(data__->,EQ103_OUT,,EQ__BOOL__USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (USINT)__GET_EXTERNAL(data__->STATE,),
    (USINT)__GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_EXTERNAL(data__->QUEUE,.BOT)) - (0)])));
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->EQ103_OUT,))) {
    __SET_VAR(data__->,UP,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->EQ103_OUT,))) {
    __SET_VAR(data__->,DOWN,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->EQ103_OUT,))) {
    __SET_VAR(data__->,OPEN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,LT44_OUT,,LT__BOOL__USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (USINT)__GET_EXTERNAL(data__->STATE,),
    (USINT)__GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_EXTERNAL(data__->QUEUE,.BOT)) - (0)])));
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->LT44_OUT,))) {
    __SET_VAR(data__->,UP,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->LT44_OUT,))) {
    __SET_EXTERNAL(data__->,DIR,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->LT44_OUT,))) {
    __SET_VAR(data__->,OPEN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,GT50_OUT,,GT__BOOL__USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (USINT)__GET_EXTERNAL(data__->STATE,),
    (USINT)__GET_EXTERNAL(data__->QUEUE,.ARR.table[(__GET_EXTERNAL(data__->QUEUE,.BOT)) - (0)])));
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->GT50_OUT,))) {
    __SET_EXTERNAL(data__->,DIR,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->GT50_OUT,))) {
    __SET_VAR(data__->,DOWN,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->READY,) && __GET_VAR(data__->GT50_OUT,))) {
    __SET_VAR(data__->,OPEN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG25.,CLK,,__GET_VAR(data__->SNS0,));
  R_TRIG_body__(&data__->R_TRIG25);
  __SET_VAR(data__->R_TRIG26.,CLK,,__GET_VAR(data__->SNS1,));
  R_TRIG_body__(&data__->R_TRIG26);
  __SET_VAR(data__->R_TRIG27.,CLK,,__GET_VAR(data__->SNS2,));
  R_TRIG_body__(&data__->R_TRIG27);
  __SET_VAR(data__->R_TRIG28.,CLK,,__GET_VAR(data__->SNS3,));
  R_TRIG_body__(&data__->R_TRIG28);
  __SET_VAR(data__->ENCODER0.,IN0,,__GET_VAR(data__->R_TRIG25.Q,));
  __SET_VAR(data__->ENCODER0.,IN1,,__GET_VAR(data__->R_TRIG26.Q,));
  __SET_VAR(data__->ENCODER0.,IN2,,__GET_VAR(data__->R_TRIG27.Q,));
  __SET_VAR(data__->ENCODER0.,IN3,,__GET_VAR(data__->R_TRIG28.Q,));
  ENCODER_body__(&data__->ENCODER0);
  __SET_VAR(data__->EN_USINT_STATE0.,IN,,__GET_VAR(data__->ENCODER0.OUT,));
  __SET_VAR(data__->EN_USINT_STATE0.,DATA,,__GET_VAR(data__->ENCODER0.DATA,));
  EN_USINT_STATE_body__(&data__->EN_USINT_STATE0);
  __SET_VAR(data__->TON0.,IN,,(__GET_VAR(data__->READY,) && __GET_VAR(data__->EQ103_OUT,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->OUT_USINT_QUEUE0.,IN,,__GET_VAR(data__->TON0.Q,));
  OUT_USINT_QUEUE_body__(&data__->OUT_USINT_QUEUE0);

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





