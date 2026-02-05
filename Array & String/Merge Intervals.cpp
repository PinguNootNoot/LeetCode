#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        vector<int> inter;
        vector<char> bridges(10001, 'X');
        char lastChar = 'X';
        int intStart, intEnd, tempEnd;
        int maxRight = 0;

        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i][0] == intervals[i][1]) {
                bridges[intervals[i][0]] = (bridges[intervals[i][0]] == 'X') ? 'T' : bridges[intervals[i][0]];
            } else {
                fill(bridges.begin()+intervals[i][0], bridges.begin()+intervals[i][1], 'O');
                if(bridges[intervals[i][1]] == 'T') bridges[intervals[i][1]] = 'X';
            }
            if(intervals[i][1] > maxRight) maxRight = intervals[i][1];
        }
        for(int i = 0; i <= maxRight; ++i) {
            if(bridges[i] == 'T') {
                if(lastChar == 'O') {
                    intEnd = tempEnd;
                    inter.push_back(intStart);
                    inter.push_back(intEnd);
                    Sol.push_back(inter);
                    inter.clear();
                } else {
                    inter.push_back(i);
                    inter.push_back(i);
                    Sol.push_back(inter);
                    inter.clear();
                }
                lastChar = 'T';
            } else if(bridges[i] == 'X') {
                if(lastChar == 'O') {
                    intEnd = tempEnd;
                    inter.push_back(intStart);
                    inter.push_back(intEnd);
                    Sol.push_back(inter);
                    inter.clear();
                    lastChar = 'X';
                }
            } else if(bridges[i] == 'O') {
                intStart = (lastChar == 'X' || lastChar == 'T') ? i : intStart;
                lastChar = 'O';
                tempEnd = i + 1;
            }
        }
        if(intStart > intEnd) {
            inter.push_back(intStart);
            inter.push_back(tempEnd);
            Sol.push_back(inter);
        }
        return Sol;
    }

private:
    vector<vector<int>> Sol;
};
