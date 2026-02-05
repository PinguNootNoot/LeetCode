#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i) {
            M.insert(pair<int,int>(nums[i], i));
        }
        if(M.find(target) != M.end()) return M.find(target)->second;
        else return -1;
    }

private:
    map<int,int> M;
};
