#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        Ans.push_back(nums);
        if(nums.size() == 1) return Ans;

        while(next_permutation(nums.begin(), nums.end())) Ans.push_back(nums);

        return Ans;
    }

private:
    vector<vector<int>> Ans;
};
