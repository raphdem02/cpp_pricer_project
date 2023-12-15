#include "BinaryTree.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1);  //Init the full size 
    for (int i = 0; i < _tree.size(); i++)
        _tree[i].resize(i + 1); // Init the size of each branch
}

//Destructor
template <typename T>
BinaryTree<T>::~BinaryTree(){}

//Get the depth of the tree
template<typename T>
int BinaryTree<T>::getDepth(){
    return _depth;
}

// Set depth
template<typename T>
void BinaryTree<T>::setDepth(int depth){
    if(_depth > depth){ //Shrink the tree in this case
        _depth = depth;
        _tree.resize(_depth + 1);
    }
    else{ //Create new branches in this case
        _tree.resize(depth + 1);
        for(int i = _depth; i < _tree.size(); i++){
            _tree[i].resize(i+1);
        }
        _depth = depth;
    }
}

//Length of a specific branch
template<typename T>
long BinaryTree<T>::getLengthBranch(int idx){
    return _tree[idx].size();
}

// Set the value of a node
template<typename T>
void BinaryTree<T>::setNode(int idx1, int idx2, T  newNodeValue){
    _tree[idx1][idx2] = newNodeValue;
}

// Get the value of a node
template<typename T>
T BinaryTree<T>::getNode(int idx1, int idx2){
    return _tree[idx1][idx2];
}


template<typename T>
void BinaryTree<T>::display() {
    for (int i = 0; i < _tree.size(); i++) {
        int space = _depth * 3 + 3 - 3 * i;

        
        for (int k = 0; k < space; k++) {
            std::cout << " ";
        }

        
        for (int j = 0; j < _tree[i].size(); j++) {
            long value = (_tree[i][j] == int(_tree[i][j])) ? std::to_string(int(_tree[i][j])).length() : std::to_string(int(_tree[i][j]) * 100).length() + 1;

            switch (value) {
                case 1: std::cout << "  " << _tree[i][j] << "   "; break;
                case 2: std::cout << "  " << _tree[i][j] << "  "; break;
                case 3: std::cout << " " << _tree[i][j] << "  "; break;
                case 4: std::cout << _tree[i][j] << "  "; break;
                default: std::cout << "Erreur" << " ";
            }
        }

        std::cout << std::endl;

        
        if (i != _tree.size() - 1) {
            for (int k = 0; k < space; k++) {
                std::cout << " ";
            }

            
            for (int j = 0; j < _tree[i].size(); j++) {
                std::cout << "/   \\ ";
            }

            std::cout << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
}




// Model function for each types
template class BinaryTree<bool>;
template class BinaryTree<double>;
template class BinaryTree<int>;