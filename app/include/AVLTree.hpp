#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H

#include <optional>
#include <memory>
#include <string>

class AVLTree {
private:
    int height = 0;
    std::unique_ptr<int> root = nullptr;

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

    static AVLTree* createNewAVLTree(int value);

    AVLTree* getRoot();
    AVLTree* getAVLTree(int value);
    AVLTree* insert(int value); // can retun new root
    bool hasValue(int value);

    void prompt(const std::string& mode);
};

#endif