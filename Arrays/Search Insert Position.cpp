#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0] > target) return 0;
        else if(nums[nums.size()-1] < target) return nums.size();

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target || nums[i] > target) return i;
        }
        return nums.size();
    }
};
