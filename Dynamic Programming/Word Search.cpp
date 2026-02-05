#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), s = word.size();
        vector<vector<bool>> valid(m, vector<bool>(n, true));
        unordered_map<char,int> M;

        char head = word[0];
        int r, c;
        bool backtrack = false;

        for(int i = 0; i < s; ++i) {
            if(M.find(word[i]) == M.end()) M.insert(pair<char,int>(word[i],1));
            else ++M.find(word[i])->second;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                auto m = M.find(board[i][j]);
                if(m != M.end()) {
                    if(m->second == 1) M.erase(m);
                    else --m->second;
                }
                if(board[i][j] == head) {
                    S.push(pair<int,int>(i,j));
                    Level.push(0);
                }
            }
        }

        if(!M.empty()) return false;
        while(!S.empty()) {
            auto next = S.top(); S.pop();
            r = next.first, c = next.second;
            pointer = Level.top() + 1; Level.pop();
            if(pointer >= word.size()) return true;
            if(backtrack) {
                trackNum -= pointer;
                while(trackNum >= 0) {
                    auto grid = revisit.top();
                    valid[grid.first][grid.second] = true;
                    revisit.pop();
                    --trackNum;
                }
                backtrack = false;
            }
            valid[r][c] = false;
            revisit.push(pair<int,int>(r,c));

            if(r < m - 1) {
                if(board[r+1][c] == word[pointer] && valid[r+1][c]) {
                    S.push(pair<int,int>(r+1,c));
                    Level.push(pointer);
                }
            } if(r > 0) {
                if(board[r-1][c] == word[pointer] && valid[r-1][c]) {
                    S.push(pair<int,int>(r-1,c));
                    Level.push(pointer);
                }
            } if(c < n - 1) {
                if(board[r][c+1] == word[pointer] && valid[r][c+1]) {
                    S.push(pair<int,int>(r,c+1));
                    Level.push(pointer);
                }
            } if(c > 0) {
                if(board[r][c-1] == word[pointer] && valid[r][c-1]) {
                    S.push(pair<int,int>(r,c-1));
                    Level.push(pointer);
                }
            }
            if(!Level.empty()) {
                backtrack = (pointer > Level.top()) ? true : false;
                trackNum = (pointer > Level.top()) ? pointer : 0;
            }
        }
        return false;
    }

private:
    stack<pair<int,int>> S, revisit;
    stack<int> Level;
    int pointer, trackNum;
};
