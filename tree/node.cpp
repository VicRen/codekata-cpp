#include "node.h"

#include <iostream>
#include <utility>

Node::Node(std::string name) : name_(std::move(name)) {
}

void Node::Print() const {
    std::cout << "Node: " << name_ << std::endl;
}
