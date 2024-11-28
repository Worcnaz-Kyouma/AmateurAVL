#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <optional>
#include <memory>

class Node {
private:
    std::unique_ptr<int> value;
public:
    Node(std::unique_ptr<int> value): value(value){};
    Node(int value);
    bool hasValue();
    int getValue();
    void setValue(int value);

    bool operator<(const int& other) const {
        return this->getValue() < other;
    }
    bool operator<=(const int& other) const {
        return this->getValue() <= other;
    }
    bool operator>(const int& other) const {
        return this->getValue() > other;
    }
    bool operator==(const int& other) const {
        return this->getValue() == other;
    }
};

#endif