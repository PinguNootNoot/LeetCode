#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        char alpha;
        vector<int> offset = {0,3,6,9,12,15,19,22};
        vector<string> ansV, returnedV;
        string buffer;
        int range = (digits[0] == '7' || digits[0] == '9') ? 4 : 3;

        if(digits.size() == 0) return ansV;
        if(digits.size() == 1) {
            for(int i = 0; i < range; ++i) {
                alpha = 'a' + offset[digits[0]-'2'] + i;
                buffer.push_back(alpha);
                ansV.push_back(buffer);
                buffer.clear();
            }
            return ansV;
        }

        string subStr = digits;
        subStr.erase(0,1);

        for(int i = 0; i < range; ++i) {
            returnedV = letterCombinations(subStr);
            alpha = 'a' + offset[digits[0]-'2'] + i;
            if(returnedV.empty()) {
                buffer.push_back(alpha);
                ansV.push_back(buffer);
                continue;
            }
            for(int j = 0; j < returnedV.size(); ++j) {
                string alphabet;
                buffer = returnedV[j];
                buffer.insert(0, alphabet.append(1,alpha));
                ansV.push_back(buffer);
            }
        }
        return ansV;
    }
};
