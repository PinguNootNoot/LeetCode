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


/* Traversing iteratively */
class Solution {
public:
    vector<int> visitOrder;
    stack<TreeNode*> S;

    vector<int> preorderTraversal(TreeNode* root) {
        if(root != nullptr){
            S.push(root);
            Travel();
        }
        return visitOrder;
    }

    void Travel(){
        TreeNode* tmp;
        while(!S.empty()){
            tmp = S.top();
            visitOrder.push_back(tmp->val);
            S.pop();
            if(tmp->right != nullptr) S.push(tmp->right);
            if(tmp->left != nullptr) S.push(tmp->left);
        }
    }
};
