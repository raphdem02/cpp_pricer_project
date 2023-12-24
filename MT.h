#include <random>

class MT{
    private: 
    MT(); 
    std::mt19937 _MTGen;
    static std::uniform_real_distribution<double> _unifDist;
    static std::normal_distribution<double> _normDist;

    public:
    MT(const MT&) =delete; 
    MT& operator=(const MT&) = delete;

    static MT& getInstance(); //To access the class statically, returns instance of singleton
    static double rand_unif();
    static double rand_norm();
};