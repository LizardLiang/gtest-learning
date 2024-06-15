#include <fstream>
#include <gtest/gtest.h>
#include <string>

class FileProcessor {
public:
  FileProcessor(const std::string &filename) : filename_(filename) {}

  bool write(const std::string &content) {
    std::ofstream file(filename_);
    if (!file.is_open()) {
      return false;
    }
    file << content;
    file.close();
    return true;
  }

  std::string read() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
      return "";
    }
    std::string content;
    std::string line;
    while (std::getline(file, line)) {
      content += line;
    }
    file.close();
    return content;
  }

private:
  std::string filename_;
};

class FileProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {
    processor = new FileProcessor("test.txt");
    processor->write("Initial content.");
  }

  void TearDown() override {
    delete processor;
    std::remove("test.txt");
  }

  FileProcessor *processor;
};

TEST_F(FileProcessorTest, Write) {
  ASSERT_TRUE(processor->write("Hello, World!"));
  ASSERT_EQ("Hello, World!", processor->read());
}

TEST_F(FileProcessorTest, Read) {
  ASSERT_EQ("Initial content.", processor->read());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
