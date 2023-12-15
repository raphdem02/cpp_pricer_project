#pragma once
#include "DigitalOption.h"


class DigitalPutOption : public DigitalOption
{
	public:
		DigitalPutOption(double, double);
		~DigitalPutOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
