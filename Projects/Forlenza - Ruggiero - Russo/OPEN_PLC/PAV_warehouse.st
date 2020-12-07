PROGRAM main
  VAR
    start_button AT %IX100.0 : BOOL := False;
    at_entry_sensor AT %IX100.1 : BOOL := True;
    at_load_sensor AT %IX100.2 : BOOL := True;
    at_middle_sensor AT %IX100.3 : BOOL := True;
    x_sensor AT %IX100.4 : BOOL := False;
    z_sensor AT %IX100.5 : BOOL := False;
    manual AT %IX100.6 : BOOL := False;
    auto AT %IX100.7 : BOOL := False;
    forw_button AT %IX101.0 : BOOL := False;
  END_VAR
  VAR_EXTERNAL
    at_unload_sensor : BOOL;
  END_VAR
  VAR
    at_exit_sensor AT %IX101.2 : BOOL := True;
    retrieve_button AT %IX101.3 : BOOL := False;
    carrello_entrata AT %QX100.0 : BOOL := False;
    carrello_carico AT %QX100.1 : BOOL := False;
    start_light AT %QX100.2 : BOOL := False;
    carica_pallet AT %QX100.3 : BOOL := False;
    lift AT %QX100.4 : BOOL := False;
    scarica_pallet AT %QX100.5 : BOOL := False;
    forw_light AT %QX100.6 : BOOL := False;
    errore_0 AT %QX100.7 : BOOL;
    carrello_uscita AT %QX101.0 : BOOL := False;
    carrello_scarico AT %QX101.1 : BOOL := False;
    retr_light AT %QX101.2 : BOOL := False;
    position AT %QW100 : INT := 0;
    manual_position AT %QW0 : INT := 0;
  END_VAR
  VAR
    counter : INT := 0;
    sync0 : BOOL := False;
    sync1 : BOOL := False;
    sync2 : BOOL := False;
    sync3 : BOOL := False;
    sync4 : BOOL := False;
    tras_fermo : BOOL := False;
    magazzino : ARRAY [1..54] OF BOOL;
    i : INT;
    trovato : BOOL;
    pos : INT;
    max_dim : INT := 54;
  END_VAR
  VAR
    cont_mag AT %QW1 : INT;
  END_VAR
  VAR
    ok_retrieve : BOOL := False;
    ok_ins : BOOL := True;
    ok_ret_pos : BOOL := False;
    sistema_avviato : BOOL := False;
    store_avviato : BOOL := False;
    retrieve_avviato : BOOL := False;
    forward_avviato : BOOL := False;
  END_VAR

  INITIAL_STEP QUIETE_STORE:
  END_STEP

  TRANSITION FROM QUIETE_STORE TO VER_ST_FASI
    := (start_button) and not(retrieve_button) and not(forw_button);
  END_TRANSITION

  STEP VER_ST_FASI:
  END_STEP

  TRANSITION FROM VER_ST_FASI TO STORE
    := not(retrieve_avviato) and not(forward_avviato);
  END_TRANSITION

  STEP STORE:
    store_avviato(S);
  END_STEP

  TRANSITION FROM STORE TO CARICA_PAL
    := (cont_mag <> max_dim) and not(at_load_sensor);
  END_TRANSITION

  STEP CARICA_PAL:
    carica_pallet(L, t#6s);
    lift(D, t#3s);
    sync0(D, t#10s);
  END_STEP

  TRANSITION FROM CARICA_PAL TO SCARICA_PA
    := (sync0) ;
  END_TRANSITION

  STEP SCARICA_PA:
  END_STEP

  TRANSITION FROM SCARICA_PA TO AUTO_MODE
    := (auto);
  END_TRANSITION

  STEP AUTO_MODE:
  END_STEP

  TRANSITION FROM AUTO_MODE TO ABBASSA_LIF
    := (at_middle_sensor);
  END_TRANSITION

  STEP ABBASSA_LIF:
    ricerca_primo_libero(P);
    ABBASSA_LIF_INLINE1(D, t#1s);
    sync0(D, t#3s);
  END_STEP

  ACTION ricerca_primo_libero:
    i := 1;
    trovato := FALSE;
    pos := -1;

    while (not(trovato) AND (i<=max_dim)) do
            if (magazzino[i]=False) then
                pos := i;
                trovato := TRUE;
            else
                i := i+1;
            end_if;
    end_while;

    magazzino[pos]:=True;
    counter := pos;
  END_ACTION

  ACTION ABBASSA_LIF_INLINE1:
    position:=counter;
  END_ACTION

  TRANSITION FROM ABBASSA_LIF TO inter_0
    := sync0;
  END_TRANSITION

  STEP inter_0:
  END_STEP

  TRANSITION FROM inter_0 TO STOC
    := not(x_sensor) AND not(z_sensor);
  END_TRANSITION

  STEP STOC:
    scarica_pallet(SD, t#6s);
    lift(D, t#3s);
    sync0(D, t#10s);
  END_STEP

  TRANSITION FROM STOC TO time_w0
    := sync0;
  END_TRANSITION

  STEP time_w0:
    sync0(D, t#3s);
  END_STEP

  TRANSITION FROM time_w0 TO abbassa_scar_pal
    := sync0;
  END_TRANSITION

  STEP abbassa_scar_pal:
    scarica_pallet(R);
    ABBASSA_SCAR_PAL_INLINE2(D, t#3s);
    sync0(D, t#6s);
  END_STEP

  ACTION ABBASSA_SCAR_PAL_INLINE2:
    position:=2147;
  END_ACTION

  TRANSITION FROM abbassa_scar_pal TO MAG_PLUS
    := (sync0) AND not(x_sensor) AND not(z_sensor);
  END_TRANSITION

  STEP MAG_PLUS:
    MAG_PLUS_INLINE3(P);
    MAG_PLUS_INLINE4(P);
    store_avviato(R);
  END_STEP

  ACTION MAG_PLUS_INLINE3:
    cont_mag:=cont_mag+1;
  END_ACTION

  ACTION MAG_PLUS_INLINE4:
    manual_position:=0;
  END_ACTION

  TRANSITION FROM MAG_PLUS TO QUIETE_STORE
    := 1;
  END_TRANSITION

  TRANSITION FROM SCARICA_PA TO Manual_Mode
    := manual;
  END_TRANSITION

  STEP Manual_Mode:
  END_STEP

  TRANSITION FROM Manual_Mode TO ABBASSA_LIF_MAN
    := (at_middle_sensor);
  END_TRANSITION

  STEP ABBASSA_LIF_MAN:
    check_manual_position(N);
  END_STEP

  ACTION check_manual_position:
    if( (manual_position<1) OR (manual_position>max_dim) ) then
        position:=0;
        errore_0:=1;
        
    else
        if ( (magazzino[manual_position]=TRUE)) then
            position:=0;
            errore_0:=1;
        else
            position:=manual_position;
            magazzino[manual_position]:=TRUE;
            errore_0:=0;
         end_if;
    end_if;


  END_ACTION

  TRANSITION FROM ABBASSA_LIF_MAN TO inter_0
    := (position)<>0 AND (position)<>2167 ;
  END_TRANSITION

  TRANSITION FROM STORE TO annulla_ins
    := cont_mag = max_dim;
  END_TRANSITION

  STEP annulla_ins:
    store_avviato(R);
  END_STEP

  TRANSITION FROM annulla_ins TO QUIETE_STORE
    := 1;
  END_TRANSITION

  INITIAL_STEP forw_0:
  END_STEP

  TRANSITION FROM forw_0 TO forw_on
    := (forw_button) ;
  END_TRANSITION

  STEP forw_on:
    forw_light(S);
    sistema_avviato(S);
  END_STEP

  TRANSITION FROM forw_on TO forw_off
    := not(forw_button);
  END_TRANSITION

  STEP forw_off:
    forw_light(R);
    sistema_avviato(R);
  END_STEP

  TRANSITION FROM forw_off TO forw_0
    := 1;
  END_TRANSITION

  INITIAL_STEP retr_0:
  END_STEP

  TRANSITION FROM retr_0 TO retr_on
    := retrieve_button;
  END_TRANSITION

  STEP retr_on:
    retr_light(S);
    sistema_avviato(S);
  END_STEP

  TRANSITION FROM retr_on TO Step0
    := not(retrieve_button);
  END_TRANSITION

  STEP Step0:
    retr_light(R);
    sistema_avviato(R);
  END_STEP

  TRANSITION FROM Step0 TO retr_0
    := 1;
  END_TRANSITION

  INITIAL_STEP start_0:
  END_STEP

  TRANSITION FROM start_0 TO start_on
    := (start_button);
  END_TRANSITION

  STEP start_on:
    start_light(S);
    sistema_avviato(S);
  END_STEP

  TRANSITION FROM start_on TO start_off
    := not(start_button);
  END_TRANSITION

  STEP start_off:
    start_light(R);
    sistema_avviato(R);
  END_STEP

  TRANSITION FROM start_off TO start_0
    := 1;
  END_TRANSITION

  INITIAL_STEP QUIETE_RET:
  END_STEP

  TRANSITION FROM QUIETE_RET TO VER_RET_FASI
    := (retrieve_button) and not(start_button)  and not(forw_button);
  END_TRANSITION

  STEP VER_RET_FASI:
  END_STEP

  TRANSITION FROM VER_RET_FASI TO RETR_start
    := not(store_avviato) and not(forward_avviato);
  END_TRANSITION

  STEP RETR_start:
    retrieve_avviato(S);
  END_STEP

  TRANSITION FROM RETR_start TO CONTROLLO_POSIZIONE
    := cont_mag <>0;
  END_TRANSITION

  STEP CONTROLLO_POSIZIONE:
    check_retrieve_position(N);
    retrieve_avviato(S);
  END_STEP

  ACTION check_retrieve_position:
    if( (manual_position<1) OR (manual_position>max_dim) ) then
        ok_ret_pos:=False;
        errore_0:=1;
        
    else
        if ( (magazzino[manual_position]=False)) then
            ok_ret_pos:=False;
            errore_0:=1;
        else
            position:=manual_position;
            magazzino[manual_position]:=False;
            ok_ret_pos:=True;
            errore_0:=0;
         end_if;
    end_if;
  END_ACTION

  TRANSITION FROM CONTROLLO_POSIZIONE TO wait_dummy
    := ok_ret_pos;
  END_TRANSITION

  STEP wait_dummy:
    sync2(D, t#3s);
  END_STEP

  TRANSITION FROM wait_dummy TO RETR
    := not(x_sensor) AND not(z_sensor) and sync2 ;
  END_TRANSITION

  STEP RETR:
    scarica_pallet(L, t#6s);
    lift(D, t#3s);
    sync2(D, t#10s);
  END_STEP

  TRANSITION FROM RETR TO BACK_0
    := sync2;
  END_TRANSITION

  STEP BACK_0:
    BACK_0_INLINE5(P);
    sync2(D, t#4s);
  END_STEP

  ACTION BACK_0_INLINE5:
    position:=2147;
  END_ACTION

  TRANSITION FROM BACK_0 TO Scar_ret
    := (sync2) AND not(x_sensor) AND not(z_sensor) and (at_unload_sensor);
  END_TRANSITION

  STEP Scar_ret:
    scarica_pallet(D, t#1s);
    lift(L, t#3s);
    sync2(D, t#6s);
  END_STEP

  TRANSITION FROM Scar_ret TO MAG_SUB
    := sync2;
  END_TRANSITION

  STEP MAG_SUB:
    MAG_SUB_INLINE6(P);
    sync2(D, t#2s);
    retrieve_avviato(R);
    MAG_SUB_INLINE7(P);
  END_STEP

  ACTION MAG_SUB_INLINE6:
    cont_mag:=cont_mag-1;
  END_ACTION

  ACTION MAG_SUB_INLINE7:
    manual_position:=0;
  END_ACTION

  TRANSITION FROM MAG_SUB TO QUIETE_RET
    := 1;
  END_TRANSITION

  TRANSITION FROM RETR_start TO annulla_retr
    := cont_mag=0;
  END_TRANSITION

  STEP annulla_retr:
    retrieve_avviato(R);
  END_STEP

  TRANSITION FROM annulla_retr TO QUIETE_RET
    := 1;
  END_TRANSITION

  INITIAL_STEP QUIETE_CAR_SCAR:
  END_STEP

  TRANSITION FROM QUIETE_CAR_SCAR TO MUOVI_CAR_SCAR0
    := not(at_unload_sensor);
  END_TRANSITION

  STEP MUOVI_CAR_SCAR0:
    carrello_scarico(S);
    sync4(D, t#3s);
    carrello_uscita(S);
  END_STEP

  TRANSITION FROM MUOVI_CAR_SCAR0 TO RISORSA_OCC
    := (at_unload_sensor);
  END_TRANSITION

  STEP RISORSA_OCC:
    carrello_scarico(R);
    carrello_uscita(R);
  END_STEP

  TRANSITION FROM RISORSA_OCC TO QUIETE_CAR_SCAR
    := 1;
  END_TRANSITION

  INITIAL_STEP QUIETE_CAR_ENT:
  END_STEP

  TRANSITION FROM QUIETE_CAR_ENT TO attesa_avvio_0
    := sistema_avviato;
  END_TRANSITION

  STEP attesa_avvio_0:
  END_STEP

  TRANSITION FROM attesa_avvio_0 TO Step1
    := not(at_entry_sensor) and (at_load_sensor);
  END_TRANSITION

  STEP Step1:
    sync1(D, t#2s);
  END_STEP

  TRANSITION FROM Step1 TO MUOVI_CAR_ENT
    := sync1;
  END_TRANSITION

  STEP MUOVI_CAR_ENT:
    carrello_carico(S);
    carrello_entrata(S);
  END_STEP

  TRANSITION FROM MUOVI_CAR_ENT TO FERMA_CAR_ENT
    := not(at_load_sensor);
  END_TRANSITION

  STEP FERMA_CAR_ENT:
    carrello_carico(R);
    carrello_entrata(R);
  END_STEP

  TRANSITION FROM FERMA_CAR_ENT TO QUIETE_CAR_ENT
    := 1;
  END_TRANSITION

  INITIAL_STEP QUIETE_FORW:
  END_STEP

  TRANSITION FROM QUIETE_FORW TO VER_FORW_FASI
    := (forw_button) and not(retrieve_button) and not(start_button);
  END_TRANSITION

  STEP VER_FORW_FASI:
  END_STEP

  TRANSITION FROM VER_FORW_FASI TO FORW_start
    := not(store_avviato) and not(retrieve_avviato);
  END_TRANSITION

  STEP FORW_start:
    forward_avviato(S);
  END_STEP

  TRANSITION FROM FORW_start TO CARICA_PAL_FW
    := not(at_load_sensor);
  END_TRANSITION

  STEP CARICA_PAL_FW:
    carica_pallet(L, t#6s);
    lift(D, t#3s);
    sync3(D, t#10s);
  END_STEP

  TRANSITION FROM CARICA_PAL_FW TO SCARICA_PAL_FW
    := (sync3) and (at_unload_sensor);
  END_TRANSITION

  STEP SCARICA_PAL_FW:
    scarica_pallet(D, t#1s);
    lift(L, t#3s);
    sync3(D, t#6s);
  END_STEP

  TRANSITION FROM SCARICA_PAL_FW TO dummy_tmp
    := sync3;
  END_TRANSITION

  STEP dummy_tmp:
    sync3(D, t#3s);
  END_STEP

  TRANSITION FROM dummy_tmp TO FORW_start0
    := sync3;
  END_TRANSITION

  STEP FORW_start0:
    forward_avviato(R);
  END_STEP

  TRANSITION FROM FORW_start0 TO QUIETE_FORW
    := 1;
  END_TRANSITION

END_PROGRAM

PROGRAM smistatore
  VAR_EXTERNAL
    at_unload_sensor : BOOL;
  END_VAR
  VAR
    turn_entry AT %IX101.5 : BOOL := False;
    at_front AT %IX101.6 : BOOL := 0;
    pallet_sensor AT %IX101.7 : BOOL := 0;
    low AT %IX102.0 : BOOL := 0;
    medium AT %IX102.1 : BOOL := 0;
    hight AT %IX102.2 : BOOL := 0;
    at_right AT %IX102.3 : BOOL := 0;
    at_right_exit AT %IX102.4 : BOOL := 0;
    at_left AT %IX102.5 : BOOL := 0;
    at_left_exit AT %IX102.6 : BOOL := 0;
    at_fwd AT %IX102.7 : BOOL := 0;
    at_fwd_exit AT %IX103.0 : BOOL := 0;
    enterconveyor AT %QX101.3 : BOOL := False;
    enterconveyor1 AT %QX101.4 : BOOL := False;
    loaded_turn AT %QX101.5 : BOOL := 0;
    rightconveyor AT %QX101.6 : BOOL := 0;
    turn AT %QX101.7 : BOOL := 0;
    loaded_turn_right AT %QX102.0 : BOOL := 0;
    leftconveyor AT %QX102.1 : BOOL := 0;
    frconveyor AT %QX102.2 : BOOL := 0;
  END_VAR
  VAR
    wait : BOOL := 0;
    wait1 : BOOL := 0;
    wait2 : BOOL := 0;
    wait3 : BOOL := 0;
    left_ok : BOOL := 0;
    right_ok : BOOL := 0;
    fwd_ok : BOOL := 0;
    cont : INT := 0;
  END_VAR

  INITIAL_STEP CHECk_QUIETE:
  END_STEP

  TRANSITION FROM CHECk_QUIETE TO SCELTA
    := 1;
  END_TRANSITION

  STEP SCELTA:
  END_STEP

  TRANSITION FROM SCELTA TO CHECK_PROCESSING0
    := (pallet_sensor) AND (low) AND (medium) AND (hight);
  END_TRANSITION

  STEP CHECK_PROCESSING0:
  END_STEP

  TRANSITION FROM CHECK_PROCESSING0 TO CARICA0
    := turn_entry ;
  END_TRANSITION

  STEP CARICA0:
    loaded_turn(N);
  END_STEP

  TRANSITION FROM CARICA0 TO FERMA_CARR
    := at_front ;
  END_TRANSITION

  STEP FERMA_CARR:
  END_STEP

  TRANSITION FROM FERMA_CARR TO GIRA
    := 1;
  END_TRANSITION

  STEP GIRA:
    turn(S);
    left_ok(S);
  END_STEP

  TRANSITION FROM GIRA TO CHECk_QUIETE
    := 1;
  END_TRANSITION

  TRANSITION FROM SCELTA TO CHECK_PROCESSING1
    := (pallet_sensor) AND (low) AND (medium) AND NOT(hight);
  END_TRANSITION

  STEP CHECK_PROCESSING1:
  END_STEP

  TRANSITION FROM CHECK_PROCESSING1 TO CARICA1
    := turn_entry ;
  END_TRANSITION

  STEP CARICA1:
    loaded_turn(N);
  END_STEP

  TRANSITION FROM CARICA1 TO FERMA_CARR1
    := at_front ;
  END_TRANSITION

  STEP FERMA_CARR1:
    fwd_ok(S);
  END_STEP

  TRANSITION FROM FERMA_CARR1 TO CHECk_QUIETE
    := 1;
  END_TRANSITION

  TRANSITION FROM SCELTA TO CHECK_PROCESSING2
    := (pallet_sensor) AND (low) AND NOT (medium) AND NOT(hight);
  END_TRANSITION

  STEP CHECK_PROCESSING2:
  END_STEP

  TRANSITION FROM CHECK_PROCESSING2 TO CARICA2
    := turn_entry ;
  END_TRANSITION

  STEP CARICA2:
    loaded_turn(N);
  END_STEP

  TRANSITION FROM CARICA2 TO FERMA_CARR2
    := at_front ;
  END_TRANSITION

  STEP FERMA_CARR2:
  END_STEP

  TRANSITION FROM FERMA_CARR2 TO GIRA1
    := 1;
  END_TRANSITION

  STEP GIRA1:
    turn(S);
    right_ok(S);
  END_STEP

  TRANSITION FROM GIRA1 TO CHECk_QUIETE
    := 1;
  END_TRANSITION

  INITIAL_STEP FWD_QUIETE:
  END_STEP

  TRANSITION FROM FWD_QUIETE TO DI_FRONTE1
    := (fwd_ok);
  END_TRANSITION

  STEP DI_FRONTE1:
    frconveyor(S);
    fwd_ok(R);
    loaded_turn(SD, T#3s);
  END_STEP

  TRANSITION FROM DI_FRONTE1 TO RESETTA_FRONT1
    := at_fwd;
  END_TRANSITION

  STEP RESETTA_FRONT1:
    loaded_turn(R);
  END_STEP

  TRANSITION FROM RESETTA_FRONT1 TO Pause1
    := 1;
  END_TRANSITION

  STEP Pause1:
  END_STEP

  TRANSITION FROM Pause1 TO RIPOS_DESTRA2
    := at_fwd_exit;
  END_TRANSITION

  STEP RIPOS_DESTRA2:
    frconveyor(R);
  END_STEP

  TRANSITION FROM RIPOS_DESTRA2 TO FWD_QUIETE
    := 1;
  END_TRANSITION

  INITIAL_STEP LEFT_QUIETE:
  END_STEP

  TRANSITION FROM LEFT_QUIETE TO SINISTRA0
    := (left_ok);
  END_TRANSITION

  STEP SINISTRA0:
    leftconveyor(S);
    loaded_turn(SD, T#5s);
  END_STEP

  TRANSITION FROM SINISTRA0 TO RIPOS_SINISTRA0
    := at_left;
  END_TRANSITION

  STEP RIPOS_SINISTRA0:
    turn(R);
    loaded_turn(R);
    left_ok(R);
  END_STEP

  TRANSITION FROM RIPOS_SINISTRA0 TO Pause
    := 1;
  END_TRANSITION

  STEP Pause:
  END_STEP

  TRANSITION FROM Pause TO RIPOS_DESTRA1
    := at_left_exit;
  END_TRANSITION

  STEP RIPOS_DESTRA1:
    leftconveyor(R);
  END_STEP

  TRANSITION FROM RIPOS_DESTRA1 TO LEFT_QUIETE
    := 1;
  END_TRANSITION

  INITIAL_STEP RIGHT_QUIETE:
  END_STEP

  TRANSITION FROM RIGHT_QUIETE TO DESTRA1
    := (right_ok);
  END_TRANSITION

  STEP DESTRA1:
    rightconveyor(S);
    loaded_turn_right(SD, t#5s);
  END_STEP

  TRANSITION FROM DESTRA1 TO RIPOS_DESTRA
    := at_right;
  END_TRANSITION

  STEP RIPOS_DESTRA:
    turn(R);
    right_ok(R);
    loaded_turn_right(R);
  END_STEP

  TRANSITION FROM RIPOS_DESTRA TO RIPOS_DESTRA0
    := at_right_exit;
  END_TRANSITION

  STEP RIPOS_DESTRA0:
    rightconveyor(R);
  END_STEP

  TRANSITION FROM RIPOS_DESTRA0 TO RIGHT_QUIETE
    := 1;
  END_TRANSITION

  INITIAL_STEP start_converyors:
    wait3(D, t#2s);
  END_STEP

  TRANSITION FROM start_converyors TO attiva_carrelli
    := not(at_unload_sensor) and wait3;
  END_TRANSITION

  STEP attiva_carrelli:
    enterconveyor(S);
    enterconveyor1(S);
  END_STEP

  TRANSITION FROM attiva_carrelli TO disattiva_carrelli0
    := turn_entry;
  END_TRANSITION

  STEP disattiva_carrelli0:
    wait3(D, t#3s);
  END_STEP

  TRANSITION FROM disattiva_carrelli0 TO disattiva_carrelli
    := wait3;
  END_TRANSITION

  STEP disattiva_carrelli:
    enterconveyor(R);
    enterconveyor1(R);
  END_STEP

  TRANSITION FROM disattiva_carrelli TO inter_fase
    := not(turn);
  END_TRANSITION

  STEP inter_fase:
  END_STEP

  TRANSITION FROM inter_fase TO attiva_carrelli
    := ((at_fwd) or (at_right) or (at_left)) and cont<>0;
  END_TRANSITION

  TRANSITION FROM inter_fase TO start_converyors
    := ((at_fwd) or (at_right) or (at_left)) and cont=0;
  END_TRANSITION

  INITIAL_STEP Cont_Plus:
    wait1(D, t#2s);
  END_STEP

  TRANSITION FROM Cont_Plus TO Pluss
    := not(at_unload_sensor) and wait1;
  END_TRANSITION

  STEP Pluss:
    PLUSS_INLINE1(P);
  END_STEP

  ACTION PLUSS_INLINE1:
    cont:=cont+1;
  END_ACTION

  TRANSITION FROM Pluss TO Cont_Plus
    := at_unload_sensor;
  END_TRANSITION

  INITIAL_STEP Cont_Sub:
    wait2(D, t#2s);
  END_STEP

  TRANSITION FROM Cont_Sub TO Subb
    := turn_entry and wait2;
  END_TRANSITION

  STEP Subb:
    SUBB_INLINE2(P);
  END_STEP

  ACTION SUBB_INLINE2:
    cont:=cont-1;
  END_ACTION

  TRANSITION FROM Subb TO Cont_Sub
    := not(turn_entry);
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      at_unload_sensor AT %IX101.1 : BOOL := True;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
    PROGRAM instance1 WITH task0 : smistatore;
  END_RESOURCE
END_CONFIGURATION
