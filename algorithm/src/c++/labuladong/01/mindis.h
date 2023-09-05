//
// Created by gcc on 8/29/23.
//

#ifndef BACKTRACK_MINDIS_H
#define BACKTRACK_MINDIS_H

#include <queue>

#include "../Tree.h"

using namespace std;

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    // root itself is the first level, so depth initialize as 1
    int depth = 1;

    while (!q.empty()) {
        int sz = q.size();
        /*将当前队列中的所有节点向四周扩散*/
        for (int i = 0; i < sz; i++) {
            TreeNode* cur = q.front();
            q.pop();
            /*判断是否到达终点*/
            if (cur->left == nullptr && cur->right == nullptr)
                return depth;
            /*将 cur 的相邻节点加入队列*/
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        /* 这里增加步数 */
        depth++;
    }
    return depth;
}



#endif //BACKTRACK_MINDIS_H
