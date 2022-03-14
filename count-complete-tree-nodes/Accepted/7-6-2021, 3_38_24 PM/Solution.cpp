// https://leetcode.com/problems/count-complete-tree-nodes

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
public:int mx=0;
    void count(TreeNode* root){
        if(!root) return;
        mx++;
        if(root->left)count(root->left);
        if(root->right)count(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        count(root);
        return mx;
    }
};