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
    TreeNode* conv(vector<int>& nums,int l,int r){
        if(r<l) return NULL;
        int m=l+(r-l)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=conv(nums,l,m-1);
        root->right=conv(nums,m+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return conv(nums,0,nums.size()-1);
    }
};