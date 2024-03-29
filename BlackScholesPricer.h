
#include "Option.h"


class BlackScholesPricer{
    private:
        Option* _option;
        double _asset_price;
        double _interest_rate;
        double _volatility;
        void calculateD1D2(double& d1, double& d2);
        double calculateOptionPrice(double d1, double d2);
    
    public:
        BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility);
        ~BlackScholesPricer();

        double normalDistrib(double);
        double normalCont(double);
        double operator()();
        double delta();
    

};