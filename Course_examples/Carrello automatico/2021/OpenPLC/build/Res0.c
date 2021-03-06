/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

// RESOURCE RES0

extern unsigned long long common_ticktime__;

#include "accessor.h"
#include "POUS.h"

#include "Config0.h"
__DECLARE_GLOBAL(BOOL,RES0,GO_RIGHT)
__DECLARE_GLOBAL(BOOL,RES0,GO_LEFT)
__DECLARE_GLOBAL(BOOL,RES0,LOAD)
__DECLARE_GLOBAL(BOOL,RES0,FS)
__DECLARE_GLOBAL(BOOL,RES0,FD)
__DECLARE_GLOBAL(BOOL,RES0,FR)

#include "POUS.c"

BOOL TASK0;
BOOL TASK1;
CARRELLO RES0__CONTROLLO;
#define CONTROLLO RES0__CONTROLLO
SIMULAZIONE_CARRELLO RES0__SIMULAZIONE;
#define SIMULAZIONE RES0__SIMULAZIONE

void RES0_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(BOOL,GO_RIGHT,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,GO_LEFT,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,LOAD,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,FS,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,FD,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,FR,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  TASK0 = __BOOL_LITERAL(FALSE);
  TASK1 = __BOOL_LITERAL(FALSE);
  CARRELLO_init__(&CONTROLLO,retain);
  SIMULAZIONE_CARRELLO_init__(&SIMULAZIONE,retain);
}

void RES0_run__(unsigned long tick) {
  TASK0 = !(tick % 1);
  TASK1 = !(tick % 5);
  if (TASK0) {
    CARRELLO_body__(&CONTROLLO);
  }
  if (TASK1) {
    SIMULAZIONE_CARRELLO_body__(&SIMULAZIONE);
  }
}

