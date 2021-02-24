#include <iostream>

#include "flyweight.h"

Flyweight::Flyweight(const std::string &intrinsicState) {
    intrinsicState_ = intrinsicState;
}

Flyweight::~Flyweight() {

}

void Flyweight::Operation(const std::string &state) {
}

std::string Flyweight::GetIntrinsicState() {
    return intrinsicState_;
}

ConcreteFlyweight::ConcreteFlyweight(const std::string &intrinsicState) : Flyweight(
        intrinsicState) {
    std::cout << "ConcreteFlyweight Building..." << intrinsicState << std::endl;
}

ConcreteFlyweight::~ConcreteFlyweight() {
}

void ConcreteFlyweight::Operation(const std::string &state) {
    std::cout << "ConcreteFlyweight:[" << GetIntrinsicState() << "][" << state << "]" << std::endl;
}

FlyweightFactory::FlyweightFactory() {
}

FlyweightFactory::~FlyweightFactory() {

}

Flyweight *FlyweightFactory::GetFlyweight(const std::string &key) {
    auto it = fly_.begin();
    for (; it != fly_.end(); it++) {
        if ((*it)->GetIntrinsicState() == key) {
            std::cout << "already created by users..." << std::endl;
            return *it;
        }
    }
    Flyweight *fn = new ConcreteFlyweight(key);
    fly_.push_back(fn);
    return fn;
}
