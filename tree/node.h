#ifndef CODEKATA_CPP_NODE_H
#define CODEKATA_CPP_NODE_H

#include <string>

class Node {
public:
    explicit Node(std::string name);

    void Print() const;

    std::string name_;
    Node *left{};
    Node *right{};
};


#endif //CODEKATA_CPP_NODE_H
