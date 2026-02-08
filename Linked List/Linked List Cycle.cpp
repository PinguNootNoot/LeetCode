#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *hare = head, *tortoise = head;

        while(hare && hare->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(tortoise == hare) return true;
        }
        return false;
    }
};
