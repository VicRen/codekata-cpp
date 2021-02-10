#include <iostream>
#include <string>
#include "leetcode.h"
#include "fsm.h"

using namespace std;

enum {
    opening,
    closing,
    waiting,
    playing,

    open,
    close,
    play,
    stop,
    insert,
    eject,
};

struct cd_player {
    bool has_cd;

    bool good_disk_format() {
        return true;
    }

    void open_tray() {
        std::cout << "opening tray" << std::endl;
    }

    void close_tray() {
        std::cout << "closing tray" << std::endl;
    }

    void get_cd_info() {
        std::cout << "retrieving CD info" << std::endl;
    }

    void start_playback(const std::string &track) {
        std::cout << "playing track # " << track << std::endl;
    }

    fsm::stack fsm;

    cd_player() : has_cd(false) {
        fsm.on(opening, close) = [&](const fsm::args &args) {
            close_tray();
            if (!has_cd) {
                fsm.set(closing);
            } else {
                get_cd_info();
                fsm.set(waiting);
            }
        };

        fsm.set(opening);
    }
};

int main() {
    cout << "Code Kat for C++" << endl;
    auto leetCode = new LeetCode("1.0");

    leetCode->PrintVersion();

    cd_player cd;
    cd.fsm.command(close);
    return 0;
}
