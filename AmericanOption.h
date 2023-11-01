#include "Option.h"
#include <vector>
#pragma once

#pragma region AmericanOp
class AmericanOption: public Option {

    protected:
        double _strike;

    public:
        AmericanOption(double,double);
        ~AmericanOption();
        bool isAmericanOption() override;
        double GetStrike() override;


};
#pragma endregion

#pragma region AmericanCallOp

class AmericanCallOption: public AmericanOption{
    public:
        AmericanCallOption(double,double);
        ~AmericanCallOption();
        OptionType GetOptionType() override;
        double payoff(double) override;
};

#pragma endregion

#pragma region AmericanPutOp
class AmericanPutOption : public AmericanOption{
    public:
        AmericanPutOption(double , double);
        ~AmericanPutOption();
        OptionType GetOptionType() override;
        double payoff(double) override;
};

#pragma endregion