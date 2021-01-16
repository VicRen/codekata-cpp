#include "string_wrapper.h"

#include <utility>
#include <iostream>

StringWrapper::StringWrapper(string s) : str(std::move(s)) {
}

string &StringWrapper::getStr() {
    return str;
}

void StringWrapper::setStr(string s) {
    str = std::move(s);
}

void StringWrapper::print() {
    std::cout << str << endl;
}
