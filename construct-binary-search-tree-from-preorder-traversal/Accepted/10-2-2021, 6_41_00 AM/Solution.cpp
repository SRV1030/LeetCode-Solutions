// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    void dfs(TreeNode* &root,int i){
        if(!root){
            root=new TreeNode(i);
            return;
        }
        if(root->val>i){
            if(!root->left) root->left=new TreeNode(i);
            else dfs(root->left,i);
        }else{
           if(!root->right) root->right=new TreeNode(i);
           else dfs(root->right,i); 
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=NULL; 
        for(auto&i:pre) dfs(root,i);
        return root;
    }
};