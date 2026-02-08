#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int small = 101, big = 0;
        vector<int> missing;

        for(int i = 0; i < nums.size(); ++i) {
            if(big < nums[i]) big = nums[i];
            if(small > nums[i]) small = nums[i];
        }

        if(nums.size() == 2) {
            for(int i = small + 1; i < big; ++i) missing.push_back(i);
            return missing;
        }

        vector<int> check(big-small-1,1);
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == small || nums[i] == big) continue;
            --check[nums[i]-small-1];
        }
        for(int i = 0; i < check.size(); ++i) {
            if(check[i]) missing.push_back(i+small+1);
        }
        return missing;
    }
};
