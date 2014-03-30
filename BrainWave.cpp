#include "BrainWave.h"

BrainWave::BrainWave(Brain *br) {
	b = br;
}

boolean BrainWave::refresh() {
	return b->update();
}

char* BrainWave::error() {
	return b->readErrors();
}

boolean BrainWave::poorSignal() {
	return b->readSignalQuality() < 100;
}

uint8_t BrainWave::attention() {
	return b->readAttention();
}

uint8_t BrainWave::meditation() {
	return b->readMeditation();
}

uint32_t* BrainWave::brainData() {
	return b->readPowerArray();
}
