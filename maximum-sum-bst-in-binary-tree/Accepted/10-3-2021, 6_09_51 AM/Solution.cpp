// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree

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
struct check{
    bool isbst;
    int s;
    int mn;
    int mx;
};
class Solution {
public:
    int mxs=0;
    check util(TreeNode* root){
        if(!root) return {true,0,INT_MAX,INT_MIN};
        check lt=util(root->left),rt=util(root->right);
        check cur;
        cur.mn=min(root->val,min(lt.mn,rt.mn));
        cur.mx=max(root->val,max(lt.mx,rt.mx));
        if(lt.isbst && rt.isbst && lt.mx<root->val && root->val<rt.mn){
            cur.isbst=true;
            cur.s=root->val+lt.s+rt.s;
            if(cur.s>mxs)mxs=cur.s;
        }
        else{
            cur.isbst=false;
            cur.s=max(lt.s,rt.s);
        }
        return cur;
    }
    int maxSumBST(TreeNode* root) {
        util(root);
        return mxs;
    }
};