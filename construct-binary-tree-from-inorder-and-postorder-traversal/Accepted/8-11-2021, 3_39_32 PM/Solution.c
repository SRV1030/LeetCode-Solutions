// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* inorder, int inlen, int* postorder, int postlen){
    if(inlen == 0) return NULL;
	
    // Last elem of postorder must be (sub)tree's root
    struct TreeNode* curr = malloc(sizeof(struct TreeNode));
    curr->val = postorder[postlen-1];
	
    // Find partition index
    int mid = 0;
    while(inorder[mid]!=curr->val) ++mid;
	
    curr->left = buildTree(&inorder[0], mid, &postorder[0], mid);
    curr->right = buildTree(&inorder[mid+1], inlen-mid-1, &postorder[mid], inlen-mid-1);
    return curr;
}