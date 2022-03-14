// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
public: int ans=0;
    void util(TreeNode* root,string s){
        if(!root) return;
        s+=to_string(root->val);
        if(!root->left && !root->right)ans+=stoi(s);
        util(root->left,s);
        util(root->right,s);
    }
    int sumNumbers(TreeNode* root) {
        util(root,"");
        return ans;
    }
};