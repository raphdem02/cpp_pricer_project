#pragma once
#include "DigitalOption.h"

class DigitalCallOption : public DigitalOption
{
	public:
		DigitalCallOption(double, double);
		~DigitalCallOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
