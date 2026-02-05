#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> ans(n1+1, vector<int>(n2+1));

        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j <= n2; ++j) {
                if(text1[i-1] == text2[j-1]) ans[i][j] = ans[i-1][j-1] + 1;
                else ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
        return ans[n1][n2];
    }
};
