#ifndef CODEKATA_CPP_PRODUCT_H
#define CODEKATA_CPP_PRODUCT_H

class Product {
public:
    virtual ~Product() = 0;

protected:
    Product();

private:
};

class ConcreteProduct : public Product {
public:
    ~ConcreteProduct();
    ConcreteProduct();

protected:
private:
};

#endif //CODEKATA_CPP_PRODUCT_H
