#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> Count;

        for(int i = 0; i < nums.size(); ++i) {
            if(Count.find(nums[i]) == Count.end()) Count.insert(pair<int,int>(nums[i],1));
            else ++Count.find(nums[i])->second;
        }
        int i = 0;
        for(int color = 0; color < 3; ++color) {
            int n = Count.find(color)->second;
            while(n > 0) {
                nums[i] = color;
                --n; ++i;
            }
        }
    }
};
