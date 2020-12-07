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
#define BUFFER_SIZE 281

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
extern MAIN RES0__INSTANCE0;
extern MAINLD RES0__INSTANCE2;
extern SMISTATORE RES0__INSTANCE1;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_BOOL_t RES0__AT_UNLOAD_SENSOR;
extern       MAIN   RES0__INSTANCE0;
extern       MAINLD   RES0__INSTANCE2;
extern       SMISTATORE   RES0__INSTANCE1;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(RES0__AT_UNLOAD_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.START_BUTTON), BOOL_ENUM},
{&(RES0__INSTANCE0.AT_ENTRY_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.AT_LOAD_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.AT_MIDDLE_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.X_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.Z_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.MANUAL), BOOL_ENUM},
{&(RES0__INSTANCE0.AUTO), BOOL_ENUM},
{&(RES0__INSTANCE0.FORW_BUTTON), BOOL_ENUM},
{&(RES0__INSTANCE0.AT_UNLOAD_SENSOR), BOOL_P_ENUM},
{&(RES0__INSTANCE0.AT_EXIT_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRIEVE_BUTTON), BOOL_ENUM},
{&(RES0__INSTANCE0.CARRELLO_ENTRATA), BOOL_ENUM},
{&(RES0__INSTANCE0.CARRELLO_CARICO), BOOL_ENUM},
{&(RES0__INSTANCE0.START_LIGHT), BOOL_ENUM},
{&(RES0__INSTANCE0.CARICA_PALLET), BOOL_ENUM},
{&(RES0__INSTANCE0.LIFT), BOOL_ENUM},
{&(RES0__INSTANCE0.SCARICA_PALLET), BOOL_ENUM},
{&(RES0__INSTANCE0.FORW_LIGHT), BOOL_ENUM},
{&(RES0__INSTANCE0.ERRORE_0), BOOL_ENUM},
{&(RES0__INSTANCE0.CARRELLO_USCITA), BOOL_ENUM},
{&(RES0__INSTANCE0.CARRELLO_SCARICO), BOOL_ENUM},
{&(RES0__INSTANCE0.RETR_LIGHT), BOOL_ENUM},
{&(RES0__INSTANCE0.POSITION), INT_ENUM},
{&(RES0__INSTANCE0.MANUAL_POSITION), INT_ENUM},
{&(RES0__INSTANCE0.COUNTER), INT_ENUM},
{&(RES0__INSTANCE0.SYNC0), BOOL_ENUM},
{&(RES0__INSTANCE0.SYNC1), BOOL_ENUM},
{&(RES0__INSTANCE0.SYNC2), BOOL_ENUM},
{&(RES0__INSTANCE0.SYNC3), BOOL_ENUM},
{&(RES0__INSTANCE0.SYNC4), BOOL_ENUM},
{&(RES0__INSTANCE0.TRAS_FERMO), BOOL_ENUM},
{&(RES0__INSTANCE0.I), INT_ENUM},
{&(RES0__INSTANCE0.TROVATO), BOOL_ENUM},
{&(RES0__INSTANCE0.POS), INT_ENUM},
{&(RES0__INSTANCE0.MAX_DIM), INT_ENUM},
{&(RES0__INSTANCE0.CONT_MAG), INT_ENUM},
{&(RES0__INSTANCE0.OK_RETRIEVE), BOOL_ENUM},
{&(RES0__INSTANCE0.OK_INS), BOOL_ENUM},
{&(RES0__INSTANCE0.OK_RET_POS), BOOL_ENUM},
{&(RES0__INSTANCE0.SISTEMA_AVVIATO), BOOL_ENUM},
{&(RES0__INSTANCE0.STORE_AVVIATO), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRIEVE_AVVIATO), BOOL_ENUM},
{&(RES0__INSTANCE0.FORWARD_AVVIATO), BOOL_ENUM},
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
{&(RES0__INSTANCE0.__step_list[5].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[5]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[6].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[0].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[1].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[6]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[7].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[7]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[8].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[8]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[9].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[9]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[10].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[2].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[10]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[11].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[3].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[4].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[11]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[12]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[12].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[13]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[13].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[5].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[14]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[15]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[14].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[16]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[15].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[17]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[16].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[18]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[17].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[19]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[18].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[20]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[19].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[21]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[20].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[22]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[21].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[23]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[22].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[24]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[23].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[25]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[24].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[26]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[25].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[27]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[26].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[28]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[27].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[6].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[29]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[28].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[30]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[29].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[31]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[30].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[7].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[32]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[31].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[33]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[32].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[8].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__action_list[9].state), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[34]), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[35]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[33].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[36]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[34].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[37]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[35].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[38]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[36].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[39]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[37].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[40]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[38].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[41]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[39].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[42]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[40].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[43]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[41].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[44]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[42].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[45]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[43].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[46]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[44].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[47]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[45].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[48]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[46].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[49]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[47].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[50]), BOOL_ENUM},
{&(RES0__INSTANCE0.__step_list[48].X), BOOL_ENUM},
{&(RES0__INSTANCE0.__debug_transition_list[51]), BOOL_ENUM},
{&(RES0__INSTANCE2.INIT), BOOL_ENUM},
{&(RES0__INSTANCE2.START_0), BOOL_ENUM},
{&(RES0__INSTANCE2.FORW_0), BOOL_ENUM},
{&(RES0__INSTANCE2.RETR_0), BOOL_ENUM},
{&(RES0__INSTANCE2.QUIETE_STORE), BOOL_ENUM},
{&(RES0__INSTANCE2.QUIETE_RET), BOOL_ENUM},
{&(RES0__INSTANCE2.QUIETE_FORW), BOOL_ENUM},
{&(RES0__INSTANCE2.QUIETE_CAR_SCAR), BOOL_ENUM},
{&(RES0__INSTANCE2.QUIETE_CAR_ENT), BOOL_ENUM},
{&(RES0__INSTANCE2.PROVA), BOOL_ENUM},
{&(RES0__INSTANCE2.PROVA2), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_UNLOAD_SENSOR), BOOL_P_ENUM},
{&(RES0__INSTANCE1.TURN_ENTRY), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_FRONT), BOOL_ENUM},
{&(RES0__INSTANCE1.PALLET_SENSOR), BOOL_ENUM},
{&(RES0__INSTANCE1.LOW), BOOL_ENUM},
{&(RES0__INSTANCE1.MEDIUM), BOOL_ENUM},
{&(RES0__INSTANCE1.HIGHT), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_RIGHT), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_RIGHT_EXIT), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_LEFT), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_LEFT_EXIT), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_FWD), BOOL_ENUM},
{&(RES0__INSTANCE1.AT_FWD_EXIT), BOOL_ENUM},
{&(RES0__INSTANCE1.ENTERCONVEYOR), BOOL_ENUM},
{&(RES0__INSTANCE1.ENTERCONVEYOR1), BOOL_ENUM},
{&(RES0__INSTANCE1.LOADED_TURN), BOOL_ENUM},
{&(RES0__INSTANCE1.RIGHTCONVEYOR), BOOL_ENUM},
{&(RES0__INSTANCE1.TURN), BOOL_ENUM},
{&(RES0__INSTANCE1.LOADED_TURN_RIGHT), BOOL_ENUM},
{&(RES0__INSTANCE1.LEFTCONVEYOR), BOOL_ENUM},
{&(RES0__INSTANCE1.FRCONVEYOR), BOOL_ENUM},
{&(RES0__INSTANCE1.WAIT), BOOL_ENUM},
{&(RES0__INSTANCE1.WAIT1), BOOL_ENUM},
{&(RES0__INSTANCE1.WAIT2), BOOL_ENUM},
{&(RES0__INSTANCE1.WAIT3), BOOL_ENUM},
{&(RES0__INSTANCE1.LEFT_OK), BOOL_ENUM},
{&(RES0__INSTANCE1.RIGHT_OK), BOOL_ENUM},
{&(RES0__INSTANCE1.FWD_OK), BOOL_ENUM},
{&(RES0__INSTANCE1.CONT), INT_ENUM},
{&(RES0__INSTANCE1.__step_list[0].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[0]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[1].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[1]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[2].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[2]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[3].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[3]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[4].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[4]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[5].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[5]), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[6]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[6].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[7]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[7].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[8]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[8].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[9]), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[10]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[9].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[11]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[10].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[12]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[11].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[13]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[12].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[14]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[13].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[15]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[14].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[16]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[15].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[17]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[16].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[18]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[17].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[19]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[18].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[20]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[19].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[21]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[20].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[22]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[21].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[23]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[22].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[24]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[23].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[25]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[24].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[26]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[25].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[27]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[26].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[28]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[27].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[29]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[28].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[30]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[29].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[31]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[30].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[32]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[31].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[33]), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[34]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[32].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[35]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[33].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__action_list[0].state), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[36]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[34].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[37]), BOOL_ENUM},
{&(RES0__INSTANCE1.__step_list[35].X), BOOL_ENUM},
{&(RES0__INSTANCE1.__action_list[1].state), BOOL_ENUM},
{&(RES0__INSTANCE1.__debug_transition_list[38]), BOOL_ENUM}
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

