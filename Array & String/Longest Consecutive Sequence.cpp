#incclude <bit/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 1) return n;

        int temp;
        for(int i = 1; i < n; ++i) {
            if(S.find(nums[i]) != S.end()) continue;
            temp = nums[i-1];
            if(nums[i] == temp+1) ++cnt;
            else {
                if(longest < cnt) longest = cnt;
                cnt = 1;
            }
            S.insert(nums[i]);
        }
        longest = (longest < cnt) ? cnt : longest;
        return longest;
    }

private:
    int longest = 0;
    int cnt = 1;
    unordered_set<int> S;
};
