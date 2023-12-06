// BlackScholesPricer.cpp
#include "BlackScholesPricer.h"
#include <cmath>
#define _PI 3.14159265358979

BlackScholesPricer::BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility) : _option(option), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility) {}

BlackScholesPricer::~BlackScholesPricer() { }

double BlackScholesPricer::normalDistrib(double x) {
    return 1.0 / std::sqrt(2.0 * _PI) * std::exp(-0.5 * x * x);
}

// Normal cumulative distribution function
double BlackScholesPricer::normalCont(double x) {
    return 0.5 * erfc(-x / std::sqrt(2.0));
}

double BlackScholesPricer::operator()() {
    double d1, d2;
    calculateD1D2(d1, d2);
    return calculateOptionPrice(d1, d2);
}

void BlackScholesPricer::calculateD1D2(double& d1, double& d2) {
    double strike = _option->GetStrike();
    double expiry = _option->getExpiry();
    d1 = (log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * sqrt(expiry));
    d2 = d1 - _volatility * sqrt(expiry);
}

double BlackScholesPricer::calculateOptionPrice(double d1, double d2) {
    if (_option->GetOptionType() == OptionType::Call) {
        return _option->isDigital() ?
            normalCont(d2) * exp(-_interest_rate * _option->getExpiry()) :
            _asset_price * normalCont(d1) - _option->GetStrike() * exp(-_interest_rate * _option->getExpiry()) * normalCont(d2);
    } else { // Put
        return _option->isDigital() ?
            normalCont(-d2) * exp(-_interest_rate * _option->getExpiry()) :
            _option->GetStrike() * exp(-_interest_rate * _option->getExpiry()) * normalCont(-d2) - _asset_price * normalCont(-d1);
    }
}


double BlackScholesPricer::delta() {
    double strike = _option->GetStrike();
    double expiry = _option->getExpiry();

    double d1 = (log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * sqrt(expiry));
    double d2 = d1 - _volatility * sqrt(expiry);
    double cdf_d1 = 0.5 * std::erfc(-d1 / sqrt(2));

    if (_option->GetOptionType() == OptionType::Call) {
        if (_option->isDigital()) {
            return normalDistrib(d2) * std::exp(-_interest_rate * _option->getExpiry()) / (_asset_price * _volatility * std::sqrt(_option->getExpiry()));
        } else {
            return normalCont(d1);
        }
    } else { // Put
        if (_option->isDigital()) {
            return -normalDistrib(-d2) * std::exp(-_interest_rate * _option->getExpiry()) / (_asset_price * _volatility * std::sqrt(_option->getExpiry()));
        } else {
            return -normalCont(-d1);
        }
    }
}