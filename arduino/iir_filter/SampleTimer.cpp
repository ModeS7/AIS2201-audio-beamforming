#include "SampleTimer.h"

bool SampleTimer::timeTick()
{
  unsigned long currentMicros = micros();
  bool expired = (currentMicros>=previousMicros + T_s);
  if(expired)
  {
    previousMicros = currentMicros;
  }
  return expired;
}

SampleTimer::SampleTimer(unsigned long T_s) : T_s(T_s), previousMicros(0) {};
