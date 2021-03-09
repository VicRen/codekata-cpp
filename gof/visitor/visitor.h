#ifndef CODEKATA_CPP_VISITOR_H
#define CODEKATA_CPP_VISITOR_H

class Visitor;

class Element {
public:
    virtual ~Element();

    virtual void Accept(Visitor *visitor) = 0;

protected:
    Element();
};

class ConcreteElementA : public Element {
public:
    ConcreteElementA();

    ~ConcreteElementA() override;

    void Accept(Visitor *visitor) override;
};

class ConcreteElementB : public Element {
public:
    ConcreteElementB();

    ~ConcreteElementB() override;

    void Accept(Visitor *visitor) override;
};

class Visitor {
public:
    virtual ~Visitor();

    virtual void VisitConcreteElementA(Element *element) = 0;

    virtual void VisitConcreteElementB(Element *element) = 0;

protected:
    Visitor();
};

class ConcreteVisitorA : public Visitor {

public:
    ConcreteVisitorA();

    ~ConcreteVisitorA() override;

    void VisitConcreteElementA(Element *element) override;

    void VisitConcreteElementB(Element *element) override;
};

class ConcreteVisitorB : public Visitor {
    ConcreteVisitorB();

    ~ConcreteVisitorB() override;

public:
    void VisitConcreteElementA(Element *element) override;

    void VisitConcreteElementB(Element *element) override;
};


#endif //CODEKATA_CPP_VISITOR_H
