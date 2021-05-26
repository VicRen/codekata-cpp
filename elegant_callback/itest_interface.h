#ifndef CODEKATA_CPP_ITEST_INTERFACE_H
#define CODEKATA_CPP_ITEST_INTERFACE_H

#include <functional>
#include <memory>

class ITestInterface {
public:
    using Callback = std::function<void()>;
    class Event {
    public:
        std::shared_ptr<Callback> callback;
    };
    virtual void doTest(std::shared_ptr<Event> event) = 0;
};

#endif //CODEKATA_CPP_ITEST_INTERFACE_H
