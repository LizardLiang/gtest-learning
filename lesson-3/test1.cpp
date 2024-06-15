#include <gtest/gtest.h>
#include <string>

std::string reverseString(const std::string &str) {
  std::string reversed;
  for (auto it = str.rbegin(); it != str.rend(); ++it) {
    reversed += *it;
  }
  return reversed;
}

class ReverseStringTest
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {};

TEST_P(ReverseStringTest, ReverseString) {
  auto param = GetParam();
  ASSERT_EQ(param.second, reverseString(param.first));
}

INSTANTIATE_TEST_SUITE_P(
    ReverseStringTests, ReverseStringTest,
    ::testing::Values(std::make_pair("Hello, World!", "!dlroW ,olleH"),
                      std::make_pair("12345", "54321"),
                      std::make_pair("A", "A"), std::make_pair("", "")));

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
