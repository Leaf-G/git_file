//
// Created by gcc on 8/29/23.
//
#ifndef BACKTRACK_TREE1_H
#define BACKTRACK_TREE1_H



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* buildTree() {
    // Level 1
    TreeNode* root = new TreeNode(1);

    // Level 2
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Level 3
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);

    // Level 4
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    return root;
}


#endif //BACKTRACK_TREE1_H