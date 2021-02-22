#include <iostream>

#include "adapter.h"

Target::Target() {

}

Target::~Target() {

}

void Target::Request() {
    std::cout << "Target::Request" << std::endl;
}

Adaptee::Adaptee() {

}

Adaptee::~Adaptee() {

}

void Adaptee::SpecialRequest() {
    std::cout << "Adaptee::SpecialRequest" << std::endl;
}

Adapter::Adapter(Adaptee *adaptee) : adaptee_(adaptee) {

}

Adapter::~Adapter() {

}

void Adapter::Request() {
    adaptee_->SpecialRequest();
}