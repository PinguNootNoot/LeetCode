#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pair<int,int>> land;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]-'0' == 1 && !visited[i][j]) {
                    land.push(pair<int,int>(i,j));
                    ++island;
                }
                while(!land.empty()) {
                    auto g = land.front();
                    int x = g.first, y = g.second;
                    land.pop();

                    if(visited[x][y]) continue;
                    if(x >= 1) {
                        if(grid[x-1][y]-'0' == 1 && !visited[x-1][y]) land.push(pair<int,int>(x-1,y));
                    } if(y >= 1) {
                        if(grid[x][y-1]-'0' == 1 && !visited[x][y-1]) land.push(pair<int,int>(x,y-1));
                    } if(x < m-1) {
                        if(grid[x+1][y]-'0' == 1 && !visited[x+1][y]) land.push(pair<int,int>(x+1,y));
                    } if(y < n-1) {
                        if(grid[x][y+1]-'0' == 1 && !visited[x][y+1]) land.push(pair<int,int>(x,y+1));
                    }
                    visited[x][y] = true;
                }
            }
        }
        return island;
    }
};
