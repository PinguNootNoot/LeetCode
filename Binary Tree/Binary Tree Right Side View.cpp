#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        findView(root,0);
        return nodes;
    }

private:
    void findView(TreeNode* root, int depth) {
        if(root) {
            if(depth > maxdepth) {
                nodes.push_back(root->val);
                ++maxdepth;
            }
            findView(root->right, depth+1);
            findView(root->left, depth+1);
        }
    }
    vector<int> nodes;
    int maxdepth = -1;
};
