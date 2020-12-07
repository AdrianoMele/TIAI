/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */
#ifdef TARGET_DEBUG_AND_RETAIN_DISABLE

void __init_debug    (void){}
void __cleanup_debug (void){}
void __retrieve_debug(void){}
void __publish_debug (void){}

#else

#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

#ifndef TARGET_ONLINE_DEBUG_DISABLE
#define BUFFER_SIZE 785

/* Atomically accessed variable for buffer state */
#define BUFFER_FREE 0
#define BUFFER_BUSY 1
static long buffer_state = BUFFER_FREE;

/* The buffer itself */
char debug_buffer[BUFFER_SIZE];

/* Buffer's cursor*/
static char* buffer_cursor = debug_buffer;
#endif

static unsigned int retain_offset = 0;
/***
 * Declare programs 
 **/
extern CANCELLO_ESTERNO RES0__INSTANCE0;
extern ILLUMINAZIONE RES0__INSTANCE1;
extern ANTIFURTO RES0__INSTANCE2;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_BOOL_t CONFIG0__BUTTON;
extern __IEC_BOOL_t CONFIG0__ALARM1;
extern __IEC_BOOL_t CONFIG0__ALARM2;
extern __IEC_BOOL_t CONFIG0__ALARM3;
extern __IEC_BOOL_t CONFIG0__ALARM4;
extern __IEC_BOOL_t CONFIG0__FOTOC1;
extern __IEC_BOOL_t CONFIG0__FOTOC2;
extern __IEC_BOOL_t CONFIG0__S_MOV1;
extern __IEC_BOOL_t CONFIG0__MOT_C;
extern __IEC_BOOL_t CONFIG0__MOT_C1;
extern __IEC_BOOL_t CONFIG0__C_APERTO;
extern __IEC_BOOL_t CONFIG0__C_CHIUSO;
extern __IEC_BOOL_t CONFIG0__C_PEDONALE;
extern __IEC_BOOL_t CONFIG0__LIGHT1;
extern __IEC_BOOL_t CONFIG0__LIGHT2;
extern __IEC_BOOL_t CONFIG0__LIGHT3;
extern __IEC_BOOL_t CONFIG0__LIGHT4;
extern __IEC_BOOL_t CONFIG0__G_CHIUSO;
extern       CANCELLO_ESTERNO   RES0__INSTANCE0;
extern       ILLUMINAZIONE   RES0__INSTANCE1;
extern       ANTIFURTO   RES0__INSTANCE2;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(CONFIG0__BUTTON), BOOL_ENUM},
{&(CONFIG0__ALARM1), BOOL_ENUM},
{&(CONFIG0__ALARM2), BOOL_ENUM},
{&(CONFIG0__ALARM3), BOOL_ENUM},
{&(CONFIG0__ALARM4), BOOL_ENUM},
{&(CONFIG0__FOTOC1), BOOL_ENUM},
{&(CONFIG0__FOTOC2), BOOL_ENUM},
{&(CONFIG0__S_MOV1), BOOL_ENUM},
{&(CONFIG0__MOT_C), BOOL_ENUM},
{&(CONFIG0__MOT_C1), BOOL_ENUM},
{&(CONFIG0__C_APERTO), BOOL_ENUM},
{&(CONFIG0__C_CHIUSO), BOOL_ENUM},
{&(CONFIG0__C_PEDONALE), BOOL_ENUM},
{&(CONFIG0__LIGHT1), BOOL_ENUM},
{&(CONFIG0__LIGHT2), BOOL_ENUM},
{&(CONFIG0__LIGHT3), BOOL_ENUM},
{&(CONFIG0__LIGHT4), BOOL_ENUM},
{&(CONFIG0__G_CHIUSO), BOOL_ENUM},
{&(RES0__INSTANCE0.BUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE0.LIGHT), BOOL_ENUM},
{&(RES0__INSTANCE0.MOT_A), BOOL_ENUM},
{&(RES0__INSTANCE0.MOT_C), BOOL_P_ENUM},
{&(RES0__INSTANCE0.ALARM1), BOOL_P_ENUM},
{&(RES0__INSTANCE0.ALARM2), BOOL_P_ENUM},
{&(RES0__INSTANCE0.ALARM3), BOOL_P_ENUM},
{&(RES0__INSTANCE0.ALARM4), BOOL_P_ENUM},
{&(RES0__INSTANCE0.FOTOC1), BOOL_P_ENUM},
{&(RES0__INSTANCE0.C_CHIUSO), BOOL_P_ENUM},
{&(RES0__INSTANCE0.C_APERTO), BOOL_P_ENUM},
{&(RES0__INSTANCE0.BUTTON1), BOOL_ENUM},
{&(RES0__INSTANCE0.MOT_A1), BOOL_ENUM},
{&(RES0__INSTANCE0.MOT_C1), BOOL_P_ENUM},
{&(RES0__INSTANCE0.FOTOC2), BOOL_P_ENUM},
{&(RES0__INSTANCE0.G_CHIUSO), BOOL_P_ENUM},
{&(RES0__INSTANCE0.G_APERTO), BOOL_ENUM},
{&(RES0__INSTANCE0.S_MOV1), BOOL_P_ENUM},
{&(RES0__INSTANCE0.BUTTON2), BOOL_ENUM},
{&(RES0__INSTANCE0.C_PEDONALE), BOOL_P_ENUM},
{&(RES0__INSTANCE0.__step_list[0].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[0]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[1].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[1]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[2].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[2]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[3].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[3]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[4].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[4]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[5]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[5].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[6]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[6].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[7]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[7].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[8]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[8].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[9]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[9].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[10]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[10].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[11]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[12]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[11].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[13]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[14]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[12].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[15]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[13].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[16]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[14].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[17]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[15].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[18]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[16].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[19]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[17].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[20]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[21]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[18].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[22]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[19].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[23]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[20].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[24]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[21].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[25]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[22].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[26]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[23].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[27]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[28]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[24].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[29]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[30]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[25].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[31]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[26].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[32]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[27].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[33]), BOOL_ENUM},
{&(RES0__INSTANCE1.C_CHIUSO), BOOL_P_ENUM},
{&(RES0__INSTANCE1.BUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE1.C_PEDONALE), BOOL_P_ENUM},
{&(RES0__INSTANCE1.G_CHIUSO), BOOL_P_ENUM},
{&(RES0__INSTANCE1.LIGHT1), BOOL_P_ENUM},
{&(RES0__INSTANCE1.LIGHT2), BOOL_P_ENUM},
{&(RES0__INSTANCE1.LIGHT3), BOOL_P_ENUM},
{&(RES0__INSTANCE1.LIGHT4), BOOL_P_ENUM},
{&(RES0__INSTANCE1.S_CREPUSCOLARE), BOOL_ENUM},
{&(RES0__INSTANCE1.B_LIGHT1), BOOL_ENUM},
{&(RES0__INSTANCE1.B_LIGHT2), BOOL_ENUM},
{&(RES0__INSTANCE1.B_LIGHT3), BOOL_ENUM},
{&(RES0__INSTANCE1.B_LIGHT4), BOOL_ENUM},
{&(RES0__INSTANCE1.B_TIMER), BOOL_ENUM},
{&(RES0__INSTANCE1.TP0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TP0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP0.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TP0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TP0.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TP0.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TP0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TEMPO_ACCENSIONE), TOD_ENUM},
{&(RES0__INSTANCE1.DATA_INIZIALE), DT_ENUM},
{&(RES0__INSTANCE1.TEMPO_CORRENTE), TOD_ENUM},
{&(RES0__INSTANCE1.RTC0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.RTC0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.RTC0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.RTC0.PDT), DT_ENUM},
{&(RES0__INSTANCE1.RTC0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.RTC0.CDT), DT_ENUM},
{&(RES0__INSTANCE1.RTC0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.RTC0.OFFSET), TIME_ENUM},
{&(RES0__INSTANCE1.RTC0.CURRENT_TIME), DT_ENUM},
{&(RES0__INSTANCE1.S_MOV1), BOOL_P_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.RESET), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP_WITH_RESET0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.RESET), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.RESET), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP_RESETOFF_TIMER1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TP1.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP1.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TP1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TP1.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TP1.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TP1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TP1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TP1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.GIORNODOPO), BOOL_ENUM},
{&(RES0__INSTANCE1.DATE_AND_TIME_TO_TIME_OF_DAY35_OUT), TOD_ENUM},
{&(RES0__INSTANCE1.GT37_OUT), BOOL_ENUM},
{&(RES0__INSTANCE2.ANTI_THEFT1), BOOL_ENUM},
{&(RES0__INSTANCE2.ANTI_THEFT2), BOOL_ENUM},
{&(RES0__INSTANCE2.ANTI_THEFT3), BOOL_ENUM},
{&(RES0__INSTANCE2.ANTI_THEFT4), BOOL_ENUM},
{&(RES0__INSTANCE2.T_PROX1), BOOL_ENUM},
{&(RES0__INSTANCE2.FOTOC1), BOOL_P_ENUM},
{&(RES0__INSTANCE2.FOTOC2), BOOL_P_ENUM},
{&(RES0__INSTANCE2.S_MOV1), BOOL_P_ENUM},
{&(RES0__INSTANCE2.S_MOV2), BOOL_ENUM},
{&(RES0__INSTANCE2.S_FUMO), BOOL_ENUM},
{&(RES0__INSTANCE2.ALARM1), BOOL_P_ENUM},
{&(RES0__INSTANCE2.ALARM2), BOOL_P_ENUM},
{&(RES0__INSTANCE2.ALARM3), BOOL_P_ENUM},
{&(RES0__INSTANCE2.ALARM4), BOOL_P_ENUM},
{&(RES0__INSTANCE2.L_PORTA), BOOL_ENUM},
{&(RES0__INSTANCE2.L_FINESTRE), BOOL_ENUM},
{&(RES0__INSTANCE2.C_CHIUSO), BOOL_P_ENUM},
{&(RES0__INSTANCE2.G_CHIUSO), BOOL_P_ENUM},
{&(RES0__INSTANCE2.C_PEDONALE), BOOL_P_ENUM},
{&(RES0__INSTANCE2.FARO1), BOOL_ENUM},
{&(RES0__INSTANCE2.FARO2), BOOL_ENUM},
{&(RES0__INSTANCE2.FARO3), BOOL_ENUM},
{&(RES0__INSTANCE2.FARO4), BOOL_ENUM},
{&(RES0__INSTANCE2.LIGHT5), BOOL_ENUM},
{&(RES0__INSTANCE2.SPEAKER1), BOOL_ENUM},
{&(RES0__INSTANCE2.SPRINKLER), BOOL_ENUM},
{&(RES0__INSTANCE2.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF0.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF0.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF0.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TOF0.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF0.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TOF0.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TOF0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON1.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TON1.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON1.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TON1.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TON1.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TON1.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TON1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF1.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF1.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF1.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TOF1.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF1.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TOF1.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TOF1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON2.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TON2.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON2.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TON2.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TON2.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TON2.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TON2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF2.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF2.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF2.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TOF2.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF2.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TOF2.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TOF2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON3.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TON3.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON3.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TON3.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TON3.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TON3.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TON3.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON3.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON3.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF3.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF3.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF3.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TOF3.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF3.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TOF3.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TOF3.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF3.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF3.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON4.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TON4.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON4.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TON4.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TON4.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TON4.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TON4.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TON4.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TON4.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF4.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF4.IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF4.PT), TIME_ENUM},
{&(RES0__INSTANCE2.TOF4.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF4.ET), TIME_ENUM},
{&(RES0__INSTANCE2.TOF4.STATE), SINT_ENUM},
{&(RES0__INSTANCE2.TOF4.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE2.TOF4.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE2.TOF4.START_TIME), TIME_ENUM}
};

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    unsigned int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;\
            forced_value_p = *real_value_p = &((__IEC_##TYPENAME##_t *)varp)->value;\
            break;

#define __Unpack_case_p(TYPENAME)\
        case TYPENAME##_O_ENUM :\
            *flags = __IEC_OUTPUT_FLAG;\
        case TYPENAME##_P_ENUM :\
            *flags |= ((__IEC_##TYPENAME##_p *)varp)->flags;\
            *real_value_p = ((__IEC_##TYPENAME##_p *)varp)->value;\
            forced_value_p = &((__IEC_##TYPENAME##_p *)varp)->fvalue;\
            break;

void* UnpackVar(dbgvardsc_t *dsc, void **real_value_p, char *flags)
{
    void *varp = dsc->ptr;
    void *forced_value_p = NULL;
    *flags = 0;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        break;
    }
    if (*flags & __IEC_FORCE_FLAG)
        return forced_value_p;
    return *real_value_p;
}

void Remind(unsigned int offset, unsigned int count, void * p);

void RemindIterator(dbgvardsc_t *dsc)
{
    void *real_value_p = NULL;
    char flags = 0;
    UnpackVar(dsc, &real_value_p, &flags);

    if(flags & __IEC_RETAIN_FLAG){
        USINT size = __get_type_enum_size(dsc->type);
        /* compute next cursor positon*/
        unsigned int next_retain_offset = retain_offset + size;
        /* if buffer not full */
        Remind(retain_offset, size, real_value_p);
        /* increment cursor according size*/
        retain_offset = next_retain_offset;
    }
}

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
#ifndef TARGET_ONLINE_DEBUG_DISABLE	
    buffer_cursor = debug_buffer;
    buffer_state = BUFFER_FREE;
#endif

    retain_offset = 0;
    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
    	__for_each_variable_do(RemindIterator);
    }else{
    	char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
    retain_offset = 0;
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
#ifndef TARGET_ONLINE_DEBUG_DISABLE	
    buffer_cursor = debug_buffer;
    InitiateDebugTransfer();
#endif    

    CleanupRetain();
}

void __retrieve_debug(void)
{
}


void Retain(unsigned int offset, unsigned int count, void * p);

static inline void BufferIterator(dbgvardsc_t *dsc, int do_debug)
{
    void *real_value_p = NULL;
    void *visible_value_p = NULL;
    char flags = 0;

    visible_value_p = UnpackVar(dsc, &real_value_p, &flags);

    if(flags & ( __IEC_DEBUG_FLAG | __IEC_RETAIN_FLAG)){
        USINT size = __get_type_enum_size(dsc->type);

#ifndef TARGET_ONLINE_DEBUG_DISABLE	
        if(flags & __IEC_DEBUG_FLAG){
            /* copy visible variable to buffer */;
            if(do_debug){
                /* compute next cursor positon.
                   No need to check overflow, as BUFFER_SIZE
                   is computed large enough */
		if((dsc->type == STRING_ENUM)   ||
		   (dsc->type == STRING_P_ENUM) ||
		   (dsc->type == STRING_O_ENUM)){
                    /* optimization for strings */
                    size = ((STRING*)visible_value_p)->len + 1;
                }
                char* next_cursor = buffer_cursor + size;
                /* copy data to the buffer */
                memcpy(buffer_cursor, visible_value_p, size);
                /* increment cursor according size*/
                buffer_cursor = next_cursor;
            }
            /* re-force real value of outputs (M and Q)*/
            if((flags & __IEC_FORCE_FLAG) && (flags & __IEC_OUTPUT_FLAG)){
                memcpy(real_value_p, visible_value_p, size);
            }
        }
#endif	

        if(flags & __IEC_RETAIN_FLAG){
            /* compute next cursor positon*/
            unsigned int next_retain_offset = retain_offset + size;
            /* if buffer not full */
            Retain(retain_offset, size, real_value_p);
            /* increment cursor according size*/
            retain_offset = next_retain_offset;
        }
    }
}

void DebugIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 1);
}

void RetainIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 0);
}


unsigned int retain_size = 0;

/* GetRetainSizeIterator */
void GetRetainSizeIterator(dbgvardsc_t *dsc)
{
    void *real_value_p = NULL;
    char flags = 0;
    UnpackVar(dsc, &real_value_p, &flags);

    if(flags & __IEC_RETAIN_FLAG){
        USINT size = __get_type_enum_size(dsc->type);
        /* Calc retain buffer size */
        retain_size += size;
    }
}

/* Return size of all retain variables */
unsigned int GetRetainSize(void)
{
    __for_each_variable_do(GetRetainSizeIterator);
    return retain_size;
}


extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

void __publish_debug(void)
{
    retain_offset = 0;
    InValidateRetainBuffer();
    
#ifndef TARGET_ONLINE_DEBUG_DISABLE 
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &buffer_state,
            BUFFER_FREE,
            BUFFER_BUSY);
            
        /* If buffer was free */
        if(latest_state == BUFFER_FREE)
        {
            /* Reset buffer cursor */
            buffer_cursor = debug_buffer;
            /* Iterate over all variables to fill debug buffer */
            __for_each_variable_do(DebugIterator);
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }else{
            /* when not debugging, do only retain */
            __for_each_variable_do(RetainIterator);
        }
        LeaveDebugSection();
    }else
#endif
    {
        /* when not debugging, do only retain */
        __for_each_variable_do(RetainIterator);
    }
    ValidateRetainBuffer();
}

#ifndef TARGET_ONLINE_DEBUG_DISABLE
#define __RegisterDebugVariable_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);\
            break;
#define __RegisterDebugVariable_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
            break;\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force){\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
             *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
            }\
            break;
void RegisterDebugVariable(unsigned int idx, void* force)
{
    if(idx  < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        unsigned char flags = force ?
            __IEC_DEBUG_FLAG | __IEC_FORCE_FLAG :
            __IEC_DEBUG_FLAG;
        dbgvardsc_t *dsc = &dbgvardsc[idx];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(__RegisterDebugVariable_case_t)
            __ANY(__RegisterDebugVariable_case_p)
        default:
            break;
        }
    }
}

#define __ResetDebugVariablesIterator_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

#define __ResetDebugVariablesIterator_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

void ResetDebugVariablesIterator(dbgvardsc_t *dsc)
{
    /* force debug flag to 0*/
    void *varp = dsc->ptr;
    switch(dsc->type){
        __ANY(__ResetDebugVariablesIterator_case_t)
        __ANY(__ResetDebugVariablesIterator_case_p)
    default:
        break;
    }
}

void ResetDebugVariables(void)
{
    __for_each_variable_do(ResetDebugVariablesIterator);
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &buffer_state,
        BUFFER_BUSY,
        BUFFER_FREE);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = buffer_cursor - debug_buffer;
        *buffer = debug_buffer;
    }
    return wait_error;
}
#endif
#endif

