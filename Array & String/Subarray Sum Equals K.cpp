#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> sum(n);
        sum[0] = nums[0];

        for(int i = 1; i < n; ++i) sum[i] = sum[i-1] + nums[i];
        for(int i = 0; i < n; ++i) {
            if(sum[i] == k) ++ans;
            if(subSum.find(sum[i]-k) != subSum.end()) ans += subSum[sum[i]-k];  /** Try to find whether a sub-array(sum[i] - sum[j]) = k exists */
            ++subSum[sum[i]];
        }
        return ans;
    }

private:
    unordered_map<int,int> subSum;
};
