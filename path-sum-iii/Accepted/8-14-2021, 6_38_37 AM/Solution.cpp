// https://leetcode.com/problems/path-sum-iii

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
public:unordered_map<int,int>mp;
        int c;
    void solve(TreeNode* root, int t,int s){
        if(!root) return;
        s+=root->val;
        if(mp.count(s-t))c+=mp[s-t];
        mp[s]++;
        solve(root->left,t,s);
        solve(root->right,t,s);
        mp[s]--;
    }
    int pathSum(TreeNode* root, int t) {        
        c=0; 
        if(!root) return c;
        mp[0]=1;
        solve(root,t,0);
        return c;
    }
};