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
    int res=0;
    pair<bool,int> dfs(TreeNode* root, int start){
        if(!root) return {false,0};
        pair<bool,int> l=dfs(root->left,start),r=dfs(root->right,start);
        if(root->val==start){
            res=max(res,max(l.second,r.second));
            return {true,0};
        }
        int sum = l.second+r.second+1;
        if(l.first || r.first) res = max(res,sum);
        if(l.first) return {true,l.second+1};
        if(r.first) return {true,r.second+1};
        sum = max(l.second,r.second);
        return {false,1+sum};
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return res;
    }
};