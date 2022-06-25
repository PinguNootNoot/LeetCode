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

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        stack<pair<TreeNode*,string>> S;
        pair<TreeNode*,string> Ltmp, Rtmp;

        /* Check left-subtree & right-subtree simultaneously */
        /* Push left first, extract right first */
        if(root->left != nullptr) S.push({root->left, "LL"});
        if(root->right != nullptr) S.push({root->right, "RR"});
        while(!S.empty()){
            Rtmp = S.top();
            S.pop();
            if(S.empty() || (Rtmp.second == "LL" || Rtmp.second == "LR")) return false;
            Ltmp = S.top();
            if(Ltmp.second == "RR" || Ltmp.second == "RL") return false;
            S.pop();

            if(Ltmp.first->val != Rtmp.first->val) return false;
            if((Ltmp.second == "LL" && Rtmp.second == "RL") || (Ltmp.second == "LR" && Rtmp.second == "RR")) return false;

            if(Ltmp.first->left != nullptr) S.push({Ltmp.first->left, "LL"});
            if(Rtmp.first->right != nullptr) S.push({Rtmp.first->right, "RR"});
            if(Ltmp.first->right != nullptr) S.push({Ltmp.first->right, "LR"});
            if(Rtmp.first->left != nullptr) S.push({Rtmp.first->left, "RL"});
        }
        return true;
    }
};
