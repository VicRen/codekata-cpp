#include "observer.h"

#include <iostream>

ObserverSubject::ObserverSubject() {

}

ObserverSubject::~ObserverSubject() {

}

void ObserverSubject::Attach(Observer *observer) {
    observers_.push_front(observer);
}

void ObserverSubject::Detach(Observer *observer) {
    if (observer) {
        observers_.remove(observer);
    }
}

void ObserverSubject::Notify() {
    std::list<Observer*>::iterator it;
    it = observers_.begin();
    for (; it != observers_.end(); it++) {
        (*it)->Update(this);
    }
}

ConcreteObserverSubject::ConcreteObserverSubject() {
    state_ = '\0';
}

ConcreteObserverSubject::~ConcreteObserverSubject() noexcept {

}

ObserverState ConcreteObserverSubject::GetState() {
    return state_;
}

void ConcreteObserverSubject::SetState(const ObserverState &state) {
    state_ = state;
}

Observer::Observer() {
    state_ = '\0';
}

Observer::~Observer() {

}

ConcreteObserverA::ConcreteObserverA(ObserverSubject *subject) : sub_(subject) {

}

ConcreteObserverA::~ConcreteObserverA() {

}

ObserverSubject *ConcreteObserverA::GetSubject() {
    return sub_;
}

void ConcreteObserverA::Update(ObserverSubject *subject) {
    state_ = subject->GetState();
    PrintInfo();
}

void ConcreteObserverA::PrintInfo() {
    std::cout << "ConcreteObserverA::observer..." << sub_->GetState() << std::endl;
}

ConcreteObserverB::ConcreteObserverB(ObserverSubject *subject) : sub_(subject) {

}

ConcreteObserverB::~ConcreteObserverB() {

}

ObserverSubject *ConcreteObserverB::GetSubject() {
    return sub_;
}

void ConcreteObserverB::Update(ObserverSubject *subject) {
    state_ = subject->GetState();
    PrintInfo();
}

void ConcreteObserverB::PrintInfo() {
    std::cout << "ConcreteObserverB::observer..." << sub_->GetState() << std::endl;
}
