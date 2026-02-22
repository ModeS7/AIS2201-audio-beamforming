#ifndef SAMPLETIMER_H
#define SAMPLETIMER_H

#include <arduino.h>

/** A class to handle timing for sampling a signal at regular intervals.
 *  Sample time is set in microseconds. Calls to function "timeTick" returns
 *  "true" boolean value if a number T_s microseconds has passed since the
 *  last sampling time.
 */
class SampleTimer
{
  public:
    bool timeTick();
    SampleTimer(unsigned long T_s);
  private:
    unsigned long previousMicros;
    unsigned long T_s;
};

#endif
