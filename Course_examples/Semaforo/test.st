PROGRAM main
  VAR
    f12X : BOOL := 0;
    f1X : BOOL := 0;
    f4X : BOOL := 0;
  END_VAR
  VAR
    c1 AT %QX1.0 : BOOL := 0;
    c2 AT %QX1.1 : BOOL := 0;
    ped AT %QX2.0 : BOOL := 1;
    V1 AT %QX0.0 : BOOL := 0;
    V2 AT %QX0.1 : BOOL := 0;
    G1 AT %QX0.2 : BOOL := 0;
    G2 AT %QX0.3 : BOOL := 0;
    R1 AT %QX0.4 : BOOL := 0;
    R2 AT %QX0.5 : BOOL := 0;
  END_VAR

  INITIAL_STEP f1:
    V1(N);
    R2(N);
    f1X(N);
  END_STEP

  TRANSITION FROM f1 TO f2
    := c1 AND NOT ped;
  END_TRANSITION

  STEP f2:
    V1(N);
    R2(N);
  END_STEP

  TRANSITION FROM f2 TO f4
    := f12X AND (c2 OR f2.T>=T#2s400ms);
  END_TRANSITION

  STEP f4:
    G1(N);
    R2(N);
    f4X(N);
  END_STEP

  TRANSITION FROM f4 TO f5
    := f4.T>=T#1s;
  END_TRANSITION

  STEP f5:
    R1(N);
    V2(N);
  END_STEP

  TRANSITION FROM f5 TO f6
    := f5.T>=T#1s;
  END_TRANSITION

  STEP f6:
    R1(N);
    G2(N);
  END_STEP

  TRANSITION FROM f6 TO f1
    := f6.T>=T#1s;
  END_TRANSITION

  TRANSITION FROM f2 TO f3
    := ped AND NOT(c2) AND f2.T<T#2s100ms;
  END_TRANSITION

  STEP f3:
    V1(N);
    R2(N);
  END_STEP

  TRANSITION FROM f3 TO f4
    := f12X AND (c2 OR f3.T>=T#300ms);
  END_TRANSITION

  TRANSITION FROM f1 TO f3
    := ped;
  END_TRANSITION

  INITIAL_STEP f10:
  END_STEP

  TRANSITION FROM f10 TO f11
    := f1X;
  END_TRANSITION

  STEP f11:
  END_STEP

  TRANSITION FROM f11 TO f12
    := f11.T>=T#3s;
  END_TRANSITION

  STEP f12:
    f12X(N);
  END_STEP

  TRANSITION FROM f12 TO f10
    := f4X;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
