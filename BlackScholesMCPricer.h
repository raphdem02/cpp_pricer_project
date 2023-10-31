#pragma once 
#include <vector>
#include "Option.h"

class BlackScholesMCPricer
{
    private:
    Option* _option;
	double _initial_price;
	double _interest_rate;
	double _volatility;
	double _current_estimate;
	int _nb_paths;  

    public:
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);
		~BlackScholesMCPricer();

		int getNbPaths();
		void generate(int);
		double operator()();
		std::vector<double> confidenceInterval();

};