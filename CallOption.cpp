#include "CallOption.h"
#include <stdexcept> 

CallOption::CallOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

CallOption::~CallOption() {}

OptionType CallOption::GetOptionType() {
    return OptionType::Call;
}

double CallOption::payoff(double stockPrice) {
    return std::max(stockPrice - GetStrike(), 0.0);
}