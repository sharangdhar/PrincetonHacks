//returns an int to be made into a binary string for game
uint32_t brainData(unint32_t* wave, uint32_t atten, uint32_t med){
  size_t len = 8;
  size_t result = 0;
  
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
  uint32_t max = getMax(waves, len);
  uint32_t min = getMin(waves, len);
  uint32_t = max-min;
  //synced waves increase focus
  result -= diff/min;
  
  //scale result based on how we're going to put together the binary string
  return result;  //change scaling factor as needed
}

//gets the min in the array
uint32_t getMin (uint32_t* array, size_t len){
  uint32_t min = array[0];
  for (size_t i = 1; i < len; i++){
    if (array[i] < min)
	  min = wave[i];
  }
  return min;
}

//gets the max in the array
uint32_t getMax (uinte32_t* array, size_t len){
  uint32_t min = array[0];
  for (size_t i = 1; i < len; i++){
    if (array[i] > max)
	  max = array[i];
  }
  return max;
}
