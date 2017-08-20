#ifndef _LDR_
#define _LDR_


#include <Arduino.h>
#include <math.h>


#define AREF      5.0       // tensione riferimento
#define RES       1024      // risoluzione (max)
#define GAMMA     0.66      // valore gamma tabella costruttore (0.6 - 0.8)
#define PULLDOWN  893       // pulldown resistor 1K
#define LDR_UNIT  75000     // resistenza del fotoresistore in condizioni di luce unitario
#define CONV_FC   0.0929    // 1 lux = 0.0929 footcandle

#define LDR_VREF    (AREF / RES)
#define LDR_RREF    (AREF * PULLDOWN)
#define ANTI_GAMMA  (-1.0 / GAMMA)


class LDR
{
    public:
        LDR() {}

        void setup(byte p);
        double read();

        double getLux()        const { return _lux; }
        double getFootCandle() const { return _lux * CONV_FC; }

    protected:
        byte _pin;
        double _lux;
};

#endif
