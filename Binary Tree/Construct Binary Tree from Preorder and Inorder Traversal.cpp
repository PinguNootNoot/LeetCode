#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* construct(vector<int>::iterator left, vector<int>::iterator right) {
        if(left == right) return nullptr;
        TreeNode* node = new TreeNode();
        auto index = find(left, right, P[cnt]);
        node->val = P[cnt++];
        node->left = construct(left, index);
        node->right = construct(index+1,right);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        P.resize(preorder.size()); copy(preorder.begin(), preorder.end(), P.begin());

        TreeNode* root = new TreeNode();
        auto index = find(inorder.begin(), inorder.end(), preorder[cnt]);
        root->val = preorder[cnt++];
        root->left = construct(inorder.begin(), index);
        root->right = construct(index+1, inorder.end());
        return root;
    }

private:
    vector<int> P;
    int cnt = 0;
};
