#include <iostream>

#include "facade.h"

using namespace std;

Subsystem1::Subsystem1() {

}

Subsystem1::~Subsystem1() {

}

void Subsystem1::Operation() {
    cout << "Subsystem1 Operation" << endl;
}

Subsystem2::Subsystem2() {

}

Subsystem2::~Subsystem2() {

}

void Subsystem2::Operation() {
    cout << "Subsystem2 Operation" << endl;
}

Facade::Facade() {
    sub1_ = make_unique<Subsystem1>();
    sub2_ = make_unique<Subsystem2>();
}

Facade::~Facade() {

}

void Facade::OperationWrapper() {
    sub1_->Operation();
    sub2_->Operation();
}
