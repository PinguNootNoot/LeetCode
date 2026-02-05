#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 1) return;

        int done = 0, toRotate = (matrix.size() % 2 == 0) ? pow(matrix.size(),2) : pow(matrix.size(),2) - 1;
        int boundary = 0, layer = 0;
        char dir = 'D';

        while(done < toRotate) {
            int fromX = layer + 1, fromY = matrix.size() - boundary - 1;

            for(int i = boundary + 1; i < matrix.size() - boundary; ++i) Q.push(matrix[layer][i]);
            int x = fromX, y = fromY;
            while(1) {
                Q.push(matrix[x][y]);
                matrix[x][y] = Q.front();
                Q.pop();
                ++done;

                if(dir == 'D') {
                    if(x == (matrix.size() - boundary - 1)) {
                        --y;
                        dir = 'L';
                    }
                    else ++x;
                } else if(dir == 'L') {
                    if(y == boundary) {
                        --x;
                        dir = 'U';
                    }
                    else --y;
                } else if(dir == 'U') {
                    if(x == boundary) {
                        ++y;
                        dir = 'D';
                        break;
                    }
                    else --x;
                }
            }
            while(!Q.empty()) {
                matrix[x][y] = Q.front();
                Q.pop();
                ++y; ++done;
            }
            ++boundary;
            ++layer;
        }
    }

private:
    queue<int> Q;
};
