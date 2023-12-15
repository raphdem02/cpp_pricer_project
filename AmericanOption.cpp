#include "AmericanOption.h"
#include <vector>


AmericanOption::AmericanOption(double expiry,double strike):Option(expiry){
    if(strike<=0){
        throw std::invalid_argument("Strike has to be positive");
    }
    else{
        _strike=strike;
    }
}

AmericanOption::~AmericanOption(){}

bool AmericanOption::isAmericanOption(){
    return true;
}

double AmericanOption::GetStrike(){
    return _strike;
}




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




AmericanPutOption::AmericanPutOption(double expiry, double strike) : AmericanOption(expiry , strike){

}

AmericanPutOption::~AmericanPutOption(){}

OptionType AmericanPutOption::GetOptionType(){
    return OptionType::Put;
}

double AmericanPutOption::payoff(double spot_prices){
    if(spot_prices > _strike){
        return 0;
    }
    else{
        return _strike - spot_prices;
    }
}
