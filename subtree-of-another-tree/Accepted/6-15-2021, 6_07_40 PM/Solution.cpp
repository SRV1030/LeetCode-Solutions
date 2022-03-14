// https://leetcode.com/problems/subtree-of-another-tree

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
public:vector<TreeNode*>v;
    void FindAll(TreeNode*root,int k){
        if(!root)return;
        if(root->val==k) v.push_back(root);
        FindAll(root->left,k);
        FindAll(root->right,k);        
    }
    bool Check(TreeNode* r, TreeNode* s){
        if((r && !s)|| (!r && s)) return false;
        if(!r && !s) return true;
        if(r->val==s->val){
            return Check(r->left,s->left) && Check(r->right,s->right);
        }
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        v.clear();       
        FindAll(root,subRoot->val);
        for(auto i:v){
            if(Check(i,subRoot)) return true;
        }
        return false;
    }
};