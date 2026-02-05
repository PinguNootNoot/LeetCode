#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    }; */

class Solution {
public:
    int flag = 0;

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        PreorderTraverse(root, targetSum, 0);
        if(!flag) return false;
        return true;
    }

    void PreorderTraverse(TreeNode* root, int tar, int cur){
        if(root != nullptr){
            if(root->left == nullptr && root->right == nullptr && (root->val + cur == tar)) flag = 1;
            else{
                PreorderTraverse(root->left, tar, root->val+cur);
                PreorderTraverse(root->right, tar, root->val+cur);
            }
        }
    }
};
