// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal

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
public: int n;
    TreeNode* pre(string t,int &i,int depth){
        if(i>=n) return NULL;
        int pInd=i,cv=0,cd=0;
        while(i<n && t[i]=='-'){
            i++;cd++;
        }
        while(i<n && isdigit(t[i])){
            cv=cv*10+t[i]-'0';
            i++;
        }
        if(cd<depth){//Rchild
            i=pInd;
            return NULL;
        }
        TreeNode* root= new TreeNode(cv);
        root->left= pre(t,i,depth+1);
        root->right= pre(t,i,depth+1);
        return root;
        
    }
    TreeNode* recoverFromPreorder(string t) {
        int i=0;
        n=t.size();
        return pre(t,i,0);
    }
};