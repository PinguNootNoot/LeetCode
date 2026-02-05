#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;
        while(headA) {
            nodes.insert(headA);
            headA = headA->next;
        }
        while(headB) {
            if(nodes.find(headB) != nodes.end()) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
