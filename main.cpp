#include <iostream>
#include <random>
#include <string>
#include "Option.h"
#include "VanillaOption.h"
#include "BlackScholesPricer.h"
#include "BinaryTree.h"
#include "CRRPricer.h"
#include "DigitalOption.h"

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
        /*
        int N(150);
        double U = exp(sigma * sqrt(T / N)) - 1.0;
        double D = exp(-sigma * sqrt(T / N)) - 1.0;
        double R = exp(r * T / N) - 1.0;

        CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
        std::cout << "Calling CRR pricer with depth = " << N << std::endl;
        std::cout << std::endl;
        std::cout << "CRR pricer computed call price = " << crr_pricer1() << std::endl;
        std::cout << "CRR pricer explicit formula call price = " << crr_pricer1(true) << std::endl;
        std::cout << std::endl;


        CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
        std::cout << "Calling CRR pricer with depth = " << N << std::endl;
        std::cout << std::endl;
        std::cout << "CRR pricer computed put price = " << crr_pricer2() << std::endl;
        std::cout << "CRR pricer explicit formula put price = " << crr_pricer2(true) << std::endl;
        */
    }
    #pragma endregion

    {
        DigitalCallOption opt1(T, K);
        DigitalPutOption opt2(T, K);

        BlackScholesPricer pricer1(&opt1, S0, r, sigma);
        std::cout << "BlackScholesPricer digital call price = " << pricer1() << ", delta = " << pricer1.delta() << std::endl;
            
        BlackScholesPricer pricer2(&opt2, S0, r, sigma);
        std::cout << "BlackScholesPricer digital put price = " << pricer2() << ", delta = " << pricer2.delta() << std::endl;
        std::cout << std::endl;
    }

    { //TODO TEST A changer
     std::cout << std::endl << "================= Binary Tree =================" << std::endl << std::endl;
    
     BinaryTree<bool> t1(3);
     t1.setDepth(3);
     t1.setNode(1, 1, true);
     t1.display();
     t1.setDepth(5);
     t1.display();
     t1.setDepth(3);
     t1.display();
     
     BinaryTree<double> t2;
     t2.setDepth(2);
     t2.setNode(2, 1, 3.14);
     t2.display();
     t2.setDepth(4);
     t2.display();
     t2.setDepth(3);
     t2.display();
     
     BinaryTree<int> t3;
     t3.setDepth(4);
     t3.setNode(3, 0, 188);
     t3.display();
     t3.setDepth(2);
     t3.display();
     t3.setDepth(4);
     t3.display();
     }
}