#include <iostream>
#include <string>
#include "leetcode.h"
#include "fsm.h"

using namespace std;

enum {
    init,
    joining,
    joined,
    leaving,
};

struct venus {
    bool isJoined_;

    fsm::stack fsm;

    venus() : isJoined_(false) {
        fsm.on(init, joining) = [&](const fsm::args &args) {
            std::cout << "venus init" << std::endl;
            fsm.set(joining);
        };
        fsm.on(joining, joined) = [&](const fsm::args &args) {
            std::cout << "venus joined" << std::endl;
            fsm.set(joined);
        };
        fsm.on(joined, leaving) = [&](const fsm::args &args) {
            std::cout << "venus leaving" << std::endl;
            fsm.set(leaving);
        };
        fsm.on(leaving, init) = [&](const fsm::args &args) {
            std::cout << "venus left" << std::endl;
            fsm.set(init);
        };
        fsm.set(joining);
    }
};

int main() {
    cout << "Code Kat for C++" << endl;
    auto leetCode = new LeetCode("1.0");

    leetCode->PrintVersion();
    venus l;
    l.fsm.command(init);
    l.fsm.command(joining);
    l.fsm.command(joined);
    l.fsm.command(leaving);
    l.fsm.command(init);
    return 0;
}
