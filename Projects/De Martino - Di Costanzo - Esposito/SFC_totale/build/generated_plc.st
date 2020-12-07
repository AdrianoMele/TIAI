PROGRAM program0
  VAR
    temp_sens AT %IW0 : INT := 0;
    temp_rif AT %QW0 : INT := 10;
    atterraggio AT %QX0.0 : BOOL := 0;
    start AT %QX0.1 : BOOL := 0;
    temp_ok AT %QX3.0 : BOOL := 0;
  END_VAR
  VAR
    giorni : INT := 0;
    Na : BOOL := 0;
    Ar : BOOL := 0;
    O : BOOL := 0;
  END_VAR
  VAR
    Na_ok AT %QX0.2 : BOOL := 0;
    Ar_ok AT %QX0.3 : BOOL := 0;
    O_ok AT %QX0.4 : BOOL := 0;
    umidita_ok AT %QX0.5 : BOOL := 0;
    irrigazione_ok_A AT %QX0.6 : BOOL := 0;
    irrigazione_ok_E AT %QX0.7 : BOOL := 0;
    semina_des AT %QX1.0 : BOOL := 0;
    semina_sin AT %QX1.1 : BOOL := 0;
    sens_luce_buio AT %QX1.2 : BOOL := 0;
    irrigatore_acqua_A AT %QX4.3 : BOOL := 0;
    irrigatore_acqua_E AT %QX4.4 : BOOL := 0;
    start2 AT %QX3.1 : BOOL := 0;
  END_VAR
  VAR
    T_18 : INT := 17;
    T_24 : INT := 23;
  END_VAR
  VAR
    not_luce AT %QX1.3 : BOOL := 0;
    luci_em AT %QX1.4 : BOOL := 0;
    em_rover AT %QX1.5 : BOOL := 0;
    fine_em_luce AT %QX1.6 : BOOL := 0;
    estrazione_ok AT %QX1.7 : BOOL := 0;
    A_Motore_avanti AT %QX3.6 : BOOL := 0;
  END_VAR
  VAR
    A_Motore_indietro : BOOL := 0;
  END_VAR
  VAR
    A_apri_spazzola AT %QX4.0 : BOOL := 0;
  END_VAR
  VAR
    A_chiudi_spazzola : BOOL := 0;
  END_VAR
  VAR
    A_dock_ricarica AT %QX2.0 : BOOL := 1;
    secco1 AT %QX2.1 : BOOL := 0;
    secco2 AT %QX2.2 : BOOL := 0;
    A_aziona_spazzola AT %QX2.7 : BOOL := 0;
    sensore_P AT %QX3.7 : BOOL := 0;
    espulsione_ok AT %QX2.3 : BOOL := 0;
    sporco AT %QX2.4 : BOOL := 0;
    estrazione_ossigeno AT %QX2.5 : BOOL := 0;
    espulsione_ossigeno AT %QX2.6 : BOOL := 0;
    ventilatore_A AT %QX3.4 : BOOL := 0;
    ventilatore_B AT %QX3.5 : BOOL := 0;
    giorno AT %QX4.1 : BOOL := 0;
    notte AT %QX4.2 : BOOL := 0;
  END_VAR
  VAR
    durata_notte : BOOL := 0;
    durata_giorno : BOOL := 0;
    temp1 : BOOL := 0;
    umidificatore_acqua : BOOL := 0;
  END_VAR
  VAR
    apertura AT %QX4.5 : BOOL := 0;
    aperto AT %QX4.6 : BOOL := 0;
  END_VAR
  VAR
    R_TRIG1 : R_TRIG;
  END_VAR

  INITIAL_STEP S0:
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    R_TRIG1(CLK := em_rover);
  END_ACTION

  TRANSITION FROM S0 TO F0
    := start AND atterraggio;
  END_TRANSITION

  STEP F0:
    apertura(N);
    aperto(SD, T#5s);
  END_STEP

  TRANSITION FROM F0 TO S7
    := aperto;
  END_TRANSITION

  STEP S7:
    t_ok10(SD, T#5s);
  END_STEP

  ACTION t_ok10:
    temp_ok := GE (temp_sens, 10);
  END_ACTION

  TRANSITION FROM S7 TO (S01, S02, S03)
    := temp_ok;
  END_TRANSITION

  STEP S01:
    Na(L, T#70s);
    Ar(L, T#2s);
    O(L, T#20s);
    Na_ok(SD, T#20s);
    Ar_ok(SD, T#2s);
    O_ok(SD, T#22s);
  END_STEP

  TRANSITION FROM S01 TO S04
    := Na_ok AND Ar_ok AND O_ok;
  END_TRANSITION

  STEP S04:
  END_STEP

  TRANSITION FROM (S04, S05, S06) TO S08
    := 1;
  END_TRANSITION

  STEP S08:
    temp_ok_0(S);
    irrigazione_ok_A(R);
    irrigazione_ok_E(R);
  END_STEP

  ACTION temp_ok_0:
    temp_ok:=0;
  END_ACTION

  TRANSITION FROM S08 TO Semina
    := NOT(temp_ok);
  END_TRANSITION

  STEP Semina:
    semina_des(SD, T#11s);
    semina_sin(SD, T#9s);
  END_STEP

  TRANSITION FROM Semina TO S09
    := semina_des AND semina_sin;
  END_TRANSITION

  STEP S09:
    start2(S);
  END_STEP

  STEP S02:
    umidificatore_acqua(N);
    umidita_ok(SD, T#25s);
  END_STEP

  TRANSITION FROM S02 TO S05
    := umidita_ok;
  END_TRANSITION

  STEP S05:
  END_STEP

  STEP S03:
    irrigatore_acqua_A(N);
    irrigatore_acqua_E(N);
    irrigazione_ok_A(SD, T#15s);
    irrigazione_ok_E(SD, T#17s);
  END_STEP

  TRANSITION FROM S03 TO S06
    := irrigazione_ok_A AND irrigazione_ok_E;
  END_TRANSITION

  STEP S06:
  END_STEP

  INITIAL_STEP Manutenzione_cupola:
  END_STEP

  TRANSITION FROM Manutenzione_cupola TO R0
    := semina_sin AND semina_des AND R_TRIG1.Q;
  END_TRANSITION

  STEP R0:
    A_Motore_avanti(N);
    sensore_P(SD, T#6s);
    A_dock_ricarica(R);
  END_STEP

  TRANSITION FROM R0 TO R1
    := sensore_P;
  END_TRANSITION

  STEP R1:
    A_apri_spazzola(S);
    A_aziona_spazzola(D, T#3s);
    temp1(D, T#12s);
  END_STEP

  TRANSITION FROM R1 TO R2
    := temp1;
  END_TRANSITION

  STEP R2:
    A_apri_spazzola(R);
    sporco(R);
  END_STEP

  TRANSITION FROM R2 TO R3
    := 1;
  END_TRANSITION

  STEP R3:
    A_Motore_indietro(N);
    sensore_P(R);
    A_chiudi_spazzola(N);
    A_dock_ricarica(SD, T#10s);
  END_STEP

  TRANSITION FROM R3 TO Step3
    := A_dock_ricarica;
  END_TRANSITION

  STEP Step3:
    em_rover(R);
  END_STEP

  TRANSITION FROM Step3 TO Manutenzione_cupola
    := 1;
  END_TRANSITION

  INITIAL_STEP s00:
  END_STEP

  TRANSITION FROM s00 TO NOTTE0
    := start2;
  END_TRANSITION

  STEP NOTTE0:
    notte(S);
    durata_notte(SD, T#90s);
    giorno(R);
    durata_giorno(R);
  END_STEP

  TRANSITION FROM NOTTE0 TO GIORNO0
    := durata_notte;
  END_TRANSITION

  STEP GIORNO0:
    giorno(S);
    durata_giorno(SD, T#90s);
    notte(R);
    durata_notte(R);
  END_STEP

  TRANSITION FROM GIORNO0 TO NOTTE0
    := durata_giorno;
  END_TRANSITION

  INITIAL_STEP quiete_luce_buio0:
  END_STEP

  TRANSITION FROM quiete_luce_buio0 TO Q1
    := start2;
  END_TRANSITION

  STEP Q1:
  END_STEP

  TRANSITION FROM Q1 TO Buio0
    := notte;
  END_TRANSITION

  STEP Buio0:
    ventilatore_A(S);
    ventilatore_B(R);
    t_rif_18(P);
  END_STEP

  ACTION t_rif_18:
    temp_rif := 18;
  END_ACTION

  TRANSITION FROM Buio0 TO quiete_luce_buio0
    := NOT(notte);
  END_TRANSITION

  TRANSITION FROM Q1 TO Luce0
    := giorno;
  END_TRANSITION

  STEP Luce0:
    ventilatore_B(S);
    not_luce(R);
    t_rif_24(P);
  END_STEP

  ACTION t_rif_24:
    temp_rif := 24;
  END_ACTION

  TRANSITION FROM Luce0 TO Prelievo0
    := 1;
  END_TRANSITION

  STEP Prelievo0:
    estrazione_ossigeno(S);
    estrazione_ok(SD, T#10s);
  END_STEP

  TRANSITION FROM Prelievo0 TO Espulsione0
    := estrazione_ok;
  END_TRANSITION

  STEP Espulsione0:
    espulsione_ossigeno(S);
    estrazione_ossigeno(R);
    espulsione_ok(SD, T#10s);
  END_STEP

  TRANSITION FROM Espulsione0 TO G1
    := espulsione_ok;
  END_TRANSITION

  STEP G1:
    estrazione_ok(R);
    espulsione_ossigeno(R);
    estrazione_ossigeno(R);
    espulsione_ok(R);
  END_STEP

  TRANSITION FROM G1 TO quiete_luce_buio0
    := 1;
  END_TRANSITION

  TRANSITION FROM Q1 TO Step0
    := giorno AND not_luce;
  END_TRANSITION

  STEP Step0:
    sporco(S);
    luci_em(S);
    em_rover(S);
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := NOT(giorno);
  END_TRANSITION

  STEP Step1:
    luci_em(R);
  END_STEP

  TRANSITION FROM Step1 TO quiete_luce_buio0
    := 1;
  END_TRANSITION

  TRANSITION FROM Step0 TO Step4
    := giorno AND NOT(sporco) ;
  END_TRANSITION

  STEP Step4:
    not_luce(R);
    luci_em(R);
  END_STEP

  TRANSITION FROM Step4 TO quiete_luce_buio0
    := 1;
  END_TRANSITION

  INITIAL_STEP irrigazione_aloe0:
  END_STEP

  TRANSITION FROM irrigazione_aloe0 TO I2
    := start2;
  END_TRANSITION

  STEP I2:
    secco1(SD, T#28s);
  END_STEP

  TRANSITION FROM I2 TO I3
    := secco1;
  END_TRANSITION

  STEP I3:
    irrigatore_acqua_A(N);
    irrigazione_ok_A(SD, T#10s);
  END_STEP

  TRANSITION FROM I3 TO I4
    := irrigazione_ok_A;
  END_TRANSITION

  STEP I4:
    secco1(R);
    irrigazione_ok_A(R);
  END_STEP

  TRANSITION FROM I4 TO I2
    := 1;
  END_TRANSITION

  INITIAL_STEP irrigazione_edera0:
  END_STEP

  TRANSITION FROM irrigazione_edera0 TO I1
    := start2;
  END_TRANSITION

  STEP I1:
    secco2(SD, T#12s);
  END_STEP

  TRANSITION FROM I1 TO I5
    := secco2;
  END_TRANSITION

  STEP I5:
    irrigatore_acqua_E(N);
    irrigazione_ok_E(SD, T#10s);
  END_STEP

  TRANSITION FROM I5 TO I6
    := irrigazione_ok_E;
  END_TRANSITION

  STEP I6:
    secco2(R);
    irrigazione_ok_E(R);
  END_STEP

  TRANSITION FROM I6 TO I1
    := 1;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
