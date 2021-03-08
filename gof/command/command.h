#ifndef CODEKATA_CPP_COMMAND_H
#define CODEKATA_CPP_COMMAND_H

class Receiver {
public:
    Receiver();
    ~Receiver();
    void Action();
};

class Command {
public:
    virtual ~Command();
    virtual void Execute() = 0;

protected:
    Command();
};

class ConcreteCommand : public Command {
public:
    ConcreteCommand();
    ConcreteCommand(Receiver* receiver);
    ~ConcreteCommand() override;

    void Execute() override;

private:
    Receiver *receiver_;
};

class Invoker {
public:
    explicit Invoker(Command *cmd);
    ~Invoker();

    void Invoke();

private:
    Command *cmd_;
};


#endif //CODEKATA_CPP_COMMAND_H
