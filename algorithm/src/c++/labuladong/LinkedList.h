//
// Created by gcc on 8/29/23.
//

#ifndef BACKTRACK_LINKEDLIST_H
#define BACKTRACK_LINKEDLIST_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //BACKTRACK_LINKEDLIST_H
