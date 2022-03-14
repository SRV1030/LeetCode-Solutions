// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {        
        if(!root) return {};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool f=false;
            while(n--){
                TreeNode* x=q.front();
                q.pop();
                if(!f){
                    v.push_back(x->val);
                    f=true;
                }
                if(x->right)q.push(x->right);
                if(x->left)q.push(x->left);
            }
        }
        return v;
    }
};