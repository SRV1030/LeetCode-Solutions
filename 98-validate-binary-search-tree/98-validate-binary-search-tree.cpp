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
#define li long long int

bool val(TreeNode* root,li mn,li mx){
    if(!root) return true;
    if(root->val<=mn || root->val>=mx) return false;
    return val(root->left,mn,root->val) && val(root->right,root->val,mx);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return val(root,LONG_MIN,LONG_MAX);
    }
};