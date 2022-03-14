// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    long long int md=1e9+7,mx=0,ans=0;
    int addchildval(TreeNode* root){
        if(!root) return 0;
        int l= addchildval(root->left)%md,r=addchildval(root->right)%md;
        root->val=(root->val+l+r)%md;
        return root->val;        
    }
    void findmx(TreeNode* root){
        if(!root) return;
        findmx(root->left);
        findmx(root->right);
        ans= max(ans,(root->val)*(mx - root->val));
    }
    int maxProduct(TreeNode* root) {
        addchildval(root);
        mx=root->val;
        findmx(root);
        return ans%md;
    }
};