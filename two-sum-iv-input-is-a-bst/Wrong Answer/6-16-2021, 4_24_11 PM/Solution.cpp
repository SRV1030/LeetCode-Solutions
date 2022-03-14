// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
public:TreeNode* head;
    bool search(TreeNode* root,int k){
        if(!root) return false;
         if(root->val==k) return true;
        if(root->val>k)return search(root->left,k);
        else return search(root->right,k);
    }
    bool tg(TreeNode* root,int k){
        if(!root) return false;
        int t=k-root->val;  
        if(t!=k){
            if(search(head,t)) return true;
        }        
        return tg(root->left,k)||tg(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        head=root;
        return tg(root,k);
    }
};