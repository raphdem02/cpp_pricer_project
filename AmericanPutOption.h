#pragma once
#include "AmericanOption.h"
#include <vector>

class AmericanPutOption : public AmericanOption{
    public:
        AmericanPutOption(double , double);
        ~AmericanPutOption();
        OptionType GetOptionType() override;
        double payoff(double) override;
};
