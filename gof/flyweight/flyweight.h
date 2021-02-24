#ifndef CODEKATA_CPP_FLYWEIGHT_H
#define CODEKATA_CPP_FLYWEIGHT_H

#include <string>
#include <vector>

class Flyweight {
public:
    virtual ~Flyweight();

    virtual void Operation(const std::string &state);
    std::string GetIntrinsicState();

protected:
    explicit Flyweight(const std::string &intrinsicState);

private:
    std::string intrinsicState_;
};

class ConcreteFlyweight : public Flyweight {
public:
    explicit ConcreteFlyweight(const std::string &intrinsicState);
    ~ConcreteFlyweight() override;

    void Operation(const std::string &state) override;
};

class FlyweightFactory {
public:
    FlyweightFactory();
    ~FlyweightFactory();

    Flyweight *GetFlyweight(const std::string &key);

private:
    std::vector<Flyweight*> fly_;
};


#endif //CODEKATA_CPP_FLYWEIGHT_H
