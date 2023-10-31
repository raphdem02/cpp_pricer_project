#include "MT.h"

// Private constructor
MT::MT() : _MTGen(std::random_device{}()) {}

MT& MT::getInstance() 
{
    static MT instance; //  destroyed and instantiated on first use
    return instance;
}

std::uniform_real_distribution<double> MT::_unifDist(0.0, 1.0);

double MT::rand_unif() 
{
    return _unifDist(getInstance()._MTGen);
}

std::normal_distribution<double> MT::_normDist(0.0, 1.0);

double MT::rand_norm() 
{
    return _normDist(getInstance()._MTGen);
}

