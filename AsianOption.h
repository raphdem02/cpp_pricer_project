#pragma once
#include "Option.h"
#include <vector>



class AsianOption : public Option{
    protected:
        std::vector<double> _timeSteps;
        double _strike;
    
    public:
        AsianOption(std::vector<double>,double);
        ~AsianOption();
        
        std::vector<double> getTimeSteps() override;
        double payoffPath(std::vector<double>) override;
        virtual double payoff(double) override = 0;
		virtual OptionType GetOptionType() override = 0;
        double GetStrike() override;

        bool isAsianOption() override;
};




