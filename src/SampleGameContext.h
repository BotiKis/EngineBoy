#pragma once

#include <Arduboy2.h>
#include <Tinyfont.h>

class SampleGameContext
{
public:

	// Getters & setters
	uint16_t yValue(void) const
	{
		return this->_yValue;
	}

	void setYValue(uint16_t aVal)
	{
		this->_yValue = aVal;
	}

	const Tinyfont & tinyfont(void) const
	{
		return this->_tinyfont;
	}

private:
	uint16_t _yValue;
	Tinyfont _tinyfont = Tinyfont(Arduboy2Base::sBuffer, Arduboy2Base::width(), Arduboy2Base::height());
};
