// https://leetcode.com/problems/balanced-binary-tree

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
public: bool f=true;
    int ht(TreeNode* root){
        if(!root || !f) return 0;
        int l=ht(root->left),r=ht(root->right); 
        if(abs(l-r)>1) f=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        ht(root);
        return f;
    }
};