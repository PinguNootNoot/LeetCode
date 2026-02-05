#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return Ans;
        if(n == 1) {
            Ans.push_back("()");
            return Ans;
        }
        parenPermutation(n*2, 1, "");
        return Ans;
    }

private:
    vector<string> Ans;
    stack<char> S;

    void parenPermutation(int n, int level, string buffer) {
        if(level > n) {
            if(S.empty()) Ans.push_back(buffer);
            return;
        } else {
            buffer.push_back('(');
            S.push('(');
            parenPermutation(n, level+1, buffer);
            buffer.pop_back();
            S.pop();

            if(S.empty()) return;
            char t = S.top();
            S.pop();
            buffer.push_back(')');
            parenPermutation(n, level+1, buffer);
            buffer.pop_back();
            S.push(t);
        }
    }
};
