#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string newStr;
        int index = 0;

        for(int i = 0; i < strs.size(); ++i) {
            newStr = strs[i];
            sort(newStr.begin(), newStr.end());
            if(M.find(newStr) == M.end()) {
                M.insert(pair<string,int>(newStr,index));
                vector<string> newAna;
                newAna.push_back(strs[i]);
                Ans.push_back(newAna);
                ++index;
            } else {
                int idx = M.find(newStr)->second;
                Ans[idx].push_back(strs[i]);
            }
        }
        return Ans;
    }

private:
    map<string,int> M;
    vector<vector<string>> Ans;
};
