#include "AsianOption.h"



//Constructor
AsianOption::AsianOption(std::vector<double> timeSteps , double strike) : Option(timeSteps.back()){
    
    if(strike <= 0){
        throw std::invalid_argument("Strike must be positive");
    }
    else{

        _timeSteps = timeSteps;
        _strike = strike;
    }  
}

// Destructor
AsianOption::~AsianOption(){}

// Return all the time steps, overriden 
std::vector<double> AsianOption::getTimeSteps(){
    return _timeSteps;
}

// Return the payoff of one path
double AsianOption::payoffPath(std::vector<double> spot_prices){
    long length = spot_prices.size();
    double sum = 0;
    for(int i = 0; i < length; i++){
        sum += spot_prices.at(i);
    }

    double mean = sum / length;
    return payoff(mean);

}

double AsianOption::GetStrike(){
    return _strike;
}

bool AsianOption::isAsianOption(){
    return true;
}



