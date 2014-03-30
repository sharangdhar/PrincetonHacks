#ifndef Headset_h
#define Headset_h

#include "Arduino.h"

class Head {
	public:
		uint32_t brainData(uint32_t* wave, uint8_t atten, uint8_t med);
	private:
		uint32_t getMin (uint32_t* array, size_t len);
		uint32_t getMax (uint32_t* array, size_t len);
};

#endif
