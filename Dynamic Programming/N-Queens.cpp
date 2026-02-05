#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findNextQueen(int row, int goal) {
        if(row == goal) {
            vector<string> solution;

            for(int i = 0; i < queenColPos.size(); ++i) {
                string curRow;
                for(int j = 0; j < queenColPos[i]; ++j) curRow.push_back('.');
                curRow.push_back('Q');
                for(int j = queenColPos[i]+1; j < goal; ++j) curRow.push_back('.');
                solution.push_back(curRow);
            }
            Ans.push_back(solution);
            return;
        }
        for(int i = 0; i < goal; ++i) {
            bool placeable = true;
            for(int j = 0; j < queenColPos.size(); ++j) {
                // if on the same column or on the same diagonal
                if((i == queenColPos[j]) || (abs(row - j) == abs(i - queenColPos[j]))) {
                    placeable = false;
                    break;
                }
            }
            if(placeable) {
                queenColPos.push_back(i);
                findNextQueen(row+1, goal);
                queenColPos.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens;

        if(n == 2 || n == 3) return Ans;
        if(n == 1) {
            queens.push_back("Q");
            Ans.push_back(queens);
            return Ans;
        }
        findNextQueen(0, n);
        return Ans;
    }

private:
    vector<vector<string>> Ans;
    vector<int> queenColPos;
};
