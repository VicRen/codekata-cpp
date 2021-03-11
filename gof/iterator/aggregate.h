#ifndef CODEKATA_CPP_AGGREGATE_H
#define CODEKATA_CPP_AGGREGATE_H

typedef int Object;

class Iterator;

class Aggregate {
public:
    virtual ~Aggregate();

    virtual Iterator *CreateIterator() = 0;

    virtual Object GetItem(int index) = 0;

    virtual int GetSize() = 0;

protected:
    Aggregate();
};

class ConcreteAggregate : public Aggregate {
public:
    enum {
        SIZE = 3,
    };

    ConcreteAggregate();

    ~ConcreteAggregate() override;

    Iterator *CreateIterator() override;

    Object GetItem(int index) override;

    int GetSize() override;

private:
    Object objs_[SIZE];
};

class Iterator {
public:
    virtual ~Iterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Object CurrentItem() = 0;

protected:
    Iterator();
};

class ConcreteIterator : public Iterator {
public:
    ConcreteIterator();
    ConcreteIterator(Aggregate *ag, int index = 0);
    ~ConcreteIterator() override;

    void First() override;

    void Next() override;

    bool IsDone() override;

    Object CurrentItem() override;

private:
    Aggregate *ag_;
    int index_;
};


#endif //CODEKATA_CPP_AGGREGATE_H
