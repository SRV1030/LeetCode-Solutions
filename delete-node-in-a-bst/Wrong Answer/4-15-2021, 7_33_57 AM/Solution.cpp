// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* Inpre(TreeNode* rootH){
        TreeNode * root=rootH;
        while(root!=NULL && root->right!=NULL)root=root->right;
        return root;
    }
    TreeNode* Insuc(TreeNode* rootH){
        TreeNode * root=rootH;
        while(root!=NULL && root->left!=NULL)root=root->left;
        return root;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;        
        if(root->val>key) deleteNode(root->left,key);
        else if (root->val<key) deleteNode(root->right,key);
        else{
            if(root->left==NULL && root->right==NULL){
                // delete root;
                return NULL;
            }  
            else if(root->left==NULL){
                TreeNode* temp= root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                TreeNode* temp= root->left;
                delete root;
                return temp;
            }
                if(height(root->left)>height(root->right)){
                    // cout<<height(root->left)<<"\n";
                    TreeNode* temp= Inpre(root->left);
                    root->val=temp->val;
                    root->left=deleteNode(root->left,temp->val);
                }
                else{
                    TreeNode* temp= Insuc(root->right);
                     root->val=temp->val;
                    root->right=deleteNode(root->right,temp->val);
                } 
            }
        return root;
        }
        
        
    
};