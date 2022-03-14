// https://leetcode.com/problems/binary-tree-postorder-traversal

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
public: vector<int>p;
    void post(TreeNode* root){
        if(!root) return;
        post(root->left);
        post(root->right);
        p.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return p;
    }
};