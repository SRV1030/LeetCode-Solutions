// https://leetcode.com/problems/univalued-binary-tree

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
    bool ch(int &v,TreeNode* root){
        if(!root) return true;
        if(root->val!=v) return false;
        return ch(v,root->left) && ch(v,root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return false;
        return ch(root->val,root);
    }
};