// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
      void finddown(TreeNode* root,int k){
        if(!root || k<0) return;
        if(k==0)v.push_back(root->val);
        finddown(root->left,k-1);
        finddown(root->right,k-1);
    }
    int kdistNode(TreeNode*root,TreeNode* t,int k){
        if(!root) return -1;
        if(root==t){
            finddown(root,k);
            return 0;
        }
        int lr=kdistNode(root->left,t,k);
        if(lr!=-1){
            if(lr+1==k)v.push_back(root->val);
            else finddown(root->right,k-lr-2);
            return 1+lr;
        }
        int rr=kdistNode(root->right,t,k);
        if(rr!=-1){
            if(rr+1==k)v.push_back(root->val);
            else finddown(root->left,k-rr-2);
            return 1+rr;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        kdistNode(root,target,k);
        return v;
    }
};