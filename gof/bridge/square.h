#ifndef CODEKATA_CPP_SQUARE_H
#define CODEKATA_CPP_SQUARE_H

#include "shape.h"
#include "color.h"

class Square : public ColoredShape {
public:
    explicit Square(Color *color) : ColoredShape(color) {
    }
    void Draw() override;
    void Print() override;
};


#endif //CODEKATA_CPP_SQUARE_H
