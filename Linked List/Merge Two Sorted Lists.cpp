#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *l1 = list1, *l2 = list2;
        ListNode *head, *tail;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                head = l1;
                while(l1) {
                    if(l1->val > l2->val) break;
                    tail = l1;
                    l1 = l1->next;
                }
                tail->next = l2;
            } else {
                head = l2;
                while(l2) {
                    if(l1->val <= l2->val) break;
                    tail = l2;
                    l2 = l2->next;
                }
                tail->next = l1;
            }
        }
        return (list1->val <= list2->val) ? list1 : list2;
    }
};
