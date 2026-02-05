#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sumMap(m, vector<int>(n,-1));
        sumMap[0][0] = grid[0][0];

        for(int i = 1; i < n; ++i) sumMap[0][i] = sumMap[0][i-1] + grid[0][i];
        for(int i = 1; i < m; ++i) sumMap[i][0] = sumMap[i-1][0] + grid[i][0];
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(sumMap[i][j] == -1 || sumMap[i][j] > sumMap[i-1][j] + grid[i][j] || sumMap[i][j] > sumMap[i][j-1] + grid[i][j]) sumMap[i][j] = min(sumMap[i-1][j], sumMap[i][j-1]) + grid[i][j];
            }
        }
        return sumMap[m-1][n-1];
    }
};
