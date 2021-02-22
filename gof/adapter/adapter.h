#ifndef CODEKATA_CPP_TARGET_H
#define CODEKATA_CPP_TARGET_H

class Target {
public:
    Target();
    virtual ~Target();
    virtual void Request();
};

class Adaptee {
public:
    Adaptee();
    ~Adaptee();
    void SpecialRequest();
};

class Adapter : public Target {
public:
    Adapter(Adaptee *adaptee);
    ~Adapter();
    void Request();

private:
    Adaptee *adaptee_;
};


#endif //CODEKATA_CPP_TARGET_H
