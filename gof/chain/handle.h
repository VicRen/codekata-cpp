#ifndef CODEKATA_CPP_HANDLE_H
#define CODEKATA_CPP_HANDLE_H


class Handle {
public:
    virtual ~Handle();
    virtual void HandleRequest() = 0;
    void SetSuccessor(Handle *succ);
    Handle *GetSuccessor();

protected:
    Handle();
    explicit Handle(Handle *succ);

private:
    Handle* succ_;
};

class ConcreteHandleA : public Handle {
public:
    ConcreteHandleA();
    ~ConcreteHandleA() override;
    explicit ConcreteHandleA(Handle *succ);

    void HandleRequest() override;
};

class ConcreteHandleB : public Handle {
public:
    ConcreteHandleB();
    ~ConcreteHandleB() override;
    explicit ConcreteHandleB(Handle *succ);

    void HandleRequest() override;
};


#endif //CODEKATA_CPP_HANDLE_H
