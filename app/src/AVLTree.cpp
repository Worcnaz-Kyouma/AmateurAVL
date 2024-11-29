#include "AVLTree.hpp"

#include <iostream>
#include <cstdlib>
#include <stdexcept>

AVLTree::AVLTree(AVLTree* parent): parent(parent) {}

AVLTree* AVLTree::createNewAVLTree(int value){
    AVLTree* tree = new AVLTree(nullptr);
    
    tree->root = std::make_unique<int>(value);
    tree->rChild = new AVLTree(tree);
    tree->lChild = new AVLTree(tree);

    return tree;
}

AVLTree* AVLTree::getRoot() {
    if(this->parent == nullptr) return this;
    return this->parent->getRoot();
}

AVLTree* AVLTree::getAVLTree(int value) {
    if(!this->root || *this->root == value) {
        return this;
    }

    return *this->root <= value
        ?   this->rChild->getAVLTree(value)
        :   this->lChild->getAVLTree(value);
}

bool AVLTree::hasValue(int value) {
    AVLTree* tree = this->getAVLTree(value);
    return static_cast<bool>(tree->root);
}

AVLTree* AVLTree::insert(int value) {
    AVLTree* tree = this->getAVLTree(value);
    if(tree->root) throw std::runtime_error("Value already inside tree");

    tree->root = std::make_unique<int>(value);
    tree->rChild = new AVLTree(tree);
    tree->lChild = new AVLTree(tree);

    tree->parent->balance(tree);

    return this->getRoot();
}

void AVLTree::balance(AVLTree* child) {
    this->height += 1 * (this->rChild == child) ? -1 : 1;
    if(abs(this->height) == 2) this->rotateTree();
    else if(this->parent != nullptr) this->parent->balance(this);
}

void AVLTree::rotateTree() {
    if(this->height == 2) {
        if(this->lChild->height == 1) this->rotateRight();
        else {
            this->lChild->rotateLeft();
            this->rotateRight();
        }
    } else {
        if(this->rChild->height == -1) this->rotateLeft();
        else {
            this->rChild->rotateRight();
            this->rotateLeft();
        }
    }
}

void AVLTree::rotateLeft() {
    AVLTree* grandParent = this->parent;
    AVLTree* newParent = this->rChild;
    AVLTree* newParentOldLChild = newParent->lChild;

    // GrandParent connections
    newParent->parent = grandParent;
    if(grandParent != nullptr) {
        if(grandParent->lChild == this) grandParent->lChild = newParent;
        else grandParent->rChild = newParent;
    }

    // NewParent conection to Old Parent(this)
    this->parent = newParent;
    newParent->lChild = this;

    // Old Parent receives old left child of new parent on right
    this->rChild = newParentOldLChild;
    newParentOldLChild->parent = this;

    this->parent->height = 0;
    this->height = 0;
}

void AVLTree::rotateRight() {
    AVLTree* grandParent = this->parent;
    AVLTree* newParent = this->lChild;
    AVLTree* newParentOldRChild = newParent->rChild;

    // GrandParent connections
    newParent->parent = grandParent;
    if(grandParent != nullptr) {
        if(grandParent->lChild == this) grandParent->lChild = newParent;
        else grandParent->rChild = newParent;
    }

    // NewParent conection to Old Parent(this)
    this->parent = newParent;
    newParent->rChild = this;

    // Old Parent receives old right child of new parent on left
    this->lChild = newParentOldRChild;
    newParentOldRChild->parent = this;

    this->parent->height = 0;
    this->height = 0;
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