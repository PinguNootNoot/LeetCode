#include <bits/stdc++.h>
using namespace std;

/** Use hash-map to solve the Two Sum problem.
*    Time complexity = O(n)
*/

class TwoSum {
public:
    vector<int> solve(vector<int> &nums, int target) {
        map<int,int> m = createMap(nums);
        vector<int> ans;
        int n, dif;
        map<int,int>::iterator it;

        for(int i = 0; i < nums.size(); ++i) {
            n = nums[i];
            dif = target - n;
            it = m.find(dif);
            if(it == m.end()) continue;
            else {
                if(i != it->second) {
                    ans.push_back(i);
                    ans.push_back(it->second);
                    return ans;
                }
            }
        }
        return {-1, -1};
    }

private:
    map<int,int> createMap(vector<int> &arr) {
        map<int,int> m;

        for(int i = 0; i < arr.size(); ++i) {
            m.insert(pair<int,int>(arr[i],i));
        }
        return m;
    }
};

int main() {
    TwoSum ts;
    vector<int> arr = {1, 2, 3, 7, 5};
    vector<int> ans;
    int tar = 6;

    ans = ts.solve(arr,tar);
    printf("[%d, %d]\n", ans[0], ans[1]);
    return 0;
}
