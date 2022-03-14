// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void ser(string &s,TreeNode* root){
        if(!root){
            s+=",n";
            return;
        }
        s+=","+to_string(root->val);
        ser(s,root->left);
        ser(s,root->right);        
    }
    string serialize(TreeNode* root) {
        string s="";
        ser(s,root);
        return s.substr(1,s.size()-1);
    }

    // Decodes your encoded data to tree.
    void des(stringstream &s,TreeNode* &root){
          string val;
          getline(s,val,',');
        if(val=="n"){
            root=NULL;
            return;
        }
        root= new TreeNode(stoi(val));
        des(s,root->left);
        des(s,root->right);   
    }
    TreeNode* deserialize(string data) {
        stringstream s(data);
        TreeNode *root;
        des(s,root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));