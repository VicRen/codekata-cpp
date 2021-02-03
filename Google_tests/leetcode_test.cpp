#include "gtest/gtest.h"
#include "leetcode.h"
#include <iostream>

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

TEST(TESTING, TEST_REVERSE) {
    auto ret = LeetCode::reverse("testing");
    EXPECT_EQ(ret , "gnitset");
}

TEST(MULTIPLES, TEST_MULTIPLES_OF_3_5) {
    auto ret = LeetCode::multiplesOf35(16);
    EXPECT_EQ(ret, 15);

    std::cout << "multiples of 3 and 5: " << LeetCode::multiplesOf35(1000) << std::endl;
}

TEST(EULER_PORJECT, LARGEST_PRIME_FACTOR) {
    auto ret = LeetCode::largestPrimeFactor(10);
    EXPECT_EQ(ret, 5);
}

class PrimeFactorFixture : public ::testing::Test {

};

TEST_F(PrimeFactorFixture, PRIME_FACOTR_OF_1) {
    auto *expect = new vector<int>{};
    auto ret = LeetCode::findPrimeFactors(1);
    EXPECT_EQ(expect, ret);
}
