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





void GENERA_init__(GENERA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->GENERATE,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_INT_10 temp = {{0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,VEICOLI,,temp);
  }
  __INIT_VAR(data__->CURRENT_ARRAY_POS,1,retain)
  __INIT_VAR(data__->WEIGHT,0,retain)
}

// Code part
void GENERA_body__(GENERA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,VEICOLI,.table[(1) - (1)],100);
  __SET_VAR(data__->,VEICOLI,.table[(2) - (1)],1454);
  __SET_VAR(data__->,VEICOLI,.table[(3) - (1)],807);
  __SET_VAR(data__->,VEICOLI,.table[(4) - (1)],252);
  __SET_VAR(data__->,VEICOLI,.table[(5) - (1)],1068);
  __SET_VAR(data__->,VEICOLI,.table[(6) - (1)],908);
  __SET_VAR(data__->,VEICOLI,.table[(7) - (1)],300);
  __SET_VAR(data__->,VEICOLI,.table[(8) - (1)],154);
  __SET_VAR(data__->,VEICOLI,.table[(9) - (1)],603);
  __SET_VAR(data__->,VEICOLI,.table[(10) - (1)],414);
  if ((__GET_VAR(data__->GENERATE,) == __BOOL_LITERAL(TRUE))) {
    __SET_VAR(data__->,WEIGHT,,__GET_VAR(data__->VEICOLI,.table[(__GET_VAR(data__->CURRENT_ARRAY_POS,)) - (1)]));
  };
  __SET_VAR(data__->,CURRENT_ARRAY_POS,,(__GET_VAR(data__->CURRENT_ARRAY_POS,) + 1));
  if ((__GET_VAR(data__->CURRENT_ARRAY_POS,) > 10)) {
    __SET_VAR(data__->,CURRENT_ARRAY_POS,,1);
  };

  goto __end;

__end:
  return;
} // GENERA_body__() 





static inline BOOL __VEHICLE_CNT_EQ__BOOL__REAL1(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VEHICLE_CNT *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ13_ENO,);
  __res = EQ__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ13_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __VEHICLE_CNT_EQ__BOOL__REAL2(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VEHICLE_CNT *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ26_ENO,);
  __res = EQ__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ26_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __VEHICLE_CNT_EQ__BOOL__REAL3(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VEHICLE_CNT *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ10_ENO,);
  __res = EQ__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ10_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __VEHICLE_CNT_EQ__BOOL__REAL4(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VEHICLE_CNT *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ23_ENO,);
  __res = EQ__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ23_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __VEHICLE_CNT_EQ__BOOL__REAL5(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VEHICLE_CNT *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ14_ENO,);
  __res = EQ__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ14_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __VEHICLE_CNT_EQ__BOOL__REAL6(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VEHICLE_CNT *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ27_ENO,);
  __res = EQ__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ27_ENO,,__TMP_ENO);
  return __res;
}

void VEHICLE_CNT_init__(VEHICLE_CNT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CONFIRM_ENTER,0,retain)
  __INIT_VAR(data__->CONFIRM_EXIT,0,retain)
  __INIT_VAR(data__->VEICOLO_IN,0,retain)
  __INIT_VAR(data__->VEICOLO_OUT,0,retain)
  __INIT_VAR(data__->TOT_AUTO,0,retain)
  __INIT_VAR(data__->TOT_MOTO,0,retain)
  __INIT_VAR(data__->TOT_CAMION,0,retain)
  __INIT_VAR(data__->CAP,4,retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  CTUD_init__(&data__->CTUD0,retain);
  CTUD_init__(&data__->CTUD1,retain);
  CTUD_init__(&data__->CTUD2,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->EQ13_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->EQ26_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ26_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->EQ10_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ10_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->EQ23_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ23_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG5,retain);
  __INIT_VAR(data__->EQ14_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ14_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG6,retain);
  __INIT_VAR(data__->EQ27_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ27_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG7,retain);
}

// Code part
void VEHICLE_CNT_body__(VEHICLE_CNT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->CONFIRM_ENTER,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,EQ13_OUT,,__VEHICLE_CNT_EQ__BOOL__REAL1(
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->VEICOLO_IN,),
    (REAL)1.0,
    data__));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->EQ13_OUT,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->CONFIRM_EXIT,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,EQ26_OUT,,__VEHICLE_CNT_EQ__BOOL__REAL2(
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->VEICOLO_OUT,),
    (REAL)1.0,
    data__));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->EQ26_OUT,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTUD0.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTUD0.,CD,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTUD0.,PV,,__GET_VAR(data__->CAP,));
  CTUD_body__(&data__->CTUD0);
  __SET_VAR(data__->,TOT_AUTO,,__GET_VAR(data__->CTUD0.CV,));
  __SET_VAR(data__->,EQ10_OUT,,__VEHICLE_CNT_EQ__BOOL__REAL3(
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->VEICOLO_IN,),
    (REAL)0.50,
    data__));
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->EQ10_OUT,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->,EQ23_OUT,,__VEHICLE_CNT_EQ__BOOL__REAL4(
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->VEICOLO_OUT,),
    (REAL)0.50,
    data__));
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_VAR(data__->EQ23_OUT,));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->CTUD1.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTUD1.,CD,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTUD1.,PV,,__GET_VAR(data__->CAP,));
  CTUD_body__(&data__->CTUD1);
  __SET_VAR(data__->,TOT_MOTO,,__GET_VAR(data__->CTUD1.CV,));
  __SET_VAR(data__->,EQ14_OUT,,__VEHICLE_CNT_EQ__BOOL__REAL5(
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->VEICOLO_IN,),
    (REAL)2.0,
    data__));
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_VAR(data__->EQ14_OUT,));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->,EQ27_OUT,,__VEHICLE_CNT_EQ__BOOL__REAL6(
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->VEICOLO_OUT,),
    (REAL)2.0,
    data__));
  __SET_VAR(data__->R_TRIG7.,CLK,,__GET_VAR(data__->EQ27_OUT,));
  R_TRIG_body__(&data__->R_TRIG7);
  __SET_VAR(data__->CTUD2.,CU,,__GET_VAR(data__->R_TRIG6.Q,));
  __SET_VAR(data__->CTUD2.,CD,,__GET_VAR(data__->R_TRIG7.Q,));
  __SET_VAR(data__->CTUD2.,PV,,__GET_VAR(data__->CAP,));
  CTUD_body__(&data__->CTUD2);
  __SET_VAR(data__->,TOT_CAMION,,__GET_VAR(data__->CTUD2.CV,));

  goto __end;

__end:
  return;
} // VEHICLE_CNT_body__() 





static inline BOOL __GETTONIERA_GE__BOOL__REAL1(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  GETTONIERA *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->GE14_ENO,);
  __res = GE__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->GE14_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __GETTONIERA_ADD__REAL__REAL2(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  REAL IN3,
  REAL IN4,
  GETTONIERA *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->ADD16_ENO,);
  __res = ADD__REAL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2,
    IN3,
    IN4);
  __SET_VAR(,data__->ADD16_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __GETTONIERA_SUB__REAL__REAL__REAL3(BOOL EN,
  REAL IN1,
  REAL IN2,
  GETTONIERA *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->SUB171_ENO,);
  __res = SUB__REAL__REAL__REAL(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->SUB171_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __GETTONIERA_MOVE__REAL__REAL4(BOOL EN,
  REAL IN,
  GETTONIERA *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE134_ENO,);
  __res = MOVE__REAL__REAL(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE134_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __GETTONIERA_MOVE__INT__INT5(BOOL EN,
  INT IN,
  GETTONIERA *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE165_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE165_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __GETTONIERA_BOOL_TO_INT6(BOOL EN,
  BOOL IN,
  GETTONIERA *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_INT161_ENO,);
  __res = BOOL_TO_INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_INT161_ENO,,__TMP_ENO);
  return __res;
}

void GETTONIERA_init__(GETTONIERA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENABLE,0,retain)
  __INIT_VAR(data__->EURO_1,0,retain)
  __INIT_VAR(data__->EURO_2,0,retain)
  __INIT_VAR(data__->EURO_50C,0,retain)
  __INIT_VAR(data__->ORE,0,retain)
  __INIT_VAR(data__->TARIFFA,1.0,retain)
  __INIT_VAR(data__->TOT,0.0,retain)
  __INIT_VAR(data__->PRC,1.0,retain)
  __INIT_VAR(data__->PREZZO,1.0,retain)
  __INIT_VAR(data__->TOT_MON,0.0,retain)
  __INIT_VAR(data__->HRS,0,retain)
  __INIT_VAR(data__->ORA,1,retain)
  __INIT_VAR(data__->APRI_SBARRA,0,retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->RESTO,0.0,retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  CTUD_init__(&data__->CTUD0,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  __INIT_VAR(data__->MUL182_OUT,0,retain)
  __INIT_VAR(data__->ADD185_OUT,0,retain)
  __INIT_VAR(data__->GE14_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GE14_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG6,retain);
  __INIT_VAR(data__->BOOL_TO_REAL108_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_REAL109_OUT,0,retain)
  __INIT_VAR(data__->MUL121_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_REAL150_OUT,0,retain)
  __INIT_VAR(data__->MUL151_OUT,0,retain)
  __INIT_VAR(data__->ADD16_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ADD16_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG7,retain);
  __INIT_VAR(data__->SUB171_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUB171_OUT,0,retain)
  __INIT_VAR(data__->MOVE134_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE134_OUT,0,retain)
  __INIT_VAR(data__->MOVE165_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE165_OUT,0,retain)
  __INIT_VAR(data__->LIMIT200_OUT,0,retain)
  __INIT_VAR(data__->INT_TO_REAL181_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_INT161_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_INT161_OUT,0,retain)
  __INIT_VAR(data__->ADD168_OUT,0,retain)
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

  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->ENABLE,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_VAR(data__->R_TRIG4.Q,));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->,MUL182_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->PRC,),
    (REAL)__GET_VAR(data__->TARIFFA,)));
  __SET_VAR(data__->,ADD185_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->MUL182_OUT,),
    (REAL)1.0));
  __SET_VAR(data__->,GE14_OUT,,__GETTONIERA_GE__BOOL__REAL1(
    (BOOL)__GET_VAR(data__->CTUD0.QU,),
    (UINT)2,
    (REAL)__GET_VAR(data__->TOT,),
    (REAL)__GET_VAR(data__->ADD185_OUT,),
    data__));
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_VAR(data__->GE14_OUT,));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->CTUD0.,CU,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTUD0.,CD,,__GET_VAR(data__->R_TRIG6.Q,));
  __SET_VAR(data__->CTUD0.,PV,,1);
  CTUD_body__(&data__->CTUD0);
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->EURO_1,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,BOOL_TO_REAL108_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->EURO_2,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,BOOL_TO_REAL109_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,)));
  __SET_VAR(data__->,MUL121_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL109_OUT,),
    (REAL)2.0));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->EURO_50C,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,BOOL_TO_REAL150_OUT,,BOOL_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG2.Q,)));
  __SET_VAR(data__->,MUL151_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL150_OUT,),
    (REAL)0.5));
  __SET_VAR(data__->,ADD16_OUT,,__GETTONIERA_ADD__REAL__REAL2(
    (BOOL)__GET_VAR(data__->CTUD0.QU,),
    (UINT)4,
    (REAL)__GET_VAR(data__->BOOL_TO_REAL108_OUT,),
    (REAL)__GET_VAR(data__->MUL121_OUT,),
    (REAL)__GET_VAR(data__->MUL151_OUT,),
    (REAL)__GET_VAR(data__->TOT,),
    data__));
  if (__GET_VAR(data__->ADD16_ENO,)) {
    __SET_VAR(data__->,TOT,,__GET_VAR(data__->ADD16_OUT,));
  };
  __SET_VAR(data__->R_TRIG7.,CLK,,__GET_VAR(data__->GE14_OUT,));
  R_TRIG_body__(&data__->R_TRIG7);
  __SET_VAR(data__->,APRI_SBARRA,,__GET_VAR(data__->R_TRIG7.Q,));
  if (__GET_VAR(data__->ADD16_ENO,)) {
    __SET_VAR(data__->,TOT_MON,,__GET_VAR(data__->ADD16_OUT,));
  };
  __SET_VAR(data__->,SUB171_OUT,,__GETTONIERA_SUB__REAL__REAL__REAL3(
    (BOOL)__GET_VAR(data__->GE14_OUT,),
    (REAL)__GET_VAR(data__->TOT,),
    (REAL)__GET_VAR(data__->PREZZO,),
    data__));
  __SET_VAR(data__->,MOVE134_OUT,,__GETTONIERA_MOVE__REAL__REAL4(
    (BOOL)__GET_VAR(data__->SUB171_ENO,),
    (REAL)0.0,
    data__));
  if (__GET_VAR(data__->MOVE134_ENO,)) {
    __SET_VAR(data__->,TOT,,__GET_VAR(data__->MOVE134_OUT,));
  };
  __SET_VAR(data__->,PREZZO,,__GET_VAR(data__->ADD185_OUT,));
  if (__GET_VAR(data__->MOVE134_ENO,)) {
    __SET_VAR(data__->,TOT_MON,,__GET_VAR(data__->MOVE134_OUT,));
  };
  __SET_VAR(data__->,MOVE165_OUT,,__GETTONIERA_MOVE__INT__INT5(
    (BOOL)__GET_VAR(data__->SUB171_ENO,),
    (INT)1,
    data__));
  if (__GET_VAR(data__->MOVE165_ENO,)) {
    __SET_VAR(data__->,ORA,,__GET_VAR(data__->MOVE165_OUT,));
  };
  __SET_VAR(data__->,LIMIT200_OUT,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)__GET_VAR(data__->ORA,),
    (INT)6));
  __SET_VAR(data__->,INT_TO_REAL181_OUT,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->LIMIT200_OUT,)));
  __SET_VAR(data__->,PRC,,__GET_VAR(data__->INT_TO_REAL181_OUT,));
  if (__GET_VAR(data__->SUB171_ENO,)) {
    __SET_VAR(data__->,RESTO,,__GET_VAR(data__->SUB171_OUT,));
  };
  __SET_VAR(data__->,HRS,,__GET_VAR(data__->LIMIT200_OUT,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->ORE,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->,BOOL_TO_INT161_OUT,,__GETTONIERA_BOOL_TO_INT6(
    (BOOL)__GET_VAR(data__->CTUD0.QU,),
    (BOOL)__GET_VAR(data__->R_TRIG3.Q,),
    data__));
  __SET_VAR(data__->,ADD168_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BOOL_TO_INT161_OUT,),
    (INT)__GET_VAR(data__->ORA,)));
  __SET_VAR(data__->,ORA,,__GET_VAR(data__->ADD168_OUT,));

  goto __end;

__end:
  return;
} // GETTONIERA_body__() 





static inline INT __VEHICLE_SEL_MOVE__INT__INT1(BOOL EN,
  INT IN,
  VEHICLE_SEL *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE63_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE63_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __VEHICLE_SEL_MOVE__INT__INT2(BOOL EN,
  INT IN,
  VEHICLE_SEL *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE64_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE64_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __VEHICLE_SEL_MOVE__INT__INT3(BOOL EN,
  INT IN,
  VEHICLE_SEL *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE66_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE66_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __VEHICLE_SEL_EQ__BOOL__INT4(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  VEHICLE_SEL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->EQ56_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->EQ56_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VEHICLE_SEL_MUX__REAL__INT__REAL5(BOOL EN,
  INT K,
  UINT __PARAM_COUNT,
  REAL IN0,
  REAL IN1,
  REAL IN2,
  VEHICLE_SEL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MUX1_ENO,);
  __res = MUX__REAL__INT__REAL(EN,
    &__TMP_ENO,
    K,
    __PARAM_COUNT,
    IN0,
    IN1,
    IN2);
  __SET_VAR(,data__->MUX1_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __VEHICLE_SEL_MOVE__INT__INT6(BOOL EN,
  INT IN,
  VEHICLE_SEL *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE27_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE27_ENO,,__TMP_ENO);
  return __res;
}

void VEHICLE_SEL_init__(VEHICLE_SEL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->INVIO,0,retain)
  __INIT_VAR(data__->SLCT,0,retain)
  __INIT_VAR(data__->WEIGHT,0,retain)
  __INIT_VAR(data__->ABILITA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->VEICLEDETECT,0,retain)
  __INIT_VAR(data__->VEICOLO,1.0,retain)
  __INIT_VAR(data__->TIPO,0,retain)
  __INIT_VAR(data__->AUTO,1.0,retain)
  __INIT_VAR(data__->MOTO,0.50,retain)
  __INIT_VAR(data__->CAMION,2.00,retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  __INIT_VAR(data__->GT59_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LE39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND61_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_INT49_OUT,0,retain)
  __INIT_VAR(data__->MOVE63_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE63_OUT,0,retain)
  __INIT_VAR(data__->GT42_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LE45_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND44_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_INT2_OUT,0,retain)
  __INIT_VAR(data__->MUL50_OUT,0,retain)
  __INIT_VAR(data__->MOVE64_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE64_OUT,0,retain)
  __INIT_VAR(data__->GT47_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_INT3_OUT,0,retain)
  __INIT_VAR(data__->MUL5_OUT,0,retain)
  __INIT_VAR(data__->MOVE66_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE66_OUT,0,retain)
  __INIT_VAR(data__->EQ56_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ56_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUX1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUX1_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_INT19_OUT,0,retain)
  __INIT_VAR(data__->ADD20_OUT,0,retain)
  __INIT_VAR(data__->MUX32_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->EQ25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE27_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE27_OUT,0,retain)
}

// Code part
void VEHICLE_SEL_body__(VEHICLE_SEL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,GT59_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->WEIGHT,),
    (INT)0));
  __SET_VAR(data__->,LE39_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->WEIGHT,),
    (INT)250));
  __SET_VAR(data__->,AND61_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->GT59_OUT,),
    (BOOL)__GET_VAR(data__->LE39_OUT,)));
  __SET_VAR(data__->,BOOL_TO_INT49_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->AND61_OUT,)));
  __SET_VAR(data__->,MOVE63_OUT,,__VEHICLE_SEL_MOVE__INT__INT1(
    (BOOL)__GET_VAR(data__->AND61_OUT,),
    (INT)__GET_VAR(data__->BOOL_TO_INT49_OUT,),
    data__));
  if (__GET_VAR(data__->MOVE63_ENO,)) {
    __SET_VAR(data__->,VEICLEDETECT,,__GET_VAR(data__->MOVE63_OUT,));
  };
  __SET_VAR(data__->,GT42_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->WEIGHT,),
    (INT)250));
  __SET_VAR(data__->,LE45_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->WEIGHT,),
    (INT)900));
  __SET_VAR(data__->,AND44_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->GT42_OUT,),
    (BOOL)__GET_VAR(data__->LE45_OUT,)));
  __SET_VAR(data__->,BOOL_TO_INT2_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->AND44_OUT,)));
  __SET_VAR(data__->,MUL50_OUT,,MUL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BOOL_TO_INT2_OUT,),
    (INT)0));
  __SET_VAR(data__->,MOVE64_OUT,,__VEHICLE_SEL_MOVE__INT__INT2(
    (BOOL)__GET_VAR(data__->AND44_OUT,),
    (INT)__GET_VAR(data__->MUL50_OUT,),
    data__));
  if (__GET_VAR(data__->MOVE64_ENO,)) {
    __SET_VAR(data__->,VEICLEDETECT,,__GET_VAR(data__->MOVE64_OUT,));
  };
  __SET_VAR(data__->,GT47_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->WEIGHT,),
    (INT)900));
  __SET_VAR(data__->,BOOL_TO_INT3_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->GT47_OUT,)));
  __SET_VAR(data__->,MUL5_OUT,,MUL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BOOL_TO_INT3_OUT,),
    (INT)2));
  __SET_VAR(data__->,MOVE66_OUT,,__VEHICLE_SEL_MOVE__INT__INT3(
    (BOOL)__GET_VAR(data__->GT47_OUT,),
    (INT)__GET_VAR(data__->MUL5_OUT,),
    data__));
  if (__GET_VAR(data__->MOVE66_ENO,)) {
    __SET_VAR(data__->,VEICLEDETECT,,__GET_VAR(data__->MOVE66_OUT,));
  };
  __SET_VAR(data__->,EQ56_OUT,,__VEHICLE_SEL_EQ__BOOL__INT4(
    (BOOL)__GET_VAR(data__->INVIO,),
    (UINT)2,
    (INT)__GET_VAR(data__->VEICLEDETECT,),
    (INT)__GET_VAR(data__->TIPO,),
    data__));
  __SET_VAR(data__->,MUX1_OUT,,__VEHICLE_SEL_MUX__REAL__INT__REAL5(
    (BOOL)__GET_VAR(data__->EQ56_OUT,),
    (INT)__GET_VAR(data__->TIPO,),
    (UINT)3,
    (REAL)__GET_VAR(data__->AUTO,),
    (REAL)__GET_VAR(data__->MOTO,),
    (REAL)__GET_VAR(data__->CAMION,),
    data__));
  __SET_VAR(data__->,ABILITA,,__GET_VAR(data__->MUX1_ENO,));
  if (__GET_VAR(data__->MUX1_ENO,)) {
    __SET_VAR(data__->,VEICOLO,,__GET_VAR(data__->MUX1_OUT,));
  };
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->SLCT,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,BOOL_TO_INT19_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,)));
  __SET_VAR(data__->,ADD20_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BOOL_TO_INT19_OUT,),
    (INT)__GET_VAR(data__->TIPO,)));
  __SET_VAR(data__->,TIPO,,__GET_VAR(data__->ADD20_OUT,));
  __SET_VAR(data__->,MUX32_OUT,,MUX__STRING__INT__STRING(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->TIPO,),
    (UINT)3,
    (STRING)__STRING_LITERAL(4,"auto"),
    (STRING)__STRING_LITERAL(4,"moto"),
    (STRING)__STRING_LITERAL(6,"camion")));
  __SET_VAR(data__->,CAT,,__GET_VAR(data__->MUX32_OUT,));
  __SET_VAR(data__->,EQ25_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TIPO,),
    (INT)3));
  __SET_VAR(data__->,MOVE27_OUT,,__VEHICLE_SEL_MOVE__INT__INT6(
    (BOOL)__GET_VAR(data__->EQ25_OUT,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->MOVE27_ENO,)) {
    __SET_VAR(data__->,TIPO,,__GET_VAR(data__->MOVE27_OUT,));
  };

  goto __end;

__end:
  return;
} // VEHICLE_SEL_body__() 





static inline REAL __EXIT_SEL_MUX__REAL__INT__REAL1(BOOL EN,
  INT K,
  UINT __PARAM_COUNT,
  REAL IN0,
  REAL IN1,
  REAL IN2,
  EXIT_SEL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MUX1_ENO,);
  __res = MUX__REAL__INT__REAL(EN,
    &__TMP_ENO,
    K,
    __PARAM_COUNT,
    IN0,
    IN1,
    IN2);
  __SET_VAR(,data__->MUX1_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __EXIT_SEL_MOVE__INT__INT2(BOOL EN,
  INT IN,
  EXIT_SEL *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE27_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE27_ENO,,__TMP_ENO);
  return __res;
}

void EXIT_SEL_init__(EXIT_SEL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CONFIRM,0,retain)
  __INIT_VAR(data__->SLCT,0,retain)
  __INIT_VAR(data__->VEICOLO,0,retain)
  __INIT_VAR(data__->AUTO,1.0,retain)
  __INIT_VAR(data__->MOTO,0.50,retain)
  __INIT_VAR(data__->CAMION,2.0,retain)
  __INIT_VAR(data__->OK_EXIT,0,retain)
  __INIT_VAR(data__->CAT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TIPO,0,retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  __INIT_VAR(data__->MUX1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUX1_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_INT19_OUT,0,retain)
  __INIT_VAR(data__->ADD20_OUT,0,retain)
  __INIT_VAR(data__->MUX32_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->EQ25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE27_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE27_OUT,0,retain)
}

// Code part
void EXIT_SEL_body__(EXIT_SEL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,MUX1_OUT,,__EXIT_SEL_MUX__REAL__INT__REAL1(
    (BOOL)__GET_VAR(data__->CONFIRM,),
    (INT)__GET_VAR(data__->TIPO,),
    (UINT)3,
    (REAL)__GET_VAR(data__->AUTO,),
    (REAL)__GET_VAR(data__->MOTO,),
    (REAL)__GET_VAR(data__->CAMION,),
    data__));
  if (__GET_VAR(data__->MUX1_ENO,)) {
    __SET_VAR(data__->,VEICOLO,,__GET_VAR(data__->MUX1_OUT,));
  };
  __SET_VAR(data__->,OK_EXIT,,__GET_VAR(data__->CONFIRM,));
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->SLCT,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,BOOL_TO_INT19_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,)));
  __SET_VAR(data__->,ADD20_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BOOL_TO_INT19_OUT,),
    (INT)__GET_VAR(data__->TIPO,)));
  __SET_VAR(data__->,TIPO,,__GET_VAR(data__->ADD20_OUT,));
  __SET_VAR(data__->,MUX32_OUT,,MUX__STRING__INT__STRING(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->TIPO,),
    (UINT)3,
    (STRING)__STRING_LITERAL(4,"auto"),
    (STRING)__STRING_LITERAL(4,"moto"),
    (STRING)__STRING_LITERAL(6,"camion")));
  __SET_VAR(data__->,CAT,,__GET_VAR(data__->MUX32_OUT,));
  __SET_VAR(data__->,EQ25_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TIPO,),
    (INT)3));
  __SET_VAR(data__->,MOVE27_OUT,,__EXIT_SEL_MOVE__INT__INT2(
    (BOOL)__GET_VAR(data__->EQ25_OUT,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->MOVE27_ENO,)) {
    __SET_VAR(data__->,TIPO,,__GET_VAR(data__->MOVE27_OUT,));
  };

  goto __end;

__end:
  return;
} // EXIT_SEL_body__() 





static inline REAL __PARK_STATS_ADD__REAL__REAL1(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  PARK_STATS *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->ADD16_ENO,);
  __res = ADD__REAL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->ADD16_ENO,,__TMP_ENO);
  return __res;
}

void PARK_STATS_init__(PARK_STATS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->EN_CALC,0,retain)
  __INIT_VAR(data__->GUAD,0,retain)
  __INIT_VAR(data__->TOT_AUTO1,0,retain)
  __INIT_VAR(data__->TOT_MOTO1,0,retain)
  __INIT_VAR(data__->TOT_CAMION1,0,retain)
  __INIT_VAR(data__->TOT_AUTO2,0,retain)
  __INIT_VAR(data__->TOT_MOTO2,0,retain)
  __INIT_VAR(data__->TOT_CAMION2,0,retain)
  __INIT_VAR(data__->TOT_AUTO,0,retain)
  __INIT_VAR(data__->TOT_MOTO,0,retain)
  __INIT_VAR(data__->TOT_CAMION,0,retain)
  __INIT_VAR(data__->INCASSO,0.0,retain)
  __INIT_VAR(data__->DAILY_VHCL,0,retain)
  R_TRIG_init__(&data__->R_TRIG0,retain);
  __INIT_VAR(data__->ADD16_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ADD16_OUT,0,retain)
  __INIT_VAR(data__->ADD1_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_INT22_OUT,0,retain)
  __INIT_VAR(data__->ADD20_OUT,0,retain)
  __INIT_VAR(data__->ADD2_OUT,0,retain)
  __INIT_VAR(data__->ADD3_OUT,0,retain)
}

// Code part
void PARK_STATS_body__(PARK_STATS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->EN_CALC,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,ADD16_OUT,,__PARK_STATS_ADD__REAL__REAL1(
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (UINT)2,
    (REAL)__GET_VAR(data__->GUAD,),
    (REAL)__GET_VAR(data__->INCASSO,),
    data__));
  if (__GET_VAR(data__->ADD16_ENO,)) {
    __SET_VAR(data__->,INCASSO,,__GET_VAR(data__->ADD16_OUT,));
  };
  __SET_VAR(data__->,ADD1_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TOT_AUTO1,),
    (INT)__GET_VAR(data__->TOT_AUTO2,)));
  __SET_VAR(data__->,TOT_AUTO,,__GET_VAR(data__->ADD1_OUT,));
  __SET_VAR(data__->,BOOL_TO_INT22_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,)));
  __SET_VAR(data__->,ADD20_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BOOL_TO_INT22_OUT,),
    (INT)__GET_VAR(data__->DAILY_VHCL,)));
  __SET_VAR(data__->,DAILY_VHCL,,__GET_VAR(data__->ADD20_OUT,));
  __SET_VAR(data__->,ADD2_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TOT_MOTO1,),
    (INT)__GET_VAR(data__->TOT_MOTO2,)));
  __SET_VAR(data__->,TOT_MOTO,,__GET_VAR(data__->ADD2_OUT,));
  __SET_VAR(data__->,ADD3_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TOT_CAMION1,),
    (INT)__GET_VAR(data__->TOT_CAMION2,)));
  __SET_VAR(data__->,TOT_CAMION,,__GET_VAR(data__->ADD3_OUT,));

  goto __end;

__end:
  return;
} // PARK_STATS_body__() 





void PARKING_init__(PARKING *data__, BOOL retain) {
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->GEN,0,retain)
  __INIT_VAR(data__->SLCT,0,retain)
  __INIT_VAR(data__->CONFERMA,0,retain)
  __INIT_VAR(data__->CENT_50,0,retain)
  __INIT_VAR(data__->EURO_1,0,retain)
  __INIT_VAR(data__->EURO_2,0,retain)
  __INIT_VAR(data__->ORA,0,retain)
  __INIT_VAR(data__->SLCT_EXIT1,0,retain)
  __INIT_VAR(data__->SLCT_EXIT2,0,retain)
  __INIT_VAR(data__->CONF1,0,retain)
  __INIT_VAR(data__->CONF2,0,retain)
  __INIT_VAR(data__->RESTO,0.0,retain)
  __INIT_VAR(data__->PREZZO,0.0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  __INIT_VAR(data__->CAP,4,retain)
  __INIT_VAR(data__->SBARRA1,0,retain)
  __INIT_VAR(data__->SBARRA2,0,retain)
  __INIT_VAR(data__->SBARRA1_MAN,0,retain)
  __INIT_VAR(data__->SBARRA1_EXIT,0,retain)
  __INIT_VAR(data__->SBARRA2_MAN,0,retain)
  __INIT_VAR(data__->SBARRA2_EXIT,0,retain)
  __INIT_VAR(data__->ENTER_1,0,retain)
  __INIT_VAR(data__->PIANO1_FULL,0,retain)
  __INIT_VAR(data__->PIANO2_FULL,0,retain)
  __INIT_VAR(data__->EXIT_1,0,retain)
  __INIT_VAR(data__->EXIT_2,0,retain)
  __INIT_VAR(data__->ENTER_2,0,retain)
  __INIT_VAR(data__->PARK_FULL,0,retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->TEMP1,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->TEMP2,__time_to_timespec(1, 0, 4, 0, 0, 0),retain)
  __INIT_VAR(data__->TEMP3,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  CTUD_init__(&data__->CTUD0,retain);
  __INIT_VAR(data__->EXIT1_EN,0,retain)
  __INIT_VAR(data__->EXIT2_EN,0,retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  CTUD_init__(&data__->CTUD1,retain);
  TON_init__(&data__->TON3,retain);
  TOF_init__(&data__->TOF1,retain);
  GETTONIERA_init__(&data__->GETTONIERA0,retain);
  VEHICLE_SEL_init__(&data__->VEHICLE_SEL0,retain);
  VEHICLE_CNT_init__(&data__->VEHICLE_CNT0,retain);
  EXIT_SEL_init__(&data__->EXIT_SEL0,retain);
  VEHICLE_CNT_init__(&data__->VEHICLE_CNT1,retain);
  EXIT_SEL_init__(&data__->EXIT_SEL1,retain);
  PARK_STATS_init__(&data__->PARK_STATS0,retain);
  GENERA_init__(&data__->GENERA0,retain);
  R_TRIG_init__(&data__->R_TRIG0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->AND127_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PARKING_body__(PARKING *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->GEN,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->GENERA0.,GENERATE,,__GET_VAR(data__->R_TRIG0.Q,));
  GENERA_body__(&data__->GENERA0);
  __SET_VAR(data__->VEHICLE_SEL0.,INVIO,,((__GET_VAR(data__->CONFERMA,) && !(__GET_VAR(data__->STOP,))) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->VEHICLE_SEL0.,SLCT,,((__GET_VAR(data__->SLCT,) && !(__GET_VAR(data__->STOP,))) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->VEHICLE_SEL0.,WEIGHT,,__GET_VAR(data__->GENERA0.WEIGHT,));
  VEHICLE_SEL_body__(&data__->VEHICLE_SEL0);
  __SET_VAR(data__->GETTONIERA0.,ENABLE,,__GET_VAR(data__->VEHICLE_SEL0.ABILITA,));
  __SET_VAR(data__->GETTONIERA0.,EURO_1,,((__GET_VAR(data__->EURO_1,) && !(__GET_VAR(data__->STOP,))) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,EURO_2,,((__GET_VAR(data__->EURO_2,) && !(__GET_VAR(data__->STOP,))) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,EURO_50C,,((__GET_VAR(data__->CENT_50,) && !(__GET_VAR(data__->STOP,))) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,ORE,,((__GET_VAR(data__->ORA,) && !(__GET_VAR(data__->STOP,))) && __GET_VAR(data__->START,)));
  __SET_VAR(data__->GETTONIERA0.,TARIFFA,,__GET_VAR(data__->VEHICLE_SEL0.VEICOLO,));
  GETTONIERA_body__(&data__->GETTONIERA0);
  if (((!(__GET_VAR(data__->PIANO1_FULL,)) && __GET_VAR(data__->GETTONIERA0.APRI_SBARRA,)) || __GET_VAR(data__->SBARRA1_MAN,))) {
    __SET_VAR(data__->,SBARRA1,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,PREZZO,,__GET_VAR(data__->GETTONIERA0.PREZZO,));
  if (((__GET_VAR(data__->PIANO1_FULL,) && __GET_VAR(data__->GETTONIERA0.APRI_SBARRA,)) || __GET_VAR(data__->SBARRA2_MAN,))) {
    __SET_VAR(data__->,SBARRA2,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,RESTO,,__GET_VAR(data__->GETTONIERA0.RESTO,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->SBARRA1,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->TEMP1,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,ENTER_1,,__GET_VAR(data__->TON0.Q,));
  if (__GET_VAR(data__->ENTER_1,)) {
    __SET_VAR(data__->,SBARRA1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EXIT1_EN,,__GET_VAR(data__->ENTER_1,));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->ENTER_1,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->EXIT_1,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTUD0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTUD0.,CD,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTUD0.,PV,,__GET_VAR(data__->CAP,));
  CTUD_body__(&data__->CTUD0);
  if (__GET_VAR(data__->CTUD0.QU,)) {
    __SET_VAR(data__->,SBARRA1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->CTUD0.QU,)) {
    __SET_VAR(data__->,PIANO1_FULL,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,EXIT1_EN,,!(__GET_VAR(data__->CTUD0.QD,)));
  __SET_VAR(data__->EXIT_SEL0.,CONFIRM,,(__GET_VAR(data__->CONF1,) && __GET_VAR(data__->EXIT1_EN,)));
  __SET_VAR(data__->EXIT_SEL0.,SLCT,,(__GET_VAR(data__->SLCT_EXIT1,) && __GET_VAR(data__->EXIT1_EN,)));
  EXIT_SEL_body__(&data__->EXIT_SEL0);
  __SET_VAR(data__->TON1.,IN,,(__GET_VAR(data__->SBARRA1_EXIT,) && __GET_VAR(data__->EXIT_SEL0.OK_EXIT,)));
  __SET_VAR(data__->TON1.,PT,,__GET_VAR(data__->TEMP1,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,EXIT_1,,__GET_VAR(data__->TON1.Q,));
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_VAR(data__->,PIANO1_FULL,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON2.,IN,,(__GET_VAR(data__->PIANO1_FULL,) && __GET_VAR(data__->SBARRA2,)));
  __SET_VAR(data__->TON2.,PT,,__GET_VAR(data__->TEMP2,));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,ENTER_2,,__GET_VAR(data__->TON2.Q,));
  if (__GET_VAR(data__->ENTER_2,)) {
    __SET_VAR(data__->,SBARRA2,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EXIT2_EN,,__GET_VAR(data__->ENTER_2,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->ENTER_2,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->EXIT_2,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->CTUD1.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTUD1.,CD,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTUD1.,PV,,__GET_VAR(data__->CAP,));
  CTUD_body__(&data__->CTUD1);
  if (__GET_VAR(data__->CTUD1.QU,)) {
    __SET_VAR(data__->,PIANO2_FULL,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,EXIT2_EN,,!(__GET_VAR(data__->CTUD1.QD,)));
  __SET_VAR(data__->EXIT_SEL1.,CONFIRM,,(__GET_VAR(data__->CONF2,) && __GET_VAR(data__->EXIT2_EN,)));
  __SET_VAR(data__->EXIT_SEL1.,SLCT,,(__GET_VAR(data__->SLCT_EXIT2,) && __GET_VAR(data__->EXIT2_EN,)));
  EXIT_SEL_body__(&data__->EXIT_SEL1);
  __SET_VAR(data__->TON3.,IN,,(__GET_VAR(data__->SBARRA2_EXIT,) && __GET_VAR(data__->EXIT_SEL1.OK_EXIT,)));
  __SET_VAR(data__->TON3.,PT,,__GET_VAR(data__->TEMP2,));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->,EXIT_2,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->TOF1.,PT,,__GET_VAR(data__->TEMP1,));
  TOF_body__(&data__->TOF1);
  if (__GET_VAR(data__->TOF1.Q,)) {
    __SET_VAR(data__->,PIANO2_FULL,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,AND127_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->PIANO1_FULL,),
    (BOOL)__GET_VAR(data__->PIANO2_FULL,)));
  __SET_VAR(data__->,STOP,,__GET_VAR(data__->AND127_OUT,));
  __SET_VAR(data__->VEHICLE_CNT0.,CONFIRM_ENTER,,__GET_VAR(data__->ENTER_1,));
  __SET_VAR(data__->VEHICLE_CNT0.,CONFIRM_EXIT,,__GET_VAR(data__->EXIT_1,));
  __SET_VAR(data__->VEHICLE_CNT0.,VEICOLO_IN,,__GET_VAR(data__->VEHICLE_SEL0.VEICOLO,));
  __SET_VAR(data__->VEHICLE_CNT0.,VEICOLO_OUT,,__GET_VAR(data__->EXIT_SEL0.VEICOLO,));
  VEHICLE_CNT_body__(&data__->VEHICLE_CNT0);
  __SET_VAR(data__->VEHICLE_CNT1.,CONFIRM_ENTER,,__GET_VAR(data__->ENTER_2,));
  __SET_VAR(data__->VEHICLE_CNT1.,CONFIRM_EXIT,,__GET_VAR(data__->EXIT_2,));
  __SET_VAR(data__->VEHICLE_CNT1.,VEICOLO_IN,,__GET_VAR(data__->VEHICLE_SEL0.VEICOLO,));
  __SET_VAR(data__->VEHICLE_CNT1.,VEICOLO_OUT,,__GET_VAR(data__->EXIT_SEL1.VEICOLO,));
  VEHICLE_CNT_body__(&data__->VEHICLE_CNT1);
  __SET_VAR(data__->PARK_STATS0.,EN_CALC,,__GET_VAR(data__->GETTONIERA0.APRI_SBARRA,));
  __SET_VAR(data__->PARK_STATS0.,GUAD,,__GET_VAR(data__->PREZZO,));
  __SET_VAR(data__->PARK_STATS0.,TOT_AUTO1,,__GET_VAR(data__->VEHICLE_CNT0.TOT_AUTO,));
  __SET_VAR(data__->PARK_STATS0.,TOT_MOTO1,,__GET_VAR(data__->VEHICLE_CNT0.TOT_MOTO,));
  __SET_VAR(data__->PARK_STATS0.,TOT_CAMION1,,__GET_VAR(data__->VEHICLE_CNT0.TOT_CAMION,));
  __SET_VAR(data__->PARK_STATS0.,TOT_AUTO2,,__GET_VAR(data__->VEHICLE_CNT1.TOT_AUTO,));
  __SET_VAR(data__->PARK_STATS0.,TOT_MOTO2,,__GET_VAR(data__->VEHICLE_CNT1.TOT_MOTO,));
  __SET_VAR(data__->PARK_STATS0.,TOT_CAMION2,,__GET_VAR(data__->VEHICLE_CNT1.TOT_CAMION,));
  PARK_STATS_body__(&data__->PARK_STATS0);

  goto __end;

__end:
  return;
} // PARKING_body__() 





