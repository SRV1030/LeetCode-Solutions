// https://leetcode.com/problems/subtree-of-another-tree

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
    bool isSub(TreeNode* root,TreeNode* subRoot){
        if(!root || !subRoot) return root==subRoot;
        return root->val==subRoot->val && isSub(root->left,subRoot->left) && isSub(root->right,subRoot->right);
            
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;
        return isSub(root,subRoot) ||  isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};