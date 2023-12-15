#include "PutOption.h"
#include <stdexcept> 

PutOption::PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

PutOption::~PutOption() {}

OptionType PutOption::GetOptionType() {
    return OptionType::Put;
}

double PutOption::payoff(double stockPrice) {
    return std::max(GetStrike() - stockPrice, 0.0); 
}