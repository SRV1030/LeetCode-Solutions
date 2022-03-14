// https://leetcode.com/problems/find-duplicate-subtrees

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
    vector<TreeNode*> v;
    unordered_map<string,int>mp;
    string  dfsPath(TreeNode* root,string p){
        if(!root) return p+"$";
        p+=to_string(root->val)+"-"+dfsPath(root->left,p)+"-"+dfsPath(root->right,p);
        mp[p]++;
        if(mp[p]==2)v.push_back(root);
        return p;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfsPath(root,"");
        return v;
    }
};