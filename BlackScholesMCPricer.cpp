#include "BlackScholesMCPricer.h"
#include "MT.h"
#include <cmath>
#include <stdexcept>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
	: _option(option), _initial_price(initial_price), _interest_rate(interest_rate), _volatility(volatility), _current_estimate(0.0), _nb_paths(0) { }


BlackScholesMCPricer::~BlackScholesMCPricer() { }

double BlackScholesMCPricer::operator()()
{
	if (_nb_paths == 0)
		throw std::runtime_error("Error: No current estimate has yet been defined.");
	return _current_estimate;
}

int BlackScholesMCPricer::getNbPaths()
{
	return _nb_paths;
}


/*void BlackScholesMCPricer::generate(int nb_paths)
{	
	if (_option->isAsianOption()) // Number of steps for asian options
		m = _option->getTimeSteps().size();
	else // Number of steps for european options
		m = 1;

	double expiry = _option->getExpiry();
	double dt = expiry / m;  // European Option, si on doit faire les autres on fera d'autre variable

	for (int i = 0; i < nb_paths; i++)
	{
		double normal = MT::rand_norm();
		double s = _initial_price * exp((_interest_rate - 0.5 * _volatility * _volatility) * dt + _volatility * sqrt(dt) * normal);

		// incremental formula
		_current_estimate = (_nb_paths * _current_estimate + _option->payoff(s)) / (_nb_paths + 1);
		_nb_paths++;
	}
}*/

void BlackScholesMCPricer::generate(int nb_paths)
{   
    double m = (_option->isAsianOption()) ? _option->getTimeSteps().size() : 1;
    double expiry = _option->getExpiry();
    double dt = expiry / m;

    for (int i = 0; i < nb_paths; i++)
    {
        std::vector<double> spot_prices(m + 1, _initial_price);
        double normal = MT::rand_norm();

        for (int j = 1; j <= m; j++) 
        {
            double step_price = spot_prices[j - 1] * exp((_interest_rate - 0.5 * _volatility * _volatility) * dt + _volatility * sqrt(dt) * normal);
            spot_prices[j] = step_price;
        }

        _current_estimate = (_nb_paths * _current_estimate + _option->payoffPath(spot_prices)) / (_nb_paths + 1);
        _nb_paths++;
    }
}





std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	double standard_error = _volatility / sqrt(_nb_paths);
	return {_current_estimate - 2 * standard_error, _current_estimate + 2 * standard_error}; //on arrondi à deux, on verra si utile de prendre 1.96
}