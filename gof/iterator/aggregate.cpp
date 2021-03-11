#include "aggregate.h"

Aggregate::Aggregate() {

}

Aggregate::~Aggregate() {

}

ConcreteAggregate::ConcreteAggregate() {
    for (int i = 0; i < SIZE; i++) {
        objs_[i] = i;
    }
}

ConcreteAggregate::~ConcreteAggregate() {

}

Iterator *ConcreteAggregate::CreateIterator() {
    return nullptr;
}

Object ConcreteAggregate::GetItem(int index) {
    if (index < GetSize()) {
        return objs_[index];
    }
    return -1;
}

int ConcreteAggregate::GetSize() {
    return SIZE;
}

Iterator::Iterator() {

}

Iterator::~Iterator() {

}

ConcreteIterator::ConcreteIterator() {

}

ConcreteIterator::ConcreteIterator(Aggregate *ag, int index) {
    ag_ = ag;
    index_ = index;
}

ConcreteIterator::~ConcreteIterator() {

}

void ConcreteIterator::First() {
    index_ = 0;
}

void ConcreteIterator::Next() {
    if (index_ < ag_->GetSize()) {
        index_++;
    }
}

bool ConcreteIterator::IsDone() {
    return (index_ == ag_->GetSize());
}

Object ConcreteIterator::CurrentItem() {
    return ag_->GetItem(index_);
}
