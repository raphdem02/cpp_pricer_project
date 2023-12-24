#include "CRRPricer.h"
#include "BinaryTree.h"
#include <cmath>

// Constructor
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) 
: _asset_price(asset_price), _up(up), _down(down), _option(option), _interest_rate(interest_rate) {
    validInit(option, depth);
}

void CRRPricer::validInit(Option* option, int depth) {
    if (option->isAsianOption()) {
        throw std::invalid_argument("Error: Asian Option is not supported");
    } else {
        checkAbritrage(depth);
    }
}

void CRRPricer::checkAbritrage(int depth) {
    if (!isArbitrage()) {
        throw std::invalid_argument("Error: Arbitrage opportunity detected");
    }
    inititTree(depth);
}

bool CRRPricer::isArbitrage() {
    return _down < _interest_rate && _interest_rate < _up;
}

void CRRPricer::inititTree(int depth) {
    _tree = BinaryTree<double>(depth);
    _exerciseTree = BinaryTree<bool>(depth);
    compute();
}


// Overloaded constructor for TD8
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double r, double volatility) 
: _asset_price(asset_price), _option(option) {
    if (option->isAsianOption()) {
        throw std::invalid_argument("Error: Asian Option is not supported");
    } else {
        calculateBlackScholesParams(depth, r, volatility);
        if (!isArbitrage()) {
            throw std::invalid_argument("Error: Arbitrage opportunity detected");
        }
        inititTree(depth);
    }
}

void CRRPricer::calculateBlackScholesParams(int depth, double r, double volatility) {
    double h = _option->getExpiry() / depth;
    _up = std::exp((r + (std::pow(volatility, 2) / 2)) * h + volatility * std::sqrt(h)) - 1;
    _down = std::exp((r + (std::pow(volatility, 2) / 2)) * h - volatility * std::sqrt(h)) - 1;
    _interest_rate = std::exp(r * h) - 1;
}



// Destructor
CRRPricer::~CRRPricer() { }

// Init the tree with prices
void CRRPricer::compute()
{
	double value = 0;
	for (int n = 0; n < _tree.getDepth() + 1; n++)
	{
		for (int i = 0; i < _tree.getLengthBranch(n); i++)
		{
			value =  _asset_price * std::pow((1 + _up), i) * std::pow((1 + _down), n - i);
			_tree.setNode(n, i, value);
		}
	}
}

// Returns the payoff at a specified state
double CRRPricer::get(int n, int i) {	
	return _option->payoff(_tree.getNode(n, i)); 
	}

//Indicate the exercise condition for american options
bool CRRPricer::getExercise(int n, int i) {
	 return _exerciseTree.getNode(n, i); 
}

// Display
void CRRPricer::display() {	_tree.display(); }

// Compute the factorial
double CRRPricer::facto(int n)
{
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n * facto(n - 1);
}

// Compute the price of the option with the CRR method
double CRRPricer::operator()(bool closed_form) {
    double q = (_interest_rate - _down) / (_up - _down);
    
    if (closed_form) {
        double value = 0;
        for (int i = 0; i <= _tree.getDepth(); i++) {
            value += combination(_tree.getDepth(), i) * std::pow(q, i) * std::pow(1 - q, _tree.getDepth() - i) * this->get(_tree.getDepth(), i);
        }
        return value / std::pow(1 + _interest_rate, _tree.getDepth());
    } else {
        BinaryTree<double> optionValues(_tree.getDepth());
        BinaryTree<bool> exerciseIndicators(_tree.getDepth());
        computeTerminalValues(optionValues, exerciseIndicators, q);
        return optionValues.getNode(0, 0);
    }
}


double CRRPricer::combination(int n, int k) {
    if (k < 0 || k > n) {
        return 0.0;  // Invalid combination
    }

    double result = 1.0;
    for (int i = 0; i < k; ++i) {
        result *= static_cast<double>(n - i) / (i + 1);
    }
    return result;
}

void CRRPricer::computeTerminalValues(BinaryTree<double>& optionValues, BinaryTree<bool>& exerciseIndicators, double q) {
    int depth = _tree.getDepth();
    for (int i = 0; i <= depth; i++) {
        optionValues.setNode(depth, i, this->get(depth, i));
        exerciseIndicators.setNode(depth, i, false);
    }

    for (int n = depth - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++) {
            double price = calculatePriceAtNode(n, i, optionValues, q);
            updateNodeValues(n, i, price, optionValues, exerciseIndicators);
        }
    }
}

double CRRPricer::calculatePriceAtNode(int n, int i, BinaryTree<double>& optionValues, double q) {
    return (q * optionValues.getNode(n + 1, i + 1) + (1 - q) * optionValues.getNode(n + 1, i)) / (1 + _interest_rate);
}

void CRRPricer::updateNodeValues(int n, int i, double price, BinaryTree<double>& optionValues, BinaryTree<bool>& exerciseIndicators) {
    double intrinsic = this->get(n, i);
    if (_option->isAmericanOption() && intrinsic >= price) {
        optionValues.setNode(n, i, intrinsic);
        exerciseIndicators.setNode(n, i, true);
    } else {
        optionValues.setNode(n, i, price);
        exerciseIndicators.setNode(n, i, false);
    }
}