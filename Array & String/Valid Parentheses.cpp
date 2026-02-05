#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char topParen;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') S.push(s[i]);
            else {
                if(S.empty()) return false;

                topParen = S.top();
                if(topParen == '(' && s[i] == ')') S.pop();
                else if(topParen == '[' && s[i] == ']') S.pop();
                else if(topParen == '{' && s[i] == '}') S.pop();
                else return false;
            }
        }
        if(S.empty()) return true;
        else return false;
    }

private:
    stack<char> S;
};
