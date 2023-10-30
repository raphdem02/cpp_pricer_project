#include "VanillaOption.h"
#include <stdexcept> 

VanillaOption::VanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) {
    if (strike <= 0) 
        throw std::invalid_argument("strike have to be positive");
    else 
        _strike = strike;
}

VanillaOption::~VanillaOption() {}

//Override version
double VanillaOption::GetStrike() { 
    return _strike; 
}


CallOption::CallOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

CallOption::~CallOption() {}

OptionType CallOption::GetOptionType() {
    return OptionType::Call;
}

double CallOption::payoff(double stockPrice) {
    return std::max(stockPrice - GetStrike(), 0.0);
}


PutOption::PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

PutOption::~PutOption() {}

OptionType PutOption::GetOptionType() {
    return OptionType::Put;
}

double PutOption::payoff(double stockPrice) {
    return std::max(GetStrike() - stockPrice, 0.0); 
}
