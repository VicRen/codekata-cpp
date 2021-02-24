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
#include "adapter/adapter.h"
#include "composite/leaf.h"
#include "composite/composite.h"
#include "flyweight/flyweight.h"

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

void TestingAdapter() {
    auto *adaptee = new Adaptee;
    Target *target = new Adapter(adaptee);
    target->Request();
}

void TestingComposite() {
    Leaf *l = new Leaf;
    l->Operation();

    auto *c = new Composite;
    c->Add(l);
    c->Operation();
    Component *com = c->GetChild(0);
    com->Operation();
}

void TestingFlyweight() {
    auto fc = new FlyweightFactory();
    auto fw1 = fc->GetFlyweight("hello");
    auto fw2 = fc->GetFlyweight("world");
    auto fw3 = fc->GetFlyweight("hello");
}

int main() {
    cout << "Code Kat for C++" << endl;
    auto leetCode = new LeetCode("1.0");

    leetCode->PrintVersion();

    TestingDoublyLinkedList();
    TestingFactory();
    TestingBridge();
    TestingAdapter();
    TestingComposite();
    TestingFlyweight();

    venus l;
    l.fsm.command(init);
    l.fsm.command(joining);
    l.fsm.command(joined);
    std::cout << "is joined: " << l.isJoined() << std::endl;
    l.fsm.command(leaving);
    l.fsm.command(init);
    return 0;
}
