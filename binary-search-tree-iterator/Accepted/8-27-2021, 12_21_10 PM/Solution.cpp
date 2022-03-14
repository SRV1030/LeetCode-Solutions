// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
public:
    vector<int>nodes;
    int p;
    void inor(TreeNode* root){
        if(!root)return;
        inor(root->left);
        nodes.push_back(root->val);
        inor(root->right);
    }
    BSTIterator(TreeNode* root) {
        inor(root);
        p=0;
    }
    
    int next() {
        if(hasNext()) return nodes[p++];
        return -1;
    }
    
    bool hasNext() {
        return p<nodes.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */