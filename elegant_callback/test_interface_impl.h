#ifndef CODEKATA_CPP_TEST_INTERFACE_H
#define CODEKATA_CPP_TEST_INTERFACE_H

#include "itest_interface.h"

class TestInterfaceImpl : public ITestInterface {
public:
    TestInterfaceImpl() = default;

    ~TestInterfaceImpl() = default;

    void doTest() override;
};

#endif //CODEKATA_CPP_TEST_INTERFACE_H
