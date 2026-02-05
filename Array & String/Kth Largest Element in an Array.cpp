#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        int n = nums.size();
        int mini = INT_MIN;

        for(int i = 0; i < n; ++i) {
            if(mini < nums[i]) mini = nums[i];
            auto m = M.find(nums[i]);
            if(m == M.end()) M.insert(pair<int,int>(nums[i],1));
            else ++m->second;
        }
        int sum = 0;
        for(int i = mini; ; --i) {
            if(M.find(i) == M.end()) continue;
            sum += M.find(i)->second;
            if(k <= sum) return i;
        }
        return 0;
    }
};
