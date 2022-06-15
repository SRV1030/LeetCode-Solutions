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
    int d=0;
    int ht(TreeNode* root){
        if(!root) return 0;
        int l=ht(root->left),r=ht(root->right);
        if((l+r)>d) d=l+r;
        return 1+max(l,r);        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ht(root);
        return d;
    }
};