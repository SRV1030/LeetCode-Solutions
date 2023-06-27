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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long,vector<long>,greater<>>pq;
        while(!q.empty()){
            long n=size(q),sm=0;
            while(n--){
                TreeNode* c=q.front();
                q.pop();
                if(c->left)q.push(c->left);
                if(c->right)q.push(c->right);
                sm+=c->val;
            }
            pq.push(sm);
            if(size(pq)>k)pq.pop();
        }
        return (size(pq)==k)?pq.top():-1;
    }
};