#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> zeroes;

        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) zeroes.insert(pair<int,int>(i,j));
            }
        }
        for(auto it = zeroes.begin(); it != zeroes.end(); ++it) {
            int m = (*it).first, n = (*it).second;
            fill(matrix[m].begin(), matrix[m].end(), 0);
            for(int i = 0; i < n; ++i) matrix[i][n] = 0;
            for(int i = n+1; i < matrix.size(); ++i) matrix[i][n] = 0;
        }
    }
};
