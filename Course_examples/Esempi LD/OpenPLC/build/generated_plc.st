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
