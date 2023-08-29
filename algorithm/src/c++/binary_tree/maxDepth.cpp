//
// Created by gcc on 8/21/23.
//
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

#include <cmath>


using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// 记录最大深度
int res = 0;
// 记录遍历到的节点的深度
int depth = 0;

// 二叉树遍历框架
void traverse(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 前序位置
    depth++;
    if (root->left == NULL && root->right == NULL) {
        // 到达叶子节点，更新最大深度
        res = max(res, depth);
    }
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
    depth--;
}

// 主函数
int maxDepth(TreeNode* root) {
    traverse(root);
    return res;
}





int maxDepth_dp(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    // 利用定义，计算左右子树的最大深度
    int leftMax = maxDepth_dp(root->left);
    int rightMax = maxDepth_dp(root->right);
    // 整棵树的最大深度等于左右子树的最大深度取最大值，
    // 然后再加上根节点自己
    int res = max(leftMax, rightMax) + 1;

    return res;
}

int main () {

}