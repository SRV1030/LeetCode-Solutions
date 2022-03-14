// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(),mx=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode *t=q.front();
                q.pop();
                if(t->val>mx)mx=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            v.push_back(mx);
        }
        return v;
    }
};