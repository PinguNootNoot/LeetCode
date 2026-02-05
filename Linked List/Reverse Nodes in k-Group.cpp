#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode();
        ListNode *nextNode = head, *tail = head;
        ListNode *curNode = newHead;

        while(nextNode) {
            for(int i = 0; i < k; ++i) {
                if(!nextNode) {
                    while(tail) {
                        curNode->next = tail;
                        tail = tail->next;
                        curNode = curNode->next;
                    }
                    return newHead->next;
                }
                S.push(nextNode);
                nextNode = nextNode->next;
            }
            while(!S.empty()) {
                curNode->next = S.top();
                S.pop();
                curNode = curNode->next;
                curNode->next = nullptr;
            }
            tail = nextNode;
        }
        return newHead->next;
    }

private:
    stack<ListNode*> S;
};
