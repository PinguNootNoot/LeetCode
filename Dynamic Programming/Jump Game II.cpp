#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> S(nums.size(), -1);

        if(nums.size() == 1) return 0;
        if(nums[0] >= nums.size()-1) return 1;

        S[0] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 1; j <= nums[i]; ++j) {
                if(i+j >= nums.size()) break;
                if(S[i+j] == -1 || S[i+j] > S[i]+1) S[i+j] = S[i] + 1;
            }
        }
        return S[S.size()-1];
    }
};
