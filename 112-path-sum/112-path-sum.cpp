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
    void check(TreeNode* root,bool &f,int s,int t){
        if(f || !root)return;        
        s+=root->val;
        if(!root->left && !root->right && s==t){
            f=true;
            return;
        }
        check(root->left,f,s,t);
        check(root->right,f,s,t); 
    }
    bool hasPathSum(TreeNode* root, int t) {
        bool f=false;
        int s=0;
        check(root,f,s,t);
        return f;
    }
};