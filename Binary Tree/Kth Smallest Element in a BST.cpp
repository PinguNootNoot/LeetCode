#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        countChild(root, k);
        return ans;
    }

private:
    void countChild(TreeNode* root, int k) {
        if(ans >= 0) return;

        if(root->left) countChild(root->left, k);
        if((sum == k || sum+1 == k) && !found) {
            ans = root->val;
            found = true;
            return;
        }
        ++sum;
        if(root->right) countChild(root->right,k);
        if(sum == k && !found) {
            ans = root->val;
            found = true;
            return;
        }
    }

    int ans = -1;
    int sum = 0;
    bool found = false;
};
