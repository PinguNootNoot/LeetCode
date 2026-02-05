#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxcnt = 0, cnt = 1;
        int maxnum = nums[0];
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i) {
            if(nums[i] == nums[i-1]) ++cnt;
            else {
                if(maxcnt < cnt) {
                    maxcnt = cnt;
                    maxnum = nums[i-1];
                }
                cnt = 1;
            }
            if(cnt > n/2) return nums[i];
        }
        return maxnum;
    }
};
