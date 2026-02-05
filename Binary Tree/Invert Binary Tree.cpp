#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        invertChild(root);
        return root;
    }

private:
    void invertChild(TreeNode* root) {
        if(!root->left && !root->right) return;

        if(root->left) invertChild(root->left);
        if(root->right) invertChild(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};
