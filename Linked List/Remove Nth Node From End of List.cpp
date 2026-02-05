#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodeCount = 0;
        ListNode *temp = head;
        ListNode *curNode, *prevNode;

        while(temp) {
            ++nodeCount;
            temp = temp->next;
        } if(nodeCount == 1) {
            return nullptr;
        }
        nodeId = nodeCount - (n - 1);
        curNode = head; prevNode = nullptr;
        while(1) {
            if(nodeId <= 1) {
                if(curNode->next) {
                    if(prevNode){
                        prevNode->next = curNode->next;
                        curNode->next = nullptr;
                    }
                    else {
                        head = curNode->next;
                        curNode->next = nullptr;
                    }
                }
                else prevNode->next = nullptr;
                delete curNode;
                break;
            }
            --nodeId;
            prevNode = curNode;
            curNode = curNode->next;
        }
        return head;
    }

private:
    int nodeId;
};
