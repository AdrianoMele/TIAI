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
#define BUFFER_SIZE 249

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
extern MANAGECOUNTERS RES0__INSTANCE1;
extern MANAGEBUTTONLIGHTS RES0__INSTANCE2;
extern MAIN RES0__INSTANCE3;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_BOOL_t RES0__HIGHSENS;
extern __IEC_BOOL_t RES0__LOWSENS;
extern __IEC_BOOL_t RES0__PALLETSENS;
extern __IEC_BOOL_t RES0__LOADED;
extern __IEC_BOOL_t RES0__LEFTENTRY;
extern __IEC_BOOL_t RES0__LEFTEXIT;
extern __IEC_BOOL_t RES0__RIGHTENTRY;
extern __IEC_BOOL_t RES0__RIGHTEXIT;
extern __IEC_BOOL_t RES0__STARTBUTTON;
extern __IEC_BOOL_t RES0__RESETBUTTON;
extern __IEC_BOOL_t RES0__STOPBUTTON;
extern __IEC_BOOL_t RES0__EMERGENCYSTOP;
extern __IEC_BOOL_t RES0__AUTOMODE;
extern __IEC_BOOL_t RES0__STOPINTERNAL;
extern __IEC_BOOL_t RES0__RESETINTERNAL;
extern __IEC_BOOL_t RES0__CONVENTRY;
extern __IEC_BOOL_t RES0__LOAD;
extern __IEC_BOOL_t RES0__UNLOAD;
extern __IEC_BOOL_t RES0__TRANSFLEFT;
extern __IEC_BOOL_t RES0__TRANSFRIGHT;
extern __IEC_BOOL_t RES0__CONVLEFT;
extern __IEC_BOOL_t RES0__CONVRIGHT;
extern __IEC_BOOL_t RES0__STARTLIGHT;
extern __IEC_BOOL_t RES0__RESETLIGHT;
extern __IEC_BOOL_t RES0__STOPLIGHT;
extern __IEC_BOOL_t RES0__WARNLIGHT;
extern __IEC_INT_t RES0__COUNTHIGH;
extern __IEC_INT_t RES0__COUNTLOW;
extern       MANAGECOUNTERS   RES0__INSTANCE1;
extern       MANAGEBUTTONLIGHTS   RES0__INSTANCE2;
extern       MAIN   RES0__INSTANCE3;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(RES0__HIGHSENS), BOOL_ENUM},
{&(RES0__LOWSENS), BOOL_ENUM},
{&(RES0__PALLETSENS), BOOL_ENUM},
{&(RES0__LOADED), BOOL_ENUM},
{&(RES0__LEFTENTRY), BOOL_ENUM},
{&(RES0__LEFTEXIT), BOOL_ENUM},
{&(RES0__RIGHTENTRY), BOOL_ENUM},
{&(RES0__RIGHTEXIT), BOOL_ENUM},
{&(RES0__STARTBUTTON), BOOL_ENUM},
{&(RES0__RESETBUTTON), BOOL_ENUM},
{&(RES0__STOPBUTTON), BOOL_ENUM},
{&(RES0__EMERGENCYSTOP), BOOL_ENUM},
{&(RES0__AUTOMODE), BOOL_ENUM},
{&(RES0__STOPINTERNAL), BOOL_ENUM},
{&(RES0__RESETINTERNAL), BOOL_ENUM},
{&(RES0__CONVENTRY), BOOL_ENUM},
{&(RES0__LOAD), BOOL_ENUM},
{&(RES0__UNLOAD), BOOL_ENUM},
{&(RES0__TRANSFLEFT), BOOL_ENUM},
{&(RES0__TRANSFRIGHT), BOOL_ENUM},
{&(RES0__CONVLEFT), BOOL_ENUM},
{&(RES0__CONVRIGHT), BOOL_ENUM},
{&(RES0__STARTLIGHT), BOOL_ENUM},
{&(RES0__RESETLIGHT), BOOL_ENUM},
{&(RES0__STOPLIGHT), BOOL_ENUM},
{&(RES0__WARNLIGHT), BOOL_ENUM},
{&(RES0__COUNTHIGH), INT_ENUM},
{&(RES0__COUNTLOW), INT_ENUM},
{&(RES0__INSTANCE1.LEFTEXIT), BOOL_P_ENUM},
{&(RES0__INSTANCE1.RIGHTEXIT), BOOL_P_ENUM},
{&(RES0__INSTANCE1.RESETBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE1.STOPLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE1.COUNTHIGH), INT_P_ENUM},
{&(RES0__INSTANCE1.COUNTLOW), INT_P_ENUM},
{&(RES0__INSTANCE1.RESETINTERNAL), BOOL_P_ENUM},
{&(RES0__INSTANCE1.PRESETVALUE), INT_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.OUT), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.AUX), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG1.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.OUT), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.AUX), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.DOUBLETRIG0.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.CU), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.R), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.PV), INT_ENUM},
{&(RES0__INSTANCE1.CTU0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.CV), INT_ENUM},
{&(RES0__INSTANCE1.CTU0.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU0.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.CU), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.R), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.PV), INT_ENUM},
{&(RES0__INSTANCE1.CTU1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.CV), INT_ENUM},
{&(RES0__INSTANCE1.CTU1.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU1.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE1.AND9_OUT), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE2.STARTBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE2.RESETBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE2.STOPBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE2.STOPINTERNAL), BOOL_P_ENUM},
{&(RES0__INSTANCE2.STARTLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.RESETLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.STOPLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.EMERGENCYSTOP), BOOL_P_ENUM},
{&(RES0__INSTANCE2.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.F_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE2.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE3.HIGHSENS), BOOL_P_ENUM},
{&(RES0__INSTANCE3.LOWSENS), BOOL_P_ENUM},
{&(RES0__INSTANCE3.PALLETSENS), BOOL_P_ENUM},
{&(RES0__INSTANCE3.LOADED), BOOL_P_ENUM},
{&(RES0__INSTANCE3.LEFTENTRY), BOOL_P_ENUM},
{&(RES0__INSTANCE3.LEFTEXIT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.RIGHTENTRY), BOOL_P_ENUM},
{&(RES0__INSTANCE3.RIGHTEXIT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.STARTBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE3.RESETBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE3.STOPBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE3.STOPINTERNAL), BOOL_P_ENUM},
{&(RES0__INSTANCE3.RESETINTERNAL), BOOL_P_ENUM},
{&(RES0__INSTANCE3.STOPLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.STARTLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.EMERGENCYSTOP), BOOL_P_ENUM},
{&(RES0__INSTANCE3.AUTOMODE), BOOL_P_ENUM},
{&(RES0__INSTANCE3.CONVENTRY), BOOL_P_ENUM},
{&(RES0__INSTANCE3.LOAD), BOOL_P_ENUM},
{&(RES0__INSTANCE3.UNLOAD), BOOL_P_ENUM},
{&(RES0__INSTANCE3.TRANSFLEFT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.TRANSFRIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.CONVLEFT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.CONVRIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.WARNLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.PALLETMAXWAIT), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE3.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG5.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG5.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG5.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG5.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG6.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG6.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG6.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG6.M), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[0].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__action_list[0].state), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[0]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[1].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[1]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[2].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[2]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[3].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[3]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[4]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[4].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[5]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[5].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[6]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[7]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[6].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[8]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[9]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[7].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[10]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[11]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[12]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[8].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[13]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[14]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[15]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[16]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[9].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[17]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[18]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[10].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[19]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[20]), BOOL_ENUM},
{&(RES0__INSTANCE3.__step_list[11].X), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[21]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[22]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[23]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[24]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[25]), BOOL_ENUM},
{&(RES0__INSTANCE3.__debug_transition_list[26]), BOOL_ENUM}
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

