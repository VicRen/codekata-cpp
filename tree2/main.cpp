#include <string>
#include <iostream>
#include <utility>
#include <stack>

class Node {
public:
    explicit Node(std::string name) : name_(std::move(name)) {}

    void Print() {
        std::cout << name_ << std::endl;
    }

    Node* Left{};
    Node* Right{};
private:
    std::string name_;
};

Node *createTree() {
    auto a = new Node("1");
    auto b = new Node("2");
    auto c = new Node("3");
    auto d = new Node("4");
    auto e = new Node("5");
    auto f = new Node("6");
    auto g = new Node("7");
    auto h = new Node("8");
    a->Left = b;
    a->Right = c;
    b->Left = d;
    b->Right = e;
    c->Right = f;
    e->Left = g;
    e->Right = h;
    return a;
}

void preOrder(Node *root) {
    std::stack<Node*> stack;
    auto tmp = root;
    while (tmp != nullptr || !stack.empty()) {
        if (tmp != nullptr) {
            tmp->Print();
            stack.push(tmp);
            tmp = tmp->Left;
        } else {
            tmp = stack.top();
            stack.pop();
            tmp = tmp->Right;
        }
    }
}

void inOrder(Node *root) {
    std::stack<Node*> stack;
    auto tmp = root;
    while (tmp != nullptr || !stack.empty()) {
        if (tmp != nullptr) {
            stack.push(tmp);
            tmp = tmp->Left;
        } else {
            tmp = stack.top();
            tmp->Print();
            stack.pop();
            tmp = tmp->Right;
        }
    }
}

void postOrder(Node *root) {
    std::stack<Node*> stack;
    auto tmp = root;
    while (tmp != nullptr || !stack.empty()) {
        if (tmp != nullptr) {
            stack.push(tmp);
            tmp = tmp->Left;
        } else {
            auto top = stack.top();
            if (top->Right == nullptr) {
                top->Print();
                stack.pop();
                continue;;
            }
            tmp = top->Right;
            top->Right = nullptr;
        }
    }
}

int main() {
    auto root = createTree();
    std::cout << "----------pre order--------" << std::endl;
    preOrder(root);
    std::cout << "----------in order--------" << std::endl;
    root = createTree();
    inOrder(root);
    std::cout << "----------post order--------" << std::endl;
    root = createTree();
    postOrder(root);
    return 0;
}
