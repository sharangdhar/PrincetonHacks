#ifndef BrainWave_h
#define BrainWave_h

#include "Arduino.h"
#include "Brain.h"

class BrainWave {
	public:
		// Constructor, 8-bit uint for transmit input pin
		BrainWave(Brain *br);

		// Call update function to receive next byte in serial sequence
		// Updates values of attention, meditation, raw brainwaves, etc. once entire
		//		packet is parsed, requires multiple calls at frequency higher than 
		//	 	baud rate of TGAM chip
		// True if update was successful
		boolean refresh();

		// Most recent error string of update function when unsuccessful
		char* error();

		// Bad signal
		boolean poorSignal();

		// Returns values of attention and meditation as 32 bit integers (24 bit accuracy)
		uint8_t attention();
		uint8_t meditation();

		// Array of raw data:
		// {Delta, Theta, LowAlpha, HighAlpha, LowBeta, HighBeta, LowGamma, HighGamma}
		uint32_t* brainData();

	private:
		Brain *b;
};

#endif
