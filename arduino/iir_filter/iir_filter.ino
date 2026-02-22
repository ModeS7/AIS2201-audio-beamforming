#include <MCP_DAC.h>
#include "SampleTimer.h"
#include "Filter.h"

// Input pin for analog signal
#define SIG_INPUT = A0

// Configuration of output to external DAC
MCP4911 MCP(11, 13);  // Declare an object for handling of DAC
#define CS_PIN 10  // "Chip Select" output pin on Arduino Uno

// Set sampling period
#define T_s 500 // Sampleperiode er 500 mikrosekund
SampleTimer sigTimer(T_s); // Declare SampleTimer instance



void setup()
{
  MCP.begin(CS_PIN);
}

void loop()
{

  
  if(sigTimer.timeTick())
  {
    float x = (float)analogRead(A0);
    float y = filter(x);
    MCP.analogWrite((int)y, 0);
  }
}
