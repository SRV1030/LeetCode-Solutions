// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int s=0;
    void util(TreeNode* root,int ans){
        if(!root) return;
        ans=ans*2+root->val;
        if(!root->left && !root->right) s+=ans;
        util(root->left,ans);
        util(root->right,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        util(root,ans);
        return s;
    }
};