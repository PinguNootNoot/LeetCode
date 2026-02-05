#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        for(int layer = 2; layer <= numRows; ++layer) {
            vector<int> hier(layer);
            int dog = -1, cat = 0;
            for(int i = 0; i < layer; ++i) {
                if(dog < 0 || cat >= layer-1) hier[i] = 1;
                else hier[i] += Pas[layer-2][dog] + Pas[layer-2][cat];
                ++dog; ++cat;
            }
            Pas.push_back(hier);
        }
        return Pas;
    }

private:
    vector<vector<int>> Pas {{1}};
};
