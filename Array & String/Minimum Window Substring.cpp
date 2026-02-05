#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(s.compare(t) == 0) return s;
        if(m < n) return "";

        vector<int> toMatch(128,0);
        int targetLen = n;

        for(int i = 0; i < n; ++i) ++toMatch[t[i]];
        int i = 0, j = 0;
        while(j < m) {
            if(toMatch[s[j]] > 0) --targetLen;
            --toMatch[s[j]];
            ++j;
            while(targetLen == 0 && i <= m-n) {
                if(j-i < minLen) {
                    left = i; right = j - 1;
                    minLen = j - i;
                }
                ++toMatch[s[i]];
                if(toMatch[s[i]] > 0) ++targetLen;
                ++i;
            }
        }
        return s.substr(left, right-left+1);
    }

private:
    int left = 0, right = -1;
    int minLen = 100000;
};
