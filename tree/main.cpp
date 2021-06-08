#include "node.h"
#include <stack>
#include <iostream>
#include <vector>

Node *root;

void createTree() {
    auto a = new Node("1");
    auto b = new Node("2");
    auto c = new Node("3");
    auto d = new Node("4");
    auto e = new Node("5");
    auto f = new Node("6");
    auto g = new Node("7");
    auto h = new Node("8");
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    e->left = g;
    e->right = h;
    root = a;
}

void preOrder() {
    std::cout << "==========preOrder=========" << std::endl;
    createTree();
    std::stack<Node *> stack;
    auto tmp = root;
    while (tmp != nullptr || !stack.empty()) {
        if (tmp != nullptr) {
            tmp->Print();
            stack.push(tmp);
            tmp = tmp->left;
        } else {
            tmp = stack.top()->right;
            stack.pop();
        }
    }
}

void inOrder() {
    std::cout << "==========inOrder=========" << std::endl;
    createTree();
    std::stack<Node *> stack;
    auto tmp = root;
    while (tmp != nullptr || !stack.empty()) {
        if (tmp != nullptr) {
            stack.push(tmp);
            tmp = tmp->left;
        } else {
            tmp = stack.top();
            tmp->Print();
            stack.pop();
            tmp = tmp->right;
        }
    }
}

void postOrder() {
    std::cout << "==========postOrder=========" << std::endl;
    createTree();
    std::vector<Node *> ans;
    std::stack<Node *> stack;
    while (root != nullptr || !stack.empty()) {
        if (root != nullptr) {
            stack.push(root);
            root = root->left;
        } else {
            auto tmp = stack.top();
            if (tmp->right == nullptr) {
                stack.pop();
                tmp->Print();
                continue;
            }
            root = tmp->right;
            tmp->right = nullptr;
        }
    }
}

int main() {
    preOrder();
    inOrder();
    postOrder();
    return 0;
}
