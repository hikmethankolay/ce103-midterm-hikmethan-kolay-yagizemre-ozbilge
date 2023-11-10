//#define ENABLE_TESTS  // Uncomment this line to enable the tests

#include "gtest/gtest.h"
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


int main(int argc, char **argv) {
#ifdef ENABLE_CALCULATOR_TEST
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  return 0;
#endif
}
