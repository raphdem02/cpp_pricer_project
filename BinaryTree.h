#pragma once
#include <vector>

template <typename T>
class BinaryTree {
private:
    int _depth;
    std::vector<std::vector<T>> _tree;

public:
    // Constructors
    BinaryTree(int depth);
    BinaryTree() : _depth(0) {}

    // Destructor
    ~BinaryTree();

    int getDepth();
    void setDepth(int depth);
    long getLengthBranch(int idx);
    void setNode(int idx1, int idx2, T newNodeValue);
    T getNode(int idx1, int idx2);
    void display();
};

// Model function for each types
extern template class BinaryTree<bool>;
extern template class BinaryTree<double>;
extern template class BinaryTree<int>;