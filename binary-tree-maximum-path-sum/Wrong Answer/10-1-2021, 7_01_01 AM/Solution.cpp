// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
public: int mx=INT_MIN;
    int mxd(TreeNode* root){
        if(!root) return 0;
        int l=mxd(root->left),r=mxd(root->right),v=l+r+root->val;
        if(v>mx)mx=v;
        return v;
    }
    int maxPathSum(TreeNode* root) {
        mxd(root);
        return mx;
    }
};