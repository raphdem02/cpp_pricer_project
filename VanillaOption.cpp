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






