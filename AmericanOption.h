#pragma once
#include "Option.h"
#include <vector>



class AmericanOption: public Option {

    protected:
        double _strike;

    public:
        AmericanOption(double,double);
        ~AmericanOption();
        bool isAmericanOption() override;
        double GetStrike() override;


};


