#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void buildTree(int left, int mid, int right) {
        if(left > right) return;

        if(left != mid) {
            bst[mid]->left = bst[(left+mid)/2];
            buildTree(left, (left+mid)/2, mid-1);
        } else bst[mid]->left = nullptr;

        if(right != mid) {
            bst[mid]->right = bst[(mid+right+1)/2];
            buildTree(mid+1, (mid+right+1)/2, right);
        } else bst[mid]->right = nullptr;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
    
        while(head) {
            TreeNode* newNode = new TreeNode(head->val);
            bst.push_back(newNode);
            head = head->next;
        }

        int left = 0, right = bst.size() - 1, mid = (left + right) / 2;
        buildTree(left, mid, right);

        return bst[mid];
    }

private:
    vector<TreeNode*> bst;
};
