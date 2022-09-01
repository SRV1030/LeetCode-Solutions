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
    void util(TreeNode* root,int mx){
        if(!root) return;
        if(root->val>=mx){
            ans++;
            mx=root->val;
        }
        util(root->left,mx);
        util(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        int mx=root->val;
        util(root,mx);
        return ans;
    }
};