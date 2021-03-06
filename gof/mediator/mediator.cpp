#include "mediator.h"

#include <iostream>

Colleague::Colleague() {

}

Colleague::Colleague(Mediator *mediator) : mediator_(mediator) {

}

Colleague::~Colleague() {

}

ConcreteColleagueA::ConcreteColleagueA() {

}

ConcreteColleagueA::ConcreteColleagueA(Mediator *mediator) : Colleague(mediator) {

}

ConcreteColleagueA::~ConcreteColleagueA() {

}

void ConcreteColleagueA::Action() {
    mediator_->DoActionFromAtoB();
    std::cout << "State of ConcreteColleagueB:" << GetState() << std::endl;
}

void ConcreteColleagueA::SetState(const std::string &state) {
    state_ = state;
}

std::string ConcreteColleagueA::GetState() {
    return state_;
}

ConcreteColleagueB::ConcreteColleagueB() {

}

ConcreteColleagueB::ConcreteColleagueB(Mediator *mediator) : Colleague(mediator) {

}

ConcreteColleagueB::~ConcreteColleagueB() {

}

void ConcreteColleagueB::Action() {
    mediator_->DoActionFromBtoA();
    std::cout << "State of ConcreteColleagueA:" << GetState() << std::endl;
}

void ConcreteColleagueB::SetState(const std::string &state) {
    state_ = state;
}

std::string ConcreteColleagueB::GetState() {
    return state_;
}

Mediator::Mediator() {

}

Mediator::~Mediator() {

}

ConcreteMediator::ConcreteMediator() {

}

ConcreteMediator::ConcreteMediator(Colleague *colleagueA, Colleague *colleagueB)
        : colleagueA_(colleagueA), colleagueB_(colleagueB) {

}

ConcreteMediator::~ConcreteMediator() {

}

void ConcreteMediator::DoActionFromAtoB() {
    colleagueB_->SetState(colleagueA_->GetState());
}

void ConcreteMediator::DoActionFromBtoA() {
    colleagueA_->SetState(colleagueB_->GetState());
}

void ConcreteMediator::SetColleagueA(Colleague *colleague) {
    colleagueA_ = colleague;
}

void ConcreteMediator::SetColleagueB(Colleague *colleague) {
    colleagueB_ = colleague;
}

Colleague *ConcreteMediator::GetColleagueA() {
    return colleagueA_;
}

Colleague *ConcreteMediator::GetColleagueB() {
    return colleagueB_;
}

void ConcreteMediator::IntroColleague(Colleague *colleagueA, Colleague *colleagueB) {
    colleagueA_ = colleagueA;
    colleagueB_ = colleagueB;
}
