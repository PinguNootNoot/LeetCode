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
    vector<vector<int>> visitOrder;
    queue<TreeNode*> Q;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root){
            Q.push(root);
            visitOrder.push_back(vector<int>());
            LevelTravel();
        }
        return visitOrder;
    }

    void LevelTravel() {
        TreeNode* tmp;
        int thisLevelNode = 1, nextLevelNode = 0, cnt = 0, level = 0;

        while(!Q.empty()){
            tmp = Q.front();
            cnt++;
            visitOrder[level].push_back(tmp->val);
            Q.pop();

            if(tmp->left != nullptr){
                Q.push(tmp->left);
                nextLevelNode++;
            } if(tmp->right != nullptr){
                Q.push(tmp->right);
                nextLevelNode++;
            }
            if(cnt >= thisLevelNode){
                thisLevelNode = nextLevelNode;
                cnt = nextLevelNode = 0;
                level++;
                visitOrder.push_back(vector<int>());
            }
        }
        if(visitOrder[visitOrder.size()-1].size() == 0) visitOrder.pop_back();
    }
};
