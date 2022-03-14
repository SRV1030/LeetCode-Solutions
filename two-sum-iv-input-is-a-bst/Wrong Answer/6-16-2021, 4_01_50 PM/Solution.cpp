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
        if(root->left && root->val>k)return search(root->left,k);
        else if(root->right) return search(root->right,k);
       return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        int t=k-root->val;        
        if(search(root->right,t)) return true;
        else if(search(root->left,t)) return true;
        return findTarget(root->left,k)||findTarget(root->right,k);
    }
};