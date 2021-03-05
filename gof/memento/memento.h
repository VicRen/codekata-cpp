#ifndef CODEKATA_CPP_MEMENTO_H
#define CODEKATA_CPP_MEMENTO_H

#include <string>

class Memento;

class Originator {
public:
    typedef std::string State;

    Originator();

    explicit Originator(const State &state);

    ~Originator();

    Memento *CreateMemento();

    void SetMemento(Memento *mt);

    void RestoreToMemento(Memento *mt);

    State GetState();

    void SetState(const State &state);

    void PrintState();

private:
    State state_;
    Memento *memento_;
};

class Memento {
private:
    friend class Originator;

    typedef std::string State;

    Memento();

    explicit Memento(const State &state);

    ~Memento();

    void SetState(const State &state);

    State GetState();

    State state_;
};


#endif //CODEKATA_CPP_MEMENTO_H
