//
// Created by gcc on 9/1/23.
//

#ifndef GIT_FILE_MINDISTANCE_H
#define GIT_FILE_MINDISTANCE_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//编辑距离
int minDistance(string word1, string word2){
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i < word1.size() + 1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j < word2.size() + 1; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i < word1.size() + 1; ++i) {
        for (int j = 1; j < word2.size() + 1; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }
    return dp[word1.size()][word2.size()];
}

#endif //GIT_FILE_MINDISTANCE_H