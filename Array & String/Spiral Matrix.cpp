#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int width = matrix[0].size(), height = matrix.size();
        int done = 0, toDo = width*height;
        char dir = 'R';

        int layer = 0;
        int i = layer, j = layer;
        while(done < toDo) {
            Ans.push_back(matrix[i][j]);
            ++done;
            if(dir == 'R') {
                if(j == width - layer - 1) {
                    dir = 'D';
                    ++i;
                } else ++j;
            } else if(dir == 'D') {
                if(i == height - layer - 1) {
                    dir = 'L';
                    --j;
                } else ++i;
            } else if(dir == 'L') {
                if(j == layer) {
                    --i;
                    dir = 'U';
                } else --j;
            } else if(dir == 'U') {
                if(i == layer + 1) {
                    dir = 'R';
                    ++layer; i = layer; j = layer;
                } else --i;
            }
        }
        return Ans;
    }

private:
    vector<int> Ans;
};
