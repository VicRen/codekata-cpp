#ifndef CODEKATA_CPP_SHAPE_H
#define CODEKATA_CPP_SHAPE_H

#include <memory>

class Color;

class Shape {
public:
    explicit Shape(Color *color) : color_(color) {}
    virtual ~Shape();

    virtual void Draw();

protected:
    std::unique_ptr<Color> color_;
};


#endif //CODEKATA_CPP_SHAPE_H
