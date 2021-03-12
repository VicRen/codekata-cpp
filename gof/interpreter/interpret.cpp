#include "interpret.h"

#include <iostream>

InterpreterContext::InterpreterContext() {

}

InterpreterContext::~InterpreterContext() {

}

AbstractExpression::AbstractExpression() {

}

AbstractExpression::~AbstractExpression() {

}

void AbstractExpression::Interpret(const InterpreterContext &ctx) {

}

TerminalExpression::TerminalExpression(const std::string &statement) {
    statement_ = statement;
}

TerminalExpression::~TerminalExpression() {

}

void TerminalExpression::Interpret(const InterpreterContext &ctx) {
    std::cout << statement_ << "TerminalExpression" << std::endl;
}

NonterminalExpression::NonterminalExpression(AbstractExpression *expression, int times) {
    expression_ = expression;
    times_ = times;
}

NonterminalExpression::~NonterminalExpression() {

}

void NonterminalExpression::Interpret(const InterpreterContext &ctx) {
    for (int i = 0; i < times_; i++) {
        expression_->Interpret(ctx);
    }
}
