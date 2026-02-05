#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        return generateStr(s,0,n);
    }

private:
    string generateStr(string s, int i, int n) {
        string pattern;
        string num;

        for(; i < n; ++i) {
            cur_idx = i;
            if(isdigit(s[i])) {
                num.push_back(s[i]);
                continue;
            } else if(isalpha(s[i])) {
                pattern.push_back(s[i]);
                continue;
            }
            if(s[i] == '[') {
                string temp = generateStr(s,i+1,n);
                int k = stoi(num);
                for(int j = 0; j < k; ++j) pattern.append(temp);
                num.clear();
                i = cur_idx;
            } else if(s[i] == ']') break;
        }
        return pattern;
    }

    int cur_idx;
};
