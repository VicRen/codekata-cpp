#ifndef CODEKATA_CPP_PROXY_H
#define CODEKATA_CPP_PROXY_H

class Subject {
public:
    virtual void Request() = 0;
};

class ConcreteSubject : public Subject {
public:
    ConcreteSubject();
    ~ConcreteSubject();
    void Request() override;
};

class Proxy {
public:
    Proxy();
    Proxy(Subject *sub);
    ~Proxy();
    void Request();

protected:
private:
    Subject *sub_;
};


#endif //CODEKATA_CPP_PROXY_H
