#include "Headset.h"

//returns an int to be made into a binary string for game
uint32_t Head::brainData(uint32_t* wave, uint8_t atten, uint8_t med){
  size_t len = 8;
  uint32_t result = 0;
  
  //weighted sum of each freq
  for (int i = 0; i < len; i++){
    result += (i+1)*wave[i];
  }
  
  result += atten;
  result -= med;
  uint32_t max = wave[0];

  //find how closely the waves are synced
  uint32_t max = wave[0];
  for (size_t i = 1; i < len; i++){
	if (wave[i] > max)
	  max = wave[i];
  }
  uint32_t min = wave[0];
  for (size_t i = 1; i < len; i++){
	if (wave[i] < min)
	  min = wave[i];
  }
  
  //synced waves increase focus
  result -= 8*(max-min);
  
  //scale result based on how we're going to put together the binary string
  return result % 100000000;  //change scaling factor as needed
}
