#include <bits/stdc++.h>
using namespace std;

/** Applying Knapsack */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int arrSum = accumulate(nums.begin(), nums.end(), 0);
        if(arrSum % 2 != 0) return false;

        int n = nums.size();
        arrSum /= 2;
        vector<bool>sackRow(arrSum+1, false);
        sackRow[0] = true;

        for(int i = 0; i < n; ++i) {
            for(int j = arrSum; j - nums[i] >= 0; --j) {
                sackRow[j] = sackRow[j-nums[i]] | sackRow[j];
            }
        }
        return sackRow[arrSum];
    }
};
