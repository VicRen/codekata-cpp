#include <iostream>
#include <string>
#include "leetcode.h"
#include "fsm.h"

using namespace std;

enum {
    on,
    off,
};

struct light {
    bool isOn_;

    fsm::stack fsm;

    light() : isOn_(false) {
        fsm.on(on, off) = [&](const fsm::args &args) {
            std::cout << "lights off" << std::endl;
            fsm.set(off);
        };
        fsm.on(off, on) = [&](const fsm::args &args) {
            std::cout << "lights on" << std::endl;
            fsm.set(on);
        };
        fsm.set(off);
    }
};

int main() {
    cout << "Code Kat for C++" << endl;
    auto leetCode = new LeetCode("1.0");

    leetCode->PrintVersion();
    light l;
    l.fsm.command(on);
    l.fsm.command(off);
    return 0;
}
