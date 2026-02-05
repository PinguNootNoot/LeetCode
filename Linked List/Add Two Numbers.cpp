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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1, num2, sum, carry = 0;
        ListNode *temp = new ListNode();
        ListNode *headNode = temp;  // Store the head

        while(1) {
            num1 = (l1 == nullptr) ? 0 : l1->val;
            num2 = (l2 == nullptr) ? 0 : l2->val;

            sum = num1 + num2 + carry;
            carry = sum / 10;
            temp->val = sum % 10;
            temp->next = nullptr;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            if(l1 || l2 || carry) {
                temp->next = new ListNode();
                temp = temp->next;
            } else break;
        }
        return headNode;
    }
};
