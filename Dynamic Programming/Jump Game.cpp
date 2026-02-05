#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        vector<int> Steps(nums.size(),-1);
        Steps[0] = 0;

        for(int i = 0; i < nums.size()-1; ++i) {
            for(int j = 1; j <= nums[i]; ++j) {
                if(Steps[i] != -1) {
                    if(nums[i] >= (nums.size()-i-1)) return true;
                    if((Steps[i+j] == -1 || Steps[i+j] > Steps[i] + 1)) Steps[i+j] = Steps[i] + 1;
                }
            }
        }
        if(Steps[nums.size()-1] > 0) return true;
        else return false;
    }
};
