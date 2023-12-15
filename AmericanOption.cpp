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








