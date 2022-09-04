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
    map<int,map<int,multiset<int>>>mp;
    void dfs(TreeNode* root,int r,int c){
        if(!root) return;
        mp[r][c].insert(root->val);
        dfs(root->left,r-1,c+1);
        dfs(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      vector<vector<int>> ans;
        if(!root) return ans;
        dfs(root,0,0);
        for(auto&[k,v]:mp){
            ans.push_back({});
            for(auto&[k1,v1]:v)
                for(auto&e:v1)ans.back().push_back(e);            
        }
        return ans;            
    }
};