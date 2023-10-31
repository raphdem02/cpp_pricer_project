#include "AsianOption.h"

#pragma region AsianOp

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

// Return all the time steps of the option to compute the payoff paths overriden version
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

#pragma endregion

// Call
#pragma region AsianCallOp

AsianCallOption::AsianCallOption(std::vector<double> timeSteps , double strike) : AsianOption(timeSteps , strike){

} 

AsianCallOption::~AsianCallOption(){}

OptionType AsianCallOption::GetOptionType(){
    return OptionType::Call;
}

double AsianCallOption::payoff(double spot_prices){
    return std::max(spot_prices - _strike , 0.0);
}

#pragma endregion

//Put
#pragma region AsianPutOp

AsianPutOption::AsianPutOption(std::vector<double> timeSteps , double strike) : AsianOption(timeSteps , strike){

}


AsianPutOption::~AsianPutOption(){}

OptionType AsianPutOption::GetOptionType(){
    return OptionType::Put;
}


double AsianPutOption::payoff(double spot_prices){
    return std::max(_strike - spot_prices, 0.0);
}

#pragma endregion