// https://leetcode.com/problems/house-robber-iii

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
// class Solution {
// public: unordered_map<TreeNode* ,pair<int,int>>mp;
//     void util(TreeNode* root){
//         if(!root) return;
//         rob(root->left);
//         rob(root->right);
//         if(!root->left && !root->right) mp[root]={root->val,0};
//         else{
//             int l1=0,l2=0,r1=0,r2=0;
//             if(root->left){
//                 l1=mp[root->left].first;
//                 l2=mp[root->left].second;
//             }
//             if(root->right){
//                 r1=mp[root->right].first;
//                 r2=mp[root->right].second;
//             }
//             mp[root]={root->val+l2+r2,max(l1,l2)+max(r1,r2)};
//         }
//     }
//     int rob(TreeNode* root) {
//         util(root);
//         return max(mp[root].first,mp[root].second);
//     }
// };
class Solution {
public: 
    void util(TreeNode* root,int &chs,int &gcs){
        if(!root) return;
        if(!root->left && !root->right){
            chs=root->val;
            gcs=0;
            return;
        }
        int lc=0,lg=0,rc=0,rg=0;
        util(root->left,lc,lg);
        util(root->right,rc,rg);
        chs=max(root->val+lg+rg,lc+rc);
        gcs=lc+rc;
    }
    int rob(TreeNode* root) {
        int chs=0,gcs=0;
        util(root,chs,gcs);
        return chs;
    }
};