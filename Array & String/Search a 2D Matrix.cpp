#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int targetRow = -1;

        for(int i = 0; i < m; ++i) {
            if(target == matrix[i][n-1]) return true;
            else if(target < matrix[i][n-1]) {
                targetRow = i;
                break;
            }
        }
        if(targetRow == -1) return false;

        int left = 0, right = n-1;
        while(1) {
            if(left == right-1 || left == right) {
                if(matrix[targetRow][left] == target || matrix[targetRow][right] == target) return true;
                else break;
            }
            int mid = (left + right) / 2;
            if(matrix[targetRow][mid] == target) return true;
            else if(matrix[targetRow][mid] > target) right = mid;
            else left = mid;
        }
        return false;
    }
};
