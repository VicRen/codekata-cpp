#include "state.h"

#include <iostream>

using namespace std;

Ctx::Ctx() {

}

Ctx::Ctx(State *state) : state_(state) {
}

Ctx::~Ctx() {

}

void Ctx::OperationInterface() {
    state_->OperationInterface(this);
}

bool Ctx::ChangeState(State *state) {
    state_ = state;
    return true;
}

void Ctx::OperationChangeState() {
    state_->OperationChangeState(this);
}

State::State() {

}

State::~State() {

}

void State::OperationInterface(Ctx *context) {
    cout << "State::OperationInterface" << endl;
}

bool State::ChangeState(Ctx *ctx, State *state) {
    ctx->ChangeState(state);
    return true;
}

ConcreteStateA::ConcreteStateA() {

}

ConcreteStateA::~ConcreteStateA() noexcept {

}

void ConcreteStateA::OperationInterface(Ctx *context) {
    cout << "ConcreteStateA::OperationInterface" << endl;
}

void ConcreteStateA::OperationChangeState(Ctx *context) {
    OperationInterface(context);
    ChangeState(context, new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB() {

}

ConcreteStateB::~ConcreteStateB() noexcept {

}

void ConcreteStateB::OperationInterface(Ctx *context) {
    cout << "ConcreteStateB::OperationInterface" << endl;
}

void ConcreteStateB::OperationChangeState(Ctx *context) {
    OperationInterface(context);
    ChangeState(context, new ConcreteStateA());
}
