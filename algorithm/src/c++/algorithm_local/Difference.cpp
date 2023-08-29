//
// Created by gcc on 8/7/23.
//

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

// 差分数组工具类
#include <assert.h>
#include <iostream>
#include <vector>
#include "output_container.h"

class Difference {
    // 差分数组
private:
    std::vector<int> diff;

    /* 输入一个初始数组，区间操作将在这个数组上进行 */
public:
    Difference(std::vector<int>& nums, int length) {
        assert(length > 0);
        diff = std::vector<int> (length);
//        diff.resize(length);
        diff[0] = nums[0];
        for (int i = 1; i < length; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i, j] 增加 val（可以是负数）*/
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    /* 返回结果数组 */
    std::vector<int> result() {
        std::vector<int> res;
        res = std::vector<int> (diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

int main() {
    std::vector<int> matrix = {3, 0, 1, 4, 2};


    Difference* numMatrix = new Difference(matrix, 5);
    numMatrix->increment(1, 3, 2);
    std::cout << "子矩阵的和：" << numMatrix->result() << std::endl;

    return 0;
}