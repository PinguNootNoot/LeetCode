#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1) return nums[0];

        int sum = 0, expected = 0;
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0) expected += nums[i] * 2;
            sum += nums[i];
        }
        return (expected - sum);
    }
};
