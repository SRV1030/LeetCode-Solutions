// https://leetcode.com/problems/symmetric-tree

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
const mirrorCheck=(l,r)=>{
    if(!l && !r) return true;
    if(l?.val!==r?.val) return false;
    return mirrorCheck(l.left,r.right) && mirrorCheck(l.right,r.left);
}
var isSymmetric = function(root) {
    if(!root) return true;
    return mirrorCheck(root.left,root.right);
};