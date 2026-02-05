#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombination(vector<int>& candidates, int start, int sum, int target, vector<int>& comb) {
        if(start >= candidates.size()) return;

        vector<int> nextComb = comb;
        int quo = sum + candidates[start];

        if(quo == target) {
            nextComb.push_back(candidates[start]);
            ans.push_back(nextComb);
            nextComb.pop_back();
        } else {
            if(quo < target) {
                nextComb.push_back(candidates[start]);
                findCombination(candidates, start, quo, target, nextComb);
                nextComb.pop_back();
            }
        }
        findCombination(candidates, start+1, quo-candidates[start], target, nextComb);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;

        findCombination(candidates, 0, 0, target, comb);
        return ans;
    }

private:
    vector<vector<int>> ans;
};
