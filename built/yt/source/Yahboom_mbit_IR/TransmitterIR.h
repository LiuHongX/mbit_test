//
//
//
//
//
//

#ifndef _TRANSMITTER_IR_H_
#define _TRANSMITTER_IR_H_

#include <mbed.h>

#include "RemoteIR.h"

//
//
//
class TransmitterIR {
public:

//
//
//
//
//
    explicit TransmitterIR(PinName txpin);

//
//
//
    ~TransmitterIR();

    typedef enum {
        Idle,
        Leader,
        Data,
        Trailer
    } State;

//
//
//
//
//
    State getState(void);

//
//
//
//
//
//
//
//
//
    int setData(RemoteIR::Format format, uint8_t *buf, int bitlength);

private:

    typedef struct {
        State state;
        int bitcount;
        int leader;
        int data;
        int trailer;
    } work_t;

    typedef struct {
        RemoteIR::Format format;
        int bitlength;
        uint8_t buffer[64];
    } data_t;

    PwmOut tx;
    Ticker ticker;
    data_t data;
    work_t work;

    void tick();

};

#endif
