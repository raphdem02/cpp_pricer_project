#pragma once
#include <iostream>
#include <vector>

enum class OptionType {Call, Put};

class Option{
    private: 

        double _expiry;

    public:
        Option(double);
        virtual ~Option(); //destructeur virtuel
        double getExpiry();

        virtual double payoff(double)=0;
        virtual double GetStrike() =0;
        virtual OptionType GetOptionType() = 0;
        virtual double payoffPath(std::vector<double>);
        virtual bool isDigital();
        virtual std::vector<double> getTimeSteps();
        virtual bool isAsianOption();
        virtual bool isAmericanOption();
    
};


