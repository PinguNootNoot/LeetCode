#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head) {
            if(Nodes.find(head) != Nodes.end()) return true;
            Nodes.insert(head);
            head = head->next;
        }
        return false;
    }

private:
    unordered_set<ListNode*> Nodes;
};
