#include <Arduino.h>

#include "Stepper.h"

#define PIN_RA_STEP 23
#define PIN_RA_DIR 22

#define PIN_DEC_STEP 14
#define PIN_DEC_DIR 32

using Ra = Stepper<PIN_RA_STEP, PIN_RA_DIR>;
using Dec = Stepper<PIN_DEC_STEP, PIN_DEC_DIR>;

void setup()
{
  Serial.begin(115200);

  Ra::setup();
  Dec::setup();
  Serial.println("RA,DEC");
}

void loop()
{
  Serial.print(Ra::getCount());
  Serial.print(",");
  Serial.println(Dec::getCount());
  delay(200);
}