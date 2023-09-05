//
// Created by gcc on 8/7/23.
//
#include <vector>
#include <iostream>
#include "output_container.h"

using namespace std;

void reverseString(vector<char>& s) {
    // 一左一右两个指针相向而行
    int left = 0, right = s.size() - 1;
    while (left < right) {
        // 交换 s[left] 和 s[right]
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    vector<char> test = {'a','b','c'};


    reverseString(test);
    cout << "返回结果：" << test << endl;

    return 0;
}
