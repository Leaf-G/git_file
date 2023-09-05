//
// Created by gcc on 8/7/23.
//
#include <vector>
#include <iostream>
#include "output_container.h"

using namespace std;

string palindrome(string s, int l, int r) {
    // 防止索引越界
    while (l >= 0 && r < s.length()
           && s[l] == s[r]) {
        // 双指针，向两边展开
        l--; r++;
    }
    // 返回以 s[l] 和 s[r] 为中心的最长回文串
    return s.substr(l + 1, r - l - 1);
}

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

vector<string> longestPalindrome(string s) {
    vector<string> res;
    string tem = "";
    for (int i = 0; i < s.length(); i++) {
        // 以 s[i] 为中心的最长回文子串
        string s1 = palindrome(s, i, i);
        // 以 s[i] 和 s[i+1] 为中心的最长回文子串
        string s2 = palindrome(s, i, i + 1);
        // res = longest(res, s1, s2)
        if (s1 != ""){
            res.push_back(s1);
        }
        if (s2 != ""){
            res.push_back(s2);
        }
    }
    return res;
}

int main() {
    string test = "babad";
    vector<string> result;

    result = longestPalindrome(test);
    cout << "返回结果：" << result << endl;

    return 0;
}
