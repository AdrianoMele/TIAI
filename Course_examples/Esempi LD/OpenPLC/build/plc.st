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


FUNCTION_BLOCK mySquare
  VAR_INPUT
    enable : BOOL;
  END_VAR
  VAR_OUTPUT
    square : BOOL;
  END_VAR
  VAR
    timeUp : TIME := T#1s;
    timeDwn : TIME := T#2s;
    TON0 : TON;
    TON1 : TON;
  END_VAR

  TON0(IN := NOT(TON1.Q) AND enable, PT := timeDwn);
  square := TON0.Q;
  TON1(IN := TON0.Q, PT := timeUp);
END_FUNCTION_BLOCK

FUNCTION myXOR : BOOL
  VAR_INPUT
    a : BOOL;
    b : BOOL;
  END_VAR

  myXOR := NOT(b) AND a OR NOT(a) AND b;
END_FUNCTION

PROGRAM main
  VAR
    a : BOOL;
    b : BOOL;
    square : BOOL := 0;
    resetCnt : BOOL := 0;
    CNT : INT := 0;
    mySquare0 : mySquare;
    CTU0 : CTU;
    myXOR2_OUT : BOOL;
    R_TRIG1 : R_TRIG;
  END_VAR

  myXOR2_OUT := myXOR(a, b);
  mySquare0(enable := myXOR2_OUT);
  square := mySquare0.square;
  R_TRIG1(CLK := mySquare0.square);
  CTU0(CU := R_TRIG1.Q, R := resetCnt, PV := 1000);
  CNT := CTU0.CV;
END_PROGRAM

PROGRAM myST_PRG
  VAR
    a : BOOL;
    b : BOOL;
    enbl : BOOL;
    out : BOOL;
    mySQ : mySquare;
  END_VAR

  (*Chiamata a funzione*)
  enbl := myXOR(a := a, 
                b := b);
                
  (*Chiamata a blocco funzionale*)
  mySQ(enable := enbl, 
       square => out);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK myTask(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM myMainPRGInstance WITH myTask : main;
    PROGRAM mySTPRGInstance WITH myTask : myST_PRG;
  END_RESOURCE
END_CONFIGURATION
