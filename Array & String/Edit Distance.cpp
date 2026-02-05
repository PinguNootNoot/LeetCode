#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Dynamic programming (similar to climbing stairs)
        int m = word1.size(), n = word2.size();
        if(m == 0) return n;
        else if(n == 0) return m;

        vector<vector<int>> Ans(m, vector<int>(n,0));
        bool repeated = false;

        if(word1[0] != word2[0]) Ans[0][0] = 1;
        for(int i = 1; i < n; ++i){
            Ans[0][i] = (word1[0] == word2[i] && !repeated) ? Ans[0][i-1] : Ans[0][i-1]+1;
            repeated = (word1[0] == word2[i]) ? true : repeated;
        }
        repeated = false;
        for(int i = 1; i < m; ++i) {
            Ans[i][0] = (word1[i] == word2[0] && !repeated) ? Ans[i-1][0] : Ans[i-1][0]+1;
            repeated = (word1[i] == word2[0]) ? true : repeated;
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(word1[i] == word2[j]) Ans[i][j] = Ans[i-1][j-1];
                else {
                    /**
                    * Ans[i-1][j-1] + 1: Replace
                    * Ans[i-1][j] + 1: Delete
                    * Ans[i][j-1] + 1: Insert
                    */
                    int minDis = min(Ans[i-1][j-1], Ans[i-1][j]);
                    minDis = min(minDis, Ans[i][j-1]) + 1;
                    Ans[i][j] = minDis;
                }
            }
        }
        return Ans[m-1][n-1];
    }
};
