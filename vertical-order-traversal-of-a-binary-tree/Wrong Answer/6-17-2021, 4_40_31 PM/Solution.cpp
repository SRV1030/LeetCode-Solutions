// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
public: map<int,map<int,set<int>>> mp;
    void dfs(TreeNode* root,int r,int c){
        if(!root) return;
        mp[r][c].insert(root->val);
        dfs(root->left,r-1,c+1);
        dfs(root->right,r+1,c+1);        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        dfs(root,0,0);
        for(auto r:mp){
            v.push_back({});
            for(auto c:r.second)
                for(auto e:c.second)
                    v.back().push_back(e);
        }
        return v;
            
    }
};