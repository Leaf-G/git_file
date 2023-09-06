//
// Created by gcc on 8/29/23.
//
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。
#ifndef BACKTRACK_MAXDEPTH_H
#define BACKTRACK_MAXDEPTH_H


#include <algorithm>
#include <string>
#include "../Tree.h"

using namespace std;

class Solution_maxDepth {
public:

    // 记录最大深度
    int res = 0;
    int depth = 0;

    // 主函数
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }

    // 二叉树遍历框架
    void traverse(TreeNode* root) {
        if (root == NULL) {
            // 到达叶子节点
            res = max(res, depth);
            return;
        }
        // 前序遍历位置
        depth++;
        traverse(root->left);
        traverse(root->right);
        // 后序遍历位置
        depth--;
    }
};

#endif BACKTRACK_MAXDEPTH_H