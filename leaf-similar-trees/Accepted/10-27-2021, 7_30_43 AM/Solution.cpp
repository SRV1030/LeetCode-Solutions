// https://leetcode.com/problems/leaf-similar-trees

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
    void getst(TreeNode* root1,string &r1){
        if(!root1)return;  
        getst(root1->left,r1);      
        if(!root1->left && !root1->right)r1+=to_string(root1->val)+',';
        getst(root1->right,r1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string r1,r2;
        getst(root1,r1);
        getst(root2,r2);
        return r1==r2;
    }
};