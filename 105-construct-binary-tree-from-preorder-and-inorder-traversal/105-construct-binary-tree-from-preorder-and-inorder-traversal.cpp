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
    int preInd=0;
    int search(vector<int>& in,int x,int l,int h){
        for(int i=l;i<=h;i++) if(in[i]==x) return i;
        return -1;
    }
    TreeNode* build(vector<int>& pre, vector<int>& in,int l,int h){
       if(l>h) return NULL;
        TreeNode *root=new TreeNode(pre[preInd++]);
        int i=search(in,root->val,l,h);
        if(i!=-1){
            root->left=build(pre,in,l,i-1);
            root->right=build(pre,in,i+1,h);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        return build(p,in,0,p.size()-1);
    }
};
