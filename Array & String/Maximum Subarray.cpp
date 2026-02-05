#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        /** using sliding window technique */
        /* temp represents the sum of a subarray
            if temp < 0, it means that the subarray has a sum smaller than 0,
            and any other subarrray that includes this subarray will have a smaller sum.
            Thus, we reset temp to 0 here, indicating that we are going to find a new subarray the sum of which is greater than 0.
        */
        int maxSum = pow(10,5) * -1, temp = 0;
        for(int i = 0; i < nums.size(); ++i) {
            temp += nums[i];
            if(temp > maxSum) maxSum = temp;
            if(temp < 0) temp = 0;
        }
        return maxSum;
    }
};
