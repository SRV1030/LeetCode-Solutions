// https://leetcode.com/problems/validate-binary-search-tree

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
    bool util(TreeNode*root,int mn,int mx){
        if(!root) return 1;
        if(root->val<=mn || root->val>=mx) return 0;
        return util(root->left,mn,root->val)&&util(root->right,root->val,mx);
        
    }
    bool isValidBST(TreeNode* root) {              
        return util(root,-100000007,100000007);        
    }
};