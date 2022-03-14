// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    void depth(TreeNode* root,int dep,int &ans)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            ans = min(dep,ans);
            return;
        }
        depth(root->left,dep+1,ans);
        depth(root->right,dep+1,ans);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX;
        depth(root,1,ans);
        return ans;
    }
};