// https://leetcode.com/problems/diameter-of-binary-tree

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
    int ht(TreeNode* root){
        if(!root) return 0;
        return max(ht(root->left),ht(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int l=ht(root->left),r=ht(root->right),ld=diameterOfBinaryTree(root->left),rd=diameterOfBinaryTree(root->right);
        return max(l+r,max(ld,rd));
    }
};