#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        for(int i = 0; i < s.size(); ++i) {
            if(M.find(s[i]) == M.end()) {
                M.insert(pair<char,int>(s[i],i));
                ++subLen;
            } else {
                i = M.find(s[i])->second;
                M.clear();
                if(maxLength < subLen) maxLength = subLen;
                subLen = 0;
            }
            if(maxLength < subLen) maxLength = subLen;
        }
        return maxLength;
    }

private:
    map <char,int> M;
    int maxLength = 0, subLen = 0;
};
