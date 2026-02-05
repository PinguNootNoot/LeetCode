#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;

        while(head) {
            value.push_back(head->val);
            head = head->next;
        }
        sort(value.begin(), value.end());
        ListNode *node = new ListNode(value[0]);
        nodes.push_back(node);
        for(int i = 1; i < value.size(); ++i) {
            ListNode *node = new ListNode(value[i]);
            nodes.push_back(node);
            nodes[i-1]->next = nodes[i];
        }
        return nodes[0];
    }

private:
    vector<int> value;
    vector<ListNode*> nodes;
};
