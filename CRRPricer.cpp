#include "CRRPricer.h"
#include <cmath>
#include <stdexcept>

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate), _tree(depth) {
    if (!(_down < _interest_rate && _interest_rate < _up)) {
        throw std::invalid_argument("Error: There is an arbitrage opportunity.");
    }

    compute();
    
}

CRRPricer::~CRRPricer() { }

void CRRPricer::checkArbitrage(){
    if(!(_down < _interest_rate && _interest_rate < _up)){
        throw std::invalid_arguement("Error : Carefull, There is an arbitrage")
    }
}

//Initialize the tree with prices
void CRRPricer::compute() {
    double value = 0;
    for (int n = 0; n <= _depth; ++n) {
        for (int i = 0; i <= n; ++i) {
            value = _asset_price * std::pow(1 + _up, i) * std::pow(1 + _down, n - i);
            _tree.setNode(n, i, value);
        }
    }
}

// Specified state of the tree payoff
double CRRPricer::get(int n, int i) {
    return _option->payoff(_tree.getNode(n, i));
}


double CRRPricer::facto(int n) {
    return (n <= 1) ? 1 : n * facto(n - 1);
}

double CRRPricer::operator()(bool closed_form)
{
	double q = (_interest_rate - _down) / (_up - _down);
	if (closed_form) // Compute price using closed formula
	{
		double value = 0;
		for (int i = 0; i <= _depth; i++)
			value += (facto(_depth) / (facto(i) * facto(_depth - i))) 
                     * std::pow(q, i) * std::pow((1 - q), _depth - i) * get(_depth, i);
		
        return value / std::pow(1 + _interest_rate, _depth);
	}
	else { // Compute price by iterating through the tree
		BinaryTree<double> values(_depth); // Tree that will contain the prices of the option

		// Compute prices at the last branch
		for (int i = 0; i <= _depth; i++) {
			values.setNode(_depth, i, get(_depth, i));
		}

		// Iterate through the tree in reverse order
		double price = 0;
		double intrinsic = 0;

		for (int n = _depth - 1; n >= 0; n--)
		{
			for (int i = 0; i <= n; i++)
			{
				price = (q * values.getNode(n + 1, i + 1) + (1 - q) * values.getNode(n + 1, i)) 
                       / (1 + _interest_rate);

	
				values.setNode(n, i, price);
				
			}
		}

		return values.getNode(0, 0); // Return the first price
	}
}
