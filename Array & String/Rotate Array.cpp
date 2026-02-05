#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0) return;

        k %= n;
        vector<int> t1(nums.begin(), nums.begin()+n-k);
        vector<int> t2(nums.begin()+n-k, nums.end());
        t2.insert(t2.end(), t1.begin(), t1.end());
        nums.swap(t2);
        return;
    }
};
