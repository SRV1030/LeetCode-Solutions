// https://leetcode.com/problems/create-binary-tree-from-descriptions

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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<TreeNode*,TreeNode*>mparent;
        unordered_map<int,TreeNode*>mp;
        for(auto& d:desc){
            int p=d[0],c=d[1],isL=d[2];
            TreeNode* parent = mp.count(p)?mp[p]:(mp[p]=new TreeNode(p));
            TreeNode* child = mp.count(c)?mp[c]:(mp[c]=new TreeNode(c));
            if(isL)parent->left=child;
            else parent->right=child;
            mparent[child]=parent;
        }
        TreeNode* root=mp.begin()->second;
        while(mparent.count(root))root=mparent[root];
        return root;
    }
};