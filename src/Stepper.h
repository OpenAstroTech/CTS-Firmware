#include "Arduino.h"

template <uint8_t PIN_STEP, uint8_t PIN_DIR>
class Stepper
{
    volatile static int inc;
    volatile static int cnt;

public:
    void static setup()
    {
        pinMode(PIN_STEP, INPUT_PULLDOWN);
        pinMode(PIN_DIR, INPUT_PULLDOWN);

        attachInterrupt(PIN_STEP, isr_step, RISING);
    }

    static int getCount()
    {
        return cnt;
    }

private:
    static void IRAM_ATTR isr_step()
    {
        if (digitalRead(PIN_DIR))
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
};

template <uint8_t PIN_STEP, uint8_t PIN_DIR>
volatile int Stepper<PIN_STEP, PIN_DIR>::inc = 0;

template <uint8_t PIN_STEP, uint8_t PIN_DIR>
volatile int Stepper<PIN_STEP, PIN_DIR>::cnt = 0;