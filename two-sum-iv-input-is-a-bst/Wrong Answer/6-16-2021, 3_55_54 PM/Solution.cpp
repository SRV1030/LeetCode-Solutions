// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    bool search(TreeNode* root,int k){
        if(!root) return false;
         if(root->val==k) return true;
        if(root->left && root->val>k)if(search(root->left,k)) return true;
        else if(root->right && root->val<k)if(search(root->right,k)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        int t=k-root->val;
        if(t>root->val)
            if(search(root->right,t)) return true;
        else if(search(root->left,t)) return true;
        return (root->left,k)||(root->right,k);
    }
};