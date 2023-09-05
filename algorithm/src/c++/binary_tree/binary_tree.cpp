//
// Created by gcc on 8/21/23.
//
#include <vector>

using namespace std;

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

//迭代遍历数组
void traverse(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {

    }
}

//递归遍历数组
void traverse(vector<int>& arr, int i) {
    if (i == arr.size()) {
        return;
    }
    //前序位置
    traverse(arr, i + 1);
    //后序位置
}

//迭代遍历单链表
void traverse(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p -> next) {

    }
}

//递归遍历单链表
void traverse(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    //前序位置
    traverse(head -> next);
    //后序位置
}
