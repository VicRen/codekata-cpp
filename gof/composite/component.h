#ifndef CODEKATA_CPP_COMPONENT_H
#define CODEKATA_CPP_COMPONENT_H


class Component {
public:
    Component();
    virtual ~Component();

public:
    virtual void Operation() = 0;
    virtual void Add(const Component &component);
    virtual void Remove(const Component &component);
    virtual Component *GetChild(int index);
};


#endif //CODEKATA_CPP_COMPONENT_H
