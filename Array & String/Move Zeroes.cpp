#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;

        int cnt = 0;
        for(auto it = nums.begin(); it != nums.end();) {
            if(*it == 0) {
                nums.erase(it);
                ++cnt;
            } else ++it;
        }
        for(; cnt > 0; --cnt) nums.push_back(0);
    }
};
