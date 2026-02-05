#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

        int x = 0, y = 0;
        bool dive = false;
        while(1) {
            if(x < 0 || y < 0 || x >= m || y >= n) break;
            if(target > matrix[x][n-1]) {
                ++x;
                continue;
            }

            int num = matrix[x][y];
            if(target == num) return true;
            if(target > num) {
                if(dive) ++x;
                else ++y;
            } else {
                if(!dive) {
                    dive = true;
                    ++x; --y;
                } else --y;
            }
        }
        return false;
    }
};
