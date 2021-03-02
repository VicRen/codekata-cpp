#include "strategy.h"

#include <iostream>

using namespace std;

Strategy::Strategy() {

}

Strategy::~Strategy() {
    cout << "~Strategy..." << endl;
}

ConcreteStrategyA::ConcreteStrategyA() {

}

ConcreteStrategyA::~ConcreteStrategyA() {
    cout << "~ConcreteStrategyA..." << endl;
}

void ConcreteStrategyA::AlgorithmInterface() {
    cout << "ConcreteStrategyA::AlgorithmInterface" << endl;
}

ConcreteStrategyB::ConcreteStrategyB() {

}

ConcreteStrategyB::~ConcreteStrategyB() {
    cout << "~ConcreteStrategyB..." << endl;
}

void ConcreteStrategyB::AlgorithmInterface() {
    cout << "ConcreteStrategyB::AlgorithmInterface" << endl;
}

Context::Context(Strategy *strategy) : strategy_(strategy) {
}

Context::~Context() {
    delete strategy_;

}

void Context::DoAction() {
    strategy_->AlgorithmInterface();
}
