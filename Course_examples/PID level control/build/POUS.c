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





void AUTOMODE_init__(AUTOMODE *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,AUTO,data__->AUTO,retain)
  __INIT_EXTERNAL(BOOL,STARTLIGHT,data__->STARTLIGHT,retain)
  __INIT_EXTERNAL(INT,SETPOINTVAL,data__->SETPOINTVAL,retain)
  __INIT_EXTERNAL(INT,LEVELVAL,data__->LEVELVAL,retain)
  __INIT_EXTERNAL(INT,FILLVALVE,data__->FILLVALVE,retain)
  __INIT_EXTERNAL(INT,DISCHARGEVALVE,data__->DISCHARGEVALVE,retain)
  __INIT_EXTERNAL(INT,KPVAL,data__->KPVAL,retain)
  __INIT_EXTERNAL(INT,KIVAL,data__->KIVAL,retain)
  __INIT_EXTERNAL(INT,KDVAL,data__->KDVAL,retain)
  __INIT_VAR(data__->KP_INTERNAL,0,retain)
  __INIT_VAR(data__->KI_INTERNAL,0,retain)
  __INIT_VAR(data__->KD_INTERNAL,0,retain)
  __INIT_VAR(data__->TI_INTERNAL,0,retain)
  __INIT_VAR(data__->TD_INTERNAL,0,retain)
  __INIT_VAR(data__->SETPOINT_INTERNAL,0,retain)
  __INIT_VAR(data__->LEVEL_INTERNAL,0,retain)
  __INIT_VAR(data__->CYCLE,__time_to_timespec(1, 20, 0, 0, 0, 0),retain)
  PID_init__(&data__->PID_LEVEL,retain);
  __INIT_VAR(data__->CONTROL,0,retain)
  __INIT_VAR(data__->KPMAX,100.0,retain)
  __INIT_VAR(data__->KIMAX,0.1,retain)
  __INIT_VAR(data__->KDMAX,10.0,retain)
}

// Code part
void AUTOMODE_body__(AUTOMODE *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,KP_INTERNAL,,((INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_EXTERNAL(data__->KPVAL,)) / 100.0) * __GET_VAR(data__->KPMAX,)));
  __SET_VAR(data__->,KI_INTERNAL,,((INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_EXTERNAL(data__->KIVAL,)) / 100.0) * __GET_VAR(data__->KIMAX,)));
  __SET_VAR(data__->,KD_INTERNAL,,((INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_EXTERNAL(data__->KDVAL,)) / 100.0) * __GET_VAR(data__->KDMAX,)));
  __SET_VAR(data__->,SETPOINT_INTERNAL,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_EXTERNAL(data__->SETPOINTVAL,)));
  __SET_VAR(data__->,LEVEL_INTERNAL,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_EXTERNAL(data__->LEVELVAL,)));
  if (GT__BOOL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->KI_INTERNAL,),
    (REAL)0.0)) {
    __SET_VAR(data__->,TI_INTERNAL,,(__GET_VAR(data__->KP_INTERNAL,) / __GET_VAR(data__->KI_INTERNAL,)));
  } else {
    __SET_VAR(data__->,TI_INTERNAL,,100000000000000000.0);
  };
  if (GT__BOOL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->KD_INTERNAL,),
    (REAL)0.0)) {
    __SET_VAR(data__->,TD_INTERNAL,,(__GET_VAR(data__->KD_INTERNAL,) / __GET_VAR(data__->KP_INTERNAL,)));
  } else {
    __SET_VAR(data__->,TD_INTERNAL,,0.0);
  };
  __SET_VAR(data__->PID_LEVEL.,AUTO,,__GET_EXTERNAL(data__->AUTO,));
  __SET_VAR(data__->PID_LEVEL.,PV,,__GET_VAR(data__->LEVEL_INTERNAL,));
  __SET_VAR(data__->PID_LEVEL.,SP,,__GET_VAR(data__->SETPOINT_INTERNAL,));
  __SET_VAR(data__->PID_LEVEL.,X0,,0.0);
  __SET_VAR(data__->PID_LEVEL.,KP,,__GET_VAR(data__->KP_INTERNAL,));
  __SET_VAR(data__->PID_LEVEL.,TR,,__GET_VAR(data__->TI_INTERNAL,));
  __SET_VAR(data__->PID_LEVEL.,TD,,__GET_VAR(data__->TD_INTERNAL,));
  __SET_VAR(data__->PID_LEVEL.,CYCLE,,__GET_VAR(data__->CYCLE,));
  PID_body__(&data__->PID_LEVEL);
  __SET_VAR(data__->,CONTROL,,__GET_VAR(data__->PID_LEVEL.XOUT));
  __SET_VAR(data__->,CONTROL,, -(__GET_VAR(data__->CONTROL,)));
  if ((__GET_EXTERNAL(data__->AUTO,) && __GET_EXTERNAL(data__->STARTLIGHT,))) {
    if (GT__BOOL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)__GET_VAR(data__->CONTROL,),
      (REAL)0.0)) {
      __SET_EXTERNAL(data__->,FILLVALVE,,REAL_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)__GET_VAR(data__->CONTROL,)));
      __SET_EXTERNAL(data__->,DISCHARGEVALVE,,0);
    } else {
      __SET_EXTERNAL(data__->,FILLVALVE,,0);
      __SET_EXTERNAL(data__->,DISCHARGEVALVE,,REAL_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL) -(__GET_VAR(data__->CONTROL,))));
    };
  };

  goto __end;

__end:
  return;
} // AUTOMODE_body__() 





void MANAGEDISPLAYS_init__(MANAGEDISPLAYS *data__, BOOL retain) {
  __INIT_EXTERNAL(INT,LEVELMETER,data__->LEVELMETER,retain)
  __INIT_EXTERNAL(INT,FLOWMETER,data__->FLOWMETER,retain)
  __INIT_EXTERNAL(INT,SETPOINT,data__->SETPOINT,retain)
  __INIT_EXTERNAL(INT,KP,data__->KP,retain)
  __INIT_EXTERNAL(INT,KI,data__->KI,retain)
  __INIT_EXTERNAL(INT,KD,data__->KD,retain)
  __INIT_EXTERNAL(INT,DISCHARGEVALVE,data__->DISCHARGEVALVE,retain)
  __INIT_EXTERNAL(INT,DISCHARGEVALVEPOS,data__->DISCHARGEVALVEPOS,retain)
  __INIT_EXTERNAL(INT,FILLVALVE,data__->FILLVALVE,retain)
  __INIT_EXTERNAL(INT,FILLVALVEPOS,data__->FILLVALVEPOS,retain)
  __INIT_EXTERNAL(INT,KPVAL,data__->KPVAL,retain)
  __INIT_EXTERNAL(INT,KIVAL,data__->KIVAL,retain)
  __INIT_EXTERNAL(INT,KDVAL,data__->KDVAL,retain)
  __INIT_EXTERNAL(INT,SETPOINTVAL,data__->SETPOINTVAL,retain)
  __INIT_EXTERNAL(INT,ERRORVAL,data__->ERRORVAL,retain)
  __INIT_EXTERNAL(INT,LEVELVAL,data__->LEVELVAL,retain)
  __INIT_VAR(data__->LEVELCONVFACTOR,3.34,retain)
  __INIT_VAR(data__->SETPOINTCONVFACTOR,3.34,retain)
  __INIT_VAR(data__->KPCONVFACTOR,10,retain)
  __INIT_VAR(data__->KICONVFACTOR,10,retain)
  __INIT_VAR(data__->KDCONVFACTOR,10,retain)
}

// Code part
void MANAGEDISPLAYS_body__(MANAGEDISPLAYS *data__) {
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,DISCHARGEVALVEPOS,,__GET_EXTERNAL(data__->DISCHARGEVALVE,));
  __SET_EXTERNAL(data__->,FILLVALVEPOS,,__GET_EXTERNAL(data__->FILLVALVE,));
  __SET_EXTERNAL(data__->,KPVAL,,(__GET_EXTERNAL(data__->KP,) / __GET_VAR(data__->KPCONVFACTOR,)));
  __SET_EXTERNAL(data__->,KIVAL,,(__GET_EXTERNAL(data__->KI,) / __GET_VAR(data__->KICONVFACTOR,)));
  __SET_EXTERNAL(data__->,KDVAL,,(__GET_EXTERNAL(data__->KD,) / __GET_VAR(data__->KDCONVFACTOR,)));
  __SET_EXTERNAL(data__->,SETPOINTVAL,,REAL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)DIV__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)INT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_EXTERNAL(data__->SETPOINT,)),
      (REAL)__GET_VAR(data__->SETPOINTCONVFACTOR,))));
  __SET_EXTERNAL(data__->,LEVELVAL,,REAL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)DIV__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)INT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_EXTERNAL(data__->LEVELMETER,)),
      (REAL)__GET_VAR(data__->LEVELCONVFACTOR,))));
  __SET_EXTERNAL(data__->,ERRORVAL,,(__GET_EXTERNAL(data__->SETPOINTVAL,) - __GET_EXTERNAL(data__->LEVELVAL,)));

  goto __end;

__end:
  return;
} // MANAGEDISPLAYS_body__() 





void MANUALMODE_init__(MANUALMODE *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,MANUAL,data__->MANUAL,retain)
  __INIT_EXTERNAL(BOOL,STARTLIGHT,data__->STARTLIGHT,retain)
  __INIT_EXTERNAL(BOOL,STOPLIGHT,data__->STOPLIGHT,retain)
  __INIT_EXTERNAL(BOOL,FILLMANUALLIGHT,data__->FILLMANUALLIGHT,retain)
  __INIT_EXTERNAL(BOOL,DISCHARGEMANUALLIGHT,data__->DISCHARGEMANUALLIGHT,retain)
  __INIT_EXTERNAL(INT,FILLVALVE,data__->FILLVALVE,retain)
  __INIT_EXTERNAL(INT,DISCHARGEVALVE,data__->DISCHARGEVALVE,retain)
}

// Code part
void MANUALMODE_body__(MANUALMODE *data__) {
  // Initialise TEMP variables

  if ((__GET_EXTERNAL(data__->MANUAL,) && __GET_EXTERNAL(data__->STARTLIGHT,))) {
    if (__GET_EXTERNAL(data__->FILLMANUALLIGHT,)) {
      __SET_EXTERNAL(data__->,FILLVALVE,,(10 * 100));
    } else {
      __SET_EXTERNAL(data__->,FILLVALVE,,0);
    };
    if (__GET_EXTERNAL(data__->DISCHARGEMANUALLIGHT,)) {
      __SET_EXTERNAL(data__->,DISCHARGEVALVE,,(10 * 100));
    } else {
      __SET_EXTERNAL(data__->,DISCHARGEVALVE,,0);
    };
  } else if ((__GET_EXTERNAL(data__->MANUAL,) && __GET_EXTERNAL(data__->STOPLIGHT,))) {
    __SET_EXTERNAL(data__->,FILLVALVE,,0);
    __SET_EXTERNAL(data__->,DISCHARGEVALVE,,0);
  };

  goto __end;

__end:
  return;
} // MANUALMODE_body__() 





void MANAGELIGHTS_init__(MANAGELIGHTS *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,STARTBUTTON,data__->STARTBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STOPBUTTON,data__->STOPBUTTON,retain)
  __INIT_EXTERNAL(BOOL,STARTLIGHT,data__->STARTLIGHT,retain)
  __INIT_EXTERNAL(BOOL,STOPLIGHT,data__->STOPLIGHT,retain)
  __INIT_EXTERNAL(BOOL,FILLVALVEMAN,data__->FILLVALVEMAN,retain)
  __INIT_EXTERNAL(BOOL,DISCHARGEVALVEMAN,data__->DISCHARGEVALVEMAN,retain)
  __INIT_EXTERNAL(BOOL,FILLMANUALLIGHT,data__->FILLMANUALLIGHT,retain)
  __INIT_EXTERNAL(BOOL,DISCHARGEMANUALLIGHT,data__->DISCHARGEMANUALLIGHT,retain)
  __INIT_EXTERNAL(BOOL,MANUAL,data__->MANUAL,retain)
  __INIT_VAR(data__->AUX1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUX2,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG6,retain);
  R_TRIG_init__(&data__->R_TRIG7,retain);
  R_TRIG_init__(&data__->R_TRIG8,retain);
}

// Code part
void MANAGELIGHTS_body__(MANAGELIGHTS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_EXTERNAL(data__->STARTBUTTON,));
  R_TRIG_body__(&data__->R_TRIG1);
  if (__GET_VAR(data__->R_TRIG1.Q,)) {
    __SET_EXTERNAL(data__->,STARTLIGHT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_EXTERNAL(data__->FILLVALVEMAN,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,AUX1,,((__GET_EXTERNAL(data__->FILLMANUALLIGHT,) && __GET_VAR(data__->R_TRIG2.Q,)) && __GET_EXTERNAL(data__->MANUAL,)));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_EXTERNAL(data__->STARTBUTTON,));
  R_TRIG_body__(&data__->R_TRIG3);
  if (__GET_VAR(data__->R_TRIG3.Q,)) {
    __SET_EXTERNAL(data__->,STOPLIGHT,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_EXTERNAL(data__->FILLVALVEMAN,));
  R_TRIG_body__(&data__->R_TRIG4);
  if (((__GET_EXTERNAL(data__->FILLMANUALLIGHT,) && __GET_VAR(data__->R_TRIG4.Q,)) && __GET_EXTERNAL(data__->MANUAL,))) {
    __SET_EXTERNAL(data__->,FILLMANUALLIGHT,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_EXTERNAL(data__->STOPBUTTON,));
  F_TRIG_body__(&data__->F_TRIG1);
  if (__GET_VAR(data__->F_TRIG1.Q,)) {
    __SET_EXTERNAL(data__->,STOPLIGHT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_EXTERNAL(data__->FILLVALVEMAN,));
  R_TRIG_body__(&data__->R_TRIG5);
  if ((((!(__GET_VAR(data__->AUX1,)) && !(__GET_EXTERNAL(data__->FILLMANUALLIGHT,))) && __GET_VAR(data__->R_TRIG5.Q,)) && __GET_EXTERNAL(data__->MANUAL,))) {
    __SET_EXTERNAL(data__->,FILLMANUALLIGHT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_EXTERNAL(data__->STOPBUTTON,));
  F_TRIG_body__(&data__->F_TRIG2);
  if (__GET_VAR(data__->F_TRIG2.Q,)) {
    __SET_EXTERNAL(data__->,STARTLIGHT,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_EXTERNAL(data__->DISCHARGEVALVEMAN,));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->,AUX2,,((__GET_EXTERNAL(data__->DISCHARGEMANUALLIGHT,) && __GET_VAR(data__->R_TRIG6.Q,)) && __GET_EXTERNAL(data__->MANUAL,)));
  __SET_VAR(data__->R_TRIG7.,CLK,,__GET_EXTERNAL(data__->DISCHARGEVALVEMAN,));
  R_TRIG_body__(&data__->R_TRIG7);
  if (((__GET_EXTERNAL(data__->DISCHARGEMANUALLIGHT,) && __GET_VAR(data__->R_TRIG7.Q,)) && __GET_EXTERNAL(data__->MANUAL,))) {
    __SET_EXTERNAL(data__->,DISCHARGEMANUALLIGHT,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG8.,CLK,,__GET_EXTERNAL(data__->DISCHARGEVALVEMAN,));
  R_TRIG_body__(&data__->R_TRIG8);
  if ((((!(__GET_VAR(data__->AUX2,)) && !(__GET_EXTERNAL(data__->DISCHARGEMANUALLIGHT,))) && __GET_VAR(data__->R_TRIG8.Q,)) && __GET_EXTERNAL(data__->MANUAL,))) {
    __SET_EXTERNAL(data__->,DISCHARGEMANUALLIGHT,,__BOOL_LITERAL(TRUE));
  };
  if (!(__GET_EXTERNAL(data__->MANUAL,))) {
    __SET_EXTERNAL(data__->,DISCHARGEMANUALLIGHT,,__BOOL_LITERAL(FALSE));
  };
  if (!(__GET_EXTERNAL(data__->MANUAL,))) {
    __SET_EXTERNAL(data__->,FILLMANUALLIGHT,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // MANAGELIGHTS_body__() 





