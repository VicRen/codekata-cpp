#ifndef CODEKATA_CPP_CIRCLE_H
#define CODEKATA_CPP_CIRCLE_H

#include "shape.h"

class Circle : public ColoredShape {
public:
    Circle();
    void Draw() override;
    void Print() override;
};


#endif //CODEKATA_CPP_CIRCLE_H
