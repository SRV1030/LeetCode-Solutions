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
public:
    unordered_map<TreeNode*,int>mp;
    int ht(TreeNode* root){
        if(!root) return 0;
        int l=ht(root->left),r=ht(root->right); 
        if(root->left)mp[root->left]=l;
        if(root->right)mp[root->right]=r;
        return mp[root]=1+max(mp[root->left], mp[root->right]);
    }
    bool isBal(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return true;
        if((!root->left && mp[root->right]<=1) ||  (!root->right && mp[root->left]<=1)) return true;
        if(abs(mp[root->left]-mp[root->right])>1) return false;
        return isBal(root->left) && isBal(root->right);
    }
    bool isBalanced(TreeNode* root) {
        ht(root);
        return isBal(root);
    }
};