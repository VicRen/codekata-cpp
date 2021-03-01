#ifndef CODEKATA_CPP_ABSTRACTCLASS_H
#define CODEKATA_CPP_ABSTRACTCLASS_H

class AbstractClass {
public:
    virtual ~AbstractClass();
    void TemplateMethod();

protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    AbstractClass();
};

class ConcreteClass1 : public AbstractClass {
public:
    ConcreteClass1();
    ~ConcreteClass1() override;

protected:
    void PrimitiveOperation1() override;
    void PrimitiveOperation2() override;
};

class ConcreteClass2 : public AbstractClass {
public:
    ConcreteClass2();
    ~ConcreteClass2() override;

protected:
    void PrimitiveOperation1() override;
    void PrimitiveOperation2() override;
};


#endif //CODEKATA_CPP_ABSTRACTCLASS_H
