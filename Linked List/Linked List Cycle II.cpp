#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while(head) {
            if(List.find(head) != List.end()) return head;
            List.insert(head);
            head = head->next;
        }
        return nullptr;
    }

private:
    unordered_set<ListNode*> List;
};
