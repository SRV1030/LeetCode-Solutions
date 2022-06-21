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
    vector<int> count(TreeNode *root,int d){
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        vector<int> lt=count(root->left,d),rt=count(root->right,d),res;
        for(auto&i:lt)
            for(auto&j:rt)if(i+j<=d)++ans;
        for(auto&i:lt)if(i+1<=d)res.push_back(i+1);
        for(auto&j:rt)if(j+1<=d)res.push_back(j+1);
        return res;
    }
    int countPairs(TreeNode* root, int dist) {
        count(root,dist);
        return ans;
    }
};