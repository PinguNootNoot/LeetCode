#include <bit/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int window_len = p.size();
        if(n < window_len) return ans;

        for(int i = 0; i < window_len; ++i) {
            ++p_alpha[p[i] - 'a'];
            ++s_alpha[s[i] - 'a'];
        }
        if(s_alpha == p_alpha) ans.push_back(0);

        for(int i = 0, j = i + window_len; j < n; ++i, ++j) {
            ++s_alpha[s[j] - 'a'];
            --s_alpha[s[i] - 'a'];
            if(s_alpha == p_alpha) ans.push_back(i+1);
        }
        return ans;
    }

private:
    vector<int> s_alpha(26);
    vector<int> p_alpha(26);
    vector<int> ans;
};
