#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int bin = findPQ(root, p->val, q->val);
        return lca;
    }

private:
    bool findPQ(TreeNode* root, int p, int q) {
        if(p_found && q_found) return false;
        if(!root) return false;

        bool left = findPQ(root->left, p, q);
        bool right = findPQ(root->right, p, q);
        bool parent = false;

        if(root->val == p) {
            p_found = true;
            parent = true;
        } else if(root->val == q) {
            q_found = true;
            parent = true;
        }
        if((left & right) | (left & parent) | (right & parent)) lca = root;
        return (left | right) | (left | parent) | (right | parent);
    }

    TreeNode* lca;
    bool p_found = false, q_found = false;
};
