PROGRAM program0
  VAR
    A_start : BOOL := 0;
    S3X : BOOL := 0;
    S3_BX : BOOL := 0;
    S16X : BOOL := 0;
    S16_BX : BOOL := 0;
    A_Tempo_Semina : BOOL;
    B_Tempo_Semina : BOOL;
    A_motore_avanti : BOOL := 0;
    A_motore_dietro : BOOL := 0;
    A_motore_sinistra : BOOL := 0;
    A_andata : BOOL := 0;
    A_rilascio : BOOL := 0;
    A_dock_ricarica : BOOL := 0;
    B_start : BOOL := 0;
    B_motore_avanti : BOOL := 0;
    B_motore_dietro : BOOL := 0;
    B_motore_destra : BOOL := 0;
    B_dock_ricarica : BOOL := 0;
    B_andata : BOOL := 0;
    B_rilascio : BOOL := 0;
    C_sensor : BOOL := 0;
    D_sensor : BOOL := 0;
    E_sensor : BOOL := 0;
    F_sensor : BOOL := 0;
    G_sx_sensor : BOOL := 0;
    G_dx_sensor : BOOL := 0;
    Pressione_giu : BOOL := 0;
    Pressione_min : BOOL := 0;
    Pressione_su : BOOL := 0;
    Pressione_max : BOOL := 0;
    Portello_A_apri : BOOL := 0;
    Portello_A_chiudi : BOOL := 0;
    Portello_A_aperto : BOOL := 0;
    Portello_A_chiuso : BOOL := 0;
    Portello_B_chiuso : BOOL := 0;
    Portello_B_chiudi : BOOL := 0;
    Portello_B_apri : BOOL := 0;
    Portello_B_aperto : BOOL := 0;
    Semina_A_OK : BOOL := 0;
    Semina_B_OK : BOOL := 0;
  END_VAR

  INITIAL_STEP S1:
  END_STEP

  TRANSITION FROM S1 TO S2
    := A_start;
  END_TRANSITION

  STEP S2:
    A_motore_avanti(N);
  END_STEP

  TRANSITION FROM S2 TO S3
    := A_andata;
  END_TRANSITION

  STEP S3:
    S3X(N);
  END_STEP

  TRANSITION FROM (S3, D1) TO S4
    := 1;
  END_TRANSITION

  STEP S4:
    B_motore_avanti(N);
  END_STEP

  TRANSITION FROM S4 TO S5
    := C_sensor;
  END_TRANSITION

  STEP S5:
    Pressione_giu(N);
  END_STEP

  TRANSITION FROM S5 TO S6
    := Pressione_min;
  END_TRANSITION

  STEP S6:
    Portello_A_apri(N);
  END_STEP

  TRANSITION FROM S6 TO S7
    := Portello_A_aperto;
  END_TRANSITION

  STEP S7:
    A_motore_avanti(N);
  END_STEP

  TRANSITION FROM S7 TO S8
    := D_sensor;
  END_TRANSITION

  STEP S8:
    Portello_A_chiudi(N);
  END_STEP

  TRANSITION FROM S8 TO S9
    := Portello_A_chiuso;
  END_TRANSITION

  STEP S9:
    A_motore_avanti(N);
  END_STEP

  TRANSITION FROM S9 TO S10
    := E_sensor;
  END_TRANSITION

  STEP S10:
    Pressione_su(N);
  END_STEP

  TRANSITION FROM S10 TO S11
    := Pressione_max;
  END_TRANSITION

  STEP S11:
    Portello_B_apri(N);
  END_STEP

  TRANSITION FROM S11 TO S12
    := Portello_B_aperto;
  END_TRANSITION

  STEP S12:
    A_motore_avanti(N);
  END_STEP

  TRANSITION FROM S12 TO S13
    := F_sensor;
  END_TRANSITION

  STEP S13:
    Portello_B_chiudi(N);
  END_STEP

  TRANSITION FROM S13 TO S14
    := Portello_B_chiuso;
  END_TRANSITION

  STEP S14:
    A_motore_sinistra(N);
  END_STEP

  TRANSITION FROM S14 TO (S15, D5)
    := G_sx_sensor;
  END_TRANSITION

  STEP S15:
    A_rilascio(N);
    A_Tempo_Semina(SD, T#30s);
  END_STEP

  TRANSITION FROM S15 TO S16
    := A_Tempo_Semina;
  END_TRANSITION

  STEP S16:
    A_motore_dietro(N);
    S16X(N);
  END_STEP

  TRANSITION FROM (S16, D3) TO S17
    := F_sensor;
  END_TRANSITION

  STEP S17:
    Pressione_su(N);
  END_STEP

  TRANSITION FROM S17 TO S18
    := Pressione_max;
  END_TRANSITION

  STEP S18:
    Portello_B_apri(N);
  END_STEP

  TRANSITION FROM S18 TO S19
    := Portello_B_aperto;
  END_TRANSITION

  STEP S19:
    A_motore_dietro(N);
  END_STEP

  TRANSITION FROM S19 TO S20
    := E_sensor;
  END_TRANSITION

  STEP S20:
    Portello_B_chiudi(N);
  END_STEP

  TRANSITION FROM S20 TO S21
    := Portello_B_chiuso;
  END_TRANSITION

  STEP S21:
    Pressione_giu(N);
  END_STEP

  TRANSITION FROM S21 TO S22
    := Pressione_min;
  END_TRANSITION

  STEP S22:
    A_motore_dietro(N);
  END_STEP

  TRANSITION FROM S22 TO S23
    := D_sensor;
  END_TRANSITION

  STEP S23:
    Portello_A_apri(N);
  END_STEP

  TRANSITION FROM S23 TO S24
    := Portello_A_aperto;
  END_TRANSITION

  STEP S24:
    A_motore_dietro(N);
  END_STEP

  TRANSITION FROM S24 TO (S25, D7)
    := C_sensor;
  END_TRANSITION

  STEP S25:
    Portello_A_chiudi(N);
  END_STEP

  TRANSITION FROM S25 TO S26
    := Portello_A_chiuso;
  END_TRANSITION

  STEP S26:
    A_motore_dietro(N);
  END_STEP

  TRANSITION FROM S26 TO S27
    := A_dock_ricarica;
  END_TRANSITION

  STEP S27:
    Semina_A_OK(S);
    A_start(R);
  END_STEP

  TRANSITION FROM S27 TO S1
    := 1;
  END_TRANSITION

  STEP D7:
  END_STEP

  TRANSITION FROM D7 TO Semaforo
    := 1;
  END_TRANSITION

  INITIAL_STEP Semaforo:
  END_STEP

  TRANSITION FROM Semaforo TO D1
    := S3X;
  END_TRANSITION

  STEP D1:
  END_STEP

  TRANSITION FROM Semaforo TO D3
    := S16X;
  END_TRANSITION

  STEP D3:
  END_STEP

  TRANSITION FROM Semaforo TO D4
    := NOT(S16X) AND S16_BX AND NOT(S3X);
  END_TRANSITION

  STEP D4:
  END_STEP

  TRANSITION FROM (D4, S16_B) TO S17_B
    := F_sensor;
  END_TRANSITION

  STEP S17_B:
    Pressione_su(N);
  END_STEP

  TRANSITION FROM S17_B TO S18_B
    := Pressione_max;
  END_TRANSITION

  STEP S18_B:
    Portello_B_apri(N);
  END_STEP

  TRANSITION FROM S18_B TO S19_B
    := Portello_B_aperto;
  END_TRANSITION

  STEP S19_B:
    B_motore_dietro(N);
  END_STEP

  TRANSITION FROM S19_B TO S20_B
    := E_sensor;
  END_TRANSITION

  STEP S20_B:
    Portello_B_chiudi(N);
  END_STEP

  TRANSITION FROM S20_B TO S21_B
    := Portello_B_chiuso;
  END_TRANSITION

  STEP S21_B:
    Pressione_giu(N);
  END_STEP

  TRANSITION FROM S21_B TO S22_B
    := Pressione_min;
  END_TRANSITION

  STEP S22_B:
    B_motore_dietro(N);
  END_STEP

  TRANSITION FROM S22_B TO S23_B
    := D_sensor;
  END_TRANSITION

  STEP S23_B:
    Portello_A_apri(N);
  END_STEP

  TRANSITION FROM S23_B TO S24_B
    := Portello_A_aperto;
  END_TRANSITION

  STEP S24_B:
    B_motore_dietro(N);
  END_STEP

  TRANSITION FROM S24_B TO (S25_B, D8)
    := C_sensor;
  END_TRANSITION

  STEP S25_B:
    Portello_A_chiudi(N);
  END_STEP

  TRANSITION FROM S25_B TO S26_B
    := Portello_A_chiuso;
  END_TRANSITION

  STEP S26_B:
    B_motore_dietro(N);
  END_STEP

  TRANSITION FROM S26_B TO S27_B
    := B_dock_ricarica;
  END_TRANSITION

  STEP S27_B:
    Semina_B_OK(S);
    B_start(R);
  END_STEP

  TRANSITION FROM S27_B TO S1_B
    := 1;
  END_TRANSITION

  INITIAL_STEP S1_B:
  END_STEP

  TRANSITION FROM S1_B TO S2_B
    := B_start;
  END_TRANSITION

  STEP S2_B:
    A_motore_avanti(N);
  END_STEP

  TRANSITION FROM S2_B TO S3_B
    := B_andata;
  END_TRANSITION

  STEP S3_B:
    S3_BX(N);
  END_STEP

  TRANSITION FROM (D2, S3_B) TO S4_B
    := 1;
  END_TRANSITION

  STEP S4_B:
    B_motore_avanti(N);
  END_STEP

  TRANSITION FROM S4_B TO S5_B
    := C_sensor;
  END_TRANSITION

  STEP S5_B:
    Pressione_giu(N);
  END_STEP

  TRANSITION FROM S5_B TO S6_B
    := Pressione_min;
  END_TRANSITION

  STEP S6_B:
    Portello_A_apri(N);
  END_STEP

  TRANSITION FROM S6_B TO S7_B
    := Portello_A_aperto;
  END_TRANSITION

  STEP S7_B:
    B_motore_avanti(N);
  END_STEP

  TRANSITION FROM S7_B TO S8_B
    := D_sensor;
  END_TRANSITION

  STEP S8_B:
    Portello_A_chiudi(N);
  END_STEP

  TRANSITION FROM S8_B TO S9_B
    := Portello_A_chiuso;
  END_TRANSITION

  STEP S9_B:
    B_motore_avanti(N);
  END_STEP

  TRANSITION FROM S9_B TO S10_B
    := E_sensor;
  END_TRANSITION

  STEP S10_B:
    Pressione_su(N);
  END_STEP

  TRANSITION FROM S10_B TO S11_B
    := Pressione_max;
  END_TRANSITION

  STEP S11_B:
    Portello_B_apri(N);
  END_STEP

  TRANSITION FROM S11_B TO S12_B
    := Portello_B_aperto;
  END_TRANSITION

  STEP S12_B:
    B_motore_avanti(N);
  END_STEP

  TRANSITION FROM S12_B TO S13_B
    := F_sensor;
  END_TRANSITION

  STEP S13_B:
    Portello_B_chiudi(N);
  END_STEP

  TRANSITION FROM S13_B TO S14_B
    := Portello_B_chiuso;
  END_TRANSITION

  STEP S14_B:
    B_motore_destra(N);
  END_STEP

  TRANSITION FROM S14_B TO (S15_B, D6)
    := G_dx_sensor;
  END_TRANSITION

  STEP S15_B:
    B_rilascio(N);
    B_Tempo_Semina(SD, T#20s);
  END_STEP

  TRANSITION FROM S15_B TO S16_B
    := B_Tempo_Semina;
  END_TRANSITION

  STEP S16_B:
    B_motore_dietro(N);
    S16_BX(N);
  END_STEP

  STEP D6:
  END_STEP

  TRANSITION FROM D6 TO Semaforo
    := 1;
  END_TRANSITION

  STEP D8:
  END_STEP

  TRANSITION FROM D8 TO Semaforo
    := 1;
  END_TRANSITION

  TRANSITION FROM Semaforo TO D2
    := NOT(S3.X) AND S3_B.X AND NOT(S16.X);
  END_TRANSITION

  STEP D2:
  END_STEP

  STEP D5:
  END_STEP

  TRANSITION FROM D5 TO Semaforo
    := 1;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
