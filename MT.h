#pragma once
#include <random>

class MT{
    private: 
    MT(); //mise en privée pour gérer l'instanciation
    std::mt19937 _MTGen;
    static std::uniform_real_distribution<double> _unifDist;
    static std::normal_distribution<double> _normDist;

    public:
    MT(const MT&) =delete; //On évite de créer des copies du singleton 
    MT& operator=(const MT&) = delete; //On évite d'assigner des copies du singleton

    static MT& getInstance(); //To access the class statically, returns instance of singleton
    static double rand_unif();
    static double rand_norm();
};