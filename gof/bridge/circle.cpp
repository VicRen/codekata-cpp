#include <iostream>

#include "circle.h"

using namespace std;
void Circle::Draw() {
    cout << "Drawing a circle" << endl;
}

void Circle::Print() {
    cout << "I am a " << color_ << " circle" << endl;
}
