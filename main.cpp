#include <iostream>
#include <random>
#include <string>
#include "Option.h"
#include "VanillaOption.h"
#include "BlackScholesPricer.h"


int main()
{
    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    #pragma region Part1    
    {
        
        CallOption opt1(T, K);
        PutOption opt2(T, K);
        BlackScholesPricer BSpricerCall(&opt1, S0, r, sigma);
        BlackScholesPricer BSpricerPut(&opt2, S0, r, sigma);
        std::cout << "######################### Black Scholes Model ################################" << std::endl;
        std::cout << "call price = " << BSpricerCall() << ", delta = " << BSpricerCall.delta() << std::endl;
        std::cout << "put price = " << BSpricerPut() << ", delta = " << BSpricerPut.delta() << std::endl;
        

    }
    #pragma endregion
}