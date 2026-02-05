#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_len = s1.size(), n = s2.size();
        if(window_len > n) return false;

        vector<int> freq1(26);
        vector<int> freq2(26);
        for(int i = 0; i < window_len; ++i) {
            ++freq1[s1[i] - 'a'];
            ++freq2[s2[i] - 'a'];
        }
        if(freq1 == freq2) return true;
        for(int i = 0, j = window_len; j < n; ++i, ++j) {
            --freq2[s2[i] - 'a'];
            ++freq2[s2[j] - 'a'];
            if(freq1 == freq2) return true;
        }
        return false;
    }
};
