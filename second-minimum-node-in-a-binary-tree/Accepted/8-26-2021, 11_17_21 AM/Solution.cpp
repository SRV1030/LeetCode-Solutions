// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        long long int mn=INT_MAX,r=root->val;
        mn+=10;
        queue<TreeNode*>q;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode *t=q.front();
                q.pop();
                if(t->val!=r && t->val<mn)mn=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return mn-10!=INT_MAX?mn:-1;
    }
};