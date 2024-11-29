#include <iostream>
#include "AVLTree.hpp"

int main() {
    // Creating a new AVL tree with root value 10
    AVLTree* tree = AVLTree::createNewAVLTree(10);
    
    // Insert values to trigger balancing
    std::cout << "With values 10, 20, 30, 40, 50, 25..." << std::endl;
    tree = tree->insert(20);
    tree = tree->insert(30);
    tree = tree->insert(40);
    tree = tree->insert(50);
    tree = tree->insert(25);

    // Prompting tree traversals to check if the structure is correct
    tree->prompt("IN_ORDER");
    //tree->prompt("PRE_ORDER");
    //tree->prompt("POS_ORDER");

    return 0;
}