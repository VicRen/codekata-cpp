#ifndef CODEKATA_CPP_LEETCODE_H
#define CODEKATA_CPP_LEETCODE_H

#include <string>
#include <utility>

using namespace std;
class LeetCode {
public:
    explicit LeetCode(string version) : version_(std::move(version)) {}
    ~LeetCode() = default;

    void SetVersion(const string &version);
    string GetVersion();
    void PrintVersion();

    string replace(const string &str, char c, char r);
    static string reverse(const string &str);
private:
    string version_{};
};

#endif //CODEKATA_CPP_LEETCODE_H
