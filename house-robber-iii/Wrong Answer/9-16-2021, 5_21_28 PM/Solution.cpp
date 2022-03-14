// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root) {
        // if(!root->left && !root->right) return root->val;
        vector<int>v={0,root->val};
        queue<TreeNode*>q;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        while(!q.empty()){
            int n=q.size(),sz=v.size(),s=0;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                s+=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);                
            }
            v.push_back(max(s+v[sz-2],v[sz-1]));
        }
        return v.back();        
    }
};