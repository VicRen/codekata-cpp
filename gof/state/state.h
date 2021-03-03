#ifndef CODEKATA_CPP_STATE_H
#define CODEKATA_CPP_STATE_H

class State;

class Ctx {
public:
    Ctx();
    Ctx(State *state);
    ~Ctx();
    void OperationInterface();
    void OperationChangeState();
private:
    friend class State;
    bool ChangeState(State *state);
private:
    State *state_;
};

class State {
public:
    State();

    virtual ~State();

    virtual void OperationInterface(Ctx *context) = 0;

    virtual void OperationChangeState(Ctx *context) = 0;

protected:
    bool ChangeState(Ctx *ctx, State *state);
};

class ConcreteStateA : public State {
public:
    ConcreteStateA();

    ~ConcreteStateA() override;

    void OperationInterface(Ctx *context) override;

    void OperationChangeState(Ctx *context) override;
};

class ConcreteStateB : public State {
public:
    ConcreteStateB();

    virtual ~ConcreteStateB();

    void OperationInterface(Ctx *context) override;

    void OperationChangeState(Ctx *context) override;
};


#endif //CODEKATA_CPP_STATE_H
