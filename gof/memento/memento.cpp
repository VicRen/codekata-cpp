#include "memento.h"

#include <iostream>

Originator::Originator() {
    state_ = "";
    memento_ = nullptr;
}

Originator::Originator(const Originator::State &state) {
    state_ = state;
    memento_ = nullptr;
}

Originator::~Originator() {

}

Memento *Originator::CreateMemento() {
    return new Memento(state_);
}

void Originator::SetMemento(Memento *mt) {

}

void Originator::RestoreToMemento(Memento *mt) {
    state_ = mt->GetState();
}

Originator::State Originator::GetState() {
    return state_;
}

void Originator::SetState(const State &state) {
    state_ = state;
}

void Originator::PrintState() {
    std::cout << state_ << "..." << std::endl;
}

Memento::Memento() {

}

Memento::Memento(const Memento::State &state) {
    state_ = state;
}

Memento::~Memento() {

}

Memento::State Memento::GetState() {
    return state_;
}

void Memento::SetState(const Memento::State &state) {
    state_ = state;
}
