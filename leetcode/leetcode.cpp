#include <iostream>
#include <sstream>
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

string LeetCode::replace(const string &str, const char c, char r) {
    cout << "char: " << c << endl;
    stringstream ss;
    PrintVersion();
    for_each(str.begin(), str.end(), [c, r, &ss](char i) {
        cout << "string: " << i << endl;
        if (i != c) {
            ss << i;
        } else {
            ss << r;
        }
    });
    return ss.str();
}
