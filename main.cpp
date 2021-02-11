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
        fsm.on(opening, insert) = [&](const fsm::args &args) {
            has_cd = true;
            fsm.set(opening);
        };
        fsm.on(opening, eject) = [&](const fsm::args &args) {
            has_cd = false;
            fsm.set(opening);
        };
        fsm.on(closing, open) = [&](const fsm::args &args) {
            open_tray();
            fsm.set(opening);
        };
        fsm.on(waiting, play) = [&](const fsm::args &args) {
            if (!good_disk_format()) {
                fsm.set(waiting);
            } else {
                start_playback(args[0]);
                fsm.set(playing);
            }
        };
        fsm.on(waiting, open) = [&](const fsm::args &args) {
            open_tray();
            fsm.set(opening);
        };
        fsm.on(playing, open) = [&](const fsm::args &args) {
            open_tray();
            fsm.set(opening);
        };
        fsm.on(playing, stop) = [&](const fsm::args &args) {
            fsm.set(waiting);
        };

        fsm.set(opening);
    }
};

int main() {
    cout << "Code Kat for C++" << endl;
    auto leetCode = new LeetCode("1.0");

    leetCode->PrintVersion();

    cd_player cd;
    cd.fsm.command(insert);
    cd.fsm.command(close);
//    cd.fsm.command(open);
    cd.fsm.command(play, 1);
    return 0;
}
