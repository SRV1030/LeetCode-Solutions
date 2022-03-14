// https://leetcode.com/problems/binary-tree-coloring-game

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
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* trg;
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t->val==x){
                trg=t;
                break;
            }
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        int lft=count(trg->left),rt=count(trg->right);
        if(lft+rt+1<=n/2)return true;
        if(lft>n/2 || rt>n/2)return true;
        return false;
    }
};