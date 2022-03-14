// https://leetcode.com/problems/recover-binary-search-tree

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
    void solve(TreeNode* root,TreeNode* &prev,TreeNode* &f,TreeNode* &s){
        if(!root) return;
        solve(root->left,prev,f,s);
        if(prev->val>root->val){
            if(!f){
                f=prev;
                s=root;
            }
            else s=root;
        }
        prev=root;
       solve(root->right,prev,f,s);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev=new TreeNode(INT_MIN),*f=NULL,*s=NULL;
        solve(root,prev,f,s);
        if(!f || !s) return;
        swap(f->val,s->val);
    }
};