#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H

#include "Node.hpp"
#include <optional>
#include <memory>

class AVLTree {
private:
    int height = 0;
    Node root(nullptr);

    AVLTree* parent;
    AVLTree* rChild = nullptr;
    AVLTree* lChild = nullptr;

    void promptInOrder();
    void promptPreOrder();
    void promptPosOrder();

    void balance(AVLTree*);
    void rotateTree();
    void rotateLeft();
    void rotateRight();
public:
    AVLTree(AVLTree* parent);
    ~AVLTree();

    AVLTree getAVLTree(int value);
    void insert(int value);
    bool hasValue(int value);

    void prompt(const std::string& mode);
}

#endif