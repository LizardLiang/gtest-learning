#include <cmath>
#include <gtest/gtest.h>
#include <iostream>

double squareRoot(double x) { return std::sqrt(x); }

class TestEventListener : public ::testing::EmptyTestEventListener {
public:
  void OnTestStart(const ::testing ::TestInfo &test_info) override {
    std::cout << "Test Name: " << test_info.test_case_name() << "."
              << test_info.name() << std::endl;
  }

  void OnTestEnd(const ::testing::TestInfo &test_info) override {
    std::cout << "Test " << (test_info.result()->Passed() ? "PASSED" : "FAILED")
              << std::endl;
  }
};

::testing::AssertionResult IsNear(double val1, double val2, double epsilon) {
  if (std::fabs(val1 - val2) <= epsilon) {
    return ::testing::AssertionSuccess();
  } else {
    return ::testing::AssertionFailure()
           << val1 << " and " << val2 << " are not near each other";
  }
}

TEST(SquareRootTest, PositiveNos) {
  ASSERT_TRUE(IsNear(squareRoot(4.0), 2.0, 0.001));
  ASSERT_TRUE(IsNear(squareRoot(9.0), 3.0, 0.001));
  ASSERT_FALSE(IsNear(squareRoot(2.0), 1.5, 0.001)); // This will fail
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  ::testing::TestEventListeners &listeners =
      ::testing::UnitTest::GetInstance()->listeners();
  listeners.Append(new TestEventListener);

  return RUN_ALL_TESTS();
}
