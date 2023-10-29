#pragma once 
#include "Option.h"
#include <iostream>


class VanillaOption : public Option{

    private:
        double _strike;
    public: 
        VanillaOption(double, double);
        ~VanillaOption();

        double GetStrike() override; 
        virtual OptionType GetOptionType() override = 0;
        virtual double payoff(double) override = 0;

		friend class BlackScholesPricer;
};


class CallOption : public VanillaOption
{
	public:
		CallOption(double, double);
		~CallOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};



class PutOption : public VanillaOption
{
	public:
		PutOption(double, double);
		~PutOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
