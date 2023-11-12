#define ENABLE_TESTS  // Uncomment this line to enable the tests

#include "../../tests/googletest/googletest/include/gtest/gtest.h"
#include "../../farm_management_lib/include/farm_management_lib.h"  // Adjust this include path based on your project structure

class FarmTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Setup test data
  }

  void TearDown() override {
    // Clean up test data
  }
};

string testString;

TEST_F(FarmTest, TestFileRead) {
  testString = "0-)TEXT STRING0\n1-)TEXT STRING1\n2-)TEXT STRING2\n3-)TEXT STRING3\n4-)TEXT STRING4\n";
  EXPECT_EQ(testString, file_read("test1.txt"));
}

TEST_F(FarmTest, TestFileAppend) {
  testString = "0-)TEXT STRING0\n1-)TEXT STRING1\n2-)TEXT STRING2\n3-)TEXT STRING3\n4-)TEXT STRING4\n5-)TEXT STRING5\n";
  string appendString = "TEXT STRING5";
  file_append("test2.txt", appendString);
  EXPECT_EQ(testString, file_read("test2.txt"));
}

TEST_F(FarmTest, TestFileEdit) {
  testString = "0-)TEXT STRING0\n1-)TEXT STRING1\n2-)TEXT STRING2\n3-)TEXT STRING EDIT\n4-)TEXT STRING4\n";
  string editString = "TEXT STRING EDIT";
  file_edit("test3.txt", 3, editString);
  EXPECT_EQ(testString, file_read("test3.txt"));
}

TEST_F(FarmTest, TestFileDelete) {
  testString = "0-)TEXT STRING0\n1-)TEXT STRING1\n2-)TEXT STRING3\n3-)TEXT STRING4\n";
  file_line_delete("test4.txt", 2);
  EXPECT_EQ(testString, file_read("test4.txt"));
}

TEST_F(FarmTest, TestFileWrite) {
  testString = "0-)TEXT STRING WRITE\n";
  string writeString = "TEXT STRING WRITE";
  file_write("test5.txt", writeString);
  EXPECT_EQ(testString, file_read("test5.txt"));
}

int main(int argc, char **argv) {
#ifdef ENABLE_TESTS
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  return 0;
#endif
}
