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


PROGRAM carrello
  VAR_INPUT
    start_button : BOOL;
  END_VAR
  VAR_EXTERNAL
    go_right : BOOL;
    go_left : BOOL;
    load : BOOL;
    fd : BOOL;
    fs : BOOL;
    fr : BOOL;
  END_VAR
  VAR
    R_TRIG1 : R_TRIG;
  END_VAR

  INITIAL_STEP quiete:
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    R_TRIG1(CLK := start_button);
  END_ACTION

  TRANSITION FROM quiete TO vai_a_dx
    := R_TRIG1.Q;
  END_TRANSITION

  STEP vai_a_dx:
    go_right(N);
  END_STEP

  TRANSITION FROM vai_a_dx TO carica
    := fd;
  END_TRANSITION

  STEP carica:
    load(N);
  END_STEP

  TRANSITION FROM carica TO Step0
    := fr;
  END_TRANSITION

  STEP Step0:
    go_left(N);
  END_STEP

  TRANSITION FROM Step0 TO quiete
    := fs;
  END_TRANSITION

END_PROGRAM

PROGRAM simulazione_carrello
  VAR
    dummy1 : BOOL := 0;
    dummy2 : BOOL := 0;
    dummy3 : BOOL := 0;
  END_VAR
  VAR_EXTERNAL
    go_right : BOOL;
    go_left : BOOL;
    load : BOOL;
    fd : BOOL;
    fs : BOOL;
    fr : BOOL;
  END_VAR

  INITIAL_STEP fermo_a_sx:
    fs(N);
  END_STEP

  TRANSITION FROM fermo_a_sx TO vai_a_dx
    := go_right;
  END_TRANSITION

  STEP vai_a_dx:
    dummy1(D, T#2s);
  END_STEP

  TRANSITION FROM vai_a_dx TO fermo_a_dx
    := dummy1;
  END_TRANSITION

  STEP fermo_a_dx:
    fd(N);
  END_STEP

  TRANSITION FROM fermo_a_dx TO vai_a_sx
    := go_left;
  END_TRANSITION

  STEP vai_a_sx:
    dummy1(D, T#2s);
  END_STEP

  TRANSITION FROM vai_a_sx TO fermo_a_sx
    := dummy1;
  END_TRANSITION

  INITIAL_STEP quiete:
  END_STEP

  TRANSITION FROM quiete TO svuota
    := load;
  END_TRANSITION

  STEP svuota:
    dummy2(D, T#1s);
  END_STEP

  TRANSITION FROM svuota TO vuoto
    := dummy2;
  END_TRANSITION

  STEP vuoto:
    fr(N);
    dummy3(D, T#500ms);
  END_STEP

  TRANSITION FROM vuoto TO quiete
    := dummy3;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      go_right : BOOL;
      go_left : BOOL;
      load : BOOL;
      fs : BOOL;
      fd : BOOL;
      fr : BOOL;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task1(INTERVAL := T#100ms,PRIORITY := 1);
    PROGRAM controllo WITH task0 : carrello;
    PROGRAM simulazione WITH task1 : simulazione_carrello;
  END_RESOURCE
END_CONFIGURATION
