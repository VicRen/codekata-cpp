#ifndef CODEKATA_CPP_COLOR_H
#define CODEKATA_CPP_COLOR_H

#include <iostream>
#include <string>

class Color {
public:
    explicit Color(std::string &name) : name_(name) {}
    ~Color() = default;
    friend std::ostream& operator <<(std::ostream& strm, const Color* color) {
        strm << color->name_;
        return strm;
    }
private:
    std::string name_;
};


#endif //CODEKATA_CPP_COLOR_H
