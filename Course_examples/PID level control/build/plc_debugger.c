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
#define BUFFER_SIZE 325

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
extern MANAGEDISPLAYS RES0__INSTANCE1;
extern MANUALMODE RES0__INSTANCE2;
extern AUTOMODE RES0__INSTANCE3;
extern MANAGELIGHTS RES0__INSTANCE0;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_BOOL_t RES0__STARTBUTTON;
extern __IEC_BOOL_t RES0__STOPBUTTON;
extern __IEC_BOOL_t RES0__MANUAL;
extern __IEC_BOOL_t RES0__AUTO;
extern __IEC_BOOL_t RES0__FILLVALVEMAN;
extern __IEC_BOOL_t RES0__DISCHARGEVALVEMAN;
extern __IEC_BOOL_t RES0__STARTLIGHT;
extern __IEC_BOOL_t RES0__STOPLIGHT;
extern __IEC_BOOL_t RES0__FILLMANUALLIGHT;
extern __IEC_BOOL_t RES0__DISCHARGEMANUALLIGHT;
extern __IEC_INT_t RES0__LEVELMETER;
extern __IEC_INT_t RES0__FLOWMETER;
extern __IEC_INT_t RES0__SETPOINT;
extern __IEC_INT_t RES0__KP;
extern __IEC_INT_t RES0__KI;
extern __IEC_INT_t RES0__KD;
extern __IEC_INT_t RES0__DISCHARGEVALVE;
extern __IEC_INT_t RES0__DISCHARGEVALVEPOS;
extern __IEC_INT_t RES0__FILLVALVE;
extern __IEC_INT_t RES0__FILLVALVEPOS;
extern __IEC_INT_t RES0__KPVAL;
extern __IEC_INT_t RES0__KIVAL;
extern __IEC_INT_t RES0__KDVAL;
extern __IEC_INT_t RES0__SETPOINTVAL;
extern __IEC_INT_t RES0__ERRORVAL;
extern __IEC_INT_t RES0__LEVELVAL;
extern       MANAGEDISPLAYS   RES0__INSTANCE1;
extern       MANUALMODE   RES0__INSTANCE2;
extern       AUTOMODE   RES0__INSTANCE3;
extern       MANAGELIGHTS   RES0__INSTANCE0;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(RES0__STARTBUTTON), BOOL_ENUM},
{&(RES0__STOPBUTTON), BOOL_ENUM},
{&(RES0__MANUAL), BOOL_ENUM},
{&(RES0__AUTO), BOOL_ENUM},
{&(RES0__FILLVALVEMAN), BOOL_ENUM},
{&(RES0__DISCHARGEVALVEMAN), BOOL_ENUM},
{&(RES0__STARTLIGHT), BOOL_ENUM},
{&(RES0__STOPLIGHT), BOOL_ENUM},
{&(RES0__FILLMANUALLIGHT), BOOL_ENUM},
{&(RES0__DISCHARGEMANUALLIGHT), BOOL_ENUM},
{&(RES0__LEVELMETER), INT_ENUM},
{&(RES0__FLOWMETER), INT_ENUM},
{&(RES0__SETPOINT), INT_ENUM},
{&(RES0__KP), INT_ENUM},
{&(RES0__KI), INT_ENUM},
{&(RES0__KD), INT_ENUM},
{&(RES0__DISCHARGEVALVE), INT_ENUM},
{&(RES0__DISCHARGEVALVEPOS), INT_ENUM},
{&(RES0__FILLVALVE), INT_ENUM},
{&(RES0__FILLVALVEPOS), INT_ENUM},
{&(RES0__KPVAL), INT_ENUM},
{&(RES0__KIVAL), INT_ENUM},
{&(RES0__KDVAL), INT_ENUM},
{&(RES0__SETPOINTVAL), INT_ENUM},
{&(RES0__ERRORVAL), INT_ENUM},
{&(RES0__LEVELVAL), INT_ENUM},
{&(RES0__INSTANCE1.LEVELMETER), INT_P_ENUM},
{&(RES0__INSTANCE1.FLOWMETER), INT_P_ENUM},
{&(RES0__INSTANCE1.SETPOINT), INT_P_ENUM},
{&(RES0__INSTANCE1.KP), INT_P_ENUM},
{&(RES0__INSTANCE1.KI), INT_P_ENUM},
{&(RES0__INSTANCE1.KD), INT_P_ENUM},
{&(RES0__INSTANCE1.DISCHARGEVALVE), INT_P_ENUM},
{&(RES0__INSTANCE1.DISCHARGEVALVEPOS), INT_P_ENUM},
{&(RES0__INSTANCE1.FILLVALVE), INT_P_ENUM},
{&(RES0__INSTANCE1.FILLVALVEPOS), INT_P_ENUM},
{&(RES0__INSTANCE1.KPVAL), INT_P_ENUM},
{&(RES0__INSTANCE1.KIVAL), INT_P_ENUM},
{&(RES0__INSTANCE1.KDVAL), INT_P_ENUM},
{&(RES0__INSTANCE1.SETPOINTVAL), INT_P_ENUM},
{&(RES0__INSTANCE1.ERRORVAL), INT_P_ENUM},
{&(RES0__INSTANCE1.LEVELVAL), INT_P_ENUM},
{&(RES0__INSTANCE1.LEVELCONVFACTOR), REAL_ENUM},
{&(RES0__INSTANCE1.SETPOINTCONVFACTOR), REAL_ENUM},
{&(RES0__INSTANCE1.KPCONVFACTOR), INT_ENUM},
{&(RES0__INSTANCE1.KICONVFACTOR), INT_ENUM},
{&(RES0__INSTANCE1.KDCONVFACTOR), INT_ENUM},
{&(RES0__INSTANCE2.MANUAL), BOOL_P_ENUM},
{&(RES0__INSTANCE2.STARTLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.STOPLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.FILLMANUALLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.DISCHARGEMANUALLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE2.FILLVALVE), INT_P_ENUM},
{&(RES0__INSTANCE2.DISCHARGEVALVE), INT_P_ENUM},
{&(RES0__INSTANCE3.AUTO), BOOL_P_ENUM},
{&(RES0__INSTANCE3.STARTLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE3.SETPOINTVAL), INT_P_ENUM},
{&(RES0__INSTANCE3.LEVELVAL), INT_P_ENUM},
{&(RES0__INSTANCE3.FILLVALVE), INT_P_ENUM},
{&(RES0__INSTANCE3.DISCHARGEVALVE), INT_P_ENUM},
{&(RES0__INSTANCE3.KPVAL), INT_P_ENUM},
{&(RES0__INSTANCE3.KIVAL), INT_P_ENUM},
{&(RES0__INSTANCE3.KDVAL), INT_P_ENUM},
{&(RES0__INSTANCE3.KP_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.KI_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.KD_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.TI_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.TD_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.SETPOINT_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.LEVEL_INTERNAL), REAL_ENUM},
{&(RES0__INSTANCE3.CYCLE), TIME_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.AUTO), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.PV), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.SP), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.X0), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.KP), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.TR), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.TD), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.CYCLE), TIME_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.XOUT), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ERROR), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.RUN), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.R1), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.XIN), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.X0), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.CYCLE), TIME_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.ITERM.XOUT), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.RUN), BOOL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.XIN), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.CYCLE), TIME_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.XOUT), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.X1), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.X2), REAL_ENUM},
{&(RES0__INSTANCE3.PID_LEVEL.DTERM.X3), REAL_ENUM},
{&(RES0__INSTANCE3.CONTROL), REAL_ENUM},
{&(RES0__INSTANCE3.KPMAX), REAL_ENUM},
{&(RES0__INSTANCE3.KIMAX), REAL_ENUM},
{&(RES0__INSTANCE3.KDMAX), REAL_ENUM},
{&(RES0__INSTANCE0.STARTBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE0.STOPBUTTON), BOOL_P_ENUM},
{&(RES0__INSTANCE0.STARTLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE0.STOPLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE0.FILLVALVEMAN), BOOL_P_ENUM},
{&(RES0__INSTANCE0.DISCHARGEVALVEMAN), BOOL_P_ENUM},
{&(RES0__INSTANCE0.FILLMANUALLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE0.DISCHARGEMANUALLIGHT), BOOL_P_ENUM},
{&(RES0__INSTANCE0.MANUAL), BOOL_P_ENUM},
{&(RES0__INSTANCE0.AUX1), BOOL_ENUM},
{&(RES0__INSTANCE0.AUX2), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.M), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.M), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.M), BOOL_ENUM}
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

