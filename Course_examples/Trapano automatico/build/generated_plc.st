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
