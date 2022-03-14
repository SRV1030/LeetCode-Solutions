// https://leetcode.com/problems/path-sum-ii

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
public: vector<vector<int>> v;
    void solve(TreeNode* root,vector<int> a,int s,int t){
        if(!root)return;
        s+=root->val;
        a.push_back(root->val);
        if(s==t){
            v.push_back(a);
            return;
        }
        solve(root->left,a,s,t);
        solve(root->right,a,s,t);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        if(!root) return v;
        vector<int>a;
        solve(root,a,0,t);
        return v;
    }
};