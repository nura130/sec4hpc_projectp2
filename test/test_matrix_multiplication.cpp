#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test case for square matrices
TEST(MatrixMultiplicationTest, TestSquareMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<int>> B = {
        {5, 6},
        {7, 8}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {19, 22},
        {43, 50}
    };

    ASSERT_EQ(C, expected) << "Square matrix multiplication test failed!";
}

// Test case for zero matrices
TEST(MatrixMultiplicationTest, TestZeroMatrices) {
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> B = {
        {0, 0},
        {0, 0},
        {0, 0}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}
    };

    ASSERT_EQ(C, expected) << "Zero matrix multiplication test failed!";
}

// Test case for single element matrices
TEST(MatrixMultiplicationTest, TestSingleElementMatrix) {
    std::vector<std::vector<int>> A = {
        {2}
    };
    std::vector<std::vector<int>> B = {
        {3}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
        {6}
    };

    ASSERT_EQ(C, expected) << "Single element matrix multiplication test failed!";
}

// Test case for rectangular matrices A (2x3) * B (3x4)
TEST(MatrixMultiplicationTest, TestRectangularMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8, 9, 10},
        {11, 12, 13, 14},
        {15, 16, 17, 18}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(4, 0));

    multiplyMatrices(A, B, C, 2, 3, 4);

    std::vector<std::vector<int>> expected = {
        {74, 80, 86, 92},
        {173, 188, 203, 218}
    };

    ASSERT_EQ(C, expected) << "Rectangular matrix multiplication test failed!";
}

// Test case with negative numbers
TEST(MatrixMultiplicationTest, TestNegativeNumbers) {
    std::vector<std::vector<int>> A = {
        {1, -2},
        {-3, 4}
    };
    std::vector<std::vector<int>> B = {
        {-5, 6},
        {7, -8}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {19, -20},
        {-43, 44}
    };

    ASSERT_EQ(C, expected) << "Negative number matrix multiplication test failed!";
}

// Test case with a larger matrix
TEST(MatrixMultiplicationTest, TestLargerMatrix) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<std::vector<int>> B = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };
    std::vector<std::vector<int>> C(4, std::vector<int>(4, 0));

    multiplyMatrices(A, B, C, 4, 4, 4);

    std::vector<std::vector<int>> expected = {
        {250, 260, 270, 280},
        {618, 644, 670, 696},
        {986, 1028, 1070, 1112},
        {1354, 1412, 1470, 1528}
    };

    ASSERT_EQ(C, expected) << "Larger matrix multiplication test failed!";
}

// Test case for non-square result matrix
TEST(MatrixMultiplicationTest, TestNonSquareResultMatrix) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8, 9},
        {10, 11, 12}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 2, 3);

    std::vector<std::vector<int>> expected = {
        {27, 30, 33},
        {61, 68, 75},
        {95, 106, 117}
    };

    ASSERT_EQ(C, expected) << "Non-square result matrix multiplication test failed!";
}

// Test case for different dimensions
TEST(MatrixMultiplicationTest, TestDifferentDimensions) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    std::vector<std::vector<int>> B = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 4, 2);

    std::vector<std::vector<int>> expected = {
        {50, 60},
        {114, 140}
    };

    ASSERT_EQ(C, expected) << "Different dimensions matrix multiplication test failed!";
}

// Test case for larger single dimension (1xN) * (Nx1)
TEST(MatrixMultiplicationTest, TestSingleDimensionLarge) {
    std::vector<std::vector<int>> A = {{1, 2, 3, 4, 5}};
    std::vector<std::vector<int>> B = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 5, 1);

    std::vector<std::vector<int>> expected = {
        {55}
    };

    ASSERT_EQ(C, expected) << "Single dimension large matrix multiplication test failed!";
}

// Test case for sparse matrices
TEST(MatrixMultiplicationTest, TestSparseMatrices) {
    std::vector<std::vector<int>> A = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    ASSERT_EQ(C, expected) << "Sparse matrix multiplication test failed!";
}

// Test case for symmetric matrices
TEST(MatrixMultiplicationTest, TestSymmetricMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8, 9},
        {8, 10, 11},
        {9, 11, 12}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {50, 61, 67},
        {92, 112, 123},
        {125, 152, 167}
    };

    ASSERT_EQ(C, expected) << "Symmetric matrix multiplication test failed!";
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
