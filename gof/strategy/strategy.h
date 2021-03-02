#ifndef CODEKATA_CPP_STRATEGY_H
#define CODEKATA_CPP_STRATEGY_H


class Strategy {
public:
    Strategy();

    virtual ~Strategy();

    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    ConcreteStrategyA();

    ~ConcreteStrategyA() override;

    void AlgorithmInterface() override;
};

class ConcreteStrategyB : public Strategy {
public:
    ConcreteStrategyB();

    ~ConcreteStrategyB() override;

    void AlgorithmInterface() override;
};

class Context {
public:
    explicit Context(Strategy *strategy);
    ~Context();

    void DoAction();

private:
    Strategy* strategy_;
};


#endif //CODEKATA_CPP_STRATEGY_H
