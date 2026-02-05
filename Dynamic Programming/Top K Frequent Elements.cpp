#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return nums;
        int cnt = 1;

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i) {
            if(nums[i] == nums[i-1]) ++cnt;
            else {
                Counts[cnt].push(nums[i-1]);
                PQ.push(cnt);
                cnt = 1;
            }
        }
        Counts[cnt].push(nums[n-1]);
        PQ.push(cnt);
        for(int i = 0; i < k; ++i) {
            int t = PQ.top();
            ans.push_back(Counts[t].front());
            Counts[t].pop();
            PQ.pop();
        }
        return ans;
    }

private:
    map<int,queue<int>> Counts;
    priority_queue<int> PQ;
    vector<int> ans;
};
