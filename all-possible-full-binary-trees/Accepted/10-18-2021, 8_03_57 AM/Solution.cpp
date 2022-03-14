// https://leetcode.com/problems/all-possible-full-binary-trees

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
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> helper(int n){
        if(n==1) return mp[1];
        if(mp.count(n)) return mp[n];
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
           vector<TreeNode*> left= helper(i);
           vector<TreeNode*> right= helper(n-1-i);
            for(auto& l:left)
                for(auto& r:right){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
        }
        return mp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return{};        
        mp[1].push_back(new TreeNode(0));
        return helper(n);
    }
};