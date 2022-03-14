// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
public: unordered_map<int,vector<int>>mp;
    void trav(int l,TreeNode* root){
        if(!root) return;
        mp[l].push_back(root->val);
        trav(l+1,root->left);
        trav(l+1,root->right);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return{};
        trav(1,root);
        vector<vector<int>> ans;
        for(int i=mp.size();i>=1;i--) ans.push_back(mp[i]);
        return ans;
    }
};