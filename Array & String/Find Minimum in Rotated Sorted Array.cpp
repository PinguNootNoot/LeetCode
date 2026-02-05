#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans;

        if(nums[0] <= nums[n-1]) return nums[0];
        for(int i = 1, j = n-2; i < n, j >= 0; ++i, --j) {
            if(nums[i] - nums[i-1] < 0) {
                ans = nums[i];
                break;
            } else if(nums[j] - nums[j-1] < 0) {
                ans = nums[j];
                break;
            }
        }
        return ans;
    }
};
