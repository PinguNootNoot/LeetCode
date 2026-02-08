#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Apply Floyd's Cycle-Finding Algorithm
        ListNode *hare = head, *tortoise = head;
        while(hare && hare->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(hare == tortoise) {
                tortoise = head;
                while(tortoise != hare) {
                    tortoise = tortoise->next;
                    hare = hare->next;
                }
                return tortoise;
            }
        }
        return nullptr;
    }
};
