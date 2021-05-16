#include <iostream>
#include <string>

#include "leetcode.h"
#include "fsm.h"
#include "doubly_linked_list.h"
#include "factory/factory.h"
#include "factory/product.h"
#include "bridge/color.h"
#include "bridge/shape.h"
#include "bridge/square.h"
#include "adapter/adapter.h"
#include "composite/leaf.h"
#include "composite/composite.h"
#include "flyweight/flyweight.h"
#include "facade/facade.h"
#include "proxy/proxy.h"
#include "template/template.h"
#include "strategy/strategy.h"
#include "state/state.h"
#include "observer/observer.h"
#include "memento/memento.h"
#include "mediator/mediator.h"
#include "command/command.h"
#include "visitor/visitor.h"
#include "chain/handle.h"
#include "iterator/aggregate.h"
#include "interpreter/interpret.h"

#include "elegant_callback/test_interface_impl.h"

#include <random>
#include <type_traits>

class IDGenerator {
public:
    explicit IDGenerator(unsigned int seed = 0) : seed_(seed) {
    }
    ~IDGenerator() = default;
    unsigned int GenerateID() {
        std::default_random_engine defEngine(seed_);
        std::uniform_real_distribution<unsigned int> dblDistro(0U, RAND_MAX);
        return dblDistro(defEngine);
    }

    static std::string ToString(unsigned int id) {
        return std::to_string(id);
    }

    static unsigned int ToInt(std::string id) {
        return std::stoul(id);
    }
private:
    unsigned int seed_;
};

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

void TestingFacade() {
    auto f = new Facade;
    f->OperationWrapper();
}

void TestingProxy() {
    Subject *sub = new ConcreteSubject;
    auto p = new Proxy(sub);
    p->Request();
}

void TestingTemplate() {
    AbstractClass *p1 = new ConcreteClass1();
    AbstractClass *p2 = new ConcreteClass2;
    p1->TemplateMethod();
    p2->TemplateMethod();
}

void TestingStrategy() {
    Strategy *ps = new ConcreteStrategyA;
    auto *pc = new Context(ps);
    pc->DoAction();
    delete pc;
}

void TestingStat() {
    State *state = new ConcreteStateA;
    Ctx *context = new Ctx(state);
    context->OperationInterface();
    context->OperationInterface();
    context->OperationInterface();
    context->OperationChangeState();
    context->OperationChangeState();
    context->OperationChangeState();
}

void TestingObserver() {
    auto sub = new ConcreteObserverSubject;
    auto o1 = new ConcreteObserverA(sub);
    auto o2 = new ConcreteObserverB(sub);
    sub->Attach(o1);
    sub->SetState("old");
    sub->Notify();
    sub->Attach(o2);
    sub->SetState("new");
    sub->Notify();
}

void TestingMemento() {
    auto o = new Originator;
    o->SetState("old");
    o->PrintState();
    Memento *m = o->CreateMemento();
    o->SetState("new");
    o->PrintState();
    o->RestoreToMemento(m);
    o->PrintState();
}

void TestingMediator() {
    auto m = new ConcreteMediator;
    auto c1 = new ConcreteColleagueA(m);
    auto c2 = new ConcreteColleagueB(m);
    m->IntroColleague(c1, c2);
    c1->SetState("old");
    c2->SetState("old");
    c1->Action();
    c2->Action();
    std::cout << std::endl;

    c1->SetState("new");
    c1->Action();
    c2->Action();
    std::cout << std::endl;

    c2->SetState("old");
    c2->Action();
    c1->Action();
}

void TestingCommand() {
    auto rev = new Receiver;
    auto cmd = new ConcreteCommand(rev);
    auto inv = new Invoker(cmd);
    inv->Invoke();
}

void TestingVisitor() {
    Visitor *visitor = new ConcreteVisitorA;
    Element *element = new ConcreteElementA;
    element->Accept(visitor);
}

void TestingChainOfResponsibility() {
    Handle *h1 = new ConcreteHandleA;
    Handle *h2 = new ConcreteHandleB;

    h1->SetSuccessor(h2);
    h1->HandleRequest();
}

void TestingIterator() {
    Aggregate *ag = new ConcreteAggregate;
    Iterator *it = new ConcreteIterator(ag);

    for (; !(it->IsDone()); it->Next()) {
        std::cout << "iterator: " << it->CurrentItem() << std::endl;
    }
}

void TestingInterpreter() {
    auto c = new InterpreterContext;
    AbstractExpression *e = new TerminalExpression("hello");
    AbstractExpression *nte = new NonterminalExpression(e, 2);
    nte->Interpret(*c);
}

void TestingCallback() {
    auto t = new TestInterfaceImpl;
    t->doTest();
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
    TestingFacade();
    TestingProxy();
    TestingTemplate();
    TestingStrategy();
    TestingStat();
    TestingObserver();
    TestingMemento();
    TestingMediator();
    TestingCommand();
    TestingVisitor();
    TestingChainOfResponsibility();
    TestingIterator();
    TestingInterpreter();
    TestingCallback();

    venus l;
    l.fsm.command(init);
    l.fsm.command(joining);
    l.fsm.command(joined);
    std::cout << "is joined: " << l.isJoined() << std::endl;
    l.fsm.command(leaving);
    l.fsm.command(init);

    auto ig = new IDGenerator(time(nullptr));
    auto id = ig->GenerateID();
    std::cout << "---->id: " << id << std::endl;
    std::string idStr = IDGenerator::ToString(id);
    std::cout << "---->id to string: " << idStr << std::endl;
    unsigned int ti;
    ti = IDGenerator::ToInt(idStr);
    std::cout << "---->id to int: " << ti << std::endl;
    return 0;
}
