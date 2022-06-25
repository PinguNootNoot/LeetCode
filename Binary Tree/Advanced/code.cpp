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

/* Tree root is the last visited node in Post-order traversal */
/* Every node that is on the left side of the "root node" in In-order list is on the left-subtree */
/* Same rule applies for the nodes on the right-subtree */
/* IMPORTANT: Apply Divide-and-Conquer technique */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if((*inorder).size() == 0) return nullptr;
        if((*inorder).size() == 1) return new TreeNode((*inorder)[0]);

        TreeNode* root;
        stack<int> PrevMotherIdx;
        int IdxChild, lastMotherIdx, IdxMother = (*postorder).size() - 1;
        int consNodeCnt = 0;

        while(consNodeCnt < (*inorder).size()){
            root = new TreeNode((*postorder)[IdxMother]);
        }
        return root;
    }
};
