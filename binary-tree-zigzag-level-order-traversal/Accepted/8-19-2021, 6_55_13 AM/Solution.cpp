// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!root) return v;
        stack<TreeNode*>cur,nxt;
        cur.push(root);
        bool ltr=true;
        vector<int>a;
        while(!cur.empty()){
            TreeNode* node=cur.top();
            cur.pop();
            a.push_back(node->val);
            if(ltr){
                if(node->left)nxt.push(node->left);
                if(node->right)nxt.push(node->right);
            }
            else{
                if(node->right)nxt.push(node->right);
                if(node->left)nxt.push(node->left);
            }
            if(cur.empty()){
                swap(cur,nxt);
                v.push_back(a);
                a.clear();
                ltr=!ltr;
            }
        }
        return v;
    }
};