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



