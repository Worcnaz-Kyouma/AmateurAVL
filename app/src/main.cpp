#include "AVLTree.hpp"
#include <iostream>

int main() {
    AVLTree* tree = AVLTree::createNewAVLTree(4);

    tree->insert(1);
    tree->insert(5);

    tree->prompt("IN_ORDER");
    tree->prompt("PRE_ORDER");
    tree->prompt("POS_ORDER");

    std::cout << std::boolalpha << tree->hasValue(3) << std::endl;
}