//
// Created by gcc on 5/18/23.
//
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int size_nums = nums.size();
        vector<int> result;
        for (int i = k; i < size_nums - k; ++i) {
            int j;
            for (j = i - k; j < i - 1; ++j) {
                if (nums[j] < nums[j + 1])
                    break;
            }
            if (j != i - 1)
                continue;
            for (j = i + 1; j < i + k; ++j) {
                if (nums[j] > nums[j + 1])
                    break;
            }
            if (j == i + k)
                result.push_back(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {253747,459932,263592,354832,60715,408350,959296};
    vector<int> result = s.goodIndices(nums, 2);
}