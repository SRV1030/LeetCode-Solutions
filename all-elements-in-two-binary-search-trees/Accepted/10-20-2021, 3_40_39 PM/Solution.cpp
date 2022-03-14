// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    
    void infill(TreeNode* root,vector<int>&ans){
        if(!root) return;
        infill(root->left,ans);
        ans.push_back(root->val);
        infill(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a1,a2,res;
        infill(root1,a1);
        infill(root2,a2);
        for(int i=0,j=0;i<a1.size()||j<a2.size();){
            if(i>=a1.size() || (j<a2.size() && a2[j]<a1[i])) res.push_back(a2[j++]);
            else res.push_back(a1[i++]);
        }
        return res;
    }
};