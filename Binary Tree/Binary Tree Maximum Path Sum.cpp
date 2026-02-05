#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* node) {
        if(!node) return 0;
        int leftSum = pathSum(node->left);
        int rightSum = pathSum(node->right);

        int subMax;
        if(leftSum > 0 && rightSum > 0) subMax = node->val + leftSum + rightSum;
        else {
            if(leftSum > 0) subMax = node->val + leftSum;
            else if(rightSum > 0) subMax = node->val + rightSum;
            else subMax = node->val;
        }
        if(maxSum < subMax) maxSum = subMax;
        return max(node->val, max(node->val+leftSum, node->val+rightSum));
    }

    int maxPathSum(TreeNode* root) {
        int can = pathSum(root);
        return maxSum;
    }

private:
    int maxSum = INT_MIN;
};
