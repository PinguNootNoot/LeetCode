#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        ListNode *cur = head;
        ListNode *prev = nullptr, *prec;
        while(cur) {
            prec = cur;
            cur = cur->next;
            prec->next = prev;
            prev = prec;
        }
        head = prec;
        return head;
    }
};
