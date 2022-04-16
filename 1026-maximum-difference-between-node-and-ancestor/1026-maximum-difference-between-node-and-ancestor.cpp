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
    int util(TreeNode* root,int mx,int mn){
        if(!root) return mx-mn;
        if(root->val>mx)mx=root->val;
        if(root->val<mn)mn=root->val;
        return max(util(root->left,mx,mn),util(root->right,mx,mn));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;        
        return util(root,root->val,root->val);
    }
};