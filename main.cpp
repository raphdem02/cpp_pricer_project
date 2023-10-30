#include <iostream>
#include <random>
#include <string>
#include "Option.h"
#include "VanillaOption.h"
#include "BlackScholesPricer.h"
#include "BinaryTree.h"

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