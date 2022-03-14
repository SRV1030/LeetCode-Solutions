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
    void down(TreeNode* root,int k){
        if(!root) return;
        if(k==0) v.push_back(root->val);
        down(root->left,k-1);
        down(root->right,k-1);
    }
    int distk(TreeNode* root, TreeNode* target, int k){
        if(!root) return -1;
        if(root==target){
            down(root,k);
            return 0;
        }
        int lr=distk(root->left,target,k);
        if(lr!=-1){
            if(lr+1==k) v.push_back(root->val);
            else down(root->right,k-lr-2);
            return lr+1;
        }
        int rr=distk(root->right,target,k);
        if(rr!=-1){
            if(rr+1==k) v.push_back(root->val);
            else down(root->left,k-rr-2);
            return rr+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        distk(root,target,k);
        return v;
    }
};