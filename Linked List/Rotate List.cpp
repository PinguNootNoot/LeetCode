#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;

        int len = 0;
        vector<ListNode*> nodes;

        while(head) {
            ++len;
            nodes.push_back(head);
            head = head->next;
        }
        if(k % len == 0 || len == 1) return nodes[0];
        k %= len;
        nodes[len-k-1]->next = nullptr;
        nodes[len-1]->next = nodes[0];
        return nodes[len-k];
    }
};
