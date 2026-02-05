#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curNode1, *curNode2;

        if(list1 && !list2) return list1;
        if(!list1 && list2) return list2;
        if(!list1 && !list2) return nullptr;

        curNode1 = list1; curNode2 = list2;
        while(curNode1 || curNode2) {
            if(curNode1) {
                if(M.find(curNode1->val) != M.end()) {
                    ++M.find(curNode1->val)->second;
                } else {
                    M.insert(pair<int,int>(curNode1->val,1));
                }
                curNode1 = curNode1->next;
            } if(curNode2) {
                if(M.find(curNode2->val) != M.end()) {
                    ++M.find(curNode2->val)->second;
                } else {
                    M.insert(pair<int,int>(curNode2->val,1));
                }
                curNode2 = curNode2->next;
            }
        }

        ListNode *newHead, *temp;

        newHead = new ListNode(M.begin()->first); temp = newHead;
        --M.begin()->second;
        for(auto i = M.begin(); i != M.end(); ++i) {
            while(i->second > 0) {
                temp->next = new ListNode(i->first);
                --i->second;
                temp = temp->next;
            }
        }
        return newHead;
    }

private:
    map<int,int> M;
};
