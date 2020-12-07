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


PROGRAM autoMode
  VAR_EXTERNAL
    auto : BOOL;
    startLight : BOOL;
    setpointVal : INT;
    levelVal : INT;
    fillValve : INT;
    dischargeValve : INT;
    KpVal : INT;
    KiVal : INT;
    KdVal : INT;
  END_VAR
  VAR
    Kp_internal : REAL;
    Ki_internal : REAL;
    Kd_internal : REAL;
    Ti_internal : REAL;
    Td_internal : REAL;
    setpoint_internal : REAL;
    level_internal : REAL;
    cycle : TIME := T#20ms;
    PID_level : PID;
    control : REAL;
    Kpmax : REAL := 100.0;
    Kimax : REAL := 0.1;
    Kdmax : REAL := 10.0;
  END_VAR

  Kp_internal := INT_TO_REAL(KpVal)/100.0*Kpmax;
  Ki_internal := INT_TO_REAL(KiVal)/100.0*Kimax;
  Kd_internal := INT_TO_REAL(KdVal)/100.0*Kdmax;

  setpoint_internal := INT_TO_REAL(setpointVal);
  level_internal := INT_TO_REAL(levelVal);

  IF GT(Ki_internal,0.0) THEN
    Ti_internal := Kp_internal/Ki_internal;
  ELSE
    Ti_internal := 100000000000000000.0; (* just a very big number to put Ki = 0 *)
  END_IF;

  IF GT(Kd_internal,0.0) THEN
    Td_internal := Kd_internal/Kp_internal;
  ELSE
    Td_internal := 0.0;
  END_IF;

  PID_level(
       AUTO := auto,
       PV := level_internal, (* process variable *)
       SP := setpoint_internal,
       X0 := 0.0, (* default when auto=false *)
       KP := Kp_internal,
       TR := Ti_internal,
       TD := Td_internal,
       CYCLE := cycle,
       XOUT => control);

  control := - control; (* OpenPLC does PV-SP *)
  IF auto&startLight THEN
    IF GT(control, 0.0) THEN
      fillValve := REAL_TO_INT(control);
      dischargeValve := 0;
    ELSE
      fillValve := 0;
      dischargeValve := REAL_TO_INT(-control);
    END_IF;

  END_IF;
END_PROGRAM

PROGRAM manageDisplays
  VAR_EXTERNAL
    levelMeter : INT;
    flowMeter : INT;
    setpoint : INT;
    Kp : INT;
    Ki : INT;
    Kd : INT;
    dischargeValve : INT;
    dischargeValvePos : INT;
    fillValve : INT;
    fillValvePos : INT;
    KpVal : INT;
    KiVal : INT;
    KdVal : INT;
    setpointVal : INT;
    errorVal : INT;
    levelVal : INT;
  END_VAR
  VAR
    levelConvFactor : REAL := 3.34;
    setpointConvFactor : REAL := 3.34;
    KpConvFactor : INT := 10;
    KiConvFactor : INT := 10;
    KdConvFactor : INT := 10;
  END_VAR

  dischargeValvePos := dischargeValve;
  fillValvePos := fillValve;
  KpVal := Kp/KpConvFactor;
  KiVal := Ki/KiConvFactor;
  KdVal := Kd/KdConvFactor;
  setpointVal := REAL_TO_INT(DIV(INT_TO_REAL(setpoint), setpointConvFactor));
  levelVal := REAL_TO_INT(DIV(INT_TO_REAL(levelMeter), levelConvFactor));
  errorVal := setpointVal - levelVal;
END_PROGRAM

PROGRAM manualMode
  VAR_EXTERNAL
    manual : BOOL;
    startLight : BOOL;
    stopLight : BOOL;
    fillManualLight : BOOL;
    dischargeManualLight : BOOL;
    fillValve : INT;
    dischargeValve : INT;
  END_VAR

  IF manual&startLight THEN
    IF fillManualLight THEN
      fillValve := 10*100;
    ELSE
      fillValve := 0; 
    END_IF;
    
    IF dischargeManualLight THEN
      dischargeValve := 10*100;
    ELSE
      dischargeValve := 0; 
    END_IF;

  ELSIF manual&stopLight THEN
    fillValve := 0;
    dischargeValve := 0;
  END_IF;
END_PROGRAM

PROGRAM manageLights
  VAR_EXTERNAL
    startButton : BOOL;
    stopButton : BOOL;
    startLight : BOOL;
    stopLight : BOOL;
    fillValveMan : BOOL;
    dischargeValveMan : BOOL;
    fillManualLight : BOOL;
    dischargeManualLight : BOOL;
    manual : BOOL;
  END_VAR
  VAR
    aux1 : BOOL;
    aux2 : BOOL;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    F_TRIG1 : F_TRIG;
    R_TRIG5 : R_TRIG;
    F_TRIG2 : F_TRIG;
    R_TRIG6 : R_TRIG;
    R_TRIG7 : R_TRIG;
    R_TRIG8 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := startButton);
  IF R_TRIG1.Q THEN
    startLight := TRUE; (*set*)
  END_IF;
  R_TRIG2(CLK := fillValveMan);
  aux1 := fillManualLight AND R_TRIG2.Q AND manual;
  R_TRIG3(CLK := startButton);
  IF R_TRIG3.Q THEN
    stopLight := FALSE; (*reset*)
  END_IF;
  R_TRIG4(CLK := fillValveMan);
  IF fillManualLight AND R_TRIG4.Q AND manual THEN
    fillManualLight := FALSE; (*reset*)
  END_IF;
  F_TRIG1(CLK := stopButton);
  IF F_TRIG1.Q THEN
    stopLight := TRUE; (*set*)
  END_IF;
  R_TRIG5(CLK := fillValveMan);
  IF NOT(aux1) AND NOT(fillManualLight) AND R_TRIG5.Q AND manual THEN
    fillManualLight := TRUE; (*set*)
  END_IF;
  F_TRIG2(CLK := stopButton);
  IF F_TRIG2.Q THEN
    startLight := FALSE; (*reset*)
  END_IF;
  R_TRIG6(CLK := dischargeValveMan);
  aux2 := dischargeManualLight AND R_TRIG6.Q AND manual;
  R_TRIG7(CLK := dischargeValveMan);
  IF dischargeManualLight AND R_TRIG7.Q AND manual THEN
    dischargeManualLight := FALSE; (*reset*)
  END_IF;
  R_TRIG8(CLK := dischargeValveMan);
  IF NOT(aux2) AND NOT(dischargeManualLight) AND R_TRIG8.Q AND manual THEN
    dischargeManualLight := TRUE; (*set*)
  END_IF;
  IF NOT(manual) THEN
    dischargeManualLight := FALSE; (*reset*)
  END_IF;
  IF NOT(manual) THEN
    fillManualLight := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      startButton : BOOL;
      stopButton : BOOL;
      manual : BOOL;
      auto : BOOL;
      fillValveMan : BOOL;
      dischargeValveMan : BOOL;
      startLight : BOOL;
      stopLight : BOOL;
      fillManualLight : BOOL;
      dischargeManualLight : BOOL;
      levelMeter : INT;
      flowMeter : INT;
      setpoint : INT;
      Kp : INT;
      Ki : INT;
      Kd : INT;
      dischargeValve : INT;
      dischargeValvePos : INT;
      fillValve : INT;
      fillValvePos : INT;
      KpVal : INT;
      KiVal : INT;
      KdVal : INT;
      setpointVal : INT;
      errorVal : INT;
      levelVal : INT;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task1(INTERVAL := T#200ms,PRIORITY := 2);
    PROGRAM instance1 WITH task0 : manageDisplays;
    PROGRAM instance2 WITH task0 : manualMode;
    PROGRAM instance3 WITH task0 : autoMode;
    PROGRAM instance0 WITH task1 : manageLights;
  END_RESOURCE
END_CONFIGURATION
