#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int Begin, End;
        int select1, select2, mid;

        if(s.size() <= 1) return s;
        else if(s.size() == 2) {
            if(s[0] == s[1]) return s;
            else {
                out.push_back(s[0]);
                return out;
            }
        }

        for(int i = 0; i < s.size()-2; ++i) {
            select1 = i; mid = i + 1; select2 = i + 2;
            if(s[select1] == s[select2]) {
                subLength = 3;
                while(select1 >= 0 && select2 < s.size()) {
                    if(s[select1] != s[select2]) break;
                    subLength += 2; --select1; ++select2;
                }
                if(maxLength < subLength) {
                    maxLength = subLength;
                    Begin = select1 + 1; End = select2 - 1;
                }
                select1 = i; mid = i + 1;
            } if(s[select1] == s[mid]) {
                select2 = mid;
                subLength = 2;
                while(select1 >= 0 && select2 < s.size()) {
                    if(s[select1] != s[select2]) break;
                    subLength += 2; --select1; ++select2;
                }
                if(maxLength < subLength) {
                    maxLength = subLength;
                    Begin = select1 + 1; End = select2 - 1;
                }
                mid = i + 1; select2 = i + 2;
            } else if(s[mid] == s[select2]) {
                select1 = mid;
                subLength = 2;
                while(select1 >= 0 && select2 < s.size()) {
                    if(s[select1] != s[select2]) break;
                    subLength += 2; --select1; ++select2;
                }
                if(maxLength < subLength) {
                    maxLength = subLength;
                    Begin = select1 + 1; End = select2 - 1;
                }
            } else {
                if(maxLength < 1) {
                    maxLength = 1;
                    Begin = End = i;
                }
            }
        }
        for(int i = Begin; i <= End; ++i) out.push_back(s[i]);
        return out;
    }

private:
    string out;
    int maxLength = 0, subLength;
};
