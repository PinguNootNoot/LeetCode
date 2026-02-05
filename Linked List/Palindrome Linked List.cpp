#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
        return isPalin(arr);
    }

private:
    bool isPalin(vector<int>& vec) {
        int n = vec.size(), mid = n / 2;
        int left = mid - 1;
        int right = (n % 2 == 0) ? mid : mid + 1;

        for(; left >= 0, right < n; --left, ++right) {
            if(vec[left] != vec[right]) return false;
        }
        return true;
    }

    vector<int> arr;
};
