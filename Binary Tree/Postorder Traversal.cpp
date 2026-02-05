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

/* Traversing recursively */
class Solution {
public:
    vector<int> visitOrder;

    vector<int> postorderTraversal(TreeNode* root) {
        Travel(root);
        return visitOrder;
    }

    void Travel(TreeNode* r){
        if(r){
            Travel(r->left);
            Travel(r->right);
            visitOrder.push_back(r->val);
        }
    }
};
