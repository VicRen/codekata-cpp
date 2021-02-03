#include <iostream>
#include <sstream>
#include <vector>
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

string LeetCode::reverse(const string &str) {
    stringstream ss;
    for_each(str.rbegin(), str.rend(), [str, &ss](char i) {
        ss << i;
    });
    return ss.str();
}

int LeetCode::multiplesOf35(const int limit) {
    int ret = 0;
    for (int i = 3; i < limit; i++) {
        if ((i % 3 == 0) && (i % 5 == 0)) {
            ret += i;
        }
    }
    return ret;
}

int LeetCode::largestPrimeFactor(int n) {
    int max = 0;
    int divider = 2;
    while (n > 1) {
        while (n % divider == 0) {
            n = n / divider;
            if (divider > max) {
                max = divider;
            }
        }
        divider++;
    }
    return max;
}

vector<int> *LeetCode::findPrimeFactors(int n) {
    auto *ret = new vector<int>;
    return ret;
}
