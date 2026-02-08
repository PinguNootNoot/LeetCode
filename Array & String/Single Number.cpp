#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ans = nums[0];

        // Don't forget the power of XOR operator
        for(int i = 1; i < nums.size(); ++i) ans ^= nums[i];
        return ans;
    }
};
