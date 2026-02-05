#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalin(string s, int left, int right) {
        int i = ((left + right) % 2 == 0) ? (left + right) / 2 - 1 : (left + right) / 2;
        int j = (left + right) / 2 + 1;

        for(; i >= left, j <= right; --i, ++j) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    void recurPartition(string s, int start, int n) {
        if(start == n) {
            ans.push_back(par);
        } else {
            for(int i = start; i < n; ++i) {
                if(isPalin(s,start,i)) {
                    par.push_back(s.substr(start, i-start+1));
                    recurPartition(s, i+1, n);
                    par.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        recurPartition(s,0,n);
        return ans;
    }

private:
    vector<vector<string>> ans;
    vector<string> par;
};
