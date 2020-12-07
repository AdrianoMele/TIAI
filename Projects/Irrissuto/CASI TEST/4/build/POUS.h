#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK PYTHON_EVAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_EVAL;

void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain);
// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__);
// FUNCTION_BLOCK PYTHON_POLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_POLL;

void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain);
// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__);
// FUNCTION_BLOCK PYTHON_GEAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  PYTHON_EVAL PY_EVAL;
  __DECLARE_VAR(UINT,COUNTER)
  __DECLARE_VAR(UINT,ADD10_OUT)
  __DECLARE_VAR(BOOL,EQ13_OUT)
  __DECLARE_VAR(UINT,SEL15_OUT)
  __DECLARE_VAR(BOOL,AND7_OUT)

} PYTHON_GEAR;

void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain);
// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__);
// FUNCTION_BLOCK TP_WITH_RESET
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(SINT,STATE)
  __DECLARE_VAR(BOOL,PREV_IN)
  __DECLARE_VAR(TIME,CURRENT_TIME)
  __DECLARE_VAR(TIME,START_TIME)

} TP_WITH_RESET;

void TP_WITH_RESET_init__(TP_WITH_RESET *data__, BOOL retain);
// Code part
void TP_WITH_RESET_body__(TP_WITH_RESET *data__);
// FUNCTION_BLOCK RISPRMIOENERGETICO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,USCITA)
  __DECLARE_VAR(BOOL,INGRESSO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(TIME,TEMPO)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,AUX)
  __DECLARE_VAR(TIME,TEMPO2)
  TP_WITH_RESET TP_WITH_RESET0;
  TP_WITH_RESET TP_WITH_RESET1;
  R_TRIG R_TRIG1;
  F_TRIG F_TRIG1;

} RISPRMIOENERGETICO;

void RISPRMIOENERGETICO_init__(RISPRMIOENERGETICO *data__, BOOL retain);
// Code part
void RISPRMIOENERGETICO_body__(RISPRMIOENERGETICO *data__);
// FUNCTION_BLOCK NASTRO1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,TEMPOESECUZIONE)
  __DECLARE_VAR(BOOL,INGRESSO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,USCITANASTRO)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TEMPOINTERNO)
  __DECLARE_VAR(BOOL,AUX)
  TP_WITH_RESET TP_WITH_RESET1;
  TP_WITH_RESET TP_WITH_RESET2;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  F_TRIG F_TRIG1;
  R_TRIG R_TRIG3;

} NASTRO1;

void NASTRO1_init__(NASTRO1 *data__, BOOL retain);
// Code part
void NASTRO1_body__(NASTRO1 *data__);
// FUNCTION_BLOCK MACCHINE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,TEMPODILAVORAZIONE)
  __DECLARE_VAR(BOOL,INGRESSO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,USCITAMACCHINA)

  // FB private variables - TEMP, private and located variables
  TP_WITH_RESET TP_WITH_RESET0;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;

} MACCHINE;

void MACCHINE_init__(MACCHINE *data__, BOOL retain);
// Code part
void MACCHINE_body__(MACCHINE *data__);
// FUNCTION_BLOCK ACCENSIONEPROGRAMMATA
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,OREDALLACCENSIONE)
  __DECLARE_VAR(BOOL,INGRESSO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,USCITAON)

  // FB private variables - TEMP, private and located variables
  TP_WITH_RESET TP_WITH_RESET0;
  __DECLARE_VAR(BOOL,AUX)
  __DECLARE_VAR(TIME,TEMPO0)
  TP_WITH_RESET TP_WITH_RESET1;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  F_TRIG F_TRIG1;
  R_TRIG R_TRIG3;

} ACCENSIONEPROGRAMMATA;

void ACCENSIONEPROGRAMMATA_init__(ACCENSIONEPROGRAMMATA *data__, BOOL retain);
// Code part
void ACCENSIONEPROGRAMMATA_body__(ACCENSIONEPROGRAMMATA *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TASTOON)
  __DECLARE_VAR(BOOL,ACCENSIONEMAN)
  __DECLARE_VAR(BOOL,ACCENSIONEAUT)
  __DECLARE_VAR(BOOL,RIPRISTINOX)
  __DECLARE_VAR(BOOL,RISPARMIOENERGETICO1)
  __DECLARE_VAR(BOOL,RISPARMIOENERGETICO2)
  __DECLARE_VAR(BOOL,ATTIVARESET)
  __DECLARE_VAR(BOOL,ATTIVARESETRIPR)
  __DECLARE_VAR(BOOL,ATTIVARESET0)
  __DECLARE_VAR(BOOL,ATTIVARESET2)
  __DECLARE_VAR(BOOL,ATTIVARESET3)
  __DECLARE_VAR(BOOL,ATTIVARESET4)
  __DECLARE_VAR(BOOL,ATTIVARESET5)
  __DECLARE_VAR(BOOL,ATTIVARESET6)
  __DECLARE_VAR(BOOL,ATTIVARESET7)
  __DECLARE_VAR(BOOL,TEMPOATTESA)
  __DECLARE_VAR(BOOL,TEMPOATTESA2)
  __DECLARE_VAR(BOOL,TEMPOATTESA3)
  __DECLARE_VAR(BOOL,TIMEDUMMY1)
  __DECLARE_VAR(BOOL,TIMEDUMMY2)
  __DECLARE_VAR(BOOL,TIMEDUMMY3)
  __DECLARE_VAR(BOOL,TIMEDUMMY4)
  __DECLARE_VAR(BOOL,TIMEDUMMY5)
  __DECLARE_VAR(BOOL,TIMEDUMMY6)
  __DECLARE_VAR(BOOL,TIMEDUMMY7)
  __DECLARE_VAR(BOOL,MACCHINARISCALDATA)
  __DECLARE_VAR(TIME,TIME3)
  __DECLARE_VAR(TIME,TIME5)
  __DECLARE_VAR(TIME,TIME6)
  __DECLARE_VAR(TIME,TIME7)
  __DECLARE_VAR(TIME,TIME8)
  __DECLARE_VAR(TIME,TIME9)
  __DECLARE_VAR(TIME,TEMPOPROGRAMMATO)
  __DECLARE_VAR(BOOL,LEDVERDE)
  __DECLARE_VAR(BOOL,LEDGIALLO)
  __DECLARE_VAR(BOOL,LEDBIANCO)
  __DECLARE_VAR(BOOL,ERROREMACCHINA2)
  __DECLARE_VAR(BOOL,ERROREMACCHINA1)
  __DECLARE_VAR(BOOL,LEDNERO)
  __DECLARE_VAR(BOOL,LEDROSSO)
  __DECLARE_VAR(BOOL,TASTOCARICOBUSTA)
  __DECLARE_VAR(BOOL,TASTOOFF)
  __DECLARE_VAR(BOOL,STARTLAVORAZIONE)
  __DECLARE_VAR(BOOL,VANO)
  __DECLARE_VAR(BOOL,TASTOEMERGENZA)
  __DECLARE_VAR(BOOL,STATOFUSTELLATRICE)
  __DECLARE_VAR(BOOL,STATOSTAMPAACALDO)
  __DECLARE_VAR(BOOL,NASTRO)
  __DECLARE_VAR(BOOL,SENSOREFOIL)
  __DECLARE_VAR(BOOL,SENSORETEMP)
  __DECLARE_VAR(BOOL,SENSORELAMA)
  RISPRMIOENERGETICO RISPRMIOENERGETICO1;
  RISPRMIOENERGETICO RISPRMIOENERGETICO0;
  NASTRO1 NASTRO11;
  MACCHINE MACCHINE0;
  MACCHINE MACCHINE1;
  NASTRO1 NASTRO12;
  NASTRO1 NASTRO10;
  ACCENSIONEPROGRAMMATA ACCENSIONEPROGRAMMATA0;
  NASTRO1 NASTRO13;
  TP TP0;
  TP TP1;
  RISPRMIOENERGETICO RISPRMIOENERGETICO2;
  TP TP2;
  F_TRIG F_TRIG1;
  F_TRIG F_TRIG2;
  STEP __step_list[17];
  UINT __nb_steps;
  ACTION __action_list[46];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[32];
  __IEC_BOOL_t __debug_transition_list[32];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
