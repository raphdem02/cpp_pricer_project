#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

DigitalPutOption::~DigitalPutOption() { }

OptionType DigitalPutOption::GetOptionType() { return OptionType::Put; }

double DigitalPutOption::payoff(double z)
{
	if (z <= GetStrike())
		return 1;
	else
		return 0;
}
