#pragma once
#include "Option.h"
//#include "VanillaOption.h"

class BlackScholesPricer{
    private:
        Option* _option;
        double _asset_price;
        double _interest_rate;
        double _volatility;
    
    public:
        BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility);
        ~BlackScholesPricer();

        double normalDistrib(double);
        double normalCont(double);
        double operator()();
        double delta();
    

};