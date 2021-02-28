#include "proxy.h"

#include <iostream>

ConcreteSubject::ConcreteSubject() {
}

void ConcreteSubject::Request() {
    std::cout << "Concrete Subject...request" << std::endl;
}

ConcreteSubject::~ConcreteSubject() {

}

Proxy::Proxy() {

}

Proxy::Proxy(Subject *sub) : sub_(sub) {
}

void Proxy::Request() {
    std::cout << "Proxy request" << std::endl;
    sub_->Request();
}