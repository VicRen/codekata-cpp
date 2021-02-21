#include <iostream>

#include "square.h"

using namespace std;

void Square::Draw() {
    cout << "Drawing a "<< color_ << " Square" << endl;
}

void Square::Print() {
    cout << "I am a " << color_ << " Square" << endl;
}
