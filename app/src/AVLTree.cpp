#include "AVLTree.hpp"

#include <iostream>
#include <stdexcept>

AVLTree::AVLTree(AVLTree* parent): parent(parent) {}

AVLTree* AVLTree::createNewAVLTree(int value){
    AVLTree* tree = new AVLTree(nullptr);
    
    tree->root = std::make_unique<int>(value);
    tree->rChild = new AVLTree(tree);
    tree->lChild = new AVLTree(tree);

    return tree;
}

AVLTree* AVLTree::getAVLTree(int value) {
    if(!this->root || *this->root == value) {
        return this;
    }

    return *this->root <= value
        ?   this->rChild->getAVLTree(value)
        :   this->lChild->getAVLTree(value);
}

void AVLTree::insert(int value) {
    AVLTree* tree = this->getAVLTree(value);
    if(tree->root) throw std::runtime_error("Value already inside tree");

    tree->root = std::make_unique<int>(value);
    tree->rChild = new AVLTree(tree);
    tree->lChild = new AVLTree(tree);
}

bool AVLTree::hasValue(int value) {
    AVLTree* tree = this->getAVLTree(value);
    return static_cast<bool>(tree->root);
}

void AVLTree::prompt(const std::string& mode) {
    if (mode == "IN_ORDER") {
        std::cout << "In Order Prompt:" << std::endl;
        this->promptInOrder();
    } else if(mode == "PRE_ORDER") {
        std::cout << "Pre Order Prompt:" << std::endl;
        this->promptPreOrder();
    } else if(mode == "POS_ORDER") {
        std::cout << "Pos Order Prompt:" << std::endl;
        this->promptPosOrder();
    } else {
        throw std::runtime_error("Invalid mode");
    }

    std::cout << std::endl;
}

void AVLTree::promptInOrder() {
    if(!this->root) return;
    
    this->lChild->promptInOrder();
    std::cout << *this->root << ", ";
    this->rChild->promptInOrder();
}

void AVLTree::promptPreOrder() {
    if(!this->root) return;
    
    std::cout << *this->root << ", ";
    this->lChild->promptPreOrder();
    this->rChild->promptPreOrder();
}

void AVLTree::promptPosOrder() {
    if(!this->root) return;
    
    this->lChild->promptPosOrder();
    this->rChild->promptPosOrder();
    std::cout << *this->root << ", ";
}

void AVLTree::balance(AVLTree*) {}
void AVLTree::rotateTree() {}
void AVLTree::rotateLeft() {}
void AVLTree::rotateRight() {}