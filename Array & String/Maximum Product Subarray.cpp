#include <bits/stdc++.h>
using namespace std;

/**
*   Technique: The maximum product either originates from (1 the array, or (2 one of the two subarrays(partitioned by a negative number)
*   In case 2, it doesn't matter how many negative integers the input array has
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int temp = 1;

        for(int i = 0; i < nums.size(); ++i) {
            if(temp == 0) temp = nums[i];
            else temp *= nums[i];
            promax = max(promax, temp);
        }
        temp = 1;
        for(int i = nums.size()-1; i >= 0; --i) {
            if(temp == 0) temp = nums[i];
            else temp *= nums[i];
            promax = max(promax, temp);
        }
        return promax;
    }

private:
    int promax = INT_MIN;
};
