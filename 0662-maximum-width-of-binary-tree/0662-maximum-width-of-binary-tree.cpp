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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode *,unsigned long long >>dq;
        dq.push_back({root,1});
        unsigned long long mx=0;
        while(!dq.empty()){
            mx=max(mx,dq.back().second-dq.front().second+1);
            unsigned long long n=dq.size();
            for(int i=0;i<n;i++){
                TreeNode *node=dq.front().first;
                unsigned long long w=dq.front().second;
                dq.pop_front();
                if(node->left)dq.push_back({node->left,2*w});
                if(node->right)dq.push_back({node->right,2*w+1});                
                
            }
        }
        return mx;
    }
};