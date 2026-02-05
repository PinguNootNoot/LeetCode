#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> changes(n-1);

        for(int i = 1; i < n; ++i) changes[i-1] = prices[i] - prices[i-1];
        --n;

        for(int window = 0; window < n; ++window) {
            p = (p + changes[window] > 0) ? p + changes[window] : 0;
            Profit = max(Profit, p);
        }
        return Profit;
    }

private:
    int Profit = 0, p = 0;
};
