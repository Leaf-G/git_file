//
// Created by gcc on 8/31/23.
//

#ifndef BACKTRACK_LENGTHOFLIS_H
#define BACKTRACK_LENGTHOFLIS_H

//#include <vector>

//using namespace std;
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

int lengthOfLIS(vector<int> &nums) {
    // 定义：dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度
    vector<int> dp(nums.size(), 1);
    // base case：dp 数组全都初始化为 1
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res = 0;
    for (int i = 0; i < dp.size(); i++) {
        res = max(res, dp[i]);
    }
    return res;
}

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

// 最长递增子序列
int lengthOfLIS_binary(vector<int> &nums) {
    int piles = 0;    // 牌堆数初始化为 0
    vector<int> top(nums.size());   // 牌堆数组 top

    for (int i = 0; i < nums.size(); i++) {
        int poker = nums[i];    // 要处理的扑克牌

        /***** 搜索左侧边界的二分查找 *****/
        int left = 0, right = piles;    // 搜索区间为 [left, right)
        while (left < right) {
            int mid = (left + right) / 2;    // 防溢出
            if (top[mid] > poker) {
                right = mid;
            } else if (top[mid] < poker) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        /*********************************/

        // 没找到合适的牌堆，新建一堆
        if (left == piles) piles++;
        // 把这张牌放到牌堆顶
        top[left] = poker;
    }
    // 牌堆数就是 LIS 长度
    return piles;
}


// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

int maxEnvelopes(vector<vector<int>> &envelopes) {
    int n = envelopes.size();
    // 按宽度升序排列，如果宽度一样，则按高度降序排列
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &a, vector<int> &b) {
             return a[0] == b[0] ?
                    b[1] < a[1] : a[0] < b[0];
         });

    // 对高度数组寻找 LIS
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        height[i] = envelopes[i][1];
    return lengthOfLIS_binary(height);
}

int longestCommonSubsequence(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1,vector<int>(s2.size() + 1, 0));

    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i -1] == s2[j -1])
                dp[i][j] = dp[i -1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i -1][j]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}


#endif //BACKTRACK_LENGTHOFLIS_H
