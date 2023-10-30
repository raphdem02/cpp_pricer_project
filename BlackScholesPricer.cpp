// BlackScholesPricer.cpp
#include "BlackScholesPricer.h"
#include <cmath>
#define _PI 3.14159265358979

BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility) : _option(option), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility) {}

BlackScholesPricer::~BlackScholesPricer() { }

double BlackScholesPricer::normalDistrib(double x) {
    return 1.0 / std::sqrt(2.0 * _PI) * std::exp(-0.5 * x * x);
}

// Normal cumulative distribution function
double BlackScholesPricer::normalCont(double x) {
    return 0.5 * erfc(-x / std::sqrt(2.0));
}

double BlackScholesPricer::operator()() {
    double strike = _option->GetStrike();
    double expiry = _option->getExpiry();

    double d1 = (log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * sqrt(expiry));
    double d2 = d1 - _volatility * sqrt(expiry);


    if (_option->GetOptionType() == OptionType::Call) {
        return _asset_price * normalCont(d1) - strike * exp(-_interest_rate * expiry) * normalCont(d2);
    } else { // Put
        return strike * exp(-_interest_rate * expiry) * normalCont(-d2) - _asset_price * normalCont(-d1);
    }
}

double BlackScholesPricer::delta() {
    double strike = _option->GetStrike();
    double expiry = _option->getExpiry();

    double d1 = (log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * sqrt(expiry));

    double cdf_d1 = 0.5 * std::erfc(-d1 / sqrt(2));

    if (_option->GetOptionType() == OptionType::Call) {
        return normalCont(d1);
    } else { // Put
        return -normalCont(-d1);
    }
}
