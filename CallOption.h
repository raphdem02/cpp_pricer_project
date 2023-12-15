#pragma once
#include "VanillaOption.h"
#include <iostream>

class CallOption : public VanillaOption
{
	public:
		CallOption(double, double);
		~CallOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
