// https://leetcode.com/problems/serialize-and-deserialize-bst

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
    void ser(TreeNode* root,string &s){
        if(!root){
            s+= ",n";
            return;
        }
        
        s+= "," + to_string(root->val);
        ser(root->left, s);
        ser(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        ser(root,s);
        return s.substr(1,s.size()-1);
    }
    
    void des(stringstream &s,TreeNode* &root){
        string val;
        getline(s,val,',');
        if(val=="n"){
            root=NULL;
            return;
        }
         int v;
        v = stoi(val);
        root=new TreeNode(v);
        des(s,root->left);
        des(s,root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        TreeNode *root;
        des(s,root);
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;