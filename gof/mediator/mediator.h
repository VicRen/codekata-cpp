#ifndef CODEKATA_CPP_MEDIATOR_H
#define CODEKATA_CPP_MEDIATOR_H

#include <string>

class Mediator;

class Colleague {
public:
    virtual ~Colleague();

    virtual void Action() = 0;

    virtual void SetState(const std::string &state) = 0;

    virtual std::string GetState() = 0;

protected:
    Colleague();

    explicit Colleague(Mediator *mediator);

    Mediator *mediator_;
};

class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA();

    explicit ConcreteColleagueA(Mediator *mediator);

    ~ConcreteColleagueA() override;

    void Action() override;

    void SetState(const std::string &state) override;

    std::string GetState() override;

private:
    std::string state_;
};

class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB();

    explicit ConcreteColleagueB(Mediator *mediator);

    ~ConcreteColleagueB() override;

    void Action() override;

    void SetState(const std::string &state) override;

    std::string GetState() override;

private:
    std::string state_;
};

class Mediator {
public:
    virtual ~Mediator();

    virtual void DoActionFromAtoB() = 0;

    virtual void DoActionFromBtoA() = 0;

protected:
    Mediator();
};

class ConcreteMediator : public Mediator {
public:
    ConcreteMediator();

    ConcreteMediator(Colleague *colleagueA, Colleague *colleagueB);

    ~ConcreteMediator() override;

    void SetColleagueA(Colleague *colleague);

    void SetColleagueB(Colleague *colleague);

    Colleague *GetColleagueA();

    Colleague *GetColleagueB();

    void IntroColleague(Colleague *colleagueA, Colleague *colleagueB);

    void DoActionFromAtoB() override;

    void DoActionFromBtoA() override;

private:
    Colleague *colleagueA_;
    Colleague *colleagueB_;
};


#endif //CODEKATA_CPP_MEDIATOR_H
