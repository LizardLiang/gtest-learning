#include <gtest/gtest.h>

int add(int a, int b) { return a + b; }

TEST(AddTest, Positive) {
  EXPECT_EQ(3, add(1, 2));
  EXPECT_EQ(5, add(2, 3));
}

TEST(AddTest, Negative) {
  EXPECT_EQ(-1, add(-1, 0));
  EXPECT_EQ(-5, add(-2, -3));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
