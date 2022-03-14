// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
public:int preInd=0;
    int search( vector<int>& in,int s,int e,int k){
        if(s>e) return -1;
        for(int i=s;i<=e;i++)
            if(in[i]==k) return i; 
        return -1;
    }
    TreeNode* util(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e) return NULL;
         TreeNode* root=new TreeNode(preorder[preInd++]);
        int i=search(inorder,s,e,root->val);
        if(i!=-1){
            root->left=util(preorder,inorder,s,i-1);
            root->right=util(preorder,inorder,i+1,e);
        }
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       TreeNode* root=util(preorder,inorder,0,preorder.size()-1);
       return root;
    }
};