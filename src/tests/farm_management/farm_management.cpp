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
  testString = "0-)TEXT STRING0\n";
  string writeString = "TEXT STRING0";
  file_write("crop_records_test.txt", writeString);
  EXPECT_EQ(testString, file_read("crop_records_test.txt"));
}

TEST_F(FarmTest, TestFileAppend) {
  testString = "0-)TEXT STRING0\n1-)TEXT STRING1\n";
  string appendString = "TEXT STRING1";
  file_append("crop_records_test.txt", appendString);
  EXPECT_EQ(testString, file_read("crop_records_test.txt"));
}

TEST_F(FarmTest, TestFileEdit) {
  testString = "0-)TEXT STRING0\n1-)TEXT STRING2\n";
  string editString = "TEXT STRING2";
  file_edit("crop_records_test.txt", 1, editString);
  EXPECT_EQ(testString, file_read("crop_records_test.txt"));
}

TEST_F(FarmTest, TestFileDelete) {
  testString = "0-)TEXT STRING0\n";
  file_line_delete("crop_records_test.txt", 1);
  EXPECT_EQ(testString, file_read("crop_records_test.txt"));
}

TEST_F(FarmTest, TestFileWrite) {
  testString = "0-)TEXT STRING0\n";
  string writeString = "TEXT STRING0";
  file_write("crop_records_test.txt", writeString);
  EXPECT_EQ(testString, file_read("crop_records_test.txt"));
}

int main(int argc, char **argv) {
#ifdef ENABLE_TESTS
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  return 0;
#endif
}
