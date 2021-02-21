#include <iostream>
#include <string>

#include "leetcode.h"
#include "fsm.h"
#include "doubly_linked_list.h"
#include "factory.h"
#include "product.h"
#include "bridge/color.h"
#include "bridge/shape.h"
#include "bridge/square.h"

using namespace std;

enum {
    init,
    joining,
    joined,
    leaving,
};

struct venus {
    bool isJoined_;

    fsm::stack fsm;

    bool isJoined() {
        return fsm.is_state(joined);
    }

    venus() : isJoined_(false) {
        fsm.on(init, joining) = [&](const fsm::args &args) {
            std::cout << "venus init" << std::endl;
            fsm.set(joining);
        };
        fsm.on(joining, joined) = [&](const fsm::args &args) {
            std::cout << "venus joined" << std::endl;
            fsm.set(joined);
        };
        fsm.on(joined, leaving) = [&](const fsm::args &args) {
            std::cout << "venus leaving" << std::endl;
            fsm.set(leaving);
        };
        fsm.on(leaving, init) = [&](const fsm::args &args) {
            std::cout << "venus left" << std::endl;
            fsm.set(init);
        };
        fsm.set(joining);
    }
};

void TestingDoublyLinkedList() {
    Node *head = new Node(1);

    insert(&head, 2);
    insert(&head, 3);

    std::cout << "head data: " << head->value << std::endl;
    std::cout << "next data: " << head->pnx->value << std::endl;
}

void TestingFactory() {
    Factory *fac = new ConcreteFactory();
    Product *p = fac->CreateProduct();
}

void TestingBridge() {
    auto name = std::string("White");
    auto color = new Color(name);
    Shape *shape = new Square(color);
    shape->Draw();
    shape->Print();
}

int main() {
    cout << "Code Kat for C++" << endl;
    auto leetCode = new LeetCode("1.0");

    leetCode->PrintVersion();

    TestingDoublyLinkedList();
    TestingFactory();
    TestingBridge();

    venus l;
    l.fsm.command(init);
    l.fsm.command(joining);
    l.fsm.command(joined);
    std::cout << "is joined: " << l.isJoined() << std::endl;
    l.fsm.command(leaving);
    l.fsm.command(init);
    return 0;
}
