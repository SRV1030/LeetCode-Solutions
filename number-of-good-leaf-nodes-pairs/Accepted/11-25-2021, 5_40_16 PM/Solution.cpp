// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs

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
    int ans=0;
    vector<int> count(TreeNode* root, int d){
        if(!root) return{};
        if(!root->left && ! root->right) return {1};
        vector<int>lt=count(root->left,d),rt=count(root->right,d),res;
        for(auto& l:lt)
            for(auto&r:rt)if(l+r<=d) ans++;
        for(auto& l:lt) if(l+1<=d)res.push_back(l+1);
        for(auto& r:rt) if(r+1<=d)res.push_back(r+1);
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        count(root,distance);
        return ans;
    }
};