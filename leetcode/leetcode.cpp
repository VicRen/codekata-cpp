#include <iostream>
#include "leetcode.h"

using namespace std;

void LeetCode::SetVersion(const string &version) {
    version_ = version;
}

string LeetCode::GetVersion() {
    return version_;
}

void LeetCode::PrintVersion() {
    cout << "Leet Code Version: " << version_ << endl;
}