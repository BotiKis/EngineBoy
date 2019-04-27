#include "SampleEngine.h"

SampleEngine engine;

void setup() {
	engine.setup();
}

void loop() {

	if(!engine.arduboy.nextFrame())
		return;

	engine.update();
	engine.display();
}
