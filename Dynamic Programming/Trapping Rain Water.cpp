#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(accumulate(height.begin(), height.end(), 0) == height.size()) return 0;

        for(int center = 1; center < height.size()-1; ++center) {
            for(int left = center-1, right = center+1;;) {
                if(height[left] > height[center] && height[right] > height[center]) {
                    int waterLevel = min(height[left], height[right]);
                    for(int i = left+1; i < right; ++i) {
                        totalRain += (waterLevel - height[i]);
                        height[i] += (waterLevel - height[i]);
                    }
                }
                if(height[left] < height[right]) --left;
                else if(height[left] > height[right]) ++right;
                else { --left; ++right; }

                if(left < 0 || right >= height.size()) break;
                if(height[left] < height[left+1] || height[right] < height[right-1]) break;
            }
        }
        return totalRain;
    }

private:
    int totalRain = 0;
};
