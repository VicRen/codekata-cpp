#include "handle.h"

#include <iostream>

Handle::Handle() {
    succ_ = nullptr;
}

Handle::Handle(Handle *succ) : succ_(succ) {

}

Handle::~Handle() {
    delete succ_;
}

void Handle::SetSuccessor(Handle *succ) {
    succ_ = succ;
}

Handle *Handle::GetSuccessor() {
    return succ_;
}

ConcreteHandleA::ConcreteHandleA() {

}

ConcreteHandleA::~ConcreteHandleA() {

}

ConcreteHandleA::ConcreteHandleA(Handle *succ) : Handle(succ) {
}

void ConcreteHandleA::HandleRequest() {
    if (GetSuccessor()) {
        std::cout << "ConcreteHandleA..." << std::endl;
    }
}

ConcreteHandleB::ConcreteHandleB() {

}

ConcreteHandleB::~ConcreteHandleB() {

}

ConcreteHandleB::ConcreteHandleB(Handle *succ) : Handle(succ) {
}

void ConcreteHandleB::HandleRequest() {
    if (GetSuccessor()) {
        std::cout << "ConcreteHandleB..." << std::endl;
    }
}
