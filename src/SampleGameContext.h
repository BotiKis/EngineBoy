#pragma once

#include <Arduino.h>

class SampleGameContext
{
public:

	// Getters & setters
	uint16_t yValue(void) const
	{
		return _yValue;
	}

	void setYValue(uint16_t aVal)
	{
		_yValue = aVal;
	}

private:
	uint16_t _yValue;
};
