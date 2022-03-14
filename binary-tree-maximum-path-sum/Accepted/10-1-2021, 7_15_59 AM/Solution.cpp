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
        int l=max(0,mxd(root->left)),r=max(0,mxd(root->right)),v=l+r+root->val;
        if(v>mx)mx=v;
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        mxd(root);
        return mx;
    }
};