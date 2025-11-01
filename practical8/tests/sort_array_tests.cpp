extern "C" {
#include "array_utils.h"
}

#include <gtest/gtest.h>

class SortArrayTest : public ::testing::Test {
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

    bool isRowSorted(int row_idx) {
        int* row = (int*)array[row_idx];
        for (int i = 0; i < size - 1; i++) {
            if (row[i] > row[i + 1]) return false;
        }
        return true;
    }
};

TEST_F(SortArrayTest, SortArrayWithRandomNumbers) {
    fill_2d_array(array, size);
    sort_2d_array(array, size);
    
    for (int i = 0; i < size; i++) {
        EXPECT_TRUE(isRowSorted(i));
    }
}

TEST_F(SortArrayTest, SortArrayAlreadySorted) {
    int* row0 = (int*)array[0];
    int* row1 = (int*)array[1];
    int* row2 = (int*)array[2];
    
    row0[0] = 1; row0[1] = 2; row0[2] = 3;
    row1[0] = 4; row1[1] = 5; row1[2] = 6;
    row2[0] = 7; row2[1] = 8; row2[2] = 9;
    
    sort_2d_array(array, size);
    
    EXPECT_TRUE(isRowSorted(0));
    EXPECT_TRUE(isRowSorted(1));
    EXPECT_TRUE(isRowSorted(2));
}

TEST_F(SortArrayTest, SortArrayReversed) {
    int* row0 = (int*)array[0];
    int* row1 = (int*)array[1];
    int* row2 = (int*)array[2];
    
    row0[0] = 3; row0[1] = 2; row0[2] = 1;
    row1[0] = 6; row1[1] = 5; row1[2] = 4;
    row2[0] = 9; row2[1] = 8; row2[2] = 7;
    
    sort_2d_array(array, size);
    
    EXPECT_TRUE(isRowSorted(0));
    EXPECT_TRUE(isRowSorted(1));
    EXPECT_TRUE(isRowSorted(2));
}

TEST_F(SortArrayTest, SortArrayWithDuplicates) {
    int* row0 = (int*)array[0];
    row0[0] = 5; row0[1] = 5; row0[2] = 5;
    
    sort_2d_array(array, size);
    
    EXPECT_TRUE(isRowSorted(0));
}

TEST_F(SortArrayTest, SortArrayWithNegatives) {
    int* row0 = (int*)array[0];
    row0[0] = -5; row0[1] = 10; row0[2] = -3;
    
    sort_2d_array(array, size);
    
    EXPECT_TRUE(isRowSorted(0));
    EXPECT_LE(row0[0], row0[1]);
    EXPECT_LE(row0[1], row0[2]);
}
