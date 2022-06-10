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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        int l=0;
        q.push(root);
        while(!q.empty()){
            int n=size(q),prv=(l%2)?INT_MAX:INT_MIN;
            while(n--){
                TreeNode* x=q.front();
                q.pop();
                if((l%2 && (x->val%2 || x->val>=prv)) || (l%2==0 && (x->val%2==0 || x->val<=prv)))return false; 
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                prv=x->val;
            }
            ++l;
        }
        return true;
    }
};