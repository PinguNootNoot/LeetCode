#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *curNode;

        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] == nullptr) continue;

            curNode = lists[i];
            while(curNode) {
                if(M.find(curNode->val) == M.end()) {
                    M.insert(pair<int,int>(curNode->val,1));
                } else {
                    ++M.find(curNode->val)->second;
                }
                curNode = curNode->next;
            }
        }
        if(M.empty()) return nullptr;

        ListNode *head, *temp;
        head = new ListNode(M.begin()->first); temp = head;
        --M.begin()->second;
        for(auto i = M.begin(); i != M.end(); ++i) {
            while(i->second > 0) {
                temp->next = new ListNode(i->first);
                --i->second;
                temp = temp->next;
            }
        }
        return head;
    }

private:
    map<int,int> M;
};
