#include "Option.h"
#include <stdexcept> 

Option::Option(double expiry){
    if(expiry <= 0)
        throw std::invalid_argument("Expiry have to be positive");
    else 
        _expiry = expiry;
}

Option::~Option() {}

// Return the maturity of the option
double Option::getExpiry() {return _expiry;}

// Return the payoff of the last spot prices
double Option::payoffPath(std::vector<double> spot_prices) {
    return payoff(spot_prices.at(spot_prices.size() - 1));
}

std::vector<double> Option::getTimeSteps() {
	std::vector<double> timesteps{ 0, _expiry };
	return timesteps;
}

bool Option::isDigital(){
    return false;
}

bool Option::isAsianOption(){
    return false; 
}
bool Option::isAmericanOption(){
    return false; 
}