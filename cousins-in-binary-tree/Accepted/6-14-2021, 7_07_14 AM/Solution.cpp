// https://leetcode.com/problems/cousins-in-binary-tree

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
    int Level(TreeNode* root,int x,int c){
        if(!root) return 0;
        if(root->val==x) return c;
        int l=Level(root->left,x,c+1);
        if(l!=0) return l;
        int r=Level(root->right,x,c+1);
        return  r;
    }
    bool isSibling(TreeNode* root, int x, int y){
        if(!root) return false;
        bool f1=(root->left && root->right)? (root->left->val==x && root->right->val==y) ||(root->right->val==x&& root->left->val==y):false;

        return f1 || isSibling(root->left,x,y) || isSibling(root->right,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return Level(root,x,0)==Level(root,y,0) && !isSibling(root,x,y);
    }
};