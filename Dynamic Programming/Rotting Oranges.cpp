#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2) Q.push(pair<pair<int,int>,int>(pair<int,int>(i, j), 0));
                else if(grid[i][j] == 1) ++fresh;
            }
        }
        if(!fresh) return 0;

        while(!Q.empty()) {
            auto q = Q.front();
            int x = q.first.first, y = q.first.second;
            int timemark = q.second;
            lapse = max(lapse, timemark);
            Q.pop();

            if(x > 0) {
                if(grid[x-1][y] == 1) {
                    Q.push(pair<pair<int,int>,int>(pair<int,int>(x-1, y), timemark+1));
                    grid[x-1][y] = 2;
                    --fresh;
                }
            } if(x < m - 1) {
                if(grid[x+1][y] == 1) {
                    Q.push(pair<pair<int,int>,int>(pair<int,int>(x+1, y), timemark+1));
                    grid[x+1][y] = 2;
                    --fresh;
                }
            } if(y > 0) {
                if(grid[x][y-1] == 1) {
                    Q.push(pair<pair<int,int>,int>(pair<int,int>(x, y-1), timemark+1));
                    grid[x][y-1] = 2;
                    --fresh;
                }
            } if(y < n - 1) {
                if(grid[x][y+1] == 1) {
                    Q.push(pair<pair<int,int>,int>(pair<int,int>(x, y+1), timemark+1));
                    grid[x][y+1] = 2;
                    --fresh;
                }
            }
        }
        return (fresh == 0) ? lapse : -1;
    }

private:
    int fresh = 0;
    int lapse;
    queue<pair<pair<int,int>,int>> Q;
};
