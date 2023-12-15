#pragma once
#include "AmericanOption.h"
#include <vector>

class AmericanCallOption: public AmericanOption{
    public:
        AmericanCallOption(double,double);
        ~AmericanCallOption();
        OptionType GetOptionType() override;
        double payoff(double) override;
};