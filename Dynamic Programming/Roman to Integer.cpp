#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int cur, next;

        M.insert(pair<char,int>('I',1));
        M.insert(pair<char,int>('V',5));
        M.insert(pair<char,int>('X',10));
        M.insert(pair<char,int>('L',50));
        M.insert(pair<char,int>('C',100));
        M.insert(pair<char,int>('D',500));
        M.insert(pair<char,int>('M',1000));

        if(s.size() == 1) return M.find(s[0])->second;

        for(int i = 0; i < s.size();) {
            int lookahead = i + 1;

            cur = M.find(s[i])->second; next = M.find(s[lookahead])->second;
            if(cur >= next) {
                ans += cur;
                ++i;
            } else {
                ans += abs(cur - next);
                i += 2;
            }
        }
        return ans;
    }

private:
    map<char,int> M;
};
