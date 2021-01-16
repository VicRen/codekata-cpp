#ifndef CODEKATA_CPP_STRING_WRAPPER_H
#define CODEKATA_CPP_STRING_WRAPPER_H

#include <string>

using namespace std;
class StringWrapper {
public:
    explicit StringWrapper(string s);

    string& getStr();

    void setStr(string s);

    void print();

private:
    string str;
};


#endif //CODEKATA_CPP_STRING_WRAPPER_H
