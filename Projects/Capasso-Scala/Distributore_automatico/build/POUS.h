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
__DECLARE_STRUCT_TYPE(PRODOTTO,
  BOOL MOTORE;
    REAL PREZZO;
    BOOL SENSORE;
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
// FUNCTION_BLOCK RESET
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENABLE)
  __DECLARE_VAR(BOOL,EN_O)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(REAL,CREDITO)
  __DECLARE_EXTERNAL(REAL,RESTO)

} RESET;

void RESET_init__(RESET *data__, BOOL retain);
// Code part
void RESET_body__(RESET *data__);
// FUNCTION_BLOCK ASSEGNAZIONE_SENSORI
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENABLE)
  __DECLARE_VAR(BOOL,EN_O)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3D)
  __DECLARE_EXTERNAL(BOOL,S_0A)
  __DECLARE_EXTERNAL(BOOL,S_0B)
  __DECLARE_EXTERNAL(BOOL,S_0C)
  __DECLARE_EXTERNAL(BOOL,S_0D)
  __DECLARE_EXTERNAL(BOOL,S_1A)
  __DECLARE_EXTERNAL(BOOL,S_1B)
  __DECLARE_EXTERNAL(BOOL,S_1C)
  __DECLARE_EXTERNAL(BOOL,S_1D)
  __DECLARE_EXTERNAL(BOOL,S_2A)
  __DECLARE_EXTERNAL(BOOL,S_2B)
  __DECLARE_EXTERNAL(BOOL,S_2C)
  __DECLARE_EXTERNAL(BOOL,S_2D)
  __DECLARE_EXTERNAL(BOOL,S_3A)
  __DECLARE_EXTERNAL(BOOL,S_3B)
  __DECLARE_EXTERNAL(BOOL,S_3C)
  __DECLARE_EXTERNAL(BOOL,S_3D)

} ASSEGNAZIONE_SENSORI;

void ASSEGNAZIONE_SENSORI_init__(ASSEGNAZIONE_SENSORI *data__, BOOL retain);
// Code part
void ASSEGNAZIONE_SENSORI_body__(ASSEGNAZIONE_SENSORI *data__);
// FUNCTION_BLOCK SENSORI_RIFORNIMENTO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENABLE)
  __DECLARE_VAR(BOOL,INVIA_SEGNALE)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(BOOL,S_0A)
  __DECLARE_EXTERNAL(BOOL,S_0B)
  __DECLARE_EXTERNAL(BOOL,S_0C)
  __DECLARE_EXTERNAL(BOOL,S_0D)
  __DECLARE_EXTERNAL(BOOL,S_1A)
  __DECLARE_EXTERNAL(BOOL,S_1B)
  __DECLARE_EXTERNAL(BOOL,S_1C)
  __DECLARE_EXTERNAL(BOOL,S_1D)
  __DECLARE_EXTERNAL(BOOL,S_2A)
  __DECLARE_EXTERNAL(BOOL,S_2B)
  __DECLARE_EXTERNAL(BOOL,S_2C)
  __DECLARE_EXTERNAL(BOOL,S_2D)
  __DECLARE_EXTERNAL(BOOL,S_3A)
  __DECLARE_EXTERNAL(BOOL,S_3B)
  __DECLARE_EXTERNAL(BOOL,S_3C)
  __DECLARE_EXTERNAL(BOOL,S_3D)
  ASSEGNAZIONE_SENSORI ASSEGNAZIONE_SENSORI0;

} SENSORI_RIFORNIMENTO;

void SENSORI_RIFORNIMENTO_init__(SENSORI_RIFORNIMENTO *data__, BOOL retain);
// Code part
void SENSORI_RIFORNIMENTO_body__(SENSORI_RIFORNIMENTO *data__);
// FUNCTION_BLOCK ASSEGNAZIONE_PRODOTTO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENABLE)
  __DECLARE_VAR(STRING,SELECTED)
  __DECLARE_VAR(BOOL,EN_O)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(STRING,NUMERO)
  __DECLARE_EXTERNAL(REAL,PREZZO)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3D)

} ASSEGNAZIONE_PRODOTTO;

void ASSEGNAZIONE_PRODOTTO_init__(ASSEGNAZIONE_PRODOTTO *data__, BOOL retain);
// Code part
void ASSEGNAZIONE_PRODOTTO_body__(ASSEGNAZIONE_PRODOTTO *data__);
// PROGRAM INIZIALIZZAZIONE
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3D)
  __DECLARE_EXTERNAL(BOOL,SINGLE_EX)

} INIZIALIZZAZIONE;

void INIZIALIZZAZIONE_init__(INIZIALIZZAZIONE *data__, BOOL retain);
// Code part
void INIZIALIZZAZIONE_body__(INIZIALIZZAZIONE *data__);
// FUNCTION_BLOCK EROGA_PRODOTTO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,EN_O)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(STRING,NUMERO)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_1D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_2D)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3A)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3B)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3C)
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_3D)

} EROGA_PRODOTTO;

void EROGA_PRODOTTO_init__(EROGA_PRODOTTO *data__, BOOL retain);
// Code part
void EROGA_PRODOTTO_body__(EROGA_PRODOTTO *data__);
// FUNCTION_BLOCK SCELTA_PRODOTTO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,EN_TASTIERINO)
  __DECLARE_VAR(BOOL,EN_O)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,BUTTON_0)
  __DECLARE_VAR(BOOL,BUTTON_1)
  __DECLARE_VAR(BOOL,BUTTON_2)
  __DECLARE_VAR(BOOL,BUTTON_3)
  __DECLARE_VAR(BOOL,BUTTON_A)
  __DECLARE_VAR(BOOL,BUTTON_B)
  __DECLARE_VAR(BOOL,BUTTON_C)
  __DECLARE_VAR(BOOL,BUTTON_D)
  __DECLARE_VAR(BOOL,BUTTON_R)
  __DECLARE_VAR(STRING,SELECTED)
  RESET RESET0;
  __DECLARE_VAR(BOOL,EROGA_RESTO)
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE0;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE1;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE2;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE3;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE4;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE5;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE6;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE7;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE8;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE9;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE10;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE11;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE12;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE13;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE14;
  ASSEGNAZIONE_PRODOTTO ASSEGNAZIONE15;

} SCELTA_PRODOTTO;

void SCELTA_PRODOTTO_init__(SCELTA_PRODOTTO *data__, BOOL retain);
// Code part
void SCELTA_PRODOTTO_body__(SCELTA_PRODOTTO *data__);
// FUNCTION_BLOCK GETTONIERA
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENABLE)
  __DECLARE_VAR(BOOL,MONETA_05)
  __DECLARE_VAR(BOOL,MONETA_1)
  __DECLARE_VAR(BOOL,MONETA_2)
  __DECLARE_VAR(BOOL,MONETA_5)
  __DECLARE_VAR(BOOL,MONETA_10)
  __DECLARE_VAR(BOOL,EN_TASTIERINO)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(REAL,CREDITO)
  R_TRIG R_TRIG0;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  R_TRIG R_TRIG3;
  R_TRIG R_TRIG4;
  __DECLARE_VAR(REAL,BOOL_TO_REAL5_OUT)
  __DECLARE_VAR(REAL,MUL6_OUT)
  __DECLARE_VAR(REAL,BOOL_TO_REAL13_OUT)
  __DECLARE_VAR(REAL,BOOL_TO_REAL16_OUT)
  __DECLARE_VAR(REAL,MUL17_OUT)
  __DECLARE_VAR(REAL,BOOL_TO_REAL21_OUT)
  __DECLARE_VAR(REAL,MUL22_OUT)
  __DECLARE_VAR(REAL,BOOL_TO_REAL33_OUT)
  __DECLARE_VAR(REAL,MUL34_OUT)
  __DECLARE_VAR(REAL,ADD8_OUT)
  __DECLARE_VAR(BOOL,REAL_TO_BOOL43_OUT)

} GETTONIERA;

void GETTONIERA_init__(GETTONIERA *data__, BOOL retain);
// Code part
void GETTONIERA_body__(GETTONIERA *data__);
// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(REAL,CREDITO)
  __DECLARE_EXTERNAL(STRING,NUMERO)
  __DECLARE_EXTERNAL(REAL,PREZZO)
  __DECLARE_EXTERNAL(REAL,RESTO)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,MONETA_05)
  __DECLARE_VAR(BOOL,MONETA_1)
  __DECLARE_VAR(BOOL,MONETA_2)
  __DECLARE_VAR(BOOL,MONETA_5)
  __DECLARE_VAR(BOOL,MONETA_10)
  __DECLARE_VAR(TIME,TEMPO)
  __DECLARE_VAR(BOOL,EN_RIFORNIMENTO)
  __DECLARE_VAR(BOOL,AVVISA_CENTRALE)
  __DECLARE_VAR(BOOL,SBLOCCA_VANO)
  __DECLARE_VAR(BOOL,LETTURA_CARTA)
  __DECLARE_VAR(BOOL,ADDEBITA_CARTA)
  GETTONIERA GETTONIERA0;
  SCELTA_PRODOTTO SCELTA_PRODOTTO0;
  EROGA_PRODOTTO EROGA_PRODOTTO0;
  __DECLARE_VAR(BOOL,EROGA_RESTO)
  TON TON0;
  EROGA_PRODOTTO EROGA_PRODOTTO1;
  SCELTA_PRODOTTO SCELTA_PRODOTTO1;
  TON TON1;
  SENSORI_RIFORNIMENTO SENSORI_RIFORNIMENTO0;
  __DECLARE_EXTERNAL(PRODOTTO,PRODOTTO_0A)
  __DECLARE_VAR(BOOL,GE10_ENO)
  __DECLARE_VAR(BOOL,GE10_OUT)
  __DECLARE_VAR(BOOL,SUB12_ENO)
  __DECLARE_VAR(REAL,SUB12_OUT)
  __DECLARE_VAR(BOOL,REAL_TO_BOOL23_OUT)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
