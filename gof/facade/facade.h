#ifndef CODEKATA_CPP_FACADE_H
#define CODEKATA_CPP_FACADE_H

#include <memory>

class Subsystem1 {
public:
    Subsystem1();
    ~Subsystem1();
    void Operation();
};

class Subsystem2 {
public:
    Subsystem2();
    ~Subsystem2();
    void Operation();
};

class Facade {
public:
    Facade();
    ~Facade();
    void OperationWrapper();

private:
    std::unique_ptr<Subsystem1> sub1_;
    std::unique_ptr<Subsystem2> sub2_;
};


#endif //CODEKATA_CPP_FACADE_H
