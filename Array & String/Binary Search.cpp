#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n / 2;
        int left = 0, right = n - 1;

        while(left <= right) {
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                right = mid - 1;
                mid = (left + right) / 2;
            } else {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
        return -1;
    }
};
