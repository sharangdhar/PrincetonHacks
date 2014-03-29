#include "BrainWave.h"

BrainWave(Brain brain) {
	b = brain;
}

boolean BrainWave:update() {
	return b.update();
}

char* BrainWave:error() {
	return b.readErrors();
}

boolean BrainWave:poorSignal() {
	return b.readSignalQuality() < 100;
}

uint8_t attention() {
	return b.readAttention();
}

uint8_t meditation() {
	return b.readMeditation();
}

uint32_t* brainData() {
	return b.readPowerArray();
}
