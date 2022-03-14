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
        if(!root) return{{}};
        stack<TreeNode*> cur,nxt;
        cur.push(root);
        vector<vector<int>> v;
        vector<int> a;
        bool ltr=true;
        while(!cur.empty()){
            TreeNode* t=cur.top();
            cur.pop();
            if(t){
                a.push_back(t->val);
                if(ltr){
                    if(t->left)nxt.push(t->left);
                    if(t->right)nxt.push(t->right);
                }
                else{
                    if(t->right)nxt.push(t->right);
                    if(t->left)nxt.push(t->left);
                }
            }
            if(cur.empty()){
                swap(cur,nxt);
                v.push_back(a);
                ltr= !ltr;
                a.clear();
            }
        }
        return v;
    }
};