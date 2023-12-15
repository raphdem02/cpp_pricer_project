#include "AmericanCallOption.h"
//Call
AmericanCallOption::AmericanCallOption(double expiry,double strike): AmericanOption(expiry,strike){}

AmericanCallOption::~AmericanCallOption(){}

OptionType AmericanCallOption::GetOptionType(){
    return OptionType::Call;
}

double AmericanCallOption::payoff(double spot_prices){
    if(spot_prices < _strike){
        return 0;
    }
    else{
        return spot_prices - _strike;
    }
}
