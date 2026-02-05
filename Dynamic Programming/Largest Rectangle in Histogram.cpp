#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /** Does not know why or how it works */

    int largestRectangleArea(vector<int>& heights) {
        int s = heights.size();
        vector<int> nsl(s,0), nsr(s,0);

        for(int i = s-1; i >= 0; --i) {
            while(!S.empty() && heights[S.top()] >= heights[i]) S.pop();
            if(S.empty()) nsr[i] = s;
            else nsr[i] = S.top();
            S.push(i);
        }
        while(!S.empty()) S.pop();
        for(int i = 0; i < s; ++i) {
            while(!S.empty() && heights[S.top()] >= heights[i]) S.pop();
            if(S.empty()) nsl[i] = -1;
            else nsl[i] = S.top();
            S.push(i);
        }
        for(int i = 0; i < s; ++i) {
            int temp = heights[i] * (nsr[i] - nsl[i] - 1);
            if(maxArea < temp) maxArea = temp;
        }
        return maxArea;
    }

private:
    int maxArea = 0;
    stack<int> S;
};
