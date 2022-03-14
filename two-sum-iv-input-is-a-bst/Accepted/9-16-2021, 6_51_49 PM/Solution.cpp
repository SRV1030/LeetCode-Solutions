// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    unordered_set<int>st;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(findTarget(root->left,k)) return true;
        if(st.count(k-root->val)) return true;        
        st.insert(root->val);
        return findTarget(root->right,k);
    }
};