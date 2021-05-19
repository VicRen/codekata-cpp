#ifndef CODEKATA_CPP_FSM_TESTING_H
#define CODEKATA_CPP_FSM_TESTING_H

#include <iostream>
#include "fsm.h"

enum {
    walking = 'WALK',
    defending = 'DEFN',

    tick = 'tick',
};

struct ant_t {
    fsm::stack fsm;
    int health, distance, flow;

    ant_t() : health(0), distance(0), flow(1) {
        fsm.on(walking, 'init') = [&](const fsm::args &args) {
            std::cout << "initializing" << std::endl;
        };
        fsm.on(walking, 'quit') = [&](const fsm::args &args) {
            std::cout << "exiting" << std::endl;
        };
        fsm.on(walking, 'push') = [&](const fsm::args &args) {
            std::cout << "pushing current task" << std::endl;
        };
        fsm.on(walking, 'back') = [&](const fsm::args &args) {
            std::cout << "back from another task. remaining distance: " << distance << std::endl;
        };
        fsm.on(walking, tick) = [&](const fsm::args &args) {
            std::cout << "\r" << "\\|/-"[ distance % 4 ] << " walking " << (flow > 0 ? "-->" : "<--") << " ";
            distance += flow;
            if (1000 == distance) {
                std::cout << "at food!" << std::endl;
                flow = -flow;
            }
            if (-1000 == distance) {
                std::cout << "at home!" << std::endl;
                flow = -flow;
            }
        };
        fsm.on(defending, 'init') = [&](const fsm::args &args) {
            health = 1000;
            std::cout << "somebody is attacking me! he has " << health << " health points"
                      << std::endl;
        };
        fsm.on(defending, tick) = [&](const fsm::args &args) {
            std::cout << "\r" << "\\|/-$"[ health % 4 ] << " health: (" << health << ")   ";
            --health;
            if (health < 0) {
                std::cout << std::endl;
                fsm.pop();
            }
        };
        fsm.set(walking);
    }
};

#endif //CODEKATA_CPP_FSM_TESTING_H
