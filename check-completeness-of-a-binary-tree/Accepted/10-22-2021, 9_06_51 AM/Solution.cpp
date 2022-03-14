// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* root) {
        bool end=false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r=q.front();
            if(!r)end=true;
            else if(end) return false;
            if(r){
                q.push(r->left);
                q.push(r->right);
            }
            q.pop();
        }
        return true;
    }
};