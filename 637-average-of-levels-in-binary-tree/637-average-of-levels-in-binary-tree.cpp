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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!empty(q)){
            int n=size(q);
            double a=0,t=n;
            while(n--){
                TreeNode* f=q.front();
                q.pop();
                a+=f->val;
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ans.push_back(a/t);
        }
        return ans;
    }
};