#pragma once
#include "Option.h"


class DigitalOption : public Option
{
	private:
		double _strike;
        
    public:
		DigitalOption(double, double);
		~DigitalOption();

		double GetStrike() override;
		bool isDigital() override;

		virtual OptionType GetOptionType() override = 0;
		virtual double payoff(double) override = 0;

		friend class BlackScholesPricer;

	
};


class DigitalCallOption : public DigitalOption
{
	public:
		DigitalCallOption(double, double);
		~DigitalCallOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};


class DigitalPutOption : public DigitalOption
{
	public:
		DigitalPutOption(double, double);
		~DigitalPutOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
