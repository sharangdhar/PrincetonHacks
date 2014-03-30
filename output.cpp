#include "Arduino.h"
#include "Output.h"

uint8_t output (uint32_t range){
  uint32_t r = random(1000000000) % range;
  return r > 110000;
}
