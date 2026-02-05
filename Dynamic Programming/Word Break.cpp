#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> memo(n+1, 0);  // Use dynamic programming
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        memo[0] = true;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(memo[j] && dict.count(s.substr(j, i-j))) {
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[n];
    }
};
