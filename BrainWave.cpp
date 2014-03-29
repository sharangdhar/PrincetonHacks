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
	uint32_t* waves = malloc(8*sizeof(uint32_t));
	waves[0] = b.readDelta(); 
	waves[1] = b.readTheta();
	waves[2] = b.readLowAlpha();
	waves[3] = b.readHighAlpha();
	waves[4] = b.readLowBeat();
	waves[5] = b.readHighBeta();
	waves[6] = b.readLowGamma();
	waves[7] = b.readHighGamma();
	return waves;
	//return b.readPowerArray();
}
