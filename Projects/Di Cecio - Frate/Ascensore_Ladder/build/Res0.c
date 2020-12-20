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
__DECLARE_GLOBAL(USINT_QUEUE,RES0,QUEUE)
__DECLARE_GLOBAL(USINT,RES0,STATE)
__DECLARE_GLOBAL(BOOL,RES0,DIR)

#include "POUS.c"

BOOL TASK0;
PROGRAM0 RES0__INSTANCE0;
#define INSTANCE0 RES0__INSTANCE0

void RES0_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(USINT_QUEUE,QUEUE,__INITIAL_VALUE({{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},0,0,0}),retain)
  __INIT_GLOBAL(USINT,STATE,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,DIR,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  TASK0 = __BOOL_LITERAL(FALSE);
  PROGRAM0_init__(&INSTANCE0,retain);
}

void RES0_run__(unsigned long tick) {
  TASK0 = !(tick % 1);
  if (TASK0) {
    PROGRAM0_body__(&INSTANCE0);
  }
}
