#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int target = 1;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                if(S.find(nums[i]) == S.end()) S.insert(nums[i]);
            }
        }
        while(S.find(target) != S.end()) ++target;
        return target;
    }

private:
    unordered_set<int> S;
};
