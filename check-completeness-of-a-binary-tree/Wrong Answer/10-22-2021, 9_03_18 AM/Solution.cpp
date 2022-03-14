// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* root) {
        bool nxtlvl=false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            nxtlvl=false;
            while(n--){
                TreeNode* r=q.front();
                q.pop();
                if((!r->left && !r->right && nxtlvl) || (!r->left && r->right)) return false;
                if(r->left){
                    nxtlvl=true;
                    q.push(r->left);
                }
                if(r->right) q.push(r->right);
            }
        }
        return true;
    }
};