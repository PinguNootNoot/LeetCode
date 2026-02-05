#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        while(left < right) {
            localWater = min(height[left], height[right]) * (right - left);
            if(maxWater < localWater) maxWater = localWater;
            if(height[left] >= height[right]) { --right; }
            else { ++left; }
        }
        return maxWater;
    }

private:
    int maxWater = 0, localWater;
};
