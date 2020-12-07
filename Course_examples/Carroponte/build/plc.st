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


PROGRAM main_carroponte
  VAR
    ea : BOOL := 0;
    eb : BOOL := 0;
    ex : BOOL := 0;
    cs : BOOL := 0;
    cd : BOOL := 0;
    cy : BOOL := 0;
    cy0 : BOOL := 0;
    vai : BOOL := 0;
    DX : BOOL := 0;
    SX : BOOL := 0;
    DWN : BOOL := 0;
    UP : BOOL := 0;
    MAG : BOOL := 0;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := vai;
  END_TRANSITION

  STEP Step1:
    DWN(N);
  END_STEP

  TRANSITION FROM Step1 TO Step2
    := eb;
  END_TRANSITION

  STEP Step2:
    MAG(N);
  END_STEP

  TRANSITION FROM Step2 TO (Step3, Step4, Step6)
    := step2.T>=T#500ms;
  END_TRANSITION

  STEP Step3:
    MAG(N);
  END_STEP

  TRANSITION FROM (Step3, Step10) TO (Step11, Step13)
    := 1;
  END_TRANSITION

  STEP Step11:
    SX(N);
  END_STEP

  TRANSITION FROM Step11 TO Step12
    := cs;
  END_TRANSITION

  STEP Step12:
  END_STEP

  TRANSITION FROM (Step12, Step14) TO Step0
    := 1;
  END_TRANSITION

  STEP Step13:
    UP(N);
  END_STEP

  TRANSITION FROM Step13 TO Step14
    := ea;
  END_TRANSITION

  STEP Step14:
  END_STEP

  STEP Step4:
    DX(N);
  END_STEP

  TRANSITION FROM Step4 TO Step5
    := cy;
  END_TRANSITION

  STEP Step5:
  END_STEP

  TRANSITION FROM (Step5, Step7) TO Step8
    := 1;
  END_TRANSITION

  STEP Step8:
    DX(N);
  END_STEP

  TRANSITION FROM Step8 TO Step9
    := cd;
  END_TRANSITION

  STEP Step9:
    DWN(N);
  END_STEP

  TRANSITION FROM Step9 TO Step10
    := ex;
  END_TRANSITION

  STEP Step10:
  END_STEP

  STEP Step6:
    UP(N);
  END_STEP

  TRANSITION FROM Step6 TO Step7
    := ea;
  END_TRANSITION

  STEP Step7:
  END_STEP

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main_carroponte;
  END_RESOURCE
END_CONFIGURATION
