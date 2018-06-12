//
//
//
//
//
//

#ifndef _RECEIVER_IR_H_
#define _RECEIVER_IR_H_

#include <mbed.h>

#include "RemoteIR.h"

//
//
//
class ReceiverIR {
public:

//
//
//
//
//
    explicit ReceiverIR(PinName rxpin);
    
//
//
//
    ~ReceiverIR();

//
//
//
    typedef enum {
        Idle,
        Receiving,
        Received
    } State;
    
//
//
//
//
//
    State getState();
    
//
//
//
//
//
//
//
//
//
    int getData(RemoteIR::Format *format, uint8_t *buf, int bitlength);
    
private:
    
    typedef struct {
        RemoteIR::Format format;
        int bitcount;
        uint8_t buffer[64];
    } data_t;
    
    typedef struct {
        State state;
        int c1;
        int c2;
        int c3;
        int d1;
        int d2;
    } work_t;

    InterruptIn evt;    /**< Interrupt based input for input. */
    Timer timer;        /**< Timer for WDT. */
    Ticker ticker;      /**< Tciker for tick. */
    Timeout timeout;    /**< Timeout for tail. */

    data_t data;
    work_t work;
    
    void init_state(void);

    void isr_wdt(void);
    void isr_fall(void);
    void isr_rise(void);
    
//
//
//
    void isr_timeout(void);

};

#endif

