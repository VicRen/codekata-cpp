#ifndef CODEKATA_CPP_ABSTRACTEXPRESSION_H
#define CODEKATA_CPP_ABSTRACTEXPRESSION_H

#include <string>

class InterpreterContext {
public:
    InterpreterContext();
    ~InterpreterContext();
};

class AbstractExpression {
public:
    virtual ~AbstractExpression();
    virtual void Interpret(const InterpreterContext &ctx);

protected:
    AbstractExpression();
};

class TerminalExpression : public AbstractExpression {
public:
    explicit TerminalExpression(const std::string &statement);
    ~TerminalExpression() override;
    void Interpret(const InterpreterContext &ctx);

private:
    std::string statement_;
};

class NonterminalExpression : public AbstractExpression {
public:
    NonterminalExpression(AbstractExpression *expression, int times);
    ~NonterminalExpression() override;
    void Interpret(const InterpreterContext &ctx) override;

private:
    AbstractExpression *expression_;
    int times_;
};


#endif //CODEKATA_CPP_ABSTRACTEXPRESSION_H
