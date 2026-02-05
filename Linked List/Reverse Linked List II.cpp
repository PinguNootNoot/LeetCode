#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        if(left == 1) return reverseList(head,1,right);
        else {
            ListNode *before_rev, *tmp = head;
            int i;
            for(i = 1; i < left - 1; ++i) tmp = tmp->next;
            before_rev = tmp;
            before_rev->next = reverseList(tmp->next,i+1,right);
            return head;
        }
    }

private:
    ListNode* reverseList(ListNode *head, int count, int stop) {
        ListNode *prev = nullptr, *cur = head, *next = head;
        ListNode *newtail = head;

        while(count++ <= stop) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        newtail->next = cur;
        return prev;
    }
};
