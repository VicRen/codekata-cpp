#include <iostream>

using namespace std;

void change1(int n) {
    cout << "change1 n addr = " << &n << endl;
    n++;
}

void change2(int &n) {
    cout << "change2 n addr = " << &n << endl;
    n++;
}

void change3(int *n) {
    cout << "change3 n addr = " << n << endl;
    *n = *n+1;
}

int main() {
    int n = 10;
    cout << "n addr = " << &n << endl;
    change1(n);
    cout << "n = " << n << endl;
    change2(n);
    cout << "n = " << n << endl;
    change3(&n);
    cout << "n = " << n << endl;
    return 0;
}