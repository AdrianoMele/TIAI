PROGRAM main_carrello
  VAR
    g : BOOL := 0;
    fd : BOOL := 0;
    fs : BOOL := 0;
    fr : BOOL := 0;
    DX : BOOL := 0;
    SER : BOOL := 0;
    SX : BOOL := 0;
  END_VAR

  INITIAL_STEP quiete:
  END_STEP

  TRANSITION FROM quiete TO vai_a_dx
    := g;
  END_TRANSITION

  STEP vai_a_dx:
    DX(N);
  END_STEP

  TRANSITION FROM vai_a_dx TO carica
    := fd;
  END_TRANSITION

  STEP carica:
    SER(N);
  END_STEP

  TRANSITION FROM carica TO vai_a_sx
    := fr;
  END_TRANSITION

  STEP vai_a_sx:
    SX(N);
  END_STEP

  TRANSITION FROM vai_a_sx TO quiete
    := fs;
  END_TRANSITION

END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main_carrello;
  END_RESOURCE
END_CONFIGURATION
