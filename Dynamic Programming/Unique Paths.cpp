#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pathMap(m, vector<int>(n,0));

        for(int i = 0; i < m; ++i) pathMap[i][0] = 1;
        for(int i = 1; i < n; ++i) pathMap[0][i] = 1;
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) pathMap[i][j] = pathMap[i-1][j] + pathMap[i][j-1];
        }

        return pathMap[m-1][n-1];
    }
};
