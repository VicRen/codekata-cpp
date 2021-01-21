#include <iostream>
#include <string>

using namespace std;

void lambdaToFunc() {
    int girls = 3, boys = 4;
    auto totalChild = [](int x, int y)->int {return x+y;};

    typedef int (*allChild)(int x, int y);
    typedef int (*oneChild)(int x);

    allChild p;
    p = totalChild;

    oneChild q;
//    q = totalChild; // cannot compile.

    decltype(totalChild) allPeople = totalChild;
//    decltype(totalChild) totalPeople = p; // cannot compile.
    allPeople(girls, boys);
}

void constLambda() {
    int val = 0;
    auto print = [&](const string& msg){
        cout << msg << val << endl;
    };
//    auto const_val_lambda = [=]() { val = 3; }; // cannot compile.
    auto mutable_val_lambda = [=]() mutable {
        print("mutable_val_lambda-val = ");
        val = 3;
        print("mutable_val_lambda-val = ");
    };
    print("val = ");
    mutable_val_lambda();
    print("val = ");
    auto const_ref_lambda = [&]() {val=3;};
    const_ref_lambda();
    print("val = ");

    val = 0;
    auto const_param_lambda = [](int x) { x = 3;};
    const_param_lambda(val);
    print("val = ");

}

int d = 0;

void tryCapture() {
//    auto ill_lambda = [d]{}; // 'd' cannot be captured because it does not have automatic storage duration;
}

int main() {
    int j = 12;
    auto by_val_lambda = [=]{return j+1;};
    auto by_ref_lambda = [&]{return j+1;};
    cout << "by_val_lambda: " << by_val_lambda() << endl;
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;

    j++;
    cout << "by_val_lambda: " << by_val_lambda() << endl;
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;
    lambdaToFunc();
    constLambda();
    return 0;
}