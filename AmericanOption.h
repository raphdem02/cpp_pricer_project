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

class AmericanCallOption: public AmericanOption{
    public:
        AmericanCallOption(double,double);
        ~AmericanCallOption();
        OptionType GetOptionType() override;
        double payoff(double) override;
};


class AmericanPutOption : public AmericanOption{
    public:
        AmericanPutOption(double , double);
        ~AmericanPutOption();
        OptionType GetOptionType() override;
        double payoff(double) override;
};

