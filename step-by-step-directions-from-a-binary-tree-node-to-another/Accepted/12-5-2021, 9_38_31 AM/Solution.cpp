// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
    string s,d;
    int sz=INT_MAX;
    TreeNode* lca(TreeNode* root,int n1,int n2){
        if(!root) return NULL;
        if(root->val==n1 || root->val==n2) return root;        
        TreeNode* left_lca = lca(root->left, n1, n2);
        TreeNode* right_lca = lca(root->right, n1, n2);
        if (left_lca && right_lca)
            return root;
        return (left_lca != NULL) ? left_lca : right_lca;
    }
    void finds(TreeNode* lca,int st,int dt,bool &f,bool &fd,string &r,string &t){
        if(!lca || (f && fd)) return;
        if(lca->val==st){
            f=true;
            s=r;
        }  
        if(lca->val==dt){
            fd=true;
            d=t;
        }
        r+='U';
        t+='L';
        finds(lca->left,st,dt,f,fd,r,t);
        t.pop_back();
        t+='R';
        finds(lca->right,st,dt,f,fd,r,t);
        t.pop_back();
        r.pop_back();
        
    }
    string getDirections(TreeNode* root, int st, int dt) {
        TreeNode* LCA=lca(root,st,dt);
        bool f=false,f1=false;
        string t,r;
        finds(LCA,st,dt,f,f1,r,t);
        return s+d;
    }
};