#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> gain(n+1);
        gain[1] = nums[0];

        for(int i = 2; i <= n; ++i) {
            gain[i] = max(gain[i-1], gain[i-2]+nums[i-1]);
        }
        return gain[n];
    }
};
