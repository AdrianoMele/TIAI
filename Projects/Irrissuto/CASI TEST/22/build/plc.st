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


FUNCTION_BLOCK TP_WITH_RESET
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
    RESET : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    ET : TIME := T#0s;
  END_VAR
  VAR
    STATE : SINT := 0;
    PREV_IN : BOOL := FALSE;
    CURRENT_TIME : TIME;
    START_TIME : TIME;
  END_VAR

  (* Pragma to set current time *)
  {__SET_VAR(data__->,CURRENT_TIME,,__CURRENT_TIME)}

  (*Timer block code *)
  IF ((STATE = 0) AND NOT(PREV_IN) AND IN) THEN  (* found rising edge on IN *)
      (* start timer... *)
      STATE := 1;
      Q := TRUE;
      START_TIME := CURRENT_TIME;

  ELSIF (STATE = 1) THEN (* timer counting *)
      IF ((START_TIME + PT) <= CURRENT_TIME) THEN (* timer expired *)
          STATE := 2;
          Q := FALSE;
          ET := PT;
      ELSE (* continue counting *)
          ET := CURRENT_TIME - START_TIME;
      END_IF;
  END_IF;

  IF ((STATE = 2) AND NOT(IN)) THEN
      ET := T#0s;
      STATE := 0;
  END_IF;

  IF (RESET) THEN (* reset pressed *)
    ET := T#0s;
    STATE := 0;
    Q := FALSE;
  END_IF;

  PREV_IN := IN;
END_FUNCTION_BLOCK

FUNCTION_BLOCK RisprmioEnergetico
  VAR_OUTPUT
    Uscita : BOOL := 0;
  END_VAR
  VAR
    aux : BOOL := 0;
  END_VAR
  VAR_INPUT
    Ingresso : BOOL := 0;
    Reset : BOOL := 0;
    Tempo : TIME;
  END_VAR
  VAR
    Tempo2 : TIME := T#4s;
    TP_WITH_RESET0 : TP_WITH_RESET;
    TP_WITH_RESET1 : TP_WITH_RESET;
    R_TRIG1 : R_TRIG;
    F_TRIG1 : F_TRIG;
  END_VAR

  R_TRIG1(CLK := Ingresso);
  TP_WITH_RESET0(IN := R_TRIG1.Q, PT := Tempo, RESET := Reset);
  aux := TP_WITH_RESET0.Q;
  F_TRIG1(CLK := aux);
  TP_WITH_RESET1(IN := F_TRIG1.Q, PT := Tempo2, RESET := Reset);
  Uscita := TP_WITH_RESET1.Q;
END_FUNCTION_BLOCK

FUNCTION_BLOCK Nastro1
  VAR_INPUT
    TempoEsecuzione : TIME;
  END_VAR
  VAR
    TempoInterno : TIME := T#2s;
  END_VAR
  VAR_INPUT
    Ingresso : BOOL := 0;
    reset : BOOL := 0;
  END_VAR
  VAR_OUTPUT
    UscitaNastro : BOOL := 0;
  END_VAR
  VAR
    aux : BOOL;
    TP_WITH_RESET1 : TP_WITH_RESET;
    TP_WITH_RESET2 : TP_WITH_RESET;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    F_TRIG1 : F_TRIG;
    R_TRIG3 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := Ingresso);
  R_TRIG2(CLK := reset);
  TP_WITH_RESET2(IN := R_TRIG1.Q, PT := TempoInterno, RESET := R_TRIG2.Q);
  aux := TP_WITH_RESET2.Q;
  F_TRIG1(CLK := aux);
  R_TRIG3(CLK := reset);
  TP_WITH_RESET1(IN := F_TRIG1.Q, PT := TempoEsecuzione, RESET := R_TRIG3.Q);
  UscitaNastro := TP_WITH_RESET1.Q;
END_FUNCTION_BLOCK

FUNCTION_BLOCK Macchine
  VAR_INPUT
    TempoDiLavorazione : TIME;
    Ingresso : BOOL := 0;
    Reset : BOOL := 0;
  END_VAR
  VAR_OUTPUT
    UscitaMacchina : BOOL := 0;
  END_VAR
  VAR
    TP_WITH_RESET0 : TP_WITH_RESET;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := Ingresso);
  R_TRIG2(CLK := Reset);
  TP_WITH_RESET0(IN := R_TRIG1.Q, PT := TempoDiLavorazione, RESET := R_TRIG2.Q);
  UscitaMacchina := TP_WITH_RESET0.Q AND TP_WITH_RESET0.Q;
END_FUNCTION_BLOCK

FUNCTION_BLOCK AccensioneProgrammata
  VAR
    TP_WITH_RESET0 : TP_WITH_RESET;
    Aux : BOOL;
    Tempo0 : TIME := T#3s;
  END_VAR
  VAR_INPUT
    OreDallAccensione : TIME;
    Ingresso : BOOL;
    Reset : BOOL;
  END_VAR
  VAR_OUTPUT
    UscitaOn : BOOL;
  END_VAR
  VAR
    TP_WITH_RESET1 : TP_WITH_RESET;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    F_TRIG1 : F_TRIG;
    R_TRIG3 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := Ingresso);
  R_TRIG2(CLK := Reset);
  TP_WITH_RESET0(IN := R_TRIG1.Q, PT := OreDallAccensione, RESET := R_TRIG2.Q);
  Aux := TP_WITH_RESET0.Q;
  F_TRIG1(CLK := Aux);
  R_TRIG3(CLK := Reset);
  TP_WITH_RESET1(IN := F_TRIG1.Q, PT := Tempo0, RESET := R_TRIG3.Q);
  UscitaOn := TP_WITH_RESET1.Q;
END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    TastoOn : BOOL := 0;
  END_VAR
  VAR RETAIN
    AccensioneMan : BOOL := 0;
    AccensioneAut : BOOL := 0;
  END_VAR
  VAR
    RipristinoX : BOOL := 0;
    RisparmioEnergetico1 : BOOL := 0;
    RisparmioEnergetico2 : BOOL := 0;
    AttivaReset : BOOL := 0;
    AttivaResetRipr : BOOL := 0;
    AttivaReset0 : BOOL := 0;
    AttivaReset2 : BOOL := 0;
    AttivaReset3 : BOOL := 0;
    AttivaReset4 : BOOL := 0;
    AttivaReset5 : BOOL := 0;
    AttivaReset6 : BOOL := 0;
    AttivaReset7 : BOOL := 0;
    TempoAttesa : BOOL := 0;
    TempoAttesa2 : BOOL := 0;
    TempoAttesa3 : BOOL := 0;
    TimeDummy1 : BOOL := 0;
    TimeDummy2 : BOOL := 0;
    TimeDummy3 : BOOL := 0;
    TimeDummy4 : BOOL := 0;
    TimeDummy5 : BOOL := 0;
    TimeDummy6 : BOOL := 0;
    TimeDummy7 : BOOL := 0;
    MacchinaRiscaldata : BOOL := 0;
    Time3 : TIME := T#5s;
    Time5 : TIME := T#7s;
    Time6 : TIME := T#12s;
    Time7 : TIME := T#900s;
    Time8 : TIME := T#1h;
    Time9 : TIME := T#60s;
  END_VAR
  VAR RETAIN
    TempoProgrammato : TIME := T#20s;
  END_VAR
  VAR
    LedVerde : BOOL := 0;
    LedGiallo : BOOL := 0;
    LedBianco : BOOL := 0;
    ErroreMacchina2 : BOOL := 0;
    ErroreMacchina1 : BOOL := 0;
    LedNero : BOOL := 0;
    LedRosso : BOOL := 0;
    TastoCaricoBusta : BOOL := 0;
    TastoOff : BOOL := 0;
    StartLavorazione : BOOL := 0;
    Vano : BOOL := 1;
    TastoEmergenza : BOOL := 1;
    StatoFustellatrice : BOOL := 0;
    StatoStampaACaldo : BOOL := 0;
    Nastro : BOOL := 0;
    SensoreFoil : BOOL := 0;
    SensoreTemp : BOOL := 0;
    SensoreLama : BOOL := 0;
    RisprmioEnergetico1 : RisprmioEnergetico;
    RisprmioEnergetico0 : RisprmioEnergetico;
    Nastro11 : Nastro1;
    Macchine0 : Macchine;
    Macchine1 : Macchine;
    Nastro12 : Nastro1;
    Nastro10 : Nastro1;
    AccensioneProgrammata0 : AccensioneProgrammata;
    Nastro13 : Nastro1;
    TP0 : TP;
    TP1 : TP;
    RisprmioEnergetico2 : RisprmioEnergetico;
    TP2 : TP;
    F_TRIG1 : F_TRIG;
    F_TRIG2 : F_TRIG;
  END_VAR

  INITIAL_STEP Step0:
    ResetVariabili(N);
    SimAccAut(N);
  END_STEP

  ACTION ResetVariabili:
    RisparmioEnergetico1 := NOT(TRUE);
    RisparmioEnergetico2 := NOT(TRUE);
    LedVerde := NOT(TRUE);
    LedBianco := NOT(TRUE);
    LedNero := NOT(TRUE);
    ErroreMacchina1 := NOT(TRUE);
    ErroreMacchina2 := NOT(TRUE);
    TastoOff := NOT(TRUE);
    TastoOn := NOT(TRUE);
    Vano := TRUE;
    StatoStampaACaldo := NOT(TRUE);
    StatoFustellatrice := NOT(TRUE);
    Nastro := NOT(TRUE);
  END_ACTION

  ACTION SimAccAut:
    AccensioneAut := TRUE;
  END_ACTION

  TRANSITION FROM Step0 TO AccensioneManuale
    := AccensioneMan AND NOT(AccensioneAut);
  END_TRANSITION

  STEP AccensioneManuale:
  END_STEP

  TRANSITION FROM AccensioneManuale TO Attesa
    := TastoOn AND NOT(RipristinoX);
  END_TRANSITION

  STEP Attesa:
    LedRosso(S);
    RiscaldamentoMacchina(N);
    AttivaResetRipr(R);
    AttivaReset0(R);
  END_STEP

  ACTION RiscaldamentoMacchina:
    RisprmioEnergetico2(Ingresso := NOT(RipristinoX), Reset := RipristinoX, Tempo := Time9);
    IF RisprmioEnergetico2.Uscita THEN
      MacchinaRiscaldata := TRUE; (*set*)
    END_IF;
  END_ACTION

  TRANSITION FROM Attesa TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  STEP Ripristino:
    LedGiallo(S);
    ResetVariabili(N);
    LedRosso(N);
    RipristinoX(S);
    TempoAttesa(D, T#4s);
  END_STEP

  TRANSITION FROM Ripristino TO Diagnostica
    := TempoAttesa;
  END_TRANSITION

  STEP Diagnostica:
    Vano(R);
    SvuotaNastro(D, T#3s);
    AttivaResetRipr(D, T#17s);
    TempoAttesa2(D, T#20s);
  END_STEP

  ACTION SvuotaNastro:
    Nastro13(TempoEsecuzione := Time6, Ingresso := NOT(AttivaResetRipr), reset := AttivaResetRipr);
    Nastro := Nastro13.UscitaNastro;
  END_ACTION

  TRANSITION FROM Diagnostica TO FineRipristino
    := TempoAttesa2;
  END_TRANSITION

  STEP FineRipristino:
    RipristinoX(R);
    LedRosso(R);
    Vano(S);
    TastoEmergenza(S);
    LedGiallo(R);
    TempoAttesa3(D, T#7s);
  END_STEP

  TRANSITION FROM FineRipristino TO Attesa
    := TempoAttesa3 AND NOT(RipristinoX) AND TastoEmergenza;
  END_TRANSITION

  TRANSITION FROM Attesa TO Contollo_macchina
    := NOT(RipristinoX) AND TastoEmergenza AND MacchinaRiscaldata;
  END_TRANSITION

  STEP Contollo_macchina:
    ControlloLama(N);
    ControlloStampaACaldo(N);
    TastoOn(R);
  END_STEP

  ACTION ControlloLama:
    ErroreMacchina1 := SensoreLama;
    LedNero := SensoreLama;
  END_ACTION

  ACTION ControlloStampaACaldo:
    ErroreMacchina2 := SensoreFoil OR SensoreTemp;
    LedBianco := SensoreTemp AND SensoreFoil;
  END_ACTION

  TRANSITION FROM Contollo_macchina TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM Contollo_macchina TO CaricoBusta
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(ErroreMacchina1) AND NOT(ErroreMacchina2)) ;
  END_TRANSITION

  STEP CaricoBusta:
    LedGiallo(N);
    LedRosso(R);
    AttivaReset6(P);
    Carico_Busta(N);
    TimeDummy1(D, T#20s);
  END_STEP

  ACTION Carico_Busta:
    F_TRIG1(CLK := AttivaReset6);
    RisprmioEnergetico0(Ingresso := F_TRIG1.Q, Reset := AttivaReset6, Tempo := Time9);
    RisparmioEnergetico1 := RisprmioEnergetico0.Uscita;
  END_ACTION

  TRANSITION FROM CaricoBusta TO Ripristino
    := NOT (TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM CaricoBusta TO Step0
    := NOT(RipristinoX) AND(TastoEmergenza AND TastoOff) OR (RisparmioEnergetico1 AND NOT(TastoCaricoBusta));
  END_TRANSITION

  TRANSITION FROM CaricoBusta TO ProntaLavorazione
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(TastoOff) AND TastoCaricoBusta) AND TimeDummy1;
  END_TRANSITION

  STEP ProntaLavorazione:
    LedVerde(N);
    Vano(R);
    AttivaReset7(P);
    Pronta_Lavorazione(N);
    TimeDummy2(D, T#20s);
    StartLavorazione(N);
  END_STEP

  ACTION Pronta_Lavorazione:
    F_TRIG2(CLK := AttivaReset7);
    RisprmioEnergetico1(Ingresso := F_TRIG2.Q, Reset := AttivaReset7, Tempo := Time9);
    RisparmioEnergetico2 := RisprmioEnergetico1.Uscita;
  END_ACTION

  TRANSITION FROM ProntaLavorazione TO Ripristino
    := NOT (TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM ProntaLavorazione TO Step0
    := NOT(RipristinoX) AND(TastoEmergenza AND TastoOff ) OR (TastoEmergenza  AND RisparmioEnergetico2 AND NOT(StartLavorazione));
  END_TRANSITION

  TRANSITION FROM ProntaLavorazione TO PreLavorazione1
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT (TastoOff) AND StartLavorazione) AND TimeDummy2;
  END_TRANSITION

  STEP PreLavorazione1:
    LedRosso(S);
    PreLavorazione1Nastro(N);
    AttivaReset(D, T#10s);
    TimeDummy3(D, T#12s);
  END_STEP

  ACTION PreLavorazione1Nastro:
    Nastro10(TempoEsecuzione := Time3, Ingresso := NOT(AttivaReset), reset := AttivaReset);
    Nastro := Nastro10.UscitaNastro;
  END_ACTION

  TRANSITION FROM PreLavorazione1 TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM PreLavorazione1 TO Fustella
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(Nastro) AND  TimeDummy3);
  END_TRANSITION

  STEP Fustella:
    Vano(S);
    Fustellatrice(D, T#1s);
    AttivaReset2(D, T#10s);
    TimeDummy4(D, T#12s);
  END_STEP

  ACTION Fustellatrice:
    Macchine0(TempoDiLavorazione := Time5, Ingresso := NOT(AttivaReset2), Reset := AttivaReset2);
    StatoFustellatrice := Macchine0.UscitaMacchina;
  END_ACTION

  TRANSITION FROM Fustella TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM Fustella TO PreLavorazione2
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(StatoFustellatrice)  AND TimeDummy4);
  END_TRANSITION

  STEP PreLavorazione2:
    PreLavorazione2Nastro(N);
    AttivaReset3(D, T#10s);
    TimeDummy5(D, T#12s);
  END_STEP

  ACTION PreLavorazione2Nastro:
    Nastro11(TempoEsecuzione := Time5, Ingresso := NOT(AttivaReset3), reset := AttivaReset3);
    Nastro := Nastro11.UscitaNastro;
  END_ACTION

  TRANSITION FROM PreLavorazione2 TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM PreLavorazione2 TO StampaACaldo
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(SensoreTemp) AND NOT(Nastro)  AND TimeDummy5);
  END_TRANSITION

  STEP StampaACaldo:
    StampaCaldo(D, T#1s);
    AttivaReset4(D, T#10s);
    TimeDummy6(D, T#12s);
  END_STEP

  ACTION StampaCaldo:
    Macchine1(TempoDiLavorazione := Time5, Ingresso := NOT(AttivaReset4), Reset := AttivaReset4);
    StatoStampaACaldo := Macchine1.UscitaMacchina;
  END_ACTION

  TRANSITION FROM StampaACaldo TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM StampaACaldo TO PreFineLavorazione
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(StatoStampaACaldo)  AND TimeDummy6);
  END_TRANSITION

  STEP PreFineLavorazione:
    PreFineLavorazioneNastro(N);
    AttivaReset5(D, T#10s);
    TimeDummy7(D, T#12s);
  END_STEP

  ACTION PreFineLavorazioneNastro:
    Nastro12(TempoEsecuzione := Time3, Ingresso := NOT(AttivaReset5), reset := AttivaReset5);
    Nastro := Nastro12.UscitaNastro;
  END_ACTION

  TRANSITION FROM PreFineLavorazione TO FineLavorazione
    := TastoEmergenza AND TimeDummy7;
  END_TRANSITION

  STEP FineLavorazione:
    LedRosso(R);
  END_STEP

  TRANSITION FROM FineLavorazione TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM FineLavorazione TO DisattivazioneMod
    := NOT(RipristinoX) AND(TastoEmergenza AND TastoOff);
  END_TRANSITION

  STEP DisattivazioneMod:
    AccensioneMan(R);
    AccensioneAut(R);
  END_STEP

  TRANSITION FROM DisattivazioneMod TO Step0
    := true;
  END_TRANSITION

  TRANSITION FROM FineLavorazione TO Contollo_macchina
    := NOT(RipristinoX) AND(TastoEmergenza AND NOT(TastoOff) );
  END_TRANSITION

  TRANSITION FROM PreFineLavorazione TO Ripristino
    := NOT(TastoEmergenza);
  END_TRANSITION

  TRANSITION FROM PreLavorazione2 TO Step0
    := NOT(RipristinoX) AND(TastoEmergenza AND SensoreTemp);
  END_TRANSITION

  TRANSITION FROM Step0 TO AccensioneAutomatica
    := AccensioneAut AND NOT(AccensioneMan);
  END_TRANSITION

  STEP AccensioneAutomatica:
    AccProgrammata(N);
  END_STEP

  ACTION AccProgrammata:
    AccensioneProgrammata0(OreDallAccensione := TempoProgrammato, Ingresso := NOT(AttivaReset0), Reset := AttivaReset);
    TastoOn := AccensioneProgrammata0.UscitaOn;
    IF TastoOn THEN
      AttivaReset0 := TRUE; (*set*)
    END_IF;
  END_ACTION

  TRANSITION FROM AccensioneAutomatica TO Attesa
    := TastoOn AND NOT(RipristinoX);
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
