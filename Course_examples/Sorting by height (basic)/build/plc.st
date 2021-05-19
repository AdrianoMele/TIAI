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


PROGRAM manageButtonLights
  VAR_EXTERNAL
    startButton : BOOL;
    resetButton : BOOL;
    stopButton : BOOL;
    stopInternal : BOOL;
    startLight : BOOL;
    resetLight : BOOL;
    stopLight : BOOL;
    emergencyStop : BOOL;
  END_VAR
  VAR
    R_TRIG1 : R_TRIG;
    F_TRIG1 : F_TRIG;
    F_TRIG2 : F_TRIG;
    R_TRIG2 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := startButton);
  IF emergencyStop AND R_TRIG1.Q THEN
    startLight := TRUE; (*set*)
  END_IF;
  F_TRIG1(CLK := stopButton);
  IF F_TRIG1.Q OR stopInternal THEN
    stopLight := TRUE; (*set*)
  END_IF;
  F_TRIG2(CLK := stopButton);
  IF F_TRIG2.Q OR stopInternal THEN
    startLight := FALSE; (*reset*)
  END_IF;
  R_TRIG2(CLK := startButton);
  IF emergencyStop AND R_TRIG2.Q THEN
    stopLight := FALSE; (*reset*)
  END_IF;
  resetLight := stopLight AND resetButton;
END_PROGRAM

FUNCTION_BLOCK doubleTrig
  VAR_INPUT
    in : BOOL;
  END_VAR
  VAR_OUTPUT
    out : BOOL;
  END_VAR
  VAR
    aux : BOOL := false;
    F_TRIG1 : F_TRIG;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
  END_VAR

  F_TRIG1(CLK := in);
  IF F_TRIG1.Q THEN
    aux := TRUE; (*set*)
  END_IF;
  R_TRIG1(CLK := in);
  out := aux AND R_TRIG1.Q;
  R_TRIG2(CLK := in);
  IF aux AND R_TRIG2.Q THEN
    aux := FALSE; (*reset*)
  END_IF;
END_FUNCTION_BLOCK

PROGRAM main
  VAR_EXTERNAL
    highSens : BOOL;
    lowSens : BOOL;
    palletSens : BOOL;
    loaded : BOOL;
    leftEntry : BOOL;
    leftExit : BOOL;
    rightEntry : BOOL;
    rightExit : BOOL;
    startButton : BOOL;
    resetButton : BOOL;
    stopButton : BOOL;
    stopInternal : BOOL;
    resetInternal : BOOL;
    stopLight : BOOL;
    startLight : BOOL;
    emergencyStop : BOOL;
    autoMode : BOOL;
    convEntry : BOOL;
    load : BOOL;
    unload : BOOL;
    transfLeft : BOOL;
    transfRight : BOOL;
    convLeft : BOOL;
    convRight : BOOL;
    warnLight : BOOL;
  END_VAR
  VAR
    palletMaxWait : BOOL;
    R_TRIG1 : R_TRIG;
    F_TRIG1 : F_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    R_TRIG5 : R_TRIG;
    R_TRIG6 : R_TRIG;
  END_VAR

  INITIAL_STEP START:
    convLeft(R);
    convRight(R);
    stopInternal(R);
    warnLight(R);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    R_TRIG1(CLK := rightEntry);
    F_TRIG1(CLK := stopButton);
    R_TRIG2(CLK := rightEntry);
    R_TRIG3(CLK := rightExit);
    R_TRIG4(CLK := leftEntry);
    R_TRIG5(CLK := leftEntry);
    R_TRIG6(CLK := leftExit);
  END_ACTION

  TRANSITION FROM START TO moveConveyors
    := startLight AND emergencyStop AND NOT(loaded);
  END_TRANSITION

  STEP moveConveyors:
    convEntry(N);
    load(N);
    convLeft(S);
    convRight(S);
  END_STEP

  TRANSITION FROM moveConveyors TO checkBox
    := palletSens AND emergencyStop;
  END_TRANSITION

  STEP checkBox:
    convEntry(N);
    load(N);
    palletMaxWait(D, T#2s);
  END_STEP

  TRANSITION FROM checkBox TO error
    := (palletMaxWait OR loaded) AND NOT(lowSens) AND emergencyStop;
  END_TRANSITION

  STEP error:
    warnLight(S);
    stopInternal(S);
  END_STEP

  TRANSITION FROM error TO START
    := NOT(palletSens OR loaded);
  END_TRANSITION

  TRANSITION FROM checkBox TO lowBox
    := lowSens AND NOT(highSens) AND emergencyStop;
  END_TRANSITION

  STEP lowBox:
    convEntry(N);
    load(N);
  END_STEP

  TRANSITION FROM lowBox TO goRight
    := loaded AND autoMode;
  END_TRANSITION

  STEP goRight:
    transfRight(N);
  END_STEP

  TRANSITION FROM goRight TO moveConveyors
    := emergencyStop AND R_TRIG1.Q AND NOT(stopLight);
  END_TRANSITION

  TRANSITION FROM goRight TO waitRight
    := emergencyStop AND stopLight AND R_TRIG2.Q;
  END_TRANSITION

  STEP waitRight:
  END_STEP

  TRANSITION FROM waitRight TO START
    := R_TRIG3.Q;
  END_TRANSITION

  TRANSITION FROM waitRight TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  STEP FAULT:
    load(R);
    unload(R);
    convLeft(R);
    convRight(R);
    convEntry(R);
    stopInternal(S);
    warnLight(S);
  END_STEP

  TRANSITION FROM FAULT TO START
    := emergencyStop;
  END_TRANSITION

  TRANSITION FROM goRight TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM lowBox TO wait
    := loaded AND NOT(autoMode);
  END_TRANSITION

  STEP wait:
  END_STEP

  TRANSITION FROM wait TO moveConveyors
    := NOT(loaded) AND emergencyStop;
  END_TRANSITION

  TRANSITION FROM wait TO START
    := stopLight AND emergencyStop;
  END_TRANSITION

  TRANSITION FROM wait TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM checkBox TO highBox
    := lowSens AND highSens AND emergencyStop;
  END_TRANSITION

  STEP highBox:
    convEntry(N);
    load(N);
  END_STEP

  TRANSITION FROM highBox TO wait
    := loaded AND NOT(autoMode);
  END_TRANSITION

  TRANSITION FROM highBox TO goLeft
    := loaded AND autoMode;
  END_TRANSITION

  STEP goLeft:
    transfLeft(N);
  END_STEP

  TRANSITION FROM goLeft TO moveConveyors
    := emergencyStop AND R_TRIG4.Q AND NOT(stopLight);
  END_TRANSITION

  TRANSITION FROM goLeft TO waitLeft
    := emergencyStop AND stopLight AND R_TRIG5.Q;
  END_TRANSITION

  STEP waitLeft:
  END_STEP

  TRANSITION FROM waitLeft TO START
    := emergencyStop AND R_TRIG6.Q;
  END_TRANSITION

  TRANSITION FROM waitLeft TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM goLeft TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM checkBox TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM moveConveyors TO START
    := emergencyStop AND F_TRIG1.Q;
  END_TRANSITION

  TRANSITION FROM moveConveyors TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

END_PROGRAM

PROGRAM manageCounters
  VAR_EXTERNAL
    leftExit : BOOL;
    rightExit : BOOL;
    resetButton : BOOL;
    stopLight : BOOL;
    countHigh : INT;
    countLow : INT;
    resetInternal : BOOL;
  END_VAR
  VAR
    presetValue : INT := 1000;
    doubleTrig1 : doubleTrig;
    doubleTrig0 : doubleTrig;
    CTU0 : CTU;
    CTU1 : CTU;
    R_TRIG1 : R_TRIG;
    AND9_OUT : BOOL;
    R_TRIG2 : R_TRIG;
  END_VAR

  doubleTrig0(in := leftExit);
  R_TRIG1(CLK := doubleTrig0.out);
  AND9_OUT := AND(resetButton, stopLight);
  CTU0(CU := R_TRIG1.Q, R := AND9_OUT, PV := presetValue);
  countHigh := CTU0.CV;
  doubleTrig1(in := rightExit);
  R_TRIG2(CLK := doubleTrig1.out);
  CTU1(CU := R_TRIG2.Q, R := AND9_OUT, PV := presetValue);
  countLow := CTU1.CV;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      highSens : BOOL := 0;
      lowSens : BOOL := 0;
      palletSens : BOOL := 0;
      loaded : BOOL := 0;
      leftEntry : BOOL := 1;
      leftExit : BOOL := 1;
      rightEntry : BOOL := 1;
      rightExit : BOOL := 1;
      startButton : BOOL := 0;
      resetButton : BOOL := 0;
      stopButton : BOOL := 1;
      emergencyStop : BOOL := 1;
      autoMode : BOOL := 0;
      stopInternal : BOOL;
      resetInternal : BOOL;
      convEntry : BOOL := 0;
      load : BOOL := 0;
      unload : BOOL := 0;
      transfLeft : BOOL := 0;
      transfRight : BOOL := 0;
      convLeft : BOOL := 0;
      convRight : BOOL := 0;
      startLight : BOOL := 0;
      resetLight : BOOL := 0;
      stopLight : BOOL := 0;
      warnLight : BOOL := 0;
      countHigh : INT := 0;
      countLow : INT := 0;
    END_VAR
    TASK task1(INTERVAL := T#100ms,PRIORITY := 0);
    PROGRAM instance1 WITH task1 : manageCounters;
    PROGRAM instance2 WITH task1 : manageButtonLights;
    PROGRAM instance3 WITH task1 : main;
  END_RESOURCE
END_CONFIGURATION
