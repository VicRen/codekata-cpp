#ifndef CODEKATA_CPP_SHAPE_H
#define CODEKATA_CPP_SHAPE_H

#include <memory>
#include "color.h"

class Shape {
public:
    explicit Shape() {}
    virtual ~Shape() {}

    virtual void Draw() = 0;

protected:
};

class ColoredShape : public Shape {
public:
    explicit ColoredShape(Color *color) {
        color_ = std::unique_ptr<Color>(color);
    }

protected:
    std::unique_ptr<Color> color_;
};


#endif //CODEKATA_CPP_SHAPE_H
