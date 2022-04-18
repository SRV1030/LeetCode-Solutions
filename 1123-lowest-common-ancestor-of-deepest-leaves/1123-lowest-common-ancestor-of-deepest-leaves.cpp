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
    unordered_map<TreeNode*,int>mp;
    int depth(TreeNode* root){
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        return mp[root]=1+max(depth(root->left),depth(root->right));
    }    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        int ld=depth(root->left),rd=depth(root->right);
        if(ld==rd) return root;
        if(ld>rd) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
};