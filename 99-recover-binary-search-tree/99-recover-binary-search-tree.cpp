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
    TreeNode* f=NULL,*s=NULL,*prev=new TreeNode(INT_MIN);
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        if(prev->val>root->val){
            if(!f){
                f=prev;
                s=root;                
            }
            else s=root;
        }
        prev=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        solve(root);
        if(!f || !s) return;
        swap(f->val,s->val);
    }
};