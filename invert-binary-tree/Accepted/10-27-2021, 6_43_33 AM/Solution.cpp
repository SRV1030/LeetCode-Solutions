// https://leetcode.com/problems/invert-binary-tree

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
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(!root) return NULL;
//         TreeNode* t= new TreeNode(root->val);
//         t->left=invertTree(root->right);
//         t->right=invertTree(root->left);
//         return t;
//     }
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* t= root->left;
        root->left=root->right;
        root->right=t;
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};