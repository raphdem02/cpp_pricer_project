#include "Option.h"
#include <stdexcept> 

Option::Option(double expiry){
    if(expiry <= 0)
        throw std::invalid_argument("Expiry have to be positive");
    else 
        _expiry = expiry;
}

Option::~Option() {}

double Option::getExpiry() {return _expiry;}

