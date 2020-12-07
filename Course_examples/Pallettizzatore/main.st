PROGRAM program0
  VAR
    timeDummy : BOOL;
    timeDummy2 : BOOL;
    timeDummy3 : BOOL;
    Step201X : BOOL := 0;
    Step301X : BOOL := 0;
    startConv : BOOL := 0;
    startPick : BOOL := 0;
  END_VAR
  VAR
    box AT %IX100.0 : BOOL := 0;
    startButton AT %IX100.1 : BOOL := 0;
    emergencyStop AT %IX100.2 : BOOL := 1;
    robotXSetpoint1 AT %QW100.0 : INT := 5;
    robotXSetpoint2 AT %QW101.0 : INT := 4;
    robotZSetpoint1 AT %QW102.0 : INT := 3;
    robotZSetpoint2 AT %QW103.0 : INT := 2;
    rotateRobotCW1 AT %QX100.0 : BOOL := 0;
    rotateRobotCCW1 AT %QX100.1 : BOOL := 0;
    rotateRobotCW2 AT %QX100.2 : BOOL := 0;
    rotateRobotCCW2 AT %QX100.3 : BOOL := 0;
    moveConveyor AT %QX100.4 : BOOL := 0;
    robotGrab1 AT %QX100.5 : BOOL := 0;
    robotGrab2 AT %QX100.6 : BOOL := 0;
    startLight AT %QX100.7 : BOOL := 0;
  END_VAR

  INITIAL_STEP Step0:
    startLight(R);
  END_STEP

  TRANSITION FROM Step0 TO Step3
    := startButton & emergencyStop;
  END_TRANSITION

  STEP Step3:
    startLight(S);
    resetRobot(P);
    timeDummy(D, T#2s);
  END_STEP

  ACTION resetRobot:
    robotXSetpoint1 := 0;
    robotXSetpoint2 := 0;
    robotZSetpoint1 := 0;
    robotZSetpoint2 := 0;
  END_ACTION

  TRANSITION FROM Step3 TO Step1
    := timeDummy;
  END_TRANSITION

  STEP Step1:
    startConv(N);
    startPick(N);
  END_STEP

  TRANSITION FROM Step1 TO Step0
    := NOT(emergencyStop);
  END_TRANSITION

  INITIAL_STEP Step100:
  END_STEP

  TRANSITION FROM Step100 TO Step101
    := startConv & emergencyStop;
  END_TRANSITION

  STEP Step101:
    moveConveyor(N);
  END_STEP

  TRANSITION FROM Step101 TO Step102
    := box&emergencyStop;
  END_TRANSITION

  STEP Step102:
  END_STEP

  TRANSITION FROM Step102 TO Step101
    := NOT(box)&emergencyStop;
  END_TRANSITION

  TRANSITION FROM Step102 TO Step100
    := NOT(emergencyStop);
  END_TRANSITION

  TRANSITION FROM Step101 TO Step100
    := NOT(emergencyStop);
  END_TRANSITION

  INITIAL_STEP Step200:
  END_STEP

  TRANSITION FROM Step200 TO Step201
    := startPick & emergencyStop;
  END_TRANSITION

  STEP Step201:
    Step201X(N);
  END_STEP

  TRANSITION FROM (Step201, D1) TO Step202
    := box & emergencyStop;
  END_TRANSITION

  STEP Step202:
    rotateRobotCCW1(L, T#200ms);
    goUp(P);
    timeDummy2(D, T#1s);
  END_STEP

  ACTION goUp:
    robotZSetpoint1 := 0;
  END_ACTION

  TRANSITION FROM Step202 TO Step203
    := timeDummy2;
  END_TRANSITION

  STEP Step203:
    rotateRobotCCW1(L, T#200ms);
    goFwd(P);
    timeDummy2(D, T#1s);
  END_STEP

  ACTION goFwd:
    robotXSetpoint1 := 10;
  END_ACTION

  TRANSITION FROM Step203 TO Step204
    := timeDummy2;
  END_TRANSITION

  STEP Step204:
    goMiddle(N);
    robotGrab1(SD, T#500ms);
    timeDummy2(D, T#1s);
  END_STEP

  ACTION goMiddle:
    robotZSetpoint1 := 3;
  END_ACTION

  TRANSITION FROM Step204 TO Step205
    := timeDummy2;
  END_TRANSITION

  STEP Step205:
    goUp(P);
    timeDummy2(D, T#1s);
  END_STEP

  TRANSITION FROM Step205 TO Step206
    := timeDummy2;
  END_TRANSITION

  STEP Step206:
    rotateRobotCW1(L, T#200ms);
    timeDummy2(D, T#1s);
  END_STEP

  TRANSITION FROM Step206 TO (Step207, D3)
    := timeDummy2;
  END_TRANSITION

  STEP Step207:
    rotateRobotCW1(L, T#200ms);
    timeDummy2(D, T#1s);
  END_STEP

  TRANSITION FROM Step207 TO Step208
    := timeDummy2;
  END_TRANSITION

  STEP Step208:
    unLoad1(P);
    timeDummy2(D, T#1s);
  END_STEP

  ACTION unLoad1:
    robotZSetpoint1 := 15;
    robotXSetpoint1 := 3;
  END_ACTION

  TRANSITION FROM Step208 TO Step209
    := timeDummy2;
  END_TRANSITION

  STEP Step209:
    robotGrab1(R);
    goUp(N);
  END_STEP

  TRANSITION FROM Step209 TO Step201
    := emergencyStop;
  END_TRANSITION

  TRANSITION FROM Step209 TO Step200
    := NOT(emergencyStop);
  END_TRANSITION

  STEP D3:
  END_STEP

  TRANSITION FROM D3 TO Semaphore
    := True;
  END_TRANSITION

  INITIAL_STEP Semaphore:
  END_STEP

  TRANSITION FROM Semaphore TO D1
    := Step201X;
  END_TRANSITION

  STEP D1:
  END_STEP

  TRANSITION FROM Semaphore TO D2
    := NOT(Step201X) AND Step301X;
  END_TRANSITION

  STEP D2:
  END_STEP

  TRANSITION FROM (D2, Step301) TO Step302
    := box & emergencyStop;
  END_TRANSITION

  STEP Step302:
    rotateRobotCW2(L, T#200ms);
    goUp2(P);
    timeDummy3(D, T#1s);
  END_STEP

  ACTION goUp2:
    robotZSetpoint2 := 0;
  END_ACTION

  TRANSITION FROM Step302 TO Step303
    := timeDummy3;
  END_TRANSITION

  STEP Step303:
    rotateRobotCW2(L, T#200ms);
    goFwd2(P);
    timeDummy3(D, T#1s);
  END_STEP

  ACTION goFwd2:
    robotXSetpoint2 := 12;
  END_ACTION

  TRANSITION FROM Step303 TO Step304
    := timeDummy3;
  END_TRANSITION

  STEP Step304:
    goMiddle2(N);
    robotGrab2(SD, T#500ms);
    timeDummy3(D, T#1s);
  END_STEP

  ACTION goMiddle2:
    robotZSetpoint2 := 3;
  END_ACTION

  TRANSITION FROM Step304 TO Step305
    := timeDummy3;
  END_TRANSITION

  STEP Step305:
    goUp2(P);
    timeDummy3(D, T#1s);
  END_STEP

  TRANSITION FROM Step305 TO Step306
    := timeDummy3;
  END_TRANSITION

  STEP Step306:
    rotateRobotCCW2(L, T#200ms);
    timeDummy3(D, T#1s);
  END_STEP

  TRANSITION FROM Step306 TO (Step307, D4)
    := timeDummy3;
  END_TRANSITION

  STEP Step307:
    rotateRobotCCW2(L, T#200ms);
    timeDummy3(D, T#1s);
  END_STEP

  TRANSITION FROM Step307 TO Step308
    := timeDummy3;
  END_TRANSITION

  STEP Step308:
    unLoad2(P);
    timeDummy3(D, T#1s);
  END_STEP

  ACTION unLoad2:
    robotZSetpoint2 := 15;
    robotXSetpoint2 := 3;
  END_ACTION

  TRANSITION FROM Step308 TO Step309
    := timeDummy3;
  END_TRANSITION

  STEP Step309:
    robotGrab2(R);
    goUp2(N);
  END_STEP

  TRANSITION FROM Step309 TO Step301
    := emergencyStop;
  END_TRANSITION

  STEP Step301:
    Step301X(N);
  END_STEP

  TRANSITION FROM Step309 TO Step300
    := NOT(emergencyStop);
  END_TRANSITION

  INITIAL_STEP Step300:
  END_STEP

  TRANSITION FROM Step300 TO Step301
    := startPick & emergencyStop;
  END_TRANSITION

  STEP D4:
  END_STEP

  TRANSITION FROM D4 TO Semaphore
    := True;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
