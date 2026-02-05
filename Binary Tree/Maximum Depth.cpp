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
    int ans = 0;

    int maxDepth(TreeNode* root) {
        if(root) findDepth(root,1);
        return ans;
    }

    void findDepth(TreeNode* root, int depth){
        if(ans < depth) ans = depth;
        if(root->left != nullptr) findDepth(root->left, depth+1);
        if(root->right != nullptr) findDepth(root->right, depth+1);

        return;
    }
};
