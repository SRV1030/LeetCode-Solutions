// https://leetcode.com/problems/print-binary-tree

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
    vector<vector<string>> ans;
    int ht(TreeNode* root){
        if(!root) return 0;
        return 1+max(ht(root->left),ht(root->right));
    }
    void util(TreeNode* root,int r,int l,int h){
        if(!root) return;
        int m=l+(h-l)/2;
        ans[r][m]=to_string(root->val);
        util(root->left,r+1,l,m-1);
        util(root->right,r+1,m+1,h);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return ans;
        int r=ht(root),c=(1<<r)-1;
        ans=vector<vector<string>>(r,vector<string>(c,""));
        util(root,0,0,c);
        return ans;
    }
};