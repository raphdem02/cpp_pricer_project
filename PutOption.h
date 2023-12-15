#pragma once
#include "VanillaOption.h"
#include <iostream>

class PutOption : public VanillaOption
{
	public:
		PutOption(double, double);
		~PutOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
