#ifndef BrainWave_h
#define BrainWave_h

#include "Arduino.h"

class BrainWave {
	public:
		// Constructor, 8-bit uint for transmit input pin
		BrainWave(uint8_t pinIn);
		
		// Call update function to receive next byte in serial sequence
		// Updates values of attention, meditation, raw brainwaves, etc. once entire
		//		packet is parsed, requires multiple calls at frequency higher than 
		//	 	baud rate of TGAM chip
		// True if update was successful
		boolean update();
		
		// Most recent error string of update function when unsuccessful
		char* error();
		
		// Bad signal
		boolean poorSignal();
		
		// Returns values of attention and meditation as 32 bit integers (24 bit accuracy)
		uint32_t attention();
		uint32_t meditation();
		
		// Array of raw data:
		// {Delta, Theta, LowAlpha, HighAlpha, LowBeta, HighBeta, LowGamma, HighGamma}
		uint32_t* brainData();
		
	private:
	
	/*
	
	DON'T WORRY ABOUT IT 
	DON'T BREAK THE SACRED CURTAIN OF THE INTERFACE / IMPLEMENTATION
	
	*/

}

#endif
