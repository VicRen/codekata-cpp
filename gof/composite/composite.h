#ifndef CODEKATA_CPP_COMPOSITE_H
#define CODEKATA_CPP_COMPOSITE_H

#include <vector>

#include "component.h"

class Composite : public Component {
public:
    Composite();
    ~Composite();

    void Operation();
    void Add(Component *com);
    void Remote(Component *com);
    Component *GetChild(int index);
private:
    std::vector<Component*> comVec;
};


#endif //CODEKATA_CPP_COMPOSITE_H
