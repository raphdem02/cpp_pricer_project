// BlackScholesPricer.cpp
#include "BlackScholesPricer.h"
#include <cmath>
#define _PI 3.14159265358979

BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility) : option_(option), asset_price_(asset_price), interest_rate_(interest_rate), volatility_(volatility) {}

BlackScholesPricer::~BlackScholesPricer() { }

double BlackScholesPricer::normalDistrib(double x) {
    return 1.0 / std::sqrt(2.0 * _PI) * std::exp(-0.5 * x * x);
}

// Normal cumulative distribution function
double BlackScholesPricer::normalCont(double x) {
    return 0.5 * erfc(-x / std::sqrt(2.0));
}

double BlackScholesPricer::operator()() {
    double strike = option_->GetStrike();
    double expiry = option_->getExpiry();

    double d1 = (log(asset_price_ / strike) + (interest_rate_ + 0.5 * volatility_ * volatility_) * expiry) / (volatility_ * sqrt(expiry));
    double d2 = d1 - volatility_ * sqrt(expiry);


    if (option_->GetOptionType() == VanillaOption::OptionType::Call) {
        return asset_price_ * normalCont(d1) - strike * exp(-interest_rate_ * expiry) * ;normalCont(d2);
    } else { // Put
        return strike * exp(-interest_rate_ * expiry) * normalCont(-d2) - asset_price_ * normalCont(-d1);
    }
}

double BlackScholesPricer::delta() {
    double strike = option_->GetStrike();
    double expiry = option_->getExpiry();

    double d1 = (log(asset_price_ / strike) + (interest_rate_ + 0.5 * volatility_ * volatility_) * expiry) / (volatility_ * sqrt(expiry));

    double cdf_d1 = 0.5 * std::erfc(-d1 / sqrt(2));

    if (option_->GetOptionType() == VanillaOption::OptionType::Call) {
        return normalCont(d1);
    } else { // Put
        return -normalCont(-d1);
    }
}
