FUNCTION_BLOCK distributore
  VAR_INPUT
    attiva_SA : BOOL;
    eroga_prodotto : BOOL;
    ricarica_prodotto : BOOL;
    preleva : BOOL;
    svuota : BOOL;
  END_VAR
  VAR_OUTPUT
    prodotti_da_prelevare : INT := 0;
    prodotti_disp : BOOL;
  END_VAR
  VAR
    n_prodotti : INT := 10;
    prodotti_buffer : BOOL;
    eroga_trig : BOOL;
    buffer_trig : BOOL;
    RTRIG_eroga : R_TRIG;
    RTRIG_buffer : R_TRIG;
  END_VAR

  (* Verifica che sia presente almeno un prodotto *)
  prodotti_disp := GT(IN1 := n_prodotti,IN2 := 0);

  (* Riconoscimento fronte di salita per erogazione prodotto *)
  RTRIG_eroga(
       CLK := eroga_prodotto(*BOOL*),
       Q => eroga_trig(*BOOL*));
  RTRIG_buffer(
       CLK := attiva_SA(*BOOL*),
       Q => buffer_trig(*BOOL*));
           
  (* Sposta prodotto nel buffer se disponibile *)
  IF buffer_trig AND prodotti_disp THEN
    n_prodotti := n_prodotti - 1;
    prodotti_buffer := true;
  END_IF;

  (* Eroga un prodotto se presente nel buffer *)
  IF eroga_trig AND prodotti_buffer THEN
    prodotti_buffer := false;
    prodotti_da_prelevare := prodotti_da_prelevare + 1;
  END_IF;

  (* Ricarica il distributore *)
  IF ricarica_prodotto THEN
    n_prodotti := 10;
  END_IF;

  (* Preleva tutti i prodotti dal vano *)
  IF preleva THEN
    prodotti_da_prelevare := 0;
  END_IF;

  (* Sposta tutti i prodotti nel vano prelievo *)
  IF svuota THEN
    prodotti_da_prelevare := prodotti_da_prelevare + n_prodotti;
    n_prodotti := 0;
  END_IF;
END_FUNCTION_BLOCK

PROGRAM main
  VAR_EXTERNAL
    moneta : BOOL;
    SA : BOOL;
    SB : BOOL;
    aperto : BOOL;
    BLOCCA : BOOL;
    SBLOCCA : BOOL;
  END_VAR
  VAR
    R_TRIG1 : R_TRIG;
  END_VAR

  INITIAL_STEP f0:
    BLOCCA(N);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    R_TRIG1(CLK := moneta);
  END_ACTION

  TRANSITION FROM f0 TO (f11, f21)
    := R_TRIG1.Q;
  END_TRANSITION

  STEP f11:
    SBLOCCA(N);
  END_STEP

  TRANSITION FROM f11 TO f12
    := aperto;
  END_TRANSITION

  STEP f12:
  END_STEP

  TRANSITION FROM (f12, f23) TO f0
    := true;
  END_TRANSITION

  STEP f21:
    SB(L, T#1s);
  END_STEP

  TRANSITION FROM f21 TO f22
    := f21.t>=T#2s;
  END_TRANSITION

  STEP f22:
    SA(L, T#1s);
  END_STEP

  TRANSITION FROM f22 TO f23
    := f22.t>=T#2s;
  END_TRANSITION

  STEP f23:
  END_STEP

END_PROGRAM

FUNCTION_BLOCK pistone
  VAR_INPUT
    apri : BOOL;
  END_VAR
  VAR_OUTPUT
    aperto : BOOL := 0;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
  END_VAR

  TON0(IN := NOT(aperto) AND apri, PT := T#300ms);
  aperto := TON0.Q;
  TON1(IN := NOT(apri), PT := T#300ms);
  aperto := NOT(TON1.Q);
END_FUNCTION_BLOCK

PROGRAM simulator
  VAR_EXTERNAL
    moneta : BOOL;
    SB : BOOL;
    SA : BOOL;
    SBLOCCA : BOOL;
    BLOCCA : BOOL;
    aperto : BOOL;
  END_VAR
  VAR
    A_aperto : BOOL;
    B_aperto : BOOL;
    preleva_prodotto : BOOL;
    ricarica_prodotto : BOOL;
    credito_disponibile : BOOL;
    prodotti_nel_vano : INT;
    prodotti_disponibili : BOOL;
    distributore0 : distributore;
    pistone0 : pistone;
    pistone1 : pistone;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
  END_VAR

  aperto := NOT(BLOCCA);
  aperto := NOT(BLOCCA) AND SBLOCCA;
  R_TRIG1(CLK := ricarica_prodotto);
  R_TRIG2(CLK := preleva_prodotto);
  distributore0(attiva_SA := NOT(B_aperto) AND A_aperto, eroga_prodotto := credito_disponibile AND B_aperto AND NOT(A_aperto), ricarica_prodotto := R_TRIG1.Q, preleva := aperto AND R_TRIG2.Q, svuota := B_aperto AND A_aperto);
  prodotti_nel_vano := distributore0.prodotti_da_prelevare;
  prodotti_disponibili := distributore0.prodotti_disp;
  pistone0(apri := SA);
  A_aperto := pistone0.aperto;
  pistone1(apri := SB);
  B_aperto := pistone1.aperto;
  R_TRIG3(CLK := moneta);
  IF R_TRIG3.Q THEN
    credito_disponibile := TRUE; (*set*)
  END_IF;
  IF B_aperto THEN
    credito_disponibile := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      moneta : BOOL;
      aperto : BOOL;
      SA : BOOL;
      SB : BOOL;
      BLOCCA : BOOL;
      SBLOCCA : BOOL;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
    PROGRAM instance1 WITH task0 : simulator;
  END_RESOURCE
END_CONFIGURATION
