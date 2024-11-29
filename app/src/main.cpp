#include <iostream>
#include "AVLTree.hpp"

int main() {
    AVLTree* tree = AVLTree::createNewAVLTree(10);
    
    std::cout << "10, 20, 30, 40, 50, 25" << std::endl;
    tree = tree->insert(20);
    tree = tree->insert(30);
    tree = tree->insert(40);
    tree = tree->insert(50);
    tree = tree->insert(25);

    tree->prompt("IN_ORDER");
    tree->prompt("PRE_ORDER");
    tree->prompt("POS_ORDER");

    return 0;
}