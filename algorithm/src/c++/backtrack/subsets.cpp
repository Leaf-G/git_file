//
// Created by gcc on 8/21/23.
//
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../labuladong/output_container.h"
using namespace std;


// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

class Solution {
private:
    vector<int> track;
    vector<vector<int>> res;
    vector<bool> used;
    int trackSum = 0;
public:
    void backtrack(vector<int>& nums, int target) {
        // base case, 达到目标和
        if (trackSum == target) {
            res.emplace_back(track);
            return;
        }
        //base case， 超过目标
        if (trackSum > target) {
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
//            if (used[i]) {
//                continue;
//            }

//            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) { // 剪枝逻辑，值相同的相邻树枝，只遍历第一条
//                continue;
//            }
            track.emplace_back(nums[i]);
            trackSum += nums[i];
//            used[i] = true;
            backtrack(nums, target);
            track.pop_back();
            trackSum -= nums[i];
//            used[i] = false;
        }

    }
    vector<vector<int>> adapt(vector<int>& candidates, int target) {
//        sort(candidates.begin(), candidates.end());
        //初始化used数组
//        used = vector<bool>(candidates.size(), false);
        backtrack(candidates,  target);
        return res;
    }

};




int main() {
    std::vector<int> matrix = {1,2,3};


    Solution s;
    vector<vector<int>> result = s.adapt(matrix,5);

    cout << "子矩阵的和：" << result << endl;
    cout << result.size() << endl;

    return 0;
}