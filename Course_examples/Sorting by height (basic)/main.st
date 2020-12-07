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
    processing : BOOL;
    R_TRIG1 : R_TRIG;
    F_TRIG1 : F_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    R_TRIG5 : R_TRIG;
    R_TRIG6 : R_TRIG;
    R_TRIG7 : R_TRIG;
    R_TRIG8 : R_TRIG;
  END_VAR

  INITIAL_STEP START:
    convLeft(R);
    convRight(R);
    stopInternal(R);
    processing(R);
    warnLight(R);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    R_TRIG1(CLK := rightEntry);
    F_TRIG1(CLK := stopButton);
    R_TRIG2(CLK := leftExit);
    R_TRIG3(CLK := rightExit);
    R_TRIG4(CLK := rightEntry);
    R_TRIG5(CLK := rightExit);
    R_TRIG6(CLK := leftEntry);
    R_TRIG7(CLK := leftEntry);
    R_TRIG8(CLK := leftExit);
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
    processing(R);
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
    processing(S);
  END_STEP

  TRANSITION FROM goRight TO moveConveyors
    := emergencyStop AND R_TRIG1.Q AND NOT(stopLight);
  END_TRANSITION

  TRANSITION FROM goRight TO waitRight
    := emergencyStop AND stopLight AND R_TRIG4.Q;
  END_TRANSITION

  STEP waitRight:
  END_STEP

  TRANSITION FROM waitRight TO START
    := R_TRIG5.Q;
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
    processing(S);
  END_STEP

  TRANSITION FROM goLeft TO moveConveyors
    := emergencyStop AND R_TRIG6.Q AND NOT(stopLight);
  END_TRANSITION

  TRANSITION FROM goLeft TO waitLeft
    := emergencyStop AND stopLight AND R_TRIG7.Q;
  END_TRANSITION

  STEP waitLeft:
  END_STEP

  TRANSITION FROM waitLeft TO START
    := emergencyStop AND R_TRIG8.Q;
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

  TRANSITION FROM moveConveyors TO Stopping
    := emergencyStop AND F_TRIG1.Q;
  END_TRANSITION

  STEP Stopping:
  END_STEP

  TRANSITION FROM Stopping TO PendingJob
    := processing AND emergencyStop;
  END_TRANSITION

  STEP PendingJob:
  END_STEP

  TRANSITION FROM PendingJob TO START
    := emergencyStop AND (R_TRIG2.Q OR R_TRIG3.Q);
  END_TRANSITION

  TRANSITION FROM PendingJob TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM Stopping TO START
    := NOT(processing) AND emergencyStop;
  END_TRANSITION

  TRANSITION FROM Stopping TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM moveConveyors TO FAULT
    := NOT(emergencyStop);
  END_TRANSITION

END_PROGRAM

PROGRAM manageCounters
  VAR
    CTU0 : CTU;
    CTU1 : CTU;
  END_VAR
  VAR_EXTERNAL
    leftExit : BOOL;
    rightExit : BOOL;
    resetButton : BOOL;
    stopLight : BOOL;
    countHigh : INT;
    countLow : INT;
  END_VAR
  VAR
    presetValue : INT := 1000;
  END_VAR
  VAR_EXTERNAL
    resetInternal : BOOL;
  END_VAR
  VAR
    doubleTrig1 : doubleTrig;
    R_TRIG1 : R_TRIG;
    AND9_OUT : BOOL;
    R_TRIG2 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := leftExit);
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
      highSens AT %IX100.0 : BOOL := 0;
      lowSens AT %IX100.1 : BOOL := 0;
      palletSens AT %IX100.2 : BOOL := 0;
      loaded AT %IX100.3 : BOOL := 0;
      leftEntry AT %IX100.4 : BOOL := 1;
      leftExit AT %IX100.5 : BOOL := 1;
      rightEntry AT %IX100.6 : BOOL := 1;
      rightExit AT %IX100.7 : BOOL := 1;
      startButton AT %IX101.0 : BOOL := 0;
      resetButton AT %IX101.1 : BOOL := 0;
      stopButton AT %IX101.2 : BOOL := 1;
      stopInternal : BOOL;
      resetInternal : BOOL;
      emergencyStop AT %IX101.3 : BOOL := 1;
      autoMode AT %IX101.4 : BOOL := 0;
      convEntry AT %QX100.0 : BOOL := 0;
      load AT %QX100.1 : BOOL := 0;
      unload AT %QX100.2 : BOOL := 0;
      transfLeft AT %QX100.3 : BOOL := 0;
      transfRight AT %QX100.4 : BOOL := 0;
      convLeft AT %QX100.5 : BOOL := 0;
      convRight AT %QX100.6 : BOOL := 0;
      startLight AT %QX100.7 : BOOL := 0;
      resetLight AT %QX101.0 : BOOL := 0;
      stopLight AT %QX101.1 : BOOL := 0;
      warnLight AT %QX101.2 : BOOL := 0;
      countHigh AT %QW100 : INT := 0;
      countLow AT %QW101 : INT := 0;
    END_VAR
    TASK task1(INTERVAL := T#100ms,PRIORITY := 0);
    PROGRAM instance1 WITH task1 : manageCounters;
    PROGRAM instance2 WITH task1 : manageButtonLights;
    PROGRAM instance3 WITH task1 : main;
  END_RESOURCE
END_CONFIGURATION
