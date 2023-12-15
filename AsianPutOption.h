#pragma once
#include "AsianOption.h"
class AsianPutOption : public AsianOption{

	public:
		AsianPutOption(std::vector<double>, double);
		~AsianPutOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
