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
#define BUFFER_SIZE 257

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
extern PROGRAM0 RES0__INSTANCE0;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_USINT_t RES0__STATE;
extern __IEC_BOOL_t RES0__DIR;
extern       PROGRAM0   RES0__INSTANCE0;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(RES0__STATE), USINT_ENUM},
{&(RES0__DIR), BOOL_ENUM},
{&(RES0__INSTANCE0.STATE), USINT_P_ENUM},
{&(RES0__INSTANCE0.DIR), BOOL_P_ENUM},
{&(RES0__INSTANCE0.READY), BOOL_ENUM},
{&(RES0__INSTANCE0.SNS0), BOOL_ENUM},
{&(RES0__INSTANCE0.SNS1), BOOL_ENUM},
{&(RES0__INSTANCE0.SNS2), BOOL_ENUM},
{&(RES0__INSTANCE0.SNS3), BOOL_ENUM},
{&(RES0__INSTANCE0.IND0), BOOL_ENUM},
{&(RES0__INSTANCE0.IND1), BOOL_ENUM},
{&(RES0__INSTANCE0.IND2), BOOL_ENUM},
{&(RES0__INSTANCE0.IND3), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ0), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ1), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ2), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ3), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ00), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ11), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ22), BOOL_ENUM},
{&(RES0__INSTANCE0.REQ33), BOOL_ENUM},
{&(RES0__INSTANCE0.UP), BOOL_ENUM},
{&(RES0__INSTANCE0.DOWN), BOOL_ENUM},
{&(RES0__INSTANCE0.OPEN), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.IN0), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.IN1), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.IN2), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.IN3), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.DATA0), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.DATA1), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER0.DATA), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER0.BOOL_TO_USINT22_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER0.BOOL_TO_USINT6_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER0.MUL25_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER0.ADD35_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.EN_USINT_STATE0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.EN_USINT_STATE0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.EN_USINT_STATE0.STATE), USINT_P_ENUM},
{&(RES0__INSTANCE0.EN_USINT_STATE0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.EN_USINT_STATE0.DATA), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.IN0), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.IN1), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.IN2), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.IN3), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.DATA0), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.DATA1), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.ENCODER1.DATA), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER1.BOOL_TO_USINT22_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER1.BOOL_TO_USINT6_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER1.MUL25_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.ENCODER1.ADD35_OUT), USINT_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.STATE), USINT_P_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.DIR), BOOL_P_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.I), USINT_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.J), USINT_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.H), USINT_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.DATA), USINT_ENUM},
{&(RES0__INSTANCE0.IN_USINT_QUEUE0.OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.OUT_USINT_QUEUE0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.OUT_USINT_QUEUE0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.OUT_USINT_QUEUE0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.OUT_USINT_QUEUE0.DATA), USINT_ENUM},
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
{&(RES0__INSTANCE0.R_TRIG5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.M), BOOL_ENUM},
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
{&(RES0__INSTANCE0.R_TRIG8.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG10.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG10.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG10.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG10.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG10.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG11.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG11.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG11.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG11.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG11.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG12.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG12.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG12.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG12.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG12.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG13.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG13.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG13.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG13.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG13.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG14.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG14.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG14.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG14.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG14.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG15.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG15.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG15.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG15.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG15.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG16.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG16.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG16.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG16.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG16.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG17.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG17.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG17.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG17.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG17.M), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG18.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG18.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG18.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG18.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG18.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG19.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG19.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG19.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG19.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG19.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG20.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG20.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG20.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG20.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG20.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG21.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG21.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG21.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG21.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG21.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG22.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG22.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG22.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG22.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG22.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG23.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG23.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG23.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG23.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG23.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG24.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG24.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG24.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG24.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG24.M), BOOL_ENUM},
{&(RES0__INSTANCE0.EQ103_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT44_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT50_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG25.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG25.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG25.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG25.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG25.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG26.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG26.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG26.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG26.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG26.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG27.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG27.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG27.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG27.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG27.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG28.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG28.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG28.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG28.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG28.M), BOOL_ENUM}
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

