//
// Created by gcc on 8/29/23.
//
#include "01/maxDepth.h"
#include "01/mindis.h"
#include <iostream>

int main() {
//    std::vector<int> matrix = {1,2,3};
    TreeNode* root = buildTree();

//    Solution s;
    int result = minDepth(root);

    cout << " " << result << endl;
//    cout << result.size() << endl;

    return 0;
}