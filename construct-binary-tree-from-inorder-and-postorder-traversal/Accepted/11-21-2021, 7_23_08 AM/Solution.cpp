// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
public: int pi;
    int search(vector<int>& in,int k,int l,int h){
        for(int i=l;i<=h;i++)if(in[i]==k) return i;
        return -1;
    }
    TreeNode* build(vector<int>& in, vector<int>& po,int l,int r){
        if(l>r) return NULL;
        TreeNode* root=new TreeNode(po[pi--]);
        int i=search(in,root->val,l,r);
        if(i!=-1){            
            root->right=build(in,po,i+1,r);
            root->left=build(in,po,l,i-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int n=po.size();
        pi=n-1;
        return build(in,po,0,n-1);
    }
};