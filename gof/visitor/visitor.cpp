#include "visitor.h"

#include <iostream>

Element::Element() {

}

Element::~Element() {

}

ConcreteElementA::ConcreteElementA() {

}

ConcreteElementA::~ConcreteElementA() {

}

void ConcreteElementA::Accept(Visitor *visitor) {
    visitor->VisitConcreteElementA(this);
    std::cout << "Visiting ConcreteElementA" << std::endl;
}

ConcreteElementB::ConcreteElementB() {

}

ConcreteElementB::~ConcreteElementB() {

}

void ConcreteElementB::Accept(Visitor *visitor) {
    visitor->VisitConcreteElementB(this);
    std::cout << "Visiting ConcreteElementB" << std::endl;
}

Visitor::Visitor() {

}

Visitor::~Visitor() {

}

ConcreteVisitorA::ConcreteVisitorA() {

}

ConcreteVisitorA::~ConcreteVisitorA() {

}

void ConcreteVisitorA::VisitConcreteElementA(Element *element) {
    std::cout << "I will visit VisitConcreteElementA..." << std::endl;
}

void ConcreteVisitorA::VisitConcreteElementB(Element *element) {
    std::cout << "I will visit VisitConcreteElementB..." << std::endl;
}

ConcreteVisitorB::ConcreteVisitorB() {

}

ConcreteVisitorB::~ConcreteVisitorB() {

}

void ConcreteVisitorB::VisitConcreteElementA(Element *element) {
    std::cout << "I will visit VisitConcreteElementA..." << std::endl;
}

void ConcreteVisitorB::VisitConcreteElementB(Element *element) {
    std::cout << "I will visit VisitConcreteElementB..." << std::endl;
}
