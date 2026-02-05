#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int counter = 0, powSize = pow(2,n);
        vector<int> binary(n,0);

        while(counter < powSize) {
            for(int i = 0; i < n; ++i) {
                if(binary[i] == 1) subset.push_back(nums[i]);
            }
            Ans.push_back(subset);
            subset.clear();
            ++counter;
            for(int i = n-1; i >= 0; --i) {
                if(binary[i] == 0) {
                    binary[i] = 1;
                    break;
                } else binary[i] = 0;
            }
        }
        return Ans;
    }

private:
    vector<vector<int>> Ans;
    vector<int> subset;
};
