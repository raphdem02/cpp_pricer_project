
#include "Option.h"
#include "BinaryTree.h"

class CRRPricer
{
	public:
		CRRPricer(Option*, int, double, double, double, double);
		CRRPricer(Option*, int, double, double, double);
		~CRRPricer();

		void compute();
		double get(int, int);
		double operator()(bool closed_form = false);
		void display();
		double facto(int);
		bool getExercise(int, int);

	private:
		BinaryTree<double> _tree;
		BinaryTree<bool> _exerciseTree;
		Option* _option;
		double _up;
		double _down;
		double _asset_price;
		double _interest_rate;
        void validInit(Option* option, int depth);
        void checkAbritrage(int depth);
        bool isArbitrage();
        void inititTree(int depth);
        void calculateBlackScholesParams(int depth, double r, double volatility);
        
    double combination(int n, int k);
    void computeTerminalValues(BinaryTree<double>& optionValues, BinaryTree<bool>& exerciseIndicators, double q);
    double calculatePriceAtNode(int n, int i, BinaryTree<double>& optionValues, double q);
    void updateNodeValues(int n, int i, double price, BinaryTree<double>& optionValues, BinaryTree<bool>& exerciseIndicators);
};