#include "Headset.h"

//returns an int to be made into a binary string for game
uint32_t Head::brainData(uint32_t* wave, uint8_t atten, uint8_t med){
  size_t len = 8;
  uint32_t result = 0;
  
  //sum for the 
  //low delta
  result -= 2*wave[0];
  //higher theta is focused, lower theta is daydreaming
  result += wave[1]/2;
  //lower alpha waves;
  result -= wave[2] + wave[3];
  //high beta waves
  result += 2*(wave[4] + wave[5]);
  //high gamma waves
  result += wave[6] + wave[7];
  
  result += atten;
  result -= med;
  
  //find how closely the waves are synchronized
  uint32_t max = getMax(wave, len);
  uint32_t min = getMin(wave, len);
  uint32_t diff = max-min;
  //synced waves increase focus
  result -= diff/min;
  
  //scale result based on how we're going to put together the binary string
  return result % 1000000;  //change scaling factor as needed
}

//gets the min in the array
uint32_t Head::getMin (uint32_t* array, size_t len){
  uint32_t min = array[0];
  for (size_t i = 1; i < len; i++){
	if (array[i] < min)
	  min = array[i];
  }
  return min;
}

//gets the max in the array
uint32_t Head::getMax (uint32_t* array, size_t len){
  uint32_t max = array[0];
  for (size_t i = 1; i < len; i++){
	if (array[i] > max)
	  max = array[i];
  }
  return max;
}
