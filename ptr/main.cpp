#include <iostream>
#include <memory>

#include "string_wrapper.h"

using namespace std;
unique_ptr<StringWrapper> func() {
    return std::make_unique<StringWrapper>("Hello again, C++11!");
}

void print(unique_ptr<StringWrapper> s) {
    s->print();
}

void print(const StringWrapper& s) {
}

int main() {
    // unique_ptr can be
    auto sw = std::make_unique<StringWrapper>("Hello, World!");
    auto sw2 = std::make_unique<StringWrapper>("Hello, C++11!");
    sw->print();
    sw2->print();
    print(*sw);

    sw2 = std::move(sw);
    sw2->print();

    if (sw == nullptr) {
        cout << "StringWrapper is Null" << endl;
    }

    StringWrapper* p = sw2.release();
    if (sw2 == nullptr) {
        cout << "StringWrapper is Null" << endl;
    }
    p->print();

    sw.reset(p);
    sw->print();

    sw2 = func();
    sw2->print();

    print(std::move(sw2));
    if (sw2 == nullptr) {
        cout << "StringWrapper is Null" << endl;
    }

    auto sharedSw = make_shared<StringWrapper>("Hello again, World!");
    auto sharedSw2 = make_shared<StringWrapper>("Hello again, C++11!");
    sharedSw->print();
    sharedSw2->print();
    sharedSw2 = sharedSw;
    cout << "StringWrapper is not Null " << sharedSw.use_count() << " " << sharedSw2.use_count() << endl;
    sharedSw->print();
    sharedSw2->print();

    sharedSw2->setStr("Hello, C++11");
    sharedSw2->print();

    sharedSw.reset();
    sharedSw2.reset();

    if (sharedSw2 == nullptr) {
        cout << "all shared ptr released" << endl;
    }
    return 0;
}
