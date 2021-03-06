TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM main_trapano
  VAR
    p : BOOL := 0;
    a : BOOL := 0;
    m : BOOL := 0;
    b : BOOL := 0;
    x : BOOL := 0;
    y : BOOL := 0;
    UP : BOOL := 0;
    DWN : BOOL := 0;
    ROT : BOOL := 0;
    OIL : BOOL := 0;
  END_VAR

  INITIAL_STEP f1:
  END_STEP

  TRANSITION FROM f1 TO f2
    := y AND p;
  END_TRANSITION

  STEP f2:
    ROT(S);
    DWN(N);
  END_STEP

  TRANSITION FROM f2 TO f6
    := m AND NOT(x) AND TRUE;
  END_TRANSITION

  STEP f6:
    DWN(N);
  END_STEP

  TRANSITION FROM f6 TO f7
    := b;
  END_TRANSITION

  STEP f7:
    UP(N);
  END_STEP

  TRANSITION FROM f7 TO f8
    := a;
  END_TRANSITION

  STEP f8:
    ROT(R);
  END_STEP

  TRANSITION FROM f8 TO f1
    := NOT(y);
  END_TRANSITION

  TRANSITION FROM f2 TO f3
    := x;
  END_TRANSITION

  STEP f3:
    DWN(N);
  END_STEP

  TRANSITION FROM f3 TO f4
    := m AND TRUE;
  END_TRANSITION

  STEP f4:
    UP(N);
  END_STEP

  TRANSITION FROM f4 TO f5
    := a;
  END_TRANSITION

  STEP f5:
    OIL(N);
  END_STEP

  TRANSITION FROM f5 TO f6
    := f5.T>T#2s;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main_trapano;
  END_RESOURCE
END_CONFIGURATION
