/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;   
        q.push(root);
        while(!q.empty()){
            int n=size(q);
            ans.push_back({});
            while(n--){
                Node*t=q.front();
                q.pop();
                ans.back().push_back(t->val);
                for(auto&i:t->children)q.push(i);
            }
        }
        return ans;        
    }
};