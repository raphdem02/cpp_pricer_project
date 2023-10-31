#pragma once
#include "Option.h"
#include <vector>


#pragma region AsianOp
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
#pragma endregion

#pragma region AsianCallOp
class AsianCallOption : public AsianOption{
    public:
        AsianCallOption(std::vector<double>,double);
        ~AsianCallOption();

        OptionType GetOptionType() override;
        double payoff(double) override;
};


#pragma endregion

#pragma region AsianPutOp
class AsianPutOption : public AsianOption{

	public:
		AsianPutOption(std::vector<double>, double);
		~AsianPutOption();

		OptionType GetOptionType() override;
		double payoff(double) override;
};
#pragma endregion