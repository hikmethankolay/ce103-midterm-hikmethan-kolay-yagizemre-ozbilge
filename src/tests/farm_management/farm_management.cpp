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

string testString =
  "0-)CROP TYPE | DATE OF PLANTING | DATE OF HARVESTING | CULTIVATED FIELD | EXPECTED QUANTITY\n1-)  Wheat   |    07/07/8888    |     07/07/9999     |     450m2        |       450Kg\n";

TEST_F(FarmTest, TestFileRead) {
  string result = file_read("../../../crop_records_test.txt");
  EXPECT_EQ(testString, result);
}

int main(int argc, char **argv) {
#ifdef ENABLE_TESTS
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  return 0;
#endif
}
