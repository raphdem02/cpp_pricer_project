#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

DigitalCallOption::~DigitalCallOption() { }

OptionType DigitalCallOption::GetOptionType() { return OptionType::Call; }

double DigitalCallOption::payoff(double z)
{
	if (z >= GetStrike())
		return 1;
	else
		return 0;
}
