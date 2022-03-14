// https://leetcode.com/problems/sum-of-left-leaves

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
    void util(TreeNode* root,int &s,int ch){
        if(!root) return;
        util(root->left,s,1);
        if(!root->left && !root->right)
            if(ch==1)s+=root->val;
        util(root->right,s,2);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int s=0;
        util(root,s,0);
        return s;
    }
};