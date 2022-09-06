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
    bool hasOne(TreeNode* root){
        if(!root) return false;
        bool l=hasOne(root->left),r=hasOne(root->right);
        if(!l)root->left=NULL;
        if(!r)root->right=NULL;
        return root->val==1 || l || r;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return hasOne(root)?root:NULL;
    }
};