#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption{
    public:
        AsianCallOption(std::vector<double>,double);
        ~AsianCallOption();

        OptionType GetOptionType() override;
        double payoff(double) override;
};
