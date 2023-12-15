#include "AsianPutOption.h"


//Put

AsianPutOption::AsianPutOption(std::vector<double> timeSteps , double strike) : AsianOption(timeSteps , strike){

}


AsianPutOption::~AsianPutOption(){}

OptionType AsianPutOption::GetOptionType(){
    return OptionType::Put;
}


double AsianPutOption::payoff(double spot_prices){
    return std::max(_strike - spot_prices, 0.0);
}
