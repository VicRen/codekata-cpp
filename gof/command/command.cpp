#include "command.h"

#include <iostream>

Receiver::Receiver() {

}

Receiver::~Receiver() {

}

void Receiver::Action() {
    std::cout << "Receiver::Action..." << std::endl;
}

Command::Command() {

}

Command::~Command() {

}

ConcreteCommand::ConcreteCommand() {

}

ConcreteCommand::ConcreteCommand(Receiver* receiver) : receiver_(receiver) {
}

ConcreteCommand::~ConcreteCommand() {
}

void ConcreteCommand::Execute() {
    std::cout << "ConcreteCommand::Execute..." << std::endl;
    receiver_->Action();
}

Invoker::Invoker(Command *cmd) : cmd_(cmd) {
}

Invoker::~Invoker() {

}

void Invoker::Invoke() {
    cmd_->Execute();
}
