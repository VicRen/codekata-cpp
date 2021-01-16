#include <iostream>
#include <memory>

#include "string_wrapper.h"

using namespace std;
unique_ptr<StringWrapper> func() {
    return std::make_unique<StringWrapper>("Hello again, C++11!");
}

int main() {
    auto sw = std::make_unique<StringWrapper>("Hello, World!");
    auto sw2 = std::make_unique<StringWrapper>("Hello, C++11!");
    sw->print();
    sw2->print();

    sw2 = std::move(sw);
    sw2->print();

    if (sw == nullptr) {
        cout << "StringWrapper is Null" << endl;
    }

    StringWrapper* p = sw2.release();
    if (sw == nullptr) {
        cout << "StringWrapper is Null" << endl;
    }
    p->print();

    sw.reset(p);
    sw->print();

    sw2 = func();
    sw2->print();
    return 0;
}
