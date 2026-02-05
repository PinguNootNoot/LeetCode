#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = findMin(coins, amount);
        return (ans == 1e5) ? -1 : ans;
    }

private:
    int findMin(vector<int>& coins, int remain_amt) {
        if(remain_amt == 0) return 0;
        if(minChanges[remain_amt] != -1) return minChanges[remain_amt];

        int changes = 1e5;
        for(int coin: coins) {
            if(remain_amt >= coin) {
                changes = min(changes, findMin(coins, remain_amt-coin)+1);
            }
        }
        minChanges[remain_amt] = changes;
        return changes;
    }

    vector<int> minChanges(10001, -1);
};
