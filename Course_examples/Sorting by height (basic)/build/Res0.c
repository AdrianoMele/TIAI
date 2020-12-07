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
__DECLARE_GLOBAL(BOOL,RES0,HIGHSENS)
__DECLARE_GLOBAL(BOOL,RES0,LOWSENS)
__DECLARE_GLOBAL(BOOL,RES0,PALLETSENS)
__DECLARE_GLOBAL(BOOL,RES0,LOADED)
__DECLARE_GLOBAL(BOOL,RES0,LEFTENTRY)
__DECLARE_GLOBAL(BOOL,RES0,LEFTEXIT)
__DECLARE_GLOBAL(BOOL,RES0,RIGHTENTRY)
__DECLARE_GLOBAL(BOOL,RES0,RIGHTEXIT)
__DECLARE_GLOBAL(BOOL,RES0,STARTBUTTON)
__DECLARE_GLOBAL(BOOL,RES0,RESETBUTTON)
__DECLARE_GLOBAL(BOOL,RES0,STOPBUTTON)
__DECLARE_GLOBAL(BOOL,RES0,STOPINTERNAL)
__DECLARE_GLOBAL(BOOL,RES0,RESETINTERNAL)
__DECLARE_GLOBAL(BOOL,RES0,EMERGENCYSTOP)
__DECLARE_GLOBAL(BOOL,RES0,AUTOMODE)
__DECLARE_GLOBAL(BOOL,RES0,CONVENTRY)
__DECLARE_GLOBAL(BOOL,RES0,LOAD)
__DECLARE_GLOBAL(BOOL,RES0,UNLOAD)
__DECLARE_GLOBAL(BOOL,RES0,TRANSFLEFT)
__DECLARE_GLOBAL(BOOL,RES0,TRANSFRIGHT)
__DECLARE_GLOBAL(BOOL,RES0,CONVLEFT)
__DECLARE_GLOBAL(BOOL,RES0,CONVRIGHT)
__DECLARE_GLOBAL(BOOL,RES0,STARTLIGHT)
__DECLARE_GLOBAL(BOOL,RES0,RESETLIGHT)
__DECLARE_GLOBAL(BOOL,RES0,STOPLIGHT)
__DECLARE_GLOBAL(BOOL,RES0,WARNLIGHT)
__DECLARE_GLOBAL(INT,RES0,COUNTHIGH)
__DECLARE_GLOBAL(INT,RES0,COUNTLOW)

#include "POUS.c"

BOOL TASK1;
MANAGECOUNTERS RES0__INSTANCE1;
#define INSTANCE1 RES0__INSTANCE1
MANAGEBUTTONLIGHTS RES0__INSTANCE2;
#define INSTANCE2 RES0__INSTANCE2
MAIN RES0__INSTANCE3;
#define INSTANCE3 RES0__INSTANCE3

void RES0_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(BOOL,HIGHSENS,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,LOWSENS,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,PALLETSENS,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,LOADED,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,LEFTENTRY,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(BOOL,LEFTEXIT,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(BOOL,RIGHTENTRY,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(BOOL,RIGHTEXIT,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(BOOL,STARTBUTTON,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,RESETBUTTON,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,STOPBUTTON,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(BOOL,STOPINTERNAL,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,RESETINTERNAL,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,EMERGENCYSTOP,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(BOOL,AUTOMODE,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,CONVENTRY,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,LOAD,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,UNLOAD,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,TRANSFLEFT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,TRANSFRIGHT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,CONVLEFT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,CONVRIGHT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,STARTLIGHT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,RESETLIGHT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,STOPLIGHT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(BOOL,WARNLIGHT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(INT,COUNTHIGH,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(INT,COUNTLOW,__INITIAL_VALUE(0),retain)
  TASK1 = __BOOL_LITERAL(FALSE);
  MANAGECOUNTERS_init__(&INSTANCE1,retain);
  MANAGEBUTTONLIGHTS_init__(&INSTANCE2,retain);
  MAIN_init__(&INSTANCE3,retain);
}

void RES0_run__(unsigned long tick) {
  TASK1 = !(tick % 1);
  if (TASK1) {
    MANAGECOUNTERS_body__(&INSTANCE1);
  }
  if (TASK1) {
    MANAGEBUTTONLIGHTS_body__(&INSTANCE2);
  }
  if (TASK1) {
    MAIN_body__(&INSTANCE3);
  }
}

