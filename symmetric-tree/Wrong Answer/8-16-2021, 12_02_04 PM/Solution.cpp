// https://leetcode.com/problems/symmetric-tree

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
public: bool f;
    void checkm(TreeNode* r1,TreeNode* r2){
        if(!f) return;
        if(!r1 && !r2) return;
        if(!r1 || !r2){
            f=false;
            return;
        }
        if(r1->val!=r2->val) return;
        checkm(r1->left,r2->right);
        checkm(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        f=true;
        if(!root) return f;
        checkm(root->left,root->right);
        return f;
    }
};