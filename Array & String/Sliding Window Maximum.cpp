#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            if(DQ.front() == i-k) DQ.pop_front();
            while(!DQ.empty() && nums[DQ.back()] < nums[i]) DQ.pop_back();
            DQ.push_back(i);
            if(i >= k-1) window_max.push_back(nums[DQ.front()]);
        }
        return window_max;
    }

private:
    deque<int> DQ;
    vector<int> window_max;
};
