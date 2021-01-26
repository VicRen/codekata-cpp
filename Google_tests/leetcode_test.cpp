#include "gtest/gtest.h"
#include "leetcode.h"

class LeetCodeFixture : public ::testing::Test {
protected:
    void SetUp() override {
        leetCode = new LeetCode("1.0");
    }

    void TearDown() override {
        delete leetCode;
    }

    LeetCode *leetCode;
};

TEST_F(LeetCodeFixture, TEST_VERSION) {
    string version = "2.0";
    leetCode->PrintVersion();
    leetCode->SetVersion(version);
    leetCode->PrintVersion();

    EXPECT_EQ(leetCode->GetVersion(), version);
}

TEST_F(LeetCodeFixture, TEST_REPLACE) {
    auto ret = leetCode->replace("testing", 't', 'r');
    EXPECT_EQ(ret, "resring");
}
