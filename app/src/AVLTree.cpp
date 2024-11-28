#include "AVLTree.hpp"

AVLTree::AVLTree(AVLTree* parent): parent(parent) {}

AVLTree AVLTree::getAVLTree(int value) {
    if(!this->root.hasValue() || this->root == value) {
        return this;
    }

    return this->root <= value
        ?   this->rChild->getAVLTree(value)
        :   this->lChild->getAVLTree(value);
}

void AVLTree::insert(int value) {
    AVLTree tree = this->getAVLTree(value);
    if(tree.root.hasValue()) throw new Error();

    tree.root = Node(value);
    this->rChild = new AVLTree(this);
    this->lChild = new AVLTree(this);
}