#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int bin = findLongestPath(root);
        return diameter;
    }

private:
    int findLongestPath(TreeNode* root) {
        if(!root) return 0;
        int leftDia = findLongestPath(root->left);
        int rightDia = findLongestPath(root->right);
        diameter = max(diameter, leftDia + rightDia);
        return max(leftDia, rightDia)+1;
    }

    int diameter = 0;
};
