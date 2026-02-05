#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    void validate(TreeNode* node, int min_val, int max_val) {
        if(!flag || node == nullptr) return;
        int val = node->val;
        if(val < min_val || val > max_val || S.find(val) != S.end()) {
            flag = false;
            return;
        }
        S.insert(val);
        validate(node->left, min_val, val);
        validate(node->right, val, max_val);
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return flag;
        validate(root, INT_MIN, INT_MAX);
        return flag;
    }

private:
    bool flag = true;
    unordered_set<int> S;
};
