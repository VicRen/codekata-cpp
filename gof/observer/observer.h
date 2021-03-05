#ifndef CODEKATA_CPP_OBSERVER_H
#define CODEKATA_CPP_OBSERVER_H

#include <string>
#include <list>

typedef std::string ObserverState;

class Observer;

class ObserverSubject {
public:
    virtual ~ObserverSubject();

    virtual void Attach(Observer *observer);

    virtual void Detach(Observer *observer);

    virtual void Notify();

    virtual void SetState(const ObserverState &state) = 0;

    virtual ObserverState GetState() = 0;

protected:
    ObserverSubject();

private:
    std::list<Observer *> observers_;
};

class ConcreteObserverSubject : public ObserverSubject {
public:
    ConcreteObserverSubject();

    ~ConcreteObserverSubject();

    ObserverState GetState() override;

    void SetState(const ObserverState &state) override;

private:
    ObserverState state_;
};

class Observer {
public:
    virtual ~Observer();

    virtual void Update(ObserverSubject *sub) = 0;

    virtual void PrintInfo() = 0;

protected:
    Observer();

    ObserverState state_;
};

class ConcreteObserverA : public Observer {
public:
    virtual ObserverSubject* GetSubject();
    explicit ConcreteObserverA(ObserverSubject* subject);
    ~ConcreteObserverA() override;
    void Update(ObserverSubject* subject) override;
    void PrintInfo() override;
private:
    ObserverSubject *sub_;
};

class ConcreteObserverB : public Observer {
public:
    virtual ObserverSubject* GetSubject();
    ConcreteObserverB(ObserverSubject* subject);
    virtual ~ConcreteObserverB();
    void Update(ObserverSubject* subject) override;
    void PrintInfo() override;
private:
    ObserverSubject *sub_;
};


#endif //CODEKATA_CPP_OBSERVER_H
