//
// Created by gcc on 8/7/23.
//
#include <vector>
#include <iostream>

class NumMatrix {
private:
    std::vector<std::vector<int>> preSum;
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        // 构造前缀和矩阵
        preSum = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <=n ; ++j) {
                preSum[i][j] = preSum[i][j - 1] + preSum[i - 1][j] + matrix[i - 1][j - 1] -preSum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{3, 0, 1, 4, 2},
                                            {5, 6, 3, 2, 1},
                                            {1, 2, 0, 1, 5},
                                            {4, 1, 0, 1, 7},
                                            {1, 0, 3, 0, 5}};


    NumMatrix* numMatrix = new NumMatrix(matrix);
    int sum = numMatrix->sumRegion(1, 1, 2, 2);
    std::cout << "子矩阵的和：" << sum << std::endl;

    return 0;
}