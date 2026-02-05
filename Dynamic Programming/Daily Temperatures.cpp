#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);

        for(int i = n - 2; i >= 0; --i) {
            if(temperatures[i] < temperatures[i+1]) {
                ans[i] = 1;
                S.push(pair<int,int>(temperatures[i+1], i+1));
            } else {
                while(!S.empty() && temperatures[i] >= S.top().first) S.pop();
                if(!S.empty()) ans[i] = S.top().second - i;
            }
        }
        return ans;
    }

private:
    stack<pair<int,int>> S;
};
