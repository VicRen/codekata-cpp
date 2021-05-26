#include "test_interface_impl.h"

#include <iostream>

void TestInterfaceImpl::doTest(std::shared_ptr<Event> event) {
    auto cb = event->callback;
    (*cb)();
}
