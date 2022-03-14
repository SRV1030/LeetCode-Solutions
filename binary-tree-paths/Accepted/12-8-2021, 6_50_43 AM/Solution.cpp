// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> ans;
    void fill(TreeNode* root,string a){
        if(!root) return;
        if(!root->left && !root->right){
            a+=to_string(root->val);
            ans.push_back(a);
            return;
        }
        string s=to_string(root->val)+"->";
        fill(root->left,a+s);
        fill(root->right,a+s);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) {};
        string s=to_string(root->val);
        if(!root->left && !root->right)return {s};
        s+="->";
        fill(root->left,s);
        fill(root->right,s);
        return ans;
    }
};