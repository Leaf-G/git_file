//
// Created by gcc on 8/21/23.
//
#include <assert.h>
#include <iostream>
#include <vector>
//#include "output_container.h"
using namespace std;

class Solution {
public:
    // 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        // 数组大小为 amount + 1，初始值也为 amount + 1
        dp[0] = 0;

        // 外层 for 循环在遍历所有状态的所有取值
        for (int i = 0; i < dp.size(); i++) {
            // 内层 for 循环在求所有选择的最小值
            for (int coin : coins) {
                // 子问题无解，跳过
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }

};

int main() {
    std::vector<int> matrix = {2};


    Solution s;
    int result = s.coinChange(matrix,3);

    cout << "子矩阵的和：" << result << endl;

    return 0;
}