#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        vector<ListNode*> rev;
        rev.push_back(head);
        head = head->next;
        rev[0]->next = nullptr;

        while(head) {
            int n = rev.size();
            rev.push_back(head);
            head = head->next;
            rev[n]->next = rev[n-1];
        }
        return rev[rev.size()-1];
    }
};
