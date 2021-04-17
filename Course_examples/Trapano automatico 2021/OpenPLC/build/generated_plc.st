PROGRAM sim_trapano
  VAR
    ROT : BOOL;
    OIL : BOOL;
    UP : BOOL;
    DWN : BOOL;
    a : BOOL;
    m : BOOL;
    b : BOOL;
    x : BOOL;
    y : BOOL;
    p_alto : BOOL := 0;
    TON0 : TON;
    TON1 : TON;
    TON2 : TON;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
  END_VAR

  INITIAL_STEP alto:
    a(N);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON1(IN := DWN, PT := T#1s);
    TON0(IN := DWN, PT := T#1s);
    TON3(IN := UP & NOT(DWN), PT := T#1s);
    TON2(IN := UP & NOT(DWN), PT := T#1s);
    TON4(IN := UP & NOT(DWN), PT := T#1s);
    TON5(IN := UP & NOT(DWN), PT := T#1s);
  END_ACTION

  TRANSITION FROM alto TO tra_a_e_m
    := TON1.Q;
  END_TRANSITION

  STEP tra_a_e_m:
  END_STEP

  TRANSITION FROM tra_a_e_m TO pezzo_alto
    := DWN & y & p_alto;
  END_TRANSITION

  STEP pezzo_alto:
    x(N);
  END_STEP

  TRANSITION FROM pezzo_alto TO medio
    := DWN & pezzo_alto.t>T#1s;
  END_TRANSITION

  STEP medio:
    x(N);
    m(N);
  END_STEP

  TRANSITION FROM medio TO basso
    := TON0.Q;
  END_TRANSITION

  STEP basso:
    x(N);
    b(N);
  END_STEP

  TRANSITION FROM basso TO medio
    := TON3.Q;
  END_TRANSITION

  TRANSITION FROM medio TO alto
    := TON2.Q;
  END_TRANSITION

  TRANSITION FROM tra_a_e_m TO pezzo_basso
    := DWN & y & NOT(p_alto);
  END_TRANSITION

  STEP pezzo_basso:
    m(N);
  END_STEP

  TRANSITION FROM pezzo_basso TO medio
    := DWN & pezzo_basso.t>T#1s;
  END_TRANSITION

  TRANSITION FROM tra_a_e_m TO medio_senza_pezzo
    := DWN & NOT(y);
  END_TRANSITION

  STEP medio_senza_pezzo:
    m(N);
  END_STEP

  TRANSITION FROM medio_senza_pezzo TO basso_senza_pezzo
    := DWN & medio_senza_pezzo.t>T#1s;
  END_TRANSITION

  STEP basso_senza_pezzo:
    b(N);
  END_STEP

  TRANSITION FROM basso_senza_pezzo TO medio_senza_pezzo
    := TON4.Q;
  END_TRANSITION

  TRANSITION FROM medio_senza_pezzo TO alto
    := TON5.Q;
  END_TRANSITION

  TRANSITION FROM tra_a_e_m TO alto
    := UP & NOT(DWN);
  END_TRANSITION

  INITIAL_STEP fermo0:
  END_STEP

  TRANSITION FROM fermo0 TO ruota0
    := ROT;
  END_TRANSITION

  STEP ruota0:
  END_STEP

  TRANSITION FROM ruota0 TO fermo0
    := NOT(ROT);
  END_TRANSITION

  INITIAL_STEP pompa_ferma0:
  END_STEP

  TRANSITION FROM pompa_ferma0 TO pompa_accesa0
    := OIL;
  END_TRANSITION

  STEP pompa_accesa0:
  END_STEP

  TRANSITION FROM pompa_accesa0 TO pompa_ferma0
    := NOT(OIL);
  END_TRANSITION

END_PROGRAM

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
    PROGRAM instance1 WITH task0 : sim_trapano;
  END_RESOURCE
END_CONFIGURATION
