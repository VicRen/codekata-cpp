#include "composite.h"

using namespace std;

Composite::Composite() {

}

Composite::~Composite() {

}

void Composite::Operation() {
    auto iter = comVec.begin();
    for (; iter != comVec.end(); iter++) {
        (*iter)->Operation();
    }
}

void Composite::Add(Component *com) {
    comVec.push_back(com);
}

void Composite::Remote(Component *com) {
//    comVec.erase(&com);
}

Component *Composite::GetChild(int index) {
    return comVec[index];
}
