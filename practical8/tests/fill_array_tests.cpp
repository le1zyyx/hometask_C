extern "C" {
#include "array_utils.h"
}

#include <gtest/gtest.h>

class FillArrayFromFileTest : public ::testing::Test {
protected:
    static const int size = 3;
    void** array;

    void SetUp() override {
        array = allocate_2d_array(size);
        ASSERT_NE(array, nullptr);
    }

    void TearDown() override {
        if (array) {
            free_2d_array(array, size);
        }
    }
};

TEST_F(FillArrayFromFileTest, HappyCaseWithValidFile) {
    testing::internal::CaptureStdout();
    int res = fill_2d_array_from_file(array, size, "./tests/data/tests.txt");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(res, 0);
    EXPECT_NE(output.find("Array filled from file"), std::string::npos);
}

TEST_F(FillArrayFromFileTest, ErrorWhenFileMissing) {
    int res = fill_2d_array_from_file(array, size, "./nonexistent.txt");
    EXPECT_EQ(res, -1);
}

TEST_F(FillArrayFromFileTest, NullArray) {
    int res = fill_2d_array_from_file(nullptr, size, "./tests/data/tests.txt");
    EXPECT_EQ(res, -1);
}

TEST_F(FillArrayFromFileTest, InvalidSize) {
    int res = fill_2d_array_from_file(array, 0, "./tests/data/tests.txt");
    EXPECT_EQ(res, -1);
}

TEST_F(FillArrayFromFileTest, NullFilename) {
    int res = fill_2d_array_from_file(array, size, nullptr);
    EXPECT_EQ(res, -1);
}
