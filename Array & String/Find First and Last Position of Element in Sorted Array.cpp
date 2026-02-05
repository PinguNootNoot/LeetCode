#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        if(nums.size() == 1 && nums[0] == target) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target) {
                if(ans.empty() || i == nums.size()-1) ans.push_back(i);
            } if(nums[i] > target) {
                if(ans.size() < 2 && !ans.empty()) ans.push_back(i-1);
            }
        }
        if(ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else if(ans.size() == 1) {
            ans.push_back(ans[0]);
        }
        return ans;
    }
};
