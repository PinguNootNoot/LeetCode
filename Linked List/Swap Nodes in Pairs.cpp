#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *curNode, *nextNode, *prevNode, *newHead;

        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        curNode = head; nextNode = curNode->next; prevNode = nullptr;
        if(prevNode) prevNode->next = nextNode;
        if(nextNode->next) curNode->next = nextNode->next;
        else curNode->next = nullptr;
        nextNode->next = curNode;

        newHead = nextNode;
        if(curNode->next == nullptr || curNode->next->next == nullptr) return newHead;

        prevNode = curNode;
        nextNode = curNode->next->next;
        curNode = curNode->next;

        while(curNode) {
            if(prevNode) prevNode->next = nextNode;
            if(nextNode->next) curNode->next = nextNode->next;
            else curNode->next = nullptr;
            nextNode->next = curNode;

            if(curNode->next == nullptr || curNode->next->next == nullptr) break;

            prevNode = curNode;
            nextNode = curNode->next->next;
            curNode = curNode->next;
        }
        return newHead;
    }
};
