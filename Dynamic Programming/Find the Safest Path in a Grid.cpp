#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pathSweep(int counter) {
        if(counter <= safe_fact || counter > dist[0][0]) return;

        int n = dist.size();
        queue<pair<int,int>> dest;
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        dest.push({0,0});
        visited[0][0] = true;
        while(!dest.empty()) {
            auto next = dest.front();
            int x = next.first, y = next.second;
            if(x == n - 1 && y == n - 1) {
                safe_fact = counter;
                break;
            }
            for(int i = 0; i < 4; ++i) {
                auto pos = dir[i];
                int move_x = x + pos.first, move_y = y + pos.second;
                if(move_x >= 0 && move_x < n && move_y >= 0 && move_y < n) {
                    if(dist[move_x][move_y] >= counter && !visited[move_x][move_y]) {
                        dest.push({move_x,move_y});
                        visited[move_x][move_y] = true;
                    }
                }
            }
            dest.pop();
        }
    }

    void thiefDist(int x, int y) {
        int n = dist.size();
        queue<pair<int,int>> Q;
        Q.push({x,y});

        while(!Q.empty()) {
            auto pos = Q.front();
            int x = pos.first, y = pos.second;

            for(int i = 0; i < 4; ++i) {
                int move_x = x + dir[i].first, move_y = y + dir[i].second;
                if(move_x >= 0 && move_x < n && move_y >= 0 && move_y < n) {
                    if(dist[x][y] + 1 < dist[move_x][move_y]) {
                        Q.push({move_x,move_y});
                        dist[move_x][move_y] = dist[x][y] + 1;
                    }
                }
            }
            Q.pop();
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;

        dist.assign(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    dist[i][j] = 0;
                    thiefDist(i,j);
                }
            }
        }

        int mini = 0, maxi = dist[0][0];
        while(mini <= maxi) {
            int mid = (mini + maxi) / 2;
            pathSweep(mid);
            if(safe_fact >= mid) mini = mid + 1;
            else maxi = mid - 1;
        }
        return safe_fact;
    }

private:
    int safe_fact = 0;
    vector<vector<int>> dist;
    vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
};
