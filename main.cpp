#include <iostream>
#include <random>
#include <string>
#include "Option.h"
#include "VanillaOption.h"
#include "BlackScholesPricer.h"


int main()
{
    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    {
        CallOption opt1(T, K);
        PutOption opt2(T, K);

        BlackScholesPricer BSpricer(&opt1, S0, r, sigma);
        std::cout << "call price = " << BSpricer() << ", delta = " << BSpricer.delta() << std::endl;
        

    }

    return 0;
}