#include "DigitalOption.h"

DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry)
{
	if (strike <= 0)
		throw std::invalid_argument("Strike have to be positive");
	else
		_strike = strike;
}

DigitalOption::~DigitalOption() { }

// Overriden version returning the strike of the option
double DigitalOption::GetStrike() { return _strike; }

// Overriden version returning true to indicate that this option is digital
bool DigitalOption::isDigital() { return true; }

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
