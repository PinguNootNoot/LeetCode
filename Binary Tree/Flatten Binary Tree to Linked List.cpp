#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Traverse(TreeNode* root) {
        if(root == nullptr) return;
        Q.push(root->val);
        Traverse(root->left);
        Traverse(root->right);
    }

    void flatten(TreeNode* root) {
        Traverse(root);
        if(!Q.empty()) {
            Q.pop();  // exclude the root
            root->left = nullptr;
        }
        while(!Q.empty()) {
            root->right = new TreeNode(Q.front());
            root = root->right;
            Q.pop();
        }
    }

private:
    queue<int> Q;
};
