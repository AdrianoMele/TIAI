FUNCTION_BLOCK genera
  VAR_INPUT
    generate : BOOL;
  END_VAR
  VAR
    veicoli : ARRAY [1..10] OF INT;
    current_array_pos : INT := 1;
  END_VAR
  VAR_OUTPUT
    weight : INT;
  END_VAR

  (* Blocco che simula l'ingresso di veicoli di differente peso*)
  (* peso<=250= moto, peso>250 & peso <900= auto, peso>=900=camion*)
  (* Definizione valori array di prova*)

  veicoli[1] := 100;
  veicoli[2] := 1454;
  veicoli[3] := 807;
  veicoli[4] := 252;
  veicoli[5] := 1068;
  veicoli[6] := 908;
  veicoli[7] := 300;
  veicoli[8] := 154;
  veicoli[9] := 603;
  veicoli[10] := 414;

  if (generate=TRUE) then
    weight := veicoli[current_array_pos];
  end_if;

  current_array_pos := current_array_pos + 1;
  (* Evito overflow array*)

  if current_array_pos > 10 then

    current_array_pos := 1;

  end_if;


END_FUNCTION_BLOCK

FUNCTION_BLOCK vehicle_cnt
  VAR_INPUT
    confirm_enter : BOOL := 0;
    confirm_exit : BOOL := 0;
    veicolo_in : REAL;
    veicolo_out : REAL;
  END_VAR
  VAR_OUTPUT
    tot_auto : INT := 0;
    tot_moto : INT := 0;
    tot_camion : INT := 0;
  END_VAR
  VAR
    cap : INT := 4;
    R_TRIG0 : R_TRIG;
    CTUD0 : CTUD;
    CTUD1 : CTUD;
    CTUD2 : CTUD;
    R_TRIG1 : R_TRIG;
    EQ13_ENO : BOOL;
    EQ13_OUT : BOOL;
    R_TRIG2 : R_TRIG;
    EQ26_ENO : BOOL;
    EQ26_OUT : BOOL;
    R_TRIG3 : R_TRIG;
    EQ10_ENO : BOOL;
    EQ10_OUT : BOOL;
    R_TRIG4 : R_TRIG;
    EQ23_ENO : BOOL;
    EQ23_OUT : BOOL;
    R_TRIG5 : R_TRIG;
    EQ14_ENO : BOOL;
    EQ14_OUT : BOOL;
    R_TRIG6 : R_TRIG;
    EQ27_ENO : BOOL;
    EQ27_OUT : BOOL;
    R_TRIG7 : R_TRIG;
  END_VAR

  R_TRIG0(CLK := confirm_enter);
  EQ13_OUT := EQ(EN := R_TRIG0.Q, IN1 := veicolo_in, IN2 := 1.0, ENO => EQ13_ENO);
  R_TRIG2(CLK := EQ13_OUT);
  R_TRIG1(CLK := confirm_exit);
  EQ26_OUT := EQ(EN := R_TRIG1.Q, IN1 := veicolo_out, IN2 := 1.0, ENO => EQ26_ENO);
  R_TRIG3(CLK := EQ26_OUT);
  CTUD0(CU := R_TRIG2.Q, CD := R_TRIG3.Q, PV := cap);
  tot_auto := CTUD0.CV;
  EQ10_OUT := EQ(EN := R_TRIG0.Q, IN1 := veicolo_in, IN2 := 0.50, ENO => EQ10_ENO);
  R_TRIG4(CLK := EQ10_OUT);
  EQ23_OUT := EQ(EN := R_TRIG1.Q, IN1 := veicolo_out, IN2 := 0.50, ENO => EQ23_ENO);
  R_TRIG5(CLK := EQ23_OUT);
  CTUD1(CU := R_TRIG4.Q, CD := R_TRIG5.Q, PV := cap);
  tot_moto := CTUD1.CV;
  EQ14_OUT := EQ(EN := R_TRIG0.Q, IN1 := veicolo_in, IN2 := 2.0, ENO => EQ14_ENO);
  R_TRIG6(CLK := EQ14_OUT);
  EQ27_OUT := EQ(EN := R_TRIG1.Q, IN1 := veicolo_out, IN2 := 2.0, ENO => EQ27_ENO);
  R_TRIG7(CLK := EQ27_OUT);
  CTUD2(CU := R_TRIG6.Q, CD := R_TRIG7.Q, PV := cap);
  tot_camion := CTUD2.CV;
END_FUNCTION_BLOCK

FUNCTION_BLOCK gettoniera
  VAR_INPUT
    enable : BOOL := 0;
    euro_1 : BOOL := 0;
    euro_2 : BOOL := 0;
    euro_50c : BOOL := 0;
    ore : BOOL := 0;
    tariffa : REAL := 1.0;
  END_VAR
  VAR
    tot : REAL := 0.0;
    prc : REAL := 1.0;
  END_VAR
  VAR_OUTPUT
    prezzo : REAL := 1.0;
    tot_mon : REAL := 0.0;
    hrs : INT := 0;
  END_VAR
  VAR
    ora : INT := 1;
  END_VAR
  VAR_OUTPUT
    apri_sbarra : BOOL := 0;
  END_VAR
  VAR
    R_TRIG0 : R_TRIG;
    R_TRIG1 : R_TRIG;
  END_VAR
  VAR_OUTPUT
    resto : REAL := 0.0;
  END_VAR
  VAR
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    CTUD0 : CTUD;
    R_TRIG5 : R_TRIG;
    MUL182_OUT : REAL;
    ADD185_OUT : REAL;
    GE14_ENO : BOOL;
    GE14_OUT : BOOL;
    R_TRIG6 : R_TRIG;
    BOOL_TO_REAL108_OUT : REAL;
    BOOL_TO_REAL109_OUT : REAL;
    MUL121_OUT : REAL;
    BOOL_TO_REAL150_OUT : REAL;
    MUL151_OUT : REAL;
    ADD16_ENO : BOOL;
    ADD16_OUT : REAL;
    R_TRIG7 : R_TRIG;
    SUB171_ENO : BOOL;
    SUB171_OUT : REAL;
    MOVE134_ENO : BOOL;
    MOVE134_OUT : REAL;
    MOVE165_ENO : BOOL;
    MOVE165_OUT : INT;
    LIMIT200_OUT : INT;
    INT_TO_REAL181_OUT : REAL;
    BOOL_TO_INT161_ENO : BOOL;
    BOOL_TO_INT161_OUT : INT;
    ADD168_OUT : INT;
  END_VAR

  R_TRIG4(CLK := enable);
  R_TRIG5(CLK := R_TRIG4.Q);
  MUL182_OUT := MUL(prc, tariffa);
  ADD185_OUT := ADD(MUL182_OUT, 1.0);
  GE14_OUT := GE(EN := CTUD0.QU, IN1 := tot, IN2 := ADD185_OUT, ENO => GE14_ENO);
  R_TRIG6(CLK := GE14_OUT);
  CTUD0(CU := R_TRIG5.Q, CD := R_TRIG6.Q, PV := 1);
  R_TRIG0(CLK := euro_1);
  BOOL_TO_REAL108_OUT := BOOL_TO_REAL(R_TRIG0.Q);
  R_TRIG1(CLK := euro_2);
  BOOL_TO_REAL109_OUT := BOOL_TO_REAL(R_TRIG1.Q);
  MUL121_OUT := MUL(BOOL_TO_REAL109_OUT, 2.0);
  R_TRIG2(CLK := euro_50c);
  BOOL_TO_REAL150_OUT := BOOL_TO_REAL(R_TRIG2.Q);
  MUL151_OUT := MUL(BOOL_TO_REAL150_OUT, 0.5);
  ADD16_OUT := ADD(EN := CTUD0.QU, IN1 := BOOL_TO_REAL108_OUT, IN2 := MUL121_OUT, IN3 := MUL151_OUT, IN4 := tot, ENO => ADD16_ENO);
  IF ADD16_ENO THEN
      tot := ADD16_OUT;
  END_IF;
  R_TRIG7(CLK := GE14_OUT);
  apri_sbarra := R_TRIG7.Q;
  IF ADD16_ENO THEN
      tot_mon := ADD16_OUT;
  END_IF;
  SUB171_OUT := SUB(EN := GE14_OUT, IN1 := tot, IN2 := prezzo, ENO => SUB171_ENO);
  MOVE134_OUT := MOVE(EN := SUB171_ENO, IN := 0.0, ENO => MOVE134_ENO);
  IF MOVE134_ENO THEN
      tot := MOVE134_OUT;
  END_IF;
  prezzo := ADD185_OUT;
  IF MOVE134_ENO THEN
      tot_mon := MOVE134_OUT;
  END_IF;
  MOVE165_OUT := MOVE(EN := SUB171_ENO, IN := 1, ENO => MOVE165_ENO);
  IF MOVE165_ENO THEN
      ora := MOVE165_OUT;
  END_IF;
  LIMIT200_OUT := LIMIT(1, ora, 6);
  INT_TO_REAL181_OUT := INT_TO_REAL(LIMIT200_OUT);
  prc := INT_TO_REAL181_OUT;
  IF SUB171_ENO THEN
      resto := SUB171_OUT;
  END_IF;
  hrs := LIMIT200_OUT;
  R_TRIG3(CLK := ore);
  BOOL_TO_INT161_OUT := BOOL_TO_INT(EN := CTUD0.QU, IN := R_TRIG3.Q, ENO => BOOL_TO_INT161_ENO);
  ADD168_OUT := ADD(BOOL_TO_INT161_OUT, ora);
  ora := ADD168_OUT;
END_FUNCTION_BLOCK

FUNCTION_BLOCK vehicle_sel
  VAR_INPUT
    invio : BOOL := 0;
    slct : BOOL := 0;
    weight : INT;
  END_VAR
  VAR_OUTPUT
    abilita : BOOL;
    cat : STRING;
  END_VAR
  VAR
    veicleDetect : INT;
  END_VAR
  VAR_OUTPUT
    veicolo : REAL := 1.0;
  END_VAR
  VAR
    tipo : INT := 0;
    auto : REAL := 1.0;
    moto : REAL := 0.50;
    camion : REAL := 2.00;
    R_TRIG0 : R_TRIG;
    GT59_OUT : BOOL;
    LE39_OUT : BOOL;
    AND61_OUT : BOOL;
    BOOL_TO_INT49_OUT : INT;
    MOVE63_ENO : BOOL;
    MOVE63_OUT : INT;
    GT42_OUT : BOOL;
    LE45_OUT : BOOL;
    AND44_OUT : BOOL;
    BOOL_TO_INT2_OUT : INT;
    MUL50_OUT : INT;
    MOVE64_ENO : BOOL;
    MOVE64_OUT : INT;
    GT47_OUT : BOOL;
    BOOL_TO_INT3_OUT : INT;
    MUL5_OUT : INT;
    MOVE66_ENO : BOOL;
    MOVE66_OUT : INT;
    EQ56_ENO : BOOL;
    EQ56_OUT : BOOL;
    MUX1_ENO : BOOL;
    MUX1_OUT : REAL;
    BOOL_TO_INT19_OUT : INT;
    ADD20_OUT : INT;
    MUX32_OUT : STRING;
    EQ25_OUT : BOOL;
    MOVE27_ENO : BOOL;
    MOVE27_OUT : INT;
  END_VAR

  GT59_OUT := GT(weight, 0);
  LE39_OUT := LE(weight, 250);
  AND61_OUT := AND(GT59_OUT, LE39_OUT);
  BOOL_TO_INT49_OUT := BOOL_TO_INT(AND61_OUT);
  MOVE63_OUT := MOVE(EN := AND61_OUT, IN := BOOL_TO_INT49_OUT, ENO => MOVE63_ENO);
  IF MOVE63_ENO THEN
      veicleDetect := MOVE63_OUT;
  END_IF;
  GT42_OUT := GT(weight, 250);
  LE45_OUT := LE(weight, 900);
  AND44_OUT := AND(GT42_OUT, LE45_OUT);
  BOOL_TO_INT2_OUT := BOOL_TO_INT(AND44_OUT);
  MUL50_OUT := MUL(BOOL_TO_INT2_OUT, 0);
  MOVE64_OUT := MOVE(EN := AND44_OUT, IN := MUL50_OUT, ENO => MOVE64_ENO);
  IF MOVE64_ENO THEN
      veicleDetect := MOVE64_OUT;
  END_IF;
  GT47_OUT := GT(weight, 900);
  BOOL_TO_INT3_OUT := BOOL_TO_INT(GT47_OUT);
  MUL5_OUT := MUL(BOOL_TO_INT3_OUT, 2);
  MOVE66_OUT := MOVE(EN := GT47_OUT, IN := MUL5_OUT, ENO => MOVE66_ENO);
  IF MOVE66_ENO THEN
      veicleDetect := MOVE66_OUT;
  END_IF;
  EQ56_OUT := EQ(EN := invio, IN1 := veicleDetect, IN2 := tipo, ENO => EQ56_ENO);
  MUX1_OUT := MUX(EN := EQ56_OUT, K := tipo, IN0 := auto, IN1 := moto, IN2 := camion, ENO => MUX1_ENO);
  abilita := MUX1_ENO;
  IF MUX1_ENO THEN
      veicolo := MUX1_OUT;
  END_IF;
  R_TRIG0(CLK := slct);
  BOOL_TO_INT19_OUT := BOOL_TO_INT(R_TRIG0.Q);
  ADD20_OUT := ADD(BOOL_TO_INT19_OUT, tipo);
  tipo := ADD20_OUT;
  MUX32_OUT := MUX(tipo, 'auto', 'moto', 'camion');
  cat := MUX32_OUT;
  EQ25_OUT := EQ(tipo, 3);
  MOVE27_OUT := MOVE(EN := EQ25_OUT, IN := 0, ENO => MOVE27_ENO);
  IF MOVE27_ENO THEN
      tipo := MOVE27_OUT;
  END_IF;
END_FUNCTION_BLOCK

FUNCTION_BLOCK exit_sel
  VAR_INPUT
    confirm : BOOL := 0;
    slct : BOOL := 0;
  END_VAR
  VAR_OUTPUT
    veicolo : REAL;
  END_VAR
  VAR
    auto : REAL := 1.0;
    moto : REAL := 0.50;
    camion : REAL := 2.0;
  END_VAR
  VAR_OUTPUT
    ok_exit : BOOL := 0;
    cat : STRING;
  END_VAR
  VAR
    tipo : INT;
    R_TRIG0 : R_TRIG;
    MUX1_ENO : BOOL;
    MUX1_OUT : REAL;
    BOOL_TO_INT19_OUT : INT;
    ADD20_OUT : INT;
    MUX32_OUT : STRING;
    EQ25_OUT : BOOL;
    MOVE27_ENO : BOOL;
    MOVE27_OUT : INT;
  END_VAR

  MUX1_OUT := MUX(EN := confirm, K := tipo, IN0 := auto, IN1 := moto, IN2 := camion, ENO => MUX1_ENO);
  IF MUX1_ENO THEN
      veicolo := MUX1_OUT;
  END_IF;
  ok_exit := confirm;
  R_TRIG0(CLK := slct);
  BOOL_TO_INT19_OUT := BOOL_TO_INT(R_TRIG0.Q);
  ADD20_OUT := ADD(BOOL_TO_INT19_OUT, tipo);
  tipo := ADD20_OUT;
  MUX32_OUT := MUX(tipo, 'auto', 'moto', 'camion');
  cat := MUX32_OUT;
  EQ25_OUT := EQ(tipo, 3);
  MOVE27_OUT := MOVE(EN := EQ25_OUT, IN := 0, ENO => MOVE27_ENO);
  IF MOVE27_ENO THEN
      tipo := MOVE27_OUT;
  END_IF;
END_FUNCTION_BLOCK

FUNCTION_BLOCK park_stats
  VAR_INPUT
    en_calc : BOOL := 0;
    guad : REAL;
    tot_auto1 : INT;
    tot_moto1 : INT;
    tot_camion1 : INT;
    tot_auto2 : INT;
    tot_moto2 : INT;
    tot_camion2 : INT;
  END_VAR
  VAR_OUTPUT
    tot_auto : INT := 0;
    tot_moto : INT := 0;
    tot_camion : INT := 0;
    incasso : REAL := 0.0;
    daily_vhcl : INT := 0;
  END_VAR
  VAR
    R_TRIG0 : R_TRIG;
    ADD16_ENO : BOOL;
    ADD16_OUT : REAL;
    ADD1_OUT : INT;
    BOOL_TO_INT22_OUT : INT;
    ADD20_OUT : INT;
    ADD2_OUT : INT;
    ADD3_OUT : INT;
  END_VAR

  R_TRIG0(CLK := en_calc);
  ADD16_OUT := ADD(EN := R_TRIG0.Q, IN1 := guad, IN2 := incasso, ENO => ADD16_ENO);
  IF ADD16_ENO THEN
      incasso := ADD16_OUT;
  END_IF;
  ADD1_OUT := ADD(tot_auto1, tot_auto2);
  tot_auto := ADD1_OUT;
  BOOL_TO_INT22_OUT := BOOL_TO_INT(R_TRIG0.Q);
  ADD20_OUT := ADD(BOOL_TO_INT22_OUT, daily_vhcl);
  daily_vhcl := ADD20_OUT;
  ADD2_OUT := ADD(tot_moto1, tot_moto2);
  tot_moto := ADD2_OUT;
  ADD3_OUT := ADD(tot_camion1, tot_camion2);
  tot_camion := ADD3_OUT;
END_FUNCTION_BLOCK

PROGRAM parking
  VAR
    start : BOOL := 0;
  END_VAR
  VAR_INPUT
    gen : BOOL := 0;
  END_VAR
  VAR
    slct : BOOL := 0;
  END_VAR
  VAR_INPUT
    conferma : BOOL := 0;
    cent_50 : BOOL := 0;
    euro_1 : BOOL := 0;
    euro_2 : BOOL := 0;
    ora : BOOL := 0;
    slct_exit1 : BOOL := 0;
    slct_exit2 : BOOL := 0;
    conf1 : BOOL := 0;
    conf2 : BOOL := 0;
  END_VAR
  VAR_OUTPUT
    resto : REAL := 0.0;
    prezzo : REAL := 0.0;
  END_VAR
  VAR
    stop : BOOL := 0;
    cap : INT := 4;
    sbarra1 : BOOL := 0;
    sbarra2 : BOOL := 0;
  END_VAR
  VAR_INPUT
    sbarra1_man : BOOL := 0;
    sbarra1_exit : BOOL := 0;
    sbarra2_man : BOOL := 0;
    sbarra2_exit : BOOL := 0;
  END_VAR
  VAR
    enter_1 : BOOL := 0;
    piano1_full : BOOL := 0;
    piano2_full : BOOL := 0;
    exit_1 : BOOL := 0;
  END_VAR
  VAR_OUTPUT
    exit_2 : BOOL := 0;
    enter_2 : BOOL := 0;
    park_full : BOOL := 0;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR
  VAR_INPUT
    temp1 : TIME := T#2s;
    temp2 : TIME := T#4s;
    temp3 : TIME := T#1s;
  END_VAR
  VAR
    CTUD0 : CTUD;
    exit1_en : BOOL := 0;
    exit2_en : BOOL := 0;
    TON1 : TON;
    TON2 : TON;
    CTUD1 : CTUD;
    TON3 : TON;
    TOF1 : TOF;
    gettoniera0 : gettoniera;
    vehicle_sel0 : vehicle_sel;
    vehicle_cnt0 : vehicle_cnt;
    exit_sel0 : exit_sel;
    vehicle_cnt1 : vehicle_cnt;
    exit_sel1 : exit_sel;
    park_stats0 : park_stats;
    genera0 : genera;
    R_TRIG0 : R_TRIG;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    AND127_OUT : BOOL;
  END_VAR

  R_TRIG0(CLK := gen);
  genera0(generate := R_TRIG0.Q);
  vehicle_sel0(invio := conferma AND NOT(stop) AND start, slct := slct AND NOT(stop) AND start, weight := genera0.weight);
  gettoniera0(enable := vehicle_sel0.abilita, euro_1 := euro_1 AND NOT(stop) AND start, euro_2 := euro_2 AND NOT(stop) AND start, euro_50c := cent_50 AND NOT(stop) AND start, ore := ora AND NOT(stop) AND start, tariffa := vehicle_sel0.veicolo);
  IF NOT(piano1_full) AND gettoniera0.apri_sbarra OR sbarra1_man THEN
    sbarra1 := TRUE; (*set*)
  END_IF;
  prezzo := gettoniera0.prezzo;
  IF piano1_full AND gettoniera0.apri_sbarra OR sbarra2_man THEN
    sbarra2 := TRUE; (*set*)
  END_IF;
  resto := gettoniera0.resto;
  TON0(IN := sbarra1, PT := temp1);
  enter_1 := TON0.Q;
  IF enter_1 THEN
    sbarra1 := FALSE; (*reset*)
  END_IF;
  exit1_en := enter_1;
  R_TRIG1(CLK := enter_1);
  R_TRIG2(CLK := exit_1);
  CTUD0(CU := R_TRIG1.Q, CD := R_TRIG2.Q, PV := cap);
  IF CTUD0.QU THEN
    sbarra1 := FALSE; (*reset*)
  END_IF;
  IF CTUD0.QU THEN
    piano1_full := TRUE; (*set*)
  END_IF;
  exit1_en := NOT(CTUD0.QD);
  exit_sel0(confirm := conf1 AND exit1_en, slct := slct_exit1 AND exit1_en);
  TON1(IN := sbarra1_exit AND exit_sel0.ok_exit, PT := temp1);
  exit_1 := TON1.Q;
  IF TON1.Q THEN
    piano1_full := FALSE; (*reset*)
  END_IF;
  TON2(IN := piano1_full AND sbarra2, PT := temp2);
  enter_2 := TON2.Q;
  IF enter_2 THEN
    sbarra2 := FALSE; (*reset*)
  END_IF;
  exit2_en := enter_2;
  R_TRIG3(CLK := enter_2);
  R_TRIG4(CLK := exit_2);
  CTUD1(CU := R_TRIG3.Q, CD := R_TRIG4.Q, PV := cap);
  IF CTUD1.QU THEN
    piano2_full := TRUE; (*set*)
  END_IF;
  exit2_en := NOT(CTUD1.QD);
  exit_sel1(confirm := conf2 AND exit2_en, slct := slct_exit2 AND exit2_en);
  TON3(IN := sbarra2_exit AND exit_sel1.ok_exit, PT := temp2);
  exit_2 := TON3.Q;
  TOF1(IN := TON3.Q, PT := temp1);
  IF TOF1.Q THEN
    piano2_full := FALSE; (*reset*)
  END_IF;
  AND127_OUT := AND(piano1_full, piano2_full);
  stop := AND127_OUT;
  vehicle_cnt0(confirm_enter := enter_1, confirm_exit := exit_1, veicolo_in := vehicle_sel0.veicolo, veicolo_out := exit_sel0.veicolo);
  vehicle_cnt1(confirm_enter := enter_2, confirm_exit := exit_2, veicolo_in := vehicle_sel0.veicolo, veicolo_out := exit_sel1.veicolo);
  park_stats0(en_calc := gettoniera0.apri_sbarra, guad := prezzo, tot_auto1 := vehicle_cnt0.tot_auto, tot_moto1 := vehicle_cnt0.tot_moto, tot_camion1 := vehicle_cnt0.tot_camion, tot_auto2 := vehicle_cnt1.tot_auto, tot_moto2 := vehicle_cnt1.tot_moto, tot_camion2 := vehicle_cnt1.tot_camion);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : parking;
  END_RESOURCE
END_CONFIGURATION
