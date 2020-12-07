TYPE
  GestionePiani : STRUCT
    DIR : SINT := 0;
    PIANO_CORRENTE : SINT := 0;
  END_STRUCT;
  Richieste : STRUCT
    TOP : USINT := 0;
    DIM : UINT := 0;
    BOT : USINT := 0;
    QUEUE : ARRAY [0..19] OF SINT;
  END_STRUCT;
  Tastierino : STRUCT
    PULS_0 : BOOL := 0;
    PULS_1 : BOOL := 0;
    PULS_2 : BOOL := 0;
    PULS_3 : BOOL := 0;
    PULS_ALLARM : BOOL := 0;
  END_STRUCT;
END_TYPE

PROGRAM Sensori_Piani
  VAR_EXTERNAL
    Info : GestionePiani;
    Display : Tastierino;
  END_VAR
  VAR
    Sensor0 : BOOL := 1;
    Sensor1 : BOOL := 0;
    Sensor2 : BOOL := 0;
    Sensor3 : BOOL := 0;
  END_VAR

  INITIAL_STEP Piani:
  END_STEP

  TRANSITION FROM Piani TO Piano0
    := Sensor0;
  END_TRANSITION

  STEP Piano0:
    PIANO0_INLINE1(N);
  END_STEP

  ACTION PIANO0_INLINE1:
    Info.PIANO_CORRENTE := 0;
  END_ACTION

  TRANSITION FROM Piano0 TO Piani
    := NOT Sensor0;
  END_TRANSITION

  TRANSITION FROM Piani TO Piano1
    := Sensor1;
  END_TRANSITION

  STEP Piano1:
    PIANO1_INLINE2(N);
  END_STEP

  ACTION PIANO1_INLINE2:
    Info.PIANO_CORRENTE := 1;
  END_ACTION

  TRANSITION FROM Piano1 TO Piani
    := NOT Sensor1;
  END_TRANSITION

  TRANSITION FROM Piani TO Piano2
    := Sensor2;
  END_TRANSITION

  STEP Piano2:
    PIANO2_INLINE4(N);
  END_STEP

  ACTION PIANO2_INLINE4:
    Info.PIANO_CORRENTE := 2;
  END_ACTION

  TRANSITION FROM Piano2 TO Piani
    := NOT Sensor2;
  END_TRANSITION

  TRANSITION FROM Piani TO Piano3
    := Sensor3;
  END_TRANSITION

  STEP Piano3:
    PIANO3_INLINE3(N);
  END_STEP

  ACTION PIANO3_INLINE3:
    Info.PIANO_CORRENTE := 3;
  END_ACTION

  TRANSITION FROM Piano3 TO Piani
    := NOT Sensor3;
  END_TRANSITION

END_PROGRAM

FUNCTION BOUBLESORT_CRESCENTE : Richieste
  VAR_INPUT
    CODA : Richieste;
  END_VAR
  VAR
    I : USINT;
    DUMMY : SINT;
    CAMBIO : BOOL := 1;
  END_VAR

  IF CODA.DIM > 1 THEN
    WHILE CAMBIO DO
      CAMBIO := 0;
        FOR I:=CODA.BOT TO CODA.TOP-1 BY 1 MOD 20 DO
          IF CODA.QUEUE[I] > CODA.QUEUE[I+1] THEN
            DUMMY := CODA.QUEUE[I];
            CODA.QUEUE[I] := CODA.QUEUE[I+1];
            CODA.QUEUE[I+1] := DUMMY;
            CAMBIO := 1;
          END_IF;
        END_FOR;
    END_WHILE;
    BOUBLESORT_CRESCENTE := CODA;
  END_IF;
  RETURN;
END_FUNCTION

FUNCTION INSERISCI_PIANO_SALITA : Richieste
  VAR_INPUT
    CODA : Richieste;
    PIANO : SINT;
  END_VAR

  CODA.QUEUE[CODA.TOP] := PIANO;
  IF CODA.DIM < 20 THEN
    CODA.TOP := (CODA.TOP + 1) MOD 20;
    CODA.DIM := CODA.DIM + 1;
    CODA := BOUBLESORT_CRESCENTE(CODA);
  END_IF;
  INSERISCI_PIANO_SALITA := CODA;
  RETURN;
END_FUNCTION

PROGRAM Gestione_Motore
  VAR
    ACTUATOR : SINT := 0;
    PORTE : BOOL := 0;
    SENSOR_PORTE : BOOL := 0;
  END_VAR
  VAR_EXTERNAL
    Flag : BOOL;
    Info : GestionePiani;
    Richieste_Salita : Richieste;
    Richieste_Discesa : Richieste;
  END_VAR

  INITIAL_STEP Attesa:
    Check(N);
  END_STEP

  ACTION Check:
    WHILE 1 DO
      IF Info.DIR = 1 AND Richieste_Salita.DIM <> 0 THEN
        Info.DIR := 1;
      ELSIF Info.DIR = -1 AND Richieste_Discesa.DIM <> 0 THEN
        Info.DIR := -1;
      ELSIF Richieste_Salita.DIM <> 0 THEN
        Info.DIR := 1;
      ELSIF Richieste_Discesa.DIM <> 0 THEN
        Info.DIR := -1;
      ELSE
        Info.DIR := 0;
      END_IF;
    END_WHILE;
  END_ACTION

  TRANSITION FROM Attesa TO Sali
    := Info.DIR = 1;
  END_TRANSITION

  STEP Sali:
    SALI_INLINE1(N);
    Flag(R);
  END_STEP

  ACTION SALI_INLINE1:
    ACTUATOR := 1;
  END_ACTION

  TRANSITION FROM Sali TO Preleva_Salita
    := Richieste_Salita.QUEUE[Richieste_Salita.BOT] = Info.PIANO_CORRENTE;
  END_TRANSITION

  STEP Preleva_Salita:
    PRELEVA_SALITA_INLINE3(N);
  END_STEP

  ACTION PRELEVA_SALITA_INLINE3:
    Richieste_Salita := PRELEVA_PIANO(Richieste_Salita);
  END_ACTION

  TRANSITION FROM Preleva_Salita TO Apri
    := 1;
  END_TRANSITION

  STEP Apri:
    PORTE(L, T#10s);
    Flag(S);
  END_STEP

  TRANSITION FROM Apri TO Attesa
    := NOT SENSOR_PORTE;
  END_TRANSITION

  TRANSITION FROM Attesa TO Scendi
    := Info.DIR = -1;
  END_TRANSITION

  STEP Scendi:
    SCENDI_INLINE2(N);
    Flag(R);
  END_STEP

  ACTION SCENDI_INLINE2:
    ACTUATOR := -1;
  END_ACTION

  TRANSITION FROM Scendi TO Preleva_Discesa
    := Richieste_Discesa.QUEUE[Richieste_Discesa.BOT] = Info.PIANO_CORRENTE;
  END_TRANSITION

  STEP Preleva_Discesa:
    PRELEVA_DISCESA_INLINE4(N);
  END_STEP

  ACTION PRELEVA_DISCESA_INLINE4:
    Richieste_Discesa := PRELEVA_PIANO(Richieste_Discesa);
  END_ACTION

  TRANSITION FROM Preleva_Discesa TO Apri
    := 1;
  END_TRANSITION

END_PROGRAM

FUNCTION BOUBLESORT_DECRESCENTE : Richieste
  VAR_INPUT
    CODA : Richieste;
  END_VAR
  VAR
    I : USINT;
    DUMMY : SINT;
    CAMBIO : BOOL := 1;
  END_VAR

  IF CODA.DIM > 1 THEN
    WHILE CAMBIO DO
      CAMBIO := 0;
        FOR I:=CODA.BOT TO CODA.TOP-1 BY 1 MOD 20 DO
          IF CODA.QUEUE[I] < CODA.QUEUE[I+1] THEN
            DUMMY := CODA.QUEUE[I];
            CODA.QUEUE[I] := CODA.QUEUE[I+1];
            CODA.QUEUE[I+1] := DUMMY;
            CAMBIO := 1;
          END_IF;
        END_FOR;
    END_WHILE;
    BOUBLESORT_DECRESCENTE := CODA;
  END_IF;
  RETURN;
END_FUNCTION

FUNCTION INSERISCI_PIANO_DISCESA : Richieste
  VAR_INPUT
    CODA : Richieste;
    PIANO : SINT;
  END_VAR

  CODA.QUEUE[CODA.TOP] := PIANO;
  IF CODA.DIM < 20 THEN
    CODA.TOP := (CODA.TOP + 1) MOD 20;
    CODA.DIM := CODA.DIM + 1;
    CODA := BOUBLESORT_DECRESCENTE(CODA);
  END_IF;
  INSERISCI_PIANO_DISCESA := CODA;
  RETURN;
END_FUNCTION

PROGRAM Prenotazioni_Interne
  VAR_EXTERNAL
    Flag : BOOL;
    Richieste_Salita : Richieste;
    Richieste_Discesa : Richieste;
    Display : Tastierino;
    Info : GestionePiani;
  END_VAR

  INITIAL_STEP Prenotazione_Interna:
  END_STEP

  TRANSITION FROM Prenotazione_Interna TO Abilita_Tastierino
    := Flag;
  END_TRANSITION

  STEP Abilita_Tastierino:
  END_STEP

  TRANSITION FROM Abilita_Tastierino TO Inserisci_Piano0
    := Display.PULS_0 AND Info.PIANO_CORRENTE <> 0;
  END_TRANSITION

  STEP Inserisci_Piano0:
    ins_0(N);
  END_STEP

  ACTION ins_0:
    Richieste_Discesa := INSERISCI_PIANO_DISCESA(Richieste_Discesa,0);
  END_ACTION

  TRANSITION FROM Inserisci_Piano0 TO Prenotazione_Interna
    := 1;
  END_TRANSITION

  TRANSITION FROM Abilita_Tastierino TO Inserisci_Piano1
    := Display.PULS_1 AND Info.PIANO_CORRENTE <> 1;
  END_TRANSITION

  STEP Inserisci_Piano1:
    ins_1(N);
  END_STEP

  ACTION ins_1:
    IF Info.PIANO_CORRENTE < 1 THEN
    Richieste_Salita := INSERISCI_PIANO_SALITA(Richieste_Salita,1);
    ELSE
      Richieste_Discesa := INSERISCI_PIANO_DISCESA(Richieste_Discesa,1);
    END_IF;
  END_ACTION

  TRANSITION FROM Inserisci_Piano1 TO Prenotazione_Interna
    := 1;
  END_TRANSITION

  TRANSITION FROM Abilita_Tastierino TO Inserisci_Piano2
    := Display.PULS_2 AND Info.PIANO_CORRENTE <> 2;
  END_TRANSITION

  STEP Inserisci_Piano2:
    ins_2(N);
  END_STEP

  ACTION ins_2:
    IF Info.PIANO_CORRENTE < 2 THEN
    Richieste_Salita := INSERISCI_PIANO_SALITA(Richieste_Salita,2);
    ELSE
      Richieste_Discesa := INSERISCI_PIANO_DISCESA(Richieste_Discesa,2);
    END_IF;
  END_ACTION

  TRANSITION FROM Inserisci_Piano2 TO Prenotazione_Interna
    := 1;
  END_TRANSITION

  TRANSITION FROM Abilita_Tastierino TO Inserisci_Piano3
    := Display.PULS_3 AND Info.PIANO_CORRENTE <> 3;
  END_TRANSITION

  STEP Inserisci_Piano3:
    ins_3(N);
  END_STEP

  ACTION ins_3:
    Richieste_Salita := INSERISCI_PIANO_SALITA(Richieste_Salita,3);
  END_ACTION

  TRANSITION FROM Inserisci_Piano3 TO Prenotazione_Interna
    := 1;
  END_TRANSITION

END_PROGRAM

FUNCTION PRELEVA_PIANO : Richieste
  VAR_INPUT
    CODA : Richieste;
  END_VAR

  CODA.DIM := CODA.DIM - 1;
  CODA.BOT := (CODA.BOT + 1) MOD 20;
  PRELEVA_PIANO := CODA;
  RETURN;
END_FUNCTION

PROGRAM Prenotazioni_Esterne
  VAR
    PULS_0_E : BOOL;
  END_VAR
  VAR_EXTERNAL
    Info : GestionePiani;
    Richieste_Salita : Richieste;
    Richieste_Discesa : Richieste;
  END_VAR
  VAR
    PULS_1_E : BOOL;
    PULS_2_E : BOOL;
    PULS_3_E : BOOL;
  END_VAR

  INITIAL_STEP Prenotazione_Esterna:
  END_STEP

  TRANSITION FROM Prenotazione_Esterna TO Prenota0
    := PULS_0_E AND Info.PIANO_CORRENTE <> 0;
  END_TRANSITION

  STEP Prenota0:
    ins_0(N);
  END_STEP

  ACTION ins_0:
    Richieste_Discesa := INSERISCI_PIANO_DISCESA(Richieste_Discesa,0);
  END_ACTION

  TRANSITION FROM Prenota0 TO Prenotazione_Esterna
    := 1;
  END_TRANSITION

  TRANSITION FROM Prenotazione_Esterna TO Prenota1
    := PULS_1_E AND Info.PIANO_CORRENTE <> 1;
  END_TRANSITION

  STEP Prenota1:
    ins_1(N);
  END_STEP

  ACTION ins_1:
    IF Info.PIANO_CORRENTE < 1 THEN
    Richieste_Salita := INSERISCI_PIANO_SALITA(Richieste_Salita,1);
    ELSE
      Richieste_Discesa := INSERISCI_PIANO_DISCESA(Richieste_Discesa,1);
    END_IF;
  END_ACTION

  TRANSITION FROM Prenota1 TO Prenotazione_Esterna
    := 1;
  END_TRANSITION

  TRANSITION FROM Prenotazione_Esterna TO Prenota2
    := PULS_2_E AND Info.PIANO_CORRENTE <> 2;
  END_TRANSITION

  STEP Prenota2:
    ins_2(N);
  END_STEP

  ACTION ins_2:
    IF Info.PIANO_CORRENTE < 2 THEN
    Richieste_Salita := INSERISCI_PIANO_SALITA(Richieste_Salita,2);
    ELSE
      Richieste_Discesa := INSERISCI_PIANO_DISCESA(Richieste_Discesa,2);
    END_IF;
  END_ACTION

  TRANSITION FROM Prenota2 TO Prenotazione_Esterna
    := 1;
  END_TRANSITION

  TRANSITION FROM Prenotazione_Esterna TO Prenota3
    := PULS_3_E AND Info.PIANO_CORRENTE <> 3;
  END_TRANSITION

  STEP Prenota3:
    ins_3(N);
  END_STEP

  ACTION ins_3:
    Richieste_Salita := INSERISCI_PIANO_SALITA(Richieste_Salita,3);
  END_ACTION

  TRANSITION FROM Prenota3 TO Prenotazione_Esterna
    := 1;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      Richieste_Salita : Richieste;
      Richieste_Discesa : Richieste;
      Display : Tastierino;
      Info : GestionePiani;
      Flag : BOOL := 0;
    END_VAR
    TASK loop(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH loop : Sensori_Piani;
    PROGRAM instance3 WITH loop : Prenotazioni_Esterne;
    PROGRAM instance2 WITH loop : Gestione_Motore;
    PROGRAM instance1 WITH loop : Prenotazioni_Interne;
  END_RESOURCE
END_CONFIGURATION
