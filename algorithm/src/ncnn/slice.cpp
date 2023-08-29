//
// Created by gcc on 6/7/23.
//
#include <iostream>
#include <vector>

// 切片函数
template<typename T>
std::vector<std::vector<T>> sliceMatrix(const std::vector<std::vector<T>>& matrix, int iniY, int maxY, int iniX, int maxX) {
    std::vector<std::vector<T>> slicedMatrix;

    for (int i = iniY; i < maxY; ++i) {
        std::vector<T> rowSlice(matrix[i].begin() + iniX, matrix[i].begin() + maxX);
        slicedMatrix.push_back(rowSlice);
    }

    return slicedMatrix;
}

int main() {
    std::vector<std::vector<int>> mProb = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };
    int iniY = 1, maxY = 4;
    int iniX = 2, maxX = 4;

    // 切片操作
    std::vector<std::vector<int>> prob = sliceMatrix(mProb, iniY, maxY, iniX, maxX);

    // 打印切片结果
    for (const auto& row : prob) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
