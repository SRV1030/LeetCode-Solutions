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
    TreeNode* pv;
    int mn=INT_MAX;
    void get_min(TreeNode* r){
        if(!r)return;
        get_min(r->left);
        if(pv)mn=min(mn,r->val-pv->val);
        pv=r;
        get_min(r->right);
        
    }
    int getMinimumDifference(TreeNode* root) {
        get_min(root);
        return mn;
    }
};