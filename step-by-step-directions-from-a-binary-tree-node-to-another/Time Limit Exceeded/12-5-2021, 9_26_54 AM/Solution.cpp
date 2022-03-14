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
    void finds(TreeNode* lca,int st,bool &f,string r){
        if(!lca || f) return;
        if(lca->val==st){
            f=true;
            s=r;
            return;
        }  
        finds(lca->left,st,f,r+'U');
        finds(lca->right,st,f,r+'U');
    }
    void findd(TreeNode* lca,int dt,string t){
        if(!lca) return;
        if(lca->val==dt){
            if(t.size()<sz){
                d=t;
                sz=d.size();
            }
            return;
        }  
        findd(lca->left,dt,t+'L');
        findd(lca->right,dt,t+'R');
    }
    string getDirections(TreeNode* root, int st, int dt) {
        TreeNode* LCA=lca(root,st,dt);
        bool f=false;
        string t,r;
        finds(LCA,st,f,r);
        findd(LCA,dt,t);
        return s+d;
    }
};