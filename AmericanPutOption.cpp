#include "AmericanPutOption.h"
#include <vector>

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
