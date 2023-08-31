//
// Created by gcc on 8/29/23.
//
#include "01/maxDepth.h"
#include "01/mindis.h"
#include "01/binarySearch.h"
#include "02-dp/lengthOfLIS.h"
#include <iostream>

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<vector<int>> tar = {{5,4},{6,4},{6,7},{2,3}};
    std::vector<vector<int>> tar1 = {{1,1},{1,1},{1,1},{1,1}};
    string s1 = {"babcde"}, s2 = {"ace"};
    TreeNode* root = buildTree();

//    Solution s;
//    int result = maxEnvelopes(tar);
    int result = longestCommonSubsequence(s1, s2);

    cout << " " << result << endl;
//    cout << result.size() << endl;

    return 0;
}