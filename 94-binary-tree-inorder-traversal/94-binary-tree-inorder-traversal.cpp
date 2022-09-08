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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
       TreeNode*cur=root;
        while(cur){
            if(!cur->left){
                v.push_back(cur->val);
                cur=cur->right;
            }
            else{
               TreeNode* pred=cur->left;
                while(pred->right && cur!=pred->right) pred=pred->right;
                if(!pred->right){
                    pred->right=cur;
                    cur=cur->left;
                }
                else{
                    pred->right=NULL;
                    v.push_back(cur->val);
                    cur=cur->right;                    
                }
            }
        }
        return v;
    }
};