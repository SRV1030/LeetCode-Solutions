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
    int v[10]={};
    int pseudoPalindromicPaths (TreeNode* root,int oc=0) {
        if(!root) return 0;
        int res=0;
        oc+=++v[root->val]%2==1?+1:-1;
        if(root->left==root->right) res=oc<2?1:0;
        else res+=pseudoPalindromicPaths(root->left,oc)+pseudoPalindromicPaths(root->right,oc);
        oc+=--v[root->val]%2==1?+1:-1;
        return res;
    }
};