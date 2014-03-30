#include <SoftwareSerial.h>
#include "Brain.h"
#include "BrainWave.h"
#include "Headset.h"
#include "Output.h"

SoftwareSerial bluetooth = SoftwareSerial(3,2);
Brain *sensor = new Brain(Serial);
BrainWave wave = BrainWave(sensor);
Head head = Head();

uint8_t count;

uint32_t data;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  data = 0;
}

void loop() {

  uint8_t bits = output(data);
  
  if(count == 0)
    bluetooth.print(bits);
  
  if(wave.refresh()) {
    data = head.brainData(wave.brainData(), wave.attention(), 
            wave.meditation());
  }

  count++;
}
